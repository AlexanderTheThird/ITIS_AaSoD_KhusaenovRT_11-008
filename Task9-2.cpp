#include <iostream>
#include <algorithm>
using namespace std;

struct Task {
    int num;
    int price;
    int dedline;
};

bool sort_key(Task Task1, Task Task2) {
    return Task1.price > Task2.price;
}

int * distributeTasks(Task *TasksList, int countOfTasks) {
    int * array = new int[countOfTasks];
    for (int j = 0; j < countOfTasks; j++) {
        array[j] = -1;
    }
    int max = 0;
    for (int j = 0; j < countOfTasks; j++) {
        if (TasksList[j].price >= TasksList[max].price)
            max = j;
    }
    cout << max << endl;
    // for (int i = 0; i < countOfTasks; i++) {
    //     int old_max = max;
    //     max = 0;
    //     cout << old_max << " " << max << endl;
    //     for (int j = 0; j < countOfTasks; j++) {
    //         if (TasksList[j].price >= TasksList[max].price && TasksList[j].price <= TasksList[old_max].price && j != old_max)
    //             max = j;
    //         cout << max << " ";
    //     }  
    //     cout << max << endl;
    // }
    sort(TasksList, TasksList + countOfTasks, sort_key);
    for (int j = 0; j < countOfTasks; j++) {
        int i = TasksList[j].dedline - 1;
        while (i > 0 && array[i] != -1) {
            i--;
        }
        array[i] = TasksList[j].num;
        cout << array[i] << " " << i << endl;
    }
    return array;
}


int main() {
    int countOfTasks;

    cout << "HOW MANY TASKS?" << endl;
    cin >> countOfTasks;
    cout << "GOTCHA. WHICH ONES?" << endl;

    Task taskManager[countOfTasks];

    for (int i = 0; i < countOfTasks; i++) {
        Task task;
        cin >> task.num >> task.price >> task.dedline;
        taskManager[i] = task;
    }

    int * result = distributeTasks(taskManager, countOfTasks);

    cout << "OK, YOU NEED TO COMPLETE THE TASKS IN THE FOLLOWING ORDER:" << endl;
    for (int i = 0; i < countOfTasks; i++) {
        cout << result[i] << " ";
    }

    return 0;
}