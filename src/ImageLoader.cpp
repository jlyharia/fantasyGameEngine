//
// Created by Yihung Lee on 4/18/20.
//

#include "ImageLoader.hpp"


std::shared_ptr<Image> ImageLoader::loadImg(std::string fileName) {
    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(
            std::filesystem::path(fileName).c_str(),
            &width,
            &height,
            &nrChannels,
            0);
    if (!data) {
        std::cout << "Failed to load texture" << std::endl;
    }
    return std::make_shared<Image>(width, height, nrChannels, data);
}