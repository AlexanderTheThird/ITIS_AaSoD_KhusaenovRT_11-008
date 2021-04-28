#include <iostream>
using namespace std;


int main() {
    int M, N;

    cout << "INPUT M AND N HERE: ";
    cin >> M >> N;

    int rect[M][N], i, j = i = 0;
    rect[0][0] = 0;
    for (int k = 1; k < M; k++) {
        rect[k][j] = 1;
    }
    for (int k = 1; k < N; k++) {
        rect[i][k] = 1;
    }
    i++;
    j++;

    while (i < M && j < N) {
        for (int k = j; k < N; k++) {
            rect[i][k] = rect[i][k-1] + rect[i-1][k];
        }
        i++;
    }

    cout << "\nCOUNT OF PATHS IS " << rect[M-1][N-1] << endl;
    return 0;
}