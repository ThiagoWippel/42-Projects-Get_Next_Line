# 📋 How `get_next_line.c` Works

The `get_next_line.c` file provides a **complete implementation** of the `get_next_line()` function, enabling **incremental reading of lines** from a file descriptor `fd`. It manages a static backup buffer that stores unread content, reads new data in chunks of `BUFFER_SIZE`, and returns one line at a time. This approach allows handling files of arbitrary size efficiently without loading the entire content into memory.

---

### 🗂️ Core Components

1. **`get_next_line()`**
   Main function that orchestrates reading, line extraction, and backup management.

2. **`initialize_backup()`**
   Ensures the backup buffer exists and extracts a line if possible.

3. **`extract_line()`**
   Locates the first newline in the backup and separates it from the remaining content.

4. **`read_buffer()`**
   Reads `BUFFER_SIZE` bytes from the file descriptor and appends to the backup.

5. **`return_remaining_content()`**
   Handles the last portion of the file when EOF is reached.

6. **Static backup buffer**
   Persists unread content across multiple calls to `get_next_line()`.

---

### ✅ Validations and Error Handling

* **File descriptor and buffer size:**
  Returns `NULL` if `fd` is invalid or `BUFFER_SIZE` is non-positive.

* **Memory allocations:**
  All dynamic allocations are checked, returning `NULL` if they fail.

* **Read errors:**
  If `read()` fails or concatenation fails, frees the backup and returns `NULL`.

* **EOF handling:**
  If the end of file is reached, returns any remaining content, freeing the backup afterward.

---

### 🔄 Main Flow of `get_next_line()`

1. **Initialize backup:**
   Calls `initialize_backup(&backup)` to create the buffer if it does not exist and attempt to extract a line.

2. **Return line if ready:**
   If `initialize_backup()` returns a line, it is immediately returned.

3. **Reading loop:**

   * Calls `read_buffer(fd, &backup)` to read new data in chunks.
   * On error, frees backup and returns `NULL`.
   * On EOF, calls `return_remaining_content(&backup)` to return leftover content.
   * Attempts to extract a line from backup using `extract_line()`.
   * If a line is extracted, returns it; otherwise, continues reading.

4. **Incremental reading:**
   Ensures that the function only returns complete lines and handles partially read content correctly across multiple calls.

---

### 🔗 Context in get\_next\_line Project

This file implements the **core logic** of the `get_next_line()` project. Each helper function contributes to a clear separation of responsibilities:

* **`initialize_backup()`** guarantees safe starting state.
* **`extract_line()`** handles line extraction while updating the backup.
* **`read_buffer()`** allows incremental reading of the file.
* **`return_remaining_content()`** ensures the last fragment is returned correctly.

Together, they allow `get_next_line()` to read files **line by line** efficiently, managing memory dynamically and handling all edge cases like empty lines, EOF, or read errors.

---

### 📝 Practical Example

```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

*Result:* Each iteration prints one line from `example.txt`, reading incrementally and managing memory safely.

---

### 🎯 Conclusion

The `get_next_line.c` file demonstrates a **robust, modular approach** to reading files line by line in C. It emphasizes:

* **Incremental reading** with static backup.
* **Safe memory management** with dynamic allocations.
* **Edge case handling** (EOF, empty files, read errors).
* **Separation of concerns** among helper functions for clarity and maintainability.

---

# 📋 Funcionamento do `get_next_line.c`

O arquivo `get_next_line.c` fornece uma **implementação completa** da função `get_next_line()`, permitindo a **leitura incremental de linhas** de um descritor de arquivo `fd`. Ele gerencia um buffer estático que armazena o conteúdo não lido, lê novos dados em blocos de `BUFFER_SIZE` e retorna uma linha por vez. Essa abordagem permite manipular arquivos de qualquer tamanho de forma eficiente, sem carregar todo o conteúdo na memória.

---

### 🗂️ Componentes principais

1. **`get_next_line()`**
   Função principal que coordena a leitura, extração de linhas e gerenciamento do backup.

2. **`initialize_backup()`**
   Garante que o buffer de backup exista e extrai uma linha se possível.

3. **`extract_line()`**
   Localiza a primeira quebra de linha no backup e separa-a do conteúdo restante.

4. **`read_buffer()`**
   Lê `BUFFER_SIZE` bytes do descritor de arquivo e adiciona ao backup.

5. **`return_remaining_content()`**
   Trata a última parte do arquivo ao atingir o EOF.

6. **Buffer de backup estático**
   Persiste o conteúdo não lido entre múltiplas chamadas de `get_next_line()`.

---

### ✅ Validações e tratamento de erros

* **Descritor de arquivo e tamanho do buffer:**
  Retorna `NULL` se `fd` for inválido ou `BUFFER_SIZE` não positivo.

* **Alocações de memória:**
  Todas as alocações dinâmicas são verificadas, retornando `NULL` em caso de falha.

* **Erros de leitura:**
  Se `read()` falhar ou a concatenação falhar, libera o backup e retorna `NULL`.

* **Tratamento de EOF:**
  Ao chegar ao fim do arquivo, retorna o conteúdo restante e libera o backup.

---

### 🔄 Fluxo principal do `get_next_line()`

1. **Inicializa o backup:**
   Chama `initialize_backup(&backup)` para criar o buffer caso não exista e tentar extrair uma linha.

2. **Retorna linha se disponível:**
   Se `initialize_backup()` retornar uma linha, ela é retornada imediatamente.

3. **Loop de leitura:**

   * Chama `read_buffer(fd, &backup)` para ler novos dados em blocos.
   * Em caso de erro, libera o backup e retorna `NULL`.
   * Ao atingir EOF, chama `return_remaining_content(&backup)` para retornar o conteúdo restante.
   * Tenta extrair uma linha do backup usando `extract_line()`.
   * Se uma linha for extraída, retorna-a; caso contrário, continua lendo.

4. **Leitura incremental:**
   Garante que a função retorne apenas linhas completas e trate corretamente conteúdo parcialmente lido entre chamadas.

---

### 🔗 Contexto no projeto get\_next\_line

Este arquivo implementa a **lógica central** do projeto `get_next_line()`. Cada função auxiliar contribui para uma separação clara de responsabilidades:

* **`initialize_backup()`** garante estado inicial seguro.
* **`extract_line()`** cuida da extração de linhas e atualização do backup.
* **`read_buffer()`** permite leitura incremental do arquivo.
* **`return_remaining_content()`** garante que o último fragmento seja retornado corretamente.

Juntas, essas funções permitem que `get_next_line()` leia arquivos **linha por linha** de forma eficiente, gerenciando memória dinamicamente e tratando todos os casos especiais, como linhas vazias, EOF ou erros de leitura.

---

### 📝 Exemplo prático

```c
int fd = open("exemplo.txt", O_RDONLY);
char *linha;

while ((linha = get_next_line(fd)) != NULL)
{
    printf("%s", linha);
    free(linha);
}
close(fd);
```

*Resultado:* Cada iteração imprime uma linha de `exemplo.txt`, lendo incrementalmente e gerenciando memória de forma segura.

---

### 🎯 Conclusão

O arquivo `get_next_line.c` demonstra uma abordagem **robusta e modular** para leitura de arquivos linha por linha em C. Ele enfatiza:

* **Leitura incremental** com backup estático.
* **Gerenciamento seguro de memória** com alocações dinâmicas.
* **Tratamento de casos especiais** (EOF, arquivos vazios, erros de leitura).
* **Separação de responsabilidades** entre funções auxiliares para clareza e manutenção.
