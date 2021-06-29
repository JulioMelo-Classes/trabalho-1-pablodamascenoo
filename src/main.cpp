#include <iostream>
#include "file.h"

using namespace std;

int main(int argc, char *argv[]){


    file File(argv[1]);

    cout<<File.initial_credit<<endl;
    cout<<File.rounds<<endl;
    cout<<File.bets[1]<<endl;

    return 0;
}