### 💻 Implementation

```c
static int	read_buffer(int fd, char **backup)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	*backup = ft_strjoin_free(*backup, buffer);
	free(buffer);
	if (!*backup)
		return (-1);
	return (bytes_read);
}
```

---

### 📋 How it works

The `read_buffer()` function **reads data from a file descriptor** into a temporary buffer and appends it to the backup buffer. It handles dynamic memory safely and ensures the backup grows as new content is read.

**Input parameters:**

* `int fd` → file descriptor to read from
* `char **backup` → pointer to the backup buffer that accumulates data

**Return value:**

* Number of bytes read (>0)
* `0` if end-of-file is reached
* `-1` if an error occurs (allocation failure or read error)

**Validations:**

1. Allocates a temporary buffer and checks for `NULL`.
2. Checks the return value of `read()` to handle EOF or errors.
3. Checks that the backup buffer is successfully updated with `ft_strjoin_free()`.

**Main Flow:**

1. Allocate a temporary buffer of size `BUFFER_SIZE + 1`.
2. Read up to `BUFFER_SIZE` bytes from the file descriptor into the buffer.
3. If `read()` returns ≤ 0, free the buffer and return the result.
4. Null-terminate the buffer.
5. Append the buffer to the existing backup using `ft_strjoin_free()`.
6. Free the temporary buffer.
7. Return the number of bytes read.

**Context in `get_next_line()`:**
`read_buffer()` is responsible for **filling the backup buffer** with new data from the file. It allows `get_next_line()` to process content incrementally, line by line.

**Example:**

```c
char *backup = ft_strdup("");
int fd = open("file.txt", O_RDONLY);
int bytes = read_buffer(fd, &backup);
// backup now contains the first BUFFER_SIZE bytes of the file
close(fd);
free(backup);
```

**Conclusion:**
`read_buffer()` is a crucial utility in `get_next_line()` for safe, incremental reading from a file descriptor, managing dynamic memory and backup concatenation efficiently.

---

### 📋 Como funciona

A função `read_buffer()` **lê dados de um descritor de arquivo** para um buffer temporário e os adiciona ao backup. Ela gerencia memória dinâmica de forma segura, garantindo que o backup cresça conforme novos dados são lidos.

**Parâmetros de entrada:**

* `int fd` → descritor de arquivo para leitura
* `char **backup` → ponteiro para o buffer de backup que acumula os dados

**Valor de retorno:**

* Número de bytes lidos (>0)
* `0` se for final de arquivo
* `-1` em caso de erro (falha de alocação ou erro de leitura)

**Validações:**

1. Aloca buffer temporário e verifica `NULL`.
2. Verifica o retorno de `read()` para tratar EOF ou erros.
3. Confirma que o backup foi atualizado corretamente com `ft_strjoin_free()`.

**Fluxo principal:**

1. Aloca um buffer temporário de tamanho `BUFFER_SIZE + 1`.
2. Lê até `BUFFER_SIZE` bytes do descritor de arquivo para o buffer.
3. Se `read()` retornar ≤ 0, libera o buffer e retorna o resultado.
4. Adiciona `'\0'` ao final do buffer.
5. Anexa o buffer ao backup existente usando `ft_strjoin_free()`.
6. Libera o buffer temporário.
7. Retorna o número de bytes lidos.

**Contexto no `get_next_line()`:**
`read_buffer()` é responsável por **preencher o backup** com novos dados do arquivo. Isso permite que `get_next_line()` processe o conteúdo de forma incremental, linha a linha.

**Exemplo prático:**

```c
char *backup = ft_strdup("");
int fd = open("arquivo.txt", O_RDONLY);
int bytes = read_buffer(fd, &backup);
// backup agora contém os primeiros BUFFER_SIZE bytes do arquivo
close(fd);
free(backup);
```

**Conclusão:**
`read_buffer()` é uma função essencial em `get_next_line()` para leitura incremental segura de um arquivo, gerenciando memória dinâmica e concatenação do backup de forma eficiente.
