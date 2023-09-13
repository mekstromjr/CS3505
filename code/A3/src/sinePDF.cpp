/* 
*  Michael Ekstrom 
*  CS3505 
*  A3: Facades and Makefiles
*/
#include <iostream> //Remove after testing
//See if any of these includes are unecessary and remove them
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HaruPDF.h"
#include "Sine.h"


const char FILENAME[256] = "sinePDF.pdf";
const int X_WAVE_OFFSET = 0;
const int Y_WAVE_OFFSET = 310;
const int AMPLITUDE = 30;
const int WAVELENGTH = 200;
const int INCREMENT = 20;

/// @brief Entry Point for sinePDF
/// @param argc Should always be 1 arguemnts
///             argv[1] The text of the spiral surrounded by quotes. "Example Text"
/// @param argv Contains the Argument(s)
/// @return 0 if run successfully
int main (int argc, char **argv) {
    if(argc < 2) {
        std::cout << "No sample text is provided. Quitting." << std::endl;
        return 0;
    }

    char waveText[1000] {};
    strcpy (waveText, argv[1]);

    HaruPDF pdf{};
    Sine sineWave(AMPLITUDE, WAVELENGTH, INCREMENT);

    pdf.beginText();

    for(unsigned int i = 0; i < strlen(waveText); i++) {
        pdf.addCharacter(waveText[i], sineWave.currentAngle() + X_WAVE_OFFSET, sineWave.currentHeight() + Y_WAVE_OFFSET, 0);
        sineWave++;
    }

    pdf.endText();
    pdf.saveToFile(FILENAME);
    pdf.freePDF();
    
    return 0;
}