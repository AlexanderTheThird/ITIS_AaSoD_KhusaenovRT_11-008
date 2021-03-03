#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a;
    int b;
    int c;

    int x;
    int y;

    cin >> a >> b >> c;

    y = b*b - 4*a*c;

    if (y < 0) {
        cout << "None";
    }
    else {
        x = ((-b)-sqrt(y))/(2*a);
        y = ((-b)+sqrt(y))/(2*a);

        if (x == y) {
            cout << x;
        }
        else {
            cout << x << endl;
            cout << y << endl;
        }
    }

}

