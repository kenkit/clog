//          Copyright Joe Coder 2004 - 2006.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//
//		   .__
//	  ____ |  |   ____   ____
//	_/ ___\|  |  /  _ \ / ___\
//	\  \___|  |_(  <_> ) /_/  >
//	 \___  >____/\____/\___  /
//		 \/           /_____/
//
//
//	@author	:	jhkwak
//	@brief	:	simple c++ logger using boost log
//				If you want to modify it, please refer to the link below.
//				http://www.boost.org/doc/libs/1_65_1/libs/log/doc/html/index.html

#pragma once
#define BOOST_PHOENIX_NO_VARIADIC_FUNCTION_EVAL
#define BOOST_NO_CXX11_VARIADIC_TEMPLATES

#include <boost/log/trivial.hpp>
#include <boost/log/common.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>

#pragma warning(disable: 4244) // possible loss of data


BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(slg, boost::log::sources::wseverity_logger< boost::log::trivial::severity_level >)

#define CLOG(lvl) BOOST_LOG_SEV(slg::get(), lvl)	\
	<< boost::log::add_value("File", __FILE__)		\
	<< boost::log::add_value("Line",__LINE__)		\
	<< boost::log::add_value("Function", __FUNCTION__)
//<< boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

class CLog
{
	void GlobalAttribute();
public:
	CLog();
	~CLog();

	void add_console_sink(bool trace = false);
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		void add_debug_output_sink();
	#endif
	void add_text_file_sink();
	void set_severity_min(boost::log::trivial::severity_level lv);
	void set_log_file(std::string file_name);
	std::string get_log_file(){
		return this->log_file_name;
	}
	private:
	std::string log_file_name;
};
