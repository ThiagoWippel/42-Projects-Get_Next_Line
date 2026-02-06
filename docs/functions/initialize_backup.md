### 💻 Implementation

```c
static char	*initialize_backup(char **backup)
{
	char	*line;

	if (!*backup)
	{
		*backup = ft_strdup("");
		if (!*backup)
			return (NULL);
	}
	line = extract_line(backup);
	return (line);
}
```

---

### 📋 How it works

The `initialize_backup()` function **ensures that the backup buffer is properly initialized** before reading from the file descriptor. If no backup exists, it creates an empty string. It also attempts to extract a line immediately if the backup already contains data.

**Input parameters:**

* `char **backup` → pointer to the backup buffer

**Return value:**

* Pointer to the extracted line if one exists
* `NULL` if memory allocation fails or no line is present

**Validations:**

1. Checks if `*backup` is `NULL`; if so, allocates an empty string.
2. Uses `extract_line()` to immediately return a line if the backup already contains a newline.

**Main Flow:**

1. Verify if the backup exists; allocate empty string if not.
2. Attempt to extract a line using `extract_line()`.
3. Return the extracted line or `NULL`.

**Context in `get_next_line()`:**
This function is called at the start of `get_next_line()` to **prepare the backup buffer**. It guarantees that the buffer is valid and allows immediate return of a line if present, streamlining the reading process.

**Example:**

```c
char *backup = NULL;
char *line = initialize_backup(&backup);
// line is NULL because backup is initially empty
// backup now points to an empty string
```

---

### 📋 Como funciona

A função `initialize_backup()` **garante que o buffer de backup esteja corretamente inicializado** antes da leitura do descritor de arquivo. Se não existir backup, cria uma string vazia. Ela também tenta extrair imediatamente uma linha caso o backup já contenha dados.

**Parâmetros de entrada:**

* `char **backup` → ponteiro para o buffer de backup

**Valor de retorno:**

* Ponteiro para a linha extraída, se existir
* `NULL` se a alocação falhar ou não houver linha

**Validações:**

1. Verifica se `*backup` é `NULL`; se sim, aloca uma string vazia.
2. Utiliza `extract_line()` para retornar imediatamente uma linha se o backup contiver nova linha.

**Fluxo principal:**

1. Verifica se o backup existe; aloca string vazia se não existir.
2. Tenta extrair uma linha com `extract_line()`.
3. Retorna a linha extraída ou `NULL`.

**Contexto no `get_next_line()`:**
Esta função é chamada no início de `get_next_line()` para **preparar o buffer de backup**. Ela garante que o buffer seja válido e permite retorno imediato de uma linha, agilizando o processo de leitura.

**Exemplo prático:**

```c
char *backup = NULL;
char *linha = initialize_backup(&backup);
// linha é NULL porque o backup inicialmente está vazio
// backup agora aponta para uma string vazia
```

**Conclusão:**
`initialize_backup()` assegura a **preparação segura e eficiente do buffer de backup**, facilitando a leitura de linhas e evitando problemas de alocação em `get_next_line()`.
