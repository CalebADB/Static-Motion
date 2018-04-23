
#include "Widget.h"

Widget::Widget(const Sprite & source_sprite)
	:
	Sprite(source_sprite)
{	
}

void Widget::update(Mouse & mouse, float dt)
{
	Sprite::update(dt);
	switch (widgetStatus)
	{
	case Widget::Status::active:
		if (!Sprite::isCordInSprite(mouse.GetPos()))
		{
			widgetStatus = Status::inactive;
			Sprite::setAnim((int)Status::inactive);
		}
		break;
	default:
		if (Sprite::isCordInSprite(mouse.GetPos()))
		{
			widgetStatus = Status::active;
			Sprite::setAnim((int)Status::active);
		}
		break;
	}
}

void Widget::checkMouse(Mouse & mouse)
{
	assert(false);//not defined
}
