#include <iostream>
#include <fstream>
#define SIZE 5
using namespace std;
int main()
{
    int matrix[SIZE][SIZE], distance[SIZE], visited[SIZE];
    int temp, mini, min;
    int begin_index = 0;

//    ifstream fin("/home/hfcbv/ITIS_AaSoD_KhusaenovRT_11-008/input.txt");
//
//    for (int i = 0; i < SIZE; i++) {
//        matrix[i][i] = 0;
//        for (int j = i + 1; j < SIZE; j++) {
//            fin >> temp;
//            matrix[i][j] = temp;
//            matrix[j][i] = temp;
//        }
//    }

    for (int i = 0; i < SIZE; i++) {
        matrix[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            cout << "Введите расстояние " << i+1 << " - " << j+1 << ": ";
            cin >> temp;
            matrix[i][j] = temp;
            matrix[j][i] = temp;
        }
    }

    cout << "Матрица связей равна:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        distance[i] = 10000;
        visited[i] = 1;
    }
    distance[begin_index] = 0;
    do {
        mini = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++) {
            if ((visited[i] == 1) && (distance[i] < min)) {
                min = distance[i];
                mini = i;
            }
        }

        if (mini != 10000) {
            for (int i = 0; i < SIZE; i++) {
                if (matrix[mini][i] > 0) {
                    temp = min + matrix[mini][i];
                    if (temp < distance[i]) {
                        distance[i] = temp;
                    }
                }
            }
            visited[mini] = 0;
        }
    } while (mini < 10000);

    cout << "\nКратчайшие расстояния до вершин:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << distance[i] << "\t";
    }

    int ver[SIZE];
    int end = 4;
    ver[0] = end + 1;
    int k = 1;
    int weight = distance[end];

    while (end != begin_index) {
        for (int i = 0; i < SIZE; i++) {
            if (matrix[i][end] != 0) {
                int temp = weight - matrix[i][end];
                if (temp == distance[i]) {
                    weight = temp;
                    end = i;
                    ver[k] = i + 1;
                    k++;
                }
            }
        }
    }
    cout << "\nКратчайший путь:" << endl;
    for (int i = k - 1; i >= 0; i--)
        cout << ver[i] << " ";

//    ofstream fout("/home/hfcbv/ITIS_AaSoD_KhusaenovRT_11-008/iteration.txt", ios_base::app);
//    fout << counter << " ";

    return 0;
}
