
#include "Font.h"

Font::Font(Font::Type type, Dimensions2D<int> size, Color chroma)
	:
	size(size)
{
	setType(type);
}

void Font::setType(Font::Type type)
{
	switch (type)
	{
	case Font::Type::Consolas:
		if (size.width == 13 &&
			size.height == 24)
		{
			Surface fontSheet = Surface(std::string("Consolas13x24.bmp"));
			fillFontChars(fontSheet);
		}
		break;
	}
}

void Font::fillFontChars(const Surface & fontSheet)
{
	Surface charSurf = Surface(size);
	charSurfs.resize(numChar, charSurf);
	for (int idx = 0; idx < numChar; idx++)
	{
		charSurfs[idx].blit(fontSheet,mapCharCord(charArr[idx]),Rect(Coordinates2D<int>(),size));
	}
}

Coordinates2D<int> Font::mapSheetCharCord( char c ) const
{
	assert( c >= firstChar && c <= lastChar );

	const int charI  = c - firstChar;

	const int xGlyph = charI % grid.width;
	const int yGlyph = charI / grid.width;

	return Coordinates2D<int> (xGlyph * size.width,yGlyph * size.height);
}

void Font::createTextSurf(std::string text, Rect textRect, Color chroma)
{
}
