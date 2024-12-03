//
// Created by kristof on 12/2/24.
//

#include "image.h"

#include <stdio.h>
#include <stdlib.h>

#include "color.h"

Image create_image_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    int width, height;
    fscanf(file, "%d\n%d", &width, &height);

    if (width > MAX_SIZE || height > MAX_SIZE) {
        fprintf(stderr, "Width or height is too large. Maximum size is %d\n", MAX_SIZE);
        exit(1);
    }

    Color **data = malloc(height * sizeof(Color *));
    if (!data) {
        fprintf(stderr, "Could not allocate memory for image data\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        data[i] = (Color *) malloc(width * sizeof(Color));
        if (!data[i]) {
            fprintf(stderr, "Could not allocate memory for image data\n");
            exit(1);
        }

        for (int j = 0; j < width; j++) {
            int color_int;
            fscanf(file, "%d", &color_int);
            data[i][j] = (Color) color_int;
        }
    }

    fclose(file);

    return (Image){width, height, data};
}

void print_image(const Image *image) {
    for (int i = 0; i < image->height; i++) {
        const Color *colors = image->data[i];
        color_print(colors, image->width);
        printf("\n");
    }
}

void free_image(const Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
}
