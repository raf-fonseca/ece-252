#include "lab_png.h"

int is_png(U8 *buf, size_t n) {
    
    if (buf == NULL || n < PNG_SIG_SIZE) return 0;

    U8 sig[PNG_SIG_SIZE] = {
        0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A
    };

    // Compare each char in buf against sig
    for (int i = 0; i < PNG_SIG_SIZE; i++) {
        if (buf[i] != sig[i]) {
            return 0;
        }
    }
    return 1; 

}