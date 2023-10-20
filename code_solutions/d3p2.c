#include <stdio.h>

int main() {
    char line_buffer[1024] = {0};
    int alphabet_count = 26;
    char all_letters[alphabet_count * 2];
    int first, second, third, finder, letter, index, counter, next;
    int score = 0, line_counter = 0, reset_line = 0;
    char group_rucksack[sizeof(line_buffer)] = {0};
    int item_tally[3] = {0};

    for(letter = 'a', index = 0; letter < 'a' + alphabet_count; letter++, index++) all_letters[index] = letter;
    for(letter = 'A', index = 26; letter < 'A' + alphabet_count; letter++, index++) all_letters[index] = letter;

    FILE *puzzle_input = fopen("../puzzle_inputs/pid3.txt", "r");
    while(fgets(line_buffer, sizeof(line_buffer), puzzle_input) != NULL) {
        if(line_counter == 0) {
            for(item_tally[0] = 0; line_buffer[item_tally[0]] != '\n'; item_tally[0]++);
            for(first = 0, counter = 0; first < item_tally[0]; first++, counter++) {
                group_rucksack[first] = line_buffer[counter];
            }
        }
        if(line_counter == 1) {
            for(item_tally[1] = 0; line_buffer[item_tally[1]] != '\n'; item_tally[1]++);
            for(second = item_tally[0], counter = 0; second < item_tally[0] + item_tally[1]; second++, counter++) {
                group_rucksack[second] = line_buffer[counter];
            }
        }
        if(line_counter == 2) {
            for(item_tally[2] = 0; line_buffer[item_tally[2]] != '\n'; item_tally[2]++);
            for(third = item_tally[0] + item_tally[1], counter = 0; third < item_tally[0] + item_tally[1] + item_tally[2]; third++, counter++) {
                group_rucksack[third] = line_buffer[counter];
            }
            for(first = 0; first < item_tally[0]; first++) {
                for(second = item_tally[0]; second < item_tally[0] + item_tally[1]; second++) {
                    if(group_rucksack[first] == group_rucksack[second]){
                        for(third = item_tally[0] + item_tally[1]; third < item_tally[0] + item_tally[1] + item_tally[2]; third++) {
                            if(group_rucksack[first] == group_rucksack[third]){
                                next = 1;
                                break;
                            }
                        }
                    }
                } 
                if(next == 1) break;
            }
            for(finder = 0; finder < alphabet_count * 2; finder++){
                if(group_rucksack[first] == all_letters[finder]) {
                    score = score + finder + 1;
                }
            }
            reset_line = 1;
            next = 0;
        }
        if(reset_line == 1) {
            line_counter = 0;
            reset_line = 0;
        }
        else line_counter++;
    }
    printf("sum of priorities: %d\n", score);
    return 0;
}
