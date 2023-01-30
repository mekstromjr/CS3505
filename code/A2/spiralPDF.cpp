 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2:Spiral
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HaruPDF.h"
#include "Spiral.h"

/* 
* TODO: Fix spiral, currently counter-clockwise, needs to be clockwise
* TODO: Change degrees per character to be smaller, the larger the angle
*/


int main(int argc, char **argv) {

    const int centerX = 210;
    const int centerY = 300;
    const float scaleFactor = 0.2;
    const float startingAngle = 75;

    HaruPDF pdf;
    Spiral spiral(centerX, centerY, startingAngle, scaleFactor);
    char fname[256];
    char spiralText[1000];
    unsigned int i;

    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    strcpy (spiralText, argv[1]);

    pdf.beginText();

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (spiralText); i++) {
        pdf.addCharacter(spiralText[i], spiral.getSpiralX(), spiral.getSpiralY(), 360-spiral.getSpiralAngle()/*Convert Spiral Angle to normal Angle*/);

        float radiusLength = sqrt(pow(spiral.getSpiralX()-centerX,2)+pow(spiral.getSpiralY()-centerY,2));
        spiral += 1000/radiusLength; //Change spiral angle, inversly proportional to the radius length.
    }

    pdf.endText();
    pdf.saveToFile(fname);

    return 0;
}