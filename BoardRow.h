#ifndef BOARDROW_H_INCLUDED
#define BOARDROW_H_INCLUDED

template <typename T>
class BoardRow {
public:
    BoardRow();
    BoardRow(int size);
    BoardRow(const BoardRow& objOriginal);
    ~BoardRow();

    // Overloaded indexing operator
    T& operator[](int index);
    const T& operator[](int index) const;

    // Overloaded assignment operator
    BoardRow& operator=(const BoardRow& objOriginal);

private:
    int _size;
    T* _rowData;
};

#include "BoardRow.tpp"  // Include implementation of template class

#endif // BOARDROW_H_INCLUDED
