# ft_strjoin_free Documentation

### Function Prototype
```c
char *ft_strjoin_free(char *s1, const char *s2);
```

---

### Description
`ft_strjoin_free` concatenates two strings into a new dynamically allocated string.
It automatically frees the first string `s1` to manage memory efficiently, preventing leaks during string accumulation.

---

### Parameters
* `char *s1`: The first string (will be freed after concatenation).
* `const char *s2`: The second string to append.

---

### Return Value
Returns a pointer to the newly allocated concatenated string.
Returns `NULL` if memory allocation fails (also frees `s1` in this case).
Returns `s1` unchanged if `s2` is `NULL`.
Returns a duplicate of `s2` if `s1` is `NULL`.

---

### Details
The function calculates the combined length of both strings.
Memory is allocated for the concatenated result including the null terminator.
Characters from `s1` are copied first, followed by characters from `s2`.
The original `s1` is freed before returning the new string.
This implementation prevents memory leaks during iterative concatenation operations.

---

### Example Usage
```c
#include "get_next_line.h"

char *s1 = ft_strdup("Hello, ");
const char *s2 = "world!";
char *result = ft_strjoin_free(s1, s2);

// result points to "Hello, world!"
// s1 has been freed automatically

free(result);
```

---
