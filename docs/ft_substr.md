### 💻 Implementation

```c
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
```

---

### 📋 How it works

The `ft_substr()` function creates a **new string containing a substring** of `s`, starting at index `start` and with maximum length `len`. It allocates memory for the substring and appends a null terminator.

**Input parameters:**

* `const char *s` → the original string
* `unsigned int start` → starting index of the substring
* `size_t len` → maximum length of the substring

**Return value:**

* Pointer to the newly allocated substring
* `NULL` if `s` is invalid or memory allocation fails
* An empty string (`""`) if `start` is beyond the end of `s`

**Validations:**

1. **Null pointer check:** returns `NULL` if `s` is `NULL`.
2. **Start index check:** returns empty string if `start >= length of s`.
3. **Memory allocation check:** returns `NULL` if allocation fails.

**Main Flow:**

1. Calculate length of `s` using `ft_strlen()`.
2. Adjust `len` if it exceeds remaining characters after `start`.
3. Allocate memory for the substring including null terminator.
4. Copy characters from `s[start]` to `s[start + len - 1]`.
5. Append `'\0'` and return the substring.

**Context in `get_next_line()`:**
Used in `extract_line()` to **split the backup buffer** after extracting a line. Allows storing the remaining content for the next call safely.

**Example:**

```c
const char *text = "Hello, world!";
char *sub = ft_substr(text, 7, 5);
// sub points to "world"
free(sub);
```

**Conclusion:**
`ft_substr()` provides safe substring extraction with dynamic memory allocation. In `get_next_line()`, it is crucial for handling leftover buffer content after line extraction.

---

### 📋 Como funciona

A função `ft_substr()` cria uma **nova string contendo um trecho** de `s`, começando no índice `start` e com comprimento máximo `len`. Ela aloca memória para a substring e adiciona o terminador nulo.

**Parâmetros de entrada:**

* `const char *s` → string original
* `unsigned int start` → índice inicial da substring
* `size_t len` → comprimento máximo da substring

**Valor de retorno:**

* Ponteiro para a substring alocada
* `NULL` se `s` for inválida ou a alocação falhar
* String vazia (`""`) se `start` for maior que o comprimento de `s`

**Validações:**

1. **Verificação de ponteiro nulo:** retorna `NULL` se `s` for `NULL`.
2. **Verificação do índice inicial:** retorna string vazia se `start >= comprimento de s`.
3. **Verificação de alocação:** retorna `NULL` se a alocação falhar.

**Fluxo principal:**

1. Calcula o tamanho de `s` usando `ft_strlen()`.
2. Ajusta `len` se exceder os caracteres restantes após `start`.
3. Aloca memória para a substring incluindo terminador nulo.
4. Copia caracteres de `s[start]` até `s[start + len - 1]`.
5. Adiciona `'\0'` e retorna a substring.

**Contexto no `get_next_line()`:**
Usada em `extract_line()` para **dividir o buffer de backup** após extrair uma linha, permitindo armazenar o conteúdo restante de forma segura para a próxima chamada.

**Exemplo prático:**

```c
const char *texto = "Olá, mundo!";
char *sub = ft_substr(texto, 5, 5);
// sub aponta para "mundo"
free(sub);
```

**Conclusão:**
`ft_substr()` fornece extração segura de substrings com alocação dinâmica. No `get_next_line()`, é essencial para manipular o conteúdo restante do buffer após a extração de uma linha.
