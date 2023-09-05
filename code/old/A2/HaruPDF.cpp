 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2: Spiral
 */
#include "HaruPDF.h"
#include <math.h>

HaruPDF::HaruPDF() {
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    font = HPDF_GetFont (pdf, fontName, NULL);; 
}

void HaruPDF::beginText() {
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextLeading (page, textLeading);
    HPDF_Page_SetGrayStroke (page, grayStroke);
    HPDF_Page_SetFontAndSize (page, font, textSize);
}


void HaruPDF::addCharacter(const char& text, float x, float y, float rotation) {
    rotation = rotation / 180 * 3.141592; //Converts rotation from degrees to radians
    HPDF_Page_SetTextMatrix(page, cos(rotation), sin(rotation), -sin(rotation), cos(rotation), x, y);

    char buf[2];
    buf[0] = text; // The character to display
    buf[1] = 0; 
    HPDF_Page_ShowText (page, buf);
}

void HaruPDF::endText() {
    HPDF_Page_EndText (page);
}


void HaruPDF::saveToFile(const char *fname) {
    HPDF_SaveToFile (pdf, fname);
}

void HaruPDF::freePDF() {
    HPDF_Free(pdf);
}
