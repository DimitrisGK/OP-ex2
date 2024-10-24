#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "class.h"
using namespace std;

int main(int argc,char* argv[]){

    int M=std::atoi(argv[2]);
    int N=std::atoi(argv[3]);
    int L=std::atoi(argv[4]);

    Bank bank;
    bank.K=std::atoi(argv[1]);

    for(int m=0; m<=M; m++){
        for(int n=0; n<=N; n++){
            bank.enter();
            bank.serve();
        }
        //bank.serve();
    }
}