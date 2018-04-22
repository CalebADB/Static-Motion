
#pragma once

#include "Surface.h"
#include "Physics.h"

#include "Animation.h"
#include <vector>
#include <utility>
#include <cassert>


class Sprite
{
public:
	Sprite() = delete; // cannot be default because requires rect and surface
	Sprite(std::vector<class Animation>& animations, Rect& rect);
	Sprite(std::vector<class Animation>& animations, PhysicSystem2D& body);
	Sprite(const Sprite & source_sprite);
	Sprite& Sprite::operator=(const Sprite& source_sprite);
	~Sprite() = default;

	void update(float dt);
	void draw(Graphics& gfx) const;
	bool isCordInSprite(const Coordinates2D<int> & Cord);
	bool isSpriteInSprite(const Sprite & testSprite);

	// GETTRUTION
	PhysicSystem2D getBody() const;
	std::vector<Animation> & getAnimations() const;

	// SECTUM
	void setAnim(int set_iAnim);
	void setVelo(Velocity2D velo);
protected:
	PhysicSystem2D body;
private:
	std::vector<class Animation> animations; // Sprite Sheet
	int iAnim = 0;
};

