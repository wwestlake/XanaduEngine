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


#include "XIndividual.h"
#include "MessageDispatcher.h"
#include <iostream>
#include <sstream>
#include "SystemLogger.h"



namespace Xanadu {
	namespace Engine {

		namespace utils = Xanadu::Utilities;

		ComponentRecord::ComponentRecord(XComponent* comp) {
			Component = comp;
			Name = comp->GetName();
		}

		ChildRecord::ChildRecord(XThing* child) {
			Child = child;
		}

		XIndividual::XIndividual() 
		{
			_transform = new Transform();
			_comps = new vector<ComponentRecord>();
			_children = new vector<ChildRecord>();
			MessageDispatcher::GetInstance()->ConnectTick(this, &XIndividual::Tick);
			MessageDispatcher::GetInstance()->ConnectBeginPlay(this, &XIndividual::BeginPlay);
			MessageDispatcher::GetInstance()->ConnectRender(this, &XIndividual::Render);
			MessageDispatcher::GetInstance()->ConnectUpdate(this, &XIndividual::Update);
		}


		XIndividual::~XIndividual()
		{
			delete _comps;
			delete _children;
		}

		void XIndividual::Tick(float deltaTime) {
		}

		void XIndividual::BeginPlay() {
		}

		void XIndividual::Update(float deltaTime) {
		}

		void XIndividual::Render(float deltaTime) {
		}

	}
}