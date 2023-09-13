/** 
* Michael Ekstrom 
* CS3505 
* A3: Facades and Makefiles
*/
#include "HaruPDF.h"
#include <cmath>

HaruPDF::HaruPDF() {
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    font = HPDF_GetFont (pdf, fontName, NULL);; 
    isWriting = false;
}

HaruPDF::~HaruPDF() {
    HPDF_Free(pdf);
}

void HaruPDF::addCharacter(const char& text, float x, float y, float rotation) {
    if(!isWriting) {
        HPDF_Page_BeginText (page);
        HPDF_Page_SetTextLeading (page, textLeading);
        HPDF_Page_SetGrayStroke (page, grayStroke);
        HPDF_Page_SetFontAndSize (page, font, textSize);
        isWriting = true;
    }

    rotation = rotation / 180 * M_PI; //Converts rotation from degrees to radians
    HPDF_Page_SetTextMatrix(page, cos(rotation), sin(rotation), -sin(rotation), cos(rotation), x, y);

    char buf[2] {};
    buf[0] = text; 
    buf[1] = 0; //Character must be null terminated
    HPDF_Page_ShowText (page, buf);
}

void HaruPDF::saveToFile(const char *filename) {
    if(isWriting) {
        HPDF_Page_EndText (page);
        isWriting = false;
    }

    HPDF_SaveToFile (pdf, filename);
}