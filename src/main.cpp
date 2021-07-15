#include <iostream>
#include <vector>
#include "file.h"
#include "kenobet.h"

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

using namespace std;

/*
Avaliação
Processamento do Arquivo de Entrada: 1
Execução correta: 1
Interfcace Textual: 1
Documentação: 0,8 (faltou documentar os atributos da classe file)
Compilação automatizada: 1
Organização em src, include, build, data: 1

Comentários
- Muito boa a iniciativa de adicionar arquivos de teste e documentar ela no readme!
- Vc centralizou a parte de validação do arquivo na classe file, poderia ter também
centralizado a inteface textual em uma classe específica!
- Especialmente falando do uso da classe file, como conversamos na entrevista, o lugar
onde vc usa ela com um bloco "try ... catch" gigante é uma má prática... Como eu te falei,
quando um determinado conjunto de instruções dá exceção a gente reduz o escopo daquele conjunto
o máximo que der. No seu caso a solução era criar um construtor vazio na classe file e criar
um método separado para fazer a validação do arquivo que não fosse no construtor. Assim vc poderia
criar o objeto e chamar o método em um try ... catch, saindo do programa caso ocorresse algum erro
e continuando caso contrário.
*/

int main(int argc, char *argv[]){

    /*! se o arquivo não for passado como argumento imprime o erro no terminal*/
    if(argc < 2){
        cout << "ERRO: Não foi passado o arquivo de apostas como argumento!"<<endl;
        return 0;
    }

    /*! o try tenta executar o bloco de código, se algum comportamento indevido acontecer, o try é encerrado*/
    try{
    
    /*! Variáveis e classes inicializadas*/
        file File(argv[1]);
        KenoBet game(File.bets);

        set_of_numbers_type acertos; /*! vector que recebe o número de acertos por rodadas*/
        cash_type lucro=0; /*! lucro por rodada*/
        cash_type bet_sub = 0; /*!  variável auxiliar para reduzir do total o tanto que foi apostado na rodada
                                    ex: se o total apostado foi 150 e foram 3 rodadas, na primeira rodada vai ser subtraído 50, na segunda mais 50 e etc*/


        cout<<endl;
        cout<<"    Sua aposta tem "<<game.size()<<" números, eles são: ";
        game.show_spots(game.get_spots());
        cout<<endl<<endl;

    /*! O for recebe o número de rounds lido no arquivo e executa o jogo pelo tanto de rodadas que foi estipulado*/
        for(int i=0; i<File.rounds; i++){

            cout<<">>> Essa é a rodada #"<<i+1<<" de "<<File.rounds<< " rodadas e sua aposta nessa rodada é de $"<<File.credit_round<<endl;
            cout<<"    Os números sorteados foram: ";

            acertos = game.get_hits(game.hits(i));
            game.show_spots(game.hits(i));
            cout<<endl<<endl;

            cout<<"você acertou os números: ";
            game.show_spots(acertos);
            cout<<", um total de "<<acertos.size()<<"/"<<game.size()<<endl;
            lucro = game.payoff_table(game.size(),acertos.size())*File.credit_round;
            game.set_wage(lucro);
            bet_sub = bet_sub + File.credit_round;
            cout<<"sua taxa de retorno é de "<<game.payoff_table(game.size(),acertos.size())<<" saindo com $"<<lucro <<" nessa rodada"<<endl;
            cout<<"Você possui um total de $"<<game.get_wage()+File.initial_credit-bet_sub<<endl<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
            acertos.clear();
        }

    cout<<">>> Jogo finalizado. Calculando o lucro final..."<<endl<<endl<<endl;
    cout<<"+-----------------------------------Sumário-----------------------------------+"<<endl;
    cout<<"|Você apostou um total de $"<<File.initial_credit<<endl;

    /*! Bloco que calcula se o usuário saiu no prejuízo, no lucro ou no zero a zero*/
    lucro = game.get_wage()-File.initial_credit;
    if(lucro<0){
    cout<<"|Infelizmente você perdeu dinheiro sobrando apenas $"<<game.get_wage()<<" :("<<endl;
    }
    else if (lucro ==0)
    {
    cout<<"|Você não obteve lucro mantendo seu capital inicial de $"<<File.initial_credit<<endl;
    }
    else{
    cout<<"|Você obteve o lucro de $"<<lucro<<" saíndo com um total de $"<<lucro+File.initial_credit<<" Parabéns!!"<<endl;  
    }
    cout<<"+-------------------------------------Fim-------------------------------------+"<<endl;


    }

    /*! se for recebido algum exception, o código vai direto para o catch que retorna o erro obtido e encerra o programa*/
    catch(const char* msg){
        cout<< msg<<endl;
    }

    return 0;
}