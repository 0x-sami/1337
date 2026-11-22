_This project has been created as part of the 42 curriculum by ysalama._

# ft_printf

## Description

**ft_printf** is a reimplementation of the C standard library's `printf()` function. The goal is to reproduce its basic formatted-output behavior while learning how variadic functions work in C.

The implementation writes to standard output and supports the mandatory conversions:

## Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. Prints `(null)` if the string is NULL. |
| `%p` | Prints a pointer address in hexadecimal format, prefixed with `0x`. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a literal percent sign. |

## Bonus Flags

The project also supports the following bonus flags:

| Flag | Description |
|---|---|
| `%+d` | Prints a `+` sign before positive numbers and a `-` sign before negative numbers. |
| `%+i` | Same as `%+d`, but uses the `%i` conversion. |
| `% d` | Prints a leading space before positive numbers. Negative numbers retain their `-` sign. |
| `% i` | Same as `% d`, but uses the `%i` conversion. |
| `%#x` | Adds the `0x` prefix to non-zero hexadecimal numbers. |
| `%#X` | Adds the `0X` prefix to non-zero hexadecimal numbers. |

## Error Handling

`ft_printf` returns the total number of characters printed on success.

It returns `-1` if a write operation fails or an invalid format specifier is encountered.

The project does not reproduce the buffering system of the original `printf()`.

## Instructions

### Requirements

- A C compiler (`cc`).
- GNU Make.
- `ar` (used to create the static library).

### Build

Clone the repository and enter its root directory.

Build the library:

```sh
make
```

This creates `libftprintf.a` inside the root directory.

To remove the object files:

```sh
make clean
```

To remove the object files including the library:

```sh
make fclean
```

### Use the library

Include `ft_printf.h` and link against the static library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d, hex: %x\n", "world", 42, 42);
    return (0);
}
```

Compile from the repository root:

```sh
cc main.c libftprintf.a -o example
./example
```

## Algorithm and implementation

### 1. Format-string parsing

`ft_printf()` scans the format string from left to right using an integer index.

- Ordinary characters are written directly to standard output.
- When it encounters `%`, it advances to the next character and passes that conversion specifier to `ft_print_handler()`.
- The handler selects the appropriate printing function and retrieves its argument with `va_arg()`.
- Each printing function returns a character count, which is accumulated by `ft_printf()`.

If the main loop or a conversion handler returns `-1`, `ft_printf()` ends the variadic argument processing with `va_end()` and returns `-1`.

### 2. Variadic arguments

The function uses a `va_list` to access the arguments following the format string:

- `va_start()` initializes the argument list.
- `va_arg()` retrieves each argument using the type expected by its conversion.
- `va_end()` finishes processing the argument list.

Arguments are retrieved in the same order as their corresponding conversion specifiers appear in the format string.

### 3. Decimal conversion

Signed and unsigned decimal values are printed recursively in base 10.

For each number, the function divides it by 10 and recursively prints the quotient while it is non-zero. It then prints the remainder as a decimal digit. This prints the most significant digit first without requiring a temporary digit array.

For signed values, a minus sign is printed first when the number is negative. Unsigned values are handled separately so their decimal representation is not interpreted as signed.

### 4. Hexadecimal conversion

Hexadecimal output uses the same recursive division approach, but with base 16:

1. Divide the value by 16.
2. Recursively print the quotient if it is non-zero.
3. Use the remainder as an index into a hexadecimal digit table.

The `%x` conversion uses the lowercase digit table, while `%X` uses the uppercase table.

Pointer values are converted to `uintptr_t`, printed in hexadecimal, and preceded by `0x`. The current implementation prints a null pointer as `(nil)`.

### 5. Data structures and design choices

The implementation does not require a complex data structure. It uses:

- A `va_list` to traverse the variable arguments.
- Integer indexes and counters to track the format-string position and number of characters written.
- `uintptr_t` to hold a pointer value in an integer type suitable for pointer conversion.
- Constant character tables to map numeric remainders to hexadecimal digits.

The recursive conversion approach avoids allocating memory or storing the digits in a separate array. Printing helpers are separated by responsibility: character and string output, decimal output, and hexadecimal and pointer output.

## Project structure

| File | Responsibility |
| --- | --- |
| `ft_printf.c` | Main function, format parsing, and conversion dispatch. |
| `ft_printf.h` | Function prototypes and required headers. |
| `print_utils_chars.c` | Character and string output. |
| `print_utils_nbr.c` | Signed and unsigned decimal output. |
| `print_utils_hex.c` | Hexadecimal and pointer output. |
| `Makefile` | Builds `libftprintf.a` and provides cleanup rules. |

## Resources

### References

- **42 ft_printf subject, version 12.1** — project requirements and supported conversions.
- [printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html): standard `printf()` behavior and conversion specifications.
- [stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html): variadic argument macros such as `va_start`, `va_arg`, and `va_end`.
- [write(2)](https://man7.org/linux/man-pages/man2/write.2.html): writing output to file descriptors.
- [GNU Binutils: ar](https://sourceware.org/binutils/docs/binutils/ar.html): creating and managing static libraries.

### AI usage

AI assistance was used to investigate potential bugs, and also used to help draft this README.
