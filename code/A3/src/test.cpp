#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    char filename[256] {};

    strcpy(filename, "sinePDF.pdf");

    for(int i = 0; i < 256 && filename[i] != NULL; i++) {
        cout << filename[i];
    }

    cout << endl;

}