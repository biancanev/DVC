#include <iostream>

using namespace std;

const int SIZE = 6;

/// ADD THE CLASS TEMPLATE HERE
template<typename A, typename B>
class myMap{
    private:
        pair<A, B> *Array;
        int populated = 0;
    public:
        myMap(){
            Array = new pair<A, B> [SIZE];
        }
        ~myMap(){
            delete [] Array;
        }
        void populate(pair<A, B> newItem){
            if(populated == 6){
                cout << "Out of bounds" << endl;
                return;
            }
            for(int i = 0; i < populated; i++){
                if(newItem.first == Array[i].first){
                    cout << "Key already exists" << endl;
                    return;
                }
            }
            Array[populated] = newItem;
            populated++;
            //Bubble sort is inefficient, but with an array size of 6, the effects are negligible
            for(int i = 0; i < populated; i++){
                for(int j = 0; j < populated; j++){
                    if(Array[i] < Array[j]){
                        pair<A,B> temp = Array[j];
                        Array[j] = Array[i];
                        Array[i] = temp;
                    }
                }
            }
        }
        void displayAll(){
            for(int i = 0; i < populated; i++){
                cout << Array[i].first << " -> " << Array[i].second << endl;
            }
        }

        pair<A, B> operator[](int a){
            if(a >= populated){
                cout << "Out of bounds" << endl;
            }else{
                return Array[a];
            }
        }
};

string randomQuestion(long long);
int randomPrize(long long);

int main()

{

    myMap<long long, string> mp1;
    pair<long long, string> pr1 = {1256004567, randomQuestion(1256004567)};
    mp1.populate(pr1);

    pr1 = {4105103888, randomQuestion(4105103888)};
    mp1.populate(pr1);
 
    pr1 = {5256004563, randomQuestion(5256004563)};
    mp1.populate(pr1);

    pr1 = {2105103450, randomQuestion(2105103450)};
    mp1.populate(pr1);
 
    pr1 = {3256004999, randomQuestion(3256004999)};
    mp1.populate(pr1); 

    ///  Uncomment the following two lines. An error message should prompt
    ///  because of duplicated key
    cout << endl << "***Duplicated key***" << endl;
    mp1.populate(pr1);

    pr1 = {6105177747, randomQuestion(6105177747)};
    mp1.populate(pr1);
    ///  Uncomment two following three lines. An error message should prompt
    ///  because of out of bound

    cout << endl << "***Out of bound***" << endl;
    pr1 = {7105177747, randomQuestion(6105177747)};
    mp1.populate(pr1);

    ///  Display all items in the form like
    ///   key1 -> value1
    ///   key2 -> value2
    ///   ...
    ///   The keys must be sorted.
    mp1.displayAll();

    ///  Implement operator[ ]() function and uncomment the following line for
    ///  testing
    pr1 =  mp1[5];

    cout << endl << endl << "Test overload op []" << endl;
    cout << pr1.first << " -> " << pr1.second << endl<< endl;


    myMap<long long, int> mp2;
    pair<long long, int> pr2 = {1256004567, randomPrize(2105103450)};

    mp2.populate(pr2);
    pr2 = {2105103450, randomPrize(2105103450)};

    mp2.populate(pr2);
    pr2 = {3256004999, randomPrize(3256004999)};

    mp2.populate(pr2);
    pr2 = {4105103888, randomPrize(4105103888)};

    ///  Display three items
    mp2.displayAll();
    cout << endl << endl << "Test overloading op []" << endl;

    /// Uncomment the following line for testing
    /// An error message should prompt since the item does not exist.
    pr2 =  mp2[5];
    return 0;

}

string randomQuestion(long long seed){
    string arr[10] =
    {
        "Which city is the capital of California?",
        "Which city is the capital of Japan?",
        "Which city is the capital of Mexico?",
        "Which city is the capital of Canada?",
        "Which city is the capital of South Africa?",
        "Which city is the capital of France?",
        "Which city is the capital of Netherlands?",
        "Which city is the capital of Argentina?",
        "Which city is the capital of Arizona?",
        "Which city is the capital of Colorado?"
    };

    string q = "which";
    /// ADD YOUR CODE HERE.
    /// By using the value of the provided "seed" as the seed, the function should
    /// randomly return a question
    srand(seed);
    q = arr[rand() % 10];
    return q;

}

 

int randomPrize(long long seed){
    int pz = 0;
    /// ADD YOUR CODE HERE.
    /// By using the value of the provided "seed" as the seed of rseed(),
    /// the function should randomly return a prize, which is either
    /// 500, 1000, 1500, 2000, 2500, 3000, or 3500.
    /// Short is better. Can you do this WITHOUT using an data structure like that
    /// in randomQuestion()?
    srand(seed);
    pz = (rand() % 7 + 1) * 500;
    return pz;

}