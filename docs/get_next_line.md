# 📋 How `get_next_line()` Works

The `get_next_line()` function is designed to **read one line at a time** from a file descriptor, making it reusable across multiple calls until the end of the file is reached. It uses a static buffer (`backup`) to retain leftover content between function calls, ensuring continuity when a line spans multiple reads.

---

### 🗂️ Core Structure

* **Input parameter:**
  `int fd` → the file descriptor from which the function will read.

* **Static variable:**
  `static char *backup` → keeps track of leftover characters that were not yet returned.

* **Local variables:**

  * `char *line` → pointer to hold the line ready to be returned.
  * `int read_result` → indicates the outcome of reading: number of bytes read, error, or EOF.

---

### ✅ Validations

1. **Invalid arguments:**
   If `fd < 0` or `BUFFER_SIZE <= 0`, the function immediately returns `NULL`.

2. **Backup check:**
   The function first calls `initialize_backup(&backup)` to verify if the backup already contains a complete line. If so, that line is returned without reading more data.

---

### 🔄 Main Flow

1. **Loop structure:**
   The function enters an infinite loop to keep reading until a line is ready or EOF is reached.

2. **Reading from file:**
   Calls `read_buffer(fd, &backup)` to read chunks of data and append them to the backup.

   * If `read_buffer` returns `-1`, an error occurred → free `backup`, reset it to `NULL`, and return `NULL`.
   * If `read_buffer` returns `0`, it means EOF → call `return_remaining_content(&backup)` to return the last data (if any).

3. **Extracting a line:**
   After each read, the function calls `extract_line(&backup)` to check if a newline (`\n`) exists in the backup.

   * If a line is found, it is returned immediately.
   * If not, the loop continues to read more data.

---

### 🔗 Context in get\_next\_line

This function acts as the **orchestrator** of the entire process:

* It validates inputs.
* It coordinates reading data into the backup.
* It extracts complete lines when available.
* It properly handles EOF and errors.

The use of a **static backup** is crucial, as it ensures partial reads are preserved across multiple calls, making the function reliable regardless of the `BUFFER_SIZE`.

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

// Output: prints the file content line by line
```

---

### 🎯 Conclusion

`get_next_line()` provides a **line-by-line reading mechanism** that is both efficient and memory-safe. By leveraging helper functions like `initialize_backup`, `read_buffer`, `extract_line`, and `return_remaining_content`, it guarantees a clean separation of responsibilities and ensures robust file reading behavior across different scenarios.

---

# 📋 Funcionamento da `get_next_line()`

A função `get_next_line()` foi projetada para **ler uma linha por vez** de um descritor de arquivo, sendo chamada repetidamente até que o fim do arquivo seja atingido. Ela utiliza um buffer estático (`backup`) para armazenar dados remanescentes entre chamadas, garantindo continuidade quando uma linha ocupa múltiplas leituras.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `int fd` → descritor de arquivo de onde a função irá ler.

* **Variável estática:**
  `static char *backup` → armazena caracteres que ainda não foram retornados.

* **Variáveis locais:**

  * `char *line` → ponteiro para armazenar a linha pronta para ser retornada.
  * `int read_result` → indica o resultado da leitura: número de bytes lidos, erro ou EOF.

---

### ✅ Validações

1. **Argumentos inválidos:**
   Se `fd < 0` ou `BUFFER_SIZE <= 0`, a função retorna imediatamente `NULL`.

2. **Verificação do backup:**
   A função chama `initialize_backup(&backup)` para verificar se o backup já contém uma linha completa. Se sim, essa linha é retornada sem necessidade de novas leituras.

---

### 🔄 Fluxo principal

1. **Estrutura de loop:**
   A função entra em um loop infinito, lendo até que uma linha esteja pronta ou EOF seja encontrado.

2. **Leitura do arquivo:**
   Chama `read_buffer(fd, &backup)` para ler blocos de dados e adicioná-los ao backup.

   * Se `read_buffer` retornar `-1`, ocorreu um erro → libera `backup`, reseta para `NULL` e retorna `NULL`.
   * Se `read_buffer` retornar `0`, significa EOF → chama `return_remaining_content(&backup)` para retornar os últimos dados (se houver).

3. **Extração de linha:**
   Após cada leitura, chama `extract_line(&backup)` para verificar se existe um caractere de nova linha (`\n`) no backup.

   * Se uma linha for encontrada, ela é retornada imediatamente.
   * Caso contrário, o loop continua lendo mais dados.

---

### 🔗 Contexto no get\_next\_line

Esta função atua como o **orquestrador** de todo o processo:

* Valida os parâmetros de entrada.
* Coordena a leitura de dados no backup.
* Extrai linhas completas quando disponíveis.
* Trata adequadamente EOF e erros.

O uso de um **backup estático** é essencial, pois garante que leituras parciais sejam preservadas entre chamadas, tornando a função confiável independentemente do `BUFFER_SIZE`.

---

### 📝 Exemplo prático

```c
int fd = open("exemplo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}

// Saída: imprime o conteúdo do arquivo linha por linha
```

---

### 🎯 Conclusão

`get_next_line()` fornece um **mecanismo de leitura linha a linha** eficiente e seguro quanto ao uso de memória. Ao delegar responsabilidades para funções auxiliares como `initialize_backup`, `read_buffer`, `extract_line` e `return_remaining_content`, garante uma separação clara de responsabilidades e um comportamento robusto na leitura de arquivos em diversos cenários.

---

Quer que eu já prepare a próxima documentação para `initialize_backup()`?
