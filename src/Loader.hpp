//
// Created by Yihung Lee on 4/11/20.
//

#ifndef FANTASYGAMEENGINE_LOADER_HPP
#define FANTASYGAMEENGINE_LOADER_HPP

#include <GL/glew.h>
#include <OpenGL/OpenGL.h>
#include <vector>
#include "RawModel.hpp"
#include <iostream>

class Loader {

public:
    ~Loader();

    RawModel loadToVAO(std::vector<float> positions, std::vector<unsigned int> indices);

    void unbindVAO();

    /**
 * Stores the position data of the vertices into attribute 0 of the VAO. To
 * do this the positions must first be stored in a VBO. You can simply think
 * of a VBO as an array of data that is stored in memory on the GPU for easy
 * access during rendering.
 *
 * Just like with the VAO, we create a new VBO using a "gen" method, and
 * make it the active VBO (so that we do stuff to it) by binding it.
 *
 * We then store the positions data in the active VBO by using the
 * glBufferData method. We also indicate using GL_STATIC_DRAW that this data
 * won't need to be changed. If we wanted to edit the positions every frame
 * (perhaps to animate the quad) then we would use GL_DYNAMIC_DRAW instead.
 *
 * We the connect the VBO to the VAO using the glVertexAttribPointer()
 * method. This needs to know the attribute number of the VAO where we want
 * to put the data, the number of floats used for each vertex (3 floats in
 * this case, because each vertex has a 3D position, an x, y, and z value),
 * the type of data (in this case we used floats) and then some other more
 * complicated stuff for storing the data in more fancy ways. Don't worry
 * about the last 3 parameters for now, we don't need them here.
 *
 * Now that we've finished using the VBO we can unbind it. This isn't
 * totally necessary, but I think it's good practice to unbind the VBO when
 * you're done using it.
 *
 * @param attributeNumber
 *            - The number of the attribute of the VAO where the data is to
 *            be stored.
 * @param data
 *            - The geometry data to be stored in the VAO, in this case the
 *            positions of the vertices.
 */
    void storeDataInAttributeList(int attributeNumber, std::vector<float> data);

private:
    std::vector<GLuint> vaoList;
    std::vector<GLuint> vboList;


    GLuint createVAO();

    void bindIndicesBuffer(std::vector<unsigned int> indices);
};


#endif //FANTASYGAMEENGINE_LOADER_HPP
