# get_next_line Documentation

### Function Prototype
```c
char *get_next_line(int fd);
```

---

### Description
`get_next_line` reads and returns the next line from a file descriptor each time it is called.
It uses a static backup buffer to preserve leftover data between calls, enabling incremental line-by-line reading with efficient memory management.

---

### Parameters
* `int fd`: The file descriptor to read from.

---

### Return Value
Returns a pointer to the next line, including the newline character if present.
Returns `NULL` if end-of-file is reached, an error occurs, or if `fd` or `BUFFER_SIZE` is invalid.

---

### Details
The function validates that `fd` is non-negative and `BUFFER_SIZE` is positive.
It initializes the backup buffer using `initialize_backup()` on the first call.
The function reads data incrementally using `read_buffer()` until a complete line is found.
When a newline is detected, `extract_line()` extracts and returns the line.
At end-of-file, `return_remaining_content()` returns any remaining data.
The static backup preserves state between successive calls to the function.
This implementation handles errors by freeing allocated memory and returning `NULL`.

---

### Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}

close(fd);
```

---
