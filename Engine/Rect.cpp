
#include "Rect.h"

#include <cassert>

Rect::Rect(int init_posX, int init_posY, int init_width, int init_height) // init ctr
	:
	orig_position(static_cast<float>(init_posX), static_cast<float>(init_posY)),
	orig_dimension(static_cast<float>(init_width), static_cast<float>(init_height)),
	position(static_cast<float>(init_posX), static_cast<float>(init_posY)),
	dimension(static_cast<float>(init_width), static_cast<float>(init_height))
{
}

Rect::Rect(Coordinates2D<int> init_position, Dimensions2D<int> init_dimension)
	:
	orig_position(static_cast<float>(init_position.x), static_cast<float>(init_position.y)),
	orig_dimension(static_cast<float>(init_dimension.width), static_cast<float>(init_dimension.height)),
	position(static_cast<float>(init_position.x), static_cast<float>(init_position.y)),
	dimension(static_cast<float>(init_dimension.width), static_cast<float>(init_dimension.height))
{
}

Rect::Rect(const Rect& source_rect) // copy ctr
	:
	orig_position(source_rect.position),
	orig_dimension(source_rect.dimension),
	position(source_rect.position),
	dimension(source_rect.dimension)
{
}

Rect & Rect::operator=(const Rect & source_rect) // oprerator copy
{
	orig_position = source_rect.position;
	orig_dimension = source_rect.dimension;
	position = source_rect.position;
	dimension = source_rect.dimension;
	return *this;
}

void Rect::move(Velocity2D velo, float dt)
{
	if (!rectLocked)
	{
		position.x += velo.x * dt;
		position.y += velo.y * dt;
	}
	else
	{
		//rect is locked0
		assert(false);//rect is locked1
		//rect is locked2
	}
}

void Rect::inflate(const float factorX, const float factorY)
{
	if (!rectLocked)
	{
		dimension.width *= factorX;
		dimension.height *= factorY;
	}
}

void Rect::setLock(const bool lockStatus)
{
	rectLocked = lockStatus;
}

bool Rect::getLocked() const
{
	return rectLocked;
}

int Rect::getArea() const
{
	return static_cast<int> (dimension.width) * static_cast<int> (dimension.height);
}

Dimensions2D<int> Rect::getDimension() const
{
	return Dimensions2D<int>(static_cast<int>(dimension.width), static_cast<int>(dimension.height));
}

int Rect::getWidth() const
{
	return static_cast<int> (dimension.width);
}

int Rect::getHeight() const
{
	return static_cast<int> (dimension.height);
}

int Rect::getTop() const
{
	return static_cast<int> (position.x);
}

int Rect::getLeft() const
{
	return static_cast<int> (position.y);
}

int Rect::getBottom() const
{
	return static_cast<int> (position.x + dimension.height);
}

int Rect::getRight() const
{
	return static_cast<int> (position.y + dimension.width);
}

Coordinates2D<int> Rect::getTopLeft() const
{
	return Coordinates2D<int> (static_cast<int>(position.x), // x
								static_cast<int>(position.y)); // y
}

Coordinates2D<int> Rect::getBottomLeft() const
{
	return Coordinates2D<int> (static_cast<int>(position.x), // x
								static_cast<int>(position.y + dimension.height)); // y
}

Coordinates2D<int> Rect::getTopRight() const
{
	return Coordinates2D<int> (static_cast<int>(position.x + dimension.width),   // x
								static_cast<int>(position.y)); // y
}

Coordinates2D<int> Rect::getBottomRight() const
{
	return Coordinates2D<int> (static_cast<int>(position.x + dimension.width), // x
								static_cast<int>(position.y + dimension.height)); // y
}

Coordinates2D<int> Rect::getMidTop() const
{
	return Coordinates2D<int> (static_cast<int>(position.x) + (static_cast<int>(dimension.width) / 2), // x
								static_cast<int>(position.y)); // y
}

Coordinates2D<int> Rect::getMidLeft() const
{
	return Coordinates2D<int> (static_cast<int>(position.x), // x
								static_cast<int>(position.y) + (static_cast<int>(dimension.height) / 2)); // y
}

Coordinates2D<int> Rect::getMidBottom() const
{
	return Coordinates2D<int> (static_cast<int>(position.x) + (static_cast<int>(dimension.width) / 2), // x
								static_cast<int>(position.y) + (static_cast<int>(dimension.height))); // y
}

Coordinates2D<int> Rect::getMidRight() const
{
	return Coordinates2D<int> (static_cast<int>(position.x) + (static_cast<int>(dimension.width)), // x
								static_cast<int>(position.y) + (static_cast<int>(dimension.height) / 2)); // y
}

Coordinates2D<int> Rect::getCenter() const
{
	return Coordinates2D<int> (static_cast<int>(position.x) + (static_cast<int>(dimension.width) / 2), // x
								static_cast<int>(position.y) + (static_cast<int>(dimension.height) / 2)); // y
}
