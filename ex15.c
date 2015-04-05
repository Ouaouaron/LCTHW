#include <stdio.h>

int main(int argc, char *argv[]) {
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for (i = count-1; i >= 0; i--) { 
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *end_age = ages+(count-1);
    char **end_name = names+(count-1);

    // second way using pointers
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(end_name-i), *(end_age-i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    int *cur_age = ages;
    char **cur_name = names;
    for(i = count-1; i >= 0; i--) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for(;
            (end_age - ages) >= 0;
            end_name--, end_age--) {
        printf("%s lived %d years so far.\n", *end_name, *end_age);
    }

    return 0;
}

