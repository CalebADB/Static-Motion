
#include "Font.h"

using namespace std;

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
		charSurfs[idx].blit(fontSheet,mapSheetCharCord(charArr[idx]),Rect(Coordinates2D<int>(),size));
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

Surface Font::createTextSurf(const string & text, const Dimensions2D<int> & textSurfSize, Color chroma)
{
	vector<string> words;

	int idx = 0;
	string newWord;
	do {
		while (text[idx] != ' ' &&
			idx < text.length())
		{
			newWord.push_back(text[idx]);
			idx++;
		}
		words.emplace_back(newWord);
		newWord.clear();
		idx++;
	}
	while (idx < text.length());

	vector<string> lines;
	
	string newLine;
	int numCol = textSurfSize.width  / size.width;
	int numRow = textSurfSize.height / size.height;
	int lineLength = 0;
	for (int idx = 0; idx < words.size(); idx++)
	{
		lineLength += words[idx].size();
		if (lineLength < numCol)
		{
			newLine.append(words[idx]);
			lineLength += 1;
			newLine.push_back(' ');
		}
		else
		{
			newLine.pop_back();
			lines.emplace_back(newLine);
			newLine.clear();

			if (lines.size() > numRow)
			{
				assert(false);
			}

			newLine.append(words[idx]);
			newLine.push_back(' ');
			lineLength = words[idx].size();
		}
	}
	lines.emplace_back(newLine);

	Surface textSurf(textSurfSize);

	Coordinates2D<int> charDestination;
	charDestination.y = 0;
	for (int lineI = 0; lineI < lines.size(); lineI++)
	{
		string line = lines[lineI];
		charDestination.x = 0;
		for (int charI = 0; charI < line.size(); charI++)
		{
			textSurf.blit(charSurfs[line[charI] - firstChar],Coordinates2D<int>(0,0),Rect(charDestination, size));
			charDestination.x += size.width;
		}
		charDestination.y += size.height;
	}
 	return textSurf;
}

void Font::draw(Graphics & gfx, char c)
{
	Coordinates2D<int> cord;
	for (cord.y = 0; cord.y < size.height; cord.y++)
	{
		for (cord.x = 0; cord.x < size.width; cord.x++)
		{
			gfx.PutPixel(cord.x,cord.y,charSurfs[c - firstChar].getPxl(cord));
		}
	}
}
