
#include "Surface.h"

#include <cassert>
#include <fstream>

Surface::Surface(const std::string & filename)
{
	// open file
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	// create a file header, i think this is an advanced handle
	BITMAPFILEHEADER imageFileHeader;
	file.read(reinterpret_cast<char*>(&imageFileHeader), sizeof(imageFileHeader));

	// this gets all the bits and peices of data at the start of the bmp
	BITMAPINFOHEADER imageInfoHeader;
	file.read(reinterpret_cast<char*>(&imageInfoHeader), sizeof(imageInfoHeader));

//	assert(imageInfoHeader.biCompression == 3);
//	assert(imageInfoHeader.biBitCount == 24);

	int bitCount = imageInfoHeader.biBitCount;
	dimension.width = imageInfoHeader.biWidth;
	dimension.height = imageInfoHeader.biHeight;

	int surfacePxlsSize = dimension.width * dimension.height;

	surfacePxls = new Color[surfacePxlsSize];

	const int padding = ((4 - (dimension.width * 3)) % 4) % 4;

	file.seekg(imageFileHeader.bfOffBits);

	Coordinates2D<int> coordinate(0,0);
	int red = 0;
	for (coordinate.y = dimension.height - 1; coordinate.y >= 0; coordinate.y--)
	{
		red += 1; 
		for (coordinate.x = 0; coordinate.x < dimension.width; coordinate.x++)
		{
			red += 1;
			setPxl(coordinate, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}

}

Surface::Surface(const Dimensions2D<int> dimension, const Color & bgColor)
	:
	dimension(dimension)
{
	surfacePxls = new Color[dimension.getArea()];

	Coordinates2D<int> coordinate;

	for (coordinate.y = 0; coordinate.y < dimension.height; coordinate.y++)
	{
		for (coordinate.x = 0; coordinate.x < dimension.width; coordinate.x++)
		{
			setPxl(coordinate, bgColor);
		}
	}
}

Surface::Surface(Surface && source_surface)
	:
	dimension(source_surface.dimension),
	surfacePxlsSize(source_surface.surfacePxlsSize)
{
	for (int idx = 0; idx < surfacePxlsSize; idx++)
	{
		surfacePxls[idx] = source_surface.surfacePxls[idx];
	}
}

Surface & Surface::operator=(Surface && source_surface)
{
	dimension = source_surface.dimension;
	surfacePxlsSize = source_surface.surfacePxlsSize;
	surfacePxls = std::move(source_surface.surfacePxls);
	return *this;
}

Surface::~Surface()
{
	delete[] surfacePxls;
	surfacePxls = nullptr;
}

void Surface::blit(const Surface & source_surface, const Rect & destination)
{
	Coordinates2D<int> setPxlI = destination.getTopLeft();
	Dimensions2D<int> setDimensions = destination.getDimension();
	
	Coordinates2D<int> getPxlI;
	for (getPxlI.y = 0; getPxlI.y < setDimensions.height; getPxlI.y++)
	{
		setPxlI.y++;
		for (getPxlI.x = 0; getPxlI.x < setDimensions.width; getPxlI.x++)
		{
			setPxlI.x++;
			setPxl(setPxlI, source_surface.getPxl(getPxlI));
		}
	}
}

void Surface::blit(const Surface & source_surface, const Rect & destination, Color Chroma)
{
	Coordinates2D<int> setPxlI = destination.getTopLeft();
	Dimensions2D<int> setDimensions = destination.getDimension();

	Coordinates2D<int> getPxlI;
	for (getPxlI.y = 0; getPxlI.y < setDimensions.height; getPxlI.y++)
	{
		setPxlI.y++;
		for (getPxlI.x = 0; getPxlI.x < setDimensions.width; getPxlI.x++)
		{
			setPxlI.x++;
			Color BlitPxl = source_surface.getPxl(getPxlI);
			if (BlitPxl == Chroma)
			{
				setPxl(setPxlI, BlitPxl);
			}
		}
	}
}

void Surface::draw(Graphics & gfx) const
{
	Coordinates2D<int> cordI;
	for (cordI.y = 0;  cordI.y < dimension.height;  cordI.y++)
	{
		for (cordI.x = 0; cordI.x < dimension.width; cordI.x++)
		{
			gfx.PutPixel(cordI.x, cordI.y, getPxl(cordI));
		}
	}
}

void Surface::setPxl(const Coordinates2D<int>& coordinate, const Color & pxlColor)
{
	if (0 <= coordinate.x && coordinate.x <= dimension.width)
	{
		if (0 <= coordinate.y && coordinate.y <= dimension.height)
		{
			surfacePxls[coordinate.x + (coordinate.y * dimension.width)] = pxlColor;
		}
	}
}

Color Surface::getPxl(const Coordinates2D<int>& coordinate) const
{
	if (0 <= coordinate.x && coordinate.x <= dimension.width)
	{
		if (0 <= coordinate.y && coordinate.y <= dimension.height)
		{
			return surfacePxls[coordinate.x + (coordinate.y * dimension.width)];
		}
	}
	return Colors::Magenta;
}

Dimensions2D<int> Surface::getDimensions() const
{
	return dimension;
}
