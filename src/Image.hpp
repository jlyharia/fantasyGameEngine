//
// Created by Yihung Lee on 4/18/20.
//

#ifndef FANTASYGAMEENGINE_IMAGE_HPP
#define FANTASYGAMEENGINE_IMAGE_HPP

#include <iostream>

#include "stb_image.h"

class Image {
public:
    Image(int width, int height, unsigned char *data) :
            width(width), height(height), data(data) {};

    int getHeight();

    int getWidth();

    unsigned char *getData();

    virtual ~Image();

private:
    int width;
    int height;
    unsigned char *data;
};


#endif //FANTASYGAMEENGINE_IMAGE_HPP
