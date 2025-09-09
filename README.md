# Get Next Line

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![42 School](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
[![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

> A memory-efficient C function that reads files line by line with dynamic buffer management, capable of handling files of any size with configurable buffer sizes.

> Uma função C eficiente em memória que lê arquivos linha por linha com gerenciamento dinâmico de buffer, capaz de lidar com arquivos de qualquer tamanho com buffers configuráveis.

## Overview / Visão Geral

Get Next Line is a C function developed as part of the 42 School curriculum that solves the fundamental problem of reading files line by line without loading the entire file into memory. The implementation demonstrates advanced concepts in memory management, file descriptor handling, and static variables.

Get Next Line é uma função C desenvolvida como parte do currículo da 42 School que resolve o problema fundamental de ler arquivos linha por linha sem carregar o arquivo inteiro na memória. A implementação demonstra conceitos avançados em gerenciamento de memória, manipulação de file descriptors e variáveis estáticas.

### Key Features / Características Principais

- **Universal File Support / Suporte Universal a Arquivos**: Works with any readable file descriptor / Funciona com qualquer file descriptor legível
- **Dynamic Buffer Management / Gerenciamento Dinâmico de Buffer**: Configurable buffer size from 1 byte to 10MB+ / Tamanho de buffer configurável de 1 byte a 10MB+
- **Memory Safe / Seguro em Memória**: Zero memory leaks with proper cleanup / Zero vazamentos de memória com limpeza adequada
- **Static Variable Usage / Uso de Variáveis Estáticas**: Maintains state between function calls / Mantém estado entre chamadas da função
- **Standard Compliant / Conforme Padrões**: Follows 42 School norminette standards / Segue os padrões norminette da 42 School

## Technical Specifications / Especificações Técnicas

### Function Prototype / Protótipo da Função
```c
char *get_next_line(int fd);
```

### Parameters / Parâmetros
- `fd`: File descriptor to read from / File descriptor para leitura

### Return Values / Valores de Retorno
- **Success / Sucesso**: Pointer to string containing the next line (including `\n` if present) / Ponteiro para string contendo a próxima linha (incluindo `\n` se presente)
- **End of file / Fim do arquivo**: `NULL`
- **Error / Erro**: `NULL` (invalid fd, memory allocation failure / fd inválido, falha na alocação de memória)

### Core Algorithm / Algoritmo Principal
1. **Buffer Management / Gerenciamento de Buffer**: Reads data in configurable chunks / Lê dados em blocos configuráveis
2. **State Persistence / Persistência de Estado**: Uses static variables to maintain reading position / Usa variáveis estáticas para manter posição de leitura
3. **Line Assembly / Montagem de Linha**: Efficiently extracts complete lines from buffer / Extrai eficientemente linhas completas do buffer
4. **Memory Safety / Segurança de Memória**: Automatic cleanup and error handling / Limpeza automática e tratamento de erros

## Installation & Usage / Instalação e Uso

### Basic Compilation / Compilação Básica
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    src/get_next_line.c src/get_next_line_utils.c your_main.c \
    -I include/
```

### Buffer Size Configuration / Configuração do Tamanho do Buffer
```bash
# Memory-efficient (1 byte) / Eficiente em memória (1 byte)
gcc -D BUFFER_SIZE=1 src/*.c your_main.c -I include/

# Balanced performance (recommended) / Performance balanceada (recomendado)
gcc -D BUFFER_SIZE=42 src/*.c your_main.c -I include/

# High-performance (large files) / Alta performance (arquivos grandes)
gcc -D BUFFER_SIZE=8192 src/*.c your_main.c -I include/
```

### Usage Example / Exemplo de Uso
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
        free(line);  // Always free returned line / Sempre libere a linha retornada
    }
    
    close(fd);
    return (0);
}
```

## Project Structure / Estrutura do Projeto

```
├── src/                        # Source files / Arquivos fonte
│   ├── get_next_line.c        # Main implementation / Implementação principal
│   └── get_next_line_utils.c  # Utility functions / Funções utilitárias
├── include/                   # Header files / Arquivos de cabeçalho
│   └── get_next_line.h       # Function prototypes / Protótipos das funções
└── docs/                     # Detailed documentation / Documentação detalhada
    └── *.md                  # Individual function documentation / Documentação individual das funções
```

## Testing & Quality Assurance / Testes e Garantia de Qualidade

The implementation has been thoroughly tested using industry-standard tools:
A implementação foi rigorosamente testada usando ferramentas padrão da indústria:

### Test Suites Used / Suítes de Teste Utilizadas
- **Francinette**: Official 42 testing framework - All tests passed / Framework oficial de testes da 42 - Todos os testes aprovados
- **gnlTester**: Community testing suite - Comprehensive validation / Suíte de testes da comunidade - Validação abrangente
- **Valgrind**: Memory leak detection - Zero leaks confirmed / Detecção de vazamentos de memória - Zero vazamentos confirmados
- **Norminette**: Code style compliance - 100% conformant / Conformidade de estilo de código - 100% conforme

### Validation Results / Resultados da Validação
- **Memory Safety / Segurança de Memória**: No memory leaks detected across all test scenarios / Nenhum vazamento de memória detectado em todos os cenários de teste
- **Buffer Compatibility / Compatibilidade de Buffer**: Tested with buffer sizes from 1 to 10,000,000 bytes / Testado com tamanhos de buffer de 1 a 10.000.000 bytes
- **Edge Cases / Casos Limite**: Successfully handles empty files, files without newlines, and large files / Lida com sucesso com arquivos vazios, arquivos sem quebras de linha e arquivos grandes

## Documentation / Documentação

Comprehensive technical documentation is available in the `docs/` directory with individual `.md` files for each utility function, featuring:

Documentação técnica abrangente está disponível no diretório `docs/` com arquivos `.md` individuais para cada função utilitária, incluindo:

- **Complete Implementation / Implementação Completa**: Full source code for each function / Código fonte completo para cada função
- **Bilingual Explanations / Explicações Bilíngues**: Technical details in English and Portuguese / Detalhes técnicos em inglês e português  
- **Practical Examples / Exemplos Práticos**: Usage patterns and code samples / Padrões de uso e exemplos de código
- **Project Context / Contexto do Projeto**: How each function integrates with get_next_line / Como cada função se integra com get_next_line

## Technical Requirements / Requisitos Técnicos

### Mandatory Constraints / Restrições Obrigatórias
- **Allowed functions / Funções permitidas**: `read()`, `malloc()`, `free()`
- **Forbidden / Proibido**: `lseek()`, global variables, libft usage / variáveis globais, uso da libft
- **Compilation flags / Flags de compilação**: `-Wall -Wextra -Werror`
- **Buffer size / Tamanho do buffer**: Configurable via `-D BUFFER_SIZE=n` / Configurável via `-D BUFFER_SIZE=n`

### Code Standards / Padrões de Código
- 42 School Norminette compliance / Conformidade com norminette da 42 School
- Maximum 25 lines per function / Máximo 25 linhas por função
- Proper error handling and memory management / Tratamento adequado de erros e gerenciamento de memória
- No memory leaks under any circumstances / Nenhum vazamento de memória sob qualquer circunstância

## Development Insights / Insights de Desenvolvimento

This project demonstrates proficiency in:
Este projeto demonstra proficiência em:

- **Low-level C programming / Programação C de baixo nível** with direct system calls / com chamadas diretas do sistema
- **Memory management / Gerenciamento de memória** with dynamic allocation strategies / com estratégias de alocação dinâmica
- **Algorithm optimization / Otimização de algoritmos** for efficient file processing / para processamento eficiente de arquivos
- **Static variable manipulation / Manipulação de variáveis estáticas** for state persistence / para persistência de estado
- **Error handling / Tratamento de erros** across multiple failure scenarios / em múltiplos cenários de falha

The implementation showcases solutions to complex challenges including buffer management with varying sizes, memory-safe string operations, and robust file descriptor handling.

A implementação apresenta soluções para desafios complexos incluindo gerenciamento de buffer com tamanhos variáveis, operações de string seguras em memória e manipulação robusta de file descriptors.

## License / Licença

This project is for educational purposes as part of 42 School curriculum.
Este projeto é para fins educacionais como parte do currículo da 42 School.

## Author / Autor

**Thiago Wippel**
- LinkedIn: [Thiago Wippel](https://www.linkedin.com/in/thiagowippelc/)

---

*Part of the 42 School Common Core curriculum - a comprehensive computer science program focused on practical skills development and peer-to-peer learning.*

*Parte do currículo Common Core da 42 School - um programa abrangente de ciência da computação focado no desenvolvimento de habilidades práticas e aprendizado peer-to-peer.*
