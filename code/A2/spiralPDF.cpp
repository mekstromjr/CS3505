 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2:Spiral
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
// #include "Spiral.h"

int main(int argc, char **argv) {

    const char* SAMP_TXT = "The quick brown fox jumps over the lazy dog. We need more text to test a spiral. Maybe the radians needs to increase with smaller radius. ";
    const int centerX = 210;
    const int centerY = 300;
    const float pi = 3.141592;


    HaruPDF pdf;
    char fname[256];
    float angle2;
    float rad1;
    float rad2;    
    unsigned int i;

    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    angle2 = 180;

    pdf.beginText();

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (SAMP_TXT); i++) {
        float x;
        float y;

        //Converts degrees to radians
        rad1 = (angle2 - 90) / 180 * pi; 
        rad2 = angle2 / 180 * pi;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = centerX + cos(rad2) * 150 /*distance from center, radius*/;
        y = centerY + sin(rad2) * 150;

        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix. 
        pdf.setTextMatrix(cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);

        pdf.addCharacter(SAMP_TXT[i]);

        angle2 -= 10.0; // change the angle around the circle
    }

    pdf.endText();
    pdf.saveToFile(fname);

    return 0;
}