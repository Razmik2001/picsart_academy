#include <iostream>
#include <initializer_list>


//works only with base types

template <class T>
class mVector
{
protected:
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
	virtual ~mVector(){delete [] mVec;mVec = nullptr;}
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

template <class T>
class mSteck:public mVector<T>
{
public:
	mSteck() = default;
	mSteck(std::initializer_list<T> args):mVector<T>(args){};
	T getFirst();
	~mSteck() = default;
};

template <class T>
T mSteck<T>::getFirst()
{
	try{
		if (mVector<T>::mSize > 0){
			mVector<T>::mSize-=1;
			return mVector<T>::mVec[mVector<T>::mSize];
		}
		throw std::invalid_argument("Stack is empty");
	}
	catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return T();
    }
}


template <class T>
void printVector(const T& vector)
{
    int size = vector.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Test mSteck with int
    mSteck<int> intStack{ 1, 2, 3 };
    std::cout << "mSteck with int elements: ";
    while (intStack.size() > 0) {
        std::cout << intStack.getFirst() << " ";
    }
    std::cout << std::endl;

    // Test mSteck with double
    mSteck<double> doubleStack{ 1.5, 2.5, 3.5 };
    std::cout << "mSteck with double elements: ";
    while (doubleStack.size() > 0) {
        std::cout << doubleStack.getFirst() << " ";
    }
    std::cout << std::endl;

    return 0;
}