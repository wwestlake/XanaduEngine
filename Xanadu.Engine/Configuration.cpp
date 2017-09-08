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


#include "Configuration.h"
#include "SystemLogger.h"
#include <boost/format.hpp>
#include <string>
#include <sstream>

namespace Xanadu {
	namespace Engine {
		namespace log = Xanadu::Utilities;

		static boost::shared_ptr<Configuration> _instance;

		Configuration::Configuration(int argc, char** argv) {
			po::options_description desc("Available Options");
			desc.add_options()
				("help", "display help message")
				("page-size", po::value<size_t>(&memory_page_size)->default_value(512), "size of pages in megabytes")
				("max-pages", po::value<int>(&memory_max_pages)->default_value(8), "max number of pages to allocate");
			po::store(po::parse_command_line(argc, argv, desc), vm);
			po::notify(vm);
		}

		Configuration::~Configuration() {

		}

		void Configuration::Init(int argc, char** argv)
		{
			if (nullptr != _instance) throw configuration_already_initialized_exception();
			_instance = boost::shared_ptr<Configuration>(new Configuration(argc, argv));
			log::SystemLogger::Instance()->Send(log::severity_level::info) << boost::format("Configuration: page-size=%1%, max-pages=%2%") % Configuration::Instance()->GetMemoryPageSize() % Configuration::Instance()->GetMemoryMaxPages();
		}

		boost::shared_ptr<Configuration> Configuration::Instance()
		{
			if (nullptr == _instance) throw configuration_not_initialized_exception();
			return boost::shared_ptr<Configuration>(_instance);
		}



	}

}



