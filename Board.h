#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "BoardRow.h"
#include <iostream>
#include <random>

struct Pixel{

int intRed;
int intGreen;
int intBlue;

};

// Overload the << operator for UJPixel
std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << "(" << pixel.intRed << ", " << pixel.intGreen << ", " << pixel.intBlue << ")";
    return os;
}

enum StatusCode {
    ERROR_RANGE = -1,
    SUCCESS
};

// Template declaration for UJBoard
template <typename T>
class Board {

public:
    Board();
    Board(int intRows, int intCols);
    Board(const Board& objOriginal);
    ~Board();

    int getRows();
    int getCols();
    void setPixel(int intRow, int intCol, T recPixel);

    // Overloaded operators
    BoardRow<T>& operator[](int index);  // Indexing operator
    const BoardRow<T>& operator[](int index) const;
    Board& operator=(const Board& objOriginal); // Assignment operator
    void operator()(int seed);  // Random swap operator

    // Stream insertion operator
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Board<U>& board);

private:
    void allocMem(int intRows, int intCols);
    void clone(const Board& objOriginal);
    void dealloc();
    void enforceRange(int intValue, int intMin, int intMax) const;

    int _rows;
    int _cols;
    BoardRow<T>* _image;  // Now it's a 1D array of BoardRow<T>
};

#include "Board.tpp"  // Include implementation

#endif // BOARD_H_INCLUDED
