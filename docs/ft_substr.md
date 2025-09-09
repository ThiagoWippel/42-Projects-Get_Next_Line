# 📋 How `ft_substr()` Works

The `ft_substr()` function creates a **new string that is a substring** of the input string `s`, starting at the index `start` and extending up to `len` characters. Memory for the substring is **dynamically allocated**, and the result is null-terminated.

---

### 🗂️ Core Structure

* **Input parameters:**

  * `const char *s` → the original string.
  * `unsigned int start` → starting index for the substring.
  * `size_t len` → maximum length of the substring.

* **Return value:**

  * Pointer to the newly allocated substring.
  * `NULL` if `s` is invalid or memory allocation fails.
  * Returns an empty string if `start` is beyond the length of `s`.

---

### ✅ Validations

1. **Null pointer check:**

   * If `s` is `NULL`, the function returns `NULL`.

2. **Start index check:**

   * If `start` is greater than or equal to the length of `s`, an empty string is returned.

3. **Length adjustment:**

   * If `len` exceeds the remaining characters from `start` to the end of `s`, it is reduced to the actual remaining length.

---

### 🔄 Main Flow

1. Calculate the length of `s` using `ft_strlen()`.
2. Adjust `len` if necessary to avoid overflow beyond the end of the string.
3. Allocate memory for the substring including the null terminator.
4. Copy characters from `s` starting at `start` for `len` characters.
5. Append `'\0'` at the end.
6. Return the pointer to the new substring.

---

### 🔗 Context in get\_next\_line

In `get_next_line()`, `ft_substr()` is primarily used in **`extract_line()`** to retrieve the portion of the backup buffer corresponding to a single line, including the newline character. It is also used to update the backup by creating a substring with the remaining characters after a line is extracted. This ensures that each call to `get_next_line()` returns exactly one line while preserving leftover data safely.

---

### 📝 Practical Example

```c
const char *text = "Hello, world!";
char *sub = ft_substr(text, 7, 5);

// Result:
// sub = "world"
```

---

### 🎯 Conclusion

`ft_substr()` provides a safe and flexible way to extract portions of a string. Within `get_next_line()`, it is **vital for handling line extraction** and maintaining the integrity of the backup buffer.

---

# 📋 Funcionamento da `ft_substr()`

A função `ft_substr()` cria uma **nova string que é uma substring** da string de entrada `s`, começando no índice `start` e com até `len` caracteres. A memória para a substring é **alocada dinamicamente**, e a string resultante é terminada com `\0`.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**

  * `const char *s` → string original.
  * `unsigned int start` → índice inicial da substring.
  * `size_t len` → comprimento máximo da substring.

* **Valor de retorno:**

  * Ponteiro para a substring recém-alocada.
  * `NULL` se `s` for inválida ou a alocação de memória falhar.
  * Retorna uma string vazia se `start` for maior que o comprimento de `s`.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**

   * Se `s` for `NULL`, a função retorna `NULL`.

2. **Verificação do índice inicial:**

   * Se `start` for maior ou igual ao tamanho de `s`, retorna uma string vazia.

3. **Ajuste do comprimento:**

   * Se `len` exceder os caracteres restantes de `start` até o fim de `s`, ele é reduzido para o tamanho real disponível.

---

### 🔄 Fluxo principal

1. Calcula o tamanho de `s` usando `ft_strlen()`.
2. Ajusta `len`, se necessário, para não ultrapassar o final da string.
3. Aloca memória para a substring incluindo o terminador nulo.
4. Copia os caracteres de `s` começando em `start` por `len` caracteres.
5. Adiciona `'\0'` ao final.
6. Retorna o ponteiro para a nova substring.

---

### 🔗 Contexto no get\_next\_line

No `get_next_line()`, `ft_substr()` é usado principalmente em **`extract_line()`** para obter a parte do buffer de backup que corresponde a uma linha completa, incluindo o caractere de nova linha. Também é utilizado para atualizar o backup criando uma substring com os caracteres restantes após a extração da linha. Isso garante que cada chamada de `get_next_line()` retorne exatamente uma linha, preservando os dados restantes de forma segura.

---

### 📝 Exemplo prático

```c
const char *texto = "Olá, mundo!";
char *sub = ft_substr(texto, 5, 5);

// Resultado:
// sub = "mundo"
```

---

### 🎯 Conclusão

`ft_substr()` fornece uma maneira segura e flexível de extrair partes de uma string. Dentro do `get_next_line()`, é **fundamental para a extração de linhas** e para manter a integridade do buffer de backup.
