_This project has been created as part of the 42 curriculum by ysalama._

# Libft

## Description

Libft is the first library built during the 42 curriculum. The project consists
of implementing a collection of general-purpose C functions that can be reused
in future projects. It recreates selected functions from the C standard
library, adds string and output utilities, and provides tools for working with
linked lists.

The compiled library is named `libft.a`. Its public function declarations and
linked-list type are defined in [`libft.h`](./libft.h).

## Library contents

The mandatory project is divided into three parts.

### Part 1: Reimplemented libc functions

This part recreates selected functions from the C standard library. Each
function uses the `ft_` prefix (for example, `strlen` becomes `ft_strlen`) and
must follow the behavior of its original counterpart. These implementations
must not rely on other external functions.

### Part 2: Additional functions

This part adds utility functions that are not part of libc or provide a
different interface. They allocate and transform strings, apply callbacks to
string characters, and write values to file descriptors.

### Part 3: Linked-list functions

The final part introduces a singly linked list. Each node is represented by
the `t_list` structure declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `content` points to the data stored in the node. It is a `void *`, so a node
  can hold a pointer to data of any type.
- `next` points to the next node. It is `NULL` when the node is the last one.

## Instructions

### Requirements

- A C compiler such as `cc` or `clang`
- `make`

### Compilation

From the project directory, build the static library with:

```sh
make
```

The Makefile builds `libft.a` at the root of the repository. The project
subject requires compilation with `-Wall -Wextra -Werror` and creation of the
archive using `ar`.

The Makefile provides the standard rules:

- `make` or `make all`: builds the library.
- `make clean`: removes object files.
- `make fclean`: removes object files and the compiled library.
- `make re`: performs a clean rebuild.

### Using the library

Include the header in your C source file:

```c
#include "libft.h"
```

Compile your program with the library, for example:

```sh
cc main.c libft.a -o program
```

## Resources

### References

- [42 Libft subject](https://cdn.intra.42.fr/pdf/pdf/226739/en.subject.pdf)
  project requirements and expected function behavior.
- [cppreference: C library](https://en.cppreference.com/w/c)
  reference for C library functions.
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)
  descriptions of library functions and their behavior.
- [FreeBSD manual](https://man.freebsd.org/cgi/man.cgi)
  reference for functions such as `strlcpy` and `strlcat`.
- [C documentation](https://devdocs.io/c/)
  searchable C language and library documentation.
- [CS50: Linked lists](https://cs50.harvard.edu/x/notes/5/#linked-lists)
  introductory explanation of linked-list data structures.

### AI usage

AI usage was limited to the built-in search assist tool in search engines.
