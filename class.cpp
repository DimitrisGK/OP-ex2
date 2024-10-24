#include <cstring>
#include <iostream>
#include "class.h"
using namespace std;

Cashier::Cashier(){
    open_flag=false;
    serving_flag=false;
}

Cashier::~Cashier(){
    //open_flag=false;
    //serving_flag=false;
}

void Cashier::c_open(){
    open_flag=true;
    serving_flag=false;
    customers_served=0;
}

void Cashier::c_close(){
    open_flag=false;
}

void Cashier::c_serve(){
    serving_flag=true;
}

void Cashier::free(){
    serving_flag=false;
}

bool Cashier::is_open(){
    return open_flag;
}

bool Cashier::is_free(){
    return !serving_flag;
}

///////////////////////////////////////
Bank::Bank(){
    open_cashier=1;
    last_customer=1;
    curr_serving=0;
    b_open(1);
}

Bank::~Bank(){}

void Bank::enter(){
    if(chek_to_open()==false){
        last_customer=last_customer+1;
    }
    else{
        if(open_cashier<=5){
            b_open(open_cashier);
            last_customer=last_customer+1;
        }
        else 
            cout<<"Sorry you cannot enter until some customers are served!\n"<<endl;
    } 
}

void Bank::serve(){
    if(all_close()==true){
        b_open(1);
        c[0].c_serve();
        cout<<"Customer no: "<<curr_serving<<" by cashier no: 1\n"<<endl;
        c[0].free();
        exit();
    }    
    else
        for(int i=0; i<=4; i++){
            if(c[i].is_open()==true && c[i].is_free()==true){
                c[i].c_serve();
                cout<<"Customer no: "<<curr_serving<<" by cashier no:"<<i+1<<"\n"<<endl;
                c[i].free();
                exit();
                break;
            }
        }
}

void Bank::exit(){
    curr_serving=curr_serving+1;
    if(chek_to_close()==true){
        for(int i=0; i<=4; i++){
            if(c[i].is_open()==true && c[i].is_free()==true){
                b_close(i+1);
                break;
            }
        }
    }
}

void Bank::b_open(int n){
    open_cashier=open_cashier+1;
    if(n>=1 && n<=5){
        c[n-1].c_open();
        cout<<"The cashier: "<< n <<" is open\n"<<endl;
    }
}

void Bank::b_close(int n){
    open_cashier=open_cashier-1;
    if(n>=1 && n<=5){
        c[n-1].c_close();
        cout<<"The cashier: "<< n <<" is close\n"<<endl;
    }
}

bool Bank::chek_to_open(){
    if(last_customer-curr_serving>open_cashier*K)
        return true;
    else 
        return false;
}

bool Bank::chek_to_close(){
    if(last_customer-curr_serving<=(open_cashier-1)*K)
        return true;
    else   
        return false;
}

void Bank::open_cashiers(){
    cout<<"There are"<<open_cashier<<"open cashiers\n"<<endl;
}

void Bank::waiting_customers(){
    int w=last_customer-curr_serving;
    cout<<"There are"<<w<<"customers waiting"<<endl;
}

bool Bank::all_close(){
    bool chek=false;
    for(int i=0; i<=4; i++){
        if(c[i].is_open()==true)
            chek=true;
    }
    if(chek==false)
        return true;
    else 
        return false;
}