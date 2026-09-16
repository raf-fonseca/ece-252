#include "lab_png.h"
#include <arpa/inet.h>        

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

// extract from file the data field of the IHDR chunk, to populate a struct data_IHDR
int get_png_data_IHDR(struct data_IHDR *out, FILE *fp, long offset, int whence) {
    if (fp == NULL || out == NULL) {
        return -1; 
    }
    int seek = fseek(fp, offset, whence); // returns 0 if it successfully moves the file 
    if (seek != 0) return -1; 

    size_t items_read = fread(out, DATA_IHDR_SIZE, 1, fp);
    if (items_read != 1) return -1;

    return 0;
}

int get_png_width(struct data_IHDR *buf)                                                                                                                  
{                                                                                                                                                         
    return ntohl(buf->width);                                                                                                                             
}                                                                                                                                                         
                                                                                                                                                          
int get_png_height(struct data_IHDR *buf)                                                                                                                 
{                                                                                                                                                         
    return ntohl(buf->height);                                                                                                                            
}     