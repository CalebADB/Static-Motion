
#pragma once

#include "Sprite.h"

#include "Mouse.h"

#include "Rect.h"

class Widget : public Sprite
{
public:
	enum class WidgetStatus {
		inactive,
		active,
		count
	};

	Widget(const Sprite & source_sprite);
	~Widget() = default;

	void update(const Mouse& mouse, float dt);

protected:
	Widget::WidgetStatus widgetStatus = Widget::WidgetStatus::inactive;
};

