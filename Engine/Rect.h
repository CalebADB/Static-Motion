
#pragma once

#include "PhysicContainers.h"

#include <utility>

class Rect
{
public:
	Rect() = delete; //rect should not have default constructure
	Rect(int init_posX, int init_posY, int init_width, int init_height);
	Rect(Coordinates2D<int> init_position, Dimensions2D<int> init_dimension);
	Rect(const Rect& source_rect);
	Rect& Rect::operator=(const Rect& source_rect);
	~Rect() = default;
	
public:
	// Setters (functions for changing shit)
	void move(Velocity2D velo, float dt);
	void inflate(const float factorX, const float factorY);
	void setLock(const bool lockStatus);

	// getters (functions for tell ya shit)
	bool getLocked() const;

	int getArea() const;
	
	Dimensions2D<int> getDimension() const;
	int getWidth() const;
	int getHeight() const;
	
	int getTop() const;
	int getLeft() const;
	int getBottom() const;
	int getRight() const;
	
	Coordinates2D<int>	getTopLeft() const;
	Coordinates2D<int> getBottomLeft() const;
	Coordinates2D<int> getTopRight() const;
	Coordinates2D<int> getBottomRight() const;
	
	Coordinates2D<int>	getMidTop() const;
	Coordinates2D<int> getMidLeft() const;
	Coordinates2D<int> getMidBottom() const;
	Coordinates2D<int> getMidRight() const;
	
	Coordinates2D<int>	getCenter() const;

private:
	bool rectLocked = false;

	Coordinates2D<float> orig_position;
	Coordinates2D<float> position;

	Dimensions2D<float> orig_dimension;
	Dimensions2D<float> dimension;
};

