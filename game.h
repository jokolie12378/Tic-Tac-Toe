#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

const int BOARD_SIZE = 3; // Define the size of the board

class TicTacToe {
public:
    TicTacToe(); // Constructor to create the game
    void playGame(); // Starts the game and controls the flow

private:
    char board[BOARD_SIZE][BOARD_SIZE]; // Board array to store the game state
    char currentPlayer; // Current player ('X' or 'O')

    void displayBoard(); // Displays the current state of the board
    bool placeMarker(int row, int col); // Places a marker ('X' or 'O') on the board
    bool checkWin(); // Checks if a player has won
    bool checkDraw(); // Checks if there is a draw (no more moves available)
    void switchPlayer(); // Switches to the other player
    int getPosition(); // Gets the position input from the user (1 to 9)
};

#endif //TIC_TAC_TOE_GAME_H