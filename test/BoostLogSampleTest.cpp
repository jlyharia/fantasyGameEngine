//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "../src/BoostLoggingMacro.hpp"

using namespace std;

TEST (BoostLog, format) {
    cout << '\n';
    LOG(lg, debug) << "Hello world";
    LOGGER(debug) << "Hello world";
}