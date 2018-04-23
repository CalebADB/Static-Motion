
#include "Animation.h"

#include <cassert>

Animation::Animation(Surface& spriteSheet, int frameNum, Dimensions2D<int> baseDimensions,
					 std::vector<Coordinates2D<int>> simpleFrameCords, float holdTime, Color chroma)
	:
	spriteSheet(spriteSheet),
	frameNum(frameNum),
	chroma(chroma),
	holdTime(holdTime)
{
	for (int idx = 0; idx < frameNum; idx++)
	{
		frameRects.push_back(Rect(Coordinates2D<int>(simpleFrameCords[idx].x * baseDimensions.width, 
							      simpleFrameCords[idx].y * baseDimensions.height),
							 baseDimensions));
	}
}

Animation::Animation(Surface & spriteSheet, int frameNum, std::vector<Rect> frameRects, float holdTime, Color chroma)
	:
	spriteSheet(spriteSheet),
	frameRects(frameRects),
	frameNum(frameNum),
	chroma(chroma),
	holdTime(holdTime)
{
}

Animation::Animation(const Animation & source_animation)
	:
	spriteSheet(source_animation.spriteSheet),
	frameRects(source_animation.frameRects),
	frameNum(source_animation.frameNum),
	chroma(source_animation.chroma),
	holdTime(source_animation.holdTime)
{
}

Animation & Animation::operator=(const Animation & source_animation)
{
	spriteSheet = source_animation.spriteSheet;
	frameRects = source_animation.frameRects;
	frameNum = source_animation.frameNum;
	chroma = source_animation.chroma;
	holdTime = source_animation.holdTime;
	return *this;
}

void Animation::update(float dt)
{
	curFrameLife += dt;
	while (curFrameLife > holdTime)
	{
		advanceFrame();
		curFrameLife -= holdTime;
	}
}

void Animation::draw(Graphics & gfx, const Coordinates2D<int> & spritePos, Color Chroma) const
{
	assert(iCurFrame < frameNum);

	Coordinates2D<int> setPxlI = spritePos;

	const Rect & frameRect = frameRects[iCurFrame];
	Coordinates2D<int> frameCord = frameRect.getTopLeft();
	Dimensions2D<int> frameDimensions = frameRect.getDimension();

	Coordinates2D<int> getPxlI;
	for (int y = 0; y < frameDimensions.height; y++)
	{
		frameCord.y++;
		setPxlI.y++;
		for (int x = 0; x < frameDimensions.width; x++)
		{
			frameCord.x++;
			setPxlI.x++;
			Color BlitPxl = spriteSheet.getPxl(frameCord);
			if (BlitPxl != Chroma)
			{
				gfx.PutPixel(setPxlI.x, setPxlI.y, BlitPxl);
			}
		}
		frameCord.x = frameRect.getTopLeft().x;
		setPxlI.x = spritePos.x;
	}
}

void Animation::draw(Graphics & gfx, const Coordinates2D<int> & spritePos, const Rect & clipRect, Color Chroma) const
{
	assert(false); //not defined
}

void Animation::advanceFrame()
{
	++iCurFrame;
	if (iCurFrame >= frameNum)
	{
		iCurFrame = 0;
	}
}
