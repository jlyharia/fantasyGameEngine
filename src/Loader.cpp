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

RawModel Loader::loadToVAO(std::vector<float> positions) {
    int vaoID = createVAO();
    storeDataInAttributeList(0, positions);
    unbindVAO();
    return RawModel(vaoID, positions.size() / 3);
}

/**
 * Deletes all the VAOs and VBOs when the game is closed. VAOs and VBOs are
 * located in video memory.
 */
Loader::~Loader() {
    std::cout << "Destructor of Load is invoked..\n";
    glDeleteVertexArrays(this->vaoList.size(), &this->vaoList[0]);
    glDeleteBuffers(this->vboList.size(), &this->vboList[0]);
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
 *
 * @return The ID of the newly created VAO.
 */

GLuint Loader::createVAO() {
    GLuint vaoId[1];
    glGenVertexArrays(1, &vaoId[0]);
    this->vaoList.push_back(vaoId[0]);
    glBindVertexArray(vaoId[0]);
    std::cout << "vao id: " << vaoId[0] << " is generated\n";
    return vaoId[0];
}



void Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> data) {
    GLuint vboId = 0;
    glGenBuffers(1, &vboId);
    std::cout << "vbo id: " << vboId << " is generated\n";
    this->vboList.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Unbinds the VAO after we're finished using it. If we want to edit or use
 * the VAO we would have to bind it again first.
 */

void Loader::unbindVAO() {
    glBindVertexArray(0);
}

/**
 * Before we can store data in a VBO it needs to be in a certain format: in
 * a buffer. In this case we will use a float buffer because the data we
 * want to store is float data. If we were storing int data we would use an
 * IntBuffer.
 *
 * First and empty buffer of the correct size is created. You can think of a
 * buffer as basically an array with a pointer. After putting the necessary
 * data into the buffer the pointer will have increased so that it points at
 * the first empty element of the array. This is so that we could add more
 * data to the buffer if we wanted and it wouldn't overwrite the data we've
 * already put in. However, we're done with storing data and we want to make
 * the buffer ready for reading. To do this we need to make the pointer
 * point to the start of the data, so that OpenGL knows where in the buffer
 * to start reading. The "flip()" method does just that, putting the pointer
 * back to the start of the buffer.
 *
 * @param data
 *            - The float data that is going to be stored in the buffer.
 * @return The FloatBuffer containing the data. This float buffer is ready
 *         to be loaded into a VBO.
 */
//FloatBuffer storeDataInFloatBuffer(float[] data) {
//    FloatBuffer buffer = BufferUtils.createFloatBuffer(data.length);
//    buffer.put(data);
//    buffer.flip();
//    return buffer;
//}