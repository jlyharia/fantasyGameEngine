//
// Created by Yihung Lee on 10/31/17.
//
#define BOOST_LOG_DYN_LINK 1

#include "gtest/gtest.h"
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>

using namespace std;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

#define LOG(logger, severity) \
    BOOST_LOG_SEV(logger, severity) << "(" << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ") "

void init() {
//    logging::add_file_log
//            (
//                    keywords::file_name = "sample.log",
//                    // This makes the sink to write log records that look like this:
//                    // 1: <normal> A normal severity message
//                    // 2: <error> An error severity message
//                    keywords::format =
//                            (
//                                    expr::stream
//                                            << expr::attr<unsigned int>("LineID") << " |"
//                                            << " [ " << expr::format_date_time<boost::posix_time::ptime>("TimeStamp",
//                                                                                                         "%Y-%m-%d %H:%M:%S")
//                                            << "]"
//                                            << ": <" << logging::trivial::severity << "> "
//                                            << expr::smessage
//                            )
//            );

//    logging::add_console_log
//            (
//                    std::clog,
//                    keywords::format =
//                            (
//                                    expr::stream
//                                            << " [ " << expr::format_date_time<boost::posix_time::ptime>("TimeStamp",
//                                                                                                         "%Y-%m-%d %H:%M:%S")
//                                            << "]"
//                                            << ": <" << logging::trivial::severity << "> "
//                                            << expr::smessage
//                            )
//
//            );

}

TEST (BoostLog, format){
    init();
//    logging::add_common_attributes();

    using namespace logging::trivial;
    src::severity_logger<severity_level> lg;
    cout<<'\n';
    LOG(lg, debug) << "Hello world";
    BOOST_LOG_TRIVIAL(debug)
    << "Number of Meshes = ";
}