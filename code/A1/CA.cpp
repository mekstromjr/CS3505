#include <iostream>

using namespace std;

/*
*   1. Ask a user for a rule set number from 0 to 255. If a value outside that range is input, 
        an explanatory message should be output and the program ended (returning from main with a 0). 
        You can assume that the input is a number.
*   2. The rule set number should be converted into a binary number and stored in a rule set array. 
        This array specifies what new value should be produced given a value and its neighbors. 
        The conversion is just turning the rule set integer number into a binary number. 
*   3. A starting generation array of length 64 should be made of all 0 except a single 1 at index 32. 
        This array should be displayed.
*   4. Then, 49 new generations should be computed and displayed using the rule set array to compute 
        each new generation. This makes a total of 50 rows of output.
*/

void displayGeneration(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0)
            cout << "#";
        else
            cout << " ";
    }
    cout << endl;
}

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


int convertNeighborhoodToIndex(int left, int current, int right) {
    int result = 0;
    result += left * 4;
    result += current * 2;
    result += right * 1;

    return result;
}

void computeNextGeneration(int currentGen[], int nextGen[], int curSize, int nextSize) {
    //Copy the first and Last element of the array from the current generation to the next generation



    //For the remaining elements in the current generation array, look at the value to the left of the current location, 
    //the value at the current location, and the value to the right of the current location. This forms a 3 digit binary number. 
    //Convert that number to base 10 and use it to index into the rule set array. Use that value to set the element in the next generation array.
}


int main() {
    //Ask a user for a rule set number from 0 to 255
    int ruleSet;
    int generations = 50;
    int generationSize = 64;
    int ruleSetArrSize = 8;
    cout << "Enter a rule set number from 0-255: ";
    cin >> ruleSet;

    //If a value outside that range is input, an explanatory message should be output and the program ended 
    if(ruleSet < 0 || ruleSet > 255) {
        cout << "Number entered was invalid or outside of bounds (0-255)" << endl;
        return 0;
    }

    cout << "Rule Set Number: " << ruleSet << endl;

    //Save the ruleSet in a rule set array as a binary number
    int ruleSetArr[8];
    convertRuleSetNumberToRuleSetArray(ruleSet, ruleSetArr);
    
    cout << "Binary Rule Set" << endl;
    cout << "[";
    for(int i = 0; i < ruleSetArrSize - 1; i++) {
        cout << ruleSetArr[i] << ",";
    }
    cout << ruleSetArr[ruleSetArrSize - 1] << "]" << endl;

    int curGen[generationSize];
    for(int i = 0; i < generationSize; i++) {
        curGen[i] = 0;
        if(i == 32)
            curGen [i] = 1;
    }

    displayGeneration(curGen, generationSize);




    return 0;
}

