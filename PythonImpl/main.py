from enum import Enum
from time import sleep


class Color(Enum):
    BG_BLACK = (0, "\033[40m")
    BG_RED = (1, "\033[41m")
    BG_GREEN = (2, "\033[42m")
    BG_YELLOW = (3, "\033[43m")
    BG_BLUE = (4, "\033[44m")
    BG_MAGENTA = (5, "\033[45m")
    BG_CYAN = (6, "\033[46m")
    BG_WHITE = (7, "\033[47m")
    RESET = (8, "\033[0m")

    @classmethod
    def from_value(cls, value: int):
        for color in cls:
            if color.value[0] == value:
                return color
        return cls.RESET

    def print_color(self):
        print(self.value[1] + " " + Color.RESET.value[1], end="")


class Image:
    def __init__(self, width: int, height: int, pixels: list[list[Color]]):
        self.width = width
        self.height = height
        self.pixels = pixels

    @staticmethod
    def read_from_file(path: str):
        with open(path, "r") as file:
            width = int(file.readline())
            height = int(file.readline())
            pixels = []
            for i in range(height):
                row = list(map(int, file.readline().split()))
                pixels.append([Color.from_value(row[j]) for j in range(width)])
            return Image(width, height, pixels)

    def image_print(self):
        for i in range(self.height):
            for j in range(self.width):
                self.pixels[i][j].print_color()
            print("")


class Gif:
    GIF_IMAGE_COUNT = 10

    def __init__(self, width: int, height: int, images: list[Image]):
        self.width = width
        self.height = height
        self.images = images

    @staticmethod
    def read_from_file(path: str):
        images = []
        for i in range(Gif.GIF_IMAGE_COUNT):
            image_path = path + str(i)
            images.append(Image.read_from_file(image_path))
        return Gif(images[0].width, images[0].height, images)

    def gif_print(self):
        for image in self.images:
            clear_terminal()
            image.image_print()
            sleep(0.5)


def clear_terminal():
    print("\033[H\033[J")


def main():
    image_path = input("Enter the path of the image: ")
    image = Image.read_from_file(image_path)
    image.image_print()

    gif_path = input("Enter the path of the gif: ")
    gif = Gif.read_from_file(gif_path)
    gif.gif_print()


if __name__ == '__main__':
    main()
