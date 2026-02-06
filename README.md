*This project was created as part of the 42 curriculum by twippel-.*

# Get Next Line

## Description

Get Next Line (GNL) is a project that implements a function to read lines from a file descriptor, one at a time. This seemingly simple task introduces the concept of **static variables** in C and challenges you to manage memory efficiently while dealing with variable buffer sizes.

The function returns one line per call, handling any buffer size and maintaining reading state between calls. This makes it an essential utility for file I/O operations and a foundational building block for future 42 projects.

## Algorithm Explanation

The implementation uses a **static variable** to preserve data between function calls, allowing the function to "remember" leftover content from previous reads.

### Core Strategy

1. **Buffered Reading**: Read chunks of `BUFFER_SIZE` bytes at a time (instead of byte-by-byte)
2. **Static Backup**: Store unprocessed content in a static variable that persists between calls
3. **Line Extraction**: Search for newline characters (`\n`) and return complete lines
4. **Remainder Management**: Keep any leftover content after a newline for the next call

### Step-by-Step Process

```
┌─────────────────────────────────────────────────────────────┐
│ Call get_next_line(fd)                                      │
└─────────────────────────────────────────────────────────────┘
                            │
                            ▼
┌─────────────────────────────────────────────────────────────┐
│ Check if backup already contains a complete line            │
│ (i.e., has '\n' character)                                  │
└─────────────────────────────────────────────────────────────┘
                            │
                 ┌──────────┴──────────┐
                 │                     │
            Yes  │                     │  No
                 ▼                     ▼
    ┌─────────────────────┐   ┌──────────────────────┐
    │ Extract line up to  │   │ Read BUFFER_SIZE     │
    │ and including '\n'  │   │ bytes from fd        │
    └─────────────────────┘   └──────────────────────┘
                 │                     │
                 │                     ▼
                 │            ┌──────────────────────┐
                 │            │ Append to backup     │
                 │            └──────────────────────┘
                 │                     │
                 │                     ▼
                 │            ┌──────────────────────┐
                 │            │ Repeat until '\n'    │
                 │            │ found or EOF reached │
                 │            └──────────────────────┘
                 │                     │
                 └─────────┬───────────┘
                           ▼
                ┌─────────────────────┐
                │ Return the line     │
                └─────────────────────┘
```

### Why This Approach?

- **Memory Efficient**: Only allocates what's needed
- **Flexible**: Works with any buffer size (1 to 10,000,000+)
- **Persistent State**: Static variable maintains context between calls
- **Edge Case Handling**: Properly manages EOF, empty lines, and files without trailing newlines

### Key Implementation Details

The implementation is split across several helper functions:

- `read_buffer()`: Reads `BUFFER_SIZE` bytes and appends to backup
- `extract_line()`: Finds `\n` in backup and extracts the complete line
- `return_remaining_content()`: Handles the last line when EOF is reached
- `initialize_backup()`: Sets up the static variable on first call

### Buffer Size Impact

The `BUFFER_SIZE` defines how many bytes are read from the file descriptor in each `read()` call:

- **Small buffer (1-10)**: More system calls, slower but minimal memory
- **Medium buffer (42-1024)**: Balanced performance
- **Large buffer (10000+)**: Fewer system calls, faster but more memory usage

The function works correctly regardless of buffer size, even with edge cases like `BUFFER_SIZE=1` or `BUFFER_SIZE=10000000`.

## Instructions

### Compilation

The project must be compiled with a defined `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can test with different buffer sizes:

```bash
# Small buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Large buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c
```

### Usage

Include the header in your program:

```c
#include "get_next_line.h"
```

Example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

Reading from standard input:

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    printf("Enter text (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }
    return (0);
}
```

## Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: File descriptor to read from

**Return Value:**
- The line read, including the terminating `\n` (if present)
- `NULL` if there's nothing left to read or an error occurred

**Helper Functions:**

All helper functions are implemented in `get_next_line_utils.c`:

| Function | Description |
|----------|-------------|
| `ft_strlen` | Calculates string length |
| `ft_strchr` | Locates character in string |
| `ft_strdup` | Duplicates a string |
| `ft_substr` | Extracts substring |
| `ft_strjoin_free` | Joins two strings and frees the first |

## Project Structure

```
get_next_line/
├── get_next_line.c           # Main function implementation
├── get_next_line_utils.c     # Helper functions
├── get_next_line.h           # Header file
└── README.md                 # This file
```

## Bonus Part

The bonus implementation adds support for:

1. **Multiple file descriptors**: Can read from different FDs without losing track of each one's state
2. **Single static variable**: Manages all FDs using only one static variable (an array)

Bonus files:
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

Example with multiple file descriptors:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);  // Read from file1
char *line2 = get_next_line(fd2);  // Read from file2
char *line3 = get_next_line(fd1);  // Continue reading file1
```

## Testing

Recommended testers for GNL:

- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette)

### Manual Testing

Create test files with different characteristics:

```bash
# File with normal lines
echo -e "Line 1\nLine 2\nLine 3" > test1.txt

# File without trailing newline
echo -n "No newline at end" > test2.txt

# Empty file
touch test3.txt

# File with empty lines
echo -e "\n\n\n" > test4.txt

# Very long line
python3 -c "print('A' * 10000)" > test5.txt
```

Test with different buffer sizes:

```bash
cc -D BUFFER_SIZE=1 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
cc -D BUFFER_SIZE=42 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
cc -D BUFFER_SIZE=9999 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
```

## Resources

### References

- **man read(2)**: System call documentation for the read function
- **man open(2)**: File descriptor creation and management
- **man close(2)**: Proper file descriptor cleanup
- **Static Variables in C**: Understanding storage duration and linkage
  - [GeeksforGeeks - Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/)
  - [C Programming - Static Keyword](https://www.programiz.com/c-programming/c-static-keyword)
- **File I/O in C**: Working with file descriptors
  - [GNU C Library - Low-Level I/O](https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-I_002fO.html)

### AI Usage

During the development of this project, I used AI assistance (Claude) for:

- **Concept clarification**: Understanding the behavior and lifetime of static variables in C
- **Edge case identification**: Discussing potential edge cases such as:
  - Files without trailing newlines
  - Very small buffer sizes (BUFFER_SIZE=1)
  - Very large buffer sizes (BUFFER_SIZE=10000000)
  - Reading from stdin vs regular files
  - Handling EOF conditions
- **Memory management strategies**: Reviewing proper allocation and deallocation patterns to avoid memory leaks
- **Algorithm optimization**: Discussing trade-offs between different approaches (e.g., reading character by character vs buffered reading)
- **Debugging assistance**: Identifying memory leaks and segmentation faults through systematic debugging approaches

All code was written, tested, and validated by me. AI was used as a learning tool to understand file I/O concepts, static variable behavior, and best practices for memory management, not to generate ready-made solutions.

## Author

**Thiago Wippel** (twippel-)  
42 São Paulo

---

*This is a student project for 42 School. The goal is educational, focusing on understanding file I/O, static variables, and memory management in C.*
