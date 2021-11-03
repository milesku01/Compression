#include "BigNumber.h"

BigNumber::BigNumber(string num) {
    value = num; 
}

string BigNumber::add(string first, string second) { //fairly inefficient layout atm

    //add later a filter for improper numbers (multiple decimal points etc... )

    if(first[0] == '.') first = '0' + first; 
    if(second[0] == '.') second = '0' + second; 

    char* char_arr;
    reverse(first.begin(), first.end());
    string str_obj(first);
    char_arr = &str_obj[0];

    char* char_arr2;
    reverse(second.begin(), second.end());
    string str_obj2(second);
    char_arr2 = &str_obj2[0];

    bool firstHasDecimal = false; 
    bool secondHasDecimal = false; 


    for(int i=0; i < first.length(); ++i) {
        
        if(char_arr[i] == '.') {
            firstHasDecimal = true; 
        }
    }

    for(int i=0; i < second.length(); ++i) {
        
        if(char_arr2[i] == '.') {
            secondHasDecimal = true; 
        }
    }

    int* result; 
    bool firstLarger = false; 
    int larger = 0; 
    string toReturn = ""; 

    if(!firstHasDecimal && !secondHasDecimal) {
        
        if(first.length() > second.length()) {
            larger = first.length(); 
            firstLarger = true; 
        } else {
            larger = second.length(); 
        }

        result = new int[larger + 1]; 

        for(int i=0; i < larger + 1; ++i) {
            result[i] = 0;
        }

        for(int i=0; i < larger; ++i) {
            if(firstLarger && i > second.length() - 1) {
                char_arr2[i] = '0'; 
            } else if(i > first.length() - 1) {
                char_arr[i] = '0'; 
            }
            
            if(result[i] + char_arr[i] + char_arr2[i] - 2*'0' >= 10) {
                result[i] -= 10; 
                ++(result[i + 1]); 
            }

            result[i] += char_arr[i] + char_arr2[i] - 2*'0';
        }
    } else {
        string firstF = ""; 
        string firstS = "";  
        string secondF = ""; 
        string secondS = ""; 

        

        if(firstHasDecimal) {
            for(int i=0; i < first.length(); ++i) {
                if(first[i] == '.'){
                    firstS = first.substr(0, i);
                    firstF = first.substr(i+1, first.length() - 1);
                }
            }
        } else {
            firstF = first;  
        }

        if(secondHasDecimal) {
            for(int i=0; i < second.length(); ++i) {
                if(second[i] == '.') {
                    secondS = second.substr(0, i);
                    secondF = second.substr(i+1, second.length() - 1);
                }
            }
        } else {
            secondF = second; 
        }

        bool largerDecimal = false;

        if(firstS.length() > secondS.length()) {
            largerDecimal = true; 
        }

        reverse(firstF.begin(), firstF.end()); reverse(secondF.begin(), secondF.end());
        reverse(firstS.begin(), firstS.end()); reverse(secondS.begin(), secondS.end());

        string temp = add(firstF, secondF);

        //could be shortened 
        //must also handle case where decimal is resolved
        if(firstS.length() > secondS.length()) {
            int common = secondS.length(); 

            string sub1 = add(firstS.substr(0, common), secondS.substr(0, common)); 

            //std::cout << "SUB " << sub1 << std::endl; 
            if(sub1.length() > common) {
                temp = add(temp, "1"); //can prob
                sub1 = sub1.substr(1);  
            }
            

            sub1 += firstS.substr(common, firstS.length()); //was firstS.length() - 1
            //std::cout << "SUB " << sub1 << std::endl;

            temp += ("." + sub1);
        } else if(secondS.length() > firstS.length()){
            int common = firstS.length(); 
            string sub1 = add(firstS.substr(0, common), secondS.substr(0, common)); 

            if(sub1.length() > common) {
                temp = add(temp, "1");
                sub1 = sub1.substr(1);  
            }

            sub1 += secondS.substr(common, secondS.length()); 

            temp += ("." + sub1);
        } else {
            string sub1 = add(firstS.substr(0, firstS.length()), secondS.substr(0, firstS.length())); //should have same length
             if(sub1.length() > firstS.length()) {
                temp = add(temp, "1");
                sub1 = sub1.substr(1);  
            }

            temp += ("." + sub1);
        }

        toReturn = temp; 
    }

    

    if(!firstHasDecimal && !secondHasDecimal) {
        for(int i=0; i < larger; ++i) { //fix
            toReturn += (char) result[i] + '0';
        }

        if(result[larger] != 0) {
            toReturn += (char) result[larger] + '0';
        }

        reverse(toReturn.begin(), toReturn.end()); 
        return toReturn;
    } else {
        return toReturn;
    }


}

