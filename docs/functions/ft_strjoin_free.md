### 💻 Implementation

```c
char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1 && ++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	return (free(s1), str);
}
```

---

### 📋 How it works

The `ft_strjoin_free()` function **concatenates two strings** `s1` and `s2` into a new dynamically allocated string. It also **frees the first string (`s1`)** to manage memory efficiently.

**Input parameters:**

* `char *s1` → first string (will be freed)
* `const char *s2` → second string to append

**Return value:**

* Pointer to the newly allocated concatenated string
* `NULL` if memory allocation fails

**Validations:**

1. **Null checks:**

   * Returns `s1` if `s2` is `NULL`
   * Returns a duplicate of `s2` if `s1` is `NULL`
2. **Memory allocation check:** returns `NULL` if allocation fails (also frees `s1`)

**Main Flow:**

1. Calculate lengths of `s1` and `s2`.
2. Allocate memory for combined string including null terminator.
3. Copy characters from `s1` into the new string.
4. Append characters from `s2`.
5. Add `'\0'` at the end.
6. Free `s1` and return the new string.

**Context in `get_next_line()`:**
Used to **append the newly read buffer** to the backup string. This allows dynamic accumulation of content while safely managing memory, ensuring no leaks occur during concatenation.

**Example:**

```c
char *s1 = ft_strdup("Hello, ");
char *s2 = "world!";
char *joined = ft_strjoin_free(s1, s2);
// joined points to "Hello, world!"
free(joined);
```

**Conclusion:**
`ft_strjoin_free()` provides efficient string concatenation with automatic memory management of the first operand. In `get_next_line()`, it is critical for **incrementally building the backup buffer** safely and effectively.

---

### 📋 Como funciona

A função `ft_strjoin_free()` **concatena duas strings** `s1` e `s2` em uma nova string alocada dinamicamente, **liberando `s1`** para gerenciamento eficiente de memória.

**Parâmetros de entrada:**

* `char *s1` → primeira string (será liberada)
* `const char *s2` → segunda string a ser concatenada

**Valor de retorno:**

* Ponteiro para a nova string concatenada
* `NULL` se a alocação de memória falhar

**Validações:**

1. **Verificações nulas:**

   * Retorna `s1` se `s2` for `NULL`
   * Retorna duplicata de `s2` se `s1` for `NULL`
2. **Verificação de alocação:** retorna `NULL` se a alocação falhar (libera `s1`)

**Fluxo principal:**

1. Calcula os comprimentos de `s1` e `s2`.
2. Aloca memória para a string combinada, incluindo terminador nulo.
3. Copia os caracteres de `s1` para a nova string.
4. Adiciona os caracteres de `s2`.
5. Insere `'\0'` no final.
6. Libera `s1` e retorna a nova string.

**Contexto no `get_next_line()`:**
Usada para **adicionar o buffer recém-lido** ao backup. Permite acumular conteúdo dinamicamente enquanto gerencia memória com segurança, evitando vazamentos durante a concatenação.

**Exemplo prático:**

```c
char *s1 = ft_strdup("Olá, ");
char *s2 = "mundo!";
char *joined = ft_strjoin_free(s1, s2);
// joined aponta para "Olá, mundo!"
free(joined);
```

**Conclusão:**
`ft_strjoin_free()` oferece concatenação eficiente de strings com gerenciamento automático da memória do primeiro operando. No `get_next_line()`, é essencial para **construir incrementalmente o buffer de backup** de forma segura e eficaz.
