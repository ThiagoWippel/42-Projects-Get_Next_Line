# 📋 How `ft_strdup()` Works

The `ft_strdup()` function creates a **new copy of the given string** `s`. It allocates memory dynamically, duplicates all characters from the original string, and appends a null terminator `\0` at the end. This ensures that the new string is **independent** of the original, preventing unintended modifications.

---

### 🗂️ Core Structure

* **Input parameter:**

  * `const char *s` → the string to duplicate.

* **Return value:**

  * Pointer to the newly allocated copy of `s`.
  * `NULL` if `s` is invalid or if memory allocation fails.

---

### ✅ Validations

1. **Null pointer check:**

   * If `s` is `NULL`, the function returns `NULL`.

2. **Memory allocation check:**

   * If memory allocation fails, the function returns `NULL`.

---

### 🔄 Main Flow

1. Calculate the length of `s` using `ft_strlen()`.
2. Allocate memory for a copy including the null terminator.
3. Copy each character from `s` into the new memory.
4. Append `'\0'` to terminate the string.
5. Return the pointer to the duplicated string.

---

### 🔗 Context in get\_next\_line

In the `get_next_line()` project, `ft_strdup()` is essential for **initializing the backup buffer**. When no previous backup exists, `ft_strdup("")` is used to start with a valid empty string. It is also used to **duplicate remaining content** at the end of the file before freeing the original backup, ensuring that no data is lost and memory safety is maintained.

---

### 📝 Practical Example

```c
char *original = "Hello, world!";
char *copy = ft_strdup(original);

// Result:
// copy points to a new allocated string "Hello, world!"
// Modifying 'copy' does not affect 'original'
```

---

### 🎯 Conclusion

`ft_strdup()` guarantees safe string duplication, providing an independent copy in dynamically allocated memory. In `get_next_line()`, it is a **key utility** for buffer initialization and safe handling of remaining data.

---

# 📋 Funcionamento da `ft_strdup()`

A função `ft_strdup()` cria uma **nova cópia da string fornecida** `s`. Ela aloca memória dinamicamente, duplica todos os caracteres da string original e adiciona um terminador nulo `\0` no final. Isso garante que a nova string seja **independente** da original, prevenindo alterações não intencionais.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**

  * `const char *s` → string a ser duplicada.

* **Valor de retorno:**

  * Ponteiro para a nova cópia alocada de `s`.
  * `NULL` se `s` for inválida ou se a alocação de memória falhar.

---

### ✅ Validações

1. **Verificação de ponteiro nulo:**

   * Se `s` for `NULL`, a função retorna `NULL`.

2. **Verificação de alocação:**

   * Se a alocação de memória falhar, a função retorna `NULL`.

---

### 🔄 Fluxo principal

1. Calcula o tamanho de `s` usando `ft_strlen()`.
2. Aloca memória para a cópia, incluindo o terminador nulo.
3. Copia cada caractere de `s` para o novo espaço.
4. Adiciona `'\0'` para finalizar a string.
5. Retorna o ponteiro para a string duplicada.

---

### 🔗 Contexto no get\_next\_line

No projeto `get_next_line()`, `ft_strdup()` é essencial para **inicializar o buffer de backup**. Quando não existe backup anterior, utiliza-se `ft_strdup("")` para criar uma string vazia válida. Também é usada para **duplicar o conteúdo restante** ao final do arquivo antes de liberar o backup original, garantindo que nenhum dado seja perdido e mantendo a segurança da memória.

---

### 📝 Exemplo prático

```c
char *original = "Olá, mundo!";
char *copia = ft_strdup(original);

// Resultado:
// copia aponta para uma nova string alocada "Olá, mundo!"
// Alterar 'copia' não modifica 'original'
```

---

### 🎯 Conclusão

`ft_strdup()` garante a duplicação segura de strings, fornecendo uma cópia independente em memória alocada dinamicamente. No `get_next_line()`, é uma **utilidade chave** para inicialização de buffers e manipulação segura dos dados restantes.
