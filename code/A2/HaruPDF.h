 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2: Spiral
 */
#ifndef HaruPDF_H
#define HaruPDF_H
#include "../libharu/include/hpdf.h"

class HaruPDF {
    private:
    //Member Variables:
        HPDF_Doc  pdf;
        HPDF_Page page;
        HPDF_Font font;

    public:
        HaruPDF(); //Constructor
        // ~HaruPDF(); //"Clean up" - HPDF_Free (pdf);
        void setFont(const char *fontName);
        void setTextMatrix(float cosRad1, float sinRad1, float sinNegRad1, float cosRad1b, float x, float y);
        void beginText();
        void addCharacter(const char text);
        void endText();
        void saveToFile(const char *fname);
        void freePDF();

};

#endif