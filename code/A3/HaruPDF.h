/**
* Michael Ekstrom 
* CS3505 
* A3: Facades and Makefiles
*/
#ifndef HaruPDF_H
#define HaruPDF_H
#include "hpdf.h"

class HaruPDF {
    private:
        const int textSize = 12;
        const int grayStroke = 0;
        const int textLeading = 20;
        const char* fontName = "Courier-Bold";
        HPDF_Doc  pdf;
        HPDF_Page page;
        HPDF_Font font;
        bool isWriting;

    public:
        /// @brief Constructor
        HaruPDF();

        /// @brief Destructor
        ~HaruPDF();

        /// @brief Adds a character to the document
        /// @param text - Character to be added
        /// @param x - the x position of the character
        /// @param y - the y position of the character
        /// @param rotation - the character's rotation in degrees
        void addCharacter(const char& text, float x, float y, float rotation);

        /// @brief Saves the text written to a pdf file
        /// @param filename - the name of the output file
        void saveToFile(const char *filename);

};

#endif