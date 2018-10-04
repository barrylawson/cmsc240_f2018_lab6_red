#include <iostream>
#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <stdexcept>  // for throwing Out of Range exception

int main()
{
   IntegerVector   iv;
   DoubleVector    dv;
   CharacterVector cv;

   //-------------------------------------------------------------------------

   // test IntegerVector: put, get, size, out_of_range

   std::cout << "--------------" << std::endl;
   std::cout << "IntegerVector:" << std::endl;
   std::cout << "--------------" << std::endl;
   std::cout << "Testing put()"  << std::endl;
   iv.put(10);
   iv.put(20);
   std::cout << "\tiv.put(10):" << "\t\tiv.get(0): " << iv.get(0) << std::endl;
   std::cout << "\tiv.put(20):" << "\t\tiv.get(1): " << iv.get(1) << std::endl;
   iv.put(15, 0);
   std::cout << "\tiv.put(15, 0):" << "\t\tiv.get(0): " << iv.get(0) << std::endl;

  // test put() for illegal indices
   iv.put(30, 50);
   std::cout << "\tiv.put(25, 99):" << "\t\tiv.get(2): " << iv.get(2) << std::endl;

   std::cout << "--------------" << std::endl;
   std::cout << "Testing get()"  << std::endl;
   std::cout << "\tiv.get(0): " << iv.get(0) << " [15]" << std::endl;
   std::cout << "\tiv.get(1): " << iv.get(1) << " [20]" << std::endl;
   std::cout << "\tiv.get(2): " << iv.get(2) << " [30]" << std::endl;

   std::cout << "--------------" << std::endl;
   std::cout << "Testing out_of_range" << std::endl;
   // test oor get() for index>size-1
   std::cout << "\tiv.get(100): ";
   try {
     iv.get(100);
   }
   catch (const std::out_of_range& oor) {
     std::cerr << "\tOut of Range error: " << oor.what() << std::endl;
   }
   // test oor get() for index==size
   std::cout << "\tiv.get(3): ";
   try {
     iv.get(3);
   }
   catch (const std::out_of_range& oor) {
     std::cerr << "\tOut of Range error: " << oor.what() << std::endl;
   }
   // test oor get() for negative index
   std::cout << "\tiv.get(-1): ";
   try {
     iv.get(-1);
   }
   catch (const std::out_of_range& oor) {
     std::cerr << "\tOut of Range error: " << oor.what() << std::endl << std::endl;
   }

   std::cout << "--------------" << std::endl;
   std::cout << "Testing size()"  << std::endl;
   std::cout << "\t\tSize: "   << iv.size() << " [3]" << std::endl;
   iv.put(40);
   std::cout << "iv.put(40):" << "\tSize: " << iv.size() << " [4]" << std::endl;

   std::cout << "--------------" << std::endl;

   //-------------------------------------------------------------------------

   // test CharacterVector: put, get, size, out_of_range
   std::cout << std::endl;
   std::cout << "----------------" << std::endl;
   std::cout << "CharacterVector:" << std::endl;
   std::cout << "The size of the vector: " << cv.size() << std::endl;
   try {
      std::cout << "The char at index 0: " << cv.get(0) << std::endl;
   } catch(std::exception& e) {
      std::cerr << "exception caught: " << e.what() << std::endl;
   }
   cv.put('a');
   cv.put('b');
   cv.put('c', 5);
   std::cout << "The size of the vector: " << cv.size() << std::endl;
   std::cout << "The char at index 2: " << cv.get(2) << std::endl;
   cv.put('f', 1);
   std::cout << "The size of the vector: " << cv.size() << std::endl;
   std::cout << "The char at index 2: " << cv.get(2) << std::endl;
   std::cout << "The char at index 1: " << cv.get(1) << std::endl;
   std::cout << "----------------" << std::endl;

   //-------------------------------------------------------------------------

   // test DoubleVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "-------------" << std::endl;
   std::cout << "DoubleVector:" << std::endl;
   std::cout << "-------------" << std::endl;

   std::cout << "Testing Put"  << std::endl;
   dv.put(5.5);
   dv.put(10.1);
   dv.put(15.5);
   std::cout << "Results of Put:" << std::endl;
   std::cout << "";

   //-------------------------------------------------------------------------

   // using empty IntegerVector, test appending cv & dv from above
   IntegerVector iv2;

   std::cout << std::endl;
   std::cout << "--------------------------" << std::endl;
   std::cout << "appended-to IntegerVector:" << std::endl;
   std::cout << "\tappended CharacterVector: ";
   iv2.appendCharacterVector(cv);
   for (int i = 0; i < iv2.size(); i++) {
      if(iv2.get(i)!=cv.get(i)) {
        std::cout << "Error in appending";
      }
      std::cout << iv2.get(i) << "[" << cv.get(i) << "] ";
   }
   std::cout << "\t: Size: IV[" << iv2.size() << "] CV["<< cv.size() << "]" <<std::endl;

   const int INDEX = iv2.size();
   std::cout << "\tappended DoubleVector: ";
   iv2.appendDoubleVector(dv);
   for (int i = 0; i < dv.size(); i++) {
     std::cout << iv2.get(i+INDEX) << "[" << dv.get(i) << "] ";
   }
   std::cout << "\t: Size: IV[" << iv2.size() << "] DV["<< dv.size() << "]" <<std::endl;

   std::cout << "--------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty CharacterVector, test appending iv & dv from above
   CharacterVector cv2;

   std::cout << std::endl;
   std::cout << "----------------------------" << std::endl;
   std::cout << "appended-to CharacterVector:" << std::endl;
   std::cout << "----------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty DoubleVector, test appending iv & cv from above
   DoubleVector dv2;

   std::cout << std::endl;
   std::cout << "-------------------------" << std::endl;
   std::cout << "appended-to DoubleVector:" << std::endl;
   std::cout << "-------------------------" << std::endl;

   //-------------------------------------------------------------------------

   return 0;
}
