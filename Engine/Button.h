
#pragma once

#include "Sprite.h"
#include "Widget.h"

#include "Keyboard.h"
#include "Mouse.h"

class Button : public Widget
{
	enum class ButtonStatus {
		unpressed,
		pressed,
		count
	};
public:
	Button(const Sprite & source_sprite);
	~Button();

	void update(const Mouse & mouse, const Keyboard & kbd, float dt);

private: 
	ButtonStatus buttonStatus = ButtonStatus::unpressed;
};

