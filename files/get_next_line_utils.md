# 📋 How `get_next_line_utils.c` Works

The `get_next_line_utils.c` file provides a set of **helper functions** used by `get_next_line()`. These functions handle common string operations such as calculating string length, locating characters, duplicating strings, extracting substrings, and joining strings with automatic memory management. By centralizing these utilities, the main logic of `get_next_line()` remains **clean, modular, and easier to maintain**.

---

### 🗂️ Core Functions

1. **`ft_strlen()`**
   Calculates the length of a string safely, returning `0` if the input is `NULL`.

2. **`ft_strchr()`**
   Searches for the first occurrence of a character in a string, returning a pointer to it or `NULL`.

3. **`ft_strdup()`**
   Creates a dynamically allocated copy of a string.

4. **`ft_substr()`**
   Extracts a substring from a given string starting at a specific index for a given length.

5. **`ft_strjoin_free()`**
   Concatenates two strings into a new allocation, freeing the first string automatically to avoid memory leaks.

---

### ✅ Validations and Safety

* All functions handle `NULL` inputs gracefully.
* `ft_strjoin_free()` ensures safe concatenation even if one of the strings is `NULL`.
* Memory allocations are checked, returning `NULL` on failure.
* Proper null-termination is guaranteed for all returned strings.

---

### 🔄 Main Flow and Responsibilities

* **`ft_strlen()`** → Counts characters until `\0`.
* **`ft_strchr()`** → Iterates through the string comparing each character with the target `c`.
* **`ft_strdup()`** → Allocates memory, copies characters, and appends `\0`.
* **`ft_substr()`** → Determines the actual substring length, allocates memory, copies the relevant portion, and appends `\0`.
* **`ft_strjoin_free()`** → Computes combined length, allocates memory, copies both strings, null-terminates, and frees the first string.

---

### 🔗 Context in get\_next\_line

These utilities are **fundamental** for `get_next_line()`:

* **`ft_strlen()`** helps compute lengths for substring extraction and concatenation.
* **`ft_strchr()`** is used in `extract_line()` to locate newline characters.
* **`ft_strdup()`** initializes backup buffers and handles remaining content at EOF.
* **`ft_substr()`** extracts lines and updates backup buffers.
* **`ft_strjoin_free()`** appends newly read chunks to the backup safely, avoiding memory leaks.

Together, they **support the incremental reading logic** by ensuring reliable string manipulation and memory safety.

---

### 📝 Practical Example

```c
char *backup = ft_strdup("Hello");
backup = ft_strjoin_free(backup, " World");
char *line = ft_substr(backup, 0, 5);
free(backup);
free(line);

// Result:
// backup = "Hello World" before substring
// line = "Hello"
```

---

### 🎯 Conclusion

The `get_next_line_utils.c` file provides **safe and efficient string operations** that are essential for the correct operation of `get_next_line()`. Its design ensures memory is managed properly, strings are handled safely, and the main function remains modular and readable.

---

# 📋 Funcionamento do `get_next_line_utils.c`

O arquivo `get_next_line_utils.c` fornece um conjunto de **funções auxiliares** utilizadas pelo `get_next_line()`. Essas funções lidam com operações comuns de strings, como calcular comprimento, localizar caracteres, duplicar strings, extrair substrings e concatenar strings com gerenciamento automático de memória. Ao centralizar essas utilidades, a lógica principal do `get_next_line()` permanece **limpa, modular e fácil de manter**.

---

### 🗂️ Funções principais

1. **`ft_strlen()`**
   Calcula o comprimento de uma string de forma segura, retornando `0` se a entrada for `NULL`.

2. **`ft_strchr()`**
   Procura pela primeira ocorrência de um caractere em uma string, retornando um ponteiro para ele ou `NULL`.

3. **`ft_strdup()`**
   Cria uma cópia alocada dinamicamente de uma string.

4. **`ft_substr()`**
   Extrai uma substring de uma string fornecida, começando em um índice específico e com determinado comprimento.

5. **`ft_strjoin_free()`**
   Concatena duas strings em uma nova alocação, liberando automaticamente a primeira string para evitar vazamentos de memória.

---

### ✅ Validações e segurança

* Todas as funções lidam com entradas `NULL` de forma segura.
* `ft_strjoin_free()` garante concatenação segura mesmo se uma das strings for `NULL`.
* Alocações de memória são verificadas, retornando `NULL` em caso de falha.
* Todas as strings retornadas são corretamente terminadas com `\0`.

---

### 🔄 Fluxo principal e responsabilidades

* **`ft_strlen()`** → Conta os caracteres até `\0`.
* **`ft_strchr()`** → Percorre a string comparando cada caractere com o alvo `c`.
* **`ft_strdup()`** → Aloca memória, copia os caracteres e adiciona `\0`.
* **`ft_substr()`** → Determina o comprimento real da substring, aloca memória, copia a porção relevante e adiciona `\0`.
* **`ft_strjoin_free()`** → Calcula o comprimento combinado, aloca memória, copia ambas as strings, adiciona terminador nulo e libera a primeira string.

---

### 🔗 Contexto no projeto get\_next\_line

Essas utilidades são **fundamentais** para o `get_next_line()`:

* **`ft_strlen()`** ajuda a calcular comprimentos para extração de substrings e concatenação.
* **`ft_strchr()`** é utilizada em `extract_line()` para localizar quebras de linha.
* **`ft_strdup()`** inicializa buffers de backup e trata o conteúdo restante no EOF.
* **`ft_substr()`** extrai linhas e atualiza buffers de backup.
* **`ft_strjoin_free()`** adiciona novos blocos lidos ao backup de forma segura, evitando vazamentos de memória.

Juntas, essas funções **suportam a leitura incremental** garantindo manipulação segura de strings e memória.

---

### 📝 Exemplo prático

```c
char *backup = ft_strdup("Olá");
backup = ft_strjoin_free(backup, " Mundo");
char *linha = ft_substr(backup, 0, 3);
free(backup);
free(linha);

// Resultado:
// backup = "Olá Mundo" antes da substring
// linha = "Olá"
```

---

### 🎯 Conclusão

O arquivo `get_next_line_utils.c` fornece **operações de strings seguras e eficientes** essenciais para o funcionamento correto do `get_next_line()`. Seu design garante gerenciamento adequado de memória, manipulação segura de strings e mantém a função principal modular e legível.
