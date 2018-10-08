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
   iv.put(65);
   iv.put(70);
   std::cout << "\tiv.put(65):" << "\t\tiv.get(0): " << iv.get(0) << std::endl;
   std::cout << "\tiv.put(70):" << "\t\tiv.get(1): " << iv.get(1) << std::endl;
   iv.put(75, 0);
   std::cout << "\tiv.put(75, 0):" << "\t\tiv.get(0): " << iv.get(0) << std::endl;

  // test put() for illegal indices
   iv.put(85, 50);
   std::cout << "\tiv.put(85, 50):" << "\t\tiv.get(2): " << iv.get(2) << std::endl;

   std::cout << "--------------" << std::endl;
   std::cout << "Testing get()"  << std::endl;
   std::cout << "\tiv.get(0): " << iv.get(0) << " [75]" << std::endl;
   std::cout << "\tiv.get(1): " << iv.get(1) << " [70]" << std::endl;
   std::cout << "\tiv.get(2): " << iv.get(2) << " [85]" << std::endl;

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
     std::cerr << "\tOut of Range error: " << oor.what() << std::endl;
   }

   std::cout << "--------------" << std::endl;
   std::cout << "Testing size()"  << std::endl;
   std::cout << "\t\tSize: "   << iv.size() << " [3]" << std::endl;
   iv.put(90);
   std::cout << "iv.put(90):" << "\tSize: " << iv.size() << " [4]" << std::endl;

   std::cout << "--------------" << std::endl;

   //-------------------------------------------------------------------------

   // test CharacterVector: put, get, size, out_of_range
   std::cout << std::endl;
   std::cout << "----------------" << std::endl;
   std::cout << "CharacterVector:" << std::endl;
   std::cout << "***** Testing initial size [0] *****" << std::endl;
   std::cout << "\tThe size of the vector: " << cv.size() << std::endl;
   std::cout << "***** Testing 'get' method error handling [Out of Range error] (index >= size) *****" << std::endl;
   try {
      std::cout << "\tThe char at index 0: " << cv.get(0) << std::endl;
   } catch(std::exception& e) {
      std::cerr << "\tOut of Range error: " << e.what() << std::endl;
   }
   std::cout << "***** Testing 'get' method error handling [Out of Range error] (negative index) *****" << std::endl;
   try {
      std::cout << "\tThe char at index -1: " << cv.get(-1) << std::endl;
   } catch(std::exception& e) {
      std::cerr << "\tOut of Range error: " << e.what() << std::endl;
   }

   cv.put('a');
   cv.put('b');
   cv.put('c', 5);

   std::cout << "***** Testing the size after putting 3 characters [3] *****" << std::endl;
   std::cout << "\tThe size of the vector: " << cv.size() << std::endl;
   std::cout << "***** Testing 'get' method [c] *****" << std::endl;
   std::cout << "\tThe char at index 2: " << cv.get(2) << std::endl;

   cv.put('f', 1);

   std::cout << "***** Testing the size after replacing one of the characters [3] *****" << std::endl;
   std::cout << "\tThe size of the vector: " << cv.size() << std::endl;
   std::cout << "***** Testing 'get' method [c] *****" << std::endl;
   std::cout << "\tThe char at index 2: " << cv.get(2) << std::endl;
   std::cout << "***** Testing 'get' method [f] *****" << std::endl;
   std::cout << "\tThe char at index 1: " << cv.get(1) << std::endl;
   std::cout << "----------------" << std::endl;

   //-------------------------------------------------------------------------

   // test DoubleVector: put, get, size, out_of_range


   std::cout << std::endl;
   std::cout << "-------------" << std::endl;
   std::cout << "DoubleVector:" << std::endl;
   std::cout << "-------------" << std::endl;

   std::cout << "Testing Put"  << std::endl;
   dv.put(5.5);
   std::cout << "\tput(5.5) - size: " << dv.size() << std::endl;

   dv.put(10.1);
   std::cout << "\tput(10.1) - size: " << dv.size()<< std::endl;

   dv.put(15.5);
   std::cout << "\tput(15.5) - size: " << dv.size() << std::endl;

   std::cout << "-------------" << std::endl;

   std::cout << "Testing Get"  << std::endl;
   std::cout << "\tget(0): " << dv.get(0) << "[5.5]" << std::endl;
   std::cout << "\tget(1): " << dv.get(1) << "[10.1]" << std::endl;
   std::cout << "\tget(2): " << dv.get(2) << "[15.5]" << std::endl;

   std::cout << "Testing Out of Range" << std::endl;


   std::cout << "\tget(4): ";
   try {
      dv.get(4);
   } catch(const std::out_of_range& oor) {
      std::cout << std::endl;
      std::cerr << "\tOut of Range error: " << oor.what() << std::endl;
   }

   std::cout << "\tget(-1): ";
   try {
     dv.get(-1);
   }
   catch (const std::out_of_range& oor) {
     std::cout << std::endl;
     std::cerr << "\tOut of Range error: " << oor.what() << std::endl;
   }
 std::cout << "------------" << std::endl;

   std::cout << "Testing Size" << std::endl;
   std::cout << "size(): " << dv.size() << "[3]" << std::endl;
   dv.put(1.1);
   dv.put(7.7);
   std::cout << "size(): " << dv.size() << "[5]" << std::endl;


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
   std::cout << std::endl << "\t\tSize: IV[" << iv2.size() << "] CV["
      << cv.size() << "]" <<std::endl << std::endl;

   const int INDEX = iv2.size();
   std::cout << "\tappended DoubleVector: ";
   iv2.appendDoubleVector(dv);
   for (int i = 0; i < dv.size(); i++) {
     std::cout << iv2.get(i+INDEX) << "[" << dv.get(i) << "] ";
   }
   std::cout << std::endl << "\t\tSize: IV[" << iv2.size() << "] DV["
      << dv.size() << "]" << std::endl << std::endl;

   std::cout << "--------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty CharacterVector, test appending iv & dv from above
   CharacterVector cv2;
   iv.put(65, 0);
   iv.put(66, 1);
   iv.put(67, 2);
   iv.put(68, 3);
   dv.put(69.3, 0);
   dv.put(70.0, 1);
   dv.put(71.2, 2);
   dv.put(72.9, 3);

   std::cout << std::endl;
   std::cout << "----------------------------" << std::endl;
   std::cout << "appended-to CharacterVector:" << std::endl;
   std::cout << "\tappended IntegerVector: ";
   cv2.appendIntegerVector(iv);
   for (int i = 0; i < iv.size(); i++) {
      if(cv2.get(i)!= iv.get(i)) {
        std::cout << "Error in appending";
      }
      std::cout << cv2.get(i) << "[" << iv.get(i) << "] ";
   }
   std::cout << "\n \tSize: CV[" << cv2.size() << "] IV["<< iv.size() << "]" << std::endl;
   std::cout << std::endl;

   std::cout << "\tappended DoubleVector: ";
   const int INDEX2 = cv2.size();
   cv2.appendDoubleVector(dv);
   for (int i = 0; i < dv.size(); i++) {
      std::cout << cv2.get(i + INDEX2) << "[" << dv.get(i) << "] ";
   }
   std::cout << "\n \tSize: CV[" << cv2.size() << "] DV["<< dv.size() << "]" << std::endl;
   std::cout << std::endl;

   std::cout << "----------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty DoubleVector, test appending iv & cv from above
   
   DoubleVector dv2;
   cv.put('a', 0);
   cv.put('b', 1);
   cv.put('c', 2);
   cv.put('d', 3);
   iv.put(11, 0);
   iv.put(22, 1);
   iv.put(33, 2);
   iv.put(44, 3);

   std::cout << std::endl;
   std::cout << "-------------------------" << std::endl;
   std::cout << "appended-to DoubleVector:" << std::endl;
   std::cout << "\tappended IntegerVector: ";
   dv2.appendIntegerVector(iv);
   for (int i = 0; i < iv.size(); i++) {
      if(dv2.get(i)!=iv.get(i)) {
        std::cout << "Error in appending";
      }
      std::cout << dv2.get(i) << "[" << iv.get(i) << "] ";
   }
   std::cout << std::endl << "\t\tSize: DV[" << dv2.size() << "] IV["
      << iv.size() << "]" << std::endl << std::endl;

   const int INDEX3 = dv2.size();
   std::cout << "\tappended CharacterVector: ";
   dv2.appendCharacterVector(cv);
   for (int i = 0; i < cv.size(); i++) {
     std::cout << dv2.get(i+INDEX3) << "[" << cv.get(i) << "] ";
   }
   std::cout << std::endl << "\t\tSize: DV[" << dv2.size() << "] CV["
      << cv.size() << "]" << std::endl << std::endl;

   std::cout << "-------------------------" << std::endl;

   //-------------------------------------------------------------------------

   return 0;
}
