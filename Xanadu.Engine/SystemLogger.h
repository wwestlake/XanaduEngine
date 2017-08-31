#ifndef __SYSTEM_LOGGER_H
#define __SYSTEM_LOGGER_H

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
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/log/sources/severity_logger.hpp>

using namespace std;
namespace src = boost::log::sources;

namespace Xanadu {
	namespace Utilities {


		enum XANADU_API severity_level
		{
			info,
			normal,
			notofication,
			warning,
			error,
			critical
		};


		class XANADU_API SystemLogger
		{
		public:

			// static singleton factory produces a share_ptr of this class
			static boost::shared_ptr<SystemLogger> Instance();

			void Log(severity_level severity, string message);
			void Info(string message);
			void Normal(string message);
			void Notification(string message);
			void Warning(string message);
			void Error(string message);
			void Critical(string message);

			~SystemLogger();


		private:
			SystemLogger();
			static boost::shared_ptr<SystemLogger> instance;
			src::severity_logger_mt< severity_level > slg;

		};


	}
}
#endif
