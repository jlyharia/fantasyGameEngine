//
// Created by Lee, Yihung on 6/12/18.
//

#ifndef FANTASY_BOOSTLOGGINGMACRO_HPP
#define FANTASY_BOOSTLOGGINGMACRO_HPP
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
using namespace boost::log::trivial;
boost::log::sources::severity_logger<severity_level> lg;
#define LOG(logger, severity) \
    BOOST_LOG_SEV(logger, severity) << "(" << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ") "

#define LOGGER(severity) \
    BOOST_LOG_SEV(lg, severity) << "[" << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << "]"

#endif //FANTASY_BOOSTLOGMACRO_HPP
