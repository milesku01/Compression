#include "Test.h"

using namespace std::chrono;

void Test::comparison() {
    double num = 1000010000; 
    
    auto start = high_resolution_clock::now();

    for(double i=1000000000; i<=num; ++i) {
        for(double j=1000000000; j<=num; ++j) {
            i / j; 
        }
    }   

    auto stop = high_resolution_clock::now(); 

    std::cout << "Divsion: " << duration_cast<microseconds>(stop-start).count() / (num-1000000000) << " microseconds \n"; 


    auto start2 = high_resolution_clock::now();
    
    for(double i=1000000000; i<=num; ++i) {
        for(double j=1000000000; j<=num; ++j) {
            sqrt(j);
        }
    } 

    auto stop2 = high_resolution_clock::now(); 

    std::cout << "Sqrt: " << duration_cast<microseconds>(stop2-start2).count() / (num-1000000000) << " microseconds \n"; 
}

double Test::squareRoot(int number, int precision) {
    int start = 0, end = number;
    int mid;
 
    // variable to store the answer
    double ans;
 
    // for computing integral part
    // of square root of number
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
 
        // incrementing start if integral
        // part lies on right side of the mid
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }
 
        // decrementing end if integral part
        // lies on the left side of the mid
        else {
            end = mid - 1;
        }
    }
 
    // For computing the fractional part
    // of square root upto given precision
    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
 
        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}