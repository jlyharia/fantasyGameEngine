//
// Created by Yihung Lee on 6/5/18.
//
#include "AssimpModelLoader.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
//#include <boost/log/trivial.hpp>
#include <iostream>

using namespace std;

MeshV2 AssimpModelLoader::createMesh(std::string filePath) {
//    BOOST_LOG_TRIVIAL(debug) << "model file path:" << filePath;
    Assimp::Importer importer;
    const aiScene *sc = importer.ReadFile(filePath,
                                          aiProcess_Triangulate |
                                          aiProcess_FlipUVs |
                                          aiProcess_JoinIdenticalVertices);
//    BOOST_LOG_TRIVIAL(debug) << "Number of Meshes = " << sc->mNumMeshes;
    std::vector<unsigned int> indexList;
    std::vector<float> vertexList;
    std::vector<float> normalList;
    if (sc->HasMeshes()) {
        aiMesh *aiMesh = *(sc->mMeshes);

//        BOOST_LOG_TRIVIAL(debug) << "Number of Meshes = " << sc->mNumMeshes;
        for (unsigned int i = 0; i < sc->mNumMeshes; ++i) {
            // Faces (index / 3)
//            BOOST_LOG_TRIVIAL(debug) << "Number of Faces = " << aiMesh->mNumFaces;
            for (unsigned int t = 0; t < aiMesh->mNumFaces; ++t) {
                unsigned int *ver = aiMesh->mFaces[t].mIndices;
                indexList.push_back(ver[0]);
                indexList.push_back(ver[1]);
                indexList.push_back(ver[2]);
            }
            if (aiMesh->mNumVertices > 0) {
                // while obj loaded into assimp, they reorganize the content
                // For each set of vertices
                for (unsigned int j = 0; j < aiMesh->mNumVertices; ++j) {
                    // Vertices
                    if (aiMesh->HasPositions()) {
                        auto vert = aiMesh->mVertices[j];
                        vertexList.push_back(vert.x);
                        vertexList.push_back(vert.y);
                        vertexList.push_back(vert.z);
                    }
                    // Normals
                    if (aiMesh->HasNormals()) {
                        auto nor = aiMesh->mNormals[j];
                        normalList.push_back(nor.x);
                        normalList.push_back(nor.y);
                        normalList.push_back(nor.z);
                    }
                }
            }
        }
    } else {
//        BOOST_LOG_TRIVIAL(error) << "Error: No meshes found";
    }
    MeshV2 mesh;
    mesh.setNormalList(normalList);
    mesh.setVertexList(vertexList);
    mesh.setIndexList(indexList);
    return mesh;
}
