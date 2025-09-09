# 📋 How `ft_strchr()` Works

The `ft_strchr()` function searches for the **first occurrence of a character** `c` in the string `s`. If the character is found, it returns a pointer to its position within the string; otherwise, it returns `NULL`. This implementation also includes a safety check to handle `NULL` input strings gracefully.

---

### 🗂️ Core Structure

* **Input parameters:**

  * `const char *s` → the string to be searched.
  * `int c` → the character to locate (interpreted as an `unsigned char`).

* **Return value:**

  * Pointer to the first occurrence of `c` in `s`.
  * Pointer to the null terminator (`'\0'`) if `c` is `'\0'`.
  * `NULL` if the character is not found or if `s` is invalid.

---

### ✅ Validations

1. **Null pointer check:**

   * If `s` is `NULL`, the function immediately returns `NULL`.

---

### 🔄 Main Flow

1. Traverse the string character by character.
2. At each position, compare `*s` with `c`.
3. If a match is found, return a pointer to that position.
4. If no match is found before the null terminator:

   * Return a pointer to the null terminator if `c == '\0'`.
   * Otherwise, return `NULL`.

---

### 🔗 Context in get\_next\_line

In the `get_next_line()` project, `ft_strchr()` plays a **key role** in detecting when a newline character (`'\n'`) exists in the backup buffer. This allows the function `extract_line()` to determine whether a complete line is ready to be returned, making `ft_strchr()` a **fundamental utility** for line extraction.

---

### 📝 Practical Example

```c
const char *text = "Hello\nWorld";
char *pos = ft_strchr(text, '\n');

// Result:
// pos points to the '\n' character within "Hello\nWorld"
```

---

### 🎯 Conclusion

The `ft_strchr()` function provides a reliable way to locate characters within a string. Its usage in `get_next_line()` is essential for identifying line boundaries, enabling the function to return text incrementally and correctly.

---

# 📋 Funcionamento da `ft_strchr()`

A função `ft_strchr()` procura pela **primeira ocorrência de um caractere** `c` na string `s`. Se o caractere for encontrado, retorna um ponteiro para sua posição na string; caso contrário, retorna `NULL`. Esta implementação também inclui uma verificação de segurança para lidar com strings `NULL`.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**

  * `const char *s` → string onde será feita a busca.
  * `int c` → caractere a ser localizado (interpretado como `unsigned char`).

* **Valor de retorno:**

  * Ponteiro para a primeira ocorrência de `c` em `s`.
  * Ponteiro para o terminador nulo (`'\0'`) se `c` for `'\0'`.
  * `NULL` se o caractere não for encontrado ou se `s` for inválida.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**

   * Se `s` for `NULL`, a função retorna imediatamente `NULL`.

---

### 🔄 Fluxo principal

1. Percorre a string caractere por caractere.
2. Em cada posição, compara `*s` com `c`.
3. Se houver correspondência, retorna um ponteiro para essa posição.
4. Se não encontrar antes do terminador nulo:

   * Retorna um ponteiro para o terminador nulo se `c == '\0'`.
   * Caso contrário, retorna `NULL`.

---

### 🔗 Contexto no get\_next\_line

No projeto `get_next_line()`, `ft_strchr()` tem papel **fundamental** na detecção de quebras de linha (`'\n'`) dentro do buffer de backup. Isso permite que a função `extract_line()` determine se já existe uma linha completa pronta para ser retornada, tornando `ft_strchr()` uma **utilidade essencial** para a extração de linhas.

---

### 📝 Exemplo prático

```c
const char *texto = "Olá\nMundo";
char *pos = ft_strchr(texto, '\n');

// Resultado:
// pos aponta para o caractere '\n' dentro de "Olá\nMundo"
```

---

### 🎯 Conclusão

A função `ft_strchr()` oferece uma forma confiável de localizar caracteres em uma string. Seu uso em `get_next_line()` é crucial para identificar limites de linhas, permitindo que a função retorne o texto de forma incremental e correta.
