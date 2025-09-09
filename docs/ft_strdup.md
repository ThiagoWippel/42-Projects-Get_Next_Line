# 📋 How `ft_strdup()` Works

The `ft_strdup()` function is responsible for creating a **duplicate of a given string**, returning a newly allocated copy of it. This implementation mirrors the behavior of the standard `strdup()` function from the C library, ensuring that the returned string is stored in **independent memory**, which must later be freed by the caller.

---

### 🗂️ Core Structure

* **Input parameter:**
  `const char *s` → The string to be duplicated.
* **Local variables:**

  * `len`: holds the length of the original string, calculated using `ft_strlen()`.
  * `dup`: pointer to the new memory space where the copy will be stored.
  * `i`: iteration index used during the copying process.

---

### ✅ Validations

1. **Null pointer check:**
   If `s` is `NULL`, the function returns `NULL`, preventing invalid memory access.
2. **Memory allocation:**

   * The function allocates `len + 1` bytes to store the copy of the string plus the null terminator.
   * If memory allocation fails, it returns `NULL`.

---

### 🔄 Main Flow

1. **Copying characters:**

   * Each character from the original string is copied one by one into the allocated space (`dup[i] = s[i]`).
2. **String termination:**

   * After copying, the null terminator `\0` is explicitly added at the end to ensure proper string termination.

---

🔗 Context in get_next_line
In the get_next_line project, ft_strdup() is essential for safely handling lines. Since the reading buffer is reused across multiple calls, returning its direct content would be unsafe. By duplicating strings, ft_strdup() ensures that each extracted line remains preserved and independent, preventing overwriting in subsequent reads.

---

### 📝 Practical Example

```c
const char *original = "Hello, world!";
char *copy = ft_strdup(original);

// Result:
// copy = "Hello, world!" (stored in a new allocated space)
// original remains unchanged
```

---

### 🎯 Conclusion

The `ft_strdup()` function ensures the creation of an **independent copy** of a given string, making it useful whenever the original string may change or be freed, but the program still needs to preserve its contents.

---

---

# 📋 Funcionamento da `ft_strdup()`

A função `ft_strdup()` é responsável por criar uma **cópia de uma string fornecida**, retornando uma versão recém-alocada dela. Esta implementação reproduz o comportamento da função padrão `strdup()` da biblioteca C, garantindo que a string retornada esteja em um espaço de memória **independente**, que deve ser liberado posteriormente pelo chamador.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `const char *s` → String que será duplicada.
* **Variáveis locais:**

  * `len`: armazena o tamanho da string original, calculado com `ft_strlen()`.
  * `dup`: ponteiro para a nova área de memória onde a cópia será armazenada.
  * `i`: índice de iteração usado no processo de cópia.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**
   Se `s` for `NULL`, a função retorna `NULL`, evitando acessos inválidos à memória.
2. **Alocação de memória:**

   * A função aloca `len + 1` bytes para armazenar a cópia da string mais o caractere nulo terminador.
   * Se a alocação falhar, retorna `NULL`.

---

### 🔄 Fluxo principal

1. **Cópia dos caracteres:**

   * Cada caractere da string original é copiado um a um para o espaço alocado (`dup[i] = s[i]`).
2. **Terminação da string:**

   * Após a cópia, o terminador nulo `\0` é adicionado explicitamente no final para garantir o encerramento correto da string.

---

🔗 Contexto no get_next_line
No projeto get_next_line, ft_strdup() é essencial para manipular linhas de forma segura. Como o buffer utilizado nas leituras é reutilizado a cada chamada, retornar seu conteúdo diretamente seria inseguro. Ao duplicar as strings, ft_strdup() garante que cada linha extraída permaneça preservada e independente, evitando que seja sobrescrita pelo buffer em leituras subsequentes.

---

### 📝 Exemplo prático

```c
const char *original = "Olá, mundo!";
char *copia = ft_strdup(original);

// Resultado:
// copia = "Olá, mundo!" (armazenada em um novo espaço alocado)
// original permanece inalterada
```

---

### 🎯 Conclusão

A função `ft_strdup()` garante a criação de uma **cópia independente** de uma string fornecida, sendo útil sempre que a string original possa ser alterada ou liberada, mas ainda seja necessário preservar o seu conteúdo.

---
