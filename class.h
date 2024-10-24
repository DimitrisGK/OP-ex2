#include <iostream>
#include <cstring>
using namespace std;

class Cashier{
private:
    bool open_flag;
    bool serving_flag;
    int customers_served;
public:
    Cashier();
    ~Cashier();

    void c_open();
    void c_close();

    void c_serve();
    void free();

    bool is_open();
    bool is_free();
};

//////////////////////////////
class Bank{
private:
    int last_customer;
    int curr_serving;
    int open_cashier;
public:
    Bank();
    ~Bank();

    void enter();
    void serve();
    void exit();

    bool chek_to_open();
    bool chek_to_close();

    void b_open(int);
    void b_close(int);

    void open_cashiers();
    void waiting_customers();

    Cashier c[5];

    int K;

    bool all_close();
};