#include <iostream>

using namespace std;

int convertNeighborhoodToIndex(int left, int current, int right) {
    int result = 0;
    result += left * 4;
    result += current * 2;
    result += right * 1;
    
    return result;
}


int main() {
    int result = convertNeighborhoodToIndex(1,0,0);
    cout << result << endl;

    return 0;
}