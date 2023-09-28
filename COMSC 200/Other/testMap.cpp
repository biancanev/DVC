#include <iostream>

using namespace std;

template<typename A, typename B>
class myMap{
    public:
        class Iterator{
            private:
                Iterator *left = nullptr;
                Iterator *right = nullptr;
            public:
                pair<A, B> *data = nullptr;

        };
        Iterator *begin = nullptr;
        Iterator *end = nullptr;
        myMap() = default;
        pair<Iterator, bool> insert(pair<A, B> newData){
            Iterator *it = begin;
            if(it){

            }else{
                begin = new Iterator;
                begin->data = newData;
            }
        }
        Iterator find(){

        }
};