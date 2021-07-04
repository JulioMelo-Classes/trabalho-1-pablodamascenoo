#ifndef FILE_H
#define FILE_H

using number_type = unsigned short int;

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

class file{

public:
    float initial_credit;
    int rounds;
    float credit_round;
    std::vector<unsigned short int> bets;
    file(std::string arq);
};


#endif