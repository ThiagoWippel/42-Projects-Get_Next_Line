💻 Implementation

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

📋 How it works
The `ft_strlen()` function calculates the **length of a given string** `s` by counting characters until it reaches the null terminator `\0`. It provides a safe implementation with null pointer validation, ensuring reliable operation even with invalid input.

**Input parameter:**
* `const char *s` → the string to measure

**Return value:**
* `size_t` representing the length of the string
* `0` if `s` is `NULL`

**Validations:**
1. **Null pointer check:** returns `0` if `s` is `NULL`.

**Main Flow:**
1. Initialize counter `len` to `0`.
2. Iterate through each character of the string.
3. Increment counter for each non-null character found.
4. Stop when null terminator `\0` is reached.
5. Return the total character count.

**Context in `get_next_line()`:** Used extensively for **memory allocation calculations**. When duplicating strings or creating substrings, `ft_strlen()` determines the exact amount of memory needed. Essential for functions like `ft_strdup()` and `ft_strjoin_free()` to allocate the correct buffer sizes, preventing memory waste or buffer overflows.

**Example:**

```c
char *text = "Hello, world!";
size_t length = ft_strlen(text);
// length = 13 (excluding the null terminator)
```

**Conclusion:** `ft_strlen()` provides safe and reliable string length calculation with null safety. In `get_next_line()`, it is a **fundamental utility** for all memory allocation operations involving strings.

📋 Como funciona
A função `ft_strlen()` calcula o **comprimento de uma string fornecida** `s` contando caracteres até encontrar o terminador nulo `\0`. Fornece uma implementação segura com validação de ponteiro nulo, garantindo operação confiável mesmo com entrada inválida.

**Parâmetro de entrada:**
* `const char *s` → string a ser medida

**Valor de retorno:**
* `size_t` representando o comprimento da string
* `0` se `s` for `NULL`

**Validações:**
1. **Verificação de ponteiro nulo:** retorna `0` se `s` for `NULL`.

**Fluxo principal:**
1. Inicializa contador `len` com `0`.
2. Itera através de cada caractere da string.
3. Incrementa contador para cada caractere não-nulo encontrado.
4. Para quando o terminador nulo `\0` é alcançado.
5. Retorna a contagem total de caracteres.

**Contexto no `get_next_line()`:** Usada extensivamente para **cálculos de alocação de memória**. Ao duplicar strings ou criar substrings, `ft_strlen()` determina a quantidade exata de memória necessária. Essencial para funções como `ft_strdup()` e `ft_strjoin_free()` alocarem os tamanhos corretos de buffer, prevenindo desperdício de memória ou buffer overflows.

**Exemplo prático:**

```c
char *texto = "Olá, mundo!";
size_t comprimento = ft_strlen(texto);
// comprimento = 11 (excluindo o terminador nulo)
```

**Conclusão:** `ft_strlen()` fornece cálculo seguro e confiável do comprimento de strings com proteção contra nulos. No `get_next_line()`, é uma **utilidade fundamental** para todas as operações de alocação de memória envolvendo strings.
