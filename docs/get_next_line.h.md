# get_next_line.h Documentation

---

### File Overview
`get_next_line.h` is the header file that defines the interface for the `get_next_line()` project.
It provides function prototypes, necessary system includes, and configurable macros, ensuring consistent definitions across all source files.

---

### Purpose
This header file establishes the public interface for the `get_next_line()` function and its utility functions.
It centralizes declarations, enables compile-time configuration, and ensures type safety throughout the project.

---

### Header Guards

```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
...
#endif
```

Prevents multiple inclusion of the header file, avoiding redefinition errors during compilation.
The guard uses the convention `GET_NEXT_LINE_H` to uniquely identify this header.

---

### System Includes

```c
# include <unistd.h>
# include <stdlib.h>
```

**unistd.h:**
Provides access to POSIX operating system API, including the `read()` system call.
Essential for low-level file I/O operations.

**stdlib.h:**
Provides standard library functions for dynamic memory management.
Includes `malloc()` and `free()` used throughout the implementation.

---

### Macro Definitions

```c
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
```

**BUFFER_SIZE:**
Defines the number of bytes read from the file descriptor in each `read()` call.
Can be overridden at compile time using the `-D BUFFER_SIZE=N` flag.
Defaults to 42 if not specified, providing a balanced starting point for most use cases.

**Conditional Definition:**
The `#ifndef` guard allows external definition while providing a safe default value.
This design enables easy testing with different buffer sizes without modifying source code.

---

### Function Prototypes

**Main Function:**
```c
char *get_next_line(int fd);
```
Reads and returns the next line from the given file descriptor.

**Utility Functions:**
```c
size_t ft_strlen(const char *s);
```
Calculates the length of a string.

```c
char *ft_strchr(const char *s, int c);
```
Locates the first occurrence of a character in a string.

```c
char *ft_strdup(const char *s);
```
Creates a duplicate of a string in dynamically allocated memory.

```c
char *ft_substr(const char *s, unsigned int start, size_t len);
```
Extracts a substring from a string.

```c
char *ft_strjoin_free(char *s1, const char *s2);
```
Concatenates two strings, freeing the first one automatically.

---

### Interface Design

**Modularity:**
All function declarations are centralized in one header file.
Source files include this header to access the complete interface.

**Type Safety:**
Function prototypes enable compile-time type checking.
Prevents mismatched function calls and parameter types.

**Maintainability:**
Changes to function signatures require modification in only one location.
Ensures consistency across all implementation files.

---

### Compilation Usage

**Default compilation:**
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```
Uses the default `BUFFER_SIZE` of 42.

**Custom buffer size:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
```
Overrides the default buffer size to 1 byte per read.

**Multiple buffer sizes for testing:**
```bash
cc -D BUFFER_SIZE=1 ...     # Minimal buffer
cc -D BUFFER_SIZE=42 ...    # Default buffer
cc -D BUFFER_SIZE=10000 ... # Large buffer
```

---

### Relationship with Source Files

**get_next_line.c:**
Includes this header to access all function declarations.
Implements the main `get_next_line()` function and static helpers.

**get_next_line_utils.c:**
Includes this header to ensure consistent utility function signatures.
Implements all helper functions (`ft_strlen`, `ft_strchr`, etc.).

**External usage:**
Any program using `get_next_line()` must include this header.
Provides all necessary declarations for proper compilation and linking.

---

### Design Principles

**Single Responsibility:**
This header focuses solely on declaring the interface, not implementation.

**Configuration Flexibility:**
`BUFFER_SIZE` can be adjusted without modifying source code.

**Dependency Management:**
All necessary system headers are included here, not scattered across source files.

**API Stability:**
The interface remains consistent regardless of internal implementation changes.

---

### Conclusion

The `get_next_line.h` header file provides a clean, organized interface for the entire project.
It ensures modularity, type safety, and compile-time configurability while maintaining clear separation between interface and implementation.

---
