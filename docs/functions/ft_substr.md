# ft_substr Documentation

### Function Prototype
```c
char *ft_substr(const char *s, unsigned int start, size_t len);
```

---

### Description
`ft_substr` creates a new string containing a substring of `s`, starting at index `start` and with maximum length `len`.
The substring is allocated dynamically and properly null-terminated.

---

### Parameters
* `const char *s`: The original string from which to extract the substring.
* `unsigned int start`: The starting index of the substring within `s`.
* `size_t len`: The maximum length of the substring to extract.

---

### Return Value
Returns a pointer to the newly allocated substring.
Returns `NULL` if `s` is invalid or if memory allocation fails.
Returns an empty string `""` if `start` is beyond the end of `s`.

---

### Details
The function calculates the length of `s` using `ft_strlen()`.
If `start` exceeds the string length, an empty string is returned.
The extraction length is adjusted if it would exceed the remaining characters after `start`.
Memory is allocated for the substring including space for the null terminator.
Characters are copied from the specified starting position for the given length.
This implementation ensures safe boundary handling and proper null termination.

---

### Example Usage
```c
#include "get_next_line.h"
#include <stdio.h>

const char *text = "Hello, world!";
char *sub = ft_substr(text, 7, 5);

printf("Substring: %s\n", sub);  // Output: Substring: world

free(sub);
```

---
