//
// Created by Yihung Lee on 10/31/17.
//
#define BOOST_LOG_DYN_LINK 1

#include "gtest/gtest.h"
#include "../src/modelLoader/AssimpModelLoader.hpp"
#include <boost/log/trivial.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;


TEST (Assimp, mesh) {
//    BOOST_LOG_TRIVIAL(debug) << "C++ version: " << __cplusplus;
//    std::string path = "../../geometric_data/cube.obj";
    std::string pfile = "../../geometric_data/cube.obj";
    const MeshV2 &mesh = AssimpModelLoader::createMesh(pfile);

    auto vec = mesh.getVertexList();
    for (int i = 0; i < vec.size(); i += 3) {
        cout << vec[i] << " " << vec[i + 1] << " " << vec[i + 2] << endl;
    }

    auto nor = mesh.getNormalList();
    for (int i = 0; i < nor.size(); i += 3) {
        cout << nor[i] << " " << nor[i + 1] << " " << nor[i + 2] << endl;
    }

    auto idx = mesh.getIndexList();
    for (int i = 0; i < idx.size(); i += 3) {
        cout << idx[i] << " " << idx[i + 1] << " " << idx[i + 2] << endl;
    }
}