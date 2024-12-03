//
// Created by kristof on 12/2/24.
//

#include "gif.h"

#include <stdio.h>

#define SLEEP_MS 1000

#ifdef __linux__
#include <unistd.h>
#define sleep() sleep(SLEEP_MS / 1000)
#endif

#ifdef _WIN32
#include <windows.h>
#define sleep() Sleep(SLEEP_MS)
#endif

#ifdef __APPLE__
#include <unistd.h>
#define sleep() usleep(SLEEP_MS * 1000)
#endif

Gif create_gif_from_file(const char *filename) {
    Gif gif;
    for (int i = 0; i < GIF_IMAGES; ++i) {
        char current_filename[256];
        sprintf(current_filename, "%s%d", filename, i);
        gif.images[i] = create_image_from_file(current_filename);
    }
    return gif;
}

void print_gif(const Gif *gif) {
    for (int i = 0; i < GIF_IMAGES; ++i) {
        printf("%s%s", TERMINAL_CLEAR, TERMINAL_HOME);
        print_image(&gif->images[i]);
        printf("\n");
        sleep();
    }
}

void free_gif(const Gif *gif) {
    for (int i = 0; i < GIF_IMAGES; ++i) {
        free_image(&gif->images[i]);
    }
}
