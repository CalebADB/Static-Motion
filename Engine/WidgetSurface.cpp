
#include "WidgetSurface.h"

WidgetSurface::WidgetSurface(std::vector<Color> widgetColors, std::vector<Rect> widgetFrames, Dimensions2D<int> dimension)
	: 
	Surface(dimension, Colors::Magenta)
{
	assert(widgetFrames.size() == widgetColors.size());

	Coordinates2D<int> framePxlI;
	Dimensions2D<int> frameDimensions;
	Color frameColor;
	for (int idx = 0; idx < widgetFrames.size(); idx++)
	{
		framePxlI = widgetFrames[idx].getTopLeft();
		frameDimensions = widgetFrames[idx].getDimension();
		frameColor = widgetColors[idx];

		for (int y = 0; y < frameDimensions.height; y++)
		{
			framePxlI.y++;
			for (int x = 0; x < frameDimensions.width; x++)
			{
				framePxlI.x++;
				setPxl(framePxlI, frameColor);
			}
		}
	}
}

