
#pragma once

#include "Surface.h"

#include "Colors.h"
#include "PhysicContainers.h"
#include "Rect.h"

#include <cassert>
#include <string>
#include <vector>

class Font
{
public:
	enum class Type
	{
		Consolas,
		count
	};
	Font() = delete;
	Font(Font::Type type, Dimensions2D<int> size, Color chroma = Colors::Magenta );
	~Font() = default;
private:
	void setType(Font::Type type);
	void fillFontChars(const Surface & fontSheet);
	Coordinates2D<int> mapSheetCharCord( char c ) const;

public:
	Surface createTextSurf(const std::string & text, const Dimensions2D<int> & textSurfSize, Color chroma = Colors::Magenta);
	void draw(Graphics &gfx, char c);

private:
	std::vector<Surface> charSurfs;

	Dimensions2D<int> grid = Dimensions2D<int> (32,3);
	Dimensions2D<int> size;

	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
	static constexpr int numChar = lastChar - firstChar;
	static constexpr char charArr[] = {' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
	 '@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
	 '`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~'};
};