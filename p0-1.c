#include <stdio.h>
#include <ctype.h>

//struct to store the letter count for each letter
struct alphabet{
    int count[26];
};

//initial count
void initCounts(struct alphabet *lc){
    for (int i = 0; i < 26; i++){
        lc ->count[i] = 0;
    }
}
//read the file and count letters
void countLetters(FILE *file, struct alphabet *lc) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            lc->count[ch - 'a']++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <alice.txt>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    struct alphabet lc;
    initCounts(&lc);
    countLetters(file, &lc);

    fclose(file);

    printf("Letter counts:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, lc.count[i]);
    }

    return 0;
}