string BigNumber::multiply(string first, string second) {
   
    reverse(first.begin(), first.end());
    
    reverse(second.begin(), second.end());
  

    bool firstHasDecimal = false; 
    bool secondHasDecimal = false; 


    for(int i=0; i < first.length(); ++i) {
        
        if(first[i] == '.') {
            firstHasDecimal = true; 
        }
    }

    for(int i=0; i < second.length(); ++i) {
        
        if(second[i] == '.') {
            secondHasDecimal = true; 
        }
    }

    int* result;
    string toReturn = "";

    if(!firstHasDecimal && !secondHasDecimal) {
        result = new int[first.length() + second.length()]; 

        for(int i=0; i < first.length() + second.length(); ++i) {
            result[i] = 0;
        }

        //std::cout << (first[0] - '0') * (second[0] - '0') << std::endl;

        for(int i=0; i < first.length(); ++i) {
            for(int j=0; j < second.length(); ++j) {

            if(result[i+j] + ((first[i] - '0') * (second[j] - '0')) >= 10) {
                result[i+j+1] += ( result[i+j] + (first[i] - '0') * (second[j] - '0')) / 10; 
            }

            //result[i+j] += ((first[i] - '0') * (second[j] - '0')) % 10;
                result[i+j] = ( result[i+j] + (first[i] - '0') * (second[j] - '0')) % 10;
            }
        }

       
        for(int i=0; i < first.length() + second.length() - 1; ++i) {
            toReturn += result[i] + '0';
        }

        if(result[first.length() + second.length() - 1] != 0) {
            toReturn += result[first.length() + second.length() - 1] + '0'; 
        }

    } else {
        int decimalSpaces = 0;
        int counter = 0;
         if(firstHasDecimal) {
             while(first[counter] != '.') {
                 ++counter;
             }

             decimalSpaces += counter; 

             first.erase(counter, 1);
         } 

         counter = 0;

         if(secondHasDecimal) {
             while(second[counter] != '.') {
                 ++counter;
             }

             decimalSpaces += counter; 

             second.erase(counter, 1); 
         }

        reverse(first.begin(), first.end()); reverse(second.begin(), second.end()); 
        //std::cout << first << std::endl; 
        //std::cout << second << std::endl;

        string toReturn = multiply(first, second);

        //std::cout << toReturn; 


        reverse(toReturn.begin(), toReturn.end());
        toReturn.insert(decimalSpaces, ".");
        reverse(toReturn.begin(), toReturn.end());

        return toReturn; 
    }  

    reverse(toReturn.begin(), toReturn.end());

    return toReturn; 
}

string BigNumber::divide(string numeratorStr, string denominatorStr, int precision) {
    
    
    //string tableOfValue[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //string table[9]; //table with all 9 multiples of 

    BigNumber numerator(numeratorStr);
    BigNumber denominator(denominatorStr);

    bool numeratorHasDecimal = false; 
    bool denominatorHasDecimal = false; 

    //condense this, possibly by passing type BigNumber instead of type string
    for(int i=0; i < numeratorStr.length(); ++i) {
        
        if(numeratorStr[i] == '.') {
            numeratorHasDecimal = true; 
        }
    }

    for(int i=0; i < denominatorStr.length(); ++i) {
        
        if(denominatorStr[i] == '.') {
            denominatorHasDecimal = true; 
        }
    }

    string multiplier("1"); 
    string low("1");
    string high("1"); 

    if(!numeratorHasDecimal && !denominatorHasDecimal) {
       if(numerator > denominator) {
           //std::cout << "TRUE" << std::endl; 
           

           while(BigNumber(multiply(denominatorStr, multiplier)) <= BigNumber(multiply(numeratorStr, ".5"))) {
               //std::cout << multiplier << std::endl;
               multiplier = multiply(multiplier, "2"); 
               
           }

           
           low = multiplier; 
           string average = multiply(multiplier, "1.5");
           high = multiply(multiplier,"2");

           //std::cout << multiply(denominatorStr, average) << std::endl;

           //begin binary searching
           for(int i=0; i < precision; ++i) { //edit
                //std::cout << "HERE " << multiply(denominatorStr, average) << std::endl; 
                
               if(BigNumber(multiply(denominatorStr, average)) == BigNumber(numerator)) {
                   //std::cout << "Success" << std::endl; 
                   break;
               }
               else if(BigNumber(multiply(denominatorStr, average)) < BigNumber(numerator)) {
                   //std::cout << "RUn" << std::endl;
                   //std::cout << average << std::endl;
                   //std::cout << high << std::endl;
                   low = average;
                   average = multiply(add(average, high), ".5");
               } else if(BigNumber(multiply(denominatorStr, average)) > BigNumber(numerator))  {
                   //std::cout << "This Run" << std::endl;
                   //std::cout << high << std::endl;
                   //std::cout << average << std::endl;
                   //std::cout << low << std::endl;
                   high = average;
                   average = multiply(add(average, low), ".5");
               }

               //std::cout <<  "AVG " << average << std::endl; 
           }

           return average; 


/*
           for(int i=0; i < precision; ++i) { //edit
                if(multiply(denominator, multiplier) < numerator) {
                    multiplier = multiply(multiplier, multiplierAdjustment); 
                } else if(multiply(denominator, multiplier) > numerator) {
                    multiplumultiply();
                }
           }
           */
       } else if (numerator < denominator) {

       }
    }



}

bool BigNumber::hasDecimal() const{

    for(int i=0; i < value.length(); ++i) { //change to while for efficiency
        
        if(value[i] == '.') {
           return true;
        }
    }

    return false;
}

