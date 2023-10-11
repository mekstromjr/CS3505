
#include "ThreeTuple.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


int main() {
    vector<ThreeTuple> dataInput { };

    for(int i = 0; i < 10; i++) {
        dataInput.push_back(ThreeTuple(i,i + 1,1));
    }

    cout << "fromStart\tfromEnd\tavgSpd" << endl;
    double totalRouteTime(0);
    for(ThreeTuple roadSegment : dataInput) {
        cout << roadSegment.distanceAtStart << "\t" << roadSegment.distanceAtEnd << "\t" << roadSegment.avgSpeed << endl;
        double segmentLength = (double)roadSegment.distanceAtEnd - (double)roadSegment.distanceAtStart;
        double segmentTime = (double)segmentLength / (double)roadSegment.avgSpeed;
        totalRouteTime += segmentTime;
    }

    cout << "Total Route Time: " << totalRouteTime << " hours"<<endl;

    return 0;
}