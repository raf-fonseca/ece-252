#include <stdio.h>
#include "lab_png.h"

// input: ./pnginfo WEEF 1.png 
// output: WEEF_1.png: 450 x 229

// is_png takes eight bytes and check whether they match the PNG image file signature

int main(int argc, char *argv[]) 
{
    if (argc != 2) return -1;
    // take argv[1]
    // open that file, if can't be opened, stop 
    // read first 8 bytes
    FILE* f = fopen (argv[1], "rb");
    if (f == NULL) {
        printf("Unable to open file!%s_ is invalid_name?\n", argv[1] );
        return -1;
    }

    U8 buffer[PNG_SIG_SIZE];
    size_t n = fread(buffer, 1, PNG_SIG_SIZE, f);

    int isPng = is_png(buffer, n);

    if (!isPng) {
        printf("%s: Not a PNG file", argv[1]);
    }
    // if (isPng) {
    //     printf("%s: ", argv[1])
    // }

    
    
}