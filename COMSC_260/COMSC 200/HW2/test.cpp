#include <iostream>
#include <string>

using namespace std;

struct Move{
    /**
     * Type References:
     * 1 - Fire
     * 2 - Water
     * 3 - Grass
     * **/
    string name = "";
    int type = 1;
    int base = 20;
};

class Pokemon{
    Move *moves[4];
    public:
        Pokemon(){

        }
        ~Pokemon(){
            for(int i = 0; i < 4; i++){
                delete moves[i];
            }
        }
        string name = "";
        int type = 1;
        int hp = 100;
        void addMove(Move newMove){
            Move *temp= new Move;
            *temp = newMove;
            for(int i = 0; i < 6; i++){
                if(moves[i] != nullptr){
                    moves[i] = temp;
                }
            }
        }
        Move getMoves(int index){
            return *moves[index];
        }

        float typeMultiplier(int moveType, int opponentType){
            float dmgMult = 1;
            if(moveType == type){
                dmgMult += 0.2;
            }
            switch(moveType){
                case 1:
                    break;
                default:
                    break;
            }
            return dmgMult;
        }

        void attack(Pokemon target, int moveIndex){ 
            Move attackStruct = *moves[moveIndex];
            cout << name << "used " << attackStruct.name << endl;
            int damage = round(attackStruct.base * typeMultiplier(attackStruct.type, target.type));
            target.hp -= damage;
        }
};

class Trainer{
    Pokemon *party[6] = {nullptr};
    public:
        string name = "";
        int active = 0;
        Trainer();
        ~Trainer(){
            for(int i = 0; i < 6; i++){
                delete party[i];
            }
        }
        void addPokemon(Pokemon pkmn){
            Pokemon *temp = new Pokemon;
            *temp = pkmn;
            for(int i = 0; i < 6; i++){
                if(party[i] != nullptr){
                    party[i] = temp;
                }
            }
        }
        Pokemon getPokemon(int index){
            return *party[index];
        }
        void setActive(int i){
            active = i;
        }
};

void turn(int &turnNum, Trainer *trainers){
    int player = turnNum % 2;
    if(player == 0){
        cout << "It's Player 1's turn!" << endl;
        cout << "Selct a move to use(1-4):" << endl;
        for(int i = 0; i < 4; i++){
            cout << i <<") " << trainers[player].getPokemon(trainers[player].active).getMoves(i).name << endl;
        }
        cout << "Your Selection: ";
        int selection;
        cin >> selection;
        cin.ignore(2, '\n');
        if(selection >= 0 && selection < 4){

        }else{
            cout << "Invalid input.";
        }

    }else{
        cout << "It's Player 2's turn!" << endl;
    }
}

void battle(Trainer *trainers){
    bool ongoing = true;
    int turnNo = 0;
    while(ongoing){
        turn(turnNo, trainers);
    }
}

int main(){
    Trainer player1;
    Trainer player2;
    Pokemon charmander;
    charmander.name = "Charmander";
    Pokemon bulbasaur;
    bulbasaur.addMove({"Vine Whip", 3, 40});
    charmander.addMove({"Ember", 1, 40});
    player1.addPokemon(charmander);
    player2.addPokemon(bulbasaur);
    Trainer battlefield[2] = {player1, player2};

}