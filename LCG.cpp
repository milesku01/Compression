#include "LCG.h"

int LCG::generateNum(int a, int c, int m, int seed) {

    int size = 1024; 
    bool TorF = false; 
    
    bool array[size];
     for(int i=0; i < size; ++i) {
       array[i] = false; 
    }

    while(!TorF) {
        seed = (a * seed + c) % m;
      
       if(!array[seed]) {
           std::cout << seed << " "; 
            array[seed] = true;
        } else {
           
            TorF = true; 
        }
      
    }

    std::cout << "Seed " << seed; 

    int counter = 0; 
    for(int i : array) {
        if(array[seed]) ++counter;  
    }

    std::cout << "Counter " << counter; 
} 