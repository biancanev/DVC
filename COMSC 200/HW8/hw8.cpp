#include <iostream>

using namespace std;

template<class T>
class Deque {
    struct listNode {
        T data;
        int index = 0;  /// the index for the element
        listNode* next = nullptr;
        listNode* previous = nullptr;
    };
    listNode* head = nullptr;
    listNode* tail = nullptr;

public:
    ~Deque() {
        /// ADD YOUR CODE HERE
        /// Release all dynamically allocated memory
        listNode *p = head;
        while(p){
            listNode *q = p->next;
            delete p;
            p = q;
        }
    }

    void push_back(T value) {
        /// ADD YOUR CODE HERE
        /// Add the element of the value to the end of the list
        listNode *newTail = new listNode;
        newTail->data = value;
        newTail->previous = tail;

        if(tail){
            tail->next = newTail;
            int index = 1;
            for(listNode *node = head; node; node = node->next, index++){
                node->index = index;
            }
            newTail->index = index++;
        }
        tail = newTail;
        if(!head){
            head = newTail;
            return;
        }
    }

    void push_front(T value) {
        /// ADD YOUR CODE HERE
        /// Add the element of the value to the beginning of the list
        listNode *newHead = new listNode;
        newHead->data = value;
        newHead->next = head;
        head->previous = newHead;
        head = newHead;
        int index = 1;
        for(listNode *node = head->next; node; node = node->next, index++){
            node->index = index;
        }
        if(!tail){
            head->previous = newHead;
            tail = newHead;
        }
    }

    void display_forward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from head to tail
        /// Use the link next to move the next node. (Do NOT use index.)
        for(listNode *node = head; node; node = node->next){
            cout << node->data << " ";
        }
        cout << endl;
    }

    void display_backward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from tail to head
        /// Use the link precious to move the previous node. (Do NOT use index.)
        for(listNode *node = tail; node; node = node->previous){
            cout << node->data << " ";
        }
        cout << endl;
    }

    T operator[](int index) {
        /// ADD YOUR CODE HERE
        /// With the index, the value of the element is displayed
        for(listNode *node = head; node; node = node->next){
            if(node->index == index){
                return node->data;
            }
        }
        cout << "Bounds Error" << endl;
    }

    int size()
    {
        int sz = 0;
        for(listNode *node = head; node; node = node->next){
            sz++;
        }
        return sz;
    }
};

int main() {

    Deque<int> deque1;
    deque1.push_back(11);
    deque1.push_back(22);
    deque1.push_back(33);
    cout << "Checking push_back()" << endl;
    deque1.display_forward();  /// Should display   11  22  33
    deque1.display_backward();  /// Should display   33  22  11

    deque1.push_front(0);
    cout << endl << endl << "Checking push_front()" << endl;
    deque1.display_forward();  /// Should display   0  11  22  33
    deque1.display_backward();  /// Should display   33  22  11  0

    cout << endl << endl << "Checking operator []" << endl;
    for (int i = 0; i < deque1.size(); i++)
    {
        cout << deque1[i] << endl;
    }

    return 0;
}