# 📋 How `ft_strchr()` Works

The `ft_strchr()` function searches for the **first occurrence of a character `c`** in a given string `s`. It returns a pointer to the character within the string, or `NULL` if the character is not found. The search includes the null terminator `\0`, allowing the function to locate the end of the string when needed.

---

### 🗂️ Core Structure

* **Input parameters:**
  `const char *s` → the string to search in
  `int c` → the character to find

* **Local variables:** None (pointer arithmetic is used directly)

---

### ✅ Validations

1. **Null pointer check:**
   If `s` is `NULL`, the function returns `NULL` immediately to prevent invalid memory access.

---

### 🔄 Main Flow

1. **Iterate through the string:**

   * Check each character in `s`.
   * If a character matches `c`, return a pointer to that position.

2. **Check the null terminator:**

   * If `c` is `'\0'`, return a pointer to the string’s null terminator.

3. **Character not found:**

   * If no match is found, return `NULL`.

---

### 🔗 Context in get\_next\_line

In **get\_next\_line**, `ft_strchr()` is used to **detect the presence of a newline character `\n`** in the backup buffer. This detection is crucial for functions like `extract_line()` to determine whether a complete line is available for extraction or if further reading is needed.

---

### 📝 Practical Example

```c
const char *str = "Hello, world!";
char *pos = ft_strchr(str, 'o');

// Result:
// pos points to the first 'o' in "Hello, world!"
```

---

### 🎯 Conclusion

The `ft_strchr()` function provides a **reliable way to locate characters within a string**, which is essential in `get_next_line` for identifying line boundaries and ensuring proper line extraction.

---

# 📋 Funcionamento da `ft_strchr()`

A função `ft_strchr()` procura a **primeira ocorrência de um caractere `c`** em uma string `s`. Retorna um ponteiro para o caractere encontrado na string, ou `NULL` caso não seja encontrado. A busca inclui o terminador nulo `\0`, permitindo localizar o fim da string quando necessário.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**
  `const char *s` → string onde será feita a busca
  `int c` → caractere a ser localizado

* **Variáveis locais:** Nenhuma (usa-se aritmética de ponteiros)

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**
   Se `s` for `NULL`, a função retorna `NULL` imediatamente, evitando acessos inválidos à memória.

---

### 🔄 Fluxo principal

1. **Percorrer a string:**

   * Verifica cada caractere de `s`.
   * Se encontrar `c`, retorna um ponteiro para sua posição.

2. **Verificar o terminador nulo:**

   * Se `c` for `'\0'`, retorna um ponteiro para o terminador nulo da string.

3. **Caractere não encontrado:**

   * Caso não haja correspondência, retorna `NULL`.

---

### 🔗 Contexto no get\_next\_line

No **get\_next\_line**, `ft_strchr()` é utilizada para **detectar a presença de um caractere de nova linha `\n`** no buffer de backup. Essa detecção é essencial para funções como `extract_line()`, que precisam determinar se há uma linha completa disponível para extração ou se é necessário ler mais dados do arquivo.

---

### 📝 Exemplo prático

```c
const char *str = "Olá, mundo!";
char *pos = ft_strchr(str, 'o');

// Resultado:
// pos aponta para o primeiro 'o' em "Olá, mundo!"
```

---

### 🎯 Conclusão

A função `ft_strchr()` fornece uma forma **confiável de localizar caracteres dentro de uma string**, sendo fundamental no `get_next_line` para identificar limites de linhas e garantir a extração correta.
