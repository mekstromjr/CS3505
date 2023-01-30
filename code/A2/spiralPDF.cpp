 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2:Spiral
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "HaruPDF.h"
#include "Spiral.h"

using namespace std;

/// @brief Entry Point for Spiral
/// @param argc Should be 2 arguemnts
///             1) Filename (will just be the executable name)
///             2) The text of the spiral surrounded by quotes. "Example Text"
/// @param argv Contains the Arguments
/// @return 0 if run successfully
int main(int argc, char **argv) {

    const int centerX = 200;
    const int centerY = 310;
    const float scaleFactor = 1; //How quickly the spiral grows - Values between 0.1 and 0.2 work best
    const float startingAngle = 90; //In degrees

    HaruPDF pdf;
    Spiral spiral(centerX, centerY, startingAngle, scaleFactor);
    cout << spiral.getSpiralX() << endl;
    char filename[256];
    char spiralText[1000];

    strcpy (filename, argv[0]);
    strcat (filename, ".pdf");

    strcpy (spiralText, argv[1]);

    pdf.beginText();

    // Place characters one at a time on the page.
    for (unsigned int i = 0; i < strlen (spiralText); i++) {
        pdf.addCharacter(spiralText[i], spiral.getSpiralX(), spiral.getSpiralY(), 
            360-spiral.getSpiralAngle()/*Convert Spiral Angle to normal Angle*/);

        //Change spiral angle, inversly proportional to the radius length.
        float radiusLength = sqrt(pow(spiral.getSpiralX()-centerX,2)+pow(spiral.getSpiralY()-centerY,2));
        spiral += 1000/radiusLength; 
    }

    pdf.endText();
    pdf.saveToFile(filename);
    pdf.freePDF();

    return 0;
}