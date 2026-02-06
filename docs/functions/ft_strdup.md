# ft_strdup Documentation

### Function Prototype
```c
char *ft_strdup(const char *s);
```

---

### Description
`ft_strdup` creates a new copy of the string `s` in dynamically allocated memory.
The duplicate is an independent copy with its own memory space, complete with a null terminator.

---

### Parameters
* `const char *s`: The null-terminated string to duplicate.

---

### Return Value
Returns a pointer to the newly allocated duplicate string.
Returns `NULL` if `s` is invalid or if memory allocation fails.

---

### Details
The function calculates the length of the source string using `ft_strlen()`.
Memory is allocated to accommodate all characters plus the null terminator.
Each character is copied individually from the source to the duplicate.
The duplicate is properly null-terminated.
This implementation ensures the new string is completely independent of the original.

---

### Example Usage
```c
#include "get_next_line.h"
#include <stdio.h>

char *original = "Hello, world!";
char *copy = ft_strdup(original);

printf("Copy: %s\n", copy);

free(copy);
```

---
