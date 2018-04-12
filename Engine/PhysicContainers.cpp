
#include "PhysicContainers.h"

Displacement2D::Displacement2D()
	:
	x(0.0f),
	y(0.0f)
{
}

Displacement2D::Displacement2D(float x, float y)
	:
	x(x),
	y(y)
{
}

Displacement2D::Displacement2D(const Displacement2D & source_Displacement2D)
	:
	x(source_Displacement2D.x),
	y(source_Displacement2D.y)
{
}

Velocity2D::Velocity2D()
	:
	x(0.0f),
	y(0.0f)
{
}

Velocity2D::Velocity2D(float x, float y)
	:
	x(x),
	y(y)
{
}

Velocity2D::Velocity2D(const Displacement2D & disp, float dt)
{
	float x = disp.x / dt;
	float y = disp.y / dt;
}

Velocity2D::Velocity2D(const Velocity2D & source_Velocity2D)
	:
	x(source_Velocity2D.x),
	y(source_Velocity2D.y)
{
}

void Velocity2D::accelerate(const Acceleration2D & acel, float dt)
{
	x += acel.x * dt;
	y += acel.y * dt;
}

Acceleration2D::Acceleration2D()
	:
	x(0.0f),
	y(0.0f)
{
}

Acceleration2D::Acceleration2D(float x, float y)
	:
	x(x),
	y(y)
{
}

Acceleration2D::Acceleration2D(const Velocity2D & velo, float dt)
{
	float x = velo.x / dt;
	float y = velo.y / dt;
}

Acceleration2D::Acceleration2D(const Acceleration2D & source_Acceleration2D)
	:
	x(source_Acceleration2D.x),
	y(source_Acceleration2D.y)
{
}
