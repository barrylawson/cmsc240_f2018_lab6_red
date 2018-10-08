#ifndef __DOUBLE_VECTOR_CPP__
#define __DOUBLE_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <stdexcept>
using namespace std;


DoubleVector::DoubleVector()  {}
DoubleVector::~DoubleVector() {}

int DoubleVector::size()
{
   return doubleVector.size();
}

// just return the double at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index

double DoubleVector::get(int index)
{
  if (index >= this->size() || index < 0) {
    string msg = "Invalid index: [" + to_string(index) + "]. " +
      "Size: [" + to_string(this->size()) + "]. ";
    throw out_of_range(msg.c_str());
  }
   return doubleVector.at(index);
}

// if index is size-legitimate, put the value at that index;
// otherwise, use push_back to append to the end of the vector
void DoubleVector::put(double value, int index)
{
   if(index >= 0 && index < this->size()) {
       doubleVector.at(index) = value;
   } else {
       doubleVector.push_back(value);
   }
}

// use push_back to append
void DoubleVector::put(double value)
{
   doubleVector.push_back(value);
}

// for each integer in integerVector, use static_cast<double> to append as a
// double to doubleVector
void DoubleVector::appendIntegerVector(IntegerVector& integerVector)
{
   for(int i = 0; i < integerVector.size(); i++) {
      doubleVector.push_back(static_cast<double>(integerVector.get(i)));
   }
}

// for each character in characteVector, use static_cast<double> to append as a
// double to doubleVector
void DoubleVector::appendCharacterVector(CharacterVector& characterVector)
{
   for(int i = 0; i < characterVector.size(); i++) {
      doubleVector.push_back(static_cast<double>(characterVector.get(i)));
   }
}

#endif
