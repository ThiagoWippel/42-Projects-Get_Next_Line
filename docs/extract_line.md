### 💻 Implementation

```c
static char	*extract_line(char **backup)
{
	char	*newline_pos;
	char	*line;
	char	*temp;
	size_t	line_len;

	newline_pos = ft_strchr(*backup, '\n');
	if (!newline_pos)
		return (NULL);
	line_len = newline_pos - *backup + 1;
	line = ft_substr(*backup, 0, line_len);
	if (!line)
		return (NULL);
	temp = ft_substr(*backup, line_len, ft_strlen(*backup) - line_len);
	free(*backup);
	*backup = temp;
	return (line);
}
```

---

### 📋 How it works

The `extract_line()` function **extracts a single line** from the backup buffer, including the newline character. It updates the backup to contain the remaining content after the extracted line.

**Input parameter:**

* `char **backup` → pointer to the backup buffer containing accumulated text

**Return value:**

* Pointer to the newly allocated string containing the extracted line
* `NULL` if no newline is found or memory allocation fails

**Validations:**

1. Checks if a newline character exists in the backup
2. Returns `NULL` immediately if no newline is found

**Main Flow:**

1. Find the position of the first newline character in the backup using `ft_strchr()`.
2. Calculate the length of the line to extract, including the newline.
3. Allocate and copy the line into a new string using `ft_substr()`.
4. Allocate a new string for the remaining content after the extracted line.
5. Free the old backup and update it with the remaining content.
6. Return the extracted line.

**Context in `get_next_line()`:**
Used to **return complete lines** from the backup buffer. Each call to `get_next_line()` relies on `extract_line()` to provide the next line and update the backup correctly for subsequent reads.

**Example:**

```c
char *backup = ft_strdup("Hello\nWorld\n");
char *line = extract_line(&backup);
// line points to "Hello\n"
// backup now contains "World\n"
free(line);
free(backup);
```

**Conclusion:**
`extract_line()` is a core utility in `get_next_line()`, enabling **line-by-line reading** by splitting the backup buffer safely and efficiently.

---

### 📋 Como funciona

A função `extract_line()` **extrai uma linha única** do buffer de backup, incluindo o caractere de nova linha. Ela atualiza o backup para conter o conteúdo restante após a linha extraída.

**Parâmetro de entrada:**

* `char **backup` → ponteiro para o buffer de backup contendo o texto acumulado

**Valor de retorno:**

* Ponteiro para a nova string contendo a linha extraída
* `NULL` se não houver nova linha ou se a alocação falhar

**Validações:**

1. Verifica se existe um caractere de nova linha no backup
2. Retorna `NULL` imediatamente se não encontrar

**Fluxo principal:**

1. Localiza a posição da primeira nova linha no backup usando `ft_strchr()`.
2. Calcula o tamanho da linha a ser extraída, incluindo o `\n`.
3. Aloca e copia a linha para uma nova string usando `ft_substr()`.
4. Aloca uma nova string para o conteúdo restante após a linha extraída.
5. Libera o backup antigo e atualiza-o com o conteúdo restante.
6. Retorna a linha extraída.

**Contexto no `get_next_line()`:**
Usada para **retornar linhas completas** do buffer de backup. Cada chamada de `get_next_line()` depende de `extract_line()` para fornecer a próxima linha e atualizar o backup corretamente para leituras subsequentes.

**Exemplo prático:**

```c
char *backup = ft_strdup("Olá\nMundo\n");
char *linha = extract_line(&backup);
// linha aponta para "Olá\n"
// backup agora contém "Mundo\n"
free(linha);
free(backup);
```

**Conclusão:**
`extract_line()` é uma função essencial em `get_next_line()`, permitindo a leitura **linha a linha** ao dividir o buffer de backup de forma segura e eficiente.
