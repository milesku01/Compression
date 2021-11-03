#include <iostream>
#include "FileReader.h"
#include "FileWriter.h"
#include "LCG.h"
#include "Test.h"
#include "BigNumber.h"
#include <cmath> 

int main() {
    //comment
    FileReader fr;
    FileWriter fw; 
    LCG lcg; 
    Test test; 

   // test.comparison(); 

    //std::cout << 256%257;

   // lcg.generateNum(75,74, pow(2,10)+1 , 2);

   //std::cout << test.squareRoot(2, 10);

  
  /*

   std::cout << num.add("1", "1") << std::endl; 
   std::cout << num.add("15", "15") << std::endl; ; 
   std::cout << num.add("163", "237") << std::endl; ; 
   std::cout << num.add("1.63", "1.37") << std::endl; ; 
   std::cout << num.add("1.112", "1.1") << std::endl; ; 
   std::cout << num.add("1.1", "1.112") << std::endl; ; 
   std::cout << num.add(".25", ".25") << std::endl; 

   */

  //std::cout << num.multiply("2.5", "7.95");
  //std::cout << num.multiply("12.5", "25");

  BigNumber num1("123.09");
  BigNumber num2("12.1");

  //BigNumber num3("4.5");
  //BigNumber num4("2"); 
  BigNumber num5("9.0");

  //std::cout << (num1 == num2);

  //std::cout << (BigNumber(num1.multiply("4.5", "2")) == num5); 
  //std::cout << num1.add("1.42", "1.79") << std::endl;
  //std::cout << num1.multiply(num1.add("1.875", "1.75"), ".5");
  std::cout << num1.divide("13", "7", 300); 
  
  
  //std::cout << (BigNumber("7") == BigNumber("4.5")) << std::endl;
  //num1.display();
  
}
