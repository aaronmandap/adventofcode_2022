#include <stdio.h>
#include <stdlib.h>

int main() {
    int calorie_counter;
    int highest_calorie = 0;
    int total_calorie = 0;
    char buffer[1024];

    FILE *puzzle_input = fopen("/home/aaronmandap/tasks/adventofcode/2022/pid1.txt", "r");
    while(fgets(buffer, sizeof(buffer), puzzle_input) != NULL) {
        if(atoi(buffer) != 0) total_calorie = total_calorie + atoi(buffer);
        else {
            if(total_calorie > highest_calorie) highest_calorie = total_calorie;
            total_calorie = 0;
        }
    } 
    printf("highest_calorie: %d\n", highest_calorie);
    return 0;
}
