### 💻 Implementation

```c
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
```

---

### 📋 How it works

The `ft_strlen()` function calculates the **length of the given string** `s`, excluding the null terminator `\0`. It iterates through each character until the end of the string is reached.

**Input parameter:**

* `const char *s` → the string whose length is to be calculated

**Return value:**

* The number of characters in the string (excluding `\0`)
* `0` if `s` is `NULL`

**Validations:**

1. **Null pointer check:** returns `0` if `s` is `NULL`.

**Main Flow:**

1. Initialize a counter `len` to `0`.
2. Traverse the string character by character until `\0` is encountered.
3. Increment the counter for each character.
4. Return the counter value as the string length.

**Context in `get_next_line()`:**
Used in multiple utility functions like `ft_strdup()` and `ft_substr()` to determine how much memory to allocate and how many characters to copy. Ensures proper handling of string operations.

**Example:**

```c
const char *text = "Hello, world!";
size_t length = ft_strlen(text);
// length is 13
```

**Conclusion:**
`ft_strlen()` provides a reliable way to compute string length. In `get_next_line()`, it is a **fundamental utility** for memory allocation and string manipulation.

---

### 📋 Como funciona

A função `ft_strlen()` calcula o **tamanho da string fornecida** `s`, excluindo o terminador nulo `\0`. Ela percorre cada caractere até o final da string.

**Parâmetro de entrada:**

* `const char *s` → string cujo tamanho será calculado

**Valor de retorno:**

* Número de caracteres da string (excluindo `\0`)
* `0` se `s` for `NULL`

**Validações:**

1. **Verificação de ponteiro nulo:** retorna `0` se `s` for `NULL`.

**Fluxo principal:**

1. Inicializa o contador `len` com `0`.
2. Percorre a string caractere por caractere até encontrar `\0`.
3. Incrementa o contador a cada caractere.
4. Retorna o valor do contador como tamanho da string.

**Contexto no `get_next_line()`:**
Utilizada em funções auxiliares como `ft_strdup()` e `ft_substr()` para determinar a quantidade de memória a ser alocada e quantos caracteres copiar, garantindo manipulação correta de strings.

**Exemplo prático:**

```c
const char *texto = "Olá, mundo!";
size_t tamanho = ft_strlen(texto);
// tamanho é 10
```

**Conclusão:**
`ft_strlen()` fornece uma forma confiável de calcular o tamanho de strings. No `get_next_line()`, é uma **função utilitária fundamental** para alocação de memória e manipulação de strings.
