/**
 * Link to Document: https://docs.google.com/document/d/1JxkQBB8kODHxy3f-1m9JrfhidTOAz4D2UToywfcMoGQ/edit?usp=share_link 
 * **/

#include <iostream>
#include <map>
#include <string>
#include <random>

using namespace std;

const int BOARD_SIZE = 10;
const int SHIP_SIZE = 3;
const int NUM_SHIPS = 5;

enum class CellState { Empty, Filled, Miss, Hit };

map <char, int>coordinates{
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9}
};

struct Ship{
    pair<int, int> coords[SHIP_SIZE];
    bool vert = false;
    bool sunk = false;
};

class Board {
    public:
        map<int, Ship> shipMap;
        int shipsLeft = NUM_SHIPS;

        Board() {
            for(int i = 0; i < BOARD_SIZE; i++) {
                for(int j = 0; j < BOARD_SIZE; j++) {
                    board[i][j] = CellState::Empty;
                }
            }
        }

        void placeShip(int x, int y, bool isVertical, int num) {
            // TODO: Place a ship on the board
            shipMap[num].vert = isVertical;
            for(int i = 0; i < SHIP_SIZE; i++){
                if(isVertical){
                    board[x][y+i] = CellState::Filled;
                    shipMap[num].coords[i] = {x, y+i};
                }else{
                    board[x+i][y] = CellState::Filled;
                    shipMap[num].coords[i] = {x+i, y};
                }
            }
        }

        bool isShipSunk(int x, int y) {
            // TODO: Check if a ship is sunk at the given coordinates
            for(int i = 0; i < NUM_SHIPS; i++){
                for(int j = 0; j < 3; j++){
                    if(shipMap[i].coords[j] == pair<int, int>{x, y}){
                        for(int k = 0; k < SHIP_SIZE; k++){
                            if(board[shipMap[i].coords[k].first][shipMap[i].coords[k].second] == CellState::Filled){
                                return false;
                            }
                        }
                        shipMap[i].sunk = true;
                        shipsLeft--;
                        return true;
                    }
                }
            }
            return false;
        }

        bool isGameOver() {
            // TODO: Check if the game is over
            if(shipsLeft == 0)
            return true;
        }

        void print(bool showShips) {
            // Print the board to the terminal
            cout << "    A B C D E F G H I J" << endl;
            if(showShips){
                for(int i = 0; i < BOARD_SIZE; i++){
                    cout.width(3);
                    cout << i+1 << "|";
                    for(int j = 0; j < BOARD_SIZE; j++){
                        if(board[j][i] == CellState::Empty){
                            cout << " |";
                        }if(board[j][i] == CellState::Filled){
                            cout << "S|";
                        }if(board[j][i] == CellState::Hit){
                            cout << "X|";
                        }if(board[j][i] == CellState::Miss){
                            cout << "O|";
                        }
                    }
                    cout << endl;
                }
            }else{
                for(int i = 0; i < BOARD_SIZE; i++){
                    cout.width(3);
                    cout << i+1 << "|";
                    for(int j = 0; j < BOARD_SIZE; j++){
                        if(board[j][i] == CellState::Empty || board[j][i] == CellState::Filled){
                            cout << " |";
                        }if(board[j][i] == CellState::Hit){
                            cout << "X|";
                        }if(board[j][i] == CellState::Miss){
                            cout << "O|";
                        }
                    }
                    cout << endl;
                }
            }
        }

        CellState shoot(int x, int y) {
            if(board[x][y] == CellState::Empty) {
                board[x][y] = CellState::Miss;
                return CellState::Miss;
            } else {
                board[x][y] = CellState::Hit;
                return CellState::Hit;
            }
        }

        CellState getState(int x, int y){
            return board[x][y];
        }

