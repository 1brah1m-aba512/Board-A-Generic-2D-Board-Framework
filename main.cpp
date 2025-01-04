#include "Board.h"

#include <iostream>

using namespace std;

int main() {

    // Create a UJBoard of UJPixel (3x3 board)
    Board<Pixel> board(3, 3);

    // Set a pixel at a specific location
    Pixel pixel = {200, 100, 50};
    board.setPixel(2, 2, pixel);

    // Output the board using the overloaded << operator
    cout << "Initial board state:" << endl;
    cout << board;
    cout <<" "<<endl;

    // Accessing and modifying values using the overloaded [] operator
    Pixel newPixel = {100, 150, 200};
    board[1][2] = newPixel;
    cout << "After setting pixel at [1][2]:" << endl;
    cout << board;
    cout <<" "<<endl;

    // Demonstrate deep copy with the assignment operator (=)
    Board<Pixel> copiedBoard = board;
    cout << "Copied board state:" << endl;
    cout << copiedBoard;
    cout <<" "<<endl;

    // Modify the original board and show the copied board remains unchanged
    board[2][0] = {50, 50, 255};
    cout << "After modifying original board at [2][0]:" << endl;
    cout << "Original board:" << endl;
    cout << board;
    cout <<" "<<endl;

    cout << "Copied board (should be unchanged):" << endl;
    cout << copiedBoard;
    cout <<" "<<endl;

    // Demonstrate random swapping using the overloaded () operator
    board(42);  // Perform random swapping using seed 42
    cout << "After random swap on the original board:" << endl;
    cout << board;

    return 0;
}
