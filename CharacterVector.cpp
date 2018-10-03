#ifndef __CHARACTER_VECTOR_CPP__
#define __CHARACTER_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"

#include <stdexcept>
using namespace std;

CharacterVector::CharacterVector() {}
CharacterVector::~CharacterVector() {}


int CharacterVector::size()
{
   return characterVector.size();
}

// just return the character at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index

char CharacterVector::get(int index)
{
   if(index >= characterVector.size()) {
      throw out_of_range("Invalid Index: Must be less than the size of the vector!");
   } else {
      return characterVector.at(index);
   }

}

// if index is size-legitimate, put the value at that index;
// otherwise, use push_back to append to the end of the vector
void CharacterVector::put(char value, int index)
{
    if(index >= characterVector.size()) {
        characterVector.push_back(value);
    } else {
        characterVector.at(index) = value;
    }
}

// use push_back to append
void CharacterVector::put(char value)
{
    characterVector.push_back(value);
}

// for each integer in integerVector, use static_cast<char> to append as a
// character to characterVector
void CharacterVector::appendIntegerVector(IntegerVector& integerVector)
{
    int length = integerVector.size();
    char newChar;
    for(int i = 0; i < length; i++) {
        newChar = static_cast<char>(integerVector.get(i));
        characterVector.push_back(newChar);
    }
}

// for each double in doubleVector, use static_cast<char> to append as a
// character to characterVector
void CharacterVector::appendDoubleVector(DoubleVector& doubleVector)
{
    int length = doubleVector.size();
    char newChar;
    for(int i = 0; i < length; i++) {
        newChar = static_cast<char>(doubleVector.get(i));
        characterVector.push_back(newChar);
  }
}

#endif
