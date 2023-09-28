#include <iostream>
#include <fstream>

using namespace std;

//ship record struct
struct ShipRecord{
    int serialNum = 0, shipType = 0, year = 0, cap = 0;//integer information about the ship
    string name = "";//string information about the ship
    ShipRecord* link = nullptr;//pointer for the linked list
};

//size of the hash table
const int SIZE = 10;

//Hash Manager class
class HashMgr{
    //initialize a hash table as an array of null pointers
    ShipRecord * hashTable[SIZE] = {nullptr};
    public:
        //Constructor for the manager class
        HashMgr(){
            //initialize a new shiprecord to store the input
            ShipRecord ship;
            //intialize the input filestream
            ifstream myfile;
            //open the text file called "shipRecords.txt" as an input file
            myfile.open("shipRecords.txt", ios::in);
            //check if file successfully opened
            if(myfile.is_open()){
                //iterate through lines until we reach the end of file
                while(!myfile.eof()){
                    //transfer the read data to the struct
                    myfile >> ship.serialNum >> ship.shipType >> ship.name >> ship.year >> ship.cap;
                    //add the information to the hash table
                    addInfo(ship);
                }
            //case could not open file
            }else{
                //notify the user
                cout << "Could not open the file" << endl;
            }
        }
        //Destructor for the manager class
        ~HashMgr(){
            //iterate through the hash table
            for(int i = 0; i < SIZE; i++){
                //check if the bucket is not empty
                if(hashTable[i] != nullptr){
                    //initialize the pointer p and set it to the pointer in the hash table
                    ShipRecord *p = hashTable[i];
                    //iterate through the linked list
                    while(p != nullptr){
                        //initialize the pointer q and set it to the next node in the linked list
                        ShipRecord *q = p->link;
                        //delete the pointer p
                        delete p;
                        //set the pointer p to the next node
                        p = q;
                    }
                }
            }
        }
        /***************************************************************
         * Function: add information to the hash table based on a given
         * ship record.
         **************************************************************/
        void addInfo(ShipRecord shipInfo){
            //calculate the bucket number
            int hash_number = shipInfo.serialNum % 10;
            //create a new pointer to enter into the hash table
            ShipRecord *temp = new ShipRecord;
            //set the pointer to point to the address of the read data
            *temp = shipInfo;
            //link the new node of the linked list to the bucket
            temp->link = hashTable[hash_number];
            //set the new node as the head
            hashTable[hash_number] = temp;
        }
        /***************************************************************
         * Function: display information from the hash table about a
         * certain ship given a serial number
         **************************************************************/
        void displayOne(int serial){
            //calculate the bucket number
            int hash_number = serial % 10;
            //check to make sure the bucket isn't empty
            if(hashTable[hash_number] != nullptr){
                //Display the bucket number
                cout << "Bucket #" << hash_number << endl;
                //Table break
                cout << "--------------------------------" << endl;
                //linear search for serial
                for(ShipRecord *node = hashTable[hash_number]; node; node = node->link){
                    //check if serials match
                    if(node->serialNum == serial){
                        //format the column
                        cout.width(4);
                        //output the serial number
                        cout << node->serialNum;
                        //format the column
                        cout.width(2);
                        //output the ship type
                        cout << node->shipType;
                        //format the column
                        cout.width(16);
                        //output the ship name
                        cout << node->name;
                        //format the column
                        cout.width(5);
                        //output the ship build date
                        cout << node->year;
                        //format the column
                        cout.width(5);
                        //output the capacity
                        cout << node->cap << endl;
                        //exit the linear search
                        break;
                    }
                }
                //line spacing for aesthetics
                cout << "\n";
            }else{
                cout << "No serials are located in Bucket #" << hash_number << endl;
            }
        }
        /***************************************************************
         * Function: display all information in the hash table
         **************************************************************/
        void displayAll(){
            //iterate through the hash table
            for(int i = 0; i < SIZE; i++){
                //check if the bucket is empty
                if(hashTable[i] != nullptr){
                    //Displa bucket number
                    cout << "Bucket #" << i << endl;
                    //Table break
                    cout << "--------------------------------" << endl;
                    //iterate through the linked list
                    for(ShipRecord *node = hashTable[i]; node; node = node->link){
                        //format the column
                        cout.width(4);
                        //output the serial number
                        cout << node->serialNum;
                        //format the column
                        cout.width(2);
                        //output the ship type
                        cout << node->shipType;
                        //format the column
                        cout.width(16);
                        //output the ship name
                        cout << node->name;
                        //format the column
                        cout.width(5);
                        //output the ship build year
                        cout << node->year;
                        //format the column
                        cout.width(5);
                        //output the ship capacity
                        cout << node->cap << endl;
                    }
                    //line break for aesthetics
                    cout << "\n";
                }
            }
        }
        /***************************************************************
         * Function: delete a record of a ship from the hash table given
         * a certain serial number
         **************************************************************/
        void deleteOne(int serial){
            //calclate the bucket number
            int hash_number = serial % 10;
            //check to make sure there are pointers in the bucket
            if(hashTable[hash_number] != nullptr){
                //iterate through the linked list to do a linear search
                for(ShipRecord *node = hashTable[hash_number], *prev = nullptr; node != nullptr; prev = node, node = node->link){
                    //check to see if the serial numbers match
                    if(node->serialNum == serial){
                        //case that serial is the head
                        if(prev == nullptr)
                            //set the head of the linked list to the next node
                             hashTable[hash_number] = node->link;
                        //if the serial is not the head
                        else
                            //link the previous node to the next node
                            prev->link = node->link;
                        //delete the current node
                        delete node;
                        //exit the loop
                        break;
                    }
                }
            }
        }

};

int main(){
    HashMgr hm; 
    cout << "dispalyAll()" << endl << endl;   
    hm.displayAll(); 
    cout << "dispalyOne()" << endl << endl;  
    hm.displayOne(1009); 
    hm.displayOne(1010); 
    hm.displayOne(1019); 
    hm.displayOne(1029); 
    hm.displayOne(1039); 
    hm.displayOne(1014); 
    hm.displayOne(1008); /// Prompt a message to that the record does not exist 
    hm.deleteOne(1009); 
    hm.deleteOne(1039);  
    cout << "dispalyAll()" << endl << endl;   
    hm.displayAll(); 
    return 0;
}
