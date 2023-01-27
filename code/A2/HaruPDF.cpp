 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2: Spiral
 */
#include "HaruPDF.h"

HaruPDF::HaruPDF() {
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = NULL;
 
}

void HaruPDF::setTextMatrix(float cosRad1, float sinRad1, float sinNegRad1, float cosRad1b, float x, float y) {
     HPDF_Page_SetTextMatrix(page, cosRad1, sinRad1, sinNegRad1, cosRad1b, x, y);
}

void HaruPDF::beginText() {
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetFontAndSize (page, font, 30);
}


void HaruPDF::addCharacter(const char text) {
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
