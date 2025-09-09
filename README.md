# Get Next Line

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![42 School](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
[![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

> A memory-efficient C function that reads files line by line with dynamic buffer management, capable of handling files of any size with configurable buffer sizes.

## Overview

Get Next Line is a C function developed as part of the 42 School curriculum that solves the fundamental problem of reading files line by line without loading the entire file into memory. The implementation demonstrates advanced concepts in memory management, file descriptor handling, and static variables.

### Key Features

- **Universal File Support**: Works with any readable file descriptor
- **Dynamic Buffer Management**: Configurable buffer size from 1 byte to 10MB+
- **Memory Safe**: Zero memory leaks with proper cleanup
- **Static Variable Usage**: Maintains state between function calls
- **Standard Compliant**: Follows 42 School norminette standards

## Technical Specifications

### Function Prototype
```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: File descriptor to read from

### Return Values
- **Success**: Pointer to string containing the next line (including `\n` if present)
- **End of file**: `NULL`
- **Error**: `NULL` (invalid fd, memory allocation failure)

### Core Algorithm
1. **Buffer Management**: Reads data in configurable chunks
2. **State Persistence**: Uses static variables to maintain reading position
3. **Line Assembly**: Efficiently extracts complete lines from buffer
4. **Memory Safety**: Automatic cleanup and error handling

## Installation & Usage

### Basic Compilation
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    src/get_next_line.c src/get_next_line_utils.c your_main.c \
    -I include/
```

### Buffer Size Configuration
```bash
# Memory-efficient (1 byte)
gcc -D BUFFER_SIZE=1 src/*.c your_main.c -I include/

# Balanced performance (recommended)
gcc -D BUFFER_SIZE=42 src/*.c your_main.c -I include/

# High-performance (large files)
gcc -D BUFFER_SIZE=8192 src/*.c your_main.c -I include/
```

### Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Always free returned line
    }
    
    close(fd);
    return (0);
}
```

## Project Structure

```
├── src/                        # Source files
│   ├── get_next_line.c        # Main implementation
│   └── get_next_line_utils.c  # Utility functions
├── include/                   # Header files
│   └── get_next_line.h       # Function prototypes
└── docs/                     # Detailed documentation
    ├── ft_strlen.md          # String length function
    ├── ft_strchr.md          # Character search function
    ├── ft_strdup.md          # String duplication function
    ├── ft_substr.md          # Substring extraction function
    ├── ft_strjoin_free.md    # String joining with cleanup
    └── [5 more function docs]
```

## Performance Characteristics

### Tested Buffer Sizes
| Buffer Size | 1MB File | 10MB File | Memory Usage |
|-------------|----------|-----------|--------------|
| 1 byte      | ~2.5s    | ~25s      | Minimal      |
| 42 bytes    | ~0.1s    | ~1.0s     | Low          |
| 8192 bytes  | ~0.05s   | ~0.5s     | Moderate     |

### Edge Cases Handled
- Empty files
- Files without trailing newlines
- Single character files
- Lines longer than buffer size
- Multiple consecutive newlines
- Very large files (tested up to 100MB)

## Testing & Quality Assurance

The implementation has been thoroughly tested using industry-standard tools:

### Test Suites Used
- **Francinette**: Official 42 testing framework - All tests passed
- **gnlTester**: Community testing suite - Comprehensive validation
- **Valgrind**: Memory leak detection - Zero leaks confirmed
- **Norminette**: Code style compliance - 100% conformant

### Validation Results
- **Memory Safety**: No memory leaks detected across all test scenarios
- **Buffer Compatibility**: Tested with buffer sizes from 1 to 10,000,000 bytes
- **File Type Support**: Successfully handles text files, empty files, and edge cases
- **Performance**: Optimal performance with recommended buffer sizes (42-8192 bytes)

## Documentation

Comprehensive technical documentation is available in the `docs/` directory:

- **Function Documentation**: Individual `.md` files for each utility function
- **Implementation Details**: Code examples and technical explanations
- **Usage Patterns**: Common use cases and best practices
- **Error Handling**: Detailed coverage of edge cases and error conditions

Each function is documented with:
- Complete implementation code
- Technical explanations in English and Portuguese
- Practical usage examples
- Context within the get_next_line project

## Technical Requirements

### Mandatory Constraints
- **Allowed functions**: `read()`, `malloc()`, `free()`
- **Forbidden**: `lseek()`, global variables, libft usage
- **Compilation flags**: `-Wall -Wextra -Werror`
- **Buffer size**: Configurable via `-D BUFFER_SIZE=n`

### Code Standards
- 42 School Norminette compliance
- Maximum 25 lines per function
- Proper error handling and memory management
- No memory leaks under any circumstances

## Development Insights

This project demonstrates proficiency in:

- **Low-level C programming** with direct system calls
- **Memory management** with dynamic allocation strategies  
- **Algorithm optimization** for efficient file processing
- **Static variable manipulation** for state persistence
- **Error handling** across multiple failure scenarios

The implementation showcases solutions to complex challenges including buffer management with varying sizes, memory-safe string operations, and robust file descriptor handling.

## License

This project is for educational purposes as part of 42 School curriculum.

## Author

**Thiago Wippel**
- GitHub: [@ThiagoWippel](https://github.com/ThiagoWippel)  
- 42 Intranet: `twippel-`

---

*Part of the 42 School Common Core curriculum - a comprehensive computer science program focused on practical skills development and peer-to-peer learning.*
