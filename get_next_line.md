📋 FUNCIONAMENTO DE get_next_line()

A função get_next_line() retorna um ponteiro para char e é invocada com o parâmetro de tipo int chamado fd, que se refere ao arquivo que será lido (ou entrada padrão).
A variável estática backup serve para armazenar na memória, entre as chamadas da função, os dados que foram lidos do arquivo mas ainda não foram processados/retornados. Funciona como uma "gaveta" que guarda as sobras de cada leitura.
A variável line é um ponteiro temporário que recebe a linha atual que será retornada para quem chamou a função. Ela armazena "a linha que será entregue na chamada atual".
Se o fd for menor que zero ou se o BUFFER_SIZE for menor ou igual a zero, a função retorna NULL devido a parâmetros inválidos.
Considerando que a validação passou, a função primeiro verifica se o backup já possui uma linha completa guardada das leituras anteriores. A função process_backup() NÃO LÊ NADA NOVO, apenas examina o que já está no backup e verifica: "existe alguma linha completa armazenada?".
Se process_backup() encontrou uma linha pronta no backup, a função retorna essa linha imediatamente sem precisar ler mais nada do arquivo.
Se não havia linha pronta no backup, a execução entra no loop infinito que vai FORÇAR a leitura até conseguir pelo menos uma linha completa. Dentro do loop:

read_and_process(): Lê exatamente BUFFER_SIZE bytes do arquivo e adiciona ao backup existente. Se der erro ou chegar ao fim do arquivo, pode retornar a última linha. Se leu normalmente, retorna NULL.
Se read_and_process() retornou uma linha (fim de arquivo), a função retorna essa linha.
Se não retornou linha, chama extract_line() para verificar se agora, com os novos dados adicionados ao backup, é possível extrair uma linha completa (procurando por \n).
Se conseguiu extrair uma linha, retorna ela. Se não conseguiu, volta para o início do loop para ler mais BUFFER_SIZE bytes.

O loop só para quando consegue extrair exatamente UMA linha completa ou quando o arquivo termina.
PONTO CRUCIAL: Mesmo que o BUFFER_SIZE seja enorme e leia o arquivo inteiro de uma vez só (exemplo: arquivo tem 50 bytes, BUFFER_SIZE = 1000), a função SEMPRE retorna apenas a PRIMEIRA linha encontrada. As outras linhas ficam guardadas no backup para as próximas chamadas da função.
EXEMPLO PRÁTICO:

Arquivo: "linha1\nlinha2\nlinha3\n"
BUFFER_SIZE = 1000 (maior que o arquivo)
1ª chamada: Lê arquivo inteiro, retorna só "linha1\n", backup fica com "linha2\nlinha3\n"
2ª chamada: Não lê mais nada, usa backup, retorna "linha2\n", backup fica com "linha3\n"
3ª chamada: Não lê mais nada, usa backup, retorna "linha3\n", backup fica vazio
4ª chamada: Backup vazio, tenta ler mais (EOF), retorna NULL

Por isso, independente do BUFFER_SIZE, para ler um arquivo completo é SEMPRE necessário chamar get_next_line() em loop até ela retornar NULL, porque cada chamada fornece apenas uma linha.
O BUFFER_SIZE afeta apenas a eficiência interna (quantas vezes a função precisa acessar o disco), mas não altera o comportamento externo: sempre 1 chamada = 1 linha retornada.
