template <typename T>
BoardRow<T>::BoardRow() : BoardRow(10) {}

template <typename T>
BoardRow<T>::BoardRow(int size) : _size(size) {
    _rowData = new T[_size];
}

template <typename T>
BoardRow<T>::BoardRow(const BoardRow& objOriginal) : _size(objOriginal._size) {
    _rowData = new T[_size];
    for (int i = 0; i < _size; ++i) {
        _rowData[i] = objOriginal._rowData[i];
    }
}

template <typename T>
BoardRow<T>::~BoardRow() {
    delete[] _rowData;
}

template <typename T>
T& BoardRow<T>::operator[](int index) {
    return _rowData[index];
}

template <typename T>
const T& BoardRow<T>::operator[](int index) const {
    return _rowData[index];
}

template <typename T>
BoardRow<T>& BoardRow<T>::operator=(const BoardRow& objOriginal) {
    if (this != &objOriginal) {
        delete[] _rowData;
        _size = objOriginal._size;
        _rowData = new T[_size];
        for (int i = 0; i < _size; ++i) {
            _rowData[i] = objOriginal._rowData[i];
        }
    }
    return *this;
}
