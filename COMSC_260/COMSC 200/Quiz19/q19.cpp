#include <iostream>
#include <cmath>
using namespace std;
class Timer{
    protected:
        int setting;
        int current;
    public:
        Timer(int s){
            setting = s;
            current = s;
        }
        virtual void OneTick(){
            current--;
        }
        virtual bool Done() const{
            return (current == 0);
        }
        virtual void Reset(){
            current = setting;
        }
        void Go(){
            while (this->Done() == false){
                cout << current << "*";
                this->OneTick();
            }
            cout << "ding!\n";
        }
};
class UpwardCounter : public Timer{
    public:
        UpwardCounter(int s) : Timer(s){
            current = 0;
        }
        virtual void OneTick(){
            current++;
        }
        virtual bool Done() const{
            return (current >= setting);
        }
        virtual void Reset(){
            current = 0;
        }
};
class MultCounter : public UpwardCounter{
    protected:
        int mult;
    public:
        MultCounter(int s, int m) : UpwardCounter(s){
            mult = m;
            current = 1;
        }
        virtual void OneTick(){
            current = current * mult;
        }
        virtual void Reset(){
            current = 1;
        }
};

class ExpoCounter : public MultCounter{
    public:
        ExpoCounter(int s):MultCounter(s, 1){
        }
        virtual void OneTick(){
            mult++;
            current = mult * mult;
        }
        virtual void Reset(){
            current = 1;
            mult = 1;
        }
        
};
int main()
{
    cout << "Part 1: testing Timer\n";
    Timer timerA(4);
    timerA.Go();
    cout << "\n";
    cout << "Part 2: testing UpwardCounter\n";
    UpwardCounter upA(4);
    upA.Go();
    cout << "\n";
    cout << "Part 3: testing MultCounter\n";
    MultCounter multC(8, 2);
    multC.Go();
    MultCounter multD(20, 3);
    multD.Go();
    cout << "\n";
    cout << "Part 4: testing Timer Reset()\n";
    timerA.Reset();
    timerA.Go();
    cout << "\n";
    cout << "Part 5: testing UpwardCounter Reset()\n";
    upA.Reset();
    upA.Go();
    cout << "\n";
    cout << "Part 6: testing MultCounter Reset()\n";
    multD.Reset();
    multD.Go();
    cout << "\n";
    cout << "Part 7: testing ExpoCounter\n";
    ExpoCounter ec1(100);
    ec1.Go();   
    cout << "\n";
    cout << "Part 8: testing ExpoCounter Reset()\n";
    ec1.Reset();
    ec1.Go();
    return 0;
}