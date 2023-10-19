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
            if(you == your[picks]){
                xyz = picks;
                score = score + picks + 1;
            }
        }
        diff = abc - xyz;
        diff = abs(diff);

        if((xyz > abc && diff == 1) || (xyz < abc && diff != 1)) score = score + 6;
        else if(abc == xyz) score = score + 3;
        else score = score + 0;
    }
    printf("your total score: %d\n", score);
    return 0;
}
