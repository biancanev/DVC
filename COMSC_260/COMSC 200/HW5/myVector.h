/**
 * We want to place the entire class definition of a class template in the .h file because it cannot complie without a declaration. Therefore, it is
 * easier to just place the declaration in the .h rather than doing workarounds to allow the template to compile from a separate .cpp file.
**/
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> * next = nullptr;
    Node<T> * prev = nullptr;
};

template <typename T>
class myVector{
    private:
        Node<T> *first = nullptr;
        Node<T> *last = nullptr;
    public:
        void push_back(T newData){
            Node<T> *newItem = new Node<T>;
            newItem->data = newData;
            //no items
            if(first == nullptr){
                first = newItem;
                last = newItem;
                return;
            }
            //one item
            if(first == last){
                first->next = newItem;
                newItem->prev = first;
                last = newItem;
                return;
            }
            //else
            last->next = newItem;
            newItem->prev = last;
            last = newItem;
        }
        void pop_back(){
            Node<T> *temp = last;
            last = last->prev;
            last->next = nullptr;
            delete temp;
        }
        void display(){
            for(Node<T> *node = first; node; node = node->next){
                cout << node->data;
            }
            cout << endl;
        }
        /**Extra text functions**/
        T at(int index){
            int i = 0;
            Node<T> *node = first;
            while(i != index){
                node = node->next;
                i++;
            }
            return node->data;
        }
        int indexOf(T param){
            int i = 0;
            for(Node<T> *node = first; node; node = node->next, i++){
               if(node->data == param){
                    return i;
               }
            }
            return -1;
        }
};
#endif