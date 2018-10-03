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
   std::cout << "\tiv.put(10):" << "\t\tiv.get(0): " << iv.get(0) << std::endl
      << std::endl;
   std::cout << "\tiv.put(20):" << "\t\tiv.get(1): " << iv.get(1) << std::endl
      << std::endl;
   iv.put(15, 0);
   std::cout << "\tiv.put(15, 0):" << "\t\tiv.get(0): " << iv.get(0) << std::endl
      << std::endl;
      // test put() for illegal indices
   iv.put(30, 50);
   std::cout << "\tiv.put(25, 99):" << "\t\tiv.get(2): " << iv.get(2) << std::endl
      << std::endl;

   std::cout << "--------------" << std::endl;
   std::cout << "Testing get()"  << std::endl;
   std::cout << "\tiv.get(0): " << iv.get(0) << " [15]" << std::endl;
   std::cout << "\tiv.get(1): " << iv.get(1) << " [20]" << std::endl;
   std::cout << "\tiv.get(2): " << iv.get(2) << " [30]" << std::endl;

   try {
     iv.get(50);
   }
   catch (const std::out_of_range& oor) {
    //  if (50 >= iv.size()) {
    //    std::string msg = "Index out of range: [" + 50 + "].";
    //    throw std::out_of_range(msg.c_str());
    //  }
     std::cerr << "Out of Range error: " << oor.what() << std::endl;
   }


   std::cout << "--------------" << std::endl;
   std::cout << "Testing size()"  << std::endl;
   std::cout << "\t\tSize: "   << iv.size() << " [3]" << std::endl;
   iv.put(40);
   std::cout << "iv.put(40):" << "\tSize: " << iv.size() << " [4]" << std::endl
      << std::endl;

   std::cout << "--------------" << std::endl;

   //-------------------------------------------------------------------------

   // test CharacterVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "----------------" << std::endl;
   std::cout << "CharacterVector:" << std::endl;
   std::cout << "----------------" << std::endl;

   //-------------------------------------------------------------------------

   // test DoubleVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "-------------" << std::endl;
   std::cout << "DoubleVector:" << std::endl;
   std::cout << "-------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty IntegerVector, test appending cv & dv from above
   IntegerVector iv2;

   std::cout << std::endl;
   std::cout << "--------------------------" << std::endl;
   std::cout << "appended-to IntegerVector:" << std::endl;
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
