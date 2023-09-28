#include <iostream>
#include <vector>

using namespace std;

template<typename A, typename B>
class myMap{
    public:
        vector<pair<A, B>*> elements;

        pair<A, B>* insert(pair<A, B> data){
            pair<A, B>* element = new pair<A, B> {data};
            elements.push_back(element);
            return element;
        }

        void display(){
            for(pair<A, B>* element : elements){
                cout << element->first << " -> " << element->second << endl;
            }
        }
};

int main(){
    myMap <char, int> mp1;
    mp1.insert(pair<char, int>('c', 300));
    mp1.insert(pair<char, int>('b', 200));
    mp1.insert(pair<char, int>('s', 904));
    mp1.insert(pair<char, int>('a', 100));
    mp1.insert(pair<char, int>('z', 900));
    mp1.insert(pair<char, int>('t', 203));
    mp1.display();
    return 0;
}