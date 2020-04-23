//
// Created by Yihung Lee on 4/18/20.
//

#include "Image.hpp"


int Image::getHeight() {
    return this->height;
}

int Image::getWidth() {
    return this->width;
}

unsigned char *Image::getData() {
    return this->data;
}

Image::~Image() {
    stbi_image_free(data);
    std::cout << "Destructor of Image is Invoked...\n";
}
