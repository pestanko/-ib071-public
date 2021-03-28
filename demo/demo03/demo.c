#include <stdio.h>

void array_info_param(size_t size, int array[size]);
void array_info_const(int array[5]);
void array_demo(void);
void ptr_demo(void);


int main(void) {
  array_demo();

  //ptr_demo();
  return 0;
}

void array_demo(void)
{
  printf("\n~~ ARRAY DEMO START ~~\n");
  int array[] = {1,2,3,4,5};
  size_t bytes =  sizeof(array);
  size_t elem_size = sizeof(*array);
  size_t size = sizeof(array)/sizeof(*array);
  printf("SIZES:\n(bytes: %zu, size_of_one: %zu, n of elements: %zu)\n", bytes, elem_size, size);
  printf("\n----------------\n");
  array_info_param(size, array);
  printf("\n----------------\n");
  array_info_const(array);


  printf("\n~~ ARRAY DEMO END ~~\n");
}

// we could also use int *array as argument
void array_info_param(size_t size, int array[])
{
  size_t elem_size = sizeof(*array);
  size_t bytes = size * elem_size;
  printf("SIZES:\n(bytes: %zu, size_of_one: %zu, n of elements: %zu)\n", bytes, elem_size, size);
  printf("Address of first element: %p (alt: %p)\n", array, &array[0]);
  printf("First element value: %d (alt: %d)\n", array[0], *array);
  for(size_t i = 0; i < size; i++){
    printf("Element %zu: %2d at address %p\n", i, array[i], &array[i]);
  }
}

void array_info_const(int array[]) // this is wrong
{
  size_t elem_size = sizeof(*array);
  size_t bytes = sizeof(array);
  size_t size = bytes / elem_size;
  printf("SIZES:\n(bytes: %zu, size_of_one: %zu, n of elements: %zu)\n", bytes, elem_size, size);
  printf("Address of first element: %p (alt: %p)\n", array, &array[0]);
  printf("First element value: %d (alt: %d)\n", array[0], *array);
  for(size_t i = 0; i < size; i++){
    printf("Element %zu: %2d at address %p\n", i, array[i], &array[i]);
  }
}

void inc_num(int number)
{
  number++;
}

int inc_ptr(int *ptr)
{
  (*ptr)++;
}

void ptr_demo(void)
{
  printf("\n~~ PTR DEMO START ~~\n\n");
  int num = 10;
  int *ptr_num = &num; // give me an address
  printf("(initset) num:     %d (addr: %p)\n", num, &num);
  printf("(initset) ptr_num: %d (addr: %p)\n", *ptr_num, ptr_num);

  num = 100;
  printf("(num set) num: %4d (ptr_num: %d)\n", num, *ptr_num);
  *ptr_num = 1000;
  printf("(ptr set) num: %4d (ptr_num: %d)\n", num, *ptr_num);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  num = 10;
  inc_num(num); // will it be 11?
  printf("(inc_num norm) num: %d (ptr_num: %d)\n", num, *ptr_num);
  inc_ptr(&num);
  printf("(inc_ptr &num) num: %d (ptr_num: %d)\n", num, *ptr_num);
  inc_ptr(ptr_num);
  printf("(inc_ptr ptr)  num: %d (ptr_num: %d)\n", num, *ptr_num);

  printf("\n~~ PTR DEMO END ~~\n");
}

