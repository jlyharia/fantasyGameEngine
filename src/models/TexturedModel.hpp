//
// Created by Yihung Lee on 4/18/20.
//

#ifndef FANTASYGAMEENGINE_TEXTUREDMODEL_HPP
#define FANTASYGAMEENGINE_TEXTUREDMODEL_HPP


#include "RawModel.hpp"
#include "../texture/ModelTexture.hpp"

class TexturedModel {
public:
    TexturedModel(RawModel rawModel, ModelTexture modelTexture) :
            rawModel(rawModel), modelTexture(modelTexture) {};

    RawModel getRawModel();

    ModelTexture getModelTexture();

private:
    RawModel rawModel;
    ModelTexture modelTexture;
};


#endif //FANTASYGAMEENGINE_TEXTUREDMODEL_HPP
