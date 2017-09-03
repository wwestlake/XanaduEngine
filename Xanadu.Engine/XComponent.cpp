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


#include "stdafx.h"
#include "XComponent.h"

#include "MessageDispatcher.h"

namespace Xanadu {
	namespace Engine {

		XComponent::XComponent(string name) : _name(name) 
		{
			_transform = new Transform();

			MessageDispatcher::GetInstance()->ConnectTick(this, &XComponent::Tick);
			MessageDispatcher::GetInstance()->ConnectBeginPlay(this, &XComponent::BeginPlay);
			MessageDispatcher::GetInstance()->ConnectRender(this, &XComponent::Render);
			MessageDispatcher::GetInstance()->ConnectUpdate(this, &XComponent::Update);
		}

		XComponent::~XComponent()
		{
		}

		void XComponent::Tick(float deltaTime) {
		}

		void XComponent::BeginPlay() {
		}

		void XComponent::Update(float deltaTime) {
		}

		void XComponent::Render(float deltaTime) {
		}
	}
}
