# 📋 How `extract_line()` Works

The `extract_line()` function is responsible for **isolating and returning the next complete line** from the `backup` buffer, including the newline character (`'\n'`). After extracting the line, it updates `backup` so that it only contains the remaining content to be processed in future calls.

---

### 🗂️ Core Structure

* **Input parameter:**

  * `char **backup` → pointer to the buffer that stores the accumulated data read from the file descriptor.

* **Local variables:**

  * `char *newline_pos` → pointer to the first occurrence of `'\n'` in `backup`.
  * `char *line` → stores the newly extracted line.
  * `char *temp` → temporary buffer holding the remaining content after the extracted line.
  * `size_t line_len` → length of the line to extract, including the newline.

---

### ✅ Validations

1. **Check for newline:**

   * If `'\n'` is not found, the function returns `NULL`, since no complete line is available yet.

2. **Memory allocation checks:**

   * If `ft_substr()` fails to allocate memory when creating the line, the function returns `NULL`.

---

### 🔄 Main Flow

1. Search for the newline character in `backup` with `ft_strchr()`.
2. If found, calculate the line length (`line_len`).
3. Extract the line from `backup` using `ft_substr(*backup, 0, line_len)`.
4. Extract the remaining content after the line into `temp`.
5. Free the old `backup` and update it with the new value (`temp`).
6. Return the extracted line.

---

### 🔗 Context in get\_next\_line

This function is the **core mechanism for line extraction** in `get_next_line()`. Each time data is read into `backup`, `extract_line()` checks if a newline is present and, if so, returns that complete line. It ensures that leftover content remains available for subsequent reads.

---

### 📝 Practical Example

```c
// Suppose backup = "Hello\nWorld\n"
char *line = extract_line(&backup);

// Result:
// line   = "Hello\n"
// backup = "World\n"
```

---

### 🎯 Conclusion

The `extract_line()` function ensures that the program can **progressively extract complete lines** from the `backup` buffer while preserving the remaining data for the next call. It is the fundamental step that transforms raw buffered data into properly terminated lines.

---

# 📋 Funcionamento da `extract_line()`

A função `extract_line()` é responsável por **isolar e retornar a próxima linha completa** do buffer `backup`, incluindo o caractere de quebra de linha (`'\n'`). Após extrair a linha, ela atualiza o `backup` para que contenha apenas o conteúdo restante a ser processado nas próximas chamadas.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**

  * `char **backup` → ponteiro para o buffer que armazena os dados acumulados lidos do descritor de arquivo.

* **Variáveis locais:**

  * `char *newline_pos` → ponteiro para a primeira ocorrência de `'\n'` em `backup`.
  * `char *line` → armazena a linha recém-extraída.
  * `char *temp` → buffer temporário contendo o conteúdo restante após a linha extraída.
  * `size_t line_len` → tamanho da linha a ser extraída, incluindo o `\n`.

---

### ✅ Validações

1. **Verificação de newline:**

   * Se `'\n'` não for encontrado, a função retorna `NULL`, pois não há linha completa disponível ainda.

2. **Verificação de alocação de memória:**

   * Se `ft_substr()` falhar ao criar a linha, a função retorna `NULL`.

---

### 🔄 Fluxo principal

1. Busca o caractere `\n` em `backup` com `ft_strchr()`.
2. Se encontrado, calcula o comprimento da linha (`line_len`).
3. Extrai a linha de `backup` usando `ft_substr(*backup, 0, line_len)`.
4. Extrai o conteúdo restante em `temp`.
5. Libera o `backup` antigo e atualiza-o com o novo valor (`temp`).
6. Retorna a linha extraída.

---

### 🔗 Contexto no get\_next\_line

Essa função é o **mecanismo central de extração de linhas** no `get_next_line()`. A cada vez que dados são lidos para `backup`, `extract_line()` verifica se há uma quebra de linha presente e, em caso positivo, retorna essa linha completa. Assim, garante que o conteúdo remanescente continue disponível para as próximas leituras.

---

### 📝 Exemplo prático

```c
// Suponha backup = "Ola\nMundo\n"
char *linha = extract_line(&backup);

// Resultado:
// linha  = "Ola\n"
// backup = "Mundo\n"
```

---

### 🎯 Conclusão

A função `extract_line()` garante que o programa consiga **extrair progressivamente linhas completas** do buffer `backup`, preservando o conteúdo restante para a próxima chamada. Ela é o passo fundamental que transforma dados brutos em linhas corretamente terminadas.
