//
// Created by kristof on 12/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gif.h"
#include "image.h"

#define MAX_PATH_SIZE 256

int main(void) {
    printf("Input a path to a color image file: ");
    char image_path[MAX_PATH_SIZE];
    fgets(image_path, MAX_PATH_SIZE, stdin);
    image_path[strcspn(image_path, "\n")] = '\0';

    if (strlen(image_path) == 0) {
        fprintf(stderr, "No path provided\n");
        return 1;
    }

    const Image image = create_image_from_file(image_path);
    print_image(&image);
    free_image(&image);

    printf("\n\n\nInput a path to a gif image file: ");
    char gif_path[MAX_PATH_SIZE];
    fgets(gif_path, MAX_PATH_SIZE, stdin);
    gif_path[strcspn(gif_path, "\n")] = '\0';

    if (strlen(gif_path) == 0) {
        fprintf(stderr, "No path provided\n");
        return 1;
    }

    const Gif gif = create_gif_from_file(gif_path);
    print_gif(&gif);
    free_gif(&gif);

    return 0;
}
