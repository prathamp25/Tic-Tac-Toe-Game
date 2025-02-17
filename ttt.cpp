#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, col;

void displayBoard() {
    system("clear");
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

int main() {
    int move;
    while (true) {
        displayBoard();
        cout << "Enter your move (1-9): ";
        cin >> move;
        row = (move - 1) / 3;
        col = (move - 1) % 3;
        board[row][col] = turn;
        if (checkWin()) {
            displayBoard();
            cout << "Player " << turn << " wins!\n";
            break;
        }
        turn = (turn == 'X') ? 'O' : 'X';
    }
    return 0;
}
