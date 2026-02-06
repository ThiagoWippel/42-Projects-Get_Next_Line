# read_buffer Documentation

### Function Prototype
```c
static int read_buffer(int fd, char **backup);
```

---

### Description
`read_buffer` reads data from a file descriptor into a temporary buffer and appends it to the backup buffer.
It handles dynamic memory allocation safely and ensures the backup grows incrementally as new content is read from the file.

---

### Parameters
* `int fd`: The file descriptor to read from.
* `char **backup`: Pointer to the backup buffer that accumulates data.

---

### Return Value
Returns the number of bytes read if successful (positive value).
Returns `0` if end-of-file is reached.
Returns `-1` if an error occurs (memory allocation failure or read error).

---

### Details
The function allocates a temporary buffer of size `BUFFER_SIZE + 1`.
It reads up to `BUFFER_SIZE` bytes from the file descriptor using the `read()` system call.
The temporary buffer is null-terminated after reading.
The content is appended to the backup using `ft_strjoin_free()`, which also frees the old backup.
The temporary buffer is freed before returning.
This implementation ensures efficient memory management during incremental reading.

---

### Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>

char *backup = ft_strdup("");
int fd = open("file.txt", O_RDONLY);
int bytes = read_buffer(fd, &backup);

// backup now contains the first BUFFER_SIZE bytes from the file

close(fd);
free(backup);
```

---
