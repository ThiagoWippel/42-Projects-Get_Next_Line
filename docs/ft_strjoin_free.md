# 📋 How `ft_strjoin_free()` Works

The `ft_strjoin_free()` function concatenates two strings, `s1` and `s2`, into a **new dynamically allocated string**. After joining, it **frees the memory previously allocated for `s1`**, helping manage memory efficiently and preventing leaks. This is particularly useful in scenarios where strings are progressively built or updated, as in the `get_next_line()` project.

---

### 🗂️ Core Structure

* **Input parameters:**

  * `char *s1` → the first string, which will be freed after joining.
  * `const char *s2` → the second string to append to `s1`.

* **Return value:**

  * Pointer to the new string containing the concatenation of `s1` and `s2`.
  * Returns `s1` if `s2` is `NULL`.
  * Returns `NULL` if memory allocation fails.

---

### ✅ Validations

1. **Null pointer handling:**

   * If `s2` is `NULL`, the function simply returns `s1`.
   * If `s1` is `NULL`, the function duplicates `s2` using `ft_strdup()`.

2. **Memory allocation:**

   * Allocates enough space for `len1 + len2 + 1` characters, including the null terminator.
   * If allocation fails, frees `s1` and returns `NULL`.

---

### 🔄 Main Flow

1. Calculate the lengths of `s1` and `s2` using `ft_strlen()`.
2. Allocate memory for the new concatenated string.
3. Copy characters from `s1` into the new string.
4. Append characters from `s2` after the content of `s1`.
5. Terminate the new string with `'\0'`.
6. Free the memory of `s1`.
7. Return the pointer to the new joined string.

---

### 🔗 Context in get\_next\_line

In `get_next_line()`, `ft_strjoin_free()` is primarily used in **`read_buffer()`** to append newly read data to the backup buffer. By freeing the previous backup (`s1`) after concatenation, it ensures that memory usage remains controlled while accumulating content until a complete line can be extracted. This makes it **crucial for incremental reading and memory safety**.

---

### 📝 Practical Example

```c
char *backup = ft_strdup("Hello");
backup = ft_strjoin_free(backup, ", world!");

// Result:
// backup = "Hello, world!" (s1 memory freed)
```

---

### 🎯 Conclusion

`ft_strjoin_free()` enables **safe and efficient string concatenation** with automatic memory management for the first string. In the context of `get_next_line()`, it is essential for building the backup buffer as data is read from a file.

---

# 📋 Funcionamento da `ft_strjoin_free()`

A função `ft_strjoin_free()` concatena duas strings, `s1` e `s2`, em uma **nova string alocada dinamicamente**. Após a concatenação, ela **libera a memória previamente alocada para `s1`**, ajudando a gerenciar a memória de forma eficiente e evitando vazamentos. Isso é especialmente útil quando strings são construídas ou atualizadas progressivamente, como no projeto `get_next_line()`.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetros de entrada:**

  * `char *s1` → primeira string, que será liberada após a concatenação.
  * `const char *s2` → segunda string a ser adicionada após `s1`.

* **Valor de retorno:**

  * Ponteiro para a nova string contendo a concatenação de `s1` e `s2`.
  * Retorna `s1` se `s2` for `NULL`.
  * Retorna `NULL` se a alocação de memória falhar.

---

### ✅ Validações

1. **Tratamento de ponteiros nulos:**

   * Se `s2` for `NULL`, a função retorna simplesmente `s1`.
   * Se `s1` for `NULL`, a função duplica `s2` usando `ft_strdup()`.

2. **Alocação de memória:**

   * Aloca espaço suficiente para `len1 + len2 + 1` caracteres, incluindo o terminador nulo.
   * Se a alocação falhar, libera `s1` e retorna `NULL`.

---

### 🔄 Fluxo principal

1. Calcula os comprimentos de `s1` e `s2` usando `ft_strlen()`.
2. Aloca memória para a nova string concatenada.
3. Copia os caracteres de `s1` para a nova string.
4. Adiciona os caracteres de `s2` após o conteúdo de `s1`.
5. Finaliza a nova string com `'\0'`.
6. Libera a memória de `s1`.
7. Retorna o ponteiro para a nova string concatenada.

---

### 🔗 Contexto no get\_next\_line

No `get_next_line()`, `ft_strjoin_free()` é usado principalmente em **`read_buffer()`** para adicionar os novos dados lidos ao buffer de backup. Ao liberar o backup anterior (`s1`) após a concatenação, garante que o uso de memória seja controlado enquanto o conteúdo é acumulado até que uma linha completa possa ser extraída. Isso o torna **crucial para a leitura incremental e segurança de memória**.

---

### 📝 Exemplo prático

```c
char *backup = ft_strdup("Olá");
backup = ft_strjoin_free(backup, ", mundo!");

// Resultado:
// backup = "Olá, mundo!" (memória de s1 liberada)
```

---

### 🎯 Conclusão

`ft_strjoin_free()` permite a **concatenação segura e eficiente de strings**, com gerenciamento automático da memória da primeira string. No contexto do `get_next_line()`, é essencial para construir o buffer de backup à medida que os dados são lidos de um arquivo.
