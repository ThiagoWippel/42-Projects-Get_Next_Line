📋 How get_next_line() Works

The get_next_line() function is designed to return one line at a time from a file or from standard input. It takes as parameter an integer fd, which represents the file descriptor to be read, and returns a pointer to char containing the retrieved line.

Core Structure

Static backup:
A static variable called backup stores the data already read from the file but not yet processed. It works as an auxiliary buffer, keeping leftover data between function calls.

Return line (line):
A temporary pointer that holds the line to be delivered in the current function call.

Initial Validation

If the file descriptor (fd) is invalid (less than zero) or if BUFFER_SIZE is less than or equal to zero, the function immediately returns NULL to ensure safety against invalid parameters.

Main Flow

Checking the backup:
Before reading new data, the function checks if there is already a complete line stored in the backup.

This check is performed by the helper function process_backup(), which does not read anything new from the file.

If a complete line is found in the backup, it is returned immediately.

Reading in a loop:
If no complete line exists in the backup, the function enters a loop responsible for reading from the file until at least one complete line can be built.

read_and_process(): reads exactly BUFFER_SIZE bytes from the file and appends them to the existing backup.

In case of an error or reaching the end of file, it may return the last available line.

If the read was successful, it returns NULL.

After each read, the function extract_line() checks whether it is now possible to extract a complete line (looking for the \n character).

If a line is found, it is returned.

If not, the loop continues reading more BUFFER_SIZE chunks until success.

The loop only terminates when a complete line is returned or when the end of file is reached.

Key Point

Even if BUFFER_SIZE is larger than the entire file size, the function will always return only the first line found, leaving the remaining data in the backup for subsequent calls.

Practical Example

File:

line1\nline2\nline3\n


BUFFER_SIZE = 1000 (larger than the file)

1st call: reads the whole file, returns "line1\n", backup keeps "line2\nline3\n"

2nd call: returns "line2\n", backup keeps "line3\n"

3rd call: returns "line3\n", backup becomes empty

4th call: attempts to read again (EOF), returns NULL

Conclusion

Regardless of the value of BUFFER_SIZE, each call to get_next_line() always returns exactly one line at a time. The BUFFER_SIZE only affects the internal efficiency — i.e., how many times the function needs to access the disk — but never the external behavior:

1 call → 1 line returned

Full file read → loop until NULL



📋 Funcionamento de get_next_line()

A função get_next_line() tem como objetivo retornar, a cada chamada, uma única linha de um arquivo ou da entrada padrão. Ela recebe como parâmetro um inteiro fd, que representa o descritor de arquivo a ser lido, e retorna um ponteiro para char contendo a linha obtida.

Estrutura de funcionamento

Backup estático:
Uma variável estática chamada backup é utilizada para armazenar os dados que já foram lidos do arquivo, mas que ainda não foram processados. Ela funciona como um "buffer auxiliar", guardando os trechos restantes entre as chamadas da função.

Linha de retorno (line):
É um ponteiro temporário que armazena a linha que será entregue na chamada atual da função.

Validações iniciais

Se o descritor de arquivo (fd) for inválido (menor que zero) ou se BUFFER_SIZE for menor ou igual a zero, a função retorna NULL, garantindo segurança contra parâmetros incorretos.

Fluxo principal

Verificação do backup:
Antes de realizar qualquer leitura, a função verifica se já existe no backup uma linha completa proveniente de chamadas anteriores.

Essa análise é feita pela função auxiliar process_backup(), que não lê nada novo do arquivo.

Se houver uma linha completa no backup, ela é retornada imediatamente.

Leitura em loop:
Caso não exista linha pronta no backup, a execução entra em um loop responsável por ler o arquivo até que seja possível montar pelo menos uma linha completa.

read_and_process(): lê exatamente BUFFER_SIZE bytes do arquivo e adiciona o conteúdo ao backup.

Em caso de erro ou fim do arquivo, pode retornar a última linha disponível.

Se a leitura foi bem-sucedida, retorna NULL.

Após cada leitura, a função extract_line() verifica se já é possível extrair uma linha completa (buscando o caractere \n).

Se uma linha for encontrada, ela é retornada.

Caso contrário, o loop continua até que a leitura permita formar uma linha válida.

O ciclo é interrompido apenas quando uma linha completa é retornada ou quando ocorre o fim do arquivo.

Ponto crucial

Mesmo que BUFFER_SIZE seja maior do que o tamanho total do arquivo, a função sempre retorna apenas a primeira linha encontrada, preservando o restante no backup para chamadas futuras.

Exemplo prático

Arquivo:

linha1\nlinha2\nlinha3\n


BUFFER_SIZE = 1000 (maior que o arquivo)

1ª chamada: lê o arquivo inteiro, retorna "linha1\n", backup guarda "linha2\nlinha3\n"

2ª chamada: retorna "linha2\n", backup guarda "linha3\n"

3ª chamada: retorna "linha3\n", backup fica vazio

4ª chamada: tenta ler novamente (EOF), retorna NULL

Conclusão

Independentemente do valor de BUFFER_SIZE, cada chamada de get_next_line() retorna apenas uma linha por vez. O BUFFER_SIZE influencia apenas a eficiência interna — ou seja, quantas vezes a função precisa acessar o disco — mas não altera o comportamento externo:

1 chamada → 1 linha retornada

Leitura completa → loop até NULL
