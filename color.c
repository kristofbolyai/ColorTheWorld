//
// Created by kristof on 12/2/24.
//

#include "color.h"
#include <stdio.h>

char *color_to_string(const Color color) {
    switch (color) {
        case Reset:
            return RESET;
        case Bg_Black:
            return BG_BLACK;
        case Bg_Red:
            return BG_RED;
        case Bg_Green:
            return BG_GREEN;
        case Bg_Yellow:
            return BG_YELLOW;
        case Bg_Blue:
            return BG_BLUE;
        case Bg_Magenta:
            return BG_MAGENTA;
        case Bg_Cyan:
            return BG_CYAN;
        case Bg_White:
            return BG_WHITE;
        default:
            return RESET;
    }
}

void color_print(const Color *colors, const int length) {
    for (int i = 0; i < length; i++) {
        printf("%s ", color_to_string(colors[i]));
    }

    // Reset the color to default
    printf("%s", color_to_string(Reset));
}
