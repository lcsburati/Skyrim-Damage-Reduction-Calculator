// Includes
#include <stdio.h>
#include <stdlib.h>

// Global Constants
#define HIDDEN_ARMOR_RATING 25
#define MAX_DAMAGE_REDUCTION 0.80f
#define POINTS_PER_PERCENT 0.12f
#define ARMORS_EQUIPPED 4



// Creating Structures
typedef struct {
    int armor_rating;
} armor;

// Prototypes
void argc_verify(int max_argc, int argc, char **argv);
void equip_armor(armor *armor_equipped);
int calculate_total_char_armor_rating(armor *armor_equipped);
float calculating_damage_reduction(int total_armor_rating);


// Main Function
int main(int argc, char **argv)
{   
    // Verify if the c file is correctly initialized.
    argc_verify(2, argc, argv);

    // Initializing armor type array.
    armor armor_equipped[ARMORS_EQUIPPED];

    // Populating the array with the user inputs.
    equip_armor(armor_equipped);

    // Calculating total armor rating.
    int total_char_armor_rating = calculate_total_char_armor_rating(armor_equipped);
    const int total_hidden_armor_rating = ARMORS_EQUIPPED * HIDDEN_ARMOR_RATING;
    int total_armor_rating = total_char_armor_rating + total_hidden_armor_rating;

    // Calculating damage reduction.
    float damage_reduction = calculating_damage_reduction(total_armor_rating);

    // Calculating damage taken.
    float damage_taken = atoi(argv[1]) * (1 - damage_reduction);

    printf("Char Armor: %i\n", total_char_armor_rating);
    printf("Damage taken: %.2f\n", damage_taken);


    return 0;
}

void argc_verify(int max_argc, int argc, char **argv)
{
    if (argc != max_argc)
    {
        printf("Usage: %s <damage>\n", argv[0]);
        exit(1);
    }
}

void equip_armor(armor *armor_equipped)
{
    
    for (int i = 0; i < ARMORS_EQUIPPED; i++)
    {
        int armor_rating;
        int scanf_return;
        do
        {
            printf("Enter the armor rating of the %d piece: ", i + 1);
            scanf_return = scanf("%i", &armor_rating);
        }
        while (armor_rating < 0 || scanf_return != 1);
        armor_equipped[i].armor_rating = armor_rating;
    }    
}

int calculate_total_char_armor_rating(armor *armor_equipped)
{
    int total_char_armor_rating = 0;  
    for (int i = 0; i < ARMORS_EQUIPPED; i++)
    {
        total_char_armor_rating += armor_equipped[i].armor_rating;
    }

    return total_char_armor_rating;
}

float calculating_damage_reduction(int total_armor_rating)
{
    // Calculating damage reduction.
    float damage_reduction = (total_armor_rating * POINTS_PER_PERCENT) / 100;
    
    // Limiting damage reduction.
    if (damage_reduction > MAX_DAMAGE_REDUCTION)
        damage_reduction = MAX_DAMAGE_REDUCTION;

    return damage_reduction;
}