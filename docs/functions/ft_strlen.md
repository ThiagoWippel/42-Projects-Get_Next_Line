# ft_strlen Documentation

### Function Prototype
```c
size_t ft_strlen(const char *s);
```

---

### Description
`ft_strlen` calculates the length of the string `s`, excluding the null terminator.
It counts characters from the beginning of the string until the null terminator `\0` is reached.

---

### Parameters
* `const char *s`: The null-terminated string whose length is to be calculated.

---

### Return Value
Returns the number of characters in the string (excluding the null terminator).
Returns `0` if `s` is `NULL`.

---

### Details
The function validates that `s` is not `NULL` before processing.
It iterates through each character, incrementing a counter until `\0` is encountered.
This implementation provides safe handling of invalid input.
The function does not modify the original string.

---

### Example Usage
```c
#include "get_next_line.h"
#include <stdio.h>

const char *text = "Hello, world!";
size_t length = ft_strlen(text);

printf("Length: %zu\n", length);  // Output: Length: 13
```

---
