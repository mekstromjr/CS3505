/*
Michael Ekstrom
A1: 1D Cellular Automata
This builds a 1D cellular Automata using a specific rule provided by the user.
*/

#include <iostream>
using namespace std;

/// @brief The number of generations the 1D Automota will run for
const int generations = 50;
/// @brief The size (width) of each generation.
const int generationSize = 64;
/// @brief The size of the rule set (do not modify)
const int ruleSetArrSize = 8;

/// @brief Prints to the console the generation input. " " if the index contained 0, "#" if it contained 1.
/// @param arr - Array Containing the current generation
/// @param arrSize - The size of the input Array (usually const int generationsSize)
void displayGeneration(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == 0)
            cout << " ";
        else
            cout << "#";
    }
    cout << endl;
}

/// @brief Takes an integer from 0-255 and converts it into an array containing that numbers
/// binary digits from left to right.
/// @param ruleSet An integer from 0-255 representing the rule set.
/// @param ruleSetArr An array for holding the rule set represented in binary.
void convertRuleSetNumberToRuleSetArray (int ruleSet, int ruleSetArr[8]) {
    for(int i = 7; i >= 0; i--) {
        int factor = 1;
        for (int j = i; j > 0; j--) 
            factor *= 2;

        if(ruleSet >= factor) {
            ruleSetArr[i] = 1;
            ruleSet -= factor;
        } else {
            ruleSetArr[i] = 0;
        }
    }
}

/// @brief Takes three integers and returns the index in the ruleset coresponding with their situation.
/// @param left
/// @param current 
/// @param right 
/// @return 
int convertNeighborhoodToIndex(int left, int current, int right) {
    int result = 0;

    result += left * 4;
    result += current * 2;
    result += right * 1;

    return result;
}

/// @brief Takes the current generation and, using the rule set produces the next generation, storing it in nextGen.
/// @param curGen 
/// @param nextGen 
/// @param arrSize - size (width) of the generation.
/// @param ruleSet - An array containing the binary representation of the rule set.
void computeNextGeneration(int curGen[], int nextGen[], int arrSize, int ruleSet[]) {
    nextGen[0] = curGen[0];
    nextGen[arrSize-1] = curGen[arrSize-1];

    for(int i = 1; i < arrSize - 1; i++){
        int ruleIndex = convertNeighborhoodToIndex(curGen[i-1], curGen[i], curGen[i+1]);
        nextGen[i] = ruleSet[ruleIndex];
    }
}

/// @brief This is the 1D automota driver method.
/// @return 
int main() {
    int ruleSetNum = 0;
    cout << "Enter a rule set number from 0-255: ";
    cin >> ruleSetNum;

    if(ruleSetNum < 0 || ruleSetNum > 255) {
        cout << "Number entered was invalid or outside of bounds (0-255)" << endl;
        return 0;
    }

    int ruleSet[ruleSetArrSize];
    convertRuleSetNumberToRuleSetArray(ruleSetNum, ruleSet);

    int * curGen  = new int[generationSize];
    int * nextGen = new int[generationSize];
    
    //Initialize First Generation
    for(int i = 0; i < generationSize; i++) {
        curGen[i] = 0;
        if(i == generationSize/2)
            curGen[i] = 1;
    }

    for(int i = 0; i < generations; i++) {
        displayGeneration(curGen, generationSize);
        computeNextGeneration(curGen, nextGen, generationSize, ruleSet);

        //Swap the pointer between the curGen and nextGen arrays so that what was curGen now is the buffer for the nextGen and visa versa
        int * tmp = curGen;
        curGen = nextGen;
        nextGen = tmp;
    }
    displayGeneration(curGen, generationSize);
    return 0;
}

