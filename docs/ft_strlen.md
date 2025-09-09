# 📋 How `ft_strlen()` Works

The `ft_strlen()` function calculates the **length of a string** by counting the number of characters until the null terminator (`'\0'`) is found. Unlike the standard library implementation, this version includes an additional safety check for `NULL` pointers, returning `0` when the input string is invalid.

---

### 🗂️ Core Structure

* **Input parameter:**

  * `const char *s` → pointer to the string whose length is to be calculated.

* **Local variables:**

  * `size_t len` → counter that stores the number of characters encountered before the null terminator.

---

### ✅ Validations

1. **Null pointer check:**

   * If `s` is `NULL`, the function immediately returns `0`, avoiding undefined behavior.

---

### 🔄 Main Flow

1. Initialize `len` as `0`.
2. Traverse the string character by character.
3. Stop when the null terminator `'\0'` is found.
4. Return the value stored in `len`, which represents the string length.

---

### 🔗 Context in get\_next\_line

Within the `get_next_line()` project, `ft_strlen()` is widely used in helper functions such as `ft_strdup()`, `ft_substr()`, and `ft_strjoin_free()`. It provides the **fundamental size information** needed to correctly allocate memory when copying, joining, or trimming strings.

---

### 📝 Practical Example

```c
const char *text = "Hello!";
size_t length = ft_strlen(text);

// Result:
// length = 6
```

---

### 🎯 Conclusion

The `ft_strlen()` function ensures a safe and efficient way to calculate the length of a string, supporting other core utilities in `get_next_line()` that depend on precise memory management.

---

# 📋 Funcionamento da `ft_strlen()`

A função `ft_strlen()` calcula o **comprimento de uma string** contando o número de caracteres até encontrar o terminador nulo (`'\0'`). Diferente da implementação da biblioteca padrão, esta versão inclui uma verificação extra de ponteiro `NULL`, retornando `0` quando a string de entrada é inválida.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**

  * `const char *s` → ponteiro para a string cujo comprimento será calculado.

* **Variáveis locais:**

  * `size_t len` → contador que armazena o número de caracteres encontrados antes do terminador nulo.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**

   * Se `s` for `NULL`, a função retorna imediatamente `0`, evitando comportamento indefinido.

---

### 🔄 Fluxo principal

1. Inicializa `len` como `0`.
2. Percorre a string caractere por caractere.
3. Para ao encontrar o terminador nulo `'\0'`.
4. Retorna o valor armazenado em `len`, que representa o tamanho da string.

---

### 🔗 Contexto no get\_next\_line

Dentro do projeto `get_next_line()`, `ft_strlen()` é amplamente utilizada em funções auxiliares como `ft_strdup()`, `ft_substr()` e `ft_strjoin_free()`. Ela fornece a **informação fundamental de tamanho** necessária para a correta alocação de memória ao copiar, juntar ou recortar strings.

---

### 📝 Exemplo prático

```c
const char *texto = "Olá!";
size_t tamanho = ft_strlen(texto);

// Resultado:
// tamanho = 4
```

---

### 🎯 Conclusão

A função `ft_strlen()` garante uma forma segura e eficiente de calcular o comprimento de uma string, dando suporte a outras utilidades centrais do `get_next_line()` que dependem de gerenciamento preciso de memória.
