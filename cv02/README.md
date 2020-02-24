# CV02

Na tomto cvičení sa budeme venovať témam:

- HW01 - getchar, bitove operacie
- CMake
- Cisla, premenne, typy
- Riadiace struktuty


## HW01
Zadanie: <https://www.fi.muni.cz/pb071/hw/homework-01/>

- zamerana na bitove operacie, nacitavanie znakov, zakladne riadiace struktury a funkcie

### Dokumentacia:
- <https://en.cppreference.com/w/c/types/integer> (`stdint.h`, `limits.h`)
- <https://en.cppreference.com/w/c/io/getchar> (`getchar`)


### Priklady:

- [getchar_example.c](./getchar_example.c)

```c
#include <stdio.h>

int main()
{
    int character = 0;

    while((character = getchar()) != EOF) {
        printf("Input: '%c' \n", (char) character);
    }

    return 0;
}
```

## CMAKE

- Zdroj: <https://cmake.org/>

CMake is an open-source, cross-platform family of tools designed to build, test and package software.

### Pouzitie 

Pomocou `cmake` si mozete zostavit Vas program napriklad na [`aise`](https://www.fi.muni.cz/pb071/man/#aisa). 

Ako prvy krok je, ze si v terminale otvorime priecinok (`man cd`), v ktorom sa nachadza "nas projekt" - je tam `CMakeLists.txt`.

Manual: <https://www.fi.muni.cz/pb071/man/#cmake> (Urcite sa na to pozrite!)

```bash
# Spusti cmake a "pomocne subory" pre zostavenie suboru vloz do priecinku `build`
cmake -Bbuild 

# zmen aktualny adresar na build
cd build 

# spusti zostavenie projektu
make
```


## Cvicenie 02

Zadanie: <https://www.fi.muni.cz/pb071/seminars/seminar-02/>

### Priklady

[numbers_example.c](./numbers_example.c)

```c
#include <stdio.h>
#include <stdint.h>


int main(void) {
    
    int int_number = 0;
    unsigned long ulong_number = 123456789;
    float float_number = 1.0;
    double double_number = 2.0;

    printf("VAR int_number    = %10d (with size %lu)\n", int_number, sizeof(int_number));
    printf("VAR ulong_number  = %10lu (with size %lu)\n\n", ulong_number, sizeof(ulong_number));
    printf("VAR float_number  = %10f (with size %lu)\n", float_number, sizeof(float_number));
    printf("VAR double_number = %10lf (with size %lu)\n\n", double_number, sizeof(double_number));
    
    // STD INT

    uint8_t b8 = 251;
    uint16_t b16 = 12345;
    uint32_t b32 = 12312312;
    uint64_t b64 = 123456789123;

    printf("b8  = %15u '%c' (with size %lu) \n", b8, b8, sizeof(b8));
    printf("b16 = %15u (with size %lu) \n", b16, sizeof(b16));
    printf("b32 = %15u (with size %lu) \n", b32, sizeof(b32));
    printf("b64 = %15lu (with size %lu) \n\n", b64, sizeof(b64));

    // FUN PART

    char ch = 'A';
    char new_ch = ch + 5;

    printf("Original '%c' [%03d] ~> %c + 5 [%03d + 5] = %c [%03d]\n", ch, ch, ch, ch, new_ch, new_ch);

    return 0;
}
```


### Dokumentacia

- <https://en.cppreference.com/w/c/language/statements> (`if`, `while`, `for`, `switch`)
- <https://en.cppreference.com/w/c/io/fprintf> (`printf`)
- <https://en.cppreference.com/w/c/io/fscanf> (`scanf`)

