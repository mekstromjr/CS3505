/**
 * Author:      Max Sone
 * Assignment:  A1: 1D Cellular Automata
 * Description: Simple cellular automata simulation with user input 
*/

#include <iostream>

// Forward declaration
void convertRuleSetNumberToRuleSetArray(int, int*);
void displayCurrentGeneration(int*, int);
void computeNextGeneration(int*, int*, int, int*);
int convertNeighborhoodToIndex(int, int, int);

// Main
int main() {
    // Input
    std::string input = "Default";
    int ruleSetNumber = 0;
    std::cout << "Enter rule set number between 0 to 255 to begin:" << std::endl;
    std::cin >> input;

    // Check if input is number
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            std::cout << "Input is not a number" << std::endl;
            return 0;
        }
    }

    // If number, check if input is within range
    ruleSetNumber = std::stoi(input);
    if (ruleSetNumber < 0 || ruleSetNumber > 255) {
        std::cout << "Input not within range of 0 to 255" << std::endl;
        return 0;
    }

    // Initialize arrays
    int ruleSetArray[8] = {0};
    convertRuleSetNumberToRuleSetArray(ruleSetNumber, ruleSetArray);
    int genSize = 64;
    int currGen[genSize] = {0};
    int nextGen[genSize] = {0};
    currGen[32] = 1;

    // Calculate and print generation
    for (int i = 0; i < 50; i++) {
        displayCurrentGeneration(currGen, genSize);
        computeNextGeneration(currGen, nextGen, genSize, ruleSetArray);
        for (int j = 0; j < genSize; j ++) {
            currGen[j] = nextGen[j];
        }
    }    
}

// Converts the given rule set number into a binary representation in a rule set array
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSetArray[8]) {
    ruleSetArray[8] = {0};
    int ruleSetNumberTemp = ruleSetNumber;
    int binaryTemp = 128;
    std::string finalBinary = "";

    // The [7-i] rather than just [i] is for filling the array backwards 
    for (int i = 0; i < 8; i++) {
        if (ruleSetNumberTemp >= binaryTemp) {
            ruleSetArray[7-i] = 1;
            ruleSetNumberTemp = ruleSetNumberTemp - binaryTemp;
            finalBinary = finalBinary + "1";   
        } else {
            ruleSetArray[7-i] = 0;
            finalBinary = finalBinary + "0";
        }
        binaryTemp = binaryTemp / 2;
    }
}

// Print given generation array, where zeroes are whitespace and ones are #
void displayCurrentGeneration(int binaryArray[], int arrayLength) {
    std::string currGenStr = "";

    for (int i = 0; i < arrayLength; i ++) {
        if (binaryArray[i] == 0) {
            currGenStr = currGenStr + " ";
        } else if (binaryArray[i] == 1) {
            currGenStr = currGenStr + "#";
        }
    }

    std::cout << currGenStr << std::endl;
}

// Computes the next generation array given the current generation and a given ruleset
void computeNextGeneration(int currGen[], int nextGen[], int arrLength, int ruleSet[]) {
    nextGen[0] = currGen[0];
    nextGen[arrLength-1] = currGen[arrLength-1];
    for (int i = 1; i < arrLength - 1; i++) {
        nextGen[i] = ruleSet[convertNeighborhoodToIndex(currGen[i-1], currGen[i], currGen[i+1])];
    }
}

// Does computation for individual cells within the automata
// Converts given parameters from binary to base 10
int convertNeighborhoodToIndex(int left, int middle, int right) {
    return left*4 + middle*2 + right*1;
}