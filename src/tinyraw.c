#include "tinyraw.h"
#include <stdio.h>
#include <stdlib.h>

static size_t bytes_per_pixel(int channels, tinyraw_bitdepth bits)
{
    return channels * (bits / 8);
}

tinyraw_image* tinyraw_load(
    const char* filename,
    int width,
    int height,
    int channels,
    tinyraw_bitdepth bits)
{
    if (!filename || width <= 0 || height <= 0)
        return NULL;

    if (channels != 1 && channels != 3)
        return NULL;

    FILE* f = fopen(filename, "rb");
    if (!f)
        return NULL;

    size_t pixel_size = bytes_per_pixel(channels, bits);
    size_t total_size = (size_t)width * height * pixel_size;

    void* buffer = malloc(total_size);
    if (!buffer) {
        fclose(f);
        return NULL;
    }

    size_t read = fread(buffer, 1, total_size, f);
    fclose(f);

    if (read != total_size) {
        free(buffer);
        return NULL;
    }

    tinyraw_image* img = (tinyraw_image*)malloc(sizeof(tinyraw_image));
    if (!img) {
        free(buffer);
        return NULL;
    }

    img->width    = width;
    img->height   = height;
    img->channels = channels;
    img->bits     = bits;
    img->data     = buffer;

    return img;
}

void tinyraw_free(tinyraw_image* img)
{
    if (!img)
        return;

    free(img->data);
    free(img);
}
