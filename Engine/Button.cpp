
#include "Button.h"

Button::Button(const Sprite & source_sprite)
	:
	Widget(source_sprite)
{
}


Button::~Button()
{
}

void Button::update(const Mouse & mouse, const Keyboard & kbd, float dt)
{
	Widget::update(mouse, dt);

	if (Widget::widgetStatus == Widget::WidgetStatus::active)
	{
		switch (buttonStatus)
		{
		case ButtonStatus::pressed:
			if (!mouse.LeftIsPressed())
			{
				buttonStatus = ButtonStatus::unpressed;
				Sprite::setAnim((int)widgetStatus + (int)buttonStatus);
			}
			break;
		case ButtonStatus::unpressed:
			if (mouse.LeftIsPressed())
			{
				buttonStatus = ButtonStatus::pressed;
				Sprite::setAnim((int)widgetStatus + (int)buttonStatus);
			}
			break;
		}
	}
}
