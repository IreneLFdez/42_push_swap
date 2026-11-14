*This project was created as part of the 42 curriculum by helemart.*

# README

## Libft - My very first own library

## Description

Libft is a C library developed as part of the 42 curriculum. Its goal is to recreate a selection of standard C library functions and implement additional utility functions for string manipulation, memory management, character handling, and linked list operations.

The project is divided into three sections:

- **Part I** - *Libc functions*: Reimplementations of standard library functions, including character checks, string operations, memory manipulation, conversions, and dynamic memory allocation.
- **Part II** - *Additional functions*: Utility functions for creating and transforming strings, splitting text, converting integers to strings, and writing output to file descriptors.
- **Part III** - *Linked list*: Functions for creating, traversing, modifying, and freeing singly linked lists.

The library is designed to be reusable in future C projects. Each function is implemented according to its expected interface, return value, memory ownership rules, and edge-case behavior.

### PART I - Libc functions

This section talks about the first part of the project, which is mandatory and includes the implementation of these functions:

| Function      | Prototype   | Description   |
| :---          |    :---     | :---          |
| **ft_isalpha**       | int ft_isalpha(int c) | Checks for an alphabetic character (upper or lowercase) |
| **ft_isdigit**       | int ft_isdigit(int c) | Checks for a digit (0 through 9) |
| **ft_isalnum**       | int ft_isalnum(int c) | Checks for an alphanumeric character |
| **ft_isascii**       | int ft_isascii(int c) | Checks whether *c* is a 7-bit unsigned char value that fits into the ASCII character set. |
| **ft_isprint**       | int ft_isprint(int c) | Checks for any printable characters including space. |
| **ft_strlen**        | size_t ft_strlen(const char *s) | Calculates the length of the string pointed to by *s*, excluding the terminating null byte. Returns the number of bytes in the string pointed to by *s*. |
| **ft_memset**        | void *ft_memset(void *s, int c, size_t n) | Fills the first *n* bytes of the memory area pointed to by *s* with the constant byte *c*. Returns a pointer to the memory area of *s*. |
| **ft_bzero**         | void ft_bzero(void *s, size_t n) | Erases the data in the *n* bytes of the memory starting at the location pointed to by *s* by writing zeros to that area. |
| **ft_memcpy** | void *ft_memcpy(void *dest, const void *src, size_t n) | Copies *n* bytes from memory area *src* to memory area *dest*. Returns a pointer to *dest*. |
| **ft_memmove**       | void *ft_memmove(void *dest, const void *src, size_t n) | Copies *n* bytes from memory area *src* to memory area *dest*. Returns a pointer to *dest*. Unlike **memcpy**, **memmove** makes sure there is no overlap. |
| **ft_strlcpy**       | size_t ft_strlcpy(char *dst, const char *src, size_t size) | Copies a string by taking the full size of the buffer (not just the length) and guarantees a NUL-terminated result. The NUL byte is included in *size*. Returns the total length of the string it tried to create, i.e. the length of *src*. |
| **ft_strlcat**       | size_t ft_strlcat(char *dst, const char *src, size_t size) | Appends the source string to the destination string, provided that the destination is NUL-terminated within the specified buffer size. The function appends at most size - strlen(dst) - 1 bytes when space is available and returns the length of the string it attempted to create. |
| **ft_toupper**       | int ft_toupper(int c) | Converts lowercase letters to uppercase. If *c* is neither an unsigned char value nor EOF, the behavior of the function is undefined. |
| **ft_tolower**       | int ft_tolower(int c) | Converts uppercase letters to lowercase. If *c* is neither an unsigned char value nor EOF, the behavior of the function is undefined. |
| **ft_strchr**       | char *ft_strchr(const char *s, int c) | Returns a pointer to the first occurrence of the character *c* (byte) in the string *s*. Returns a pointer to the matched character or NULL if not found. |
| **ft_strrchr**       | char *ft_strrchr(const char *s, int c) | Returns a pointer to the last occurrence of the character *c* (byte) in the string *s*. Returns a pointer to the matched character or NULL if not found. |
| **ft_strncmp**       | int ft_strncmp(const char *s1, const char *s2, size_t n) | Compares the two strings *s1* and *s2*. Returns an integer indicating the result of the comparison: 0 if equal, a negative value if *s1* is less than *s2*, and a positive value if *s1* is greater than *s2*. |
| **ft_memchr**        | void *ft_memchr(const void *s, int c, size_t n) | Scans the initial *n* bytes of the memory area pointed to by *s* for the first instance of *c*. Returns a pointer to the matching byte or NULL if the character does not occur in the given memory area. |
| **ft_memcmp**        | int ft_memcmp(const void *s1, const void *s2, size_t n) | Compares the first *n* bytes of the memory areas *s1* and *s2*. Returns an integer less than, equal to, or greater than zero if the first *n* bytes of *s1* are found, respectively, to be less than, to match, or be greater than the first *n* bytes of *s2*. |
| **ft_strnstr**       | char *ft_strnstr(const char *big, const char *little, size_t len) | Searches for the first occurrence of *little* within the first *len* bytes of *big*. Returns a pointer to the beginning of the match or NULL if no match is found. If *little* is an empty string, the function returns *big*. |
| **ft_atoi**          | int ft_atoi(const char *nptr) | Converts the initial portion of the string to an integer. The function skips leading whitespace, processes an optional sign, and converts consecutive decimal digits until a non-digit character is encountered. If no digits can be converted, it returns 0. If the converted value cannot be represented as an int, the behavior is undefined. |
| **ft_calloc**      | void *ft_calloc(size_t nmemb, size_t size) | Allocates memory for an array of *nmemb* elements, each of *size* bytes, and initializes the allocated memory to zero. Returns a pointer to the allocated memory or NULL if allocation fails. The implementation must detect multiplication overflow before allocating the memory. |
| **ft_strdup**      | char *ft_strdup(const char *s) | Returns a pointer to a new string which is a duplicate of the string *s*. Memory for the new string is obtained with **malloc** and freed with **free**. |



### PART II - Additional functions

This section includes a set of functions that are either not included in libc or exist in a different form. These functions may use the libc function as auxiliary functions.


| Function Name             | ft_substr     |
| :---                      | :---          |
| **Prototype**             | char *ft_substr(char const *s, unsigned int start, size_t len) |
| **Parameters**            | ***s***: The original string from which to create the substring. ***start***: The starting index of the substring within ’s’. ***len***: The maximum length of the substring. |
| **Return Value**          | The substring. NULL if the allocation fails. |
| **External Function**     | malloc |
| **Description**           | Allocates memory (using malloc(3)) and returns a substring from the string ’s’. The substring starts at index ’start’ and has a maximum length of ’len’. |

| Function Name             | ft_strjoin    |
| :---                      | :---          |
| **Prototype**             | char *ft_strjoin(char const *s1, char const *s2) |
| **Parameters**            | ***s1***: The prefix string. ***s2***: The suffix string. |
| **Return Value**          | The new string or NULL if the allocation fails. |
| **External Function**     | malloc |
| **Description**           | Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating ’s1’ and ’s2’. |

| Function Name             | ft_strtrim | 
| :---                      | :---          |
| **Prototype**             | char *ft_strtrim(char const *s1, char const *set) |
| **Parameters**            | ***s1***: The string to be trimmed. set: The string containing the set of characters to be removed |
| **Return Value**          | The trimmed string or NULL if the allocation fails. |
| **External Function**     | malloc |
| **Description**           | Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end. |

| Function Name             | ft_split      |
| :---                      | :---          |
| **Prototype**             | char **ft_split(char const *s, char c) |
| **Parameters**            | ***s***: The string to be split. ***c***: The delimiter character. |
| **Return Value**          | The array of new strings resulting from the split. NULL if any allocation fails. The returned structure will be released using: 1) free() on each string in the array; 2) free() the array itself |
| **External Function**     | malloc |
| **Description**           | Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. Each string in the returned array is allocated independently. The array of pointers itself is also allocated dynamically. The returned array must be NULL terminated. |

| Function Name             | ft_itoa       |
| :---                      | :---          |
| **Prototype**             | char *ft_itoa(int n) |
| **Parameters**            | ***n***: The integer to convert. |
| **Return Value**          | The string representing the integer or NULL if the allocation fails. |
| **External Function**     | malloc |
| **Description**           | Allocates memory and returns a string representing the specified integer. The function must correctly handle positive numbers, negative numbers, zero, INT_MIN, and INT_MAX. Returns NULL if memory allocation fails. |

| Function Name             | ft_strmapi    |
| :---                      | :---          |
| **Prototype**             | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) |
| **Parameters**            | ***s***: The string to iterate over. ***f***: The function to apply to each character. |
| **Return Value**          | The string created from the successive applications of ’f’. Returns NULL if the allocation fails. |
| **External Function**     | malloc |
| **Description**           | Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second. A new string is created (using malloc(3)) to store the results from the successive applications of f. |

| Function Name             | ft_striteri   |
| :---                      | :---          |
| **Prototype**             | void ft_striteri(char *s, void (*f)(unsigned int, char*)) |
| **Parameters**            | ***s***: The string to iterate over. ***f***: The function to apply to each character. |
| **Return Value**          | none |
| **External Function**     | none |
| **Description**           | Applies the function ’f’ to each character of the string passed as argument, passing its index as the first argument. Each character is passed by address to ’f’ so it can be modified if necessary. |

| Function Name             | ft_putchar_fd |
| :---                      | :---          |
| **Prototype**             | void ft_putchar_fd(char c, int fd) |
| **Parameters**            | ***s***: The character to output. ***fd***: The file descriptor on which to write. |
| **Return Value**          | none |
| **External Function**     | write |
| **Description**           | Outputs the character ’c’ to the specified file descriptor. |

| Function Name             | ft_putstr_fd  |
| :---                      | :---          |
| **Prototype**             | void ft_putstr_fd(char *s, int fd) |
| **Parameters**            | ***s***: The string to output. ***fd***: The file descriptor on which to write. |
| **Return Value**          | none |
| **External Function**     | write |
| **Description**           | Outputs the string ’s’ to the specified file descriptor. |

| Function Name             | ft_putendl_fd |
| :---                      | :---          |
| **Prototype**             | void ft_putendl_fd(char *s, int fd) |
| **Parameters**            | ***s***: The string to output. ***fd***: The file descriptor on which to write. |
| **Return Value**          | none |
| **External Function**     | write |
| **Description**           | Outputs the string ’s’ to the specified file descriptor followed by a newline. |

| Function Name             | ft_putnbr_fd |
| :---                      | :---          |
| **Prototype**             | void ft_putnbr_fd(int n, int fd) |
| **Parameters**            | ***n***: The integer to output. ***fd***: The file descriptor on which to write. |
| **Return Value**          | none |
| **External Function**     | write |
| **Description**           | Outputs the integer ’n’ to the specified file descriptor. |


### PART III - Linked list

This section details the implementation of functions that use structs to manipulate linked lists.

| Function Name             | ft_lstnew    |
| :---                      | :---          |
| **Prototype**             | t_list *ft_lstnew(void *content) |
| **Parameters**            | ***content***: The content to store in the new node |
| **Return Value**          | A pointer to the new node |
| **External Function**     | malloc |
| **Description**           | Allocates memory (using malloc(3)) and returns a new node. The ’content’ member variable is initialized with the given parameter ’content’. The variable ’next’ is initialized to NULL. |

| Function Name             | ft_lstadd_front      |
| :---                      | :---          |
| **Prototype**             | void ft_lstadd_front(t_list **lst, t_list *new) |
| **Parameters**            | ***lst***: The address of a pointer to the first node of a list. ***new***: The address of a pointer to the node to be added. |
| **Return Value**          | none |
| **External Function**     | none |
| **Description**           | Adds the node ’new’ at the beginning of the list. |

| Function Name             | ft_lstsize       |
| :---                      | :---          |
| **Prototype**             | unsigned int ft_lstsize(t_list *lst) |
| **Parameters**            | ***lst***: The beginning of the list. |
| **Return Value**          | The length of the list |
| **External Function**     | none |
| **Description**           | Counts the number of nodes in the list. |

| Function Name             | ft_lstlast    |
| :---                      | :---          |
| **Prototype**             | t_list *ft_lstlast(t_list *lst) |
| **Parameters**            | ***lst***: The beginning of the list. |
| **Return Value**          | Last node of the list |
| **External Function**     | none |
| **Description**           | Returns the last node of the list. |

| Function Name             | ft_lstadd_back   |
| :---                      | :---          |
| **Prototype**             | void ft_lstadd_back(t_list **lst, t_list *new) |
| **Parameters**            | ***lst***: The address of a pointer to the first node of a list. ***new***: The address of a pointer to the node to be added. |
| **Return Value**          | none |
| **External Function**     | none |
| **Description**           | Adds the node ’new’ at the end of the list. |

| Function Name             | ft_lstdelone |
| :---                      | :---          |
| **Prototype**             | void ft_lstdelone(t_list *lst, void (*del)(void *)) |
| **Parameters**            | ***lst***: The node to free. ***del***: The address of the function used to delete the content. |
| **Return Value**          | none |
| **External Function**     | free |
| **Description**           | Takes a node as parameter and frees its content using the function ’del’. Free the node itself but does NOT free the next node. |

| Function Name             | ft_lstclear  |
| :---                      | :---          |
| **Prototype**             | void ft_lstclear(t_list **lst, void (*del)(void *)) |
| **Parameters**            | ***lst***: The address of a pointer to a node. ***del***: The address of the function used to delete the content of the node. |
| **Return Value**          | none |
| **External Function**     | free |
| **Description**           | Deletes and frees the given node and all its successors, using the function ’del’ and free(3). Finally, set the pointer to the list to NULL. |

| Function Name             | ft_lstiter |
| :---                      | :---          |
| **Prototype**             | void ft_lstiter(t_list *lst, void (*f)(void *)) |
| **Parameters**            | ***lst***: The address of a pointer to a node. ***f***: The address of the function to apply to each node’s content. |
| **Return Value**          | none |
| **External Function**     | none |
| **Description**           | Iterates through the list ’lst’ and applies the function ’f’ to the content of each node. |

| Function Name             | ft_lstmap  |
| :---                      | :---          |
| **Prototype**             | t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) |
| **Parameters**            | ***lst***: The address of a pointer to a node. ***f***: The address of the function applied to each node’s content. ***del***: The address of the function used to delete a node’s content if needed. |
| **Return Value**          | The new list. NULL if the allocation fails. |
| **External Function**     | malloc, free |
| **Description**           | Iterates through the list ’lst’, applies the function ’f’ to each node’s content, and creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed. |

## Instructions

This section contains any information relevant to the compilation, installation, and execution of the project.

### Notes for compatibility

- The standard ctype functions, including toupper and tolower, require an argument equal to EOF or representable as unsigned char. Passing another value causes undefined behavior. ft_isascii has a different contract and should be tested separately.

- ft_memcpy must not be used with overlapping memory regions. Use ft_memmove instead.

- ft_strlcpy with size == 0 writes no bytes to the destination and still returns the length of src.

- ft_strlcat with size == 0 returns the length of src without accessing the destination buffer. When dst has no null terminator within the first size bytes, the function returns size + strlen(src).

- ft_strchr and ft_strrchr can search for '\0'. In that case, they return a pointer to the string terminator.

- ft_memchr and ft_memcmp operate on raw memory and do not stop at '\0'.

- ft_strncmp compares bytes as unsigned char; the exact nonzero return value is not guaranteed to be identical across implementations.

- ft_calloc must account for overflow in nmemb * size. It must not allocate a smaller block because the multiplication wrapped around.

### Linked list edge cases

- ft_lstnew(NULL) should create a node whose content is NULL, provided the allocation succeeds.

- ft_lstsize(NULL) returns 0.

- ft_lstlast(NULL) returns NULL.

- ft_lstadd_front and ft_lstadd_back must handle an empty list.

- ft_lstdelone must not free lst->next. The caller must manage the links appropriately before deleting a node from an existing list.

- ft_lstclear must leave the head pointer set to NULL after clearing a valid list.

- ft_lstiter must not change the list structure unless the callback itself deliberately modifies the content or performs other side effects.

- ft_lstmap must preserve the original list and construct a separate list. If an allocation fails partway through, all nodes already created for the new list must be released using the appropriate cleanup callback.

- A linked list with a cycle is outside the normal assumptions of these traversal functions and may cause an infinite loop.

The content pointer does not automatically imply ownership of the pointed-to data. The cleanup callback must match the way the content was allocated; passing an incompatible callback can cause invalid memory access or double-free errors


### Undefined Behavior and edge cases

When recreating standard C library functions, their behavior must be reproduced for valid inputs. However, not every invalid input has a defined result.

Undefined behavior (UB) means that the C standard imposes no requirements on what happens. A program may crash, return an unexpected result, corrupt memory, or appear to work correctly. An observed result on one machine must not be treated as a guarantee.

#### Invalid pointers and strings

Most string functions require valid pointers to null-terminated strings. Passing NULL, an uninitialized pointer, a dangling pointer, or a string without a valid terminating null byte can cause undefined behavior.

##### Examples include:

Calling ft_strlen(NULL).
Passing NULL to ft_strdup, ft_strchr, or ft_strncmp.
Reading a string beyond its allocated memory.
Writing to read-only memory using a function that modifies its destination.

A null pointer must not be confused with an empty string. An empty string ("") is a valid string containing a single null terminator; NULL is not a string.

#### Memory overlap and buffer boundaries

ft_memcpy requires non-overlapping source and destination regions. If the regions overlap, its behavior is undefined. ft_memmove is designed for overlapping regions and must preserve the bytes being copied.

