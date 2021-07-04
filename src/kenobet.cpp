#include "kenobet.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*! "seta" o valor do lucro obtido*/
bool KenoBet::set_wage(cash_type wage_){

    if(wage_ > 0){
        m_wage = m_wage + wage_;
        return true;
    }

    return false;
}


/*! Mostra o lucro obtido*/
cash_type KenoBet::get_wage() const{

    return m_wage;
}


/*! retorna a quantidade de números apostados */
size_t KenoBet::size() const{

    return m_spots.size();
}

/*! Ordena e mostra os  */
set_of_numbers_type KenoBet::get_spots() const{

    return m_spots;
}

void KenoBet::show_spots(set_of_numbers_type spots_){

    cout<<"[ ";
    for(auto i=spots_.begin(); i!=spots_.end(); i++){
        cout<<*i<<" ";
    }
    cout<<"]";
}

set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) const{

    set_of_numbers_type acertados;



    for (size_t i = 0; i < m_spots.size(); i++)
    {
        for (size_t j = 0; j < hits_.size(); j++)
        {
            // cout<<m_spots[i]<<" "<<hits_[j]<<endl;
            if(m_spots[i]==hits_[j]){
                acertados.push_back(m_spots[i]);
            }
        }
        
    }
    

    return acertados;
}

set_of_numbers_type KenoBet::hits(int rounds){

    set_of_numbers_type hits;
    number_type aux;
    bool equals = false;

    srand(time(0)+rounds);

    for(int i=0; i<20; i++){
        aux = rand() % 80 + 1;
        for(auto j=hits.begin(); j!=hits.end(); j++){
            if(*j==aux){
                i--;
                equals = true;
                break;
            }
        }
        if(!equals){
            hits.push_back(aux);
        }
        equals = false;
    }

    for(int i=0; i<19; i++){
        for(int j=i+1; j<20; j++){
            if(hits[i]>hits[j]){
                aux = hits[i];
                hits[i] = hits[j];
                hits[j] = aux;
            }
        }
    }

    return hits;
}


cash_type KenoBet::payoff_table(number_type total, number_type acertos){

    vector<vector<cash_type>> table = {
    {0,3},
    {0,1,9},
    {0,1,2,12},
    {0,0.5,2,6,12},
    {0,0.5,1,3,15,50},
    {0,0.5,1,2,3,30,75},
    {0,0.5,0.5,1,6,12,36,100},
    {0,0.5,0.5,1,3,6,19,90,720},
    {0,0.5,0.5,1,2,4,8,20,80,1200},
    {0,0,0.5,1,2,3,5,10,30,600,1800},
    {0,0,0.5,1,1,2,6,15,25,180,1000,3000},
    {0,0,0,0.5,1,2,4,24,72,250,500,2000,4000},
    {0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000},
    {0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500},
    {0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000}};

    return table[total-1][acertos];

}