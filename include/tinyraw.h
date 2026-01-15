#ifndef TINYRAW_H
#define TINYRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/* Tipos soportados */
typedef enum {
    TINYRAW_U8  = 8,
    TINYRAW_U16 = 16
} tinyraw_bitdepth;

/* Estructura de imagen */
typedef struct {
    int width;
    int height;
    int channels;          /* 1 = gris, 3 = RGB */
    tinyraw_bitdepth bits;
    void* data;            /* buffer de píxeles */
} tinyraw_image;

/* Cargar imagen RAW desde archivo */
tinyraw_image* tinyraw_load(
    const char* filename,
    int width,
    int height,
    int channels,
    tinyraw_bitdepth bits
);

/* Liberar imagen */
void tinyraw_free(tinyraw_image* img);

#ifdef __cplusplus
}
#endif

#endif /* TINYRAW_H */
