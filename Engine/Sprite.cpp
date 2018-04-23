
#include "Sprite.h"

#include "Animation.h"

Sprite::Sprite(std::vector<Animation>& animations, Rect& rect)
	:
	animations(animations),
	body(rect)
{
}

Sprite::Sprite(std::vector<Animation>& animations, PhysicSystem2D& body)
	:
	animations(animations),
	body(body)
{
}

Sprite::Sprite(const Sprite & source_sprite)
	:
	animations(source_sprite.animations),
	body(source_sprite.body)
{
}

Sprite & Sprite::operator=(const Sprite & source_sprite)
{
	animations = source_sprite.animations;
	body = source_sprite.body;
	return *this;
}

void Sprite::update(float dt)
{
	animations[iAnim].update(dt);
	body.update(dt);
}

void Sprite::draw(Graphics & gfx) const
{
	animations[iAnim].draw(gfx, body.rect.getTopLeft());
}

bool Sprite::isCordInSprite(const Coordinates2D<int>& Cord)
{
	if ((Cord.y < body.rect.getBottom()) && 
		(Cord.y > body.rect.getTop()))
	{
		if ((Cord.x < body.rect.getRight()) &&
			(Cord.x > body.rect.getLeft()))
		{
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

bool Sprite::isSpriteInSprite(const Sprite & testSprite)
{
	assert(false); //not defined
	return false;
}

PhysicSystem2D Sprite::getBody() const
{
	return body;
}

std::vector<Animation> Sprite::getAnimations() const
{
	return animations;
}

void Sprite::setAnim(int set_iAnim)
{
	if (set_iAnim < animations.size())
	{
		iAnim = set_iAnim;
	}
	else
	{
		assert(false);
		iAnim = 0; // default
	}
}

void Sprite::setVelo(Velocity2D velo)
{
	body.velo = velo;
}
