#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PER_LINE 1024
#define PAIR 2

int main() {
    char line_buffer[MAX_PER_LINE] = {0};
    int min[PAIR] = {0};
    int max[PAIR] = {0};
    int score = 0;

    FILE *puzzle_input = fopen("../puzzle_inputs/pid4.txt", "r");
    while(fgets(line_buffer, MAX_PER_LINE, puzzle_input) != NULL) {
        sscanf(line_buffer, "%d-%d,%d-%d", &min[0], &max[0], &min[1], &max[1]);
        if(max[0] >= min[1] && min[0] <= max[1]) score += 1;
        else if(min[0] <= max[1] && max[0] >= min[1]) score += 1;
    }
    printf("total score: %d\n", score);
}
