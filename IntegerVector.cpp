#ifndef __INTEGER_VECTOR_CPP__
#define __INTEGER_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <string>
#include <stdexcept>  // for throwing Out of Range exception

IntegerVector::IntegerVector()  {}
IntegerVector::~IntegerVector() {}

int IntegerVector::size()
{
  return integerVector.size();
}

// just return the integer at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index
int IntegerVector::get(int index)
{
  if (index >= this->size() || index < 0) {
    std::string msg = "Invalid index: [" + std::to_string(index) + "]. " +
      "Size: [" + std::to_string(this->size()) + "]. ";
    throw std::out_of_range(msg.c_str());
  }
  return integerVector.at(index);
}

// if index is size-legitimate, put the value at that index;
// otherwise, use push_back to append to the end of the vector
void IntegerVector::put(int value, int index)
{
  if (index >= this->size()) {
    integerVector.push_back(value);
  }
  else {
    integerVector.at(index) = value;
  }
}

// use push_back to append
void IntegerVector::put(int value)
{
  integerVector.push_back(value);
}

// for each double in doubleVector, use static_cast<int> to append as an
// integer to integerVector
void IntegerVector::appendDoubleVector(DoubleVector& doubleVector)
{
  for(int i=0; i<doubleVector.size(); i++) {
    integerVector.push_back(static_cast<int>(doubleVector.get(i)));
  }
}

// for each char in characterVector, use static_cast<int> to append as an
// integer to integerVector
void IntegerVector::appendCharacterVector(CharacterVector& characterVector)
{
  for(int i=0; i<characterVector.size(); i++) {
    integerVector.push_back(static_cast<int>(characterVector.get(i)));
  }
}


#endif
