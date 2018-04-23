/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/

#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

#include "FrameTimer.h"

#include "Rect.h"
#include "Sprite.h"
#include "WidgetSurface.h"
#include "Widget.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();

private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	float dt;

	std::vector<Color> widget1Colors = {Colors::Blue,
										Colors::Cyan,
										Colors::Green,
										Colors::Gray10,
										Colors::Gray15,
										Colors::Gray20};
	std::vector<Rect> widget1Frames =  {Rect(0,0,50,50),
										Rect(50,0,50,40),
										Rect(100,0,50,30),
										Rect(0,50,50,50),
										Rect(50,50,50,40),
										Rect(100,50,50,30)};
										
	WidgetSurface widget1Sheet;
	std::vector<Rect> widget1InactiveFrames = {Rect(0,0,50,50),
											   Rect(50,0,50,40),
											   Rect(100,0,50,30)};
	std::vector<Rect> widget1ActiveFrames   = {Rect(0,50,50,50),
	                                           Rect(50,50,50,40),
	                                           Rect(100,50,50,30)};
	std::vector<Animation> widget1Animations = {Animation(widget1Sheet, 3, widget1InactiveFrames),
												Animation(widget1Sheet, 3, widget1ActiveFrames)};
				   
	Widget widget1;
};
