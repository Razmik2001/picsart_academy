#ifndef MY_BITSET_HPP
#define MY_BITSET_HPP

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <climits>
#include <stdlib.h>

typedef unsigned int UI;
typedef unsigned long UL;
typedef unsigned long long ULL;

template <int len>
class my_bitset
{
private:
	UI *bset;
	short length = 0;
	const short int_byt_size = sizeof (UI);
	const short int_bit_size = int_byt_size*8;
	short bit_counts = len;
public:
	my_bitset();
	short size();
	void set(short position);
	void reset(short position);
	void flip(short position);
	bool any();
	bool none();
	bool all();
	short count();
	UL to_ulong();
	ULL to_ullong();
	std::string to_string();
	bool test(short position);
	bool operator[] (short position);
	~my_bitset();
	template <UI T>
	friend std::ostream& operator<<(std::ostream& os, my_bitset<T>& bset);
};

template <int len>
my_bitset<len>::my_bitset() 
{
    {
		length = bit_counts / (int_bit_size - 1) + 1;
		bset = new UI[length];
		for (int i = 0; i < length; ++i)
			bset[i] = 0;
	}
}

template <int len>
my_bitset<len>::~my_bitset() 
{
   delete [] bset;
}

//operator[] overloading 
template <int len>
bool my_bitset<len>::operator[] (short position) 
{
    return test(position);
}
//operator= overloading 
template <int len>
void my_bitset<len>::operator= (ULL value){
        if (value <= UINT_MAX)
        	bset[0] = value;
        else
        {
        	bset[1] = value >> (int_bit_size);
        	bset[0] = (value - (bset[1] << int_bit_size));
        }
    }

//operator<< overloading 
template <int len>
std::ostream& operator<<(std::ostream& os, my_bitset<len>& bset)
{
    os << bset.to_string();
    return os;
}

//toggles the values of bits
template <int len>
void my_bitset<len>::flip(short position)
{
	if (position > bit_counts)
		return;
	bset[position/int_bit_size] ^= (UI)(1 << (position%int_bit_size));
}

//sets bits to true or given value
template <int len>
void my_bitset<len>::set(short position)
{
	if (position > bit_counts)
		return;
	bset[position/int_bit_size] |= (UI)(1 << (position%int_bit_size));
}

//sets bits to false
template <int len>
void my_bitset<len>::reset(short position)
{
	if (position > bit_counts)
		return;
	bset[position/int_bit_size] &= (UI)~(1 << (position%int_bit_size));
}

//checks if any of the bits are set to true
template <int len>
bool my_bitset<len>::any()
{
	for (int i = 0; i < length; ++i)
		{
			if(bset[i] == 0)
				return 0;
		}
	return 1;
}

//checks if none of the bits are set to true
template <int len>
bool my_bitset<len>::none()
{
	for (int i = 0; i < length; ++i)
		{
			if(bset[i] != 0)
			return 0;
		}
	return 1;
}

//checks if all of the bits are set to true
template <int len>
bool my_bitset<len>::all()
{
	for (int i = 0; i < length - 1; ++i)
		{
			if(bset[i] != (UINT_MAX))
				return 0;
		}
	if(bset[length - 1] != (UI)((1 << ((bit_counts - 1)%int_bit_size)) - 1))
		return 0;
	return 1;
}

//returns the number of bits set to true
template <int len>
short my_bitset<len>::count()
{
	int count = 0;
	for (int i = 0; i < length; ++i)
		for (int j = 0; j < int_bit_size; ++j)
		{
			if(i == length - 1 && (i * int_bit_size + j) > bit_counts)
				break;
			if((bset[i] & (UI)(1 << j)) == (UI)(1 << j))
				count++;
		}
	return count;
}

//	returns an unsigned long integer representation of the data
template <int len>
UL my_bitset<len>::to_ulong()

{
	for(int i = sizeof(UL)/int_byt_size;i < length ; i++)
	{
		if(bset[i] != 0)
		{
			std::cout << "terminate called after throwing an instance of 'std::overflow_error'\n what():  _Base_bitset::_M_do_to_ulong\n";
			exit(1);
		}
	}
	if(sizeof(UL)/int_byt_size == 1)
		return bset[0];
	else
	{
		return ((UL)bset[1]<<32) + bset[0];
	}
}

//	returns an unsigned long long integer representation of the data
template <int len>
ULL my_bitset<len>::to_ullong()
{
	for(int i = sizeof(ULL)/int_byt_size;i < length ; i++)
	{
		if(bset[i] != 0)
		{
			std::cout << "terminate called after throwing an instance of 'std::overflow_error'\n what():  _Base_bitset::\n";
			exit(1);
		}
	}
	if(sizeof(ULL)/int_byt_size == 1)
		return bset[0];
	else
	{
		return ((unsigned long long)bset[1]<<32) + bset[0];
	}
	
}

//returns a string representation of the data
template <int len>
std::string my_bitset<len>::to_string()
{
	std::string str = "";
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < int_bit_size; ++j)
		{
			if(i == length - 1 && (i * int_bit_size + j) == bit_counts)
				break;
			if((bset[i] & (UI)(1 << j)) == (UI)(1 << j))
				str += '1';
			else
				str += '0';
		}
	}
	reverse(str.begin(), str.end()); 
	return str;
}

//accesses specific bit
template <int len>
bool my_bitset<len>::test(short position)
{
	if (position > bit_counts)
	{
		std::cout << "Wrong size";
		return false;
	}
	if((bset[position/int_bit_size] & (UI)(1 << (position%int_bit_size))) == (UI)(1 << (position%int_bit_size)))
		return true;
	else 
		return false;
}

//returns the number of bits that the bitset holds
template <int len>
short my_bitset<len>::size()
{
	return bit_counts;
}

#endif //MY_BITSET_HPP