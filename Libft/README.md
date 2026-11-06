_This project has been created as part of the 42 curriculum by ysalama._

# Libft

## Description

Libft is a C library that recreates a selection of standard C library
functions and adds utility functions commonly used in later 42 projects. The
goal of the project is to build a reliable foundation while practicing memory
management, pointer manipulation, string handling, and linked-list data
structures. The library is delivered as `libft.a`.

The public declarations and the `t_list` structure are provided by
[`libft.h`](./libft.h).

## Instructions

### Requirements

- A C compiler such as `cc` or `clang`
- `make`

### Compilation

From the project directory, build the static library with:

```sh
make
```

The resulting `libft.a` can be linked into another C program together with the
header:

```c
#include "libft.h"
```

## Resources

### References

- [42 Libft subject](https://cdn.intra.42.fr/pdf/pdf/226739/en.subject.pdf) project requirements and expected function behavior.
- [cppreference: C library](https://en.cppreference.com/w/c)
  [GNU C Library manual](https://www.gnu.org/software/libc/manual/)
  [FreeBSD manual](https://man.freebsd.org/cgi/man.cgi) descriptions of functions and their edge cases.
- [C documentation](https://devdocs.io/c/) searchable C language and library reference.
- [CS50](cs50.harvard.edu/x/notes/5/#linked-lists) resource used for understanding linked lists.

### Testing
- [LibftTester](https://github.com/Tripouille/libftTester)

Note that `LibftTester` requires [`valgrind`](https://valgrind.org/) to run.

### AI usage

AI usage was limited to the built-in search assist tool in search engines.
