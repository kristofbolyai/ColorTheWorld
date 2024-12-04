//
// Created by kristof on 12/2/24.
//

#ifndef COLOR_H
#define COLOR_H

#define RESET "\033[0m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

typedef enum {
    Bg_Black,
    Bg_Red,
    Bg_Green,
    Bg_Yellow,
    Bg_Blue,
    Bg_Magenta,
    Bg_Cyan,
    Bg_White,
    Reset
} Color;

char *color_to_string(Color);

void color_print(const Color *, int);

#endif //COLOR_H
