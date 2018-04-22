
#pragma once

#include "Surface.h"
#include "Rect.h"
#include "PhysicContainers.h"

#include <vector>
#include <cassert>

class WidgetSurface : Surface
{
public:
	WidgetSurface() = delete;
	WidgetSurface(std::vector<Color> widgetColors, std::vector<Rect> widgetFrames, Dimensions2D<int> dimension);
	~WidgetSurface() = default;
};

