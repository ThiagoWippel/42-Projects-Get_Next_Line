# ft_strchr Documentation

### Function Prototype
```c
char *ft_strchr(const char *s, int c);
```

---

### Description
`ft_strchr` locates the first occurrence of character `c` in the string `s`.
It returns a pointer to the matched character or `NULL` if the character is not found.

---

### Parameters
* `const char *s`: The string to search through.
* `int c`: The character to locate (interpreted as `unsigned char`).

---

### Return Value
Returns a pointer to the first occurrence of character `c` in string `s`.
Returns a pointer to the null terminator if `c` is `'\0'`.
Returns `NULL` if the character is not found or if `s` is `NULL`.

---

### Details
The function validates that `s` is not `NULL` before searching.
It traverses the string character by character until a match is found.
The null terminator `\0` is considered part of the string for matching purposes.
This implementation provides safe handling of invalid input.

---

### Example Usage
```c
#include "get_next_line.h"

const char *text = "Hello\nWorld";
char *newline_pos = ft_strchr(text, '\n');

// newline_pos points to the '\n' in "Hello\nWorld"
```

---
