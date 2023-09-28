/**
 * Question 4a: There are two ways to use static member functions to increase/decrease the number of ships by "x".
 * Type 1(getter/setter):
 * static int getNumCruiseShips(){
 *      return numCruiseShips;
 * }
 * static void setNumCruiseShips(int num){
 *      numCruiseShips = num;
 * }
 * setNumCruiseShips(getNumCruiseShips() + x);
 * setNumCruiseShips(getNumCruiseShips() - x);
 * 
 * Type 2(dedicated increase/decrease functions):
 * static void increaseNumCruiseShips(int num){
 *      numCruiseShips += num;
 * }
 * static void decreaseNumCruiseShips(int num){
 *      numCruiseShips -= num;
 * }
 * increaseNumCruiseShips(x);
 * decreaseNumCruiseShips(x);
 * 
 * Type 1 is more robust, as it uses only setter and getter functions which can be used for other purposes. This can save a lot of time if we have multiple
 * ships. Type 2 is more readable and requires only 1 function call rather than 2. This is the "cleaner" version.
 * 
 * Question 4b: We prefer to use static varibles over global variables because of encapsulation. The static variables containing the number and capacities
 * of the ships can only be accessed by Ship classes. Therefore, it is safe from outside influences in main or the manager classes. We prefer to use
 * static variables over local variables in the displayAll() function because it allows us to use this information elsewhere. Perhaps we want a third
 * report that outside of the class' scope. If we store it locally, this information cannot be used. Finally, we prefer to use static variables
 * over variables in the Manager class for the same reason. Perhaps the ship class has multiple manager classes that needs the total capacity information.
 * The static varables allow all the manager classes to access it, while if it is stored locally in the manager class, would need to be reiterated for each
 * manager class.
 * 
 * Question 4c: We would sometimes like to just store the total capacity in the manager class if we know the information is only going to be used
 * in that one particular manager class. This allows the ship class to be cleaner and doesn't store unneccesary data that won't be used in other
 * manager classes. In the case of this project, storing the capacity data in the manager class would have been okay because there was only one manager
 * class and it used the capacity data.
**/

#include <iostream>
#include <fstream>

using namespace std;

class Ship{
    int serialNum, year, type;
    string name;
    static int numCruiseShips;
    static int numCargoShips;
    static int capCruiseShips;
    static int capCargoShips;
    public:
        Ship *next = nullptr;
        Ship(){
            serialNum = 0;
            type = -1;
            name = "";
            year = 0;
        }
        Ship(int ser, int ty, string nme, int yr){
            serialNum = ser;
            type = ty;
            name = nme;
            year = yr;
        }
        int getSerialNumber(){
            return serialNum;
        }
        int getYear(){
            return year;
        }
        int getType(){
            return type;
        }
        string getName(){
            return name;
        }
        virtual int getCapacity() = 0;
        static int getNumCruiseShips(){
            return numCruiseShips;
        }
        static int getNumCargoShips(){
            return numCargoShips;
        }
        static int getCapCruiseShips(){
            return capCruiseShips;
        }
        static int getCapCargoShips(){
            return capCargoShips;
        }
        static void setNumCruiseShips(int num){
            numCruiseShips = num;
        }
        static void setNumCargoShips(int num){
            numCargoShips = num;
        }
        static void setCruiseShipCap(int size){
            capCruiseShips = size;
        }
        static void setCargoShipCap(int size){
            capCargoShips = size;
        }
        virtual void display() = 0;
};

int Ship::numCruiseShips = 0;
int Ship::numCargoShips = 0;
int Ship::capCruiseShips = 0;
int Ship::capCargoShips = 0;

class CruiseShip : public Ship{
    int capacity;
    public:
        CruiseShip(int ser, int ty, string nme, int yr, int cap):Ship(ser, ty, nme, yr){
            capacity = cap;
            this->setCargoShipCap(this->getCapCruiseShips() + cap);
            this->setCruiseShipCap(this->getNumCruiseShips() + 1);
        }
        ~CruiseShip(){
            this->setCargoShipCap(this->getCapCruiseShips() - this->capacity);
            this->setCruiseShipCap(this->getNumCruiseShips() - 1);
        }
        virtual int getCapacity(){
            return capacity;
        }
        virtual void display(){
            cout.width(4);
            //output the serial number
            cout << this->getSerialNumber();
            //format the column
            cout.width(16);
            //output the ship name
            cout << this->getName();
            //format the column
            cout.width(4);
            //output the ship build year
            cout << this->getYear();
            //format the column
            cout.width(5);
            //output the ship capacity
            cout << this->getCapacity() << endl;
            //line break for aesthetics
            cout << "\n";
        }

};

