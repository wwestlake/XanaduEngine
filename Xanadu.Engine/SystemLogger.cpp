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

#include "SystemLogger.h"
#include "FileManager.h"
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace util = Xanadu::Utilities;


namespace Xanadu {
	namespace Utilities {

		BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)

		XANADU_API boost::shared_ptr<SystemLogger> SystemLogger::instance;


		// The operator is used for regular stream formatting
		std::ostream& operator<< (std::ostream& strm, severity_level level)
		{
			static const char* strings[] =
			{
				"info",
				"normal",
				"notification",
				"warning",
				"error",
				"critical"
			};

			if (static_cast<std::size_t>(level) < sizeof(strings) / sizeof(*strings))
				strm << strings[level];
			else
				strm << static_cast<int>(level);

			return strm;
		}

		// Attribute value tag type
		struct severity_tag;

		// The operator is used when putting the severity level to log
		logging::formatting_ostream& operator<<
			(
				logging::formatting_ostream& strm,
				logging::to_log_manip< severity_level, severity_tag > const& manip
				)
		{
			static const char* strings[] =
			{
				"INFO",
				"NORM",
				"NTFY",
				"WARN",
				"ERRR",
				"CRIT"
			};

			severity_level level = manip.get();
			if (static_cast<std::size_t>(level) < sizeof(strings) / sizeof(*strings))
				strm << strings[level];
			else
				strm << static_cast<int>(level);

			return strm;
		}





		boost::shared_ptr<SystemLogger> SystemLogger::Instance()
		{
			if (nullptr == instance) {
				instance = boost::shared_ptr<SystemLogger>(new SystemLogger());
			}
			return boost::shared_ptr<SystemLogger>(instance);
		}

		void SystemLogger::Log(severity_level severity, string message)
		{
			BOOST_LOG_SEV(slg, severity) << message;
		}

		void SystemLogger::Info(string message)
		{
			Log(severity_level::info, message);
		}

		void SystemLogger::Normal(string message)
		{
			Log(severity_level::normal, message);
		}

		void SystemLogger::Notification(string message)
		{
			Log(severity_level::notofication, message);
		}

		void SystemLogger::Warning(string message)
		{
			Log(severity_level::warning, message);
		}

		void SystemLogger::Error(string message)
		{
			Log(severity_level::error, message);
		}

		void SystemLogger::Critical(string message)
		{
			Log(severity_level::critical, message);
		}


		SystemLogger::SystemLogger()
		{
			boost::log::register_simple_formatter_factory< severity_level, char >("Severity");
			logging::add_common_attributes();
			logging::add_file_log
			(
				keywords::file_name = util::FileManager::Instance()->LogPath(string("Xanadu_%N.log")),
				keywords::rotation_size = 10 * 1024 * 1024,
				keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
				keywords::open_mode = std::ios_base::app | std::ios_base::out,
				keywords::format =
				(
					expr::stream
					<< "[" << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S") << "]"
					<< ":<" << expr::attr< severity_level, severity_tag >("Severity")
					<< ">: " << expr::smessage
					),
				keywords::auto_flush = true
			);

			logging::add_console_log(std::cout, boost::log::keywords::format =
				(
					expr::stream
					<< "[" << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S") << "]"
					<< ":<" << expr::attr< severity_level, severity_tag >("Severity")
					<< ">: " << expr::smessage
					)
			);
		}


		SystemLogger::~SystemLogger()
		{
		}
	}
}

