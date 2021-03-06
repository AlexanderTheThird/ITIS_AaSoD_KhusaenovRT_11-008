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
    
    int correctId(int id) {
        int size = this->size();

        if (id < 0) { 
            id += size;
        }
        else {
            id = size - id - 1;
        }

        return id;
    }

    Node * requiredEl(int id) {
        id = correctId(id);
        Node * temp = pHead;

        while (id > 0) {
            temp = temp->prev;
            id -= 1;
        }

        return temp;
    }

    int get(int id) {
        if (!pHead || id < 0) throw 1;
        if (id+1 > this->size()) throw 1;

        Node * temp = requiredEl(id);

        return temp->item;
    }

    void insertAt(int item, int id) {
        int size = this->size();

        if (!pHead && id == 0) return this->add(item);
        if (id == size) return this->add(item);

        Node * temp = requiredEl(id);

        Node * node = new Node;
        node->item = item;
        node->prev = temp->prev;
        node->next = temp;
        temp->prev = node;
        temp = node->prev;
        temp->next = node;
    }

    void removeAt(int id) {
        int size = this->size();
        if (id+1 > size) throw 1;

        Node * temp = requiredEl(id);
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

    cout << list->size() << endl;
    cout << list->get(0) << endl;

    list->insertAt(15, 1);

    list->removeAt(1);

    return 0;
}