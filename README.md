# Tic-Tac-Toe
C++ Program

A console-based, two-player Tic Tac Toe game built with C++. Players X and O take turns entering positions on a 3x3 grid until one wins by lining up three in a row or the game ends in a draw. The game’s logic is organized with classes for clean and maintainable code.

**Overview**
This C++ program provides a straightforward Tic Tac Toe game with a simple text interface. The game features player turn tracking, win and draw detection, and move validation to ensure smooth gameplay.

**Features**
Interactive Gameplay: Players X and O take turns entering their moves.
Automatic Win/Draw Detection: Recognizes and announces the game outcome.
Modular Design: Uses a TicTacToe class to handle game logic.
Clear Console Output: Displays the current game board after each move.

**How to Play**
Start: The game begins with Player X.
Turn-Based Play: Players enter numbers (1-9) corresponding to the grid positions to place their marks.
Win or Draw: The game checks after each turn for a winner or a draw.

**Code Structure**
main.cpp: Starts the game and manages player turns.
TicTacToe.h: Header file defining the TicTacToe class.
TicTacToe.cpp: Contains the implementation for game logic, including move validation, board updates, and win/draw checks.
