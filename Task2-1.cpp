#include <iostream>
using namespace std;

int sum(int * a, int size) {
    int summary = 0;
    while (size != 0) {
        summary += *a;
        *a++;
        size -= 1;
    }
    return summary;
}


int main() {
    int a[5] = {1,2,3,4,6};
    int * p = a;

    cout << sum(p, 5);

    return 0;

}