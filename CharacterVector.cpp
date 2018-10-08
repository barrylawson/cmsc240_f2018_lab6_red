#ifndef __CHARACTER_VECTOR_CPP__
#define __CHARACTER_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <string>
#include <stdexcept>
using namespace std;

CharacterVector::CharacterVector() {}
CharacterVector::~CharacterVector() {}

<<<<<<< HEAD
<<<<<<< HEAD
int CharacterVector::size()
{
   return characterVector.size();
=======
int CharacterVector::size() 
{  
   return 0;
>>>>>>> jd4mx
=======
int CharacterVector::size()
{
   return characterVector.size();
>>>>>>> jd4mx
}

// just return the character at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index
<<<<<<< HEAD
<<<<<<< HEAD
=======
char CharacterVector::get(int index)
{
   return '0';
}
>>>>>>> jd4mx

char CharacterVector::get(int index)
{
   if(index >= this->size() || index < 0) {
      string msg = "Invalid index: [" + to_string(index) + "]. " +
        "Size: [" + to_string(this->size()) + "]. ";
      throw out_of_range(msg.c_str());
   } else {
      return characterVector.at(index);
   }
<<<<<<< HEAD
=======
char CharacterVector::get(int index)
{
   return '0';
>>>>>>> jd4mx
=======
>>>>>>> jd4mx
}

// if index is size-legitimate, put the value at that index;
// otherwise, use push_back to append to the end of the vector
void CharacterVector::put(char value, int index)
{
    if(index >= this->size()) {
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
