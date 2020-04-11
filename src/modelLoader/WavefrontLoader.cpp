//
// Created by Yihung Lee on 5/30/18.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "WavefrontLoader.hpp"
#include "../VectorUtil.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
//Mesh WavefrontLoader::createMesh() {
//    std::ifstream infile(this->filePath);
//    std::string attr;
//    std::string buf;
//    std::vector<Vertex> vertices;
//    std::vector<unsigned int> indices;
//    std::vector<glm::vec3> defaultNormal;
//    for (std::string line; getline(infile, line);) {
//        Vertex vertex;
//        std::istringstream iss(line);
//        if (line.find("v ") == 0) {
//            // vertex
//            glm::vec3 position;
//            iss >> attr >> position.x >> position.y >> position.z;
//            vertex.setPosition(position);
//        } else if (line.find("vn ") == 0) {
//            // vertex normal
//            glm::vec3 nor;
//            iss >> attr >> nor.x >> nor.y >> nor.z;
//            defaultNormal.push_back(nor);
//
//        } else if (line.find("vt ") == 0) {
//            // texture coord
//            glm::vec3 nor;
//            iss >> attr >> nor.x >> nor.y >> nor.z;
//            defaultNormal.push_back(nor);
//        } else if (line.find("f ") == 0) {
//            // face
//            iss >> attr;
//            std::vector<std::string> fields;
//            for (int i = 0; i < 3; i++) {
//                iss >> buf;
//                boost::split(fields, buf, boost::is_any_of("/"));
//
//                // vertex index
//                auto idx = boost::lexical_cast<unsigned int>(fields[0]);
//                indices.push_back(this->zeroIndex ? --idx : idx);
//
//                // vertex normal index
//                auto vecNorIdx = boost::lexical_cast<unsigned int>(fields[2]);
//                vertices[idx].setNormal(defaultNormal[this->zeroIndex ? --vecNorIdx : vecNorIdx]);
//            }
//        } else {
//            continue;
//        }
//        vertices.push_back(vertex);
//    }
//    return Mesh(vertices, indices);
//}
//Mesh WavefrontLoader::createMesh() {
//    std::ifstream infile(this->filePath);
//    std::string attr;
//    std::string buf;
//    std::vector<Vertex> vertices;
//    std::vector<unsigned int> indices;
//    std::vector<glm::vec3> defaultNormal;
//    for (std::string line; getline(infile, line);) {
//        Vertex vertex;
//        std::istringstream iss(line);
//        if (line.find("v ") == 0) {
//            // vertex
//            glm::vec3 position;
//            iss >> attr >> position.x >> position.y >> position.z;
//            vertex.setPosition(position);
//        } else if (line.find("vn ") == 0) {
//            // vertex normal
//            glm::vec3 nor;
//            iss >> attr >> nor.x >> nor.y >> nor.z;
//            defaultNormal.push_back(nor);
//
//        } else if (line.find("vt ") == 0) {
//            // texture coord
//            glm::vec3 nor;
//            iss >> attr >> nor.x >> nor.y >> nor.z;
//            defaultNormal.push_back(nor);
//        } else if (line.find("f ") == 0) {
//            // face
//            iss >> attr;
//            std::vector<std::string> fields;
//            for (int i = 0; i < 3; i++) {
//                iss >> buf;
//                boost::split(fields, buf, boost::is_any_of("/"));
//
//                // vertex index
//                auto idx = boost::lexical_cast<unsigned int>(fields[0]);
//                indices.push_back(this->zeroIndex ? --idx : idx);
//
//                // vertex normal index
//                auto vecNorIdx = boost::lexical_cast<unsigned int>(fields[2]);
//                vertices[idx].setNormal(defaultNormal[this->zeroIndex ? --vecNorIdx : vecNorIdx]);
//            }
//        } else {
//            continue;
//        }
//        vertices.push_back(vertex);
//    }
//    return Mesh(vertices, indices);
//}