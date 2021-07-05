# KenoBet


* [Compilação](#compilação)
* [Execução](#execução)
* [Testes](#testes)


# Compilação

Para compilar o projeto, crie a pasta build com `mkdir build`, entre na pasta com `cd build` e execute o comando `cmake --build .` para compilar o projeto dentro da pasta build.


# Execução

 Compilado o programa, ainda dentro da pasta build execute o programa com `./kenobet <../files/arquivo.txt>`. Se seu arquivo de apostas estiver fora da pasta files especifique o caminho para achá-lo.

# Testes

Todos os testes de caso estão dentro do diretório `files` e podem ser executados com `./kenobet ../files/<arquivo_teste.txt>` . Os testes são:

* **funcional**: arquivo de apostas funcional
* **empty_file**: arquivo vazio
* **more_than_15_bets**: arquivo com mais de 15 números apostados
* **out_of_range**: arquivo com números apostados fora do range(1,80)
* **repeated_numbers**: arquivo com números apostados repetidos
* **strange_formatation**: arquivo com todas as informações em uma linha só
* **string_on_credit**: string no lugar do valor apostado
* **string_on_rounds**: string no lugar das rodadas

Todos os arquivos de teste são de extensão .txt