#include "file.h"

file::file(std::string arq){

    
    std::ifstream source;
    source.open(arq);

    std::vector<std::string>lines;
    std::string line;
    int number;

    while(std::getline(source, line)){
        lines.push_back(line);
    }

    initial_credit = stof(lines[0]);
    rounds = stoi(lines[1]);
    std::stringstream iss(lines[2]);

    while(iss >> number){
        bets.push_back(number);
    }
    
}
