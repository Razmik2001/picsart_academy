#include <iostream>
#include <initializer_list>


//works only with basic types

template <class T>
class mVector
{
	T *mVec = nullptr;
	void doubleSize();
	int mSize = 0;
	int mCapacity = 0;
public:
	int size(){return mSize;};
	int capacity(){return mCapacity;};
	mVector() = default;
	mVector(std::initializer_list<T> args);
	void pushBack(T value);
	T operator[](int index);
	~mVector(){delete [] mVec;mVec = nullptr;}
};

template <class T>
mVector<T>::mVector(std::initializer_list<T> args)
{
	int size = args.size();
	mVec = new T [size];
	for (auto i = args.begin(); i < args.end(); ++i)
	{
		mVec[mSize++] = *i;
	}
	mSize = size;
	mCapacity = size;
}

template <class T>
void mVector<T>::doubleSize(){
	if (mVec == nullptr){
		mCapacity = 2;
		mVec = new T (mCapacity);
	}
	else
	{
		mCapacity *= 2;
		T *temp = new T [mCapacity];
		for (int i = 0; i < mSize; ++i)
		{
			temp[i] = mVec[i];
		}
		delete [] mVec;
		mVec = temp;
		temp = nullptr; 
	}
}

template <class T>
void mVector<T>::pushBack(T value)
{
	if (mSize == mCapacity)
		doubleSize();
	mVec[mSize] = value;
	mSize++;
}

template <class T>
T mVector<T>::operator[](int index){
	try{
		if (index < mSize)
			return mVec[index];
		throw std::invalid_argument("I don't have these coordinates;");
	}
	catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

#include <iostream>

int main()
{
    // Test default constructor
    mVector<int> vec1;
    std::cout << "Vector 1 size: " << vec1.size() << std::endl;
    std::cout << "Vector 1 capacity: " << vec1.capacity() << std::endl;
    
    // Test initializer list constructor
    mVector<int> vec2 = {1, 2, 3, 4, 5};
    std::cout << "Vector 2 size: " << vec2.size() << std::endl;
    std::cout << "Vector 2 capacity: " << vec2.capacity() << std::endl;
    
    // Test pushBack() and operator[]
    vec2.pushBack(6);
    vec2.pushBack(7);
    vec2.pushBack(8);
    
    std::cout << "Vector 2 size after push: " << vec2.size() << std::endl;
    std::cout << "Vector 2 capacity after push: " << vec2.capacity() << std::endl;
    
    for (int i = 0; i < vec2.size(); ++i)
    {
        std::cout << "Element at index " << i << ": " << vec2[i] << std::endl;
    }

    // Test mVector with integers
    mVector<int> intVector;
    
    intVector.pushBack(10);
    intVector.pushBack(20);
    intVector.pushBack(30);
    
    std::cout << "Integer Vector:" << std::endl;
    std::cout << "Size: " << intVector.size() << std::endl;
    std::cout << "Capacity: " << intVector.capacity() << std::endl;
    std::cout << "Elements: ";
    for (int i = 0; i < intVector.size(); ++i)
    {
        std::cout << intVector[i] << " ";
    }
    std::cout << std::endl;
 
    return 0;
}
