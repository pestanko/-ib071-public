#include <stdio.h>

void scanf_demo(void)
{
    printf("Please provide some number: ");
    int number;
    scanf("%d", &number); // what the scanf function returns?
    printf("You have provided: %d [0x%06x]\n", number, number);

    printf("\nPlease press your favourite character: ");
    char ch;
    scanf(" %c", &ch); // TODO: FIX ME
    printf("Provided character: %c [hex: 0x%02x, dec: %3d]\n", ch, ch, ch);

    printf("\nPlease provide your age and first name initial separated by space (example: 15 J): ");
    unsigned age;
    char initial;
    scanf("%u %c", &age, &initial);
    printf("You are %u old and your first name initial is \'%c\'\n", age, initial);
}

void getchar_demo(void)
{
  printf("Please provide your name: ");
  int ch;
  while((ch = getchar()) != EOF && ch != '\n')
  {
    printf("Provided char: %c (%03d)\n", (char) ch, ch);
  }
}

int main(void)
{
  //getchar_demo();
  scanf_demo();

  return 0;
}

