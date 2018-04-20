
#pragma once

#include "Rect.h"
#include "PhysicContainers.h"

class PhysicSystem2D
{
public:
	PhysicSystem2D() = delete; //rect should not have default constructure
	PhysicSystem2D(Rect source_rect, float mass = 0.0f, Velocity2D source_velo = Velocity2D(0,0), Acceleration2D source_acel = Acceleration2D(0, 0));
	PhysicSystem2D(const PhysicSystem2D & source_PhysicSystem2D);
	~PhysicSystem2D() = default;
	void update(float dt);

	Rect rect;
	float mass;
	Velocity2D velo;
	Acceleration2D acel;
};

