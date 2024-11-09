#include <iostream>
#include "Game/game.h"

using namespace std;

// Initializes the board and sets the first player
TicTacToe::TicTacToe() {
    currentPlayer = 'X'; // Starts player 1 with 'X'

    // Make board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Displays current board
void TicTacToe::displayBoard() {
    cout << "Current Board: " << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Places a marker on the board ('X' or 'O' at a specified row and column)
bool TicTacToe::placeMarker(int row, int col) {
    // Check if position is valid (within bounds and not taken)
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
        board[row][col] = currentPlayer; // Place the marker
        return true; // Successful placement
    }
    return false; // Invalid placement
}

// Checks if a player has won
bool TicTacToe::checkWin() {
    // Check rows and columns for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board [2][i] == currentPlayer) return true;
    }

    // Check diagonals for a win
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

    return false;  // No win
}

// Checks if the game is a draw
bool TicTacToe::checkDraw() {
    // Check if there's any empty space left on the board
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (board[i][j] == ' ') return false;
    return true;  // Draw if no empty space left
}

// Switches the current player
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Gets the position input from user and returns it
int TicTacToe::getPosition() {
    int position;
    std::cout << "Enter a position (1-" << BOARD_SIZE * BOARD_SIZE << "): ";
    std::cin >> position;
    return position - 1; // Convert to 0-based index
}

// Starts the game and controls the flow
void TicTacToe::playGame() {
    int row, col;
    bool gameOver = false;

    // Loop until the game ends (win or draw)
    while (!gameOver) {
        displayBoard();  // Display the current state of the board
        int pos = getPosition();  // Get the user's position input
        row = pos / BOARD_SIZE;  // Calculate the row index
        col = pos % BOARD_SIZE;  // Calculate the column index

        // If the position is invalid, ask the player to try again
        if (!placeMarker(row, col)) {
            std::cout << "Invalid position. Try again.\n";
            continue;
        }

        // Check for win or draw after the move
        if (checkWin()) {
            displayBoard();  // Display the final board
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        else if (checkDraw()) {
            displayBoard();  // Display the final board
            std::cout << "It's a draw!\n";
            gameOver = true;
        }
        else {
            switchPlayer();  // Switch to the next player
        }
    }
}
