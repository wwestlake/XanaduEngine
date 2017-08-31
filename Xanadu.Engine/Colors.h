#ifndef __COLORS_H
#define __COLORS_H

/***************************************************************************************
Xanadu Open GL Windows Game Engine
Copyright (C) 2017  William W. Westlake Jr.
wwestlake@lagdaemon.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************************/

#include "glm/glm.hpp"

#define COLOR(R,G,B,A) glm::vec4(R,G,B,A)
#define RGBCOLOR(R,G,B) glm::vec4(R,G,B,1.0f)
#define COLOR_DEF extern const glm::vec4
#define RGB_FROM_COLOR(A) A.r, A.g, A.b, A.a



namespace Xanadu {
	namespace Colors {
		COLOR_DEF IndianRed = COLOR(0.804f, 0.361f, 0.361f, 1.0f);
		COLOR_DEF LightCoral = COLOR(0.941f, 0.502f, 0.502f, 1.0f);
		COLOR_DEF Salmon = COLOR(0.980f, 0.502f, 0.447f, 1.0f);
		COLOR_DEF DarkSalmon = COLOR(0.914f, 0.588f, 0.478f, 1.0f);
		COLOR_DEF LightSalmon = COLOR(01.000f, 0.627f, 0.478f, 1.0f);
		COLOR_DEF Crimson = COLOR(0.863f, 0.078f, 0.235f, 1.0f);
		COLOR_DEF Red = COLOR(01.000f, 0.000f, 0.000f, 1.0f);
		COLOR_DEF FireBrick = COLOR(0.698f, 0.133f, 0.133f, 1.0f);
		COLOR_DEF DarkRed = COLOR(0.545f, 0.000f, 0.000f, 1.0f);
		COLOR_DEF Pink = COLOR(01.000f, 0.753f, 0.796f, 1.0f);
		COLOR_DEF LightPink = COLOR(01.000f, 0.714f, 0.757f, 1.0f);
		COLOR_DEF HotPink = COLOR(01.000f, 0.412f, 0.706f, 1.0f);
		COLOR_DEF DeepPink = COLOR(01.000f, 0.078f, 0.576f, 1.0f);
		COLOR_DEF MediumVioletRed = COLOR(0.780f, 0.082f, 0.522f, 1.0f);
		COLOR_DEF PaleVioletRed = COLOR(0.859f, 0.439f, 0.576f, 1.0f);
		COLOR_DEF Coral = COLOR(01.000f, 0.498f, 0.314f, 1.0f);
		COLOR_DEF Tomato = COLOR(01.000f, 0.388f, 0.278f, 1.0f);
		COLOR_DEF OrangeRed = COLOR(01.000f, 0.271f, 0.000f, 1.0f);
		COLOR_DEF DarkOrange = COLOR(01.000f, 0.549f, 0.000f, 1.0f);
		COLOR_DEF Orange = COLOR(01.000f, 0.647f, 0.000f, 1.0f);
		COLOR_DEF Gold = COLOR(01.000f, 0.843f, 0.000f, 1.0f);
		COLOR_DEF Yellow = COLOR(01.000f, 01.000f, 0.000f, 1.0f);
		COLOR_DEF LightYellow = COLOR(01.000f, 01.000f, 0.878f, 1.0f);
		COLOR_DEF LemonChion = COLOR(01.000f, 0.980f, 0.804f, 1.0f);
		COLOR_DEF LightGoldenrodYellow = COLOR(0.980f, 0.980f, 0.824f, 1.0f);
		COLOR_DEF PapayaWhip = COLOR(01.000f, 0.937f, 0.835f, 1.0f);
		COLOR_DEF Moccasin = COLOR(01.000f, 0.894f, 0.710f, 1.0f);
		COLOR_DEF PeachPu = COLOR(01.000f, 0.855f, 0.725f, 1.0f);
		COLOR_DEF PaleGoldenrod = COLOR(0.933f, 0.910f, 0.667f, 1.0f);
		COLOR_DEF Khaki = COLOR(0.941f, 0.902f, 0.549f, 1.0f);
		COLOR_DEF DarkKhaki = COLOR(0.741f, 0.718f, 0.420f, 1.0f);
		COLOR_DEF Lavender = COLOR(0.902f, 0.902f, 0.980f, 1.0f);
		COLOR_DEF Thistle = COLOR(0.847f, 0.749f, 0.847f, 1.0f);
		COLOR_DEF Plum = COLOR(0.867f, 0.627f, 0.867f, 1.0f);
		COLOR_DEF Violet = COLOR(0.933f, 0.510f, 0.933f, 1.0f);
		COLOR_DEF Orchid = COLOR(0.855f, 0.439f, 0.839f, 1.0f);
		COLOR_DEF Fuchsia = COLOR(01.000f, 0.000f, 01.000f, 1.0f);
		COLOR_DEF Magenta = COLOR(01.000f, 0.000f, 01.000f, 1.0f);
		COLOR_DEF MediumOrchid = COLOR(0.729f, 0.333f, 0.827f, 1.0f);
		COLOR_DEF MediumPurple = COLOR(0.576f, 0.439f, 0.859f, 1.0f);
		COLOR_DEF BlueViolet = COLOR(0.541f, 0.169f, 0.886f, 1.0f);
		COLOR_DEF DarkViolet = COLOR(0.580f, 0.000f, 0.827f, 1.0f);
		COLOR_DEF DarkOrchid = COLOR(0.600f, 0.196f, 0.800f, 1.0f);
		COLOR_DEF DarkMagenta = COLOR(0.545f, 0.000f, 0.545f, 1.0f);
		COLOR_DEF Purple = COLOR(0.502f, 0.000f, 0.502f, 1.0f);
		COLOR_DEF Indigo = COLOR(0.294f, 0.000f, 0.510f, 1.0f);
		COLOR_DEF SlateBlue = COLOR(0.416f, 0.353f, 0.804f, 1.0f);
		COLOR_DEF DarkSlateBlue = COLOR(0.282f, 0.239f, 0.545f, 1.0f);
		COLOR_DEF GreenYellow = COLOR(0.678f, 01.000f, 0.184f, 1.0f);
		COLOR_DEF Chartreuse = COLOR(0.498f, 01.000f, 0.000f, 1.0f);
		COLOR_DEF LawnGreen = COLOR(0.486f, 0.988f, 0.000f, 1.0f);
		COLOR_DEF Lime = COLOR(0.000f, 01.000f, 0.000f, 1.0f);
		COLOR_DEF LimeGreen = COLOR(0.196f, 0.804f, 0.196f, 1.0f);
		COLOR_DEF PaleGreen = COLOR(0.596f, 0.984f, 0.596f, 1.0f);
		COLOR_DEF LightGreen = COLOR(0.565f, 0.933f, 0.565f, 1.0f);
		COLOR_DEF MediumSpringGreen = COLOR(0.000f, 0.980f, 0.604f, 1.0f);
		COLOR_DEF SpringGreen = COLOR(0.000f, 01.000f, 0.498f, 1.0f);
		COLOR_DEF MediumSeaGreen = COLOR(0.235f, 0.702f, 0.443f, 1.0f);
		COLOR_DEF SeaGreen = COLOR(0.180f, 0.545f, 0.341f, 1.0f);
		COLOR_DEF ForestGreen = COLOR(0.133f, 0.545f, 0.133f, 1.0f);
		COLOR_DEF Green = COLOR(0.000f, 0.502f, 0.000f, 1.0f);
		COLOR_DEF DarkGreen = COLOR(0.000f, 0.392f, 0.000f, 1.0f);
		COLOR_DEF YellowGreen = COLOR(0.604f, 0.804f, 0.196f, 1.0f);
		COLOR_DEF OliveDrab = COLOR(0.420f, 0.557f, 0.137f, 1.0f);
		COLOR_DEF Olive = COLOR(0.502f, 0.502f, 0.000f, 1.0f);
		COLOR_DEF DarkOliveGreen = COLOR(0.333f, 0.420f, 0.184f, 1.0f);
		COLOR_DEF MediumAquamarine = COLOR(0.400f, 0.804f, 0.667f, 1.0f);
		COLOR_DEF DarkSeaGreen = COLOR(0.561f, 0.737f, 0.561f, 1.0f);
		COLOR_DEF LightSeaGreen = COLOR(0.125f, 0.698f, 0.667f, 1.0f);
		COLOR_DEF DarkCyan = COLOR(0.000f, 0.545f, 0.545f, 1.0f);
		COLOR_DEF Teal = COLOR(0.000f, 0.502f, 0.502f, 1.0f);
		COLOR_DEF Aqua = COLOR(0.000f, 01.000f, 01.000f, 1.0f);
		COLOR_DEF Cyan = COLOR(0.000f, 01.000f, 01.000f, 1.0f);
		COLOR_DEF LightCyan = COLOR(0.878f, 01.000f, 01.000f, 1.0f);
		COLOR_DEF PaleTurquoise = COLOR(0.686f, 0.933f, 0.933f, 1.0f);
		COLOR_DEF Aquamarine = COLOR(0.498f, 01.000f, 0.831f, 1.0f);
		COLOR_DEF Turquoise = COLOR(0.251f, 0.878f, 0.816f, 1.0f);
		COLOR_DEF MediumTurquoise = COLOR(0.282f, 0.820f, 0.800f, 1.0f);
		COLOR_DEF DarkTurquoise = COLOR(0.000f, 0.808f, 0.820f, 1.0f);
		COLOR_DEF CadetBlue = COLOR(0.373f, 0.620f, 0.627f, 1.0f);
		COLOR_DEF SteelBlue = COLOR(0.275f, 0.510f, 0.706f, 1.0f);
		COLOR_DEF LightSteelBlue = COLOR(0.690f, 0.769f, 0.871f, 1.0f);
		COLOR_DEF PowderBlue = COLOR(0.690f, 0.878f, 0.902f, 1.0f);
		COLOR_DEF LightBlue = COLOR(0.678f, 0.847f, 0.902f, 1.0f);
		COLOR_DEF SkyBlue = COLOR(0.529f, 0.808f, 0.922f, 1.0f);
		COLOR_DEF LightSkyBlue = COLOR(0.529f, 0.808f, 0.980f, 1.0f);
		COLOR_DEF DeepSkyBlue = COLOR(0.000f, 0.749f, 01.000f, 1.0f);
		COLOR_DEF DodgerBlue = COLOR(0.118f, 0.565f, 01.000f, 1.0f);
		COLOR_DEF CornlowerBlue = COLOR(0.392f, 0.584f, 0.929f, 1.0f);
		COLOR_DEF MediumSlateBlue = COLOR(0.482f, 0.408f, 0.933f, 1.0f);
		COLOR_DEF RoyalBlue = COLOR(0.255f, 0.412f, 0.882f, 1.0f);
		COLOR_DEF Blue = COLOR(0.000f, 0.000f, 01.000f, 1.0f);
		COLOR_DEF MediumBlue = COLOR(0.000f, 0.000f, 0.804f, 1.0f);
		COLOR_DEF DarkBlue = COLOR(0.000f, 0.000f, 0.545f, 1.0f);
		COLOR_DEF Navy = COLOR(0.000f, 0.000f, 0.502f, 1.0f);
		COLOR_DEF MidnightBlue = COLOR(0.098f, 0.098f, 0.439f, 1.0f);
		COLOR_DEF Cornsilk = COLOR(01.000f, 0.973f, 0.863f, 1.0f);
		COLOR_DEF BlanchedAlmond = COLOR(01.000f, 0.922f, 0.804f, 1.0f);
		COLOR_DEF Bisque = COLOR(01.000f, 0.894f, 0.769f, 1.0f);
		COLOR_DEF NavajoWhite = COLOR(01.000f, 0.871f, 0.678f, 1.0f);
		COLOR_DEF Wheat = COLOR(0.961f, 0.871f, 0.702f, 1.0f);
		COLOR_DEF BurlyWood = COLOR(0.871f, 0.722f, 0.529f, 1.0f);
		COLOR_DEF Tan = COLOR(0.824f, 0.706f, 0.549f, 1.0f);
		COLOR_DEF RosyBrown = COLOR(0.737f, 0.561f, 0.561f, 1.0f);
		COLOR_DEF SandyBrown = COLOR(0.957f, 0.643f, 0.376f, 1.0f);
		COLOR_DEF Goldenrod = COLOR(0.855f, 0.647f, 0.125f, 1.0f);
		COLOR_DEF DarkGoldenrod = COLOR(0.722f, 0.525f, 0.043f, 1.0f);
		COLOR_DEF Peru = COLOR(0.804f, 0.522f, 0.247f, 1.0f);
		COLOR_DEF Chocolate = COLOR(0.824f, 0.412f, 0.118f, 1.0f);
		COLOR_DEF SaddleBrown = COLOR(0.545f, 0.271f, 0.075f, 1.0f);
		COLOR_DEF Sienna = COLOR(0.627f, 0.322f, 0.176f, 1.0f);
		COLOR_DEF Brown = COLOR(0.647f, 0.165f, 0.165f, 1.0f);
		COLOR_DEF Maroon = COLOR(0.502f, 0.000f, 0.000f, 1.0f);
		COLOR_DEF White = COLOR(01.000f, 01.000f, 01.000f, 1.0f);
		COLOR_DEF Snow = COLOR(01.000f, 0.980f, 0.980f, 1.0f);
		COLOR_DEF Honeydew = COLOR(0.941f, 01.000f, 0.941f, 1.0f);
		COLOR_DEF MintCream = COLOR(0.961f, 01.000f, 0.980f, 1.0f);
		COLOR_DEF Azure = COLOR(0.941f, 01.000f, 01.000f, 1.0f);
		COLOR_DEF AliceBlue = COLOR(0.941f, 0.973f, 01.000f, 1.0f);
		COLOR_DEF GhostWhite = COLOR(0.973f, 0.973f, 01.000f, 1.0f);
		COLOR_DEF WhiteSmoke = COLOR(0.961f, 0.961f, 0.961f, 1.0f);
		COLOR_DEF Seashell = COLOR(01.000f, 0.961f, 0.933f, 1.0f);
		COLOR_DEF Beige = COLOR(0.961f, 0.961f, 0.863f, 1.0f);
		COLOR_DEF OldLace = COLOR(0.992f, 0.961f, 0.902f, 1.0f);
		COLOR_DEF FloralWhite = COLOR(01.000f, 0.980f, 0.941f, 1.0f);
		COLOR_DEF Ivory = COLOR(01.000f, 01.000f, 0.941f, 1.0f);
		COLOR_DEF AntiqueWhite = COLOR(0.980f, 0.922f, 0.843f, 1.0f);
		COLOR_DEF Linen = COLOR(0.980f, 0.941f, 0.902f, 1.0f);
		COLOR_DEF LavenderBlush = COLOR(01.000f, 0.941f, 0.961f, 1.0f);
		COLOR_DEF MistyRose = COLOR(01.000f, 0.894f, 0.882f, 1.0f);
		COLOR_DEF Gainsboro = COLOR(0.863f, 0.863f, 0.863f, 1.0f);
		COLOR_DEF LightGrey = COLOR(0.827f, 0.827f, 0.827f, 1.0f);
		COLOR_DEF Silver = COLOR(0.753f, 0.753f, 0.753f, 1.0f);
		COLOR_DEF DarkGray = COLOR(0.663f, 0.663f, 0.663f, 1.0f);
		COLOR_DEF Gray = COLOR(0.502f, 0.502f, 0.502f, 1.0f);
		COLOR_DEF DimGray = COLOR(0.412f, 0.412f, 0.412f, 1.0f);
		COLOR_DEF LightSlateGray = COLOR(0.467f, 0.533f, 0.600f, 1.0f);
		COLOR_DEF SlateGray = COLOR(0.439f, 0.502f, 0.565f, 1.0f);
		COLOR_DEF DarkSlateGray = COLOR(0.184f, 0.310f, 0.310f, 1.0f);
		COLOR_DEF Black = COLOR(0.000f, 0.000f, 0.000f, 1.0f);
	}


}

#endif