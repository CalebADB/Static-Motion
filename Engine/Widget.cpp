
#include "Widget.h"

Widget::Widget(const Sprite & source_sprite)
	:
	Sprite(source_sprite)
{	
}

void Widget::update(Mouse & mouse, float dt)
{
	Sprite::update(dt);
}

void Widget::checkMouse(Mouse & mouse)
{
	assert(false);//not defined
}
