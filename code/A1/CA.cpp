#include <iostream>

using namespace std;

/*
Michael Ekstrom
A1: 1D Cellular Automata
This builds a 1D cellular Automata using a specific rule provided by the user.
*/
//Checked - Working As Expected
void displayGeneration(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == 0)
            cout << " ";
        else
            cout << "#";
    }
    cout << endl;
}

//Checked - Working As expected
void convertRuleSetNumberToRuleSetArray (int ruleSet, int ruleSetArr[8]) {
    for(int i = 7; i >= 0; i--) {
        int factor = 1;
        for (int j = i; j > 0; j--) 
            factor *= 2;

        if(ruleSet >= factor) {
            ruleSetArr[i] = 1;
            ruleSet -= factor;
        }
        else {
            ruleSetArr[i] = 0;
        }
    }
}

//Checked - Working As Expected
int convertNeighborhoodToIndex(int left, int current, int right) {
    int result = 0;
    result += left * 4;
    result += current * 2;
    result += right * 1;

    return result;
}


void computeNextGeneration(int curGen[], int nextGen[], int arrSize, int ruleSet[]) {
    //Debugging
    nextGen[0] = curGen[0];
    nextGen[arrSize-1] = curGen[arrSize-1];

    for(int i = 1; i < arrSize - 1; i++){

        int ruleIndex = convertNeighborhoodToIndex(curGen[i-1], curGen[i], curGen[i+1]);

        nextGen[i] = ruleSet[ruleIndex];
    }
}


int main() {
    int ruleSetNum;
    int generations = 50;
    int generationSize = 64;
    int ruleSetArrSize = 8;
    cout << "Enter a rule set number from 0-255: ";
    cin >> ruleSetNum;

    //If a value outside that range is input, an explanatory message should be output and the program ended 
    if(ruleSetNum < 0 || ruleSetNum > 255) {
        cout << "Number entered was invalid or outside of bounds (0-255)" << endl;
        return 0;
    }

    //Save the ruleSet in a rule set array as a binary number
    int ruleSet[ruleSetArrSize];
    convertRuleSetNumberToRuleSetArray(ruleSetNum, ruleSet);

    int * curGen  = new int[generationSize];
    int * nextGen = new int[generationSize];
    
    for(int i = 0; i < generationSize; i++) {
        curGen[i] = 0;
        if(i == generationSize/2)
            curGen[i] = 1;
    }

    for(int i = 0; i < generations; i++) {
        displayGeneration(curGen, generationSize);
        computeNextGeneration(curGen, nextGen, generationSize, ruleSet);
        int * tmp = curGen;
        curGen = nextGen;
        nextGen = tmp;
    }

    displayGeneration(curGen, generationSize);

    return 0;
}

