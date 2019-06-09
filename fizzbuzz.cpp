//
//  fizzbuzz.cpp
//  practice
//
//  Created by Kelsey Blair on 2015-10-01.
//  Copyright © 2015 Kelsey Blair. All rights reserved.
//

#include "header.h"

void fizz_buzz() {
    for (int i = 1; i<=100; i++) {
        if (i%5==0 and i%3==0) std::cout << "FIZZBUZZ";
        else if (i%3==0) std::cout << "Fizz";
        else if (i%5==0) std::cout << "Buzz";
        else std::cout << i;
        std::cout << "\n";
    }
    
    std::cout << "Hello, World!\n";
}