
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
	Surface(const Dimensions2D<int> dimension, const Color& bgColor = Colors::Magenta);
	Surface(const Surface & source_surface);
	Surface& operator=(const Surface & source_surface);
	~Surface(); // not default

	void blit(const Surface& source_surface, const Coordinates2D<int> & source_location, const Rect & destination, Color Chroma = Colors::Magenta);
	void blitNoChroma(const Surface& source_surface, const Coordinates2D<int> & source_location, const Rect & destination);
	void blitSilhouette(const Surface& source_surface, const Coordinates2D<int> & source_location, const Rect & destination, Color Fg = Colors::Black, Color Chroma = Colors::Magenta);

	void draw(Graphics & gfx); 

	void saveToTxt();
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

