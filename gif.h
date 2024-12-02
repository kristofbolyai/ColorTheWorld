//
// Created by kristof on 12/2/24.
//

#ifndef GIF_H
#define GIF_H

#define TERMINAL_CLEAR "\033[2J"
#define TERMINAL_HOME "\033[2H"

#define GIF_IMAGES 10

#include "image.h"

typedef struct {
    Image images[GIF_IMAGES];
} Gif;

Gif create_gif_from_file(const char *);

void print_gif(const Gif *);

void free_gif(const Gif *);

#endif //GIF_H