Functions that receive a buffer size must never read or write beyond the memory region available to them.

For ft_strlcpy, a destination size of zero means that no bytes are written. For ft_strlcat, the destination must be null-terminated within the specified size for normal concatenation to occur.

A size of zero does not automatically make every pointer argument valid. Do not use NULL pointers as general-purpose test inputs merely because the byte count is zero. 

#### Character classification and conversion

The standard <ctype.h> functions require their argument to be either EOF or representable as unsigned char.

Passing a negative char value directly, when it is neither EOF nor representable as unsigned char, causes undefined behavior. This can happen when processing bytes above 127 on systems where char is signed.

When appropriate, convert the character before passing it to a standard classification or conversion function:

##### ft_isalpha((unsigned char)c);


This rule applies to functions such as isalpha, isdigit, isalnum, isprint, toupper, and tolower. isascii has a different contract and is not governed by the same argument restriction.

#### Integer conversions and overflow

ft_atoi does not provide a standard error-reporting mechanism. If the converted number cannot be represented as an int, the behavior of the corresponding standard conversion is undefined.

A custom implementation must not assume that overflow wraps around or that atoi returns zero on overflow.

Similarly, negating INT_MIN in a signed int may overflow because its positive counterpart is not representable in the same type. This is particularly relevant when implementing ft_itoa.

For ft_calloc, the multiplication of the element count by the element size must be checked for overflow before allocation.

#### Allocation failures

Functions that allocate memory must handle allocation failure explicitly.

String-producing functions should return NULL when allocation fails.
ft_split must release all previously allocated strings and the pointer array if a later allocation fails.
ft_lstmap must free the partially constructed list if creating a node fails.
Callers must not dereference or free an invalid pointer returned by a failed operation.
Testing policy

Undefined behavior should be documented, not used as a passing or failing test case. Tests should focus on valid inputs, defined boundary conditions, correct return values, correct memory effects, and proper cleanup.

### Makefile

The Makefile automates the compilation of the library and the management of its generated files.

Typical rules include:

- make: Compiles the mandatory functions and generates libft.a.
- make clean: Removes object files (.o).
- make fclean: Removes object files and the compiled library (libft.a).
- make re: Performs a full rebuild.

The exact rules depend on the Makefile implementation. The bonus functions must be included in the archive before they can be used by an external program.

To use the library, include its header in the source file:

```#include "libft.h"```


### Testing

Each function should be tested with ordinary inputs, boundary conditions, empty inputs where applicable, and invalid inputs only when their behavior is defined.

When comparing a custom implementation against the original library function, use equivalent inputs and compare their return values and observable effects. For pointer-returning functions, check both whether the result is NULL and whether it points to the expected position.

Tests involving undefined behavior must not be used as ordinary correctness tests. They may crash, produce inconsistent results, or appear to work by accident.

Memory allocation functions should also be checked for allocation failures when possible. Dynamically allocated memory must be released after each test, and linked list tests must verify that all allocated nodes and their contents are freed correctly.

#### ft_isalpha

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== IS ALPHA ==========================\n");
	printf("Checks for an alphabetic character (upper or lowercase).\n");
	printf(" ·1 if the character matches the tested class\n");
	printf(" ·0 if the character does not match\n");
	printf("==============================================================\n");

	printf("'A' : %d\n", ft_isalpha('A'));
	printf("'a' : %d\n", ft_isalpha('a'));
	printf("'1' : %d\n", ft_isalpha('1'));
	printf("'?' : %d\n", ft_isalpha('?'));

	printf("========================== ORIGINAL ==========================\n");
	printf("[DIFF] Will return any non-zero value rather than 1.\n");
	printf("==============================================================\n");

	printf("'A' : %d\n", isalpha('A'));
	printf("'a' : %d\n", isalpha('a'));
	printf("'1' : %d\n", isalpha('1'));
	printf("'?' : %d\n", isalpha('?'));

	return (0);
}
```

#### ft_isdigit

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== IS DIGIT ==========================\n");
	printf("Checks for a digit (0 through 9).\n");
	printf(" ·1 if the character matches the tested class\n");
	printf(" ·0 if the character does not match\n");
	printf("==============================================================\n");

	printf("'0' : %d\n", ft_isdigit('0'));
	printf("'9' : %d\n", ft_isdigit('9'));
	printf("'a' : %d\n", ft_isdigit('a'));
	printf("'*' : %d\n", ft_isdigit('*'));

	printf("========================== ORIGINAL ==========================\n");
	printf("[DIFF] Will return any non-zero value rather than 1.\n");
	printf("==============================================================\n");

	printf("'0' : %d\n", isdigit('0'));
	printf("'9' : %d\n", isdigit('9'));
	printf("'a' : %d\n", isdigit('a'));
	printf("'*' : %d\n", isdigit('*'));

	return (0);
}
```

#### ft_isalnum

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== IS ALNUM ==========================\n");
	printf("Checks for an alphanumeric character.\n");
	printf(" ·1 if the character matches the tested class\n");
	printf(" ·0 if the character does not match\n");
	printf("==============================================================\n");

	printf("'1' : %d\n", ft_isalnum('1'));
	printf("'A' : %d\n", ft_isalnum('A'));
	printf("'+' : %d\n", ft_isalnum('+'));
	printf("'*' : %d\n", ft_isalnum('*'));

	printf("========================== ORIGINAL ==========================\n");
	printf("[DIFF] Will return any non-zero value rather than 1.\n");
	printf("==============================================================\n");

	printf("'1' : %d\n", isalnum('1'));
	printf("'A' : %d\n", isalnum('A'));
	printf("'+' : %d\n", isalnum('+'));
	printf("'*' : %d\n", isalnum('*'));

	return (0);
}
```

#### ft_isascii

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== IS ASCII ==========================\n");
	printf("Checks whether *c* is a 7-bit unsigned char value that fits\n into the ASCII character set.\n");
	printf(" ·1 if the character matches the tested class\n");
	printf(" ·0 if the character does not match\n");
	printf("==============================================================\n");

	printf("'a' : %d\n", ft_isascii('a'));
	printf("'3' : %d\n", ft_isascii('3'));
	printf("'!' : %d\n", ft_isascii('!'));
	printf("37  : %d\n", ft_isascii(37));
    printf("-1  : %d\n", ft_isascii(-1));
    printf("128 : %d\n", ft_isascii(128));

	printf("========================== ORIGINAL ==========================\n");
	printf("[DIFF] Will return any non-zero value rather than 1.\n");
	printf("==============================================================\n");

	printf("'a' : %d\n", isascii('a'));
	printf("'3' : %d\n", isascii('3'));
	printf("'!' : %d\n", isascii('!'));
	printf("37  : %d\n", isascii(37));
    printf("-1  : %d\n", isascii(-1));
    printf("128 : %d\n", isascii(128));

	return (0);
}
```

#### ft_isprint

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== IS PRINT ==========================\n");
	printf("Checks for any printable characters including space.\n");
	printf(" ·1 if the character matches the tested class.\n");
	printf(" ·0 if the character does not match\n");
	printf("==============================================================\n");

	printf("'a' : %d\n", ft_isprint('a'));
	printf("57  : %d\n", ft_isprint(57));
	printf("1   : %d\n", ft_isprint(1));
	printf("127 : %d\n", ft_isprint(127));

	printf("========================== ORIGINAL ==========================\n");
	printf("[DIFF] Will return any non-zero value rather than 1.\n");
	printf("==============================================================\n");

	printf("'a' : %d\n", isprint('a'));
	printf("57  : %d\n", isprint(57));
	printf("1   : %d\n", isprint(1));
	printf("127 : %d\n", isprint(127));

	return (0);
}
```

#### ft_strlen

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== STRLEN ===========================\n");
	printf("Calculates the length of the string pointed to by *s*.\n");
	printf("Returns the number of bytes in the string pointed to by *s*.\n");
	printf("==============================================================\n");

	printf("\"Hello world\" : %zu\n", ft_strlen("Hello world"));
	printf("\"banana\"      : %zu\n", ft_strlen("banana"));
	printf("\"123456789\"   : %zu\n", ft_strlen("123456789"));

	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	printf("\"Hello world\" : %zu\n", strlen("Hello world"));
	printf("\"banana\"      : %zu\n", strlen("banana"));
	printf("\"123456789\"   : %zu\n", strlen("123456789"));

	return (0);
}
```

#### ft_memset

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== MEMSET ===========================\n");
	printf("Fills the first *n* bytes of the memory area pointed to by *s*\nwith the constant byte *c*.\n");
	printf("Returns a pointer to the memory area of *s*.\n");
	printf("==============================================================\n");

	// --- EXAMPLE OF USE: Initializing an array to zero ---
	
	// 1. Declare fixed-size string
	char	str[11] = "Hello world";
	printf("[ORIGINAL STRING] : %s\n", str);

	// 2. Fill the string with null characters
	ft_memset(str, 0, sizeof(str));
	printf("[EMPTIED STRING]  : %s\n", str);

	// 3. Fill the first 5 bytes with the character '$'
	ft_memset(str, '$', 5);
	str[5] = '\0';
	printf("[FILLED STRING]   : %s\n", str);

	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	// 1. Declare fixed-size string
	char	str_original[11] = "Hola mundo";
	printf("[ORIGINAL STRING] : %s\n", str_original);

	// 2. Fill the string with null characters
	memset(str_original, 0, sizeof(str_original));
	printf("[EMPTIED STRING]  : %s\n", str_original);

	// 3. Fill the first 5 bytes with the character '$'
	memset(str_original, '$', 5);
	str[5] = '\0';
	printf("[FILLED STRING]   : %s\n", str_original);

	printf("\n=========================== ERRORS ===========================\n");
	printf("Passing a NULL string.\n");
	printf("==============================================================\n");

	// 1. Declare fixed-size string and initialize to null
	char	str2[11];
	printf("[ORIGINAL STRING] : %s\n", str2);

	// 2. Fill the string with null characters
	ft_memset(str2, 0, sizeof(str2));
	printf("[EMPTIED STRING]  : %s\n", str2);

	// 3. Fill the first 5 bytes with the character '$'
	ft_memset(str2, '$', 5);
	//str[5] = '\0';
	printf("[FILLED STRING]   : %s\n", str2);

	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	// 1. Declare fixed-size string and initialize to null
	char	str2_original[11];
	printf("[ORIGINAL STRING] : %s\n", str2_original);

	// 2. Fill the string with null characters
	memset(str2_original, 0, sizeof(str2_original));
	printf("[EMPTIED STRING]  : %s\n", str2_original);

	// 3. Fill the first 5 bytes with the character '$'
	memset(str2_original, '$', 5);
	//str[5] = '\0';
	printf("[FILLED STRING]   : %s\n", str2_original);

	return (0);
}
```

#### ft_bzero

```
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	printf("=========================== B ZERO ===========================\n");
	printf("Erases the data in the *n* bytes of the memory starting at the\nlocation pointed to by *s* by writing zeros to that area.\n");
	printf("==============================================================\n");

	// --- EXAMPLE OF USE: Initializing an array to zero ---
	
	// 1. Declare fixed-size string
	char	str[11] = "Hello world";
	printf("[ORIGINAL STRING] : %s\n", str);

	// 2. Fill the string with null characters
	ft_bzero(str, sizeof(str));
	printf("[EMPTIED STRING]  : %s\n", str);

	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	// 1. Declare fixed-size string
	char	str_original[11] = "Hola mundo";
	printf("[ORIGINAL STRING] : %s\n", str_original);

	// 2. Fill the string with null characters
	bzero(str_original, sizeof(str_original));
	printf("[EMPTIED STRING]  : %s\n", str_original);

	return (0);
}
```

#### ft_memcpy

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== MEMCPY ===========================\n");
	printf("Copies *n* bytes from memory area *src* to memory area *dest*.\n");
	printf("Returns a pointer to *dest*.\n");
	printf("==============================================================\n");

	// --- EXAMPLE OF USE: Copying an array of integers ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	const int	source[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int destination_full[10];
	int destination_capped[5];
	printf("[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", source[i]);

	// 2. Copy source to destination in full
	ft_memcpy(destination_full, source, 10 * sizeof(int));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_full[i]);

	// 3. Copy source to destination capped at size 5
	ft_memcpy(destination_capped, source, 5 * sizeof(int));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_capped[i]);

	// --- EXAMPLE OF USE: Copying an array of chars ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	char	source2[] = "Hello world";
	char destination_full2[11];
	char destination_capped2[5];
	printf("\n[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", source2[i]);

	// 2. Copy source to destination in full
	ft_memcpy(destination_full2, source2, 11 * sizeof(char));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_full2[i]);

	// 3. Copy source to destination capped at size 5
	ft_memcpy(destination_capped2, source2, 5 * sizeof(char));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_capped2[i]);

	printf("\n\n");
	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	// 1. Declare initialized array for source and fixed-size arrays for destinations
	int	source_original[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int destination_full_original[10];
	int destination_capped_original[5];
	printf("[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", source_original[i]);

	// 2. Copy source to destination in full
	memcpy(destination_full_original, source_original, 10 * sizeof(int));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_full_original[i]);

	// 3. Copy source to destination capped at size 5
	memcpy(destination_capped_original, source_original, 5 * sizeof(int));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_capped_original[i]);

	// --- EXAMPLE OF USE: Copying an array of chars ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	char	source_original2[] = "Hola mundo";
	char destination_full_original2[11];
	char destination_capped_original2[5];
	printf("\n[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", source_original2[i]);

	// 2. Copy source to destination in full
	memcpy(destination_full_original2, source_original2, 11 * sizeof(char));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_full_original2[i]);

	// 3. Copy source to destination capped at size 5
	memcpy(destination_capped_original2, source_original2, 5 * sizeof(char));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_capped_original2[i]);

	return (0);
}
```

#### ft_memmove

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== MEMMOVE ===========================\n");
	printf("Copies n bytes from memory area src to memory area dest. Unlike\nmemcpy, memmove does not delete data from the source location.\n");
	printf("Returns a pointer to dest.\n");
	printf("==============================================================\n");

	// --- EXAMPLE OF USE: Copying an array of integers ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	const int	source[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int destination_full[10];
	int destination_capped[5];
	printf("[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", source[i]);

	// 2. Copy source to destination in full
	ft_memmove(destination_full, source, 10 * sizeof(int));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_full[i]);

	// 3. Copy source to destination capped at size 5
	ft_memmove(destination_capped, source, 5 * sizeof(int));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_capped[i]);

	// --- EXAMPLE OF USE: Copying an array of chars ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	char	source2[] = "Hello world";
	char destination_full2[11];
	char destination_capped2[5];
	printf("\n[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", source2[i]);

	// 2. Copy source to destination in full
	ft_memmove(destination_full2, source2, 11 * sizeof(char));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_full2[i]);

	// 3. Copy source to destination capped at size 5
	ft_memmove(destination_capped2, source2, 5 * sizeof(char));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_capped2[i]);

	printf("\n\n");
	printf("========================== ORIGINAL ==========================\n");
	printf("========================== FUNCTION ==========================\n");

	// 1. Declare initialized array for source and fixed-size arrays for destinations
	int	source_original[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int destination_full_original[10];
	int destination_capped_original[5];
	printf("[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", source_original[i]);

	// 2. Copy source to destination in full
	memmove(destination_full_original, source_original, 10 * sizeof(int));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_full_original[i]);

	// 3. Copy source to destination capped at size 5
	memmove(destination_capped_original, source_original, 5 * sizeof(int));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 10; i++)
		printf(" %d", destination_capped_original[i]);

	// --- EXAMPLE OF USE: Copying an array of chars ---
	
	// 1. Declare initialized array for source and fixed-size arrays for destinations
	char source_original2[] = "Hola mundo";
	char destination_full_original2[11];
	char destination_capped_original2[5];
	printf("\n[ORIGINAL ARRAY]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", source_original2[i]);

	// 2. Copy source to destination in full
	memmove(destination_full_original2, source_original2, 11 * sizeof(char));
	printf("\n[FULL DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_full_original2[i]);

	// 3. Copy source to destination capped at size 5
	memmove(destination_capped_original2, source_original2, 5 * sizeof(char));
	printf("\n[CAPPED DESTINATION]\t:");
	for (int i = 0; i < 11; i++)
		printf(" %c", destination_capped_original2[i]);

	return (0);
}
```

#### ft_strlcpy

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== STRLCPY ==========================\n");
	printf("Copies a string by taking the full size of the buffer. Guarantees\na NUL-terminated result. The NUL byte is included in size.\n");
	printf("Returns the total length of the string it tried to create.\n");
	printf("==============================================================\n");

	char	src[] = "Hello world";
	char	src_empty[] = "";
	char	src_small[] = "Hola mundo";
	char	dst;
	char	dst_empty;
	char	dst_small;
	size_t	result;
	size_t	result_empty;
	size_t	result_small;

	// Copying a correct string
	result = ft_strlcpy(dst, src, sizeof(dst));
	printf("[SOURCE]\t: %s\n", src);
	printf("[DESTINATION]\t: %s\n", dst);
	printf("[RETURN LEN]\t: %zu\n", result);

	// Copying an empty string
	result_empty = ft_strlcpy(dst_empty, src_empty, sizeof(dst_empty));
	printf("[SOURCE]\t: %s\n", src_empty);
	printf("[DESTINATION]\t: %s\n", dst_empty);
	printf("[RETURN LEN]\t: %zu\n", result_empty);

	// Copying with size smaller than src
	result_small = ft_strlcpy(dst_small, src_small, 5);
	printf("[SOURCE]\t: %s\n", src_small);
	printf("[DESTINATION]\t: %s\n", dst_small);
	printf("[RETURN LEN]\t: %zu\n", result_small);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	src_original[] = "Hello world";
	char	src_empty_original[] = "";
	char	src_small_original[] = "Hola mundo";
	char	dst_original;
	char	dst_empty_original;
	char	dst_small_original;
	size_t	result_original;
	size_t	result_empty_original;
	size_t	result_small_original;

	// Copying a correct string
	result_original = strlcpy(dst_original, src_original, sizeof(dst_original));
	printf("[SOURCE]\t: %s\n", src_original);
	printf("[DESTINATION]\t: %s\n", dst_original);
	printf("[RETURN LEN]\t: %zu\n", result_original);

	// Copying an empty string
	result_empty_original = strlcpy(dst_empty_original, src_empty_original, sizeof(dst_empty_original));
	printf("[SOURCE]\t: %s\n", src_empty_original);
	printf("[DESTINATION]\t: %s\n", dst_empty_original);
	printf("[RETURN LEN]\t: %zu\n", result_empty_original);

	// Copying with size smaller than src
	result_small_original = strlcpy(dst_small_original, src_small_original, 5);
	printf("[SOURCE]\t: %s\n", src_small_original);
	printf("[DESTINATION]\t: %s\n", dst_small_original);
	printf("[RETURN LEN]\t: %zu\n", result_small_original);

	return (0);
}
```
#### ft_strlcat

