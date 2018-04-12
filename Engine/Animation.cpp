
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

void Animation::draw(Graphics & gfx, const Coordinates2D<int> spritePos) const
{
	assert(iCurFrame < frameNum);
	
	const Rect & frameRect = frameRects[iCurFrame];
	Coordinates2D<int> sheetPxlCord(0,0);
	Dimensions2D<int> pxlOffSet(0,0); 
	
	sheetPxlCord.y = frameRect.getTop();
	for (pxlOffSet.height = 0; pxlOffSet.height < frameRect.getHeight(); pxlOffSet.height++)
	{
		sheetPxlCord.x = frameRect.getLeft();
		for (pxlOffSet.width = 0; pxlOffSet.width < frameRect.getWidth(); pxlOffSet.width++)
		{
			const Color  pxl = spriteSheet.getPxl(sheetPxlCord);
			if (pxl != chroma)
			{
				gfx.PutPixel(spritePos.x + pxlOffSet.width, spritePos.y + pxlOffSet.height, pxl);
			}
			sheetPxlCord.x++;
		}
		sheetPxlCord.y++;
	}
}

void Animation::draw(Graphics & gfx, const Coordinates2D<int> spritePos, const Rect & clipRect) const
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
