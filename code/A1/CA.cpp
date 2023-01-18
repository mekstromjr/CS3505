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








int main() {
    //Ask a user for a rule set number from 0 to 255
    int ruleSet;
    cout << "Enter a rule set number from 0-255: ";
    cin >> ruleSet;

    //If a value outside that range is input, an explanatory message should be output and the program ended 
    if(ruleSet < 0 || ruleSet > 255) {
        cout << "Number entered was invalid or outside of bounds (0-255)" << endl;
        return 0;
    }

    cout << "Rule Set Number: " << ruleSet << endl;

    //Save the ruleSet in a rule set array as a binary number
    int ruleArr[8];
    for(int i = 7; i >= 0; i--) {
        int factor = 1;
        for (int j = i; j > 0; j--) 
            factor *= 2;

        if(ruleSet >= factor) 
            ruleArr[7-i] = 1;
        else 
            ruleArr[7-i] = 0;

        if(ruleSet >= factor)
            ruleSet -= factor;
    }

    cout << "Binary Rule Set" << endl;
    for(int i = 0; i < 8; i++) {
        cout << "[" << ruleArr[i] << "] ";
    }
    cout << endl;

    return 0;
}

