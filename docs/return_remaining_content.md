# 📋 How `return_remaining_content()` Works

The `return_remaining_content()` function is responsible for handling the **end-of-file (EOF) condition** in `get_next_line()`. When no more data can be read from the file descriptor, this function ensures that any leftover content in the backup is properly returned as the final line.

---

### 🗂️ Core Structure

* **Input parameter:**
  `char **backup` → double pointer to the buffer that stores any data not yet returned to the user.

* **Local variable:**
  `char *line` → pointer used to store and return the final string.

---

### ✅ Validations

1. **Empty or null backup:**

   * If `*backup` is `NULL` or points to an empty string (`""`), there is no data left to return.
   * In this case, the memory is freed, `backup` is reset to `NULL`, and the function returns `NULL`.

2. **Content available in backup:**

   * If there is still content in the backup, it is duplicated into a new string using `ft_strdup()`.
   * The old backup is then freed and reset to `NULL`.

---

### 🔄 Main Flow

1. Check if `backup` is `NULL` or empty.

   * If true → free it and return `NULL`.

2. If not empty →

   * Duplicate the remaining string (`ft_strdup`).
   * Free the original backup.
   * Return the duplicated string as the last line.

---

### 🔗 Context in get\_next\_line

This function is called when `read()` returns `0`, meaning there is no more data to read from the file descriptor. Its role is to **return the remaining buffered content once and clean up memory**.

---

### 📝 Practical Example

```c
// Suppose backup = "last_line_without_newline"
char *line = return_remaining_content(&backup);

// line = "last_line_without_newline"
// backup = NULL
```

---

### 🎯 Conclusion

The `return_remaining_content()` function ensures that when the file reaches EOF, any **remaining content in the buffer is safely returned** as the final line. It also performs **memory cleanup** by freeing the backup pointer, preventing memory leaks and leaving the buffer in a consistent state.

---

# 📋 Funcionamento da `return_remaining_content()`

A função `return_remaining_content()` é responsável por lidar com a condição de **fim de arquivo (EOF)** em `get_next_line()`. Quando não há mais dados a serem lidos do descritor de arquivo, essa função garante que o conteúdo restante no backup seja retornado corretamente como a última linha.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `char **backup` → ponteiro duplo para o buffer que armazena dados ainda não retornados ao usuário.

* **Variável local:**
  `char *line` → ponteiro usado para armazenar e retornar a string final.

---

### ✅ Validações

1. **Backup nulo ou vazio:**

   * Se `*backup` for `NULL` ou apontar para uma string vazia (`""`), não há mais dados a serem retornados.
   * Nesse caso, a memória é liberada, `backup` é resetado para `NULL` e a função retorna `NULL`.

2. **Conteúdo disponível no backup:**

   * Se ainda houver conteúdo, ele é duplicado em uma nova string com `ft_strdup()`.
   * O backup antigo é então liberado e resetado para `NULL`.

---

### 🔄 Fluxo principal

1. Verifica se `backup` é `NULL` ou vazio.

   * Se verdadeiro → libera e retorna `NULL`.

2. Caso contrário →

   * Duplica a string restante (`ft_strdup`).
   * Libera o backup original.
   * Retorna a string duplicada como última linha.

---

### 🔗 Contexto no get\_next\_line

Essa função é chamada quando `read()` retorna `0`, indicando que não há mais dados a serem lidos do descritor de arquivo. Seu papel é **retornar o conteúdo armazenado no buffer e realizar a limpeza de memória**.

---

### 📝 Exemplo prático

```c
// Suponha que backup = "ultima_linha_sem_newline"
char *line = return_remaining_content(&backup);

// line = "ultima_linha_sem_newline"
// backup = NULL
```

---

### 🎯 Conclusão

A função `return_remaining_content()` garante que, ao chegar no EOF, qualquer **conteúdo remanescente no buffer seja retornado com segurança** como a última linha. Ela também realiza a **liberação da memória** do backup, evitando vazamentos e mantendo o estado consistente.