```
#include <stdio.h>
#include <string.h>
int main(void)
{
    const char src[] = "Hello world";
    const char src_empty[] = "";
    const char src_small[] = "Hola mundo";

    char dst[30] = "Hello ";
    char dst_empty[30] = "";
    char dst_small[5] = "Hi";

    size_t result;
    size_t result_empty;
    size_t result_small;

    printf("=========================== STRLCAT ==========================\n");

    result = ft_strlcat(dst, src, sizeof(dst));
    printf("[SOURCE]\t: %s\n", src);
    printf("[DESTINATION]\t: %s\n", dst);
    printf("[RETURN LEN]\t: %zu\n", result);

    result_empty = ft_strlcat(dst_empty, src_empty, sizeof(dst_empty));
    printf("[SOURCE]\t: %s\n", src_empty);
    printf("[DESTINATION]\t: %s\n", dst_empty);
    printf("[RETURN LEN]\t: %zu\n", result_empty);

    result_small = ft_strlcat(dst_small, src_small, sizeof(dst_small));
    printf("[SOURCE]\t: %s\n", src_small);
    printf("[DESTINATION]\t: %s\n", dst_small);
    printf("[RETURN LEN]\t: %zu\n", result_small);

    // printf("========================== ORIGINAL ==========================\n");

    // char dst_original[30] = "Hello ";
    // char dst_empty_original[30] = "";
    // char dst_small_original[5] = "Hi";

    // size_t result_original;
    // size_t result_empty_original;
    // size_t result_small_original;

    // result_original = strlcat(dst_original, src, sizeof(dst_original));

    // printf("[SOURCE]\t: %s\n", src);
    // printf("[DESTINATION]\t: %s\n", dst_original);
    // printf("[RETURN LEN]\t: %zu\n", result_original);

    // result_empty_original = strlcat(dst_empty_original, src_empty, sizeof(dst_empty_original));

    // printf("[SOURCE]\t: %s\n", src_empty);
    // printf("[DESTINATION]\t: %s\n", dst_empty_original);
    // printf("[RETURN LEN]\t: %zu\n", result_empty_original);

    // result_small_original = strlcat(dst_small_original, src_small, sizeof(dst_small_original));

    // printf("[SOURCE]\t: %s\n", src_small);
    // printf("[DESTINATION]\t: %s\n", dst_small_original);
    // printf("[RETURN LEN]\t: %zu\n", result_small_original);

    return 0;
}
```

#### ft_toupper

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== TO UPPER ==========================\n");
	printf("Converts lowercase letters to uppercase.\n");
	printf("==============================================================\n");

	printf("'a' : %c\n", ft_toupper('a'));
	printf("'B' : %c\n", ft_toupper('b'));
	printf("122  : %c\n", ft_toupper(122));

	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" In case c is neither an unsigned char value nor EOF.");
	printf("==============================================================\n");

	printf("-1 : %c\n", ft_toupper(-1));
	printf("49 : %c\n", ft_toupper(49));

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	printf("'a' : %c\n", toupper('a'));
	printf("'B' : %c\n", toupper('b'));
	printf("122  : %c\n", toupper(122));

	printf("========================== ORIGINAL ==========================\n");
	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" In case c is neither an unsigned char value nor EOF.");
	printf("==============================================================\n");

	printf("-1 : %c\n", toupper(-1));
	printf("49 : %c\n", toupper(49));

	return (0);
}
```

#### ft_tolower

```
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("========================== TO LOWER ==========================\n");
	printf("Converts uppercase letters to lowercase.\n");
	printf("==============================================================\n");

	printf("'A' : %c\n", ft_tolower('a'));
	printf("'b' : %c\n", ft_tolower('b'));
	printf("122  : %c\n", ft_tolower(122));

	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" In case c is neither an unsigned char value nor EOF.");
	printf("==============================================================\n");

	printf("-1 : %c\n", ft_tolower(-1));
	printf("49 : %c\n", ft_tolower(49));

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	printf("'A' : %c\n", tolower('a'));
	printf("'b' : %c\n", tolower('b'));
	printf("122  : %c\n", tolower(122));

	printf("========================== ORIGINAL ==========================\n");
	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" In case c is neither an unsigned char value nor EOF.");
	printf("==============================================================\n");

	printf("-1 : %c\n", tolower(-1));
	printf("49 : %c\n", tolower(49));

	return (0);
}
```
#### ft_strchr

```
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("=========================== STRCHR ===========================\n");
	printf("Returns a pointer to the first occurrence of the character c\n(byte) in the string s, or NULL if not found.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world";
	const char	*s_not_found = "Hola mundo";
	const char	*s_empty = "";
	const char	*s_null = NULL;

	char	c = 'w';

	char	*result_found;
	char	*result_not_found;
	char	*result_empty;
	char	*result_null;

	// Search existing character
	result_found = ft_strchr(s_found, c);
	printf("[HAYSTACK]\t: %s\n", s_found);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_found);

	// Search non-existing character
	result_not_found = ft_strchr(s_not_found, c);
	printf("[HAYSTACK]\t: %s\n", s_not_found);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_not_found);

	// Search in empty string
	result_empty = ft_strchr(s_empty, c);
	printf("[HAYSTACK]\t: %s\n", s_empty);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_empty);

	// Search in empty string
	// result_null = ft_strchr(s_null, c);
	// printf("[HAYSTACK]\t: %s\n", s_null);
	// printf("[NEEDLE]\t: %c\n", c);
	// printf("[RESULT]\t: %s\n", result_null);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	const char	*s_found_original = "Hello world";
	const char	*s_not_found_original = "Hola mundo";
	const char	*s_empty_original = "";
	const char	*s_null_original = NULL;

	char	c_original = 'w';

	char	*result_found_original;
	char	*result_not_found_original;
	char	*result_empty_original;
	char	*result_null_original;

	// Search existing character
	result_found_original = strchr(s_found_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_found_original);
	printf("[NEEDLE]\t: %c\n", c_original);
	printf("[RESULT]\t: %s\n", result_found_original);

	// Search non-existing character
	result_not_found_original = strchr(s_not_found_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_not_found_original);
	printf("[NEEDLE]\t: %c\n", c_original);
	printf("[RESULT]\t: %s\n", result_not_found_original);

	// Search in empty string
	result_empty_original = strchr(s_empty_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_empty_original);
	printf("[NEEDLE]\t: %c\n", c_original);
	printf("[RESULT]\t: %s\n", result_empty_original);

	// Search in empty string
	// result_null_original = strchr(s_null_original, c_original);
	// printf("[HAYSTACK]\t: %s\n", s_null_original);
	// printf("[NEEDLE]\t: %c\n", c_original);
	// printf("[RESULT]\t: %s\n", result_null_original);

	return (0);
}
```

#### ft_strrchr	

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== STRRCHR ==========================\n");
	printf("Returns a pointer to the last occurrence of the character c\n(byte) in the string s, or NULL if not found.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world";
	const char	*s_not_found = "Hola mundo";
	const char	*s_empty = "";
	const char	*s_null = NULL;

	char	c = 'w';

	char	*result_found;
	char	*result_not_found;
	char	*result_empty;
	char	*result_null;

	// Search existing character
	result_found = ft_strrchr(s_found, c);
	printf("[HAYSTACK]\t: %s\n", s_found);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_found);

	// Search non-existing character
	result_not_found = ft_strrchr(s_not_found, c);
	printf("[HAYSTACK]\t: %s\n", s_not_found);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_not_found);

	// Search in empty string
	result_empty = ft_strrchr(s_empty, c);
	printf("[HAYSTACK]\t: %s\n", s_empty);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_empty);

	// Search in empty string
	// result_null = ft_strrchr(s_null, c);
	// printf("[HAYSTACK]\t: %s\n", s_null);
	// printf("[NEEDLE]\t: %c\n", c);
	// printf("[RESULT]\t: %s\n", result_null);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	const char	*s_found_original = "Hello world";
	const char	*s_not_found_original = "Hola mundo";
	const char	*s_empty_original = "";
	const char	*s_null_original = NULL;

	char	c_original = 'w';

	char	*result_found_original;
	char	*result_not_found_original;
	char	*result_empty_original;
	char	*result_null_original;

	// Search existing character
	result_found_original = ft_strrchr(s_found_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_found_original);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_found_original);

	// Search non-existing character
	result_not_found_original = ft_strrchr(s_not_found_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_not_found_original);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_not_found_original);

	// Search in empty string
	result_empty_original = ft_strrchr(s_empty_original, c_original);
	printf("[HAYSTACK]\t: %s\n", s_empty_original);
	printf("[NEEDLE]\t: %c\n", c);
	printf("[RESULT]\t: %s\n", result_empty_original);

	// Search in empty string
	// result_null_original = ft_strrchr(s_null_original, c_original);
	// printf("[HAYSTACK]\t: %s\n", s_null_original);
	// printf("[NEEDLE]\t: %c\n", c);
	// printf("[RESULT]\t: %s\n", result_null_original);

	return (0);
}
```

#### ft_strncmp	

```
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("=========================== STRNCMP ==========================\n");
	printf("Compares the two strings s1 and s2.\n");
	printf("Returns an integer indicating the result of the comparison:\n");
	printf("	· 0 if equal\n");
	printf("	· a negative value if s1 is less than s2\n");
	printf("	· a positive value if s1 is greater than s2\n");
	printf("==============================================================\n");

	const char	*s1_match = "Hello world";
	const char	*s1_no_match = "aba";

	const char	*s2_match = "Hello world";
	const char	*s2_no_match = "abz";

	const char	*s_null = NULL;

	int			result_match;
	int			result_no_match;
	int			result_zero;
	int			result_null;

	// Compare equal strings
	result_match = ft_strncmp(s1_match, s2_match, 11);
	printf("[S1]\t: %s\n", s1_match);
	printf("[S2]\t: %s\n", s2_match);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]: %d\n", result_match);

	// Compare different strings
	result_no_match = ft_strncmp(s1_no_match, s2_no_match, 3);
	printf("[S1]\t: %s\n", s1_no_match);
	printf("[S2]\t: %s\n", s2_no_match);
	printf("[SIZE]\t: %d\n", 3);
	printf("[RESULT]: %d\n", result_no_match);

	// Compare different strings with size 0
	result_zero = ft_strncmp(s1_no_match, s2_no_match, 0);
	printf("[S1]\t: %s\n", s1_no_match);
	printf("[S2]\t: %s\n", s2_no_match);
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]: %d\n", result_zero);

	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" If s1 or s2 are NULL (segmentation fault).");
	printf("==============================================================\n");

	// Compare null strings (undefined behavior)
	// result_null = ft_strncmp(s1_match, s_null, 11);
	// printf("[S1]\t: %s\n", s1_match);
	// printf("[S2]\t: %s\n", s_null);
	// printf("[SIZE]\t: %d\n", 11);
	// printf("[RESULT]: %d\n", result_null);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	const char	*s1_match_original = "Hello world";
	const char	*s1_no_match_original = "aba";

	const char	*s2_match_original = "Hello world";
	const char	*s2_no_match_original = "abz";

	const char	*s_null_original = NULL;

	int			result_match_original;
	int			result_no_match_original;
	int			result_zero_original;
	int			result_null_original;

	// Compare equal strings
	result_match_original = ft_strncmp(s1_match_original, s2_match_original, 11);
	printf("[S1]\t: %s\n", s1_match_original);
	printf("[S2]\t: %s\n", s2_match_original);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]: %d\n", result_match_original);

	// Compare different strings
	result_no_match_original = ft_strncmp(s1_no_match_original, s2_no_match_original, 3);
	printf("[S1]\t: %s\n", s1_no_match_original);
	printf("[S2]\t: %s\n", s2_no_match_original);
	printf("[SIZE]\t: %d\n", 3);
	printf("[RESULT]: %d\n", result_no_match_original);

	// Compare different strings with size 0
	result_zero_original = ft_strncmp(s1_no_match_original, s2_no_match_original, 0);
	printf("[S1]\t: %s\n", s1_no_match_original);
	printf("[S2]\t: %s\n", s2_no_match_original);
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]: %d\n", result_zero_original);

	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" If s1 or s2 are NULL (segmentation fault).");
	printf("==============================================================\n");

	// Compare null strings (undefined behavior)
	// result_null_original = ft_strncmp(s1_match, s_null_original, 11);
	// printf("[S1]\t: %s\n", s1_match_original);
	// printf("[S2]\t: %s\n", s_null_original);
	// printf("[SIZE]\t: %d\n", 11);
	// printf("[RESULT]: %d\n", result_null_original);

	return (0);
}
```

#### ft_memchr	

```
typedef struct s_data {
	int		id;
	char	value;
}	t_data;

#include <stdio.h>
#include <string.h>
int main()
{
	printf("============================ MEMCHR ==========================\n");
	printf("Scans the initial n bytes of the memory area pointed to by s\nfor the first instance of c.\n");
	printf("Returns a pointer to the matching byte or\nNULL if the character does not occur in the given memory area.\n");
	printf("==============================================================\n");

	const char		*s_data = "Hello\0world";
	int				s_match = 'w';
	int				s_no_match = 'z';

	t_data			struct_data = {42, 'A'};
	int				struct_match = 'A';

	void			*result_match;
	void			*result_no_match;
	void			*result_zero;
	void			*result_struct;

	// 1. Match string after a null byte
	result_match = ft_memchr(s_data, s_match, 11);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: '%c' (%d)\n", s_match, s_match);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %p (Offset: %ld)\n\n", result_match, result_match ? (result_match - (void *)s_data) : -1);

	// 2. No match in string
	result_no_match = ft_memchr(s_data, s_no_match, 11);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: '%c' (%d)\n", s_no_match, s_no_match);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %p\n\n", result_no_match);

	// 3. Size 0 evaluation
	result_zero = ft_memchr(s_data, 'H', 0);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: 'H' (%d)\n", 'H');
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]\t: %p\n\n", result_zero);

	printf("=========================== STRUCTS ==========================\n");

	// 4. Struct internal byte matching
	result_struct = ft_memchr(&struct_data, struct_match, sizeof(t_data));
	printf("[DATA]\t: Struct {id: 42, value: 'A}'\n");
	printf("[CHAR]\t: '%c' (%d)\n", struct_match, struct_match);
	printf("[SIZE]\t: %zu\n", sizeof(t_data));
	printf("[RESULT]\t: %p (Offset: %ld)\n\n", result_struct, result_struct ? (result_struct - (void *)&struct_data) : -1);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	void			*result_match_original;
	void			*result_no_match_original;
	void			*result_zero_original;
	void			*result_struct_original;

	result_match_original = memchr(s_data, s_match, 11);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: '%c' (%d)\n", s_match, s_match);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %p (Offset: %ld)\n\n", result_match_original, result_match_original ? (result_match_original - (void *)s_data) : -1);

	result_no_match_original = memchr(s_data, s_no_match, 11);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: '%c' (%d)\n", s_no_match, s_no_match);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %p\n\n", result_no_match_original);

	result_zero_original = memchr(s_data, 'H', 0);
	printf("[DATA]\t: Hello\\0world\n");
	printf("[CHAR]\t: 'H' (%d)\n", 'H');
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]\t: %p\n\n", result_zero_original);

	printf("=========================== STRUCTS ==========================\n");

	result_struct_original = memchr(&struct_data, struct_match, sizeof(t_data));
	printf("[DATA]\t: Struct {id: 42, value: 'A'}\n");
	printf("[CHAR]\t: '%c' (%d)\n", struct_match, struct_match);
	printf("[SIZE]\t: %zu\n", sizeof(t_data));
	printf("[RESULT]\t: %p (Offset: %ld)\n\n", result_struct_original, result_struct_original ? (result_struct_original - (void *)&struct_data) : -1);

	return (0);
}
```

#### ft_memcmp	

