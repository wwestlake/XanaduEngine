#ifndef __XTHING_H
#define __XTHING_H

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
#include "Guid.h"

namespace util = Xanadu::Utilities;

namespace Xanadu {
	namespace Engine {

		
		/**
			class XThing represents the top of the class hierarchy for Xanadu engine.
			XThing is an abstract class that never should be instantiated and its sole
			purpose is to identify the object with a guid and provide hash values.
		*/
		class XANADU_API XThing {
		public:
			friend bool operator==(XThing const& a, XThing const& b) {
				return a.guid == b.guid;
			}

			boost::shared_ptr<util::Guid> Guid() {
				return guid;
			}

			size_t hash_value() {
				return guid->hash_value();
			}

		protected:
			XThing() {
				this->guid = util::Guid::NewGuid();
			}

			XThing(util::Guid* guid)  {
				this->guid = boost::shared_ptr<util::Guid>( guid );
			}

		private:
			boost::shared_ptr<util::Guid> guid;

		};
	}
}

#endif
