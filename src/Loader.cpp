//
// Created by Yihung Lee on 4/11/20.
//

#include "Loader.hpp"


/**
	 * Creates a VAO and stores the position data of the vertices into attribute
	 * 0 of the VAO.
	 *
	 * @param positions
	 *            - The 3D positions of each vertex in the geometry (in this
     *            example a quad).
	 * @return The loaded model.
	 */

RawModel Loader::loadToVAO(std::vector<float> positions,
                           std::vector<float> textureCoords,
                           std::vector<unsigned int> indices) {
    int vaoID = createVAO();
    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, 3, positions);
    storeDataInAttributeList(1, 2, textureCoords);
    unbindVAO();
    return RawModel(vaoID, indices.size());
}

/**
 * Deletes all the VAOs and VBOs when the game is closed. VAOs and VBOs are
 * located in video memory.
 */
Loader::~Loader() {
    std::cout << "Destructor of Load is invoked...\n";
    glDeleteVertexArrays(this->vaoList.size(), &this->vaoList[0]);
    glDeleteBuffers(this->vboList.size(), &this->vboList[0]);
    glDeleteTextures(this->textureList.size(), &this->textureList[0]);
}

/**
 * Creates a new VAO and returns its ID. A VAO holds geometry data that we
 * can render and is physically stored in memory on the GPU, so that it can
 * be accessed very quickly during rendering.
 *
 * Like most objects in OpenGL, the new VAO is created using a "gen" method
 * which returns the ID of the new VAO. In order to use the VAO it needs to
 * be made the active VAO. Only one VAO can be active at a time. To make
 * this VAO the active VAO (so that we can store stuff in it) we have to
 * bind it.
 */

GLuint Loader::createVAO() {
    GLuint vaoId[1];
    glGenVertexArrays(1, &vaoId[0]);
    this->vaoList.push_back(vaoId[0]);
    glBindVertexArray(vaoId[0]);
    std::cout << "vao id: " << vaoId[0] << " is generated\n";
    return vaoId[0];
}


void Loader::storeDataInAttributeList(int attributeNumber,
                                      int coordinateSize,
                                      std::vector<float> data) {
    GLuint vboId = 0;
    glGenBuffers(1, &vboId);
    std::cout << "vbo id: " << vboId << " is generated\n";
    this->vboList.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordinateSize,
                          GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Unbinds the VAO after we're finished using it. If we want to edit or use
 * the VAO we would have to bind it again first.
 */

void Loader::unbindVAO() {
    glBindVertexArray(0);
}

void Loader::bindIndicesBuffer(std::vector<unsigned int> indices) {
    GLuint vboId = 0;
    glGenBuffers(1, &vboId);
    std::cout << "vbo id: " << vboId << " is generated\n";
    this->vboList.push_back(vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0],
                 GL_STATIC_DRAW);
}

GLuint Loader::loadTexture(std::string fileName) {

    GLuint textureId;
    glGenTextures(1, &textureId);
    std::cout << "texture id: " << textureId << " is generated\n";
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureId);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Give the image to OpenGL
    auto img = ImageLoader::loadImg(fileName);

//    int width, height, nrChannels;
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char *data = stbi_load(std::filesystem::path("resources/texture/pointillist.bmp").c_str(), &width, &height,
//                                    &nrChannels, 0);
    if (img->getData()) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->getWidth(), img->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, img->getData());
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
//    delete img;
    this->textureList.push_back(textureId);
    return textureId;
}