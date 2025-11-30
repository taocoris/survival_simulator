#include <stdio.h>
#include <stdlib.h> 

int main() {

    // *** Durum Yönetimi için Değişkenler ***
    int saglik = 100; // Sağlık (0-100)
    int enerji = 100; // Enerji (0-100)
    int yemek_sayisi = 0; // Yemek sayısı
    int siginak_var = 0; // Sığınak bulunup bulunmadığı (0: Yok, 1: Var)
    char komut;
    int hayatta_mi = 1; 

    printf("************** KARAKTER TABANLI HAYATTA KALMA SİMÜLATÖRÜ **************\n");
    printf("Amacınız komutları kullanarak hayatta kalmak ve durumunuzu yönetmektir.\n");
    printf("----------------------------------------------------------------------\n");

    do {
        // Durum Gösterimi
        printf("\n*** KARAKTER DURUMU ***\n");
        printf(" Sağlık: %d/100\n", saglik);
        printf(" Enerji: %d/100\n", enerji);
        printf(" Yemek: %d adet\n", yemek_sayisi);
        printf(" Sığınak: %s\n", siginak_var ? "BULUNDU" : "YOK");
        printf("*************************\n");
        
        // Sağlık/Enerji kontrolü
        if (saglik <= 0 || enerji <= 0) {
            hayatta_mi = 0;
            printf("\n\n******************* OYUN BİTTİ *******************\n");
            printf("Sağlık veya enerjiniz 0 altına düştü. Hayatta kalamadınız.\n");
            printf("**************************************************\n");
            komut = 'X'; 
            break; // Ölümden sonra döngüyü sonlandır
        }

        printf("\nKOMUT (A:Avlan, S:Sığınak, E:Envanter, R:Dinlen, F:Tehlike, P:Şifre, X:Çıkış): ");
        scanf(" %c", &komut); 

        switch (komut) {
            case 'A': // Avlan
            case 'a':
                // Enerji kaybı 
                enerji -= 15;
                printf("-> Avlanmaya çıktınız. Enerji: -15. Kalan Enerji: %d\n", enerji);
                if (enerji < 0) enerji = 0;

                int sans = rand() % 100;

                if (sans >= 70) {
                    yemek_sayisi += 2;
                    printf("✅ Başarılı avlanma! 2 adet yemek buldunuz.\n");
                } else if (sans >= 40 && sans < 70) { 
                    printf("❌ Avlanma başarısız. Yemek bulamadınız.\n");
                } else if (sans < 40 || saglik < 30) { 
                    saglik -= 10;
                    printf("⚠️ Avlanırken yaralandınız! Sağlık: -10. Kalan Sağlık: %d\n", saglik);
                    if (saglik < 0) saglik = 0;
                }
                break;

            case 'S': // Sığınak ara
            case 's':
                if (siginak_var == 1) {
                    printf("🏡 Zaten bir sığınağınız var.\n");
                    break;
                }

                int arama_sans = rand() % 100;
                
                if (arama_sans >= 50 || yemek_sayisi > 2) { 
                    siginak_var = 1;
                    printf("🎉 Bir sığınak buldunuz!\n");
                } else {
                    printf("😔 Maalesef uygun bir sığınak bulamadınız.\n");
                }
                break;

            case 'E': // Envanteri görüntüle
            case 'e':
                printf("⬆️ Envanteriniz (Durumunuz) yukarıda gösterilmiştir.\n");
                break;

            case 'R': // Dinlen
            case 'r':
                // Sağlık ve enerji artışı 
                enerji += 30;
                saglik += 10;
                
                // Limit kontrolü
                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;

                if (yemek_sayisi > 0) {
                    yemek_sayisi--; // Yemek tüketimi
                    printf("😴 Dinleniyorsunuz ve 1 yemek tükettiniz. Sağlık: +10, Enerji: +30.\n");
                } else {
                    saglik -= 15;
                    printf("😫 Yemek yemeden dinleniyorsunuz. Sağlık kaybı yaşadınız! Sağlık: -15, Enerji: +30.\n");
                    if (saglik < 0) saglik = 0;
                }
                break;

            case 'F': 
            case 'f':
                printf("🚨 BÖLGEDE TEHLİKE DALGASI BAŞLADI! Kaçış simülasyonu...\n");

                for (int i = 1; i <= 3; i++) { 
                    printf("--- Dalga %d ---\n", i);

                    int tehlike_sans = rand() % 100;

                    // Duruma göre sonuç
                    if (tehlike_sans >= 70 && siginak_var == 1) { 
                        printf("✅ Sığınağınız sayesinde tehlikeyi atlattınız.\n");
                    } else if (tehlike_sans < 30 || enerji < 15) { 
                        saglik -= 20; 
                        enerji -= 5;
                        printf("💥 Tehlikeye yakalandınız! Sağlık: -20, Enerji: -5. Kalan Sağlık: %d\n", saglik);
                        if (saglik < 0) saglik = 0;
                    } else {
                        printf("🏃‍♂️ Enerjiniz sayesinde tehlikeden kaçmayı başardınız.\n");
                        enerji -= 10;
                    }

                    if (saglik <= 0 || enerji <= 0) break; 
                }
                break;

            case 'P': 
            case 'p':
                printf("🔒 Bir engel ile karşılaştınız. AŞMANIZ GEREKİYOR!\n");
                char dogru_sifre = '4'; 
                char girilen_sifre;

                do {
                    printf("Şifreyi giriniz (Tek karakter, ipucu: 4): ");
                    scanf(" %c", &girilen_sifre); 

                    if (girilen_sifre != dogru_sifre) {
                        printf("❌ Yanlış şifre! Tekrar deneyin.\n");
                        saglik -= 5; 
                        printf("Sağlık: -5. Kalan Sağlık: %d\n", saglik);
                        if (saglik < 0) saglik = 0;
                        if (saglik <= 0) break;
                    }
                } while (girilen_sifre != dogru_sifre); // Doğru karakteri girene kadar döngü devam eder

                if (girilen_sifre == dogru_sifre) {
                    printf("🔓 Şifre doğru! Engeli başarıyla aştınız.\n");
                    enerji += 10;
                }
                break;

            case 'X': // Çıkış
            case 'x':
                printf("\n👋 Simülatörden çıkış yapılıyor.\n");
                break;

            default:
                printf("❓ Geçersiz komut. Lütfen geçerli bir komut girin (A, S, E, R, F, P, X).\n");
                break;
        }
        
    } while (komut != 'X' && komut != 'x');
    
    return 0;
}