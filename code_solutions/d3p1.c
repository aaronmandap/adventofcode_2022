#include <stdio.h>

int main() {
    char buffer[1024] = {0};
    int alphabet_count = 26;
    char all_letters[alphabet_count * 2];
    int first_half, second_half, finder, letter, index, counter, next;
    int score = 0;

    for(letter = 'a', index = 0; letter < 'a' + alphabet_count; letter++, index++) all_letters[index] = letter;
    for(letter = 'A', index = 26; letter < 'A' + alphabet_count; letter++, index++) all_letters[index] = letter;

    FILE *puzzle_input = fopen("pid3.txt", "r");
    while(fgets(buffer, sizeof(buffer), puzzle_input) != NULL) {
        for(counter = 0; buffer[counter] != '\n'; counter++);
        for(first_half = 0; first_half < counter / 2; first_half++) {
            for(second_half = counter / 2; second_half < counter; second_half++) if(buffer[first_half] == buffer[second_half]) next = 1;
            if(next == 1) break;
        }
        for(finder = 0; finder < alphabet_count * 2; finder++){
            if(buffer[first_half] == all_letters[finder]) {
                score = score + finder +1;
                break;
            }
        }
        next = 0;
    }
    printf("total score: %d\n", score);
    return 0;
}
