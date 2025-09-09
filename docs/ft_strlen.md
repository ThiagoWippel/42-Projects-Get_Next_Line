# 📋 How `ft_strlen()` Works

The `ft_strlen()` function calculates the **length of a string**, excluding the null terminator. It first checks if the input pointer `s` is valid. If `s` is `NULL`, the function returns `0` to prevent invalid memory access.

---

### 🗂️ Core Structure

* **Input parameter:**
  `const char *s` → The string whose length will be calculated.
* **Local variables:**

  * `len`: counter to store the number of characters in the string.

---

### ✅ Validations

1. **Null pointer check:**
   If `s` is `NULL`, the function returns `0`, ensuring safety.

---

### 🔄 Main Flow

1. **Counting characters:**

   * Initializes `len` to 0.
   * Iterates through the string until the null terminator is reached, incrementing `len` for each character.

2. **Return length:**

   * After reaching the end, returns `len` representing the number of characters in the string.

---

### 🔗 Context in get\_next\_line

In the **get\_next\_line** project, `ft_strlen()` is extensively used to determine the size of buffers, backup contents, and lines. Knowing the exact length of a string is essential when allocating memory for duplicates or when manipulating the backup buffer, ensuring safety and correctness in each operation.

---

### 📝 Practical Example

```c
const char *str = "Hello, world!";
size_t length = ft_strlen(str);

// Result:
// length = 13
```

---

### 🎯 Conclusion

The `ft_strlen()` function provides a **reliable way to measure string length**, which is crucial in `get_next_line` for managing buffers and dynamic memory allocation safely.

---

# 📋 Funcionamento da `ft_strlen()`

A função `ft_strlen()` calcula o **tamanho de uma string**, desconsiderando o terminador nulo. Inicialmente, verifica se o ponteiro de entrada `s` é válido. Se `s` for `NULL`, a função retorna `0`, prevenindo acessos inválidos à memória.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `const char *s` → String cujo tamanho será calculado.
* **Variáveis locais:**

  * `len`: contador que armazenará o número de caracteres da string.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**
   Se `s` for `NULL`, a função retorna `0`, garantindo segurança.

---

### 🔄 Fluxo principal

1. **Contagem de caracteres:**

   * Inicializa `len` com 0.
   * Percorre a string até encontrar o terminador nulo, incrementando `len` a cada caractere.

2. **Retorno do tamanho:**

   * Ao final, retorna `len`, representando o número de caracteres da string.

---

### 🔗 Contexto no get\_next\_line

No projeto **get\_next\_line**, `ft_strlen()` é amplamente utilizada para determinar o tamanho de buffers, do conteúdo do backup e das linhas. Conhecer o tamanho exato da string é essencial ao alocar memória para cópias ou manipular o backup, garantindo segurança e precisão em cada operação.

---

### 📝 Exemplo prático

```c
const char *str = "Olá, mundo!";
size_t tamanho = ft_strlen(str);

// Resultado:
// tamanho = 11
```

---

### 🎯 Conclusão

A função `ft_strlen()` oferece uma forma **confiável de medir o tamanho de strings**, sendo fundamental no `get_next_line` para o gerenciamento seguro de buffers e da alocação dinâmica de memória.
