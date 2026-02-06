### 💻 Implementation

```c
char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	int			read_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = initialize_backup(&backup);
	if (line)
		return (line);
	while (1)
	{
		read_result = read_buffer(fd, &backup);
		if (read_result == -1)
		{
			free(backup);
			backup = NULL;
			return (NULL);
		}
		if (read_result == 0)
			return (return_remaining_content(&backup));
		line = extract_line(&backup);
		if (line)
			return (line);
	}
}
```

---

### 📋 How it works

The `get_next_line()` function **reads the next line from a file descriptor** `fd` each time it is called. It uses a static backup buffer to store leftover data between calls, ensuring lines are returned incrementally and memory is safely managed.

**Input parameters:**

* `int fd` → file descriptor to read from

**Return value:**

* Pointer to the next line, including the newline character if present
* `NULL` if end-of-file is reached, an error occurs, or `fd`/`BUFFER_SIZE` is invalid

**Validations:**

1. Checks if `fd` is negative or `BUFFER_SIZE` is invalid.
2. Initializes the backup buffer using `initialize_backup()`.
3. Handles errors from `read_buffer()` and frees memory as needed.
4. Returns remaining content at end-of-file using `return_remaining_content()`.

**Main Flow:**

1. Validate `fd` and `BUFFER_SIZE`.
2. Attempt to extract a line immediately from the backup.
3. Enter a loop:

   * Read from the file descriptor into the backup using `read_buffer()`.
   * If an error occurs, free backup and return `NULL`.
   * If end-of-file is reached, return remaining content.
   * Attempt to extract a line from backup; return if found.

**Context in `get_next_line()`:**
This is the **core function** of the project. It orchestrates reading from the file descriptor, manages the backup buffer, handles memory safely, and ensures lines are returned correctly on each call.

**Example:**

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

### 📋 Como funciona

A função `get_next_line()` **lê a próxima linha de um descritor de arquivo** `fd` a cada chamada. Ela utiliza um buffer de backup estático para armazenar dados remanescentes entre chamadas, garantindo que as linhas sejam retornadas incrementalmente e a memória seja gerenciada com segurança.

**Parâmetros de entrada:**

* `int fd` → descritor de arquivo para leitura

**Valor de retorno:**

* Ponteiro para a próxima linha, incluindo o caractere de nova linha, se presente
* `NULL` se o fim do arquivo for alcançado, ocorrer erro, ou `fd`/`BUFFER_SIZE` for inválido

**Validações:**

1. Verifica se `fd` é negativo ou `BUFFER_SIZE` inválido.
2. Inicializa o buffer de backup usando `initialize_backup()`.
3. Trata erros de `read_buffer()` e libera memória conforme necessário.
4. Retorna o conteúdo restante ao final do arquivo usando `return_remaining_content()`.

**Fluxo principal:**

1. Valida `fd` e `BUFFER_SIZE`.
2. Tenta extrair uma linha imediatamente do backup.
3. Entra em um loop:

   * Lê do descritor para o backup usando `read_buffer()`.
   * Em caso de erro, libera backup e retorna `NULL`.
   * Se atingir fim do arquivo, retorna o conteúdo restante.
   * Tenta extrair uma linha do backup; retorna se encontrada.

**Contexto no `get_next_line()`:**
Esta é a **função principal** do projeto. Ela orquestra a leitura do arquivo, gerencia o buffer de backup, assegura a alocação e liberação correta da memória e garante que as linhas sejam retornadas corretamente a cada chamada.

**Exemplo prático:**

```c
int fd = open("arquivo.txt", O_RDONLY);
char *linha;

while ((linha = get_next_line(fd)))
{
    printf("%s", linha);
    free(linha);
}
close(fd);
```

**Conclusão:**
`get_next_line()` implementa uma **leitura incremental segura de linhas**, com gerenciamento eficiente de memória e manipulação correta do buffer de backup, sendo a função central do projeto.
