#include <stdio.h>

int main()
{
    int character = 0;

    while((character = getchar()) != EOF) {
        printf("Input: '%c' \n", (char) character);
    }

    return 0;
}
