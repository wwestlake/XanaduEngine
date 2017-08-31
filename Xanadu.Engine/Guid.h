#ifndef __GUID_H
#define __GUID_H

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
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/exception/to_string.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/functional/hash.hpp>
#include <string>

namespace Xanadu {
	namespace Utilities {

		class XANADU_API_HEADER_ONLY Guid
		{
		public:

			static boost::shared_ptr<Guid> NewGuid() {
				return boost::shared_ptr<Guid>(new Guid());
			}

			static boost::shared_ptr<Guid> Copy(boost::shared_ptr<Guid> guid) {
				return boost::shared_ptr<Guid>(guid);
			}


			operator boost::uuids::uuid() const { return tag; }
			operator std::string() const { return boost::to_string(tag); }


			std::string ToString() {
				return boost::to_string(tag);
			}

			friend bool operator<(Guid g1, Guid g2) {
				return g1.tag < g2.tag;
			}
			friend bool operator<=(Guid g1, Guid g2) {
				return g1.tag <= g2.tag;
			}
			friend bool operator>(Guid g1, Guid g2) {
				return g1.tag > g2.tag;
			}
			friend bool operator>=(Guid g1, Guid g2) {
				return g1.tag >= g2.tag;
			}
			friend bool operator!=(Guid g1, Guid g2) {
				return g1.tag != g2.tag;
			}
			friend bool operator==(Guid g1, Guid g2) {
				return g1.tag == g2.tag;
			}

			std::size_t hash_value() {
				boost::hash<boost::uuids::uuid> hasher;
				return hasher(tag);
			}

		protected:
			Guid() {
				tag = boost::uuids::uuid(boost::uuids::random_generator()());
				
			}

		private:
			boost::uuids::uuid tag;

		};


	}
}
#endif

