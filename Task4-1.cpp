#include <iostream>
using namespace std;

struct Node {
    int item;
    Node * next;
    Node * prev;
};

struct DList {
    Node * pHead = NULL;

    void add(int item) {
        Node * node = new Node;
        node->item = item;
        node->prev = pHead;
        if (pHead != NULL) pHead->next = node;
        pHead = node;
    }

    int size() {
        int size = 0;

        if (!pHead) return size;
        
        Node * temp = pHead;

        while (temp->prev != NULL) {
            temp = temp->prev;
            size++;
        }

        size++;

        return size;
    }
    
    int correctId(int id, int size) {

        if (id < 0) { 
            id = -id - 1;
        }
        else {
            id = size - id - 1;
        }

        return id;
    }

    Node * requiredEl(int id, int size) {
        id = correctId(id, size);
        Node * temp = pHead;

        while (id > 0) {
            temp = temp->prev;
            id -= 1;
        }

        return temp;
    }

    int get(int id) {
        int size = this->size();
        if (!pHead) throw 1;
        if (id+1 > size || id < -size) throw 1;

        Node * temp = requiredEl(id, size);

        return temp->item;
    }

    void insertAt(int item, int id) {
        int size = this->size();

        if (!pHead && id == 0) return this->add(item);
        if (id == size || id == -1) return this->add(item);
        if (id < 0) id++;
        Node * temp = requiredEl(id, size);

        Node * node = new Node;
        node->item = item;
        node->prev = temp->prev;
        node->next = temp;
        temp->prev = node;
        temp = node->prev;
        if (temp != NULL) temp->next = node;
    }

    void removeAt(int id) {
        int size = this->size();
        if (id+1 > size) throw 1;

        Node * temp = requiredEl(id, size);
        if (temp == pHead) pHead = temp->prev;
        else temp->next->prev = temp->prev;
        if (temp->prev != NULL) temp->prev->next = temp->next;
        delete temp;
    }
};

int main() {
    DList * list = new DList;

    list->add(10);
    list->add(20);
    list->add(30);
    list->add(40);
    list->add(50);

    cout << list->size() << endl;

    cout << list->get(-1) << endl; // 50
    cout << list->get(0) << endl; // 10
    
    list->insertAt(5, 0); // 5 10 20 30 40 50
    list->insertAt(60, -1); // 5 10 20 30 40 50 60
    
    cout << list->get(-1) << endl; // 60
    cout << list->get(0) << endl; // 5
    cout << list->get(-2) << endl; // 50

    return 0;
}