# tinyraw

**tinyraw** is a tiny, fast and dependency-free C library for loading
simple RAW image files.

## Features

- Pure C (C89 compatible)
- No external dependencies
- Supports:
  - 8-bit and 16-bit RAW
  - Grayscale (1 channel)
  - RGB (3 channels)
- Single header + source
- Ideal for learning, engines and embedded systems

## Usage

```c
#include "tinyraw.h"

tinyraw_image* img = tinyraw_load(
    "image.raw",
    1024,
    768,
    3,
    TINYRAW_U8
);
test yolo
