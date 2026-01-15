#include <stdio.h>
#include "tinyraw.h"

int main(void)
{
    tinyraw_image* img = tinyraw_load(
        "image.raw",
        512,
        512,
        3,
        TINYRAW_U8
    );

    if (!img) {
        printf("Error loading RAW image\n");
        return 1;
    }

    unsigned char* pixels = (unsigned char*)img->data;

    printf("First pixel: R=%d G=%d B=%d\n",
           pixels[0],
           pixels[1],
           pixels[2]);

    tinyraw_free(img);
    return 0;
}
