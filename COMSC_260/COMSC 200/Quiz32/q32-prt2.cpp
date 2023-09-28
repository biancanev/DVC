#include <iostream>

using namespace std;

template <typename A, typename B>
class myMap{
    struct Element{
        A first;
        B second;
        Element *next = nullptr;
    };

    Element *head = nullptr;
    public:
        Element* insert(A key, B value){
            Element * newElement = new Element {key, value, nullptr};
            if(head){
                newElement->next = head;
                head = newElement;
            }else{
                head = newElement;
            }
            return newElement;
        }
        void display(){
            for(Element *node = head; node; node = node->next){
                cout << node->first << " -> " << node->second << endl;
            }
        }
};

int main(){
    myMap <char, int> mp1;
    mp1.insert('c', 300);
    mp1.insert('b', 200);
    mp1.insert('s', 904);
    mp1.insert('a', 100);
    mp1.insert('z', 900);
    mp1.insert('t', 203);
    mp1.display();

    return 0;
}