class CargoShip : public Ship{
    int capacity;
    public:
        CargoShip(int ser, int ty, string nme, int yr, int cap):Ship(ser, ty, nme, yr){
            capacity = cap;
            this->setCargoShipCap(this->getCapCargoShips() + cap);
            this->setNumCargoShips(this->getNumCargoShips() + 1);
        }
        ~CargoShip(){
            this->setCargoShipCap(this->getCapCargoShips() - this->capacity);
            this->setNumCargoShips(this->getNumCargoShips() - 1);
        }
        virtual int getCapacity(){
            return capacity;
        }
        virtual void display(){
            cout.width(4);
            //output the serial number
            cout << this->getSerialNumber();
            //format the column
            cout.width(16);
            //output the ship name
            cout << this->getName();
            //format the column
            cout.width(5);
            //output the ship build year
            cout << this->getYear();
            //format the column
            cout.width(6);
            //output the ship capacity
            cout << this->getCapacity() << endl;
            //line break for aesthetics
            cout << "\n";
        }
};

class ShipMgr{
    Ship *shipRecord[2] = {nullptr};
    public:
        ShipMgr(){
            ifstream inputFile;
            int serial, year, type, capacity;
            string name;
            Ship* newShip;
            inputFile.open("shipRecords.txt", ios::in);
            if(inputFile.is_open()){
                while(!inputFile.eof()){
                    inputFile >> serial >> type >> name >> year >> capacity;
                    if(type == 1){
                        newShip = new CruiseShip(serial, type, name, year, capacity);
                        Ship* head = shipRecord[0];
                        newShip->next = head;
                        shipRecord[0] = newShip;
                    }
                    if(type == 2){
                        newShip = new CargoShip(serial, type, name, year, capacity);
                        Ship* head = shipRecord[1];
                        newShip->next = head;
                        shipRecord[1] = newShip;
                    }
                }
            }

        }
        ~ShipMgr(){
            for(int i = 0; i < 2; i++){
                Ship *p = shipRecord[i];
                while(p != nullptr){
                    Ship *q = p->next;
                    delete p;
                    p = q;
                }
            }
        }
        void deleteOneShip(int serial){
            for(Ship *node = shipRecord[0], *prev = nullptr; node; prev = node, node = node->next){
                if(node->getSerialNumber() == serial){
                    //case that serial is the head
                    if(prev == nullptr)
                        //set the head of the linked list to the next node
                            shipRecord[0] = node->next;
                    //if the serial is not the head
                    else
                        //link the previous node to the next node
                        prev->next = node->next;
                    //delete the current node
                    delete node;
                    //exit the loop
                    return;
                }
            }
            for(Ship *node = shipRecord[1], *prev = nullptr; node; prev = node, node = node->next){
                if(node->getSerialNumber() == serial){
                    //case that serial is the head
                    if(prev == nullptr)
                        //set the head of the linked list to the next node
                            shipRecord[1] = node->next;
                    //if the serial is not the head
                    else
                        //link the previous node to the next node
                        prev->next = node->next;
                    //delete the current node
                    delete node;
                    //exit the loop
                    return;
                }
            }
            cout << "Serial " << serial << " not found!" << endl;
        }
        void displayAll(){
            cout << "Cruise Ship********************************" << endl;
            cout << "   #            Name Year Passenger Amt" << endl;
            cout << "---- --------------- ---- -------------" << endl;
            for(Ship* node = shipRecord[0]; node; node = node->next){
                node->display();
            }
            cout << "========================================" << endl;
            cout << "Total # of cruise ships: " << shipRecord[0]->getNumCruiseShips() << endl;
            cout << "Max # of passengers: " << shipRecord[0]->getCapCruiseShips() << endl;
            cout << endl << endl;
            cout << "Cargo Ship********************************" << endl;
            cout << "   #             Name Year Cargo Capacity" << endl;
            cout << "---- ---------------- ---- --------------" << endl;
            for(Ship* node = shipRecord[1]; node; node = node->next){
                node->display();
            }
            cout << "========================================" << endl;
            cout << "Total # of cargo ships: " << shipRecord[0]->getNumCargoShips() << endl;
            cout << "Max cargo capacity: " << shipRecord[0]->getCapCargoShips() << endl;

        }
};

int main(){
    ShipMgr sm;
    cout << endl << endl;
    sm.displayAll();                      /// Display all 6 ships in two reports 
    sm.deleteOneShip(1009);   /// Delete the ship with the serial number 1009
    cout << endl << endl;
    sm.displayAll();                     /// Display all 5 ships in two reports 
    return 0;
}