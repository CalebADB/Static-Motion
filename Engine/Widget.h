
#pragma once

#include "Mouse.h"

#include "Rect.h"

#include "Sprite.h"

class Widget : public Sprite
{
public:
	enum class Status {
		inactive,
		active,
		count
	};

	Widget(const Sprite & source_sprite);
	~Widget() = default;

	void update(Mouse& mouse, float dt);
protected:
	void checkMouse(Mouse& mouse);
private:
	Widget::Status boxStatus = Widget::Status::inactive;
};

