# return_remaining_content Documentation

### Function Prototype
```c
static char *return_remaining_content(char **backup);
```

---

### Description
`return_remaining_content` returns any remaining data stored in the backup buffer when end-of-file is reached and no more data can be read.
It ensures proper memory management by duplicating the content and freeing the original backup.

---

### Parameters
* `char **backup`: Pointer to the backup buffer containing remaining content.

---

### Return Value
Returns a pointer to a newly allocated string containing the remaining content.
Returns `NULL` if the backup is empty, invalid, or memory allocation fails.

---

### Details
The function checks if the backup is `NULL` or contains an empty string.
If the backup is empty or invalid, it frees the backup and returns `NULL`.
If content exists, it duplicates the backup using `ft_strdup()` to create an independent copy.
The original backup is freed and set to `NULL` to prevent memory leaks.
This implementation ensures the last portion of a file is returned safely, even without a trailing newline.

---

### Example Usage
```c
#include "get_next_line.h"

char *backup = ft_strdup("Last line without newline");
char *line = return_remaining_content(&backup);

// line now contains "Last line without newline"
// backup has been freed and set to NULL

free(line);
```

---
