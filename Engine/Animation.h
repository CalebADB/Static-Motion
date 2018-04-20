#pragma once

#include "Graphics.h"
#include "Colors.h"

#include "Surface.h"
#include "Rect.h" 

#include <vector>

class Animation
{
public:
	Animation(Surface& spriteSheet, int frameNum, Dimensions2D<int> baseDimensions, std::vector<Coordinates2D<int>> frameCords,
			  float holdTime = 1.0f, Color chroma = Colors::Magenta);
	Animation(Surface& spriteSheet, int frameNum, std::vector<Rect> frameRects, 
			  float holdTime = 1.0f, Color chroma = Colors::Magenta);
	Animation(const Animation& source_animation);
	Animation& Animation::operator=(const Animation& source_animation);
	~Animation() = default;
	
	void update(float dt);
	void draw(Graphics& gfx, const Coordinates2D<int> spritePos) const;
	void draw(Graphics& gfx, const Coordinates2D<int> spritePos, const Rect& clipRect) const;
private:
	void advanceFrame();

private:
	Surface& spriteSheet;
	std::vector<Rect> frameRects;
	Color chroma;

	int frameNum;
	int iCurFrame = 0;
	
	float holdTime;
	float curFrameLife = 0.0f;
};

