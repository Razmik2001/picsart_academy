#include <iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;


class MyString
{
	int capacity;
	char *buf = nullptr;
public:
	MyString(){capacity = 1;buf = new char[1];buf[0]= '\0';}
	MyString(const char *str);
	MyString(const string& str);
	MyString(const MyString &src);
	~MyString(){delete [] buf;};
	MyString& operator=(const MyString &src);
	MyString& operator=(const char *str);
	MyString& operator=(const string& str);
	MyString& operator+(const MyString &src);
	MyString& operator+(const char *str);
	MyString& operator+(const string& str);
	char *getChar(){
		return buf;
	}
};

std::ostream& operator<<(std::ostream& os, MyString& src)
{
    os << src.getChar();
    return os;
}

MyString::MyString(const char *str)
{
	int count = 0;
	while(str[count])
		count++;
	capacity = count + 1;
	buf = new char [capacity];
	for(count = 0;count <capacity;count++)
		buf[count] = str [count];
}


MyString::MyString(const string& str)
{
	capacity = str.size() + 1;
	buf = new char [capacity];
	for(int count = 0;count <capacity;count++)
		buf[count] = str [count];
}

MyString::MyString(const MyString &src)
{
	capacity = src.capacity;
	buf = new char [capacity];
	int count;
	for(count = 0;count <capacity - 1;count++)
		buf[count] = src.buf[count];
	buf[count] = '\0';
}

MyString& MyString::operator=(const char *str)
{
	if (buf == nullptr)
	{
		delete [] buf;
	}
	int count = 0;
	while(str[count])
		count++;
	capacity = count + 1;
	buf = new char [capacity];
	for(count = 0;count <capacity;count++)
		buf[count] = str [count];
	return *this;
}

MyString& MyString::operator=(const string& str)
{
	if (buf == nullptr)
	{
		delete [] buf;
	}
	capacity = str.size() + 1;
	buf = new char [capacity];
	int count;
	for(count = 0;count <capacity - 1;count++)
		buf[count] = str[count];
	buf[count] = '\0';
	return *this;
}

MyString& MyString::operator=(const MyString &src)
{
	if (buf == nullptr)
	{
		delete [] buf;
	}
	int count;
	capacity = src.capacity;
	buf = new char [capacity];
	for(count = 0;count <capacity - 1;count++)
		buf[count] = src.buf[count];
	buf[count] = '\0';
	return *this;
}

MyString& MyString::operator+(const char *str)
{
	int strLength = 0;
    while (str[strLength])
        strLength++;
    int newCapacity = capacity + strLength;
    char* tmp = new char[newCapacity];
    int i;
    for (i = 0; i < capacity - 1; ++i)
        tmp[i] = buf[i];
    for (int j = 0; j < strLength; ++j, ++i)
        tmp[i] = str[j];
    tmp[i] = '\0';
    MyString *result =  new MyString(tmp);
    delete[] tmp;
    return *result;
}

MyString& MyString::operator+(const string &str)
{
	int strLength = str.size();
    int newCapacity = capacity + strLength;
    char* tmp = new char[newCapacity];
    int i;
    for (i = 0; i < capacity - 1; ++i)
        tmp[i] = buf[i];
    for (int j = 0; j < strLength; ++j, ++i)
        tmp[i] = str[j];
    tmp[i] = '\0';
    MyString *result =  new MyString(tmp);
    delete[] tmp;
    return *result;
}

MyString& MyString::operator+(const MyString &src)
{
	int newCapacity = capacity + src.capacity - 1;
    char* tmp = new char[newCapacity];
    int i;
    for (i = 0; i < capacity - 1; ++i)
        tmp[i] = buf[i];
    for (int j = 0; j < src.capacity; ++j, ++i)
        tmp[i] = src.buf[j];
    tmp[i] = '\0';
    MyString *result =  new MyString(tmp);
    delete[] tmp;
    return *result;
}

using std::endl;

int main() {
    // Create an empty MyString object
    MyString str1;
    cout << "str1: " << str1 << endl;

    // Create a MyString object from a const char*
    MyString str2("Hello");
    cout << "str2: " << str2 << endl;

    // Create a MyString object from a string
    string text = "World";
    MyString str3(text);
    cout << "str3: " << str3 << endl;

    // Assign a const char* to a MyString object
    str1 = "Assignment";
    cout << "str1 after assignment: " << str1 << endl;

    // Assign a string to a MyString object
    string message = "This is a message ";
    str2 = message;
    cout << "str2 after assignment: " << str2 << endl;

    // Concatenate MyString objects
    MyString str4 = str2 + str3;
    cout << "str4: " << str4 << endl;

    // Concatenate a MyString object and a const char*
    MyString str5 = str3 + " concatenation";
    cout << "str5: " << str5 << endl;

    // Concatenate a MyString object and a string
    string extra = " Extra";
    MyString str6 = str4 + extra;
    cout << "str6: " << str6 << endl;

    return 0;
}