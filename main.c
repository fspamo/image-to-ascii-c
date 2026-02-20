#define STB_IMAGE_IMPLEMENTATION
#include "std_image.h"
#include <stdio.h>

// int calc_resolution(int image_res, int desired_res)
// {
	
// }

int main(int argc, char *argv[])
{
	int width;
	int height;
	int channels;

	int brightness;

	// unsigned char	*scale;
	unsigned char	*img;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	unsigned char scale[256] = 

	{'$', '@', 'B', '%', '8', '&', 'W', 'M', '#', '*', 'o', 'a', 'h', 'k', 'b', 'd',
		'p', 'q', 'w', 'm', 'Z', 'O', '0', 'Q', 'L', 'C', 'J', 'U', 'Y', 'X', 'z', 'c',
		'v', 'u', 'n', 'x', 'r', 'j', 'f', 't', '/', '\\', '|', '(', ')', '1', '{', '}',
		'[', ']', '?', '-', '_', '+', '~', '<', '>', 'i', '!', 'l', 'I', ';', ':', ',',
		'"', '^', '`', '\'', '.', ' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};
	if (argc == 1)
		return 0;

	img = stbi_load(argv[1], &width, &height, &channels, 0);

	if (img == NULL) {
		printf("img fail\n");
		return 1;
	}

	for (int y = 0; y < height; y+=2) {
		for (int x = 0; x < width; x++) {
			int index = (y * width + x) * channels;
			r = img[index];
			g = img[index + 1];
			b = img[index + 2];
			unsigned char a = (channels == 4) ? img[index + 3] : 255;
			brightness = 0.299f * r + 0.587f * g + 0.114f * b;

			if (x == 0)
				printf("\n");
			// printf("Pixel at (%d,%d): brightness = %.2f\n", x, y, brightness);
			if (argv[2][0] == 'w')
			{
				printf("%c", scale[brightness]);

			}
			else if (argv[2][0] == 'c')
			{
				printf("\033[38;2;%d;%d;%dm%c\033[0m", r, g, b, '@');
			}
		}
	}

	stbi_image_free(img);

	return 0;
}
