#include <stdio.h>

void print_array(size_t size, int array[])
{
    printf("[");
    for(size_t i = 0; i < size; i++)
    {
        if(i != 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

void err_array(void)
{
    // {
    //     int normal_array[] = {1,2,3,4,5};
    //     print_array(5, normal_array);
    // }

    // puts("~~~ Uninitialized Array ~~~");
    // int array[100];
    // print_array(100, array);

    puts("~~~ Shorter Array, greater size ~~~");
    int array_short[100] = {0};
    array_short[100] = 100;
    print_array(1000, array_short);
}


int main(void)
{
    err_array();
    return 0;
}

