#include "file.h"

file::file(std::string arq){

    number_type aux;

    std::ifstream source;
    source.open(arq);

    std::cout<<">>> Procurando o arquivo ["<< arq <<"] no diretório especificado "<<std::endl;
    std::cout<<"----------------------------------------------------------------"<<std::endl;

    /*!
    * If para tratar a abertura do arquivo
    * @throw: retorna uma mensagem que será recebida no catch na main.cpp
    */
    if(source.is_open()==false || source.peek() == std::ifstream::traits_type::eof()){
        throw "ERRO: O arquivo não foi encontrado ou não foi possível abrí-lo.";
    }


    std::cout<<">>> Lendo o arquivo, aguarde o processamento... "<<std::endl;
    std::cout<<"----------------------------------------------------------------"<<std::endl;

    std::vector<std::string>lines;
    std::string line;
    int number;

    while(std::getline(source, line)){
        lines.push_back(line);
    }

    if(lines.size()>3 || lines.size()<3){
        throw "ERRO: Arquivo de apostas em formatação estranha.";
    }

    
    /*!
    * bloco try para testar se o arquivo de apostas é válido
    * @throw: retorna uma mensagem que será recebida no catch na main.cpp
    */
    try{
        rounds = stoi(lines[1]);
        initial_credit = stof(lines[0]);
        if(initial_credit<=0){
            throw "ERRO: O valor de aposta é menor ou igual a zero.";
        }
        std::stringstream iss(lines[2]);
        while(iss >> number){
            bets.push_back(number);
            std::cout<<number<<std::endl;
        }
        if(bets.size() <= 0 ){
            throw "ERRO: Há um comportamento estranho com os números apostados.";
        }
    }
    catch(...){
        throw "ERRO: O Arquivo de apostas possui caracteres inválidos.";
    }
    
    credit_round = initial_credit/rounds;
    
    if(bets.size()>15){
        throw "ERRO: O número de apostas excede o limite de quinze.";
    }
    for (size_t i = 0; i < bets.size(); i++)
    {
        if(bets[i] <1 || bets[i]>80){
            throw "ERRO: algum número apostado está fora do range (1,80).";
        }
    }
    
    /*!
    * Ordena os números apostados */
    for(auto i=bets.begin(); i!=bets.end()-1; i++){
        for(auto j=i+1; j!=bets.end(); j++){
            if(*i>*j){
                aux = *i;
                *i = *j;
                *j = aux;
            }
            else if(*i==*j){
                throw "ERRO: Existem números repetidos apostados.";
            }
        }
    }


    std::cout<<">>> Aposta lida com sucesso! "<<std::endl;
    std::cout<<"    Será apostado um total de $"<<initial_credit<<" em "<<rounds<<" rodadas."<<std::endl;
    std::cout<<"    O valor apostado em cada round individual será de $"<<credit_round<<std::endl;
}
