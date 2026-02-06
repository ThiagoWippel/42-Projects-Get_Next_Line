# get_next_line.c Documentation

---

### File Overview
`get_next_line.c` implements the core functionality for reading lines incrementally from a file descriptor.
It uses a static backup buffer to preserve unread content between calls, reads data in chunks of `BUFFER_SIZE`, and returns one complete line per invocation.

---

### Purpose
This file provides a complete implementation of the `get_next_line()` function, enabling efficient line-by-line reading from any file descriptor without loading the entire file into memory.

---

### Core Components

**1. Static Functions:**
* `extract_line()` - Extracts a complete line from the backup buffer
* `read_buffer()` - Reads `BUFFER_SIZE` bytes from the file descriptor
* `initialize_backup()` - Ensures the backup buffer is properly initialized
* `return_remaining_content()` - Handles remaining content at end-of-file

**2. Main Function:**
* `get_next_line()` - Orchestrates the reading process and returns one line per call

**3. Static Variable:**
* `backup` - Persists unread content across multiple function calls

---

### Function Responsibilities

#### extract_line()
Locates the first newline character in the backup and separates it from the remaining content.
Updates the backup to contain only the content after the extracted line.

#### read_buffer()
Reads up to `BUFFER_SIZE` bytes from the file descriptor into a temporary buffer.
Appends the new content to the existing backup using dynamic concatenation.

#### initialize_backup()
Ensures the backup buffer exists before any reading operation.
Attempts to extract a line immediately if the backup already contains a newline.

#### return_remaining_content()
Returns any remaining content in the backup when end-of-file is reached.
Properly frees the backup and returns `NULL` if empty.

#### get_next_line()
Validates input parameters (`fd` and `BUFFER_SIZE`).
Manages the reading loop and coordinates all helper functions.
Ensures proper memory management and error handling throughout the process.

---

### Main Flow

1. **Input Validation:**
   Checks if `fd` is valid (non-negative) and `BUFFER_SIZE` is positive.

2. **Backup Initialization:**
   Calls `initialize_backup()` to ensure the backup exists and extract any available line.

3. **Reading Loop:**
   * Reads new data using `read_buffer()` in chunks of `BUFFER_SIZE`
   * On read error: frees backup and returns `NULL`
   * On EOF: calls `return_remaining_content()` to return leftover content
   * Attempts line extraction using `extract_line()`
   * Returns line if found, otherwise continues reading

4. **Memory Management:**
   All dynamic allocations are verified and freed appropriately.
   The backup is preserved between calls for continuous reading.

---

### Error Handling

**Invalid Parameters:**
Returns `NULL` if `fd` is negative or `BUFFER_SIZE` is non-positive.

**Memory Allocation Failures:**
Returns `NULL` and frees allocated memory when allocation fails.

**Read Errors:**
Frees the backup and returns `NULL` when `read()` encounters an error.

**End-of-File:**
Returns remaining content if any exists, otherwise returns `NULL` and frees the backup.

---

### Design Principles

**Incremental Reading:**
Reads data in fixed-size chunks instead of loading entire files.

**Static Persistence:**
Uses a static variable to maintain state across multiple calls.

**Modular Design:**
Separates concerns into specialized helper functions for clarity.

**Safe Memory Management:**
Validates all allocations and properly frees memory on errors or completion.

**Edge Case Handling:**
Handles empty files, files without trailing newlines, and various buffer sizes.

---

### Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

**Result:** Each iteration prints one complete line from `example.txt`, reading incrementally and managing memory safely.

---

### Technical Details

**Buffer Size Impact:**
* Small `BUFFER_SIZE` (1-10): More system calls, slower but minimal memory
* Medium `BUFFER_SIZE` (42-1024): Balanced performance
* Large `BUFFER_SIZE` (10000+): Fewer system calls, faster but more memory

**Newline Handling:**
Lines include the terminating `\n` character when present.
The last line may not have a trailing newline if the file doesn't end with one.

**Multiple File Descriptors:**
Each static backup is independent per file descriptor in the bonus implementation.
The mandatory version uses a single static backup for one file descriptor at a time.

---

### Conclusion

The `get_next_line.c` file demonstrates a robust, efficient approach to line-by-line file reading in C.
It emphasizes incremental processing, safe memory management, comprehensive error handling, and clear separation of concerns through modular helper functions.

---