```
typedef struct s_data {
	int		id;
	char	value;
}	t_data;

#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("============================ MEMCMP ==========================\n");
	printf("Compares the first n bytes of the memory areas s1 and s2.\n");
	printf("Returns an integer less than, equal to, or greater than zero if\ns1 is found to be less than, to match, or be greater than s2.\n");
	printf("==============================================================\n");

	const char		*str1 = "Hello\0world";
	const char		*str2 = "Hello\0worLd";
	const char		*str3 = "Hello\0world";

	// Test variables for structs
	t_data			struct1 = {42, 'A'};
	t_data			struct2 = {42, 'B'};

	int				result_diff;
	int				result_match;
	int				result_zero;
	int				result_struct;

	// 1. Comparison evaluating differences past a null byte
	result_diff = ft_memcmp(str1, str2, 11);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0worLd\n");
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %d\n\n", result_diff);

	// 2. Full match including null byte
	result_match = ft_memcmp(str1, str3, 11);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0world\n");
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %d\n\n", result_match);

	// 3. Size 0 evaluation
	result_zero = ft_memcmp(str1, str2, 0);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0worLd\n");
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]\t: %d\n\n", result_zero);

	printf("=========================== STRUCTS ==========================\n");

	// 4. Struct raw memory comparison
	result_struct = ft_memcmp(&struct1, &struct2, sizeof(t_data));
	printf("[S1]\t: Struct {id: 42, value: 'A'}\n");
	printf("[S2]\t: Struct {id: 42, value: 'B'}\n");
	printf("[SIZE]\t: %zu\n", sizeof(t_data));
	printf("[RESULT]\t: %d\n\n", result_struct);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	int				result_diff_original;
	int				result_match_original;
	int				result_zero_original;
	int				result_struct_original;

	result_diff_original = memcmp(str1, str2, 11);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0worLd\n");
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %d\n\n", result_diff_original);

	result_match_original = memcmp(str1, str3, 11);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0world\n");
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]\t: %d\n\n", result_match_original);

	result_zero_original = memcmp(str1, str2, 0);
	printf("[S1]\t: Hello\\0world\n");
	printf("[S2]\t: Hello\\0worLd\n");
	printf("[SIZE]\t: %d\n", 0);
	printf("[RESULT]\t: %d\n\n", result_zero_original);

	printf("=========================== STRUCTS ==========================\n");

	result_struct_original = memcmp(&struct1, &struct2, sizeof(t_data));
	printf("[S1]\t: Struct {id: 42, value: 'A'}\n");
	printf("[S2]\t: Struct {id: 42, value: 'B'}\n");
	printf("[SIZE]\t: %zu\n", sizeof(t_data));
	printf("[RESULT]\t: %d\n\n", result_struct_original);

	return (0);
}
```

#### ft_strnstr

```
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("=========================== STRNSTR ==========================\n");
	printf("Locates the first occurrence of the null-terminated string\nlittle in the string big, where not more than len characters\nare searched. Characters after a '\\0' are not searched.\n");
	printf("Returns a pointer to the first character of the first\noccurrence of *little*.\n");
	printf("==============================================================\n");

	const char	*big_str = "Hello world";
	const char	*little_str = "world";

	char		*result_out_of_bounds;
	char		*result_match;
	char		*result_empty_needle;
	char		*result_null;

	// 1. Match exists but finishes outside of len bounds (Should return NULL)
	result_out_of_bounds = ft_strnstr(big_str, little_str, 7);
	printf("[BIG]\t: %s\n", big_str);
	printf("[LITTLE]: %s\n", little_str);
	printf("[SIZE]\t: %d\n", 7);
	printf("[RESULT]: %p (String: %s)\n\n", (void *)result_out_of_bounds, result_out_of_bounds ? result_out_of_bounds : "NULL");

	// 2. Match exists completely within len bounds
	result_match = ft_strnstr(big_str, little_str, 11);
	printf("[BIG]\t: %s\n", big_str);
	printf("[LITTLE]: %s\n", little_str);
	printf("[SIZE]\t: %d\n", 11);
	printf("[RESULT]: %p (String: %s)\n\n", (void *)result_match, result_match ? result_match : "NULL");

	// 3. Empty needle scenario (Should return big)
	result_empty_needle = ft_strnstr(big_str, "", 5);
	printf("[BIG]\t: %s\n", big_str);
	printf("[LITTLE]: \"\"\n");
	printf("[SIZE]\t: %d\n", 5);
	printf("[RESULT]: %p (String: %s)\n\n", (void *)result_empty_needle, result_empty_needle ? result_empty_needle : "NULL");

	printf("===================== UNDEFINED BEHAVIOR =====================\n");
	printf(" If big or little are NULL (segmentation fault).\n");
	printf("==============================================================\n");

	// result_null = ft_strnstr(big_str, NULL, 11);
	// printf("[BIG]\t: %s\n", big_str);
	// printf("[LITTLE]: %p\n", NULL);
	// printf("[SIZE]\t: %d\n", 11);
	// printf("[RESULT]: %p (String: %s)\n\n", (void *)result_null, result_null ? result_null : "NULL");

	return (0);
}
```

#### ft_atoi

```
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("=========================== ATOI =============================\n");
	printf("Converts the initial portion of the string s to an integer.\n");
	printf("==============================================================\n");

	const char	*test_0 = " -+1234ab567";
	const char	*test_1 = " ---+--+1234ab567";
	const char	*test_2 = "  abc-123";
	const char	*test_3 = "+0678cc1";
	const char	*test_4 = "  \t-++--505";
	const char	*test_5 = "0";
	const char	*test_6 = "-001b";
	const char	*test_7 = " +c11110";
	const char	*test_8 = "  -153   6b";

	int	result_0;
	int	result_1;
	int	result_2;
	int	result_3;
	int	result_4;
	int	result_5;
	int	result_6;
	int	result_7;
	int	result_8;

	// Convert string to integer
	result_0 = ft_atoi(test_0);
	printf("[STRING]\t: %s\n", test_0);
	printf("[RESULT]\t: %d\n", result_0);

	// Convert string with multiple signs
	result_1 = ft_atoi(test_1);
	printf("[STRING]\t: %s\n", test_1);
	printf("[RESULT]\t: %d\n", result_1);

	// Convert string starting with non-numeric character
	result_2 = ft_atoi(test_2);
	printf("[STRING]\t: %s\n", test_2);
	printf("[RESULT]\t: %d\n", result_2);

	// Convert string with leading plus sign and leading zeros
	result_3 = ft_atoi(test_3);
	printf("[STRING]\t: %s\n", test_3);
	printf("[RESULT]\t: %d\n", result_3);

	// Convert string with whitespace and multiple signs
	result_4 = ft_atoi(test_4);
	printf("[STRING]\t: %s\n", test_4);
	printf("[RESULT]\t: %d\n", result_4);

	// Convert string containing zero
	result_5 = ft_atoi(test_5);
	printf("[STRING]\t: %s\n", test_5);
	printf("[RESULT]\t: %d\n", result_5);

	// Convert negative number with leading zeros
	result_6 = ft_atoi(test_6);
	printf("[STRING]\t: %s\n", test_6);
	printf("[RESULT]\t: %d\n", result_6);

	// Convert string starting with a plus sign followed by a non-numeric character
	result_7 = ft_atoi(test_7);
	printf("[STRING]\t: %s\n", test_7);
	printf("[RESULT]\t: %d\n", result_7);

	// Convert negative number followed by whitespace and other characters
	result_8 = ft_atoi(test_8);
	printf("[STRING]\t: %s\n", test_8);
	printf("[RESULT]\t: %d\n", result_8);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	int	result_0_original;
	int	result_1_original;
	int	result_2_original;
	int	result_3_original;
	int	result_4_original;
	int	result_5_original;
	int	result_6_original;
	int	result_7_original;
	int	result_8_original;

	// Convert string to integer
	result_0_original = atoi(test_0);
	printf("[STRING]\t: %s\n", test_0);
	printf("[RESULT]\t: %d\n", result_0_original);

	// Convert string with multiple signs
	result_1_original = atoi(test_1);
	printf("[STRING]\t: %s\n", test_1);
	printf("[RESULT]\t: %d\n", result_1_original);

	// Convert string starting with non-numeric character
	result_2_original = atoi(test_2);
	printf("[STRING]\t: %s\n", test_2);
	printf("[RESULT]\t: %d\n", result_2_original);

	// Convert string with leading plus sign and leading zeros
	result_3_original = atoi(test_3);
	printf("[STRING]\t: %s\n", test_3);
	printf("[RESULT]\t: %d\n", result_3_original);

	// Convert string with whitespace and multiple signs
	result_4_original = atoi(test_4);
	printf("[STRING]\t: %s\n", test_4);
	printf("[RESULT]\t: %d\n", result_4_original);

	// Convert string containing zero
	result_5_original = atoi(test_5);
	printf("[STRING]\t: %s\n", test_5);
	printf("[RESULT]\t: %d\n", result_5_original);

	// Convert negative number with leading zeros
	result_6_original = atoi(test_6);
	printf("[STRING]\t: %s\n", test_6);
	printf("[RESULT]\t: %d\n", result_6_original);

	// Convert string starting with a plus sign followed by a non-numeric character
	result_7_original = atoi(test_7);
	printf("[STRING]\t: %s\n", test_7);
	printf("[RESULT]\t: %d\n", result_7_original);

	// Convert negative number followed by whitespace and other characters
	result_8_original = atoi(test_8);
	printf("[STRING]\t: %s\n", test_8);
	printf("[RESULT]\t: %d\n", result_8_original);

	return (0);
}
```

#### ft_calloc

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("=========================== CALLOC ===========================\n");
	printf("Allocates memory for nmemb elements of size bytes each,\ninitializing all allocated bytes to zero.\n");
	printf("==============================================================\n");

	size_t	nmemb_0 = 5;
	size_t	size_0 = sizeof(int);
	size_t	nmemb_1 = 10;
	size_t	size_1 = sizeof(char);
	size_t	nmemb_2 = 0;
	size_t	size_2 = sizeof(int);
	size_t	nmemb_3 = 5;
	size_t	size_3 = 0;
	size_t	nmemb_4 = 3;
	size_t	size_4 = sizeof(int);

	int		*result_0;
	char	*result_1;
	void	*result_2;
	void	*result_3;
	int		*result_4;

	// Allocate memory for an array of integers
	result_0 = ft_calloc(nmemb_0, size_0);
	printf("[NMEMB]\t\t: %zu\n", nmemb_0);
	printf("[SIZE]\t\t: %zu\n", size_0);
	printf("[RESULT]\t: %p\n", (void *)result_0);
	if (result_0 != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_0; i++)
			printf("%d ", result_0[i]);
		printf("\n");
	}
	free(result_0);

	// Allocate memory for an array of characters
	result_1 = ft_calloc(nmemb_1, size_1);
	printf("[NMEMB]\t\t: %zu\n", nmemb_1);
	printf("[SIZE]\t\t: %zu\n", size_1);
	printf("[RESULT]\t: %p\n", (void *)result_1);
	if (result_1 != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_1; i++)
			printf("%d ", result_1[i]);
		printf("\n");
	}
	free(result_1);

	// Allocate memory with zero elements
	result_2 = ft_calloc(nmemb_2, size_2);
	printf("[NMEMB]\t\t: %zu\n", nmemb_2);
	printf("[SIZE]\t\t: %zu\n", size_2);
	printf("[RESULT]\t: %p\n", result_2);
	free(result_2);

	// Allocate memory with zero element size
	result_3 = ft_calloc(nmemb_3, size_3);
	printf("[NMEMB]\t\t: %zu\n", nmemb_3);
	printf("[SIZE]\t\t: %zu\n", size_3);
	printf("[RESULT]\t: %p\n", result_3);
	free(result_3);

	// Allocate memory for an array of integers and verify zero initialization
	result_4 = ft_calloc(nmemb_4, size_4);
	printf("[NMEMB]\t\t: %zu\n", nmemb_4);
	printf("[SIZE]\t\t: %zu\n", size_4);
	printf("[RESULT]\t: %p\n", (void *)result_4);
	if (result_4 != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_4; i++)
			printf("%d ", result_4[i]);
		printf("\n");
	}
	free(result_4);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	int		*result_0_original;
	char	*result_1_original;
	void	*result_2_original;
	void	*result_3_original;
	int		*result_4_original;

	// Allocate memory for an array of integers
	result_0_original = calloc(nmemb_0, size_0);
	printf("[NMEMB]\t\t: %zu\n", nmemb_0);
	printf("[SIZE]\t\t: %zu\n", size_0);
	printf("[RESULT]\t: %p\n", (void *)result_0_original);
	if (result_0_original != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_0; i++)
			printf("%d ", result_0_original[i]);
		printf("\n");
	}
	free(result_0_original);

	// Allocate memory for an array of characters
	result_1_original = calloc(nmemb_1, size_1);
	printf("[NMEMB]\t\t: %zu\n", nmemb_1);
	printf("[SIZE]\t\t: %zu\n", size_1);
	printf("[RESULT]\t: %p\n", (void *)result_1_original);
	if (result_1_original != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_1; i++)
			printf("%d ", result_1_original[i]);
		printf("\n");
	}
	free(result_1_original);

	// Allocate memory with zero elements
	result_2_original = calloc(nmemb_2, size_2);
	printf("[NMEMB]\t\t: %zu\n", nmemb_2);
	printf("[SIZE]\t\t: %zu\n", size_2);
	printf("[RESULT]\t: %p\n", result_2_original);
	free(result_2_original);

	// Allocate memory with zero element size
	result_3_original = calloc(nmemb_3, size_3);
	printf("[NMEMB]\t\t: %zu\n", nmemb_3);
	printf("[SIZE]\t\t: %zu\n", size_3);
	printf("[RESULT]\t: %p\n", result_3_original);
	free(result_3_original);

	// Allocate memory for an array of integers and verify zero initialization
	result_4_original = calloc(nmemb_4, size_4);
	printf("[NMEMB]\t\t: %zu\n", nmemb_4);
	printf("[SIZE]\t\t: %zu\n", size_4);
	printf("[RESULT]\t: %p\n", (void *)result_4_original);
	if (result_4_original != NULL)
	{
		printf("[CONTENT]\t: ");
		for (size_t i = 0; i < nmemb_4; i++)
			printf("%d ", result_4_original[i]);
		printf("\n");
	}
	free(result_4_original);

	return (0);
}
```

#### ft_strdup

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("=========================== STRDUP ===========================\n");
	printf("Allocates memory and creates a duplicate of the string s,\nreturning a pointer to the duplicated string.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world";
	const char	*s_empty = "";
	const char	*s_numbers = "123456789";
	const char	*s_special = "Hello\tworld!\n";
	const char	*s_long = "This is a longer string to duplicate.";

	char	*result_found;
	char	*result_empty;
	char	*result_numbers;
	char	*result_special;
	char	*result_long;

	// Duplicate a regular string
	result_found = ft_strdup(s_found);
	printf("[STRING]\t: %s\n", s_found);
	printf("[RESULT]\t: %s\n", result_found);
	free(result_found);

	// Duplicate an empty string
	result_empty = ft_strdup(s_empty);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[RESULT]\t: %s\n", result_empty);
	free(result_empty);

	// Duplicate a string containing numbers
	result_numbers = ft_strdup(s_numbers);
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[RESULT]\t: %s\n", result_numbers);
	free(result_numbers);

	// Duplicate a string containing special characters
	result_special = ft_strdup(s_special);
	printf("[STRING]\t: %s\n", s_special);
	printf("[RESULT]\t: %s\n", result_special);
	free(result_special);

	// Duplicate a long string
	result_long = ft_strdup(s_long);
	printf("[STRING]\t: %s\n", s_long);
	printf("[RESULT]\t: %s\n", result_long);
	free(result_long);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	*result_found_original;
	char	*result_empty_original;
	char	*result_numbers_original;
	char	*result_special_original;
	char	*result_long_original;

	// Duplicate a regular string
	result_found_original = strdup(s_found);
	printf("[STRING]\t: %s\n", s_found);
	printf("[RESULT]\t: %s\n", result_found_original);
	free(result_found_original);

	// Duplicate an empty string
	result_empty_original = strdup(s_empty);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[RESULT]\t: %s\n", result_empty_original);
	free(result_empty_original);

	// Duplicate a string containing numbers
	result_numbers_original = strdup(s_numbers);
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[RESULT]\t: %s\n", result_numbers_original);
	free(result_numbers_original);

	// Duplicate a string containing special characters
	result_special_original = strdup(s_special);
	printf("[STRING]\t: %s\n", s_special);
	printf("[RESULT]\t: %s\n", result_special_original);
	free(result_special_original);

	// Duplicate a long string
	result_long_original = strdup(s_long);
	printf("[STRING]\t: %s\n", s_long);
	printf("[RESULT]\t: %s\n", result_long_original);
	free(result_long_original);

	return (0);
}
```

==============================

