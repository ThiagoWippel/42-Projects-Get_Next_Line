# 📋 How `read_buffer()` Works

The `read_buffer()` function is responsible for **reading data from the file descriptor** and storing it in the `backup` buffer for further processing by `get_next_line()`. It ensures that newly read data is correctly concatenated with any leftover data already stored.

---

### 🗂️ Core Structure

* **Input parameters:**

  * `int fd` → file descriptor to read from.
  * `char **backup` → pointer to the dynamic buffer that accumulates data until a complete line is found.

* **Local variables:**

  * `char buffer[BUFFER_SIZE + 1]` → temporary buffer to hold freshly read data.
  * `int bytes_read` → number of bytes returned by the `read()` system call.

---

### ✅ Validations

1. **Error or EOF:**

   * If `read()` returns `-1`, it indicates an error.
   * If it returns `0`, it means EOF was reached.
   * In both cases, the function immediately returns this value without modifying `backup`.

2. **Successful read:**

   * The buffer is null-terminated (`buffer[bytes_read] = '\0'`).
   * The new content is concatenated to the existing `backup` using `ft_strjoin_free()`.
   * If memory allocation fails inside `ft_strjoin_free()`, `NULL` is set, and the function returns `-1`.

---

### 🔄 Main Flow

1. Call `read()` to fill the temporary buffer.
2. If `bytes_read <= 0`, return this value directly.
3. Null-terminate the buffer to handle it as a string.
4. Concatenate the new data to `backup`.
5. If concatenation fails, return `-1`.
6. Otherwise, return the number of bytes read.

---

### 🔗 Context in get\_next\_line

This function is called inside the main loop of `get_next_line()` to continuously read data from the file descriptor. Its role is to **feed the backup with chunks of data** until a full line is available or EOF is reached.

---

### 📝 Practical Example

```c
// Suppose fd contains: "Hello\nWorld\n"
char *backup = NULL;

// First call
int ret = read_buffer(fd, &backup);
// ret > 0, backup = "Hello\n"

// Second call
ret = read_buffer(fd, &backup);
// ret > 0, backup = "Hello\nWorld\n"
```

---

### 🎯 Conclusion

The `read_buffer()` function is a **low-level helper** in `get_next_line()`, ensuring that chunks of data read from the file descriptor are correctly appended to the backup. It bridges the gap between the raw `read()` system call and the higher-level logic that extracts lines.

---

# 📋 Funcionamento da `read_buffer()`

A função `read_buffer()` é responsável por **ler dados do descritor de arquivo** e armazená-los no buffer `backup` para processamento posterior pelo `get_next_line()`. Ela garante que os novos dados lidos sejam concatenados corretamente com qualquer dado remanescente já armazenado.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**

  * `int fd` → descritor de arquivo do qual será feita a leitura.
  * `char **backup` → ponteiro para o buffer dinâmico que acumula dados até que uma linha completa seja formada.

* **Variáveis locais:**

  * `char buffer[BUFFER_SIZE + 1]` → buffer temporário que armazena os dados recém-lidos.
  * `int bytes_read` → quantidade de bytes retornada pela chamada ao `read()`.

---

### ✅ Validações

1. **Erro ou EOF:**

   * Se `read()` retornar `-1`, houve erro.
   * Se retornar `0`, significa que o EOF foi alcançado.
   * Em ambos os casos, a função retorna imediatamente esse valor sem modificar o `backup`.

2. **Leitura bem-sucedida:**

   * O buffer é finalizado com `'\0'` (`buffer[bytes_read] = '\0'`).
   * O conteúdo lido é concatenado ao `backup` com `ft_strjoin_free()`.
   * Se a alocação falhar dentro de `ft_strjoin_free()`, `backup` é liberado e a função retorna `-1`.

---

### 🔄 Fluxo principal

1. Chama `read()` para preencher o buffer temporário.
2. Se `bytes_read <= 0`, retorna esse valor imediatamente.
3. Finaliza o buffer com `'\0'`.
4. Concatena o conteúdo lido ao `backup`.
5. Se a concatenação falhar, retorna `-1`.
6. Caso contrário, retorna a quantidade de bytes lidos.

---

### 🔗 Contexto no get\_next\_line

Essa função é chamada dentro do loop principal de `get_next_line()` para ler continuamente dados do descritor de arquivo. Seu papel é **alimentar o backup com blocos de dados** até que uma linha completa esteja disponível ou até o EOF.

---

### 📝 Exemplo prático

```c
// Suponha que fd contenha: "Ola\nMundo\n"
char *backup = NULL;

// Primeira chamada
int ret = read_buffer(fd, &backup);
// ret > 0, backup = "Ola\n"

// Segunda chamada
ret = read_buffer(fd, &backup);
// ret > 0, backup = "Ola\nMundo\n"
```

---

### 🎯 Conclusão

A função `read_buffer()` atua como um **auxiliar de baixo nível** no `get_next_line()`, garantindo que os blocos de dados lidos do descritor de arquivo sejam corretamente adicionados ao backup. Ela faz a ponte entre a chamada bruta ao `read()` e a lógica de mais alto nível que extrai linhas completas.
