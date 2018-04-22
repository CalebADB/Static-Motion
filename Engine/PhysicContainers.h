
#pragma once

template<typename containerType>
class Coordinates2D
{
public:
	Coordinates2D() = default;
	Coordinates2D(containerType x, containerType y)
		:
		x(x),
		y(y)
	{}
	Coordinates2D(const Coordinates2D & source_Coordinates2D)
		:
		x(source_Coordinates2D.x),
		y(source_Coordinates2D.y)
	{}
	~Coordinates2D() = default;
	containerType x;
	containerType y;
};

template<typename containerType>
class Dimensions2D
{
public:
	Dimensions2D() = default;
	Dimensions2D(containerType width, containerType height)
		:
		width(width),
		height(height)
	{}
	Dimensions2D(const Dimensions2D & source_Dimensions2D)
		:
		width(source_Dimensions2D.width),
		height(source_Dimensions2D.height)
	{}
	//Dimensions2D& Dimensions2D::operator=(const Dimensions2D& source_Dimensions2D);
	~Dimensions2D() = default;
	containerType getArea() const;
	containerType width;
	containerType height;
}; 

class Displacement2D
{
public:
	Displacement2D();
	Displacement2D(float x, float y);
	Displacement2D(const Displacement2D & source_Coordinates2D);
	~Displacement2D() = default;
	float x;
	float y;
};

class Velocity2D
{
public:
	Velocity2D();
	Velocity2D(float x, float y);
	Velocity2D(const Displacement2D & disp, float dt);
	Velocity2D(const Velocity2D & source_Coordinates2D);
	~Velocity2D() = default;
	void accelerate(const class Acceleration2D & acel, float dt);
	float x;
	float y;
};

class Acceleration2D
{
public:
	Acceleration2D();
	Acceleration2D(float x, float y);
	Acceleration2D(const Velocity2D & velo, float dt);
	Acceleration2D(const Acceleration2D & source_Coordinates2D);
	~Acceleration2D() = default;
	float x;
	float y;
};

template<typename containerType>
inline containerType Dimensions2D<containerType>::getArea() const
{
	return width * height;
}
