#include <iostream> 
#include <string> 
#include <bits/stdc++.h>

using std::string; 

class BigNumber {  //must hold all the overrides as well 
    public:

    BigNumber(string num);

    string value; //make getters/ setters later
    
    string add(string first, string second); 
    string multiply(string first, string second);  

    string divide(string numerator, string denominator, int precision);

    string toString(); 
    
    void display();

    bool operator<(const BigNumber& second);
    bool operator>(const BigNumber& second);
    bool operator==(const BigNumber& second); 
    bool operator<=(const BigNumber& second);
    bool operator>=(const BigNumber& second);

    private:

    bool hasDecimal() const; 
    int length() const; 
    void addToString(string word); 
    
}; 