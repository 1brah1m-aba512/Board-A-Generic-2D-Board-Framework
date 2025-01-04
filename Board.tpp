#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <random>

template <typename T>
Board<T>::Board() : Board(500, 500) {}

template <typename T>
Board<T>::Board(int intRows, int intCols) {
    allocMem(intRows, intCols);
}

template <typename T>
Board<T>::Board(const Board& objOriginal) {
    allocMem(objOriginal._rows, objOriginal._cols);
    clone(objOriginal);
}

template <typename T>
Board<T>::~Board() {
    dealloc();
}

template <typename T>
void Board<T>::allocMem(int intRows, int intCols) {
    _rows = intRows;
    _cols = intCols;
    _image = new BoardRow<T>[_rows];  // Allocate rows of UJBoardRow<T>
    for(int r = 0; r < _rows; r++) {
        _image[r] = BoardRow<T>(_cols);  // Initialize each row

        for(int c = 0; c < _cols; c++)
        {
            _image[r][c] = {0, 0, 0};
        }
    }
}

template <typename T>
void Board<T>::clone(const Board& objOriginal) {
    for(int r = 0; r < _rows; r++) {
        _image[r] = objOriginal._image[r];

    }
}

template <typename T>
void Board<T>::dealloc() {
    delete[] _image;  // Deallocate the 1D array of UJBoardRow<T>
}

template <typename T>
void Board<T>::setPixel(int intRow, int intCol, T recPixel) {
    enforceRange(intRow, 0, _rows - 1);
    enforceRange(intCol, 0, _cols - 1);
    _image[intRow][intCol] = recPixel;  // Use UJBoardRow's operator[]
}

template <typename T>
void Board<T>::enforceRange(int intValue, int intMin, int intMax) const {
    if(intValue < intMin || intValue > intMax) {
        std::cerr << intValue << " must be in [" << intMin << ", " << intMax << "]" << std::endl;
        exit(ERROR_RANGE);
    }
}

// Overloaded indexing operator
template <typename T>
BoardRow<T>& Board<T>::operator[](int index) {
    enforceRange(index, 0, _rows - 1);
    return _image[index];
}

template <typename T>
const BoardRow<T>& Board<T>::operator[](int index) const {
    enforceRange(index, 0, _rows - 1);
    return _image[index];
}

// Overloaded assignment operator
template <typename T>
Board<T>& Board<T>::operator=(const Board& objOriginal) {
    if (this != &objOriginal) {
        dealloc();
        allocMem(objOriginal._rows, objOriginal._cols);
        clone(objOriginal);
    }
    return *this;
}

// Random swap operator
template <typename T>
void Board<T>::operator()(int seed) {
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> rowDist(0, _rows - 1);
    std::uniform_int_distribution<int> colDist(0, _cols - 1);

    for (int r = 0; r < _rows; ++r) {
        for (int c = 0; c < _cols; ++c) {
            int randRow = rowDist(generator);
            int randCol = colDist(generator);
            std::swap(_image[r][c], _image[randRow][randCol]);
        }
    }
}

// Stream insertion operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const Board<T>& board) {
    for (int r = 0; r < board._rows; ++r) {
        for (int c = 0; c < board._cols; ++c) {
            os << board._image[r][c] << " ";  // Assuming << is overloaded for T
        }
        os << std::endl;
    }
    return os;
}
