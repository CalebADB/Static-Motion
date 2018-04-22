/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Colors.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
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

class Color
{
public:
	unsigned int dword;
public:
	constexpr Color() : dword() {}
	constexpr Color( const Color& col )
		:
		dword( col.dword )
	{}
	constexpr Color( unsigned int dw )
		:
		dword( dw )
	{}
	constexpr Color( unsigned char x,unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (x << 24u) | (r << 16u) | (g << 8u) | b )
	{}
	constexpr Color( unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (r << 16u) | (g << 8u) | b )
	{}
	constexpr Color( Color col,unsigned char x )
		:
		Color( (x << 24u) | col.dword )
	{}
	Color& operator =(Color source_color)
	{
		dword = source_color.dword;
		return *this;
	}
	bool operator == (const Color& source_color) const
	{
		return dword == source_color.dword;
	}
	bool operator != (const Color& source_color) const
	{
		return dword != source_color.dword;
	}
	constexpr unsigned char GetX() const
	{
		return dword >> 24u;
	}
	constexpr unsigned char GetA() const
	{
		return GetX();
	}
	constexpr unsigned char GetR() const
	{
		return (dword >> 16u) & 0xFFu;
	}
	constexpr unsigned char GetG() const
	{
		return (dword >> 8u) & 0xFFu;
	}
	constexpr unsigned char GetB() const
	{
		return dword & 0xFFu;
	}
	void SetX( unsigned char x )
	{
		dword = (dword & 0xFFFFFFu) | (x << 24u);
	}
	void SetA( unsigned char a )
	{
		SetX( a );
	}
	void SetR( unsigned char r )
	{
		dword = (dword & 0xFF00FFFFu) | (r << 16u);
	}
	void SetG( unsigned char g )
	{
		dword = (dword & 0xFFFF00FFu) | (g << 8u);
	}
	void SetB( unsigned char b )
	{
		dword = (dword & 0xFFFFFF00u) | b;
	}
};

namespace Colors
{
	static constexpr Color MakeRGB( unsigned char r,unsigned char g,unsigned char b )
	{
		return (r << 16) | (g << 8) | b;
	}
	static constexpr Color Black = MakeRGB( 0u,0u,0u );
	static constexpr Color Gray01 = MakeRGB(  10u, 10u, 10u );
	static constexpr Color Gray02 = MakeRGB(  20u, 20u, 20u );
	static constexpr Color Gray03 = MakeRGB(  30u, 30u, 30u );
	static constexpr Color Gray04 = MakeRGB(  40u, 40u, 40u );
	static constexpr Color Gray05 = MakeRGB(  50u, 50u, 50u );
	static constexpr Color Gray06 = MakeRGB(  60u, 60u, 60u );
	static constexpr Color Gray07 = MakeRGB(  70u, 70u, 70u );
	static constexpr Color Gray08 = MakeRGB(  80u, 80u, 80u );
	static constexpr Color Gray09 = MakeRGB(  90u, 90u, 90u );
	static constexpr Color Gray10 = MakeRGB( 100u,100u,100u );
	static constexpr Color Gray11 = MakeRGB( 110u,110u,110u );
	static constexpr Color Gray12 = MakeRGB( 120u,120u,120u );
	static constexpr Color Gray13 = MakeRGB( 130u,130u,130u );
	static constexpr Color Gray14 = MakeRGB( 140u,140u,140u );
	static constexpr Color Gray15 = MakeRGB( 150u,150u,150u );
	static constexpr Color Gray16 = MakeRGB( 160u,160u,160u );
	static constexpr Color Gray17 = MakeRGB( 170u,170u,170u );
	static constexpr Color Gray18 = MakeRGB( 180u,180u,180u );
	static constexpr Color Gray19 = MakeRGB( 190u,190u,190u );
	static constexpr Color Gray20 = MakeRGB( 200u,200u,200u );
	static constexpr Color Gray21 = MakeRGB( 210u,210u,210u );
	static constexpr Color Gray22 = MakeRGB( 220u,220u,220u );
	static constexpr Color Gray23 = MakeRGB( 230u,230u,230u );
	static constexpr Color Gray24 = MakeRGB( 240u,240u,240u );
	static constexpr Color White = MakeRGB( 255u,255u,0255u );
	static constexpr Color Red = MakeRGB( 255u,0u,0u );
	static constexpr Color Green = MakeRGB( 0u,255u,0u );
	static constexpr Color Blue = MakeRGB( 0u,0u,255u );
	static constexpr Color Yellow = MakeRGB( 255u,255u,0u );
	static constexpr Color Cyan = MakeRGB( 0u,255u,255u );
	static constexpr Color Magenta = MakeRGB( 255u,0u,255u );
}													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  
													  