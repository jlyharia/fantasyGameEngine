//
// Created by Yihung Lee on 4/18/20.
//

#ifndef FANTASYGAMEENGINE_MODELTEXTURE_HPP
#define FANTASYGAMEENGINE_MODELTEXTURE_HPP


class ModelTexture {
public:
    ModelTexture(int textureId) : textureId(textureId) {}

    int getTextureId();

private:
    int textureId;
};


#endif //FANTASYGAMEENGINE_MODELTEXTURE_HPP
