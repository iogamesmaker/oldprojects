#include <iostream>
#include <string>
using namespace std;

struct Coordinate {
    int x;
    int y;
};

bool isCoordinateValid(Coordinate c, string board[3][3]) {
    // Check if the coordinate is valid
    if (c.x < 1 || c.x > 3) return false;
    if (c.y < 1 || c.y > 3) return false;

    // Check if there's already a stone on the field
    if (board[c.x - 1][c.y - 1] == "_") {
        return true;
    } else {
        cout << "There's already a stone here. Please enter a valid coordinate.\n";
        return false;
    }
}

bool isBoardFull(string board[3][3]) {
    int aant = 0;
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (board[k][l] == "_") {
                aant++;
            }
        }
    }
    return (aant == 0);
}

Coordinate NewTurn(string player, string board[3][3]) {
    int x, y;
    int pos;
    Coordinate c;
    string coord;
    string str1, str2;

    while (!isCoordinateValid(c, board)) {
        cout << player << ", choose a field for your stone, describe it with coordinates x-y (e.g., 2-3)\n";
        cin >> coord;
        pos = coord.find("-"); // position of "-" in str
        str1 = coord.substr(0, pos); // get from the start to the "-" to the end
        str2 = coord.substr(pos + 1); // get from "-" to the end
        x = stoi(str1);
        y = stoi(str2);
        c.x = x;
        c.y = y;
    }
    return c;
}

void displayBoard(string board[3][3]) {
    for (int t = 2; t >= 0; t--) {
        cout << board[0][t] << " | " << board[1][t] << " | " << board[2][t] << endl;
    }
}

bool isWinner(string board[3][3], string color) {
    bool win = false;

    // Check vertically
    for (int k = 0; k < 3; k++) {
        if (board[k][0] == color && board[k][1] == color && board[k][2] == color) {
            win = true;
        }
    }

    // Check horizontally
    for (int k = 0; k < 3; k++) {
        if (board[0][k] == color && board[1][k] == color && board[2][k] == color) {
            win = true;
        }
    }

    // Check diagonally
    if (board[0][0] == color && board[1][1] == color && board[2][2] == color) {
        win = true;
    }
    if (board[0][2] == color && board[1][1] == color && board[2][0] == color) {
        win = true;
    }

    return win;
}

int main() {
    bool continueGame;
    bool validInput;
    string output;
    string player1, player2;
    string grid[3][3] = {
        {"_", "_", "_"},
        {"_", "_", "_"},
        {"_", "_", "_"}
    };
    Coordinate c;

    cout << "You are going to play a game of Tic-Tac-Toe. Enter the name of Player 1:\n";
    getline(cin, player1);

    cout << "Enter the name of Player 2:\n";
    getline(cin, player2);

    cout << "\nPlayer 1: " << player1 << "\tPlayer 2: " << player2 << "\n\n";
    cout << "The game is about to begin!\n";
    continueGame = true;

    while (continueGame) {
        c = NewTurn(player1, grid);
        grid[c.x - 1][c.y - 1] = "O";
        displayBoard(grid);

        if (isWinner(grid, "O")) {
            continueGame = false;
            cout << "Congratulations, " << player1 << " has won!";
        } else {
            if (isBoardFull(grid)) {
                cout << "It's a draw! No one wins.";
                return 0;
            }

            c = NewTurn(player2, grid);
            grid[c.x - 1][c.y - 1] = "X";
            displayBoard(grid);

            if (isWinner(grid, "X")) {
                continueGame = false;
                cout << "Congratulations, " << player2 << " has won!";
            } else {
                if (isBoardFull(grid)) {
                    cout << "It's a draw! No one wins.";
                    return 0;
                }
            }
        }
    }
    return 0;
}
