when passing null null to memmove, it segfaults, but passing null null to ft_memmove returns null, this needs defense.

# Libft defense questions

This project builds a static library, `libft.a`, from the explicitly listed
source files in the Makefile. The functions are grouped into character tests,
memory/string helpers, allocation/string transformations, output helpers, and
linked-list helpers.

## Build system

### Makefile

- What does `NAME=libft.a` mean, and why is the output a static library?
- How is `OBJS=$(SRCS:.c=.o)` derived?
- How does the `%.o: %.c` pattern rule compile each C file into an object file?
- Why is `cc` used directly in the pattern rule instead of a `CC` variable?
- What does `$(AR)` expand to, and what do the `-r`, `-s`, and `-c` options do?
- Why does `all` depend only on `$(NAME)` rather than running `clean`
  automatically after a successful build?
- What happens if a new C file is added but is not added to `SRCS`?
- What does each target do: `make`, `make clean`, `make fclean`, and `make re`?
- What happens when a header changes? Does this Makefile know that object
  files must be rebuilt?
- Why is `rm -f` used for object files and the library?
- Why are `all`, `clean`, `fclean`, and `re` marked `.PHONY`?

## Character classification and conversion

### ft_isalpha.c

- How does `ft_isalpha` distinguish uppercase and lowercase ASCII letters?
- What does it return for negative values, extended characters, and digits?
- Why does it return an `int` instead of a `char` or `bool`?

### ft_isdigit.c

- Which exact ASCII range is accepted by `ft_isdigit`?
- Why is this function independent of locale?
- Does it accept signs, whitespace, or numeric characters outside ASCII?

### ft_isalnum.c

- How does `ft_isalnum` combine the alphabetic and digit checks?
- Does it accept only ASCII letters and digits?
- Could it reuse `ft_isalpha` and `ft_isdigit` instead of repeating ranges?

### ft_isascii.c

- What range does `ft_isascii` accept?
- Why is 127 included?
- What happens for values below zero or above 127?

### ft_isprint.c

- What is the difference between a printable character and an ASCII
  character?
- Why is the accepted range 32 through 126?
- Are control characters such as newline and tab printable?

### ft_tolower.c

- When does `ft_tolower` change its input?
- What does it return for uppercase ASCII, lowercase ASCII, digits, and
  non-ASCII values?
- Why does it return an `int`?

### ft_toupper.c

- When does `ft_toupper` change its input?
- What happens to already-uppercase, numeric, and non-ASCII values?
- How would you make the implementation locale-aware, and why is that
  outside this project?

## Memory and libc-style functions

### ft_strlen.c

- How does the loop find the end of a C string?
- What is the time complexity?
- What happens if `s` is `NULL`?
- Why is the index an `int` while the return type is `size_t`?

### ft_memset.c

- Why is the value converted to `unsigned char` before writing?
- Does `ft_memset` require the destination to be a string?
- What does it return?
- What happens when `n` is zero?

### ft_bzero.c

- How is `ft_bzero` implemented using `ft_memset`?
- Why should the length parameter normally be `size_t`?
- What is the consequence of this implementation declaring `n` as
  `unsigned char`? Which lengths are truncated?
- Is the header prototype consistent with the implementation and the usual
  libft specification?

### ft_memcpy.c

- What does `ft_memcpy` guarantee about overlapping source and destination
  buffers?
- Why is `ft_memmove` required for overlap?
- Why is the loop index an `int` even though `n` is `size_t`?
- What happens when `n` is zero?
- What assumptions are made about `dest` and `src` when `n` is nonzero?

### ft_memmove.c

- How does comparing the source and destination addresses decide copy
  direction?
- Why does a destination after the source copy backwards?
- Why does a destination before the source copy forwards?
- What happens when both pointers are equal?
- Why must pointer arithmetic and the ranges be valid before calling this
  function?

### ft_memchr.c

- Why is the memory viewed as `unsigned char`?
- Why is `c` cast to `unsigned char`?
- Does it stop at a null byte?
- What does it return when no byte matches or `n` is zero?

### ft_memcmp.c

