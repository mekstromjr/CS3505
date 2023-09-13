/**
* Michael Ekstrom 
* CS3505 
* A3: Facades and Makefiles
*/
#include <string.h>
#include "HaruPDF.h"
#include "Sine.h"

/// @brief Entry Point for sinePDF
/// @param argc Should always be 2 arguements
///     If there are less 2 arguments program exits because no wave text was provided.
/// @param argv Contains the Argument(s)
///     argv[0] Contains the text used to call main.
///     argv[1] Contains the text of the wave surrounded by quotes. There should be less than 1000 characters. "Example Text." 
/// @return 0 if run successfully.
int main (int argc, char **argv) {
    if(argc < 2) {
        std::cout << "No sample text is provided, Quitting." << std::endl;
        return 0;
    }

    const char* filename = "sinePDF.pdf";

    //Wave parameters
    const int xOffset = 5;
    const int yOffset = 310;
    const int amplitude = 30;
    const int wavelength = 200;
    const int increment = 8;


    char waveText[1000] {};
    strcpy (waveText, argv[1]);

    HaruPDF pdf{ };
    Sine sineWave(amplitude, wavelength, increment);

    for(unsigned int i = 0; i < strlen(waveText); i++) {
        pdf.addCharacter(waveText[i], sineWave.currentAngle() + xOffset, sineWave.currentHeight() + yOffset, 0);
        sineWave++;
    }

    pdf.saveToFile(filename);
    
    return 0;
}