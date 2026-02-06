# get_next_line_utils.c Documentation

---

### File Overview
`get_next_line_utils.c` provides a collection of utility functions for string manipulation and memory management.
These helper functions support the core functionality of `get_next_line()` by handling common string operations safely and efficiently.

---

### Purpose
This file centralizes all auxiliary string functions required by `get_next_line()`, ensuring the main logic remains clean and modular.
Each function is designed with safety in mind, handling edge cases and null inputs gracefully.

---

### Implemented Functions

**1. ft_strlen()**
Calculates the length of a string, excluding the null terminator.
Returns `0` if the input is `NULL`.

**2. ft_strchr()**
Locates the first occurrence of a character in a string.
Returns a pointer to the character or `NULL` if not found.

**3. ft_strdup()**
Creates a dynamically allocated duplicate of a string.
Returns `NULL` if the input is invalid or allocation fails.

**4. ft_substr()**
Extracts a substring from a given string starting at a specific index.
Handles boundary conditions and adjusts length if necessary.

**5. ft_strjoin_free()**
Concatenates two strings into a new allocation.
Automatically frees the first string to prevent memory leaks.

---

### Function Responsibilities

#### ft_strlen()
**Purpose:** Safe string length calculation
**Input validation:** Returns `0` for `NULL` input
**Process:** Iterates through characters until null terminator
**Usage in GNL:** Calculates lengths for memory allocation in other utility functions

#### ft_strchr()
**Purpose:** Character location in strings
**Input validation:** Returns `NULL` for `NULL` input
**Process:** Traverses string comparing each character with target
**Special case:** Returns pointer to null terminator when searching for `'\0'`
**Usage in GNL:** Locates newline characters in `extract_line()`

#### ft_strdup()
**Purpose:** String duplication with dynamic allocation
**Input validation:** Returns `NULL` for `NULL` input
**Memory management:** Allocates exact size needed plus null terminator
**Process:** Copies all characters and null-terminates the result
**Usage in GNL:** Initializes backup buffer and handles remaining content at EOF

#### ft_substr()
**Purpose:** Substring extraction with boundary checking
**Input validation:** Returns `NULL` for `NULL` input
**Boundary handling:** Returns empty string if start index exceeds string length
**Length adjustment:** Prevents reading beyond string bounds
**Process:** Allocates memory, copies specified portion, null-terminates
**Usage in GNL:** Extracts lines from backup and updates remaining content

#### ft_strjoin_free()
**Purpose:** String concatenation with automatic memory management
**Input validation:** Handles `NULL` inputs gracefully
**Special cases:**
- Returns `s1` if `s2` is `NULL`
- Returns duplicate of `s2` if `s1` is `NULL`
**Memory management:** Frees `s1` before returning (even on allocation failure)
**Process:** Allocates combined size, copies both strings, null-terminates
**Usage in GNL:** Appends newly read buffer to backup in `read_buffer()`

---

### Safety Features

**Null Pointer Handling:**
All functions validate inputs and return safe values for `NULL` pointers.

**Memory Allocation Checks:**
Functions verify successful allocation before proceeding.
Failed allocations return `NULL` and free previously allocated memory when appropriate.

**Boundary Validation:**
`ft_substr()` prevents buffer overruns by checking start position and adjusting length.

**Proper Null Termination:**
All returned strings are guaranteed to be null-terminated.

**Automatic Memory Management:**
`ft_strjoin_free()` automatically frees the first parameter, simplifying memory management.

---

### Memory Management Strategy

**Allocation Pattern:**
Each function allocates exactly the memory needed plus one byte for null terminator.

**Deallocation Responsibility:**
- `ft_strjoin_free()` frees its first parameter automatically
- Other functions return allocated memory that must be freed by caller
- On allocation failure, functions free any already-allocated memory

**Leak Prevention:**
The automatic freeing in `ft_strjoin_free()` prevents accumulation of temporary buffers.

---

### Integration with get_next_line()

**String Length Calculation:**
`ft_strlen()` is used throughout for determining allocation sizes.

**Newline Detection:**
`ft_strchr()` is critical in `extract_line()` for finding line boundaries.

**Buffer Initialization:**
`ft_strdup()` creates the initial empty backup buffer.

**Line Extraction:**
`ft_substr()` separates extracted lines from remaining content.

**Buffer Accumulation:**
`ft_strjoin_free()` incrementally builds the backup as data is read.

---

### Example Usage Flow

```c
// Initialize backup
char *backup = ft_strdup("");

// Read and append data
char buffer[BUFFER_SIZE + 1];
read(fd, buffer, BUFFER_SIZE);
backup = ft_strjoin_free(backup, buffer);

// Find newline
char *newline_pos = ft_strchr(backup, '\n');
if (newline_pos)
{
    size_t line_len = newline_pos - backup + 1;
    
    // Extract line
    char *line = ft_substr(backup, 0, line_len);
    
    // Update backup with remaining content
    char *temp = ft_substr(backup, line_len, ft_strlen(backup) - line_len);
    free(backup);
    backup = temp;
    
    // Return extracted line
    return line;
}
```

---

### Design Principles

**Modularity:**
Each function has a single, well-defined purpose.

**Reusability:**
Functions are general-purpose and can be used in other contexts.

**Safety First:**
Extensive validation prevents undefined behavior and crashes.

**Efficiency:**
Functions allocate only necessary memory and minimize copying.

**Consistency:**
All functions follow the same patterns for validation and return values.

---

### Conclusion

The `get_next_line_utils.c` file provides a robust foundation of string utilities that enable safe and efficient implementation of `get_next_line()`.
Through careful input validation, proper memory management, and clear separation of concerns, these utilities ensure reliable operation while maintaining code clarity and maintainability.

---
