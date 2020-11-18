#include <iostream>
#include <stdint.h>

#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define uint64 uint64_t

#define int8 int8_t
#define int16 int16_t
#define int32 int32_t
#define int64 int64_t


#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
	int width = 128;
	int height = 128;
	int comp = 4;

	uint8* data = new uint8[width * height * comp];
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = (x + width * y) * comp;
			data[index + 0] = 0;
			data[index + 1] = 0;
			data[index + 2] = 0;
			data[index + 3] = 255;
		}
	}

	stbi_write_png("Images/test1.png", width, height, comp, data, width * comp);
	delete[] data;

	return 0;
}