
#include "Surface.h"

#include <cassert>
#include <fstream>
#include <string>

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

	surfacePxlsSize = dimension.width * dimension.height;

	surfacePxls = new Color[surfacePxlsSize];

	const int padding = ((4 - (dimension.width * 3)) % 4) % 4;

	file.seekg(imageFileHeader.bfOffBits);

	Coordinates2D<int> coordinate(0,0);
	for (coordinate.y = dimension.height - 1; coordinate.y >= 0; coordinate.y--)
	{
		for (coordinate.x = 0; coordinate.x < dimension.width; coordinate.x++)
		{
			setPxl(coordinate, Color(file.get(),file.get(),file.get()));
			getPxl(coordinate);
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

Surface::Surface(const Surface & source_surface)
	:
	Surface(source_surface.dimension)
{
	for (int idx = 0; idx < dimension.getArea(); idx++)
	{
		surfacePxls[idx] = source_surface.surfacePxls[idx];
	}
}

Surface & Surface::operator=(const Surface & source_surface)
{
	dimension = source_surface.dimension;

	delete[] surfacePxls;
	surfacePxls = new Color[dimension.getArea()];

	for( int idx = 0; idx < dimension.getArea(); idx++ )
	{
		surfacePxls[idx] = source_surface.surfacePxls[idx];
	}
	return *this;
}

Surface::~Surface()
{
	delete[] surfacePxls;
	surfacePxls = nullptr;
}

void Surface::blit(const Surface & source_surface, const Coordinates2D<int> & source_location, const Rect & destination, Color Chroma)
{
	Dimensions2D<int> setDimensions = destination.getDimension();

	Coordinates2D<int> getPxlI;
	Coordinates2D<int> setPxlI;
	setPxlI.y = destination.getTop();
	for (getPxlI.y = source_location.y; getPxlI.y < setDimensions.height + source_location.y; getPxlI.y++)
	{
		setPxlI.x = destination.getLeft();
		for (getPxlI.x = source_location.x; getPxlI.x < setDimensions.width + source_location.x; getPxlI.x++)
		{
			Color BlitPxl = source_surface.getPxl(getPxlI);
			if (BlitPxl != Chroma)
			{
				setPxl(setPxlI, BlitPxl);
			}
			setPxlI.x++;
		}
		setPxlI.y++;
	}
}

void Surface::blitNoChroma(const Surface & source_surface, const Coordinates2D<int> & source_location, const Rect & destination)
{
	Dimensions2D<int> setDimensions = destination.getDimension();

	Coordinates2D<int> getPxlI;
	Coordinates2D<int> setPxlI;
	setPxlI.y = destination.getTop();
	for (getPxlI.y = source_location.y; getPxlI.y < setDimensions.height + source_location.y; getPxlI.y++)
	{
		setPxlI.x = destination.getLeft();
		for (getPxlI.x = source_location.x; getPxlI.x < setDimensions.width + source_location.x; getPxlI.x++)
		{
			setPxl(setPxlI, source_surface.getPxl(getPxlI));
			setPxlI.x++;
		}
		setPxlI.y++;
	}
}

void Surface::blitSilhouette(const Surface & source_surface, const Coordinates2D<int>& source_location, const Rect & destination, Color Fg, Color Chroma)
{
	Dimensions2D<int> setDimensions = destination.getDimension();

	Coordinates2D<int> getPxlI;
	Coordinates2D<int> setPxlI;
	setPxlI.y = destination.getTop();
	for (getPxlI.y = source_location.y; getPxlI.y < setDimensions.height + source_location.y; getPxlI.y++)
	{
		setPxlI.x = destination.getLeft();
		for (getPxlI.x = source_location.x; getPxlI.x < setDimensions.width + source_location.x; getPxlI.x++)
		{
			if (source_surface.getPxl(getPxlI) != Chroma)
			{
				setPxl(setPxlI, Fg);
			}
			setPxlI.x++;
		}
		setPxlI.y++;
	}
}

void Surface::draw(Graphics & gfx)
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

void Surface::saveToTxt()
{
	std::ofstream saveFileHndl(std::string("surfaceTxtFile.txt"));

	Coordinates2D<int> getPxlI(0,0);
	for (getPxlI.y = 0; getPxlI.y < dimension.height; getPxlI.y++)
	{
		for (getPxlI.x = 0; getPxlI.x < dimension.width; getPxlI.x++)
		{

			Color pxl = getPxl(getPxlI);
			if (pxl == Colors::Magenta)
			{
				saveFileHndl.put('0');
			}
			else if (pxl == Colors::Magenta)
			{
				saveFileHndl.put('1');
			}
		}
		saveFileHndl.put('\n');
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
			int pxlI = (coordinate.y * dimension.width) + coordinate.x;
			return surfacePxls[pxlI];
		}
	}
	return Colors::Magenta;
}

Dimensions2D<int> Surface::getDimensions() const
{
	return dimension;
}
