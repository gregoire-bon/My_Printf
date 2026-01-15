# My_Printf

A custom implementation of the C standard library `printf` function. This project creates a static library `libprintf.a` that can be linked to your C projects.

## Description

`my_printf` mimics the behavior of the standard `printf` function, allowing formatted output to `stdout`. It handles various format specifiers for integers, characters, strings, and pointers.

## Supported Format Specifiers

The following conversion specifiers are supported:

| Specifier | Description |
| :--- | :--- |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%o` | Unsigned octal |
| `%x`, `%X` | Unsigned hexadecimal (lowercase/uppercase) |
| `%p` | Pointer address |
| `%c` | Single character |
| `%s` | String of characters |
| `%e`, `%E` | Scientific notation (double) |
| `%%` | Literal `%` character |

## Build Instructions

This project uses a `Makefile` for compilation.

### Prerequisites
-   `clang` or `gcc`
-   `make`

### Commands

-   **Build Library:** Compiles the source files and creates `libprintf.a`.
    ```bash
    make
    ```

-   **Clean Objects:** Removes object files (`.o`).
    ```bash
    make clean
    ```

-   **Full Clean:** Removes object files and the library/executables.
    ```bash
    make fclean
    ```

-   **Rebuild:** Performs a full clean and rebuilds the project.
    ```bash
    make re
    ```

-   **Run Example:** Compiles and runs the example program (`example.c`) against the library.
    ```bash
    make run
    ```

-   **Build Example:** Compiles the example program (`example.c`) against the library.
    ```bash
    make example
    ./example
    ```

## Usage

1.  Include the header in your source file:
    ```c
    #include "include/my.h"
    ```

2.  Call `my_printf` exactly as you would call `printf`:
    ```c
    int main(void)
    {
        my_printf("Hello, %s! The year is %d.\n", "World", 2026);
        return 0;
    }
    ```

3.  Compile your program linking with `libprintf.a`:
    ```bash
    clang main.c -L. -lprintf -o my_program
    ```

## Project Structure

-   `src/`: Source files for the implementation.
-   `include/`: Header files (`my.h`).
-   `Makefile`: Build configuration.
-   `example.c`: Example usage of the library.
