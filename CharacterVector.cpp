#ifndef __CHARACTER_VECTOR_CPP__
#define __CHARACTER_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"

#include <stdexcept>
using namespace std;

CharacterVector::CharacterVector() {}
CharacterVector::~CharacterVector() {}

//<<<<<<< HEAD
//int CharacterVector::size()
//{
//=======
int CharacterVector::size()
{
//<<<<<<< HEAD
   return characterVector.size();
//=======
//>>>>>>> 5e48b0e5cf97b751ad971781554138fb14df17e4
//   return 0;
//>>>>>>> 4928619711a790fc08fc610695d9ea6a058b8fa3
}

// just return the character at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index
//<<<<<<< HEAD
//char CharacterVector::get(int index)
//{
//   return 0;
//=======
char CharacterVector::get(int index)
{
//<<<<<<< HEAD
//<<<<<<< HEAD
   if(index >= characterVector.size()) {
      throw out_of_range("Invalid Index: Must be less than the size of the vector!");
   } else {
      return characterVector.at(index);
   }
//=======
//   return '0';
//>>>>>>> 824b5186de8775049cc72bbf22f0f302eb95e24d
//=======
//   return '0';
//>>>>>>> 5e48b0e5cf97b751ad971781554138fb14df17e4
//>>>>>>> 4928619711a790fc08fc610695d9ea6a058b8fa3
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
