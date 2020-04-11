//
// Created by Lee, Yihung on 1/19/18.
//

#ifndef FANTASY_FILE_SYSTEM_UTILS_HPP
#define FANTASY_FILE_SYSTEM_UTILS_HPP

#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else

#include <unistd.h>
#include <string>
#include <sys/stat.h>

#define GetCurrentDir getcwd
#endif

/**
 *
 * @return current working directory
 */
std::string getCWD() {
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
        return "error";
    }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    return std::string(cCurrentPath);
}

bool is_file_exist(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

#endif //FANTASY_FILE_SYSTEM_UTILS_HPP
