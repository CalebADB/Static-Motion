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

#include <vector>

#include "PhysicContainers.h"
#include "Rect.h"
#include "WidgetSurface.h"
#include "Animation.h"
#include "Font.h"
#include "Sprite.h"
#include "Button.h"

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

// \/ \/ \/ \/ Branch Code Below \/ \/ \/ \/  
/*	Dimensions2D<int> b1Dimension;
	std::vector<Color> b1Colors = {Colors::Gray10,
		                           Colors::Gray15, 
					               Colors::Gray20};
	std::vector<Rect> inactiveFrames = {Rect(Coordinates2D<int>(0,0),b1Dimension)};
	std::vector<Rect> unpressedFrames = {Rect(Coordinates2D<int>(0,b1Dimension.height),b1Dimension)};
	std::vector<Rect> pressedFrames = {Rect(Coordinates2D<int>(0,b1Dimension.height*2),b1Dimension)};

	std::vector<Rect> b1Frames  = {inactiveFrames[0],
						           unpressedFrames[0],
						           pressedFrames[0]};
	WidgetSurface b1Surface;
	std::vector<Animation> b1Animations = { Animation(b1Surface,1,inactiveFrames),
		Animation(b1Surface,1,unpressedFrames),
		Animation(b1Surface,1,pressedFrames) };
	Button b1;*/

	Font Consolas;

};
