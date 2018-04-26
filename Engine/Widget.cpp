
#include "Widget.h"

Widget::Widget(const Sprite & source_sprite)
	:
	Sprite(source_sprite)
{	
}

void Widget::update(const Mouse & mouse, float dt)
{
	Sprite::update(dt);
	switch (widgetStatus)
	{
	case Widget::WidgetStatus::active:
		if (!Sprite::isCordInSprite(mouse.GetPos()))
		{
			widgetStatus = WidgetStatus::inactive;
			Sprite::setAnim((int)WidgetStatus::inactive);
		}
		break;
	default:
		if (Sprite::isCordInSprite(mouse.GetPos()))
		{
			widgetStatus = WidgetStatus::active;
			Sprite::setAnim((int)WidgetStatus::active);
		}
		break;
	}
}