    private:
        CellState board[BOARD_SIZE][BOARD_SIZE];
    };

    class Player {
    public:
        virtual void placeShips(Board& board) = 0;
        virtual pair<int, int> makeMove(Board& board) = 0;
    };

    class HumanPlayer : public Player {
    public:
        void placeShips(Board& board) override {
            // TODO: Ask the player to place their ships on the board
            for(int i = 1; i <= NUM_SHIPS; i++){
                int x, y;
                char vertical, xChar;
                string buf;
                while(true){
                    system("cls");
                    board.print(true);
                    cout << "Input the x-coordinate of ship " << i << "[a to j]:";
                    cin >> xChar;
                    cin.ignore(1, '\n');
                    x = coordinates.find(tolower(xChar))->second;
                    cout << "Input the y-coordinate of ship " << i << "[1 to 10]:";
                    getline(cin, buf);
                    y = stoi(buf);
                    cout << "Is the ship placed horizontally or vertically?[H/h - horizontal, V/v - vertical]:";
                    cin >> vertical;
                    cin.ignore(1, '\n');
                    bool found = false;
                    for(int k = 1; k <= NUM_SHIPS; k++){
                        for(int j = 0; j < 3; j++){
                            if(pair<int, int>{x, y-1} == board.shipMap[k].coords[j]){
                                found = true;
                            }
                        }
                    }
                    if(x >= 0 && x+2 < BOARD_SIZE && y >= 0 && y+2 < BOARD_SIZE && !found){
                        if(tolower(vertical) == 'h'){
                            board.placeShip(x, y-1, false, i);
                            break;
                        }if(tolower(vertical) == 'v'){
                            board.placeShip(x, y-1, true, i);
                            break;
                        }
                    }
                    cout << "Invalid input." << endl;
                }
            }
        }

        pair<int, int> makeMove(Board& board) override {
            // TODO: Ask the player to make a move
            int x, y;
            string buf;
            char xChar;
            cout << "Input the x-coordinate of shot [a to j]:";
            cin >> xChar;
            cin.ignore(1, '\n');
            x = coordinates.find(tolower(xChar))->second;
            cout << "Input the y-coordinate of shot [1 to 10]:";
            getline(cin, buf);
            y = stoi(buf);
            cout << "Shooting at (" << xChar << y << ")" << endl;
            return {x, y-1};
        }
};

class AIPlayer : public Player {
public:
    void placeShips(Board& board) override {
        // TODO: Place the AI's ships on the board
        for(int i = 0; i < NUM_SHIPS; i++){
            while(true){
                uniform_int_distribution<int> dist(0, 9);
                int x = dist(gen), y = dist(gen);
                bool found = false;
                for(int k = 0; k < NUM_SHIPS; k++){
                    for(int j = 0; j < SHIP_SIZE; j++){
                        if(pair<int, int>{x, y} == board.shipMap[k].coords[j]){
                            found = true;
                        }
                    }
                }
                if(x >= 0 && x+2 < BOARD_SIZE && y >= 0 && y+2 < BOARD_SIZE && !found){
                    if(tolower(x % 2) == 0){
                        board.placeShip(x, y, false, i);
                        break;
                    }else{
                        board.placeShip(x, y, true, i);
                        break;
                    }
                }
            }
        }
    }

    pair<int, int> makeMove(Board& board) override {
        // TODO: Have the AI make a move
        bool valid = false;
        while(!valid){
            uniform_int_distribution<int> dist(0, 9);
            int x = dist(gen), y = dist(gen);
            if(board.getState(x, y) == CellState::Empty){
                valid = true;
                cout << "I am shooting at (" << x << ", " << y << ")" << endl;
                return {x, y};
            }
        }
    }

private:
    random_device rd;
    mt19937 gen{rd()};
};

int main() {
    Board humanBoard, aiBoard;
    HumanPlayer humanPlayer;
    AIPlayer aiPlayer;
    humanPlayer.placeShips(humanBoard);
    aiPlayer.placeShips(aiBoard);
    bool humanTurn = true;
    bool playAgain = true;
    while(playAgain){
        while(!humanBoard.isGameOver() && !aiBoard.isGameOver()) {
            if(humanTurn) {
                cout << "CPU(" << aiBoard.shipsLeft << " ships left):" << endl;
                aiBoard.print(false);
                cout << endl << "Player 1(" << humanBoard.shipsLeft << " ships left):" << endl;
                humanBoard.print(true);
                auto move = humanPlayer.makeMove(aiBoard);
                auto result = aiBoard.shoot(move.first, move.second);
                if(result == CellState::Miss) {
                    cout << "You missed!" << endl;
                } else {
                    cout << "You hit!" << endl;
                    if(aiBoard.isShipSunk(move.first, move.second)) {
                        cout << "You sunk my ship!" << endl;
                    }
                }
                humanTurn = false;
                cout << "End turn" << endl;
            } else {
                auto move = aiPlayer.makeMove(humanBoard);
                auto result = humanBoard.shoot(move.first, move.second);
                if(result == CellState::Miss) {
                    cout << "I missed!" << endl;
                } else {
                    cout << "I hit!" << endl;
                    if(humanBoard.isShipSunk(move.first, move.second)) {
                        cout << "I sunk your ship!" << endl;
                    }
                }
                humanTurn = true;
            }
        }
        cout << "Game Over. Play again?[y/n]" << endl;
        string answer;
        getline(cin, answer);
        if(answer == "n"){
            playAgain = false;
        }
    }
}