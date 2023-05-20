#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::string;

class arr {};

class arrInt : public arr {
    int mSize = 0;
    int* ptr = nullptr;

public:
    arrInt();
    arrInt(int count);
    arrInt(const arrInt& ex);
    ~arrInt();
    int operator[](int index) const;
    void set(int index, int value);
    int getSize() const;
};

arrInt::arrInt() {
    cout << "Set the size of the array: ";
    cin >> mSize;
    ptr = new int[mSize];
}

arrInt::arrInt(int count) : mSize(count) {
    ptr = new int[mSize];
}

arrInt::arrInt(const arrInt& ex) : mSize(ex.mSize) {
    ptr = new int[mSize];
    for (int i = 0; i < mSize; ++i) {
        ptr[i] = ex.ptr[i];
    }
}

arrInt::~arrInt() {
    delete[] ptr;
}

int arrInt::operator[](int index) const {
    if (index >= 0 && index < mSize) {
        return ptr[index];
    }
    throw std::out_of_range("Index out of range");
}

void arrInt::set(int index, int value) {
    if (index >= 0 && index < mSize) {
        ptr[index] = value;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int arrInt::getSize() const {
    return mSize;
}

class arrDouble : public arr {
    int mSize = 0;
    double* ptr = nullptr;

public:
    arrDouble();
    arrDouble(int count);
    arrDouble(const arrDouble& ex);
    ~arrDouble();
    double operator[](int index) const;
    void set(int index, double value);
    int getSize() const;
};

arrDouble::arrDouble() {
    cout << "Set the size of the array: ";
    cin >> mSize;
    ptr = new double[mSize];
}

arrDouble::arrDouble(int count) : mSize(count) {
    ptr = new double[mSize];
}

arrDouble::arrDouble(const arrDouble& ex) : mSize(ex.mSize) {
    ptr = new double[mSize];
    for (int i = 0; i < mSize; ++i) {
        ptr[i] = ex.ptr[i];
    }
}

arrDouble::~arrDouble() {
    delete[] ptr;
}

double arrDouble::operator[](int index) const {
    if (index >= 0 && index < mSize) {
        return ptr[index];
    }
    throw std::out_of_range("Index out of range");
}

void arrDouble::set(int index, double value) {
    if (index >= 0 && index < mSize) {
        ptr[index] = value;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int arrDouble::getSize() const {
    return mSize;
}

class arrString : public arr {
    int mSize = 0;
    string* ptr = nullptr;

public:
    arrString();
    arrString(int count);
    arrString(const arrString& ex);
    ~arrString();
    string operator[](int index) const;
    void set(int index, const string& value);
    int getSize() const;
};

arrString::arrString() {
    cout << "Set the size of the array: ";
    cin >> mSize;
    ptr = new string[mSize];
}

arrString::arrString(int count) : mSize(count) {
    ptr = new string[mSize];
}

arrString::arrString(const arrString& ex) : mSize(ex.mSize) {
    ptr = new string[mSize];
    for (int i = 0; i < mSize; ++i) {
        ptr[i] = ex.ptr[i];
    }
}

arrString::~arrString() {
    delete[] ptr;
}

string arrString::operator[](int index) const {
    if (index >= 0 && index < mSize) {
        return ptr[index];
    }
    throw std::out_of_range("Index out of range");
}

void arrString::set(int index, const string& value) {
    if (index >= 0 && index < mSize) {
        ptr[index] = value;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int arrString::getSize() const {
    return mSize;
}