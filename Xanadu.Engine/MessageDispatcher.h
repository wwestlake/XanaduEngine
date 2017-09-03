#ifndef XANADU_SINGLE_INCLUDE_MESSAGEDISPATCHER_H
#define XANADU_SINGLE_INCLUDE_MESSAGEDISPATCHER_H

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

#include "defines.h"
#include <boost/shared_ptr.hpp>
#include "XIndividual.h"
#include "XComponent.h"

namespace Xanadu {
	namespace Engine {


		class XANADU_API MessageDispatcher {
		public:
			
			static boost::shared_ptr<MessageDispatcher> GetInstance();
			
			void ConnectTick(XIndividual* me, void(XIndividual::*handler)(float));
			void ConnectTick(XComponent* me, void(XComponent::*handler)(float));
			void ConnectBeginPlay(XIndividual* me, void(XIndividual::*handler)());
			void ConnectBeginPlay(XComponent* me, void(XComponent::*handler)());
			void ConnectUpdate(XIndividual* me, void(XIndividual::*handler)(float));
			void ConnectUpdate(XComponent* me, void(XComponent::*handler)(float));
			void ConnectRender(XIndividual* me, void(XIndividual::*handler)(float));
			void ConnectRender(XComponent* me, void(XComponent::*handler)(float));

			void Tick(float deltaTime);
			void BeginPlay();
			void Update(float deltaTime);
			void Render(float deltaTime);

		protected:
			MessageDispatcher();

		};


	}
}


#endif