#### ft_substr

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("=========================== SUBSTR ===========================\n");
	printf("Allocates memory and returns a substring of s, starting at\nindex start and having a maximum length of len characters.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world";
	const char	*s_empty = "";
	const char	*s_short = "Hello";
	const char	*s_numbers = "123456789";
	const char	*s_special = "Hello\tworld!\n";

	unsigned int	start_0 = 6;
	size_t			len_0 = 5;
	unsigned int	start_1 = 0;
	size_t			len_1 = 5;
	unsigned int	start_2 = 10;
	size_t			len_2 = 5;
	unsigned int	start_3 = 3;
	size_t			len_3 = 20;
	unsigned int	start_4 = 2;
	size_t			len_4 = 4;
	unsigned int	start_5 = 0;
	size_t			len_5 = 0;
	unsigned int	start_6 = 20;
	size_t			len_6 = 5;
	unsigned int	start_7 = 5;
	size_t			len_7 = 3;

	char	*result_found;
	char	*result_empty;
	char	*result_out_of_bounds;
	char	*result_long_len;
	char	*result_numbers;
	char	*result_zero_len;
	char	*result_start_beyond;
	char	*result_special;

	// Extract a substring from the middle of a string
	result_found = ft_substr(s_found, start_0, len_0);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_0);
	printf("[LEN]\t\t: %zu\n", len_0);
	printf("[RESULT]\t: %s\n", result_found);
	free(result_found);

	// Extract a substring from an empty string
	result_empty = ft_substr(s_empty, start_1, len_1);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[START]\t\t: %u\n", start_1);
	printf("[LEN]\t\t: %zu\n", len_1);
	printf("[RESULT]\t: %s\n", result_empty);
	free(result_empty);

	// Extract a substring starting at the last character
	result_out_of_bounds = ft_substr(s_found, start_2, len_2);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_2);
	printf("[LEN]\t\t: %zu\n", len_2);
	printf("[RESULT]\t: %s\n", result_out_of_bounds);
	free(result_out_of_bounds);

	// Extract a substring with a length greater than the remaining string
	result_long_len = ft_substr(s_short, start_3, len_3);
	printf("[STRING]\t: %s\n", s_short);
	printf("[START]\t\t: %u\n", start_3);
	printf("[LEN]\t\t: %zu\n", len_3);
	printf("[RESULT]\t: %s\n", result_long_len);
	free(result_long_len);

	// Extract a substring containing numbers
	result_numbers = ft_substr(s_numbers, start_4, len_4);
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[START]\t\t: %u\n", start_4);
	printf("[LEN]\t\t: %zu\n", len_4);
	printf("[RESULT]\t: %s\n", result_numbers);
	free(result_numbers);

	// Extract a substring with zero length
	result_zero_len = ft_substr(s_found, start_5, len_5);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_5);
	printf("[LEN]\t\t: %zu\n", len_5);
	printf("[RESULT]\t: %s\n", result_zero_len);
	free(result_zero_len);

	// Extract a substring starting beyond the end of the string
	result_start_beyond = ft_substr(s_found, start_6, len_6);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_6);
	printf("[LEN]\t\t: %zu\n", len_6);
	printf("[RESULT]\t: %s\n", result_start_beyond);
	free(result_start_beyond);

	// Extract a substring containing special characters
	result_special = ft_substr(s_special, start_7, len_7);
	printf("[STRING]\t: %s\n", s_special);
	printf("[START]\t\t: %u\n", start_7);
	printf("[LEN]\t\t: %zu\n", len_7);
	printf("[RESULT]\t: %s\n", result_special);
	free(result_special);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	*result_found_original;
	char	*result_empty_original;
	char	*result_out_of_bounds_original;
	char	*result_long_len_original;
	char	*result_numbers_original;
	char	*result_zero_len_original;
	char	*result_start_beyond_original;
	char	*result_special_original;

	// Extract a substring from the middle of a string
	result_found_original = strndup(s_found + start_0, len_0);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_0);
	printf("[LEN]\t\t: %zu\n", len_0);
	printf("[RESULT]\t: %s\n", result_found_original);
	free(result_found_original);

	// Extract a substring from an empty string
	result_empty_original = strndup(s_empty + start_1, len_1);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[START]\t\t: %u\n", start_1);
	printf("[LEN]\t\t: %zu\n", len_1);
	printf("[RESULT]\t: %s\n", result_empty_original);
	free(result_empty_original);

	// Extract a substring starting at the last character
	result_out_of_bounds_original = strndup(s_found + start_2, len_2);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_2);
	printf("[LEN]\t\t: %zu\n", len_2);
	printf("[RESULT]\t: %s\n", result_out_of_bounds_original);
	free(result_out_of_bounds_original);

	// Extract a substring with a length greater than the remaining string
	result_long_len_original = strndup(s_short + start_3, len_3);
	printf("[STRING]\t: %s\n", s_short);
	printf("[START]\t\t: %u\n", start_3);
	printf("[LEN]\t\t: %zu\n", len_3);
	printf("[RESULT]\t: %s\n", result_long_len_original);
	free(result_long_len_original);

	// Extract a substring containing numbers
	result_numbers_original = strndup(s_numbers + start_4, len_4);
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[START]\t\t: %u\n", start_4);
	printf("[LEN]\t\t: %zu\n", len_4);
	printf("[RESULT]\t: %s\n", result_numbers_original);
	free(result_numbers_original);

	// Extract a substring with zero length
	result_zero_len_original = strndup(s_found + start_5, len_5);
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_5);
	printf("[LEN]\t\t: %zu\n", len_5);
	printf("[RESULT]\t: %s\n", result_zero_len_original);
	free(result_zero_len_original);

	// Extract a substring starting beyond the end of the string
	result_start_beyond_original = strdup("");
	printf("[STRING]\t: %s\n", s_found);
	printf("[START]\t\t: %u\n", start_6);
	printf("[LEN]\t\t: %zu\n", len_6);
	printf("[RESULT]\t: %s\n", result_start_beyond_original);
	free(result_start_beyond_original);

	// Extract a substring containing special characters
	result_special_original = strndup(s_special + start_7, len_7);
	printf("[STRING]\t: %s\n", s_special);
	printf("[START]\t\t: %u\n", start_7);
	printf("[LEN]\t\t: %zu\n", len_7);
	printf("[RESULT]\t: %s\n", result_special_original);
	free(result_special_original);

	return (0);
}

```

#### ft_strjoin

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("========================== STRJOIN ===========================\n");
	printf("Allocates memory and returns a new string resulting from the\nconcatenation of strings s1 and s2.\n");
	printf("==============================================================\n");

	const char	*s1_found = "Hello ";
	const char	*s2_found = "world!";
	const char	*s1_empty = "";
	const char	*s2_empty = "";
	const char	*s1_first_empty = "";
	const char	*s2_second = "Hello world";
	const char	*s1_first = "Hello world";
	const char	*s2_second_empty = "";
	const char	*s1_numbers = "12345";
	const char	*s2_numbers = "67890";
	const char	*s1_special = "Hello\t";
	const char	*s2_special = "world!\n";

	char	*result_found;
	char	*result_empty;
	char	*result_first_empty;
	char	*result_second_empty;
	char	*result_numbers;
	char	*result_special;

	// Join two regular strings
	result_found = ft_strjoin(s1_found, s2_found);
	printf("[STRING 1]\t: %s\n", s1_found);
	printf("[STRING 2]\t: %s\n", s2_found);
	printf("[RESULT]\t: %s\n", result_found);
	free(result_found);

	// Join two empty strings
	result_empty = ft_strjoin(s1_empty, s2_empty);
	printf("[STRING 1]\t: %s\n", s1_empty);
	printf("[STRING 2]\t: %s\n", s2_empty);
	printf("[RESULT]\t: %s\n", result_empty);
	free(result_empty);

	// Join an empty first string with a regular string
	result_first_empty = ft_strjoin(s1_first_empty, s2_second);
	printf("[STRING 1]\t: %s\n", s1_first_empty);
	printf("[STRING 2]\t: %s\n", s2_second);
	printf("[RESULT]\t: %s\n", result_first_empty);
	free(result_first_empty);

	// Join a regular string with an empty second string
	result_second_empty = ft_strjoin(s1_first, s2_second_empty);
	printf("[STRING 1]\t: %s\n", s1_first);
	printf("[STRING 2]\t: %s\n", s2_second_empty);
	printf("[RESULT]\t: %s\n", result_second_empty);
	free(result_second_empty);

	// Join two strings containing numbers
	result_numbers = ft_strjoin(s1_numbers, s2_numbers);
	printf("[STRING 1]\t: %s\n", s1_numbers);
	printf("[STRING 2]\t: %s\n", s2_numbers);
	printf("[RESULT]\t: %s\n", result_numbers);
	free(result_numbers);

	// Join two strings containing special characters
	result_special = ft_strjoin(s1_special, s2_special);
	printf("[STRING 1]\t: %s\n", s1_special);
	printf("[STRING 2]\t: %s\n", s2_special);
	printf("[RESULT]\t: %s\n", result_special);
	free(result_special);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	*result_found_original;
	char	*result_empty_original;
	char	*result_first_empty_original;
	char	*result_second_empty_original;
	char	*result_numbers_original;
	char	*result_special_original;

	// Join two regular strings
	result_found_original = malloc(strlen(s1_found) + strlen(s2_found) + 1);
	if (result_found_original != NULL)
	{
		strcpy(result_found_original, s1_found);
		strcat(result_found_original, s2_found);
	}
	printf("[STRING 1]\t: %s\n", s1_found);
	printf("[STRING 2]\t: %s\n", s2_found);
	printf("[RESULT]\t: %s\n", result_found_original);
	free(result_found_original);

	// Join two empty strings
	result_empty_original = malloc(strlen(s1_empty) + strlen(s2_empty) + 1);
	if (result_empty_original != NULL)
	{
		strcpy(result_empty_original, s1_empty);
		strcat(result_empty_original, s2_empty);
	}
	printf("[STRING 1]\t: %s\n", s1_empty);
	printf("[STRING 2]\t: %s\n", s2_empty);
	printf("[RESULT]\t: %s\n", result_empty_original);
	free(result_empty_original);

	// Join an empty first string with a regular string
	result_first_empty_original = malloc(strlen(s1_first_empty) + strlen(s2_second) + 1);
	if (result_first_empty_original != NULL)
	{
		strcpy(result_first_empty_original, s1_first_empty);
		strcat(result_first_empty_original, s2_second);
	}
	printf("[STRING 1]\t: %s\n", s1_first_empty);
	printf("[STRING 2]\t: %s\n", s2_second);
	printf("[RESULT]\t: %s\n", result_first_empty_original);
	free(result_first_empty_original);

	// Join a regular string with an empty second string
	result_second_empty_original = malloc(strlen(s1_first) + strlen(s2_second_empty) + 1);
	if (result_second_empty_original != NULL)
	{
		strcpy(result_second_empty_original, s1_first);
		strcat(result_second_empty_original, s2_second_empty);
	}
	printf("[STRING 1]\t: %s\n", s1_first);
	printf("[STRING 2]\t: %s\n", s2_second_empty);
	printf("[RESULT]\t: %s\n", result_second_empty_original);
	free(result_second_empty_original);

	// Join two strings containing numbers
	result_numbers_original = malloc(strlen(s1_numbers) + strlen(s2_numbers) + 1);
	if (result_numbers_original != NULL)
	{
		strcpy(result_numbers_original, s1_numbers);
		strcat(result_numbers_original, s2_numbers);
	}
	printf("[STRING 1]\t: %s\n", s1_numbers);
	printf("[STRING 2]\t: %s\n", s2_numbers);
	printf("[RESULT]\t: %s\n", result_numbers_original);
	free(result_numbers_original);

	// Join two strings containing special characters
	result_special_original = malloc(strlen(s1_special) + strlen(s2_special) + 1);
	if (result_special_original != NULL)
	{
		strcpy(result_special_original, s1_special);
		strcat(result_special_original, s2_special);
	}
	printf("[STRING 1]\t: %s\n", s1_special);
	printf("[STRING 2]\t: %s\n", s2_special);
	printf("[RESULT]\t: %s\n", result_special_original);
	free(result_special_original);

	return (0);
}
```

