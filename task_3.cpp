#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameover = false;
    char playAgain = ' ';

    do {
        initializeBoard(board);
        displayBoard(board);

        while (!gameover) {
            int row, col;
            do {
                cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                cin >> row >> col;
            } while (!isMoveValid(board, row, col));

            board[row][col] = currentPlayer;
            displayBoard(board);

            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameover = true;
            } else if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                gameover = true;
            } else {
                switchPlayer(currentPlayer);
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

        if (playAgain == 'Y') {
            gameover = false;
        }

    } while (playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        return true;
    } else {
        return false;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
