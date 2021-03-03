#include <iostream>
using namespace std;

int power(int x, unsigned p){
    int y;
    while (p > 0) {
        y = x*x;
        p -= 1;
    }
    cout << y;
}

int main(){
    int x;
    unsigned p;

    cin >> x >> p;

    power(x, p);
}