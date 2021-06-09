// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June 9, 2021
// This program rounds numbers for the user

#include <iostream>
#include <cmath>

// round function
void Rounder(float &numFunc, int numRoundFunc) {
    // makes the number larger by a factor of 10 * the number of decimal
    // places requested by the user
    numFunc = numFunc * pow(10, numRoundFunc);
    // if the number is negative then we substract 0.5
    // and the oposite for positive, this is so that
    // any number with .5 will round correctly
    if (numFunc < 0) {
        numFunc = numFunc - 0.5;
    } else {
        numFunc = numFunc + 0.5;
    }
    // turn it into an integer to get rid of all those pesky decimals
    numFunc = static_cast<int>(numFunc);
    numFunc = static_cast<float>(numFunc);
    // now move the decimal place back to where it was originally
    numFunc = numFunc / pow(10, numRoundFunc);
}


int main() {
    std::cout << "Hello! This program will round a number for you!";
    // make the string version of the var
    std::string numStr;
    std::string numRoundStr;
    // make the other variables
    float num;
    float numRound;

    // get the number from the user
    std::cout << "What is the number you want to round: ";
    std::cin >> numStr;
    std::cout << "How many decimal places do you want: ";
    std::cin >> numRoundStr;

    try {
        // try to turn it into a integer
        num = std::stof(numStr);
        numRound = std::stof(numRoundStr);

        // if user inputs a negative for the rounder
        if (numRound < 0) {
            std::cout << "You can not round by a negative";
        // if user inputs a decimal for the rounder
        } else if (static_cast<int>(numRound) != numRound) {
            std::cout << "You can not round by decimals";
        } else {
            // call the function using reference
            Rounder(num, numRound);
            // print the number rounded to the user
            std::cout << num;
        }

    // if could not turn into integer
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number";
    }
}
