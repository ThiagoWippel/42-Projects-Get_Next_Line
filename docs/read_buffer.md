# 📋 How `read_buffer()` Works

The `read_buffer()` function handles **reading a portion of data** from a file descriptor `fd` into a temporary buffer, then appends this data to the existing backup using `ft_strjoin_free()`. It ensures that the backup accumulates the file content incrementally, which is essential for extracting complete lines in `get_next_line()`.

---

### 🗂️ Core Structure

* **Input parameters:**

  * `int fd` → the file descriptor from which data is read.
  * `char **backup` → pointer to the backup buffer where read data will be appended.

* **Return value:**

  * Number of bytes read if successful.
  * `0` if the end of the file (EOF) is reached.
  * `-1` if an error occurs (allocation failure or read error).

---

### ✅ Validations

1. **Memory allocation:**

   * Allocates `BUFFER_SIZE + 1` bytes for the temporary buffer.
   * Returns `-1` if allocation fails.

2. **Read operation:**

   * Uses `read()` to fetch up to `BUFFER_SIZE` bytes from `fd`.
   * If `read()` returns `0` (EOF) or negative (error), frees the temporary buffer and returns the corresponding value.

3. **Backup concatenation:**

   * Appends the newly read buffer to `*backup` using `ft_strjoin_free()`.
   * Frees the temporary buffer after joining.
   * Returns `-1` if joining fails.

---

### 🔄 Main Flow

1. Allocate a temporary buffer of size `BUFFER_SIZE + 1`.
2. Read data from the file descriptor into the buffer.
3. Null-terminate the buffer at `bytes_read`.
4. Append the buffer to the backup using `ft_strjoin_free()`.
5. Free the temporary buffer.
6. Return the number of bytes read or an error code.

---

### 🔗 Context in get\_next\_line

In `get_next_line()`, `read_buffer()` is called **inside the main loop** when the backup does not yet contain a complete line. It incrementally reads the file in chunks of `BUFFER_SIZE`, adding the data to the backup buffer until a complete line can be extracted. This function ensures **efficient reading** and proper handling of EOF and errors.

---

### 📝 Practical Example

```c
char *backup = ft_strdup("");
int bytes = read_buffer(fd, &backup);

// Result:
// backup now contains the first BUFFER_SIZE bytes read from fd
// bytes holds the number of bytes read (or 0/-1)
```

---

### 🎯 Conclusion

`read_buffer()` provides **incremental reading and safe concatenation** of file content into the backup buffer. It is a core component of `get_next_line()` for handling files of arbitrary length efficiently.

---

# 📋 Funcionamento da `read_buffer()`

A função `read_buffer()` é responsável por **ler uma porção de dados** de um descritor de arquivo `fd` para um buffer temporário e, em seguida, adicionar esses dados ao backup existente usando `ft_strjoin_free()`. Isso garante que o backup acumule o conteúdo do arquivo de forma incremental, essencial para extrair linhas completas em `get_next_line()`.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**

  * `int fd` → descritor de arquivo do qual os dados serão lidos.
  * `char **backup` → ponteiro para o buffer de backup onde os dados lidos serão adicionados.

* **Valor de retorno:**

  * Número de bytes lidos se bem-sucedido.
  * `0` se atingir o fim do arquivo (EOF).
  * `-1` se ocorrer um erro (falha de alocação ou erro na leitura).

---

### ✅ Validações

1. **Alocação de memória:**

   * Aloca `BUFFER_SIZE + 1` bytes para o buffer temporário.
   * Retorna `-1` se a alocação falhar.

2. **Operação de leitura:**

   * Usa `read()` para buscar até `BUFFER_SIZE` bytes de `fd`.
   * Se `read()` retornar `0` (EOF) ou negativo (erro), libera o buffer temporário e retorna o valor correspondente.

3. **Concatenação ao backup:**

   * Adiciona o buffer lido a `*backup` usando `ft_strjoin_free()`.
   * Libera o buffer temporário após a junção.
   * Retorna `-1` se a junção falhar.

---

### 🔄 Fluxo principal

1. Aloca um buffer temporário de tamanho `BUFFER_SIZE + 1`.
2. Lê dados do descritor de arquivo para o buffer.
3. Adiciona o terminador nulo `\0` no final do buffer.
4. Adiciona o buffer ao backup usando `ft_strjoin_free()`.
5. Libera o buffer temporário.
6. Retorna o número de bytes lidos ou código de erro.

---

### 🔗 Contexto no get\_next\_line

Em `get_next_line()`, `read_buffer()` é chamado **dentro do loop principal** quando o backup ainda não contém uma linha completa. Ele lê o arquivo incrementalmente em blocos de `BUFFER_SIZE`, adicionando os dados ao backup até que seja possível extrair uma linha completa. Esta função garante **leitura eficiente** e tratamento adequado de EOF e erros.

---

### 📝 Exemplo prático

```c
char *backup = ft_strdup("");
int bytes = read_buffer(fd, &backup);

// Resultado:
// backup agora contém os primeiros BUFFER_SIZE bytes lidos de fd
// bytes contém o número de bytes lidos (ou 0/-1)
```

---

### 🎯 Conclusão

`read_buffer()` permite a **leitura incremental e concatenação segura** do conteúdo do arquivo no backup. É um componente central do `get_next_line()` para manipular arquivos de qualquer tamanho de forma eficiente.