#### ft_strtrim

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("========================== STRTRIM ===========================\n");
	printf("Allocates memory and returns a copy of s1 with the characters\nspecified in set removed from the beginning and end.\n");
	printf("==============================================================\n");

	const char	*s1_found = "   Hello world   ";
	const char	*set_found = " ";
	const char	*s1_empty = "";
	const char	*set_empty = " ";
	const char	*s1_all = "xxxxx";
	const char	*set_all = "x";
	const char	*s1_start = "xxxHello world";
	const char	*set_start = "x";
	const char	*s1_end = "Hello worldxxx";
	const char	*set_end = "x";
	const char	*s1_both = "xxxHello worldxxx";
	const char	*set_both = "x";
	const char	*s1_special = "***Hello world***";
	const char	*set_special = "*";
	const char	*s1_multiple = "abcHello worldcba";
	const char	*set_multiple = "abc";

	char	*result_found;
	char	*result_empty;
	char	*result_all;
	char	*result_start;
	char	*result_end;
	char	*result_both;
	char	*result_special;
	char	*result_multiple;

	// Trim spaces from the beginning and end
	result_found = ft_strtrim(s1_found, set_found);
	printf("[STRING]\t: %s\n", s1_found);
	printf("[SET]\t\t: %s\n", set_found);
	printf("[RESULT]\t: %s\n", result_found);
	free(result_found);

	// Trim an empty string
	result_empty = ft_strtrim(s1_empty, set_empty);
	printf("[STRING]\t: %s\n", s1_empty);
	printf("[SET]\t\t: %s\n", set_empty);
	printf("[RESULT]\t: %s\n", result_empty);
	free(result_empty);

	// Trim a string containing only characters from set
	result_all = ft_strtrim(s1_all, set_all);
	printf("[STRING]\t: %s\n", s1_all);
	printf("[SET]\t\t: %s\n", set_all);
	printf("[RESULT]\t: %s\n", result_all);
	free(result_all);

	// Trim characters from the beginning
	result_start = ft_strtrim(s1_start, set_start);
	printf("[STRING]\t: %s\n", s1_start);
	printf("[SET]\t\t: %s\n", set_start);
	printf("[RESULT]\t: %s\n", result_start);
	free(result_start);

	// Trim characters from the end
	result_end = ft_strtrim(s1_end, set_end);
	printf("[STRING]\t: %s\n", s1_end);
	printf("[SET]\t\t: %s\n", set_end);
	printf("[RESULT]\t: %s\n", result_end);
	free(result_end);

	// Trim characters from both ends
	result_both = ft_strtrim(s1_both, set_both);
	printf("[STRING]\t: %s\n", s1_both);
	printf("[SET]\t\t: %s\n", set_both);
	printf("[RESULT]\t: %s\n", result_both);
	free(result_both);

	// Trim special characters from both ends
	result_special = ft_strtrim(s1_special, set_special);
	printf("[STRING]\t: %s\n", s1_special);
	printf("[SET]\t\t: %s\n", set_special);
	printf("[RESULT]\t: %s\n", result_special);
	free(result_special);

	// Trim multiple characters specified in set
	result_multiple = ft_strtrim(s1_multiple, set_multiple);
	printf("[STRING]\t: %s\n", s1_multiple);
	printf("[SET]\t\t: %s\n", set_multiple);
	printf("[RESULT]\t: %s\n", result_multiple);
	free(result_multiple);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	*result_found_original;
	char	*result_empty_original;
	char	*result_all_original;
	char	*result_start_original;
	char	*result_end_original;
	char	*result_both_original;
	char	*result_special_original;
	char	*result_multiple_original;

	// Trim spaces from the beginning and end
	result_found_original = strdup(s1_found);
	if (result_found_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_found_original);

		while (result_found_original[start]
			&& strchr(set_found, result_found_original[start]))
			start++;
		while (end > start
			&& strchr(set_found, result_found_original[end - 1]))
			end--;
		memmove(result_found_original, result_found_original + start,
			end - start);
		result_found_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_found);
	printf("[SET]\t\t: %s\n", set_found);
	printf("[RESULT]\t: %s\n", result_found_original);
	free(result_found_original);

	// Trim an empty string
	result_empty_original = strdup(s1_empty);
	printf("[STRING]\t: %s\n", s1_empty);
	printf("[SET]\t\t: %s\n", set_empty);
	printf("[RESULT]\t: %s\n", result_empty_original);
	free(result_empty_original);

	// Trim a string containing only characters from set
	result_all_original = strdup(s1_all);
	if (result_all_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_all_original);

		while (result_all_original[start]
			&& strchr(set_all, result_all_original[start]))
			start++;
		while (end > start
			&& strchr(set_all, result_all_original[end - 1]))
			end--;
		memmove(result_all_original, result_all_original + start,
			end - start);
		result_all_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_all);
	printf("[SET]\t\t: %s\n", set_all);
	printf("[RESULT]\t: %s\n", result_all_original);
	free(result_all_original);

	// Trim characters from the beginning
	result_start_original = strdup(s1_start);
	if (result_start_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_start_original);

		while (result_start_original[start]
			&& strchr(set_start, result_start_original[start]))
			start++;
		while (end > start
			&& strchr(set_start, result_start_original[end - 1]))
			end--;
		memmove(result_start_original, result_start_original + start,
			end - start);
		result_start_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_start);
	printf("[SET]\t\t: %s\n", set_start);
	printf("[RESULT]\t: %s\n", result_start_original);
	free(result_start_original);

	// Trim characters from the end
	result_end_original = strdup(s1_end);
	if (result_end_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_end_original);

		while (result_end_original[start]
			&& strchr(set_end, result_end_original[start]))
			start++;
		while (end > start
			&& strchr(set_end, result_end_original[end - 1]))
			end--;
		memmove(result_end_original, result_end_original + start,
			end - start);
		result_end_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_end);
	printf("[SET]\t\t: %s\n", set_end);
	printf("[RESULT]\t: %s\n", result_end_original);
	free(result_end_original);

	// Trim characters from both ends
	result_both_original = strdup(s1_both);
	if (result_both_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_both_original);

		while (result_both_original[start]
			&& strchr(set_both, result_both_original[start]))
			start++;
		while (end > start
			&& strchr(set_both, result_both_original[end - 1]))
			end--;
		memmove(result_both_original, result_both_original + start,
			end - start);
		result_both_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_both);
	printf("[SET]\t\t: %s\n", set_both);
	printf("[RESULT]\t: %s\n", result_both_original);
	free(result_both_original);

	// Trim special characters from both ends
	result_special_original = strdup(s1_special);
	if (result_special_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_special_original);

		while (result_special_original[start]
			&& strchr(set_special, result_special_original[start]))
			start++;
		while (end > start
			&& strchr(set_special, result_special_original[end - 1]))
			end--;
		memmove(result_special_original, result_special_original + start,
			end - start);
		result_special_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_special);
	printf("[SET]\t\t: %s\n", set_special);
	printf("[RESULT]\t: %s\n", result_special_original);
	free(result_special_original);

	// Trim multiple characters specified in set
	result_multiple_original = strdup(s1_multiple);
	if (result_multiple_original != NULL)
	{
		size_t	start = 0;
		size_t	end = strlen(result_multiple_original);

		while (result_multiple_original[start]
			&& strchr(set_multiple, result_multiple_original[start]))
			start++;
		while (end > start
			&& strchr(set_multiple, result_multiple_original[end - 1]))
			end--;
		memmove(result_multiple_original, result_multiple_original + start,
			end - start);
		result_multiple_original[end - start] = '\0';
	}
	printf("[STRING]\t: %s\n", s1_multiple);
	printf("[SET]\t\t: %s\n", set_multiple);
	printf("[RESULT]\t: %s\n", result_multiple_original);
	free(result_multiple_original);

	return (0);
}
```

#### ft_split

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_original(const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	count;
	size_t	j;
	char	**split;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		split[j] = malloc(i - start + 1);
		if (!split[j])
		{
			while (j > 0)
				free(split[--j]);
			free(split);
			return (NULL);
		}
		memcpy(split[j], s + start, i - start);
		split[j][i - start] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

int	main(void)
{
	printf("=========================== SPLIT ============================\n");
	printf("Allocates memory and returns an array of strings obtained by\nsplitting s using the character c as a delimiter.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world from split";
	const char	*s_empty = "";
	const char	*s_only_delimiters = "*****";
	const char	*s_start = "***Hello world";
	const char	*s_end = "Hello world***";
	const char	*s_multiple = "Hello***world**from*split";
	const char	*s_consecutive = "Hello   world  from   split";
	const char	*s_single = "Hello";

	char	c_found = ' ';
	char	c_empty = ' ';
	char	c_only_delimiters = '*';
	char	c_start = '*';
	char	c_end = '*';
	char	c_multiple = '*';
	char	c_consecutive = ' ';
	char	c_single = ' ';

	char	**result_found;
	char	**result_empty;
	char	**result_only_delimiters;
	char	**result_start;
	char	**result_end;
	char	**result_multiple;
	char	**result_consecutive;
	char	**result_single;

	int	i;

	// Split a regular string
	result_found = ft_split(s_found, c_found);
	printf("[STRING]\t: %s\n", s_found);
	printf("[DELIMITER]\t: %c\n", c_found);
	printf("[RESULT]\t:\n");
	if (result_found != NULL)
	{
		i = 0;
		while (result_found[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_found[i]);
			i++;
		}
	}
	free_split(result_found);

	// Split an empty string
	result_empty = ft_split(s_empty, c_empty);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[DELIMITER]\t: %c\n", c_empty);
	printf("[RESULT]\t:\n");
	if (result_empty != NULL)
	{
		i = 0;
		while (result_empty[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_empty[i]);
			i++;
		}
	}
	free_split(result_empty);

	// Split a string containing only delimiters
	result_only_delimiters = ft_split(s_only_delimiters, c_only_delimiters);
	printf("[STRING]\t: %s\n", s_only_delimiters);
	printf("[DELIMITER]\t: %c\n", c_only_delimiters);
	printf("[RESULT]\t:\n");
	if (result_only_delimiters != NULL)
	{
		i = 0;
		while (result_only_delimiters[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_only_delimiters[i]);
			i++;
		}
	}
	free_split(result_only_delimiters);

	// Split a string starting with delimiters
	result_start = ft_split(s_start, c_start);
	printf("[STRING]\t: %s\n", s_start);
	printf("[DELIMITER]\t: %c\n", c_start);
	printf("[RESULT]\t:\n");
	if (result_start != NULL)
	{
		i = 0;
		while (result_start[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_start[i]);
			i++;
		}
	}
	free_split(result_start);

	// Split a string ending with delimiters
	result_end = ft_split(s_end, c_end);
	printf("[STRING]\t: %s\n", s_end);
	printf("[DELIMITER]\t: %c\n", c_end);
	printf("[RESULT]\t:\n");
	if (result_end != NULL)
	{
		i = 0;
		while (result_end[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_end[i]);
			i++;
		}
	}
	free_split(result_end);

	// Split a string using multiple consecutive delimiters
	result_multiple = ft_split(s_multiple, c_multiple);
	printf("[STRING]\t: %s\n", s_multiple);
	printf("[DELIMITER]\t: %c\n", c_multiple);
	printf("[RESULT]\t:\n");
	if (result_multiple != NULL)
	{
		i = 0;
		while (result_multiple[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_multiple[i]);
			i++;
		}
	}
	free_split(result_multiple);

	// Split a string containing consecutive spaces
	result_consecutive = ft_split(s_consecutive, c_consecutive);
	printf("[STRING]\t: %s\n", s_consecutive);
	printf("[DELIMITER]\t: %c\n", c_consecutive);
	printf("[RESULT]\t:\n");
	if (result_consecutive != NULL)
	{
		i = 0;
		while (result_consecutive[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_consecutive[i]);
			i++;
		}
	}
	free_split(result_consecutive);

	// Split a string containing a single word
	result_single = ft_split(s_single, c_single);
	printf("[STRING]\t: %s\n", s_single);
	printf("[DELIMITER]\t: %c\n", c_single);
	printf("[RESULT]\t:\n");
	if (result_single != NULL)
	{
		i = 0;
		while (result_single[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_single[i]);
			i++;
		}
	}
	free_split(result_single);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	**result_found_original;
	char	**result_empty_original;
	char	**result_only_delimiters_original;
	char	**result_start_original;
	char	**result_end_original;
	char	**result_multiple_original;
	char	**result_consecutive_original;
	char	**result_single_original;

	// Split a regular string
	result_found_original = split_original(s_found, c_found);
	printf("[STRING]\t: %s\n", s_found);
	printf("[DELIMITER]\t: %c\n", c_found);
	printf("[RESULT]\t:\n");
	if (result_found_original != NULL)
	{
		i = 0;
		while (result_found_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_found_original[i]);
			i++;
		}
	}
	free_split(result_found_original);

	// Split an empty string
	result_empty_original = split_original(s_empty, c_empty);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[DELIMITER]\t: %c\n", c_empty);
	printf("[RESULT]\t:\n");
	if (result_empty_original != NULL)
	{
		i = 0;
		while (result_empty_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_empty_original[i]);
			i++;
		}
	}
	free_split(result_empty_original);

	// Split a string containing only delimiters
	result_only_delimiters_original = split_original(s_only_delimiters,
			c_only_delimiters);
	printf("[STRING]\t: %s\n", s_only_delimiters);
	printf("[DELIMITER]\t: %c\n", c_only_delimiters);
	printf("[RESULT]\t:\n");
	if (result_only_delimiters_original != NULL)
	{
		i = 0;
		while (result_only_delimiters_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i,
				result_only_delimiters_original[i]);
			i++;
		}
	}
	free_split(result_only_delimiters_original);

	// Split a string starting with delimiters
	result_start_original = split_original(s_start, c_start);
	printf("[STRING]\t: %s\n", s_start);
	printf("[DELIMITER]\t: %c\n", c_start);
	printf("[RESULT]\t:\n");
	if (result_start_original != NULL)
	{
		i = 0;
		while (result_start_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_start_original[i]);
			i++;
		}
	}
	free_split(result_start_original);

	// Split a string ending with delimiters
	result_end_original = split_original(s_end, c_end);
	printf("[STRING]\t: %s\n", s_end);
	printf("[DELIMITER]\t: %c\n", c_end);
	printf("[RESULT]\t:\n");
	if (result_end_original != NULL)
	{
		i = 0;
		while (result_end_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_end_original[i]);
			i++;
		}
	}
	free_split(result_end_original);

	// Split a string using multiple consecutive delimiters
	result_multiple_original = split_original(s_multiple, c_multiple);
	printf("[STRING]\t: %s\n", s_multiple);
	printf("[DELIMITER]\t: %c\n", c_multiple);
	printf("[RESULT]\t:\n");
	if (result_multiple_original != NULL)
	{
		i = 0;
		while (result_multiple_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_multiple_original[i]);
			i++;
		}
	}
	free_split(result_multiple_original);

	// Split a string containing consecutive spaces
	result_consecutive_original = split_original(s_consecutive,
			c_consecutive);
	printf("[STRING]\t: %s\n", s_consecutive);
	printf("[DELIMITER]\t: %c\n", c_consecutive);
	printf("[RESULT]\t:\n");
	if (result_consecutive_original != NULL)
	{
		i = 0;
		while (result_consecutive_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i,
				result_consecutive_original[i]);
			i++;
		}
	}
	free_split(result_consecutive_original);

	// Split a string containing a single word
	result_single_original = split_original(s_single, c_single);
	printf("[STRING]\t: %s\n", s_single);
	printf("[DELIMITER]\t: %c\n", c_single);
	printf("[RESULT]\t:\n");
	if (result_single_original != NULL)
	{
		i = 0;
		while (result_single_original[i] != NULL)
		{
			printf("\t\t  [%d] : %s\n", i, result_single_original[i]);
			i++;
		}
	}
	free_split(result_single_original);

	return (0);
}
```

#### ft_itoa

```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	printf("=========================== ITOA =============================\n");
	printf("Allocates memory and returns a string representing the integer n.\n");
	printf("==============================================================\n");

	int	n_0 = 0;
	int	n_1 = 42;
	int	n_2 = -42;
	int	n_3 = 123456789;
	int	n_4 = -123456789;
	int	n_5 = INT_MAX;
	int	n_6 = INT_MIN;
	int	n_7 = 1;
	int	n_8 = -1;
	int	n_9 = 100000;

	char	*result_0;
	char	*result_1;
	char	*result_2;
	char	*result_3;
	char	*result_4;
	char	*result_5;
	char	*result_6;
	char	*result_7;
	char	*result_8;
	char	*result_9;

	// Convert zero to a string
	result_0 = ft_itoa(n_0);
	printf("[NUMBER]\t: %d\n", n_0);
	printf("[RESULT]\t: %s\n", result_0);
	free(result_0);

	// Convert a positive integer to a string
	result_1 = ft_itoa(n_1);
	printf("[NUMBER]\t: %d\n", n_1);
	printf("[RESULT]\t: %s\n", result_1);
	free(result_1);

	// Convert a negative integer to a string
	result_2 = ft_itoa(n_2);
	printf("[NUMBER]\t: %d\n", n_2);
	printf("[RESULT]\t: %s\n", result_2);
	free(result_2);

	// Convert a large positive integer to a string
	result_3 = ft_itoa(n_3);
	printf("[NUMBER]\t: %d\n", n_3);
	printf("[RESULT]\t: %s\n", result_3);
	free(result_3);

	// Convert a large negative integer to a string
	result_4 = ft_itoa(n_4);
	printf("[NUMBER]\t: %d\n", n_4);
	printf("[RESULT]\t: %s\n", result_4);
	free(result_4);

	// Convert the maximum integer value to a string
	result_5 = ft_itoa(n_5);
	printf("[NUMBER]\t: %d\n", n_5);
	printf("[RESULT]\t: %s\n", result_5);
	free(result_5);

	// Convert the minimum integer value to a string
	result_6 = ft_itoa(n_6);
	printf("[NUMBER]\t: %d\n", n_6);
	printf("[RESULT]\t: %s\n", result_6);
	free(result_6);

	// Convert a small positive integer to a string
	result_7 = ft_itoa(n_7);
	printf("[NUMBER]\t: %d\n", n_7);
	printf("[RESULT]\t: %s\n", result_7);
	free(result_7);

	// Convert a small negative integer to a string
	result_8 = ft_itoa(n_8);
	printf("[NUMBER]\t: %d\n", n_8);
	printf("[RESULT]\t: %s\n", result_8);
	free(result_8);

	// Convert an integer containing trailing zeros to a string
	result_9 = ft_itoa(n_9);
	printf("[NUMBER]\t: %d\n", n_9);
	printf("[RESULT]\t: %s\n", result_9);
	free(result_9);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	*result_0_original;
	char	*result_1_original;
	char	*result_2_original;
	char	*result_3_original;
	char	*result_4_original;
	char	*result_5_original;
	char	*result_6_original;
	char	*result_7_original;
	char	*result_8_original;
	char	*result_9_original;

	// Convert zero to a string
	result_0_original = malloc(12 * sizeof(char));
	if (result_0_original != NULL)
		sprintf(result_0_original, "%d", n_0);
	printf("[NUMBER]\t: %d\n", n_0);
	printf("[RESULT]\t: %s\n", result_0_original);
	free(result_0_original);

	// Convert a positive integer to a string
	result_1_original = malloc(12 * sizeof(char));
	if (result_1_original != NULL)
		sprintf(result_1_original, "%d", n_1);
	printf("[NUMBER]\t: %d\n", n_1);
	printf("[RESULT]\t: %s\n", result_1_original);
	free(result_1_original);

	// Convert a negative integer to a string
	result_2_original = malloc(12 * sizeof(char));
	if (result_2_original != NULL)
		sprintf(result_2_original, "%d", n_2);
	printf("[NUMBER]\t: %d\n", n_2);
	printf("[RESULT]\t: %s\n", result_2_original);
	free(result_2_original);

	// Convert a large positive integer to a string
	result_3_original = malloc(12 * sizeof(char));
	if (result_3_original != NULL)
		sprintf(result_3_original, "%d", n_3);
	printf("[NUMBER]\t: %d\n", n_3);
	printf("[RESULT]\t: %s\n", result_3_original);
	free(result_3_original);

	// Convert a large negative integer to a string
	result_4_original = malloc(12 * sizeof(char));
	if (result_4_original != NULL)
		sprintf(result_4_original, "%d", n_4);
	printf("[NUMBER]\t: %d\n", n_4);
	printf("[RESULT]\t: %s\n", result_4_original);
	free(result_4_original);

	// Convert the maximum integer value to a string
	result_5_original = malloc(12 * sizeof(char));
	if (result_5_original != NULL)
		sprintf(result_5_original, "%d", n_5);
	printf("[NUMBER]\t: %d\n", n_5);
	printf("[RESULT]\t: %s\n", result_5_original);
	free(result_5_original);

	// Convert the minimum integer value to a string
	result_6_original = malloc(12 * sizeof(char));
	if (result_6_original != NULL)
		sprintf(result_6_original, "%d", n_6);
	printf("[NUMBER]\t: %d\n", n_6);
	printf("[RESULT]\t: %s\n", result_6_original);
	free(result_6_original);

	// Convert a small positive integer to a string
	result_7_original = malloc(12 * sizeof(char));
	if (result_7_original != NULL)
		sprintf(result_7_original, "%d", n_7);
	printf("[NUMBER]\t: %d\n", n_7);
	printf("[RESULT]\t: %s\n", result_7_original);
	free(result_7_original);

	// Convert a small negative integer to a string
	result_8_original = malloc(12 * sizeof(char));
	if (result_8_original != NULL)
		sprintf(result_8_original, "%d", n_8);
	printf("[NUMBER]\t: %d\n", n_8);
	printf("[RESULT]\t: %s\n", result_8_original);
	free(result_8_original);

	// Convert an integer containing trailing zeros to a string
	result_9_original = malloc(12 * sizeof(char));
	if (result_9_original != NULL)
		sprintf(result_9_original, "%d", n_9);
	printf("[NUMBER]\t: %d\n", n_9);
	printf("[RESULT]\t: %s\n", result_9_original);
	free(result_9_original);

	return (0);
}
```

#### ft_strmapi

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char	ft_mapi_upper(unsigned int i, char c)
{
	(void)i;
	return (toupper((unsigned char)c));
}

char	ft_mapi_lower(unsigned int i, char c)
{
	(void)i;
	return (tolower((unsigned char)c));
}

char	ft_mapi_index(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (i % 2 == 0 && c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	ft_mapi_increment(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c < 'z')
		return (c + 1);
	if (c >= 'A' && c < 'Z')
		return (c + 1);
	return (c);
}

char	ft_mapi_index_char(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + (i % 26));
	return (c);
}

