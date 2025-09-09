# 📋 How `ft_substr()` Works

The `ft_substr()` function creates a **substring from a given string `s`**, starting at a specified index `start` and spanning up to `len` characters. It returns a dynamically allocated string containing the requested portion or an empty string if `start` is beyond the end of the original string.

---

### 🗂️ Core Structure

* **Input parameters:**
  `const char *s` → original string
  `unsigned int start` → starting index of the substring
  `size_t len` → maximum length of the substring

* **Local variables:**

  * `s_len`: length of the original string
  * `substr`: pointer to the newly allocated substring
  * `i`: iteration index

---

### ✅ Validations

1. **Null pointer check:**
   Returns `NULL` if `s` is `NULL`.

2. **Start index beyond string length:**
   If `start >= s_len`, returns an empty string using `ft_strdup("")`.

3. **Adjust length:**
   If `len` exceeds the remaining characters from `start`, it is reduced to fit the string.

4. **Memory allocation check:**
   Allocates `len + 1` bytes for the substring plus the null terminator. Returns `NULL` if allocation fails.

---

### 🔄 Main Flow

1. **Copy characters:**
   Iterates from `start` to `start + len`, copying each character into `substr`.

2. **Terminate string:**
   Appends `'\0'` at the end to ensure proper string termination.

3. **Return substring:**
   The substring is now a separate dynamically allocated string, ready for use.

---

### 🔗 Context in get\_next\_line

In **get\_next\_line**, `ft_substr()` is heavily used to **extract lines from the backup buffer** and to create new backups after a line has been removed. It ensures that each line returned and the remaining buffer are properly allocated and independent, preventing overwriting issues between reads.

---

### 📝 Practical Example

```c
const char *str = "Hello, world!";
char *sub = ft_substr(str, 7, 5);

// Result:
// sub = "world"
```

---

### 🎯 Conclusion

The `ft_substr()` function provides a **safe and efficient way to extract substrings**, which is crucial in `get_next_line` for separating individual lines from the backup while preserving remaining content.

---

# 📋 Funcionamento da `ft_substr()`

A função `ft_substr()` cria uma **substring a partir de uma string `s`**, iniciando em um índice `start` e com comprimento máximo `len`. Retorna uma string alocada dinamicamente contendo a porção solicitada ou uma string vazia se `start` estiver além do final da string original.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**
  `const char *s` → string original
  `unsigned int start` → índice inicial da substring
  `size_t len` → tamanho máximo da substring

* **Variáveis locais:**

  * `s_len`: tamanho da string original
  * `substr`: ponteiro para a substring recém-alocada
  * `i`: índice de iteração

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**
   Retorna `NULL` se `s` for `NULL`.

2. **Índice inicial além do tamanho da string:**
   Se `start >= s_len`, retorna uma string vazia com `ft_strdup("")`.

3. **Ajuste do comprimento:**
   Se `len` exceder os caracteres restantes a partir de `start`, é reduzido para caber na string.

4. **Verificação de alocação de memória:**
   Aloca `len + 1` bytes para a substring mais o terminador nulo. Retorna `NULL` se falhar.

---

### 🔄 Fluxo principal

1. **Cópia dos caracteres:**
   Percorre de `start` até `start + len`, copiando cada caractere para `substr`.

2. **Terminação da string:**
   Adiciona `'\0'` ao final para garantir que a substring seja válida.

3. **Retornar a substring:**
   A substring agora é independente e pronta para uso.

---

### 🔗 Contexto no get\_next\_line

No **get\_next\_line**, `ft_substr()` é amplamente utilizada para **extrair linhas do buffer de backup** e criar novos backups após a remoção de uma linha. Garante que cada linha retornada e o conteúdo restante do backup sejam corretamente alocados e independentes, prevenindo sobrescritas entre leituras.

---

### 📝 Exemplo prático

```c
const char *str = "Olá, mundo!";
char *sub = ft_substr(str, 5, 5);

// Resultado:
// sub = "mundo"
```

---

### 🎯 Conclusão

A função `ft_substr()` oferece uma forma **segura e eficiente de extrair substrings**, sendo essencial no `get_next_line` para separar linhas individuais do backup enquanto preserva o conteúdo restante.
