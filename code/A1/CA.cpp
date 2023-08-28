/* 
*  Michael Ekstrom
*  A1
*  This program generates a 1D cellular automata based on a rule chosen by the user.
*/
#include <iostream>
using std::scanf;
using std::endl;
using std::cout;

/// @brief Controls how many generations the program will generate
const static int GENERATIONS = 50;
/// @brief Controls how many cells wide each generation is
const static int GENERATION_SIZE = 64;
/// @brief Sets the size of the rule set array
const static int RULE_ARRAY_SIZE = 8;

//Function Declarations
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSetArray[8]);
void displayCurrentGeneration(int currentGeneration[], int generationSize = GENERATION_SIZE);
int  convertNeighborhoodToIndex(int left, int center, int right);
void computeNextGeneration(int currentGeneration[], int nextGeneration[], int generationSize, int ruleSetArray[]);

/// @brief Program entry point for generating a 1D cellular Automata
int main() {
    int ruleSetNumber(0);
    cout << "Please enter a rule set number from 0-255: ";
    
    //scanf returns 1 if it parsed the correct data from the input, so anyting that isn't an
    //  integer is rejected. After that bounds are checked on the input from [0-255].
    if(scanf("%d",&ruleSetNumber) == 0 || ruleSetNumber < 0 || ruleSetNumber > 255) {
        cout << "Entry is outside of bounds [0-255] or is not a number." << endl;
        return 0;
    }
    int ruleArr[RULE_ARRAY_SIZE]{ };
    convertRuleSetNumberToRuleSetArray(ruleSetNumber,ruleArr);

    int* curGen  = new int[GENERATION_SIZE] { };
    int* nextGen = new int[GENERATION_SIZE] { };
    curGen[GENERATION_SIZE/2] = 1; //Adds a single 1 to center of starting population.

    for(int i = 0; i < GENERATIONS; i++) {
        displayCurrentGeneration(curGen);
        computeNextGeneration(curGen, nextGen, GENERATION_SIZE, ruleArr);

        //Swaps the pointer between the curGen and nextGen arrays so that what 
        //  was curGen now is the buffer for the nextGen and visa versa
        int* tmp = curGen;
        curGen = nextGen;
        nextGen = tmp;
    }
    return 0;
}

/// @brief This function populates the next generation array using the rule set and the current genration.
void computeNextGeneration(int curGen[], int nextGen[], int genSize, int ruleArr[]) {
    //Cells on each end stay the same
    nextGen[0] = curGen[0];
    nextGen[genSize-1] = curGen[genSize-1];

    for(int i = 1; i < genSize - 1; i++) 
        nextGen[i] = ruleArr[convertNeighborhoodToIndex(curGen[i-1], curGen[i], curGen[i+1])];
}

/// @brief This funciton converts an integer between [0-255] to binary in an array.
void convertRuleSetNumberToRuleSetArray(int ruleNum, int ruleArr[]) {
    for(int i = 0; ruleNum > 0; i++) {
        ruleArr[i] = ruleNum%2;
        ruleNum /= 2;
    }
}

/// @brief This function gets the index of the rule from the neighbors of the current index.
int convertNeighborhoodToIndex(int left, int current, int right) {
    int index = 0;
    index += left * 4;
    index += current * 2;
    index += right * 1;
    return index;
}

/// @brief This function prints the current generation
void displayCurrentGeneration(int curGen[], int genSize) {
    for(int i = 0; i < genSize; i++) {
        if(curGen[i] == 0) {
            cout << " ";
        } else  {
            cout << "#";
        }
    }
    cout << endl;
}                                                                        