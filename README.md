#  survival-simulator-c
## Character-Based Survival Simulator (C Language Project)

This project is a character-based, text-driven Survival Simulator developed in the **C programming language** for the *Algorithm and Programming* course at Kırklareli University.

The simulation allows a player to manage their character's core stats—**Health**, **Energy**, and **Inventory**—by executing single-character commands via the console.

---

### 🌟 Project Requirements & Core C Structures

This simulator was developed with a strict mandate to utilize fundamental C control flow structures, demonstrating proficiency in algorithm implementation:

| C Structure | Used In Command | Purpose in Simulation |
| :--- | :--- | :--- |
| **SWITCH-CASE** | All Commands | Manages the primary command loop, directing program flow based on the single-character user input (A, S, R, E, F, P, X). |
| **IF-ELSE** | A, S, R, F | Implements conditional outcomes. Used heavily to determine success/failure in **Hunting (A)** and **Resting (R)** (e.g., if you have food, you rest better; else, you lose health). |
| **FOR Loop** | **F** (Danger Wave) | Simulates a sequence of repetitive, predictable events. Executes the 'Danger Wave' a fixed number of times (e.g., 3 turns), with consequences determined in each iteration. |
| **DO-WHILE Loop** | **P** (Cipher Progress) | Creates a verification mechanism. Forces the player to correctly input a specific character until the condition is met, implementing a 'lock' mechanism. |
| **Logical Operators** | A, S, F | Used (`&&` and `||`) to evaluate complex success/failure conditions (e.g., success if `high_chance` **OR** `has_food`). |
| **Arithmetic Operators** | A, R, P | Used to update character statistics (e.g., `energy -= 15;` for consumption, `saglik += 10;` for recovery). |

---

### ⚙️ How to Compile and Run

This project is written entirely in C (`survival_simulator.c`) and should be compiled using a standard C compiler (like GCC or Clang).

#### 1. Compilation (Using GCC on Linux/macOS/Windows Subsystem)

Navigate to the directory containing `survival_simulator.c` and run the following command to create an executable file named `simulator`:
`gcc survival_simulator.c -o simulator`

2. Running the Program
Execute the generated file from the terminal:
`./simulator`

🎮 Available Commands

The player interacts with the simulation using the following single-character commands:

Command    Action                    Simulation Effect
A          Hunt                    Consumes energy. IF-ELSE determines if food is gained or if the character is injured.
S          Shelter Search          Attempts to find a shelter. Success is evaluated using Logical Operators and IF-ELSE.
E          Environment/Inventory   "Displays the character's current Health, Energy, Food count, and Shelter status."
R          Rest                    Restores Health and Energy (Arithmetic Operators). Consumes 1 unit of food (if available).
F          Fallout/Danger Wave     Initiates a short simulation of danger using a FOR Loop. Causes conditional loss of Health/Energy.
P          Progress (Cipher)       Attempts to overcome an obstacle by solving a cipher. Uses a DO-WHILE Loop to enforce correct input.
X          Exit                    Terminates the simulation loop and exits the program.
