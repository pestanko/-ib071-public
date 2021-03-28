#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define COLS 5
#define ROWS 4

#define HALF ((COLS * ROWS) / 2)
#define MIN -HALF
#define MAX HALF

void fill_matrix(int min_value, int max_value, size_t mrows, size_t mcols, int matrix[mrows][mcols]);
void print_matrix(size_t mrows, size_t mcols, int matrix[mrows][mcols]);
void print_row(size_t mcols, int row[mcols]);
void inc_by_one(size_t mrows, size_t mcols, int *matrix[]);

int main(void)
{
    //srand(time(NULL));

    int matrix[ROWS][COLS] = {{0, 1, 2, 3, 4}, {10}, {100, 101}};

    puts("\nManual matrix:");
    print_matrix(ROWS, COLS, matrix);

    puts("\nRandom matrix:");
    fill_matrix(MIN, MAX, ROWS, COLS, matrix);
    print_matrix(ROWS, COLS, matrix);

    puts("\n\nUkazatelova aritmetika:");
    int arr[10] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
    printf("Value @ [5] =%3d", arr[5]);
    printf("Value @ [5] =%3d", *(arr + 5));
    printf("Value @ [5] =%3d (wrong)", *arr + 5);
    *(arr + 5) = 55;
    printf("Value @ [5] =%3d should be 55", arr[5]);

    for (size_t i = 0; i < 10; i++)
    {
        // if this is not ture program will fail
        assert(arr[i] == *(arr + i));

        // For example this will fail:
        //assert(arr[i] == 1);
    }

    puts("\nOperations:");
    printf("Value @ [1][0] =%3d\n", matrix[1][0]);
    printf("Value @ [1][0] =%3d\n", *matrix[1]);
    printf("Value @ [1][1] =%3d\n", matrix[1][1]);
    printf("Value @ [1][1] =%3d\n", *(matrix[1] + 1));
    printf("Value @ [1][1] =%3d\n", *(*(matrix + 1) + 1));
    int *row = matrix[1];
    printf("Value @ [1][1] =%3d\n", row[1]);

    puts("\n\nAdvanced operations with pointers:");
    // be aware rows is not an 2D array!!! it is an array of pointers
    int other[] = {50,51,52,53,54};
    int *rows[] = {matrix[0], matrix[1], matrix[2], other};
    for (size_t row = 0; row < 4; row++)
    {
        printf("Row %zu: ", row);
        print_row(COLS, rows[row]);
    }

    int *matrix_inline = (int *) matrix;
    printf("Inlined matrix: ");
    print_row(ROWS * COLS, matrix_inline);

//    puts("\n\nDANGER DANGER: ");
//    inc_by_one(ROWS, COLS, matrix);
//    print_matrix(ROWS, COLS, matrix);

    return 0;
}


void fill_matrix(int min_value, int max_value, size_t mrows, size_t mcols, int matrix[mrows][mcols])
{
    if (max_value <= min_value)
    {
        return;
    }
    int range = (max_value - min_value);
    for (size_t row = 0; row < mrows; row++)
    {
        for (size_t col = 0; col < mcols; col++)
        {
            matrix[row][col] = rand() % range + min_value;
        }
    }
}

void print_matrix(size_t mrows, size_t mcols, int matrix[mrows][mcols])
{
    for (size_t i = 0; i < mrows; i++)
    {
        for (size_t j = 0; j < mcols; j++)
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_row(size_t mcols, int row[mcols])
{
    for (size_t j = 0; j < mcols; j++)
    {
        printf("%3d ", row[j]);
    }
    printf("\n");
}

void inc_by_one(size_t mrows, size_t mcols, int *matrix[])
{
    for (size_t row = 0; row < mrows; row++)
    {
        for (size_t col = 0; col < mcols; col++)
        {
            matrix[row][col] += 1;
        }
    }
}


