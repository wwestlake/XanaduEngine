

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

#include "MessageDispatcher.h"
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

namespace Xanadu {
	namespace Engine {

		boost::shared_ptr<MessageDispatcher> _instance;
		MessageDispatcher::MessageDispatcher() {}
		boost::signals2::signal<void(float)> _tick;
		boost::signals2::signal<void()> _beginPlay;
		boost::signals2::signal<void(float)> _update;
		boost::signals2::signal<void(float)> _render;


		boost::shared_ptr<MessageDispatcher> MessageDispatcher::GetInstance()
		{
			if (nullptr == _instance) _instance = boost::shared_ptr<MessageDispatcher>( new MessageDispatcher() );
			return boost::shared_ptr<MessageDispatcher>(_instance);
		}

		void MessageDispatcher::ConnectTick(XIndividual* me, void(XIndividual::*tickhandler)(float))
		{
			_tick.connect(boost::bind(tickhandler, me, _1));
		}

		void MessageDispatcher::ConnectTick(XComponent* me, void(XComponent::*tickhandler)(float))
		{
			_tick.connect(boost::bind(tickhandler, me, _1));
		}


		void MessageDispatcher::ConnectBeginPlay(XIndividual* me, void(XIndividual::*handler)()) 
		{
			_beginPlay.connect(boost::bind(handler, me));
		}

		void MessageDispatcher::ConnectBeginPlay(XComponent* me, void(XComponent::*handler)())
		{
			_beginPlay.connect(boost::bind(handler, me));
		}

		void MessageDispatcher::ConnectUpdate(XIndividual* me, void(XIndividual::*handler)(float))
		{
			_update.connect(boost::bind(handler, me, _1));
		}

		void MessageDispatcher::ConnectUpdate(XComponent* me, void(XComponent::*handler)(float))
		{
			_update.connect(boost::bind(handler, me, _1));
		}

		void MessageDispatcher::ConnectRender(XIndividual* me, void(XIndividual::*handler)(float))
		{
			_render.connect(boost::bind(handler, me, _1));
		}

		void MessageDispatcher::ConnectRender(XComponent* me, void(XComponent::*handler)(float))
		{
			_render.connect(boost::bind(handler, me, _1));
		}

		void MessageDispatcher::BeginPlay()
		{
			_beginPlay();
		}

		void MessageDispatcher::Tick(float deltaTime)
		{
			_tick(deltaTime);
		}

		void MessageDispatcher::Update(float deltaTime)
		{
			_update(deltaTime);
		}

		void MessageDispatcher::Render(float deltaTime)
		{
			_render(deltaTime);
		}

	}
}
