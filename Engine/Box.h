
#pragma once

#include "Mouse.h"

#include "Rect.h"

#include "Sprite.h"

class Box : Sprite
{
public:
	enum class Status {
		inactive,
		active,
		count
	};

	Box(const Sprite & source_sprite);
	~Box() = default;

	void update(Mouse& mouse, float dt);
	void draw(Graphics& gfx);
protected:
	void checkMouse(Mouse& mouse);
private:
	Box::Status boxStatus = Box::Status::inactive;
};

