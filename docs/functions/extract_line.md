# extract_line Documentation

### Function Prototype
```c
static char *extract_line(char **backup);
```

---

### Description
`extract_line` extracts a single complete line from the backup buffer, including the newline character.
It updates the backup to contain only the remaining content after the extracted line, preparing it for subsequent calls.

---

### Parameters
* `char **backup`: Pointer to the backup buffer containing accumulated text from previous reads.

---

### Return Value
Returns a pointer to the newly allocated string containing the extracted line (including `\n`).
Returns `NULL` if no newline character is found in the backup or if memory allocation fails.

---

### Details
The function searches for the first newline character using `ft_strchr()`.
If no newline is found, it returns `NULL` immediately.
The line length includes the newline character itself.
After extracting the line, the function creates a new backup containing only the remaining content.
The old backup is freed to prevent memory leaks.

---

### Example Usage
```c
#include "get_next_line.h"

char *backup = ft_strdup("Hello\nWorld\n");
char *line = extract_line(&backup);

// line now points to "Hello\n"
// backup now contains "World\n"

free(line);
free(backup);
```

---
