#include <stdio.h>
#include <stdlib.h>

int main() {
    int calorie_counter;
    int highest_calories[3] = {0};
    int total_calorie = 0;
    int top_3_total_calories = 0;
    char buffer[1024];
    int elf = 0;

    FILE *puzzle_input = fopen("pid1.txt", "r");
    while(fgets(buffer, sizeof(buffer), puzzle_input) != NULL) {
        if(atoi(buffer) != 0) total_calorie = total_calorie + atoi(buffer);
        else {
            if(total_calorie > highest_calories[elf]) {
                highest_calories[elf + 2] = highest_calories[elf + 1];
                highest_calories[elf + 1] = highest_calories[elf];
                highest_calories[elf] = total_calorie;
            }
            else if(total_calorie > highest_calories[elf + 1]) {
                highest_calories[elf + 2] = highest_calories[elf + 1];
                highest_calories[elf + 1] = total_calorie;
            }
            else if(total_calorie > highest_calories[elf + 2]) {
                highest_calories[elf + 2] = highest_calories[elf + 1];
            }
            total_calorie = 0;
        }
    } 
    for(elf = 0; elf < 3; elf++) top_3_total_calories = top_3_total_calories + highest_calories[elf];
    printf("top 3 elves total calories: %d\n", top_3_total_calories);
    return 0;
}
