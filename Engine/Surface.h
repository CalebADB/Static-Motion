
#pragma once

#include "Graphics.h"
#include "Colors.h"

#include "Rect.h"

#include "PhysicContainers.h"
#include <utility>

class Surface
{
public:
	Surface() = delete; // must have dimensions
	Surface(const std::string & filename);
	Surface(const Dimensions2D<int> dimension, const Color& bgColor);
	Surface(Surface&& source_surface);
	Surface(const Surface&) = default;
	Surface& operator=(Surface&& source_surface);
	Surface& operator=(const Surface&) = default;
	~Surface(); // not default

	void blit(const Surface& source_surface, const Rect & destination);
	void blit(const Surface& source_surface, const Rect & destination, Color Chroma = Colors::Magenta);

	void draw(Graphics & gfx) const; 
	// Setters FOR SETTING SHIT
	void setPxl(const Coordinates2D<int>& coordinate, const Color& pxlColor);

	//wheres ma spaGET (Getters)
	Color getPxl(const Coordinates2D<int>& coordinate) const;
	Dimensions2D<int> getDimensions() const;
private:
	Dimensions2D<int> dimension;
	int surfacePxlsSize;
	Color* surfacePxls = nullptr;
};

