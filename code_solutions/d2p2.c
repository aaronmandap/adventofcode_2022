#include <stdio.h>
#include <stdlib.h>

int main() {
    char your[] = {'X', 'Y', 'Z'};
    char their[] = {'A', 'B', 'C'};
    char them, you;
    char buffer[1024];
    int picks, xyz, abc, diff;
    int score = 0;

    FILE *puzzle_input = fopen("pid2.txt", "r");
    while(fgets(buffer, sizeof(buffer), puzzle_input) != NULL) {
        sscanf(buffer, "%c %c", &them, &you);
        for(picks = 0; picks < 3; picks++){
            if(them == their[picks]) abc = picks;
            if(you == your[picks]) xyz = picks;
        }
        if(xyz == 0) {
            if(abc == 0) xyz = 2;
            else if(abc == 1) xyz = 0;
            else if(abc == 2) xyz = 1;
        }
        else if(xyz == 1) xyz = abc;
        else if(xyz == 2) {
            if(abc == 0) xyz = 1;
            else if(abc == 1) xyz = 2;
            else if(abc == 2) xyz = 0;
        }
        diff = abc - xyz;
        diff = abs(diff);
        score = score + xyz + 1;
        if((xyz > abc && diff == 1) || (xyz < abc && diff != 1)) score = score + 6;
        else if(abc == xyz) score = score + 3;
        else score = score + 0;
    }
    printf("your total score: %d\n", score);
    return 0;
}
