### 💻 Implementation

```c
static char	*return_remaining_content(char **backup)
{
	char	*line;

	if (!*backup || (*backup)[0] == '\0')
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (line);
}
```

---

### 📋 How it works

The `return_remaining_content()` function **returns the remaining data** stored in the backup buffer when no more data can be read from the file descriptor. It ensures proper memory management by freeing the backup after duplication.

**Input parameters:**

* `char **backup` → pointer to the backup buffer containing remaining content

**Return value:**

* Pointer to a newly allocated string with the remaining content
* `NULL` if the backup is empty or invalid

**Validations:**

1. Checks if the backup is `NULL` or empty; if so, frees it and returns `NULL`.
2. Uses `ft_strdup()` to create a new independent copy of the remaining content.

**Main Flow:**

1. Verify if the backup is empty or `NULL`. Return `NULL` if so.
2. Duplicate the remaining content using `ft_strdup()`.
3. Free the original backup and set it to `NULL`.
4. Return the duplicated string.

**Context in `get_next_line()`:**
This function is called when **end-of-file is reached** and no newline character remains. It allows `get_next_line()` to **return the last portion of the file safely**, ensuring no data is lost and memory is properly freed.

**Example:**

```c
char *backup = ft_strdup("Last line without newline");
char *line = return_remaining_content(&backup);
// line now contains "Last line without newline"
// backup is freed and set to NULL
free(line);
```

---

### 📋 Como funciona

A função `return_remaining_content()` **retorna os dados restantes** no buffer de backup quando não há mais dados a serem lidos do arquivo. Ela garante a gestão correta da memória, liberando o backup após duplicação.

**Parâmetros de entrada:**

* `char **backup` → ponteiro para o buffer de backup contendo o conteúdo restante

**Valor de retorno:**

* Ponteiro para uma string recém-alocada com o conteúdo restante
* `NULL` se o backup estiver vazio ou inválido

**Validações:**

1. Verifica se o backup é `NULL` ou vazio; se sim, libera e retorna `NULL`.
2. Duplica o conteúdo restante usando `ft_strdup()` para criar uma cópia independente.

**Fluxo principal:**

1. Verifica se o backup está vazio ou `NULL`. Retorna `NULL` se verdadeiro.
2. Duplica o conteúdo restante com `ft_strdup()`.
3. Libera o backup original e define-o como `NULL`.
4. Retorna a string duplicada.

**Contexto no `get_next_line()`:**
Esta função é chamada quando **chega-se ao fim do arquivo** e não restam caracteres de nova linha. Ela permite que `get_next_line()` **retorne a última parte do arquivo de forma segura**, garantindo que nenhum dado seja perdido e a memória seja liberada corretamente.

**Exemplo prático:**

```c
char *backup = ft_strdup("Última linha sem newline");
char *linha = return_remaining_content(&backup);
// linha agora contém "Última linha sem newline"
// backup é liberado e definido como NULL
free(linha);
```

**Conclusão:**
`return_remaining_content()` assegura a entrega segura do conteúdo final do arquivo em `get_next_line()`, mantendo a integridade dos dados e o gerenciamento correto da memória.
