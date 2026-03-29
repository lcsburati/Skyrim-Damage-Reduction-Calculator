# Skyrim Armor Rating Calculator

[Leia em Português](README.pt-br.md) | [中文说明](README.zh-cn.md)

**Objective:** Simulate Skyrim's Armor Rating system to calculate damage reduction based on equipped armor pieces.

In Skyrim, many players don't realize how the armor system actually works behind the scenes. This project recreates that logic in C, taking into account displayed armor rating, hidden armor bonuses, and the 80% damage reduction cap.

## How It Works

The formula used for damage reduction is:

```
Damage Reduction % = (Displayed AR + Hidden AR) × 0.12
```

### Key Concepts

*   **Hidden Armor Rating:** Each equipped armor piece (helmet, chest, gauntlets, boots) grants an invisible bonus of **25 points**, totaling **100 hidden points** for a full set.
*   **Armor Cap:** Skyrim has a maximum physical damage reduction of **80%**. To reach this cap, you need a total Armor Rating of **667**. With the hidden bonus from 4 pieces, you only need **567 displayed** to hit the cap.

You can compile the project using `CMake`:

```bash
mkdir build
cd build
cmake ..
make
./bin/Armor <damage>
```

**Example:**

```bash
./main.out 100
```

The program will ask you to input the armor rating of each of the 4 equipped pieces, then calculate your total armor rating, the damage reduction percentage, and the final damage taken.

## Functions

*   **argc_verify:**
    *   **Args:** `int max_argc`, `int argc`, `char **argv`
    *   **Return:** `void`
    *   **Process:** Validates that the correct number of command-line arguments was provided. If not, it prints the correct usage format and exits the program.

*   **equip_armor:**
    *   **Args:** `armor *armor_equipped`
    *   **Return:** `void`
    *   **Process:** Iterates through each of the 4 armor slots, prompting the user to enter the armor rating for each piece. Uses a `do-while` loop to ensure the input is valid (non-negative integer).

*   **calculate_total_char_armor_rating:**
    *   **Args:** `armor *armor_equipped`
    *   **Return:** `int` (total displayed armor rating)
    *   **Process:** Sums up the armor rating of all equipped pieces and returns the total displayed armor rating.

*   **calculating_damage_reduction:**
    *   **Args:** `int total_armor_rating`
    *   **Return:** `float` (damage reduction as a decimal)
    *   **Process:** Applies the formula `(total_armor_rating × 0.12) / 100` to calculate the damage reduction percentage. If the result exceeds the 80% cap, it clamps the value to 0.80.
