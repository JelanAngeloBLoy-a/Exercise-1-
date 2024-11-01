#include <stdio.h>
#include <ctype.h>

int main() {
    
    char lowerTest[] = {'p', 'P', '5', '!'};

    printf("According to islower:\n");
    int i; 
    for (i = 0; i < 4; i++) {
        char ch = lowerTest[i];
        if (islower(ch)) {
            printf("%c is a lowercase letter\n", ch);
        } else {
            printf("%c is not a lowercase letter\n", ch);
        }
    }

    printf("\n");

    // Test for isupper
    char upperTest[] = {'D', 'd', '8', '&'};

    printf("According to isupper:\n");
    for (i = 0; i < 4; i++) {
        char ch = upperTest[i];
        if (isupper(ch)) {
            printf("%c is an uppercase letter\n", ch);
        } else {
            printf("%c is not an uppercase letter\n", ch);
        }
    }

    printf("\n");

    
    char convertToUpper[] = {'u', '7', '$'};
    char convertToLower[] = {'L'};

    for (i = 0; i < 3; i++) {
        char ch = convertToUpper[i];
        char upperCh = toupper(ch);
        printf("%c converted to uppercase is %c\n", ch, upperCh);
    }

    for (i = 0; i < 1; i++) {
        char ch = convertToLower[i];
        char lowerCh = tolower(ch);
        printf("%c converted to lowercase is %c\n", ch, lowerCh);
    }

    return 0;
}
