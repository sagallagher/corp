#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

/**
*  file:	BoolSet.cpp
*  author:	Sarah McGlasson
*  date:	9/10/2017
*  updated:	9/24/2017
*
*  This class contains an array of booleans and has various methods for use representing 4D polytopes
*
*/

#include <iostream>
#include <string>

#include "BoolSet.h"

//constructor
BoolSet::BoolSet(int size) : _length{ size }, _numberSelected{ 0 }, _values{ nullptr }
{
	_values = new bool[_length];
	clear();
	std::cout << " bitvector start: " << toString() << "bitvector length: " << length() << "\n";
}

//copy constructor
BoolSet::BoolSet(const BoolSet& original) 
{
	_length = original._length;
	_numberSelected = original._numberSelected;
	_values = new bool[_length];
	std::memcpy(_values, original._values, sizeof(_values));
}

//overloaded equals
BoolSet& BoolSet::operator=(const BoolSet & original) 
{
	_length = original.length();
	_numberSelected = original._numberSelected;
	_values = new bool[_length];
	//std::memcpy(_values, original._values, sizeof _values);
	for (int i = 0; i < _length; i++)
	{
		//std::cout << "original value at " << i << " is " << original._values[i] << "\n";
		_values[i] = original._values[i];
		//std::cout << "value at " << i << " set to " << _values[i] << "\n";
		
	}
	return *this;
}

//destructor
BoolSet::~BoolSet() 
{
	delete[] _values;
	_values = nullptr;
}

//overloaded brackets
bool& BoolSet::operator[](int index) 
{
	return _values[index];
}

//overloaded brackets
bool BoolSet::operator[](int index) const
{
	return _values[index];
}

//gets the length of the set
int BoolSet::length() const
{
	return _length;
}

//gets the number of true values
int BoolSet::numberSelected() const
{
	return _numberSelected;
}

//sets value at given index to true
void BoolSet::setTrue(int index) 
{
	if (index >= _length || index < 0)
		return;
	if (!_values[index]) {
		_numberSelected++;
	}
	_values[index] = true;
}

//sets value at given index to true without checking bounds
void BoolSet::setTrueUnchecked(int index)
{
	if (!_values[index])
		_numberSelected++;
	std::cout << "Set " << index << " to true\n";
	_values[index] = true;
}

//sets value at given index to given value
void BoolSet::setValue(int index, bool value) 
{
	if (index >= _length || index < 0)
		return;
	if (value && !_values[index])
		_numberSelected++;
	if (!value && _values[index])
		_numberSelected--;
	_values[index] = value;
}

//sets value at given index without checking bounds
void BoolSet::setValueUnchecked(int index, bool value)
{
	if (value && !_values[index])
		_numberSelected++;
	if (!value && _values[index])
		_numberSelected--;
	_values[index] = value;
}

//toggles value at given index between true and false
void BoolSet::toggleValue(int index) 
{
	if (index >= _length || index < 0)
		return;
	if (_values[index])
		_numberSelected--;
	else
		_numberSelected++;
	_values[index] = !_values[index];
}

//toggles value at given index without checking bounds
void BoolSet::toggleValueUnchecked(int index)
{
	if (_values[index])
		_numberSelected--;
	else
		_numberSelected++;
	_values[index] = !_values[index];
}

//gets value at given index
bool BoolSet::getValue(int index) const
{
	if (index >= _length || index < 0)
		return false;
	return _values[index];
}

//gets value at given index without checking bounds
bool BoolSet::getValueUnchecked(int index) const
{
	return _values[index];
}

//returns true if every value in the array is true
bool BoolSet::allTrue() const 
{
	return _numberSelected == _length;
}

//sets every value to false
void BoolSet::clear() 
{
	_numberSelected = 0;
	//std::memset(_values, false, _length);
	for (int i = 0; i < _length; i++)
	{
		_values[i] = false;
		//std::cout << "Set the value at " << i << " to " << _values[i] << "\n";
	}
}

//returns true if all values are false
bool BoolSet::empty() const 
{
	return _numberSelected == 0;
}

std::string BoolSet::toString() const
{
	std::string result;
	result = "";
	for (int i = 0; i < _length; i++)
	{
		if (_values[i])
			result = result + "1";
		else
			result = result + "0";
	}
	return result;
}