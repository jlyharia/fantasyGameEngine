//
// Created by Yihung Lee on 4/18/20.
//

#ifndef FANTASYGAMEENGINE_IMAGELOADER_HPP
#define FANTASYGAMEENGINE_IMAGELOADER_HPP

#include <filesystem>
#include <string>
#include "Image.hpp"

class ImageLoader {
public:
    static std::shared_ptr<Image> loadImg(std::string fileName);

private:
};


#endif //FANTASYGAMEENGINE_IMAGELOADER_HPP
