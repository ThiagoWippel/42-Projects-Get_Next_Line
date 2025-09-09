### 💻 Implementation

```c
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
```

---

### 📋 How it works

The `ft_strchr()` function searches for the **first occurrence of a character** `c` in the string `s`. It returns a pointer to the character if found, or `NULL` if not.

**Input parameters:**

* `const char *s` → the string to search
* `int c` → the character to find (interpreted as `unsigned char`)

**Return value:**

* Pointer to the first occurrence of `c` in `s`
* Pointer to the null terminator `\0` if `c` is `'\0'`
* `NULL` if the character is not found or `s` is `NULL`

**Validations:**

1. **Null pointer check:** returns `NULL` if `s` is `NULL`.

**Main Flow:**

1. Traverse the string character by character.
2. Compare each character with `c`.
3. Return a pointer to the first match.
4. If no match is found and `c == '\0'`, return pointer to the null terminator.
5. Otherwise, return `NULL`.

**Context in `get_next_line()`:**
Used in `extract_line()` to detect newline characters (`'\n'`) in the backup buffer. Helps determine if a complete line is ready to return.

**Example:**

```c
const char *text = "Hello\nWorld";
char *pos = ft_strchr(text, '\n');
// pos points to the '\n' character within "Hello\nWorld"
```

**Conclusion:**
`ft_strchr()` provides a reliable way to locate characters in a string. In `get_next_line()`, it is essential for detecting line boundaries and returning lines correctly.

---

### 📋 Como funciona

A função `ft_strchr()` procura pela **primeira ocorrência de um caractere** `c` na string `s`. Retorna um ponteiro para o caractere encontrado ou `NULL` se não existir.

**Parâmetros de entrada:**

* `const char *s` → string onde será feita a busca
* `int c` → caractere a localizar (interpretado como `unsigned char`)

**Valor de retorno:**

* Ponteiro para a primeira ocorrência de `c` em `s`
* Ponteiro para o terminador nulo `\0` se `c == '\0'`
* `NULL` se o caractere não for encontrado ou se `s` for `NULL`

**Validações:**

1. **Verificação de ponteiro nulo:** retorna `NULL` se `s` for `NULL`.

**Fluxo principal:**

1. Percorre a string caractere por caractere.
2. Compara cada caractere com `c`.
3. Retorna ponteiro para a primeira correspondência.
4. Se não houver correspondência e `c == '\0'`, retorna ponteiro para o terminador nulo.
5. Caso contrário, retorna `NULL`.

**Contexto no `get_next_line()`:**
Utilizada em `extract_line()` para detectar quebras de linha (`'\n'`) no buffer de backup, determinando se uma linha completa está pronta para retorno.

**Exemplo prático:**

```c
const char *texto = "Olá\nMundo";
char *pos = ft_strchr(texto, '\n');
// pos aponta para o caractere '\n' dentro de "Olá\nMundo"
```

**Conclusão:**
`ft_strchr()` é uma forma confiável de localizar caracteres em strings. No `get_next_line()`, é essencial para identificar limites de linha e retornar o texto corretamente.
