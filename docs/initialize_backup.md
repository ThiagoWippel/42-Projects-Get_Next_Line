# 📋 How `initialize_backup()` Works

The `initialize_backup()` function ensures that the **backup pointer is properly initialized** before the main reading process begins in `get_next_line()`. It prevents errors by making sure the backup always points to valid memory, even when no data has been read yet.

---

### 🗂️ Core Structure

* **Input parameter:**
  `char **backup` → double pointer to the static buffer that stores unread content between calls.

* **Local variable:**
  `char *line` → temporarily stores a complete line if it can be extracted immediately.

---

### ✅ Validations

1. **Null backup check:**
   If `*backup` is `NULL`, it means no memory has been allocated yet. In this case, `ft_strdup("")` is called to assign an empty string to the backup.

   * If this allocation fails, the function returns `NULL`.

2. **Line extraction attempt:**
   Once the backup is guaranteed to be valid, the function calls `extract_line(backup)` to check if the backup already contains a complete line (ending with `\n`).

---

### 🔄 Main Flow

1. If `*backup` is uninitialized:

   * Allocate memory for an empty string (`""`).
   * Handle allocation failure by returning `NULL`.

2. Call `extract_line(backup)`:

   * If a full line exists in the backup, it is returned immediately.
   * If no line is found, the function simply returns `NULL`, signaling that reading from the file is required.

---

### 🔗 Context in get\_next\_line

This function is called at the very beginning of `get_next_line()`. Its purpose is to ensure **stability and continuity**:

* Prevents `extract_line()` from processing a null pointer.
* Handles the case where leftover data from previous calls already contains a complete line.

By isolating this logic, `get_next_line()` stays clean and focused on orchestrating the overall reading loop.

---

### 📝 Practical Example

```c
static char *backup = NULL;
char *line;

line = initialize_backup(&backup);

// Case 1: First call, backup = NULL
// backup becomes an empty string ("")
// line = NULL

// Case 2: Backup already has "line1\nline2\n"
// line = "line1\n", backup = "line2\n"
```

---

### 🎯 Conclusion

The `initialize_backup()` function guarantees that the backup is always in a **safe and usable state**. It acts as a preparatory step for `get_next_line()`, ensuring that either a valid line is returned immediately or the function can proceed to read new data with confidence.

---

# 📋 Funcionamento da `initialize_backup()`

A função `initialize_backup()` garante que o **ponteiro backup esteja corretamente inicializado** antes do início do processo principal de leitura em `get_next_line()`. Ela evita erros assegurando que o backup sempre aponte para uma área de memória válida, mesmo quando nenhum dado foi lido ainda.

---

### 🗂️ Estrutura de funcionamento

* **Parâmetro de entrada:**
  `char **backup` → ponteiro duplo para o buffer estático que armazena o conteúdo não processado entre chamadas.

* **Variável local:**
  `char *line` → armazena temporariamente uma linha completa, caso possa ser extraída imediatamente.

---

### ✅ Validações

1. **Verificação de backup nulo:**
   Se `*backup` for `NULL`, significa que nenhuma memória foi alocada ainda. Nesse caso, `ft_strdup("")` é chamado para atribuir uma string vazia ao backup.

   * Se a alocação falhar, a função retorna `NULL`.

2. **Tentativa de extração de linha:**
   Com o backup garantido como válido, a função chama `extract_line(backup)` para verificar se já existe uma linha completa armazenada (terminada em `\n`).

---

### 🔄 Fluxo principal

1. Se `*backup` não estiver inicializado:

   * Aloca memória para uma string vazia (`""`).
   * Em caso de falha na alocação, retorna `NULL`.

2. Chama `extract_line(backup)`:

   * Se encontrar uma linha completa no backup, ela é retornada imediatamente.
   * Se não houver linha, retorna `NULL`, indicando que será necessário ler do arquivo.

---

### 🔗 Contexto no get\_next\_line

Esta função é chamada logo no início de `get_next_line()`. Seu objetivo é garantir **estabilidade e continuidade**:

* Evita que `extract_line()` processe um ponteiro nulo.
* Trata o caso em que dados remanescentes de chamadas anteriores já contêm uma linha completa.

Ao isolar essa lógica, `get_next_line()` permanece mais limpo e focado na orquestração do loop de leitura.

---

### 📝 Exemplo prático

```c
static char *backup = NULL;
char *line;

line = initialize_backup(&backup);

// Caso 1: Primeira chamada, backup = NULL
// backup se torna uma string vazia ("")
// line = NULL

// Caso 2: Backup já contém "linha1\nlinha2\n"
// line = "linha1\n", backup = "linha2\n"
```

---

### 🎯 Conclusão

A função `initialize_backup()` garante que o backup esteja sempre em um **estado seguro e utilizável**. Ela funciona como uma etapa preparatória para `get_next_line()`, assegurando que uma linha válida seja retornada imediatamente, ou que o programa prossiga para ler novos dados com confiança.