int	main(void)
{
	printf("========================== STRMAPI ===========================\n");
	printf("Applies the function f to each character of the string s,\nusing its index, and returns a newly allocated string.\n");
	printf("==============================================================\n");

	const char	*s_found = "Hello world";
	const char	*s_empty = "";
	const char	*s_numbers = "123456789";
	const char	*s_special = "Hello, world!";
	const char	*s_mixed = "Hello World 123";

	char	*result_found;
	char	*result_empty;
	char	*result_numbers;
	char	*result_special;
	char	*result_mixed;

	// Apply uppercase transformation
	result_found = ft_strmapi(s_found, ft_mapi_upper);
	printf("[STRING]\t: %s\n", s_found);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_found);
	free(result_found);

	// Apply lowercase transformation to an empty string
	result_empty = ft_strmapi(s_empty, ft_mapi_lower);
	printf("[STRING]\t: %s\n", s_empty);
	printf("[FUNCTION]\t: lowercase\n");
	printf("[RESULT]\t: %s\n", result_empty);
	free(result_empty);

	// Apply uppercase transformation to a string containing numbers
	result_numbers = ft_strmapi(s_numbers, ft_mapi_upper);
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_numbers);
	free(result_numbers);

	// Apply uppercase transformation to a string containing special characters
	result_special = ft_strmapi(s_special, ft_mapi_upper);
	printf("[STRING]\t: %s\n", s_special);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_special);
	free(result_special);

	// Apply a transformation depending on each character's index
	result_mixed = ft_strmapi(s_mixed, ft_mapi_index);
	printf("[STRING]\t: %s\n", s_mixed);
	printf("[FUNCTION]\t: index-based transformation\n");
	printf("[RESULT]\t: %s\n", result_mixed);
	free(result_mixed);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	/*
	** There is no standard C equivalent of ft_strmapi.
	** The original section manually reproduces each transformation.
	*/

	char	*result_found_original;
	char	*result_empty_original;
	char	*result_numbers_original;
	char	*result_special_original;
	char	*result_mixed_original;

	size_t	i;

	// Apply uppercase transformation
	result_found_original = strdup(s_found);
	if (result_found_original != NULL)
	{
		i = 0;
		while (result_found_original[i])
		{
			result_found_original[i] = ft_mapi_upper(i,
					result_found_original[i]);
			i++;
		}
	}
	printf("[STRING]\t: %s\n", s_found);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_found_original);
	free(result_found_original);

	// Apply lowercase transformation to an empty string
	result_empty_original = strdup(s_empty);
	if (result_empty_original != NULL)
	{
		i = 0;
		while (result_empty_original[i])
		{
			result_empty_original[i] = ft_mapi_lower(i,
					result_empty_original[i]);
			i++;
		}
	}
	printf("[STRING]\t: %s\n", s_empty);
	printf("[FUNCTION]\t: lowercase\n");
	printf("[RESULT]\t: %s\n", result_empty_original);
	free(result_empty_original);

	// Apply uppercase transformation to a string containing numbers
	result_numbers_original = strdup(s_numbers);
	if (result_numbers_original != NULL)
	{
		i = 0;
		while (result_numbers_original[i])
		{
			result_numbers_original[i] = ft_mapi_upper(i,
					result_numbers_original[i]);
			i++;
		}
	}
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_numbers_original);
	free(result_numbers_original);

	// Apply uppercase transformation to a string containing special characters
	result_special_original = strdup(s_special);
	if (result_special_original != NULL)
	{
		i = 0;
		while (result_special_original[i])
		{
			result_special_original[i] = ft_mapi_upper(i,
					result_special_original[i]);
			i++;
		}
	}
	printf("[STRING]\t: %s\n", s_special);
	printf("[FUNCTION]\t: uppercase\n");
	printf("[RESULT]\t: %s\n", result_special_original);
	free(result_special_original);

	// Apply a transformation depending on each character's index
	result_mixed_original = strdup(s_mixed);
	if (result_mixed_original != NULL)
	{
		i = 0;
		while (result_mixed_original[i])
		{
			result_mixed_original[i] = ft_mapi_index(i,
					result_mixed_original[i]);
			i++;
		}
	}
	printf("[STRING]\t: %s\n", s_mixed);
	printf("[FUNCTION]\t: index-based transformation\n");
	printf("[RESULT]\t: %s\n", result_mixed_original);
	free(result_mixed_original);

	return (0);
}
```

#### ft_striteri

```
#include <stdio.h>
#include <string.h>

void	ft_iteri_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	ft_iteri_lower(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void	ft_iteri_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
	else if (i % 2 != 0 && *c >= 'A' && *c <= 'Z')
		*c += 32;
}

void	ft_iteri_increment(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c < 'z')
		(*c)++;
	else if (*c >= 'A' && *c < 'Z')
		(*c)++;
}

void	ft_iteri_index_char(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = 'a' + ((*c - 'a' + i) % 26);
}

int	main(void)
{
	printf("========================== STRITERI ==========================\n");
	printf("Applies the function f to each character of the string s,\npassing its index and a pointer to the character.\n");
	printf("==============================================================\n");

	char	s_found[] = "Hello world";
	char	s_empty[] = "";
	char	s_numbers[] = "123456789";
	char	s_special[] = "Hello, world!";
	char	s_mixed[] = "Hello World 123";

	// Apply uppercase transformation
	printf("[STRING]\t: %s\n", s_found);
	printf("[FUNCTION]\t: uppercase\n");
	ft_striteri(s_found, ft_iteri_upper);
	printf("[RESULT]\t: %s\n", s_found);

	// Apply lowercase transformation to an empty string
	printf("[STRING]\t: %s\n", s_empty);
	printf("[FUNCTION]\t: lowercase\n");
	ft_striteri(s_empty, ft_iteri_lower);
	printf("[RESULT]\t: %s\n", s_empty);

	// Apply uppercase transformation to a string containing numbers
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FUNCTION]\t: uppercase\n");
	ft_striteri(s_numbers, ft_iteri_upper);
	printf("[RESULT]\t: %s\n", s_numbers);

	// Apply uppercase transformation to a string containing special characters
	printf("[STRING]\t: %s\n", s_special);
	printf("[FUNCTION]\t: uppercase\n");
	ft_striteri(s_special, ft_iteri_upper);
	printf("[RESULT]\t: %s\n", s_special);

	// Apply a transformation depending on each character's index
	printf("[STRING]\t: %s\n", s_mixed);
	printf("[FUNCTION]\t: index-based transformation\n");
	ft_striteri(s_mixed, ft_iteri_index);
	printf("[RESULT]\t: %s\n", s_mixed);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	char	s_found_original[] = "Hello world";
	char	s_empty_original[] = "";
	char	s_numbers_original[] = "123456789";
	char	s_special_original[] = "Hello, world!";
	char	s_mixed_original[] = "Hello World 123";

	unsigned int	i;

	// Apply uppercase transformation
	printf("[STRING]\t: %s\n", s_found_original);
	printf("[FUNCTION]\t: uppercase\n");
	i = 0;
	while (s_found_original[i])
	{
		if (s_found_original[i] >= 'a' && s_found_original[i] <= 'z')
			s_found_original[i] -= 32;
		i++;
	}
	printf("[RESULT]\t: %s\n", s_found_original);

	// Apply lowercase transformation to an empty string
	printf("[STRING]\t: %s\n", s_empty_original);
	printf("[FUNCTION]\t: lowercase\n");
	i = 0;
	while (s_empty_original[i])
	{
		if (s_empty_original[i] >= 'A' && s_empty_original[i] <= 'Z')
			s_empty_original[i] += 32;
		i++;
	}
	printf("[RESULT]\t: %s\n", s_empty_original);

	// Apply uppercase transformation to a string containing numbers
	printf("[STRING]\t: %s\n", s_numbers_original);
	printf("[FUNCTION]\t: uppercase\n");
	i = 0;
	while (s_numbers_original[i])
	{
		if (s_numbers_original[i] >= 'a' && s_numbers_original[i] <= 'z')
			s_numbers_original[i] -= 32;
		i++;
	}
	printf("[RESULT]\t: %s\n", s_numbers_original);

	// Apply uppercase transformation to a string containing special characters
	printf("[STRING]\t: %s\n", s_special_original);
	printf("[FUNCTION]\t: uppercase\n");
	i = 0;
	while (s_special_original[i])
	{
		if (s_special_original[i] >= 'a' && s_special_original[i] <= 'z')
			s_special_original[i] -= 32;
		i++;
	}
	printf("[RESULT]\t: %s\n", s_special_original);

	// Apply a transformation depending on each character's index
	printf("[STRING]\t: %s\n", s_mixed_original);
	printf("[FUNCTION]\t: index-based transformation\n");
	i = 0;
	while (s_mixed_original[i])
	{
		if (i % 2 == 0 && s_mixed_original[i] >= 'a'
			&& s_mixed_original[i] <= 'z')
			s_mixed_original[i] -= 32;
		else if (i % 2 != 0 && s_mixed_original[i] >= 'A'
			&& s_mixed_original[i] <= 'Z')
			s_mixed_original[i] += 32;
		i++;
	}
	printf("[RESULT]\t: %s\n", s_mixed_original);

	return (0);
}
```

#### ft_putchar_fd

```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	printf("========================= PUTCHAR_FD =========================\n");
	printf("Writes the character c to the file descriptor fd.\n");
	printf("==============================================================\n");

	char	c_found = 'A';
	char	c_number = '7';
	char	c_special = '\n';
	char	c_space = ' ';
	char	c_invalid = 'X';

	int	fd_stdout = 1;
	int	fd_stderr = 2;
	int	fd_file;
	int	fd_invalid = -1;

	// Write a character to standard output
	printf("[CHARACTER]\t: %c\n", c_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putchar_fd(c_found, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a character to standard error
	printf("[CHARACTER]\t: %c\n", c_number);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	ft_putchar_fd(c_number, fd_stderr);
	ft_putchar_fd('\n', fd_stderr);

	// Write a newline character to standard output
	printf("[CHARACTER]\t: '\\n'\n");
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putchar_fd(c_special, fd_stdout);

	// Write a space character to standard output
	printf("[CHARACTER]\t: ' '\n");
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putchar_fd(c_space, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a character to a file
	fd_file = open("putchar_fd_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[CHARACTER]\t: %c\n", c_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: Character written to putchar_fd_test.txt\n");
		ft_putchar_fd(c_found, fd_file);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[CHARACTER]\t: %c\n", c_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No character should be written\n");
	ft_putchar_fd(c_invalid, fd_invalid);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	// Write a character to standard output
	printf("[CHARACTER]\t: %c\n", c_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, &c_found, 1);
	write(fd_stdout, "\n", 1);

	// Write a character to standard error
	printf("[CHARACTER]\t: %c\n", c_number);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	write(fd_stderr, &c_number, 1);
	write(fd_stderr, "\n", 1);

	// Write a newline character to standard output
	printf("[CHARACTER]\t: '\\n'\n");
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, &c_special, 1);

	// Write a space character to standard output
	printf("[CHARACTER]\t: ' '\n");
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, &c_space, 1);
	write(fd_stdout, "\n", 1);

	// Write a character to a file
	fd_file = open("putchar_fd_original.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[CHARACTER]\t: %c\n", c_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: Character written to putchar_fd_original.txt\n");
		write(fd_file, &c_found, 1);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[CHARACTER]\t: %c\n", c_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No character should be written\n");
	if (fd_invalid >= 0)
		write(fd_invalid, &c_invalid, 1);

	return (0);
}
```

#### ft_putstr_fd

```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	printf("========================== PUTSTR_FD =========================\n");
	printf("Writes the string s to the file descriptor fd.\n");
	printf("==============================================================\n");

	char	*s_found = "Hello world!";
	char	*s_empty = "";
	char	*s_numbers = "123456789";
	char	*s_special = "Hello\tworld!\n";
	char	*s_multiline = "First line\nSecond line\nThird line";
	char	*s_invalid = "This should not be written";

	int	fd_stdout = 1;
	int	fd_stderr = 2;
	int	fd_file;
	int	fd_invalid = -1;

	// Write a regular string to standard output
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putstr_fd(s_found, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write an empty string to standard output
	printf("[STRING]\t: \"%s\"\n", s_empty);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putstr_fd(s_empty, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a string containing numbers to standard output
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putstr_fd(s_numbers, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a string containing special characters to standard output
	printf("[STRING]\t: %s\n", s_special);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putstr_fd(s_special, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a multiline string to standard output
	printf("[STRING]\t: %s\n", s_multiline);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t:\n");
	ft_putstr_fd(s_multiline, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a regular string to standard error
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	ft_putstr_fd(s_found, fd_stderr);
	ft_putchar_fd('\n', fd_stderr);

	// Write a string to a file
	fd_file = open("putstr_fd_test.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[STRING]\t: %s\n", s_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: String written to putstr_fd_test.txt\n");
		ft_putstr_fd(s_found, fd_file);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[STRING]\t: %s\n", s_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No string should be written\n");
	ft_putstr_fd(s_invalid, fd_invalid);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	// Write a regular string to standard output
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_found, 12);
	write(fd_stdout, "\n", 1);

	// Write an empty string to standard output
	printf("[STRING]\t: \"%s\"\n", s_empty);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_empty, 0);
	write(fd_stdout, "\n", 1);

	// Write a string containing numbers to standard output
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_numbers, 9);
	write(fd_stdout, "\n", 1);

	// Write a string containing special characters to standard output
	printf("[STRING]\t: %s\n", s_special);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_special, 13);
	write(fd_stdout, "\n", 1);

	// Write a multiline string to standard output
	printf("[STRING]\t: %s\n", s_multiline);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t:\n");
	write(fd_stdout, s_multiline, 33);
	write(fd_stdout, "\n", 1);

	// Write a regular string to standard error
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	write(fd_stderr, s_found, 12);
	write(fd_stderr, "\n", 1);

	// Write a string to a file
	fd_file = open("putstr_fd_original.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[STRING]\t: %s\n", s_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: String written to putstr_fd_original.txt\n");
		write(fd_file, s_found, 12);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[STRING]\t: %s\n", s_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No string should be written\n");
	if (fd_invalid >= 0)
		write(fd_invalid, s_invalid, 26);

	return (0);
}
```

#### ft_putendl_fd

```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	printf("========================= PUTENDL_FD =========================\n");
	printf("Writes the string s followed by a newline to the file\n");
	printf("descriptor fd.\n");
	printf("==============================================================\n");

	char	*s_found = "Hello world!";
	char	*s_empty = "";
	char	*s_numbers = "123456789";
	char	*s_special = "Hello\tworld!";
	char	*s_multiline = "First line\nSecond line";
	char	*s_invalid = "This should not be written";

	int	fd_stdout = 1;
	int	fd_stderr = 2;
	int	fd_file;
	int	fd_invalid = -1;

	// Write a regular string followed by a newline
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_found, fd_stdout);

	// Write an empty string followed by a newline
	printf("[STRING]\t: \"%s\"\n", s_empty);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_empty, fd_stdout);

	// Write a string containing numbers followed by a newline
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_numbers, fd_stdout);

	// Write a string containing special characters followed by a newline
	printf("[STRING]\t: %s\n", s_special);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_special, fd_stdout);

	// Write a multiline string followed by a newline
	printf("[STRING]\t: %s\n", s_multiline);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_multiline, fd_stdout);

	// Write a regular string followed by a newline to standard error
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	ft_putendl_fd(s_found, fd_stderr);

	// Write a string followed by a newline to a file
	fd_file = open("putendl_fd_test.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[STRING]\t: %s\n", s_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: String written to putendl_fd_test.txt\n");
		ft_putendl_fd(s_found, fd_file);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[STRING]\t: %s\n", s_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No string should be written\n");
	ft_putendl_fd(s_invalid, fd_invalid);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	// Write a regular string followed by a newline
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_found, strlen(s_found));
	write(fd_stdout, "\n", 1);

	// Write an empty string followed by a newline
	printf("[STRING]\t: \"%s\"\n", s_empty);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_empty, strlen(s_empty));
	write(fd_stdout, "\n", 1);

	// Write a string containing numbers followed by a newline
	printf("[STRING]\t: %s\n", s_numbers);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_numbers, strlen(s_numbers));
	write(fd_stdout, "\n", 1);

	// Write a string containing special characters followed by a newline
	printf("[STRING]\t: %s\n", s_special);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_special, strlen(s_special));
	write(fd_stdout, "\n", 1);

	// Write a multiline string followed by a newline
	printf("[STRING]\t: %s\n", s_multiline);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	write(fd_stdout, s_multiline, strlen(s_multiline));
	write(fd_stdout, "\n", 1);

	// Write a regular string followed by a newline to standard error
	printf("[STRING]\t: %s\n", s_found);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	write(fd_stderr, s_found, strlen(s_found));
	write(fd_stderr, "\n", 1);

	// Write a string followed by a newline to a file
	fd_file = open("putendl_fd_original.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[STRING]\t: %s\n", s_found);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: String written to putendl_fd_original.txt\n");
		write(fd_file, s_found, strlen(s_found));
		write(fd_file, "\n", 1);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	printf("[STRING]\t: %s\n", s_invalid);
	printf("[FD]\t\t: %d\n", fd_invalid);
	printf("[RESULT]\t: No string should be written\n");
	if (fd_invalid >= 0)
	{
		write(fd_invalid, s_invalid, strlen(s_invalid));
		write(fd_invalid, "\n", 1);
	}

	return (0);
}
```

#### ft_putnbr_fd

```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	printf("========================= PUTNBR_FD ==========================\n");
	printf("Writes the integer n to the file descriptor fd.\n");
	printf("==============================================================\n");

	int	n_zero = 0;
	int	n_positive = 42;
	int	n_negative = -42;
	int	n_large_positive = 123456789;
	int	n_large_negative = -123456789;
	int	n_max = INT_MAX;
	int	n_min = INT_MIN;
	int	n_single_positive = 7;
	int	n_single_negative = -7;
	int	n_trailing_zeros = 100000;

	int	fd_stdout = 1;
	int	fd_stderr = 2;
	int	fd_file;
	int	fd_invalid = -1;

	// Write zero to standard output
	printf("[NUMBER]\t: %d\n", n_zero);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_zero, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_positive, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_negative, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a large positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_large_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_large_positive, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a large negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_large_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_large_negative, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write the maximum integer value to standard output
	printf("[NUMBER]\t: %d\n", n_max);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_max, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write the minimum integer value to standard output
	printf("[NUMBER]\t: %d\n", n_min);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_min, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a single-digit positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_single_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_single_positive, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a single-digit negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_single_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_single_negative, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write an integer containing trailing zeros to standard output
	printf("[NUMBER]\t: %d\n", n_trailing_zeros);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_trailing_zeros, fd_stdout);
	ft_putchar_fd('\n', fd_stdout);

	// Write a positive integer to standard error
	printf("[NUMBER]\t: %d\n", n_positive);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	ft_putnbr_fd(n_positive, fd_stderr);
	ft_putchar_fd('\n', fd_stderr);

	// Write an integer to a file
	fd_file = open("putnbr_fd_test.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		printf("[NUMBER]\t: %d\n", n_negative);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: Number written to putnbr_fd_test.txt\n");
		ft_putnbr_fd(n_negative, fd_file);
		ft_putchar_fd('\n', fd_file);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// Attempt to write using an invalid file descriptor
	// printf("[NUMBER]\t: %d\n", n_invalid = 123);
	// printf("[FD]\t\t: %d\n", fd_invalid);
	// printf("[RESULT]\t: No number should be written\n");
	// ft_putnbr_fd(n_invalid, fd_invalid);

	printf("========================== ORIGINAL ==========================\n");
	printf("==============================================================\n");

	// Write zero to standard output
	printf("[NUMBER]\t: %d\n", n_zero);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_zero);

	// Write a positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_positive);

	// Write a negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_negative);

	// Write a large positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_large_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_large_positive);

	// Write a large negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_large_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_large_negative);

	// Write the maximum integer value to standard output
	printf("[NUMBER]\t: %d\n", n_max);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_max);

	// Write the minimum integer value to standard output
	printf("[NUMBER]\t: %d\n", n_min);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_min);

	// Write a single-digit positive integer to standard output
	printf("[NUMBER]\t: %d\n", n_single_positive);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_single_positive);

	// Write a single-digit negative integer to standard output
	printf("[NUMBER]\t: %d\n", n_single_negative);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_single_negative);

	// Write an integer containing trailing zeros to standard output
	printf("[NUMBER]\t: %d\n", n_trailing_zeros);
	printf("[FD]\t\t: %d\n", fd_stdout);
	printf("[RESULT]\t: ");
	printf("%d\n", n_trailing_zeros);

	// Write a positive integer to standard error
	printf("[NUMBER]\t: %d\n", n_positive);
	printf("[FD]\t\t: %d\n", fd_stderr);
	printf("[RESULT]\t: ");
	fprintf(stderr, "%d\n", n_positive);

	// Write an integer to a file
	fd_file = open("putnbr_fd_original.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file != -1)
	{
		char	buffer[12];
		int		length;

		length = snprintf(buffer, sizeof(buffer), "%d\n", n_negative);
		printf("[NUMBER]\t: %d\n", n_negative);
		printf("[FD]\t\t: %d\n", fd_file);
		printf("[RESULT]\t: Number written to putnbr_fd_original.txt\n");
		write(fd_file, buffer, length);
		close(fd_file);
	}
	else
		printf("[ERROR]\t\t: Could not open file\n");

	// // Attempt to write using an invalid file descriptor
	// printf("[NUMBER]\t: %d\n", n_invalid);
	// printf("[FD]\t\t: %d\n", fd_invalid);
	// printf("[RESULT]\t: No number should be written\n");
	// if (fd_invalid >= 0)
	// 	dprintf(fd_invalid, "%d", n_invalid);

	return (0);
}
```

===============================

#### ft_lstnew

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	printf("=========================== LSTNEW ===========================\n");
	printf("Allocates and returns a new list element with the given content.\n");
	printf("==============================================================\n");

	char	*content_found = "Hello world";
	char	*content_empty = "";
	char	*content_numbers = "123456789";
	char	*content_null = NULL;

	t_list	*result_found;
	t_list	*result_empty;
	t_list	*result_numbers;
	t_list	*result_null;

	// Create a node with a regular string
	result_found = ft_lstnew(content_found);
	printf("[CONTENT]\t: %s\n", content_found);
	printf("[RESULT]\t: %s\n", (char *)result_found->content);
	printf("[NEXT]\t\t: %s\n",
		result_found->next == NULL ? "NULL" : "NOT NULL");
	free(result_found);

	// Create a node with an empty string
	result_empty = ft_lstnew(content_empty);
	printf("[CONTENT]\t: \"%s\"\n", content_empty);
	printf("[RESULT]\t: \"%s\"\n", (char *)result_empty->content);
	printf("[NEXT]\t\t: %s\n",
		result_empty->next == NULL ? "NULL" : "NOT NULL");
	free(result_empty);

	// Create a node with a numeric string
	result_numbers = ft_lstnew(content_numbers);
	printf("[CONTENT]\t: %s\n", content_numbers);
	printf("[RESULT]\t: %s\n", (char *)result_numbers->content);
	printf("[NEXT]\t\t: %s\n",
		result_numbers->next == NULL ? "NULL" : "NOT NULL");
	free(result_numbers);

	// Create a node with NULL content
	result_null = ft_lstnew(content_null);
	printf("[CONTENT]\t: NULL\n");
	printf("[RESULT]\t: %s\n",
		result_null->content == NULL ? "NULL" : "NOT NULL");
	printf("[NEXT]\t\t: %s\n",
		result_null->next == NULL ? "NULL" : "NOT NULL");
	free(result_null);

	return (0);
}
```

