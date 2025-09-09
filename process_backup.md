# 📋 How `process_backup()` Works

The `process_backup()` function plays a key role in handling the **data stored between calls** to `get_next_line()`. It is declared with **internal linkage** (`static`), returns a dynamically allocated string (`char *`), and takes as parameter a **double pointer** to `backup`, allowing direct modification of the original pointer.

---

### 🗂️ Core Structure

* **Local variable `line`:**
  Serves as a temporary holder for the string to be returned.
* **Backup initialization:**
  If `backup` is `NULL`, it is initialized with an empty string (`ft_strdup("")`).

  * This ensures that `extract_line()` will always receive a valid string, preventing errors caused by dereferencing a null pointer.
  * If memory allocation fails at this point, the function returns `NULL`.

---

### 🔄 Main Flow

1. **Check backup content:**

   * If `backup` exists but does not yet contain a full line, nothing is returned immediately.
2. **Extracting the line:**

   * The function `extract_line()` is called with the current `backup`.
   * If a newline (`\n`) is found, a complete line is extracted (e.g., `"line1\n"`) and returned, while the `backup` is updated to hold the remaining data (e.g., `"line2\n"`).
   * If no newline is found, `extract_line()` returns `NULL`, signaling that more data needs to be read from the file before a complete line can be returned.

---

### 📝 Practical Scenarios

* **Scenario 1:**
  `backup = "line1\nline2\n"` → `line = "line1\n"`, updated `backup = "line2\n"`
* **Scenario 2:**
  `backup = "incomplete_line"` → `line = NULL`, `backup` remains unchanged

---

### 🎯 Conclusion

The `process_backup()` function ensures that every call to `get_next_line()` works with a **valid buffer**, safely handling cases where no prior data exists. Its main role is to **extract complete lines already stored** in the backup, or otherwise indicate that additional reads are required.

---

---

# 📋 Funcionamento da `process_backup()`

A função `process_backup()` tem papel fundamental no tratamento dos **dados armazenados entre chamadas** da `get_next_line()`. Ela é declarada com **ligação interna** (`static`), retorna uma string alocada dinamicamente (`char *`) e recebe como parâmetro um **ponteiro de ponteiro** para `backup`, permitindo modificar diretamente o ponteiro original.

---

### 🗂️ Estrutura de funcionamento

* **Variável local `line`:**
  Usada como espaço temporário para armazenar a string que será retornada.
* **Inicialização do backup:**
  Caso `backup` seja `NULL`, ele é inicializado com uma string vazia (`ft_strdup("")`).

  * Isso garante que `extract_line()` sempre receba uma string válida, evitando erros ao acessar ponteiros nulos.
  * Se a alocação falhar, a função retorna `NULL`.

---

### 🔄 Fluxo principal

1. **Verificação do conteúdo do backup:**

   * Se o `backup` existe mas ainda não contém uma linha completa, nada é retornado de imediato.
2. **Extração da linha:**

   * A função `extract_line()` é chamada com o `backup`.
   * Caso encontre um caractere de nova linha (`\n`), extrai a linha completa (exemplo: `"linha1\n"`) e a retorna, enquanto o `backup` é atualizado com o restante (exemplo: `"linha2\n"`).
   * Se não houver `\n`, `extract_line()` retorna `NULL`, indicando que é necessário ler mais dados do arquivo para formar uma linha completa.

---

### 📝 Cenários práticos

* **Cenário 1:**
  `backup = "linha1\nlinha2\n"` → `line = "linha1\n"`, `backup` atualizado = `"linha2\n"`
* **Cenário 2:**
  `backup = "linha_incompleta"` → `line = NULL`, `backup` permanece inalterado

---

### 🎯 Conclusão

A função `process_backup()` garante que cada chamada da `get_next_line()` trabalhe sempre com um **buffer válido**, tratando com segurança os casos em que não havia dados prévios. Seu papel principal é **extrair as linhas completas já armazenadas** no backup ou indicar que novas leituras são necessárias.

---
