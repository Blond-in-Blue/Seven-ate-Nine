//
//  main.cpp
//  Seven ate Nine
//
//  Created by Hunter Holder on 5/16/15.
//  Copyright (c) 2015 Hunter Holder. All rights reserved.
//

#include <iostream>
using namespace std;

const int battlefieldSize = 5;
char battlefield[battlefieldSize][battlefieldSize];


// populating the battlefield with stars and giving 7 and 9 random positions
void createBattlefield() {
    
    for (int i = 0; i < battlefieldSize; i++) {
        for (int j = 0; j < battlefieldSize; j++) {
            battlefield[i][j] = '*';
        }
    }
    
    // position of 7
    battlefield[rand() % battlefieldSize][rand() % battlefieldSize] = '7';
    // position of 9
    battlefield[rand() % battlefieldSize][rand() % battlefieldSize] = '9';
    
    cout << "\nGet into position!\n";
    for (int i = 0; i < battlefieldSize; i++) {
        for (int j = 0; j < battlefieldSize; j++) {
            cout << battlefield[i][j] << " ";
        }
        cout << '\n';
    }

}

// function used to start or restart the game
void beginBattle() {
    cout << "\nA new battle has begun!";
    createBattlefield();
}

// ask for the user's input (← ↑ → ↓), and move 7 to a random position
// if the positoin of 7 and the position of 9 match, then 7 wins
// I could make it so after a certain number of turns, 9 will win if 7 doesn't eat it
void commenceBattle(int moveNumber) {
    
    // position of 7
    battlefield[rand() % battlefieldSize][rand() % battlefieldSize] = '7';
    // position of 9
    cout << "\nMake your move Nine (← ↑ → ↓)\n";
    
    switch(getchar()) {
        case 65:
            cout << endl << "Up" << endl;//key up
            break;
        case 66:
            cout << endl << "Down" << endl;   // key down
            break;
        case 67:
            cout << endl << "Right" << endl;  // key right
            break;
        case 68:
            cout << endl << "Left" << endl;  // key left
            break;
    }
    
    cout << '\n' << " Move #" << moveNumber+1 << '\n';
    for (int i = 0; i < battlefieldSize; i++) {
        for (int j = 0; j < battlefieldSize; j++) {
            cout << battlefield[i][j] << " ";
        }
        cout << '\n';
    }
}

void restart() {
    char restartInput;
    cout << "\n\nPress Return to restart, or press / and then Return to end the game.";
    cin.get(restartInput);
    
    if (restartInput == '/') {
        beginBattle();
    }
    
    for (int i = 0; i<5; i++) {
        commenceBattle(i);
    }
    
    restart();
}

int main(int argc, const char * argv[]) {
    
    beginBattle();
    
    for (int i = 0; i<5; i++) {
        commenceBattle(i);
    }
    
    restart();
    
    cout << "\nThanks for playing! Farewell brave Nine!";
    return 0;
}

