#ifndef FILE_H
#define FILE_H


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

class file{

public:
    float initial_credit;
    int rounds;
    std::vector<int> bets;
    file(std::string arq);
};


#endif