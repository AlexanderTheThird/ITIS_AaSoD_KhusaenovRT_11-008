#include <iostream>
using namespace std;

int findStart(int * arr, int X, int size) {
    int start = 0, stop = size-1;
    if (arr[start] > X || arr[stop] < X) throw 1;
    while (true) {
        if (arr[(stop+start)/2] >= X) stop = (stop+start)/2;
        if (arr[(stop+start)/2] < X) start = (stop+start)/2;
        if (arr[start-1] != X && arr[start] == X) return start;
        if (arr[stop-1] != X && arr[stop] == X) return stop;
        if (stop-start == 1) throw 1;
    }
}

int findEnd(int * arr, int X, int size) {
    int start = 0, stop = size-1;
    if (arr[start] > X || arr[stop] < X) throw 1;
    while (true) {
        if (arr[(stop+start)/2] > X) stop = (stop+start)/2;
        if (arr[(stop+start)/2] <= X) start = (stop+start)/2;
        if (arr[start] == X && arr[start+1] != X) return start;
        if (arr[stop] == X && arr[stop+1] != X) return stop;
        if (stop-start == 1) throw 1;
    }
}

int main() {
    int arr[] = {0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,5,5,5,5,6,9,9,9,9,9,9};
    const int size = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < 10; i++) {
        int result = findStart(arr, i, size);
        cout << arr[result-1] << " " << arr[result] << endl;
        result = findEnd(arr, i, size);
        cout << arr[result] << " " << arr[result+1] << endl;
        cout << '\n';
    }
}