- Why does it compare bytes as `unsigned char`?
- Does it return only -1, 0, and 1, or can it return the byte difference?
- Why are the buffers allowed to contain null bytes?
- What happens when `n` is zero?

### ft_strchr.c

- Does it search for the terminating null byte when `c` is zero?
- Why is `c` converted to `unsigned char` for comparison?
- What is the difference between returning the first match and returning
  `NULL`?
- Why does the implementation cast away `const` in its return path?

### ft_strrchr.c

- How does it find the last occurrence rather than the first?
- How is a search for `'\0'` handled?
- What does it return if the character is absent?
- Why is the returned pointer allowed to point into the original string?

### ft_strncmp.c

- Does `ft_strncmp` compare at most `n` bytes or complete strings?
- Why should bytes be interpreted as `unsigned char`?
- What happens if a null terminator is encountered before `n`?
- What happens when `n` is zero?

### ft_strnstr.c

- What does the `len` limit apply to: the haystack search, the match, or
  both?
- Why should an empty `little` string return `big`?
- What happens when `little` is longer than the permitted haystack region?
- Does this implementation preserve the expected behavior when `len` is
  zero?

### ft_strlcpy.c

- What value does it return, and how can that value detect truncation?
- What happens when `size` is zero?
- Why must the destination be terminated when `size` is nonzero?
- Does it copy the source terminator as part of the bounded operation?
- What destination capacity is required by the caller?

### ft_strlcat.c

- What does the return value represent when concatenation is truncated?
- How is the existing destination length bounded by `size`?
- Why does it return `size + src_len` when no null terminator is found in
  the first `size` bytes?
- What happens when `size` is zero?
- What precondition is required for `dst` to be a valid string when its
  terminator is within the available size?

## Parsing and allocation

### ft_atoi.c

- Which whitespace characters are skipped?
- How are an optional sign and the digit loop handled?
- What happens at the first non-digit after a valid prefix?
- Why is `result` a `long` but the return type is `int`?
- What happens on overflow or underflow? Does this match the standard
  `atoi` contract?
- What happens for an empty string, a sign without digits, or a `NULL`
  pointer?

### ft_calloc.c

- Why is the multiplication overflow checked before calculating the total?
- Why is the zero-size multiplication case allowed?
- How does `malloc` failure propagate?
- Why is the allocated memory explicitly zeroed?
- What does `calloc(0, 0)` or `calloc(0, size)` return on this
  implementation?

### ft_strdup.c

- How much memory is allocated, and where is the terminating null byte
  copied?
- What happens if allocation fails?
- How many times is the source length calculated?
- What happens when `s` is `NULL`?

### ft_substr.c

- What should happen when `start` is beyond the source string?
- How is the requested length clipped to the remaining source?
- Why is one extra byte allocated?
- Is the null check performed before every use of `s`?
- What is the consequence of calling `ft_strlen(s)` before checking `s`?
- What happens when `start > slen` in the `len = slen - start`
  calculation?

### ft_strjoin.c

- How is the allocation size computed?
- Why are `NULL` inputs rejected?
- How are the two strings copied and terminated?
- Why are the length variables `int` rather than `size_t`?
- What happens if the length addition overflows or allocation fails?

### ft_strtrim.c

- How is membership in the trim set tested?
- How are leading and trailing characters removed?
- What should happen when the input is empty or consists entirely of
  characters from `set`?
- Why is the condition `i == ft_strlen(s1) + 1` suspicious for an
  all-trimmed string?
- Can the trailing loop read before the beginning of `s1`?
- Is allocation failure for the empty result handled?
- What happens for `NULL` inputs or an empty trim set?

### ft_split.c

- How does `count_words` treat consecutive delimiters and delimiters at
  either end?
- Why is the returned array terminated by `NULL`?
- How are individual words allocated?
- What happens if allocating one word fails after earlier words succeeded?
- Does `free_all` free exactly the already-created words?
- What happens for `NULL`, an empty string, or a string containing only
  delimiters?
- Why is `libft.h` included twice, and is that harmless because of the
  include guard?
- Are the word count and allocation calculations safe for extremely large
  input?

### ft_itoa.c

- How are zero and `INT_MIN` handled specially?
- Why can negating the most negative `int` overflow, and how does the
  special case avoid it?
- How does `n_len` determine the allocation size?
- Why are digits initially written in reverse order?
- Why must `strrev` leave the minus sign at index zero?
- What happens if allocation fails?
- Is `n_len` safe for every `int` value?

## Higher-level string functions

### ft_strmapi.c

- What does the callback receive: the character index and the character?
- Does the original string change?
- How is the result allocated and terminated?
- What happens if the input or callback is `NULL`?
- What happens if allocating the result fails?

### ft_striteri.c

- How does this differ from `ft_strmapi`?
- Why does the callback receive a pointer to each character?
- Can the callback modify the original string?
- What happens if `s` or `f` is `NULL`?

## File-descriptor output

### ft_putchar_fd.c

- What system call is used to write one character?
- What does the `fd` argument represent?
- What happens when the descriptor is invalid or the write is interrupted?
- Is the write result checked?

### ft_putstr_fd.c

- How is the whole string written?
- What happens when `s` is `NULL`?
- Does the function add a newline?
- Is a partial write or write error reported to the caller?

### ft_putendl_fd.c

- How does it differ from `ft_putstr_fd`?
- Is the newline written separately?
- What happens when the string or descriptor is invalid?

### ft_putnbr_fd.c

- How are positive, negative, zero, and `INT_MIN` values handled?
- How are decimal digits produced recursively or iteratively?
- Why must `INT_MIN` be treated carefully?
- What happens if writing to the descriptor fails?

## Linked-list functions

### ft_lstnew.c

- What fields are initialized in a new node?
- Does the function copy `content` or only store the pointer?
- What happens when node allocation fails?
- Why is `next` initialized to `NULL`?

### ft_lstadd_front.c

- How is a node inserted at the beginning?
- What happens when `lst` or `new` is `NULL`?
- Why must the caller pass a pointer to the list head?

### ft_lstsize.c

- What is the time complexity?
- What does it return for an empty list?
- Why is the return type `unsigned int`, and what happens for a list larger
  than that type can represent?

### ft_lstlast.c

- How is the last node found?
- What does it return for an empty list?
- What happens if the list contains a cycle?

### ft_lstadd_back.c

- How does it handle an empty list versus a non-empty list?
- Why does it need `ft_lstlast`?
- What is the time complexity?
- What happens if `new` or `lst` is `NULL`?

### ft_lstdelone.c

- Why is the content destructor called before freeing the node?
- Does it free the node's `next` node?
- What happens when the destructor callback is `NULL`?
- Why does the caller remain responsible for unlinking the node?

### ft_lstclear.c

- How does it save the next node before deleting the current one?
- Why must it set `*lst` to `NULL` at the end?
- How does it behave for an empty list?
- What happens if `lst` or `del` is `NULL`?

### ft_lstiter.c

- What does the callback receive?
- Does iteration modify links or only allow content-side effects?
- What happens if the list or callback is `NULL`?
- What happens if the callback changes the current node's `next` pointer?

### ft_lstmap.c

- Does it create a new list or modify the original list?
- In what order are mapped nodes appended?
- What happens if `f` returns `NULL` as valid content?
- How is a node allocation failure cleaned up?
- Why are both the newly mapped content and the already-created mapped
  contents passed to `del` on failure?
- What happens when `lst` is empty?
- What happens if `f` or `del` is `NULL`?
- What is the time complexity when `ft_lstadd_back` traverses the result for
  every node?

## Cross-file questions to know

- Which functions allocate memory, and who owns and frees each returned
  allocation?
- Which functions require null-terminated strings and which operate on
  arbitrary byte buffers?
- Which functions return `NULL`, an empty allocation, or a numeric sentinel
  on failure or absence?
- Which functions have undefined behavior for `NULL` inputs?
- Where are `size_t`, `unsigned int`, `int`, and `unsigned char` used, and
  why do their ranges matter?
- Which functions must preserve overlap safety?
- How are allocation failures handled consistently in `ft_split`,
  `ft_lstmap`, and the string allocation helpers?
- How would you test every function with empty input, boundary values,
  allocation failure, invalid descriptors, and maximum integer values?
