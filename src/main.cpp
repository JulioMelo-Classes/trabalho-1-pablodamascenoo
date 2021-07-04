#include <iostream>
#include <vector>
#include "file.h"
#include "kenobet.h"

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

using namespace std;

int main(int argc, char *argv[]){

    
    if(argc < 2){
        cout << "Não foi passado o arquivo de apostas como argumento!"<<endl;
        return 0;
    }

    try{
        file File(argv[1]);
        KenoBet game(File.bets);
        set_of_numbers_type acertos;
        cash_type lucro=0;
        cash_type bet_sub = 0;

        cout<<endl;
        cout<<"    Sua aposta tem "<<game.size()<<" números, eles são: ";
        game.show_spots(game.get_spots());
        cout<<endl<<endl;

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

    catch(const char* msg){
        cout<< msg<<endl;
    }

    return 0;
}