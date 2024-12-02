//
// Created by kristof on 12/2/24.
//

#ifndef IMAGE_H
#define IMAGE_H

// Maximum size of the image (width and height)
#define MAX_SIZE 30
#include "color.h"

typedef struct {
    int width;
    int height;
    Color **data;
} Image;

Image create_image_from_file(const char *);

void print_image(const Image *);

void free_image(const Image *);

#endif //IMAGE_H
