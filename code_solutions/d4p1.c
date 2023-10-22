#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PER_LINE 4096
#define PAIR 2
#define RANGE 4096

int main() {
    char line_buffer[MAX_PER_LINE] = {0};
    int pairs[PAIR][RANGE] = {0};
    int min[2] = {0};
    int max[2] = {0};
    int i, j, k, l;
    int score = 0;
    char string[PAIR][RANGE] = {0};
    char compare[128] = {0};
    int rounds = 0;

    int breakkk = 0;
    FILE *puzzle_input = fopen("../puzzle_inputs/pid4.txt", "r");
    while(fgets(line_buffer, MAX_PER_LINE, puzzle_input) != NULL) {
        rounds++;
        sscanf(line_buffer, "%d-%d,%d-%d", &min[0], &max[0], &min[1], &max[1]);
        printf("=========WHAT IS THE ANSWER============\n");
        printf("First elf range: %d-%d\n", min[0], max[0]);
        printf("First elf range: %d-%d\n", min[1], max[1]);
        for(j = 0; j < PAIR; j++){
            printf("printing numbers\n");
            for(i = min[j], k = 0, l = 0; i <= max[j]; i++, k++, l++){
                pairs[j][i] = i;
                printf("%d,", i);
                if(i > 9){
                    string[j][l] = pairs[j][i] / 10 + '0';
                    string[j][l + 1] = pairs[j][i] % 10 + '0';
                    string[j][l + 2] = ',';
                    compare[1] = string[j][l + 1];
                    compare[0] = string[j][l];
                    l += 2;
                    // l++;
                    // printf("\nCOMPARE i: %d\tto\t", i);
                    // printf("string: %s\n", compare);
                }
                else { 
                    string[j][l] = pairs[j][i] + '0';
                    string[j][l + 1] = ',';
                    l++;
                }
                string[j][l + 1] = '\0';
            }
            printf("\nprinting strings\n");
            printf("%s\n", string[j]);
        }
        
        // for(j = 0; j < PAIR; j++){
        //     // if(strlen(string[j]) == 1){
        //     //     printf("ONE N ONLY\n");
        //     // }
        //     // printf("len: %lu\n", strlen(string[j]));
        //     printf("string %d %s\n", j + 1, string[j]);
        // }
        if(strstr(string[0], string[1]) || strstr(string[1], string[0])){
            score = score + 1;
            printf("THERE IS A MATCH!!!\nCURRENT SCORE: %d\n", score);
            printf("string 1: %s \n\twith len of %lu\n", string[0], strlen(string[0]));
            printf("string 2: %s \n\twith len of %lu\n", string[1], strlen(string[1]));
        }
        memset(string[0], 0, RANGE);
        memset(string[1], 0, RANGE);
    }
    printf("total score: %d\n", score);
    printf("rounds: %d\n", rounds);
}
