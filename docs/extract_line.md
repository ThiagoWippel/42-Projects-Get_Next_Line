# 📋 How `extract_line()` Works

The `extract_line()` function is responsible for **extracting a single complete line** from the backup buffer, including the newline character `\n`. It receives a pointer to the backup string and returns a dynamically allocated string containing the line, or `NULL` if no complete line is found.

---

### 🗂️ Core Structure

* **Input parameter:**
  `char **backup` → pointer to the backup buffer containing previously read data.
* **Local variables:**

  * `newline_pos`: pointer to the first occurrence of `\n` in the backup.
  * `line`: the extracted line to be returned.
  * `temp`: temporary string holding the remaining content after extraction.
  * `line_len`: length of the line to be extracted.

---

### ✅ Validations

1. **Check for newline:**
   Uses `ft_strchr` to find the first occurrence of `\n` in `*backup`. If not found, returns `NULL` since there is no complete line yet.

2. **Memory allocation checks:**

   * Uses `ft_substr` to allocate the line. If allocation fails, returns `NULL`.
   * Allocates a new substring for the remaining backup content, updates `*backup`, and frees the old buffer.

---

### 🔄 Main Flow

1. **Find the newline character:**
   Determine the position of `\n` in the backup string.

2. **Calculate line length:**
   Compute `line_len` as the distance from the start of the backup to the newline, inclusive.

3. **Extract the line:**
   Use `ft_substr` to create a new string containing the line.

4. **Update the backup:**
   Copy the remaining content after the extracted line into a new buffer (`temp`) and free the old backup. Assign `temp` to `*backup`.

5. **Return the extracted line:**
   The line is now a separate dynamically allocated string, ready to be returned by `get_next_line()`.

---

### 🔗 Context in get\_next\_line

In **get\_next\_line**, `extract_line()` is the core utility that ensures **only one complete line is returned per function call**. It allows the backup buffer to preserve leftover data for future reads. This separation ensures that even if the buffer contains multiple lines, each call to `get_next_line()` returns exactly one line, while the rest remains in backup.

---

### 📝 Practical Example

```c
char *backup = ft_strdup("line1\nline2\nline3\n");
char *line = extract_line(&backup);

// Result after first call:
// line = "line1\n"
// backup = "line2\nline3\n"
```

---

### 🎯 Conclusion

The `extract_line()` function isolates a single complete line from the backup buffer, updating the backup for subsequent reads. It is fundamental in **get\_next\_line** to maintain proper line-by-line extraction while preserving leftover content for future calls.

---

# 📋 Funcionamento da `extract_line()`

A função `extract_line()` é responsável por **extrair uma única linha completa** do backup, incluindo o caractere de nova linha `\n`. Recebe um ponteiro para o backup e retorna uma string alocada dinamicamente contendo a linha, ou `NULL` caso não exista uma linha completa.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `char **backup` → ponteiro para o buffer que armazena dados lidos anteriormente.
* **Variáveis locais:**

  * `newline_pos`: ponteiro para a primeira ocorrência de `\n` no backup.
  * `line`: linha extraída que será retornada.
  * `temp`: string temporária contendo o restante do backup após a extração.
  * `line_len`: tamanho da linha a ser extraída.

---

### ✅ Validações

1. **Verificação de nova linha:**
   Utiliza `ft_strchr` para encontrar a primeira ocorrência de `\n` em `*backup`. Se não encontrar, retorna `NULL`, indicando que não há linha completa.

2. **Verificação de alocação de memória:**

   * Usa `ft_substr` para criar a linha. Se falhar, retorna `NULL`.
   * Aloca uma nova substring para o restante do backup, atualiza `*backup` e libera o buffer antigo.

---

### 🔄 Fluxo principal

1. **Localizar o caractere de nova linha:**
   Determina a posição de `\n` na string do backup.

2. **Calcular o tamanho da linha:**
   Calcula `line_len` como a distância do início do backup até o `\n`, incluindo-o.

3. **Extrair a linha:**
   Cria uma nova string contendo a linha usando `ft_substr`.

4. **Atualizar o backup:**
   Copia o conteúdo restante após a linha extraída para um novo buffer (`temp`), libera o antigo e atribui `temp` a `*backup`.

5. **Retornar a linha extraída:**
   A linha agora é uma string alocada dinamicamente, pronta para ser retornada pelo `get_next_line()`.

---

### 🔗 Contexto no get\_next\_line

No **get\_next\_line**, `extract_line()` é a função central que garante que **apenas uma linha completa seja retornada por chamada**. Ela permite que o backup preserve os dados restantes para leituras futuras. Isso garante que, mesmo que o buffer contenha múltiplas linhas, cada chamada a `get_next_line()` retorna exatamente uma linha, enquanto o restante permanece no backup.

---

### 📝 Exemplo prático

```c
char *backup = ft_strdup("linha1\nlinha2\nlinha3\n");
char *line = extract_line(&backup);

// Resultado após a primeira chamada:
// line = "linha1\n"
// backup = "linha2\nlinha3\n"
```

---

### 🎯 Conclusão

A função `extract_line()` isola uma linha completa do buffer de backup, atualizando o restante para futuras leituras. Ela é fundamental no **get\_next\_line** para garantir a extração correta linha a linha, mantendo os dados restantes preservados para as próximas chamadas.