int BigNumber::length() const{
    return value.length(); 
}

void BigNumber::addToString(string word) {
    value += word;
}

void BigNumber::display() {
    for(char i : value) {
        std::cout << i; 
    }
     std::cout << std::endl; 
}

string BigNumber::toString() {
    return value; 
}

bool BigNumber::operator<(const BigNumber& second) {
    if(!this->hasDecimal() && !second.hasDecimal()) {
        if(this->length() < second.length()) {
            return true;
        } else if(this->length() == second.length()) {
            int counter = 0;
            while(counter < this->length()) {
                if(value[counter] < second.value[counter]) {
                    return true; 
                } else if(value[counter] == second.value[counter]) { 
                    ++counter; 
                } else {
                    return false; 
                }
            }
        } else {
            return false; 
        }
    } else { //one or both has decimals
        int firstDecimalPos = value.length();
        int secondDecimalPos = second.length();

        if(this->hasDecimal()) {
            for(int i=0; i<value.length(); ++i ) {
                if(value[i] == '.') {
                    firstDecimalPos = i;
                    break;
                }
            }
        }

        if(second.hasDecimal()) {
            for(int i=0; i<second.value.length(); ++i ) {
                if(second.value[i] == '.') {
                   secondDecimalPos = i;
                    break;
                }
            }
        }

        //std::cout << "First " << firstDecimalPos << " " << secondDecimalPos; 

        if(firstDecimalPos < secondDecimalPos) {
            return true; 
        } else if(firstDecimalPos == secondDecimalPos) {
            
            BigNumber one(this->value.substr(0, firstDecimalPos));
            BigNumber two(second.value.substr(0, secondDecimalPos));

            
            if(one == two) {

                //pad end of decimal
                if(this->length() - one.length() != second.length() - two.length()) {
                    if(this->length() - one.length() < second.length() - two.length()) {
                        for(int i=this->length() - one.length(); i < second.length() - two.length(); ++i) {
                            this->addToString("0"); 
                        }
                    }
                }

                BigNumber oneDec("0");
                BigNumber twoDec("0");  

                if(this->hasDecimal()) {
                    oneDec = BigNumber(this->value.substr(firstDecimalPos + 1));
                } 
                if(second.hasDecimal()) {
                    twoDec = BigNumber(second.value.substr(secondDecimalPos + 1));
                } 
               
                if(oneDec < twoDec) {
                    return true;
                } else {
                    return false; 
                }
            } else if(one < two) {
                return true;
            } else {
                return false; 
            }

        } else {
            return false; 
        }
    }
} 

bool BigNumber::operator>(const BigNumber& second) {
    return !(*this < second); 
}

bool BigNumber::operator<=(const BigNumber& second) {
    return (*this < second) || (*this == second);
}

bool BigNumber::operator>=(const BigNumber& second) {
    return (*this > second) || (*this == second);
}


//decimal position code can be shortend and stored as a second variable
bool BigNumber::operator==(const BigNumber& second) {
    if(!this->hasDecimal() && !second.hasDecimal()) {
        if(this->length() == second.length()) {
            for(int i=0; i < this->length(); ++i) {
                if(this->value[i] != second.value[i]) {
                    return false; 
                }
            }
            return true; 
        } else {
            return false; 
        }
    
    } else { //both have a decimal
        int firstDecimalPos = value.length();
        int secondDecimalPos = second.length();

        if(this->hasDecimal()) {
            for(int i=0; i<value.length(); ++i ) {
                if(value[i] == '.') {
                    firstDecimalPos = i;
                    break;
                }
            }
        }

        if(second.hasDecimal()) {
            for(int i=0; i<second.value.length(); ++i ) {
                if(second.value[i] == '.') {
                   secondDecimalPos = i;
                    break;
                }
            }
        }

        if(firstDecimalPos != secondDecimalPos) {
            
            return false; 
        } else if(firstDecimalPos == secondDecimalPos) {

            
            BigNumber one(this->value.substr(0, firstDecimalPos));
            BigNumber two(second.value.substr(0, secondDecimalPos));


            if(one == two) {

                if(this->length() - one.length() != second.length() - two.length()) {
                    if(this->length() - one.length() < second.length() - two.length()) {
                        for(int i=firstDecimalPos; i<this->length() - one.length(); ++i) { 
                            if(this->value[i] != second.value[i]) {
                                return false;
                            }
                        }

                        for(int i=1; i<second.length() - two.length() - (this->length() - one.length() ); ++i) {
                            if(second.value[secondDecimalPos + i] != '0') {
                                return false;
                            }
                        }
                    } else if(this->length() - one.length() > second.length() - two.length()) {
                       
                        for(int i=secondDecimalPos; i<second.length() - two.length(); ++i) { 
                            if(this->value[i] != second.value[i]) {
                                return false;
                            }
                        }

                        for(int i=1; i < this->length() - one.length() - (second.length() - two.length()); ++i) {
                            if(this->value[firstDecimalPos + i] != '0') {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }

            return false;

        } else {
            
            return false; 
        }
    }
}