#### ft_lstadd_front

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\t\t  [%d] : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	printf("======================== LSTADD_FRONT ========================\n");
	printf("Adds a new node at the beginning of the list.\n");
	printf("==============================================================\n");

	t_list	*lst;
	t_list	*new_node;

	// Add a node to the front of a list
	lst = ft_lstnew("World");
	lst->next = ft_lstnew("!");
	new_node = ft_lstnew("Hello");
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstadd_front(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	// Add a node to the front of an empty list
	lst = NULL;
	new_node = ft_lstnew("First");
	ft_lstadd_front(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	// Add a node to the front of a list containing one node
	lst = ft_lstnew("Second");
	new_node = ft_lstnew("First");
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstadd_front(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	return (0);
}
```

#### ft_lstsize

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	printf("========================== LSTSIZE ===========================\n");
	printf("Returns the number of nodes in the list.\n");
	printf("==============================================================\n");

	t_list	*lst;
	t_list	*lst_single;
	t_list	*lst_multiple;

	// Calculate the size of an empty list
	lst = NULL;
	printf("[LIST]\t\t: Empty\n");
	printf("[RESULT]\t: %d\n", ft_lstsize(lst));

	// Calculate the size of a list with one node
	lst_single = ft_lstnew("Hello");
	printf("[LIST]\t\t: Single node\n");
	printf("[RESULT]\t: %d\n", ft_lstsize(lst_single));
	ft_lstclear(&lst_single, NULL);

	// Calculate the size of a list with multiple nodes
	lst_multiple = ft_lstnew("Hello");
	lst_multiple->next = ft_lstnew("world");
	lst_multiple->next->next = ft_lstnew("!");
	printf("[LIST]\t\t: Multiple nodes\n");
	printf("[RESULT]\t: %d\n", ft_lstsize(lst_multiple));
	ft_lstclear(&lst_multiple, NULL);

	// Calculate the size of a list containing five nodes
	lst = ft_lstnew("One");
	lst->next = ft_lstnew("Two");
	lst->next->next = ft_lstnew("Three");
	lst->next->next->next = ft_lstnew("Four");
	lst->next->next->next->next = ft_lstnew("Five");
	printf("[LIST]\t\t: Five nodes\n");
	printf("[RESULT]\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	return (0);
}
```

#### ft_lstlast

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	printf("========================== LSTLAST ===========================\n");
	printf("Returns the last node of the list.\n");
	printf("==============================================================\n");

	t_list	*lst;
	t_list	*result;

	// Find the last node of an empty list
	lst = NULL;
	result = ft_lstlast(lst);
	printf("[LIST]\t\t: Empty\n");
	printf("[RESULT]\t: %s\n",
		result == NULL ? "NULL" : (char *)result->content);

	// Find the last node of a list containing one node
	lst = ft_lstnew("Hello");
	result = ft_lstlast(lst);
	printf("[LIST]\t\t: Single node\n");
	printf("[RESULT]\t: %s\n", (char *)result->content);
	ft_lstclear(&lst, NULL);

	// Find the last node of a list containing multiple nodes
	lst = ft_lstnew("Hello");
	lst->next = ft_lstnew("world");
	lst->next->next = ft_lstnew("!");
	result = ft_lstlast(lst);
	printf("[LIST]\t\t: Multiple nodes\n");
	printf("[RESULT]\t: %s\n", (char *)result->content);
	ft_lstclear(&lst, NULL);

	// Find the last node of a list containing five nodes
	lst = ft_lstnew("One");
	lst->next = ft_lstnew("Two");
	lst->next->next = ft_lstnew("Three");
	lst->next->next->next = ft_lstnew("Four");
	lst->next->next->next->next = ft_lstnew("Five");
	result = ft_lstlast(lst);
	printf("[LIST]\t\t: Five nodes\n");
	printf("[RESULT]\t: %s\n", (char *)result->content);
	ft_lstclear(&lst, NULL);

	return (0);
}
```

#### ft_lstadd_back

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\t\t  [%d] : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	printf("======================== LSTADD_BACK =========================\n");
	printf("Adds a new node at the end of the list.\n");
	printf("==============================================================\n");

	t_list	*lst;
	t_list	*new_node;

	// Add a node to the back of a list
	lst = ft_lstnew("Hello");
	lst->next = ft_lstnew("world");
	new_node = ft_lstnew("!");
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstadd_back(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	// Add a node to the back of an empty list
	lst = NULL;
	new_node = ft_lstnew("First");
	ft_lstadd_back(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	// Add a node to the back of a list containing one node
	lst = ft_lstnew("First");
	new_node = ft_lstnew("Second");
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstadd_back(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	// Add a node to the back of a list containing multiple nodes
	lst = ft_lstnew("One");
	lst->next = ft_lstnew("Two");
	lst->next->next = ft_lstnew("Three");
	new_node = ft_lstnew("Four");
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstadd_back(&lst, new_node);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	printf("[SIZE]\t\t: %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, NULL);

	return (0);
}
```

#### ft_lstdelone

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	del_content(void *content)
{
	free(content);
}

static char	*duplicate_content(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	printf("========================= LSTDELONE ==========================\n");
	printf("Deletes one node using the given deletion function.\n");
	printf("==============================================================\n");

	t_list	*lst;
	char	*content;

	// Delete a node containing a regular string
	content = duplicate_content("Hello");
	if (!content)
		return (1);
	lst = ft_lstnew(content);
	if (!lst)
	{
		free(content);
		return (1);
	}
	printf("[CONTENT]\t: %s\n", (char *)lst->content);
	printf("[RESULT]\t: Deleting node\n");
	ft_lstdelone(lst, del_content);

	// Delete a node containing a numeric string
	content = duplicate_content("12345");
	if (!content)
		return (1);
	lst = ft_lstnew(content);
	if (!lst)
	{
		free(content);
		return (1);
	}
	printf("[CONTENT]\t: %s\n", (char *)lst->content);
	printf("[RESULT]\t: Deleting node\n");
	ft_lstdelone(lst, del_content);

	// Delete a node containing an empty string
	content = duplicate_content("");
	if (!content)
		return (1);
	lst = ft_lstnew(content);
	if (!lst)
	{
		free(content);
		return (1);
	}
	printf("[CONTENT]\t: \"%s\"\n", (char *)lst->content);
	printf("[RESULT]\t: Deleting node\n");
	ft_lstdelone(lst, del_content);

	// Delete a node with NULL content
	lst = ft_lstnew(NULL);
	if (!lst)
		return (1);
	printf("[CONTENT]\t: NULL\n");
	printf("[RESULT]\t: Deleting node\n");
	ft_lstdelone(lst, NULL);

	return (0);
}
```

#### ft_lstclear

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	del_content(void *content)
{
	free(content);
}

static char	*duplicate_content(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\t\t  [%d] : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	printf("========================= LSTCLEAR ===========================\n");
	printf("Deletes and frees all nodes in the list, then sets the head\n");
	printf("pointer to NULL.\n");
	printf("==============================================================\n");

	t_list	*lst;

	// Clear a list containing multiple nodes
	lst = ft_lstnew(duplicate_content("Hello"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("world"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next = ft_lstnew(duplicate_content("!"));
	if (!lst->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstclear(&lst, del_content);
	printf("[RESULT]\t: %s\n", lst == NULL ? "NULL" : "NOT NULL");

	// Clear an empty list
	lst = NULL;
	printf("[LIST]\t\t: Empty\n");
	ft_lstclear(&lst, del_content);
	printf("[RESULT]\t: %s\n", lst == NULL ? "NULL" : "NOT NULL");

	// Clear a list containing a single node
	lst = ft_lstnew(duplicate_content("Single"));
	if (!lst)
		return (1);
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstclear(&lst, del_content);
	printf("[RESULT]\t: %s\n", lst == NULL ? "NULL" : "NOT NULL");

	// Clear a list containing five nodes
	lst = ft_lstnew(duplicate_content("One"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("Two"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next = ft_lstnew(duplicate_content("Three"));
	if (!lst->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next->next = ft_lstnew(duplicate_content("Four"));
	if (!lst->next->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next->next->next = ft_lstnew(duplicate_content("Five"));
	if (!lst->next->next->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstclear(&lst, del_content);
	printf("[RESULT]\t: %s\n", lst == NULL ? "NULL" : "NOT NULL");

	return (0);
}
```

#### ft_lstiter

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	uppercase_content(void *content)
{
	int		i;
	char	*str;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

static void	del_content(void *content)
{
	free(content);
}

static char	*duplicate_content(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\t\t  [%d] : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	printf("========================== LSTITER ===========================\n");
	printf("Applies the function f to the content of every node.\n");
	printf("==============================================================\n");

	t_list	*lst;

	// Apply uppercase transformation to every node
	lst = ft_lstnew(duplicate_content("hello"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("world"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next = ft_lstnew(duplicate_content("libft"));
	if (!lst->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstiter(lst, uppercase_content);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	ft_lstclear(&lst, del_content);

	// Apply uppercase transformation to a list with mixed case
	lst = ft_lstnew(duplicate_content("Hello"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("WoRlD"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Before\n");
	print_list(lst);
	ft_lstiter(lst, uppercase_content);
	printf("[LIST]\t\t: After\n");
	print_list(lst);
	ft_lstclear(&lst, del_content);

	// Apply the function to an empty list
	lst = NULL;
	printf("[LIST]\t\t: Empty\n");
	ft_lstiter(lst, uppercase_content);
	printf("[RESULT]\t: No nodes processed\n");

	return (0);
}
```

#### ft_lstmap

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	*uppercase_content(void *content)
{
	size_t	i;
	char	*str;
	char	*copy;

	str = (char *)content;
	i = 0;
	while (str[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			copy[i] = str[i] - 32;
		else
			copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	del_content(void *content)
{
	free(content);
}

static char	*duplicate_content(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("\t\t  [%d] : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	printf("=========================== LSTMAP ===========================\n");
	printf("Creates a new list by applying the function f to each node's\n");
	printf("content. The function del frees content if an error occurs.\n");
	printf("==============================================================\n");

	t_list	*lst;
	t_list	*result;

	// Map a list containing multiple strings
	lst = ft_lstnew(duplicate_content("hello"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("world"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	lst->next->next = ft_lstnew(duplicate_content("libft"));
	if (!lst->next->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Original\n");
	print_list(lst);
	result = ft_lstmap(lst, uppercase_content, del_content);
	printf("[LIST]\t\t: Mapped\n");
	print_list(result);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&result, del_content);

	// Map a list containing mixed-case strings
	lst = ft_lstnew(duplicate_content("Hello"));
	if (!lst)
		return (1);
	lst->next = ft_lstnew(duplicate_content("WoRlD"));
	if (!lst->next)
	{
		ft_lstclear(&lst, del_content);
		return (1);
	}
	printf("[LIST]\t\t: Original\n");
	print_list(lst);
	result = ft_lstmap(lst, uppercase_content, del_content);
	printf("[LIST]\t\t: Mapped\n");
	print_list(result);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&result, del_content);

	// Map an empty list
	lst = NULL;
	result = ft_lstmap(lst, uppercase_content, del_content);
	printf("[LIST]\t\t: Empty\n");
	printf("[RESULT]\t: %s\n",
		result == NULL ? "NULL" : "NOT NULL");
	ft_lstclear(&result, del_content);

	return (0);
}
```


## Resources

This section enumerates the references for the project as well as a description of AI use, specifying on which tasks and sections of the projects it has been used.

### AI use

AI has been used to review errors when testing limit cases, to redact this README, and to create the mains that test the functions of the second and third part.

### Libraries used

#### <stdlib.h>

This library is used for all memory allocation functions, such as **malloc**, **free** and *size_t*.

#### <unistd.h>

This library is used for the function **write**.

### Libraries used for testing

#### <stdio.h>

This library is used for the **printf** function, to print out the outputs and additional text formating for testing.

#### <ctype.h>

This library is used to test the functions **isalnum**, **isalpha**, **isdigit**, **isprint**, **isascii** and **toupper**.

#### <string.h>

This library is used to test the functions **strlen**, **memset**, **memcpy**, **strchr**, **strrchr**, **strrchr**, **memchr** and **memcmp**.

#### <strings.h>

This library is used to test the function **bzero**.

#### <fcntl.h>

This library is used to test the file descriptor functions.