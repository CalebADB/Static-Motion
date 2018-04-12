
#include "Physics.h"

PhysicSystem2D::PhysicSystem2D(Rect source_rect, float mass, Velocity2D source_velo, Acceleration2D source_acel)
	:
	rect(source_rect),
	mass(mass),
	velo(source_velo),
	acel(source_acel)
{
}

PhysicSystem2D::PhysicSystem2D(const PhysicSystem2D & source_PhysicSystem2D)
	:
	rect(source_PhysicSystem2D.rect),
	mass(source_PhysicSystem2D.mass),
	velo(source_PhysicSystem2D.velo),
	acel(source_PhysicSystem2D.acel)
{
}

void PhysicSystem2D::update(float dt)
{
	velo.accelerate(acel, dt);
	rect.move(velo, dt);
}
