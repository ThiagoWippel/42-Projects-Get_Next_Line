# initialize_backup Documentation

### Function Prototype
```c
static char *initialize_backup(char **backup);
```

---

### Description
`initialize_backup` ensures that the backup buffer is properly initialized before reading from the file descriptor.
If no backup exists, it creates an empty string. It also attempts to extract a line immediately if the backup already contains data with a newline character.

---

### Parameters
* `char **backup`: Pointer to the backup buffer.

---

### Return Value
Returns a pointer to the extracted line if one exists in the backup.
Returns `NULL` if memory allocation fails or no complete line is present.

---

### Details
The function checks if the backup pointer is `NULL` and allocates an empty string if needed.
It uses `ft_strdup("")` to create a valid empty backup buffer.
After initialization, it calls `extract_line()` to check for an existing complete line.
This approach allows immediate return of a line without reading from the file descriptor if possible.
This implementation ensures the backup is always in a valid state before further operations.

---

### Example Usage
```c
#include "get_next_line.h"

char *backup = NULL;
char *line = initialize_backup(&backup);

// line is NULL because backup is initially empty
// backup now points to an empty string ""

free(backup);
```

---
