#ifndef XANADU_SINGLE_INCLUDE_CONFIGURATION_H
#define XANADU_SINGLE_INCLUDE_CONFIGURATION_H

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
#include <boost/program_options.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/exception/exception.hpp>



namespace Xanadu {
	namespace Engine {

		namespace po = boost::program_options;


		class XANADU_API configuration_not_initialized_exception : boost::exception {};
		class XANADU_API configuration_already_initialized_exception : boost::exception {};

		class XANADU_API Configuration {
		public:
			~Configuration();

			static boost::shared_ptr<Configuration> Instance();

			static void Init(int argc, char** argv);

			size_t GetMemoryPageSize() { return memory_page_size * megabyte_multiplier; }
			int GetMemoryMaxPages() { return memory_max_pages; }

		protected:
			Configuration(int argc, char** argv);

		private:
			const size_t megabyte_multiplier = 1024 * 1024;

			po::variables_map vm;

			size_t memory_page_size;
			int memory_max_pages;

		};



	}
}


#endif

