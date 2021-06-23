
/*******************************************************************************
** Toolbox-base                                                               **
** MIT License                                                                **
** Copyright (c) [2018] [Florian Lance]                                       **
**                                                                            **
** Permission is hereby granted, free of charge, to any person obtaining a    **
** copy of this software and associated documentation files (the "Software"), **
** to deal in the Software without restriction, including without limitation  **
** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
** and/or sell copies of the Software, and to permit persons to whom the      **
** Software is furnished to do so, subject to the following conditions:       **
**                                                                            **
** The above copyright notice and this permission notice shall be included in **
** all copies or substantial portions of the Software.                        **
**                                                                            **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
** DEALINGS IN THE SOFTWARE.                                                  **
**                                                                            **
********************************************************************************/


#include "assimp_loader.hpp"

// std
#include <filesystem>
#include <algorithm>

// assimp
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

using namespace tool::geo;
using namespace tool::files;

//Texture2D *AiLoader::read_texture(Model *model, aiMaterial *mat, aiTextureType type, unsigned int index){

//    // ai data
//    aiString path;              // receives the path to the texture. If the texture is embedded, receives a '*' followed by the id of the texture
//    // (for the textures stored in the corresponding scene) which can be converted to an int using a function like atoi. NULL is a valid value
//    aiTextureMapping mapping;   // texture mapping, NULL is allowed as value
//    unsigned int uvIndex;       // uv index of the texture (NULL is valid value)
//    ai_real blend;              // blend factor for the texture
//    aiTextureOp operation;      // texture operation to be performed between this texture and the previous texture
//    aiTextureMapMode mapMode[3];// mapping modes to be used for the texture, the parameter may be NULL but if it is a valid pointer it MUST
//    // point to an array of 3 aiTextureMapMode's (one for each axis: UVW order (=XYZ)).
//    mat->GetTexture(type, index, &path, &mapping, &uvIndex, &blend, &operation, &mapMode[0]);

//    //  auto wrapping     = read_texture_property<int>(MatP::text_mapping, aiMat, texturesPerType.first, ii).value();
//    //  auto uvwSource    = read_texture_property<int>(MatP::text_uvw_source, aiMat, texturesPerType.first, ii).value();
//    //  auto mappingModeU = read_texture_property<int>(MatP::text_mapping_mode_u, aiMat, texturesPerType.first, ii).value();
//    //  auto mappingModeV = read_texture_property<int>(MatP::text_mapping_mode_v, aiMat, texturesPerType.first, ii).value();
//    //  auto flags        = read_texture_property<int>(MatP::text_flags, aiMat, texturesPerType.first, ii).value();
//    //  auto texmapAxis   = read_texture_property<aiVector3D>(MatP::text_texmap_axis, aiMat, texturesPerType.first, ii).value();
//    //  auto blend        = read_texture_property<float>(MatP::text_blend, aiMat, texturesPerType.first, ii).value();

//    // find texture
//    namespace fs = std::filesystem;


//    const std::string aiPath = path.C_Str();
//    if(aiPath.length() > 0){
//        if(aiPath[0] == '*'){
//            std::cout << "[ASSIMP_LOADER] Embedded texture detected, not managed yet\n";
//            return nullptr;
//        }
//    }

//    fs::path texturePath = aiPath;
//    if(!fs::exists(texturePath)){ // check if full path exist

//        fs::path dirPath = model->directory;

//        std_v1<fs::path> pathsToTest;
//        pathsToTest.emplace_back(dirPath / texturePath.filename());
//        pathsToTest.emplace_back(dirPath / "texture" / texturePath.filename());
//        pathsToTest.emplace_back(dirPath / "textures" / texturePath.filename());
//        pathsToTest.emplace_back(dirPath / ".." / "texture" / texturePath.filename());
//        pathsToTest.emplace_back(dirPath / ".." / "textures" / texturePath.filename());

//        bool found = false;
//        for(const auto &pathToTest : pathsToTest){
//            if(fs::exists(pathToTest)){
//                found = true;
//                texturePath = pathToTest;
//                break;
//            }
//        }

//        if(!found){
//            std::cerr << "[ASSIMP_LOADER] Cannot find texture " << texturePath.filename() << "\n";
//            return nullptr;
//        }
//    }


//    std::string foundPath = texturePath.u8string();


//    auto textures = &model->m_textures;
//    if(textures->count(foundPath) == 0){

//        // load texture
//        Texture2D texture(foundPath);

//        // type
//        texture.type = get_texture_type(type);

//        // mapping
//        texture.mapping   = get_texture_mapping(mapping);

//        // operation
//        texture.operation = get_texture_operation(operation);

//        // mapMode
//        texture.mapMode   = Pt3<TexMapMode>{get_texture_map_mode(mapMode[0]),get_texture_map_mode(mapMode[1]),get_texture_map_mode(mapMode[2])};


//        // add texture to model
//        (*textures)[foundPath] = std::move(texture);
//    }

//    return &(*textures)[foundPath];
//}

std::shared_ptr<Model> AiLoader::load_model(std::string path, bool verbose){

    if(verbose){
        std::cout << "[ASSIMP_LOADER] Load model with path: " << path << "\n";
    }

    namespace fs = std::filesystem;
    fs::path pathModel = path;
    if(!fs::exists(pathModel)){
//        throw std::runtime_error("[ASSIMP_LOADER] Path " + path + " doesn't exists, cannot load model.\n");
        std::cerr << "[ASSIMP_LOADER] Path " << path << " doesn't exists, cannot load model.\n";
        return nullptr;
    }

    // read from assimp
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate); // aiProcess_EmbedTextures / aiProcess_FlipUVs
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cerr << "[ASSIMP_LOADER] " << import.GetErrorString() << "\n";
        return nullptr;
    }

    // create model
    auto model       = std::make_shared<Model>();
    model->directory = pathModel.parent_path().string();
    model->name      = scene->mRootNode->mName.C_Str();

    if(verbose){
        std::cout << "[ASSIMP_LOADER] Model name: " << model->name << "\n";
    }

    // retrieve global inverse transform
    model->globalInverseTr = scene->mRootNode->mTransformation;
    model->globalInverseTr.Inverse();

    auto m = scene->mRootNode->mTransformation;
    m.Inverse();

    model->globalInverseTr2 = geo::Mat4f{
        m.a1,m.a2,m.a3,m.a4,
        m.b1,m.b2,m.b3,m.b4,
        m.c1,m.c2,m.c3,m.c4,
        m.d1,m.d2,m.d3,m.d4,
    };

//    aiVector3t<float> aiTr,aiRot,aiSc;
//    m_GlobalInverseTransform.Decompose(aiSc,aiRot,aiTr);



//    auto r = geo::Pt3f{aiRot.x,aiRot.y,aiRot.z};
//    model->globalInverseTr = geo::Mat4f::transform(
//        geo::Pt3f{aiSc.x,aiSc.y,aiSc.z},
//        geo::Pt3f{rad_2_deg(r.x()),rad_2_deg(r.y()),rad_2_deg(r.z())},
//        geo::Pt3f{aiTr.x,aiTr.y,aiTr.z}
//    );
//    std::cout << "GLOBAL INVERSE:\n " <<geo::Pt3f{aiSc.x,aiSc.y,aiSc.z} << " " <<  geo::Pt3f{rad_2_deg(r.x()),rad_2_deg(r.y()),rad_2_deg(r.z())} << " "<< geo::Pt3f{aiTr.x,aiTr.y,aiTr.z}  << "\n";


//    // read embedded textures // EMBEDDED
//    if(scene->HasTextures()){
//        for(size_t ii = 0; ii < scene->mNumTextures; ++ii){

//            auto aiTexture = scene->mTextures[ii];
//            std::string file = aiTexture->mFilename.C_Str();
//            std::cout << "embedded texture " << ii <<  " " << file << " " << aiTexture->mWidth << " " << aiTexture->mHeight << "\n";

//            for(size_t jj = 0; jj < aiTexture->mWidth * aiTexture->mHeight; ++jj){

//                aiTexture->pcData->r;
//                aiTexture->pcData->g;
//                aiTexture->pcData->b;
//                aiTexture->pcData->a;
//            }

//        }
//    }


    // retrieve materials
    if(scene->HasMaterials()){

        if(verbose){
            std::cout << "[ASSIMP_LOADER] Load materials: " << scene->mNumMaterials << "\n";
        }

        for(size_t ii = 0; ii < scene->mNumMaterials; ++ii){
            read_material(model.get(), scene->mMaterials[ii]);
        }
    }


    // retrieve meshes
    if(scene->HasMeshes()){

        if(verbose){
            std::cout << "[ASSIMP_LOADER] Load meshes: " << scene->mNumMeshes << "\n";
        }

        for(size_t ii = 0; ii < scene->mNumMeshes; ++ii){
            if(verbose){
                std::cout << "[ASSIMP_LOADER] Mesh: " << scene->mMeshes[ii]->mName.C_Str() << "\n";
            }
            read_mesh(model.get(), scene->mMeshes[ii]);
        }
    }

    // retrieve animations
    if(scene->HasAnimations()){

        if(verbose){
            std::cout << "[ASSIMP_LOADER] Load animations: " << scene->mNumAnimations << "\n";
        }

        for(size_t ii = 0; ii < scene->mNumAnimations; ++ii){

            if(verbose){
                std::cout << "[ASSIMP_LOADER] Animation: " << scene->mAnimations[ii]->mName.C_Str() << "\n";
            }

            auto assimpAnimation = scene->mAnimations[ii];
            graphics::Animation animation;
            animation.duration = assimpAnimation->mDuration;
            animation.ticksPerSecond = assimpAnimation->mTicksPerSecond;
            animation.name =  assimpAnimation->mName.C_Str();

            for(size_t jj = 0; jj < assimpAnimation->mNumChannels; ++jj){

                auto assimpChannel = assimpAnimation->mChannels[jj];
                const std::string affectedNodeName = assimpChannel->mNodeName.C_Str();

                tool::graphics::AnimationKeys keys;
                keys.positionTimes.resize(assimpChannel->mNumPositionKeys);
                keys.positionKeys.resize(assimpChannel->mNumPositionKeys);
                for(size_t kk = 0; kk < keys.positionTimes.size(); ++kk){
                    auto &key = assimpChannel->mPositionKeys[kk];
                    keys.positionTimes[kk] = key.mTime;
                    keys.positionKeys[kk]  = {key.mValue.x,key.mValue.y,key.mValue.z};
                }

                keys.rotationTimes.resize(assimpChannel->mNumRotationKeys);
                keys.rotationKeys.resize(assimpChannel->mNumRotationKeys);
                for(size_t kk = 0; kk < keys.rotationTimes.size(); ++kk){
                    auto &key = assimpChannel->mRotationKeys[kk];
                    keys.rotationTimes[kk] = key.mTime;
                    keys.rotationKeys[kk]  = {key.mValue.x,key.mValue.y,key.mValue.z, key.mValue.w};
                }

                keys.scalingTimes.resize(assimpChannel->mNumScalingKeys);
                keys.scalingKeys.resize(assimpChannel->mNumScalingKeys);
                for(size_t kk = 0; kk < keys.scalingTimes.size(); ++kk){
                    auto &key = assimpChannel->mScalingKeys[kk];
                    keys.scalingTimes[kk] = key.mTime;
                    keys.scalingKeys[kk]  = {key.mValue.x,key.mValue.y,key.mValue.z};
                }

                model->animationsKeys[animation.name][affectedNodeName] = std::move(keys);
            }


            model->animations.emplace_back(std::move(animation));
        }
    }

    // bones
    read_bones_hierarchy(&model->bonesHierachy, scene->mRootNode);

    return model;
}


void AiLoader::read_mesh(Model *model, aiMesh *aiMesh){

    bool verbose = false;

    auto gmesh = std::make_shared<GMesh>();
    gmesh->name = aiMesh->mName.C_Str();
    gmesh->material = &model->m_materials[aiMesh->mMaterialIndex];

    Mesh *mesh = &gmesh->mesh;

    bool hasPoints    = aiMesh->mPrimitiveTypes & aiPrimitiveType::aiPrimitiveType_POINT;
    bool hasLines     = aiMesh->mPrimitiveTypes & aiPrimitiveType::aiPrimitiveType_LINE;
    bool hasTriangles = aiMesh->mPrimitiveTypes & aiPrimitiveType::aiPrimitiveType_TRIANGLE;
    bool hasPolygons  = aiMesh->mPrimitiveTypes & aiPrimitiveType::aiPrimitiveType_POLYGON;

    // process vertex positions, normals and texture coordinates
    mesh->vertices.reserve(aiMesh->mNumVertices);
    if(aiMesh->HasNormals()){
        mesh->normals.reserve(aiMesh->mNumVertices);
    }

    if(aiMesh->HasTextureCoords(0)){
        mesh->tCoords.reserve(aiMesh->mNumVertices);
    }else{
        mesh->tCoords.resize(aiMesh->mNumVertices);
        std::fill(std::begin(mesh->tCoords), std::end(mesh->tCoords), Pt2f{0.f,0.f});
    }

    if(aiMesh->HasTangentsAndBitangents()){
        mesh->tangents.resize(aiMesh->mNumVertices);
    }

    if(aiMesh->HasVertexColors(0)){
        mesh->colors.reserve(aiMesh->mNumVertices);
    }

    if(aiMesh->HasBones()){
        mesh->bones.resize(aiMesh->mNumVertices);
    }

    for(unsigned int ii = 0; ii < aiMesh->mNumVertices; ii++){

        // position
        mesh->vertices.emplace_back(Pt3f{aiMesh->mVertices[ii].x, aiMesh->mVertices[ii].y, aiMesh->mVertices[ii].z});

        // normal
        if(aiMesh->HasNormals()){
            mesh->normals.emplace_back(Vec3f{aiMesh->mNormals[ii].x,  aiMesh->mNormals[ii].y,  aiMesh->mNormals[ii].z});
        }

        // uv
        // aiMesh->GetNumUVChannels()
        if(aiMesh->HasTextureCoords(0)){
            mesh->tCoords.emplace_back(Pt2f{aiMesh->mTextureCoords[0][ii].x,  aiMesh->mTextureCoords[0][ii].y});
        }

        // tangents
        if(aiMesh->HasTangentsAndBitangents()){
            mesh->tangents.emplace_back(Pt4f{aiMesh->mTangents->x,aiMesh->mTangents->y,aiMesh->mTangents->z,1.f});
        }

        // colors
        // aiMesh->GetNumColorChannels()
        if(aiMesh->HasVertexColors(0)){
            mesh->colors.emplace_back(Pt4f{
                aiMesh->mColors[0][ii].r,
                aiMesh->mColors[0][ii].g,
                aiMesh->mColors[0][ii].b,
                aiMesh->mColors[0][ii].a
            });
        }

        // aiMesh->mBitangents
        // aiMesh->mMethod
        // aiMesh->mAnimMeshes
    }

    // process indices
    if(hasTriangles && !hasPoints && !hasLines && !hasPolygons){

        mesh->triIds.reserve(aiMesh->mNumFaces);

        for(unsigned int ii = 0; ii < aiMesh->mNumFaces; ii++){
            aiFace face = aiMesh->mFaces[ii];
            mesh->triIds.emplace_back(TriIds{face.mIndices[0], face.mIndices[1], face.mIndices[2]});
        }

    }else{
        std::cerr << "[ASSIMP_LOADER] Face format not managed.\n";
    }

    // compute normals if necessary
    if(!aiMesh->HasNormals()){
        mesh->generate_normals();
    }

    // generate tangents if necessary
    if(!aiMesh->HasTangentsAndBitangents() && (mesh->normals.size() > 0) && aiMesh->HasTextureCoords(0)){
        mesh->generate_tangents();
    }

//    if(mesh->tangents.size() != mesh->vertices.size()){
//        std::cout << "[ASSIMP_LOADER] Invalid tangents. Recomputing.\n";
//        mesh->generate_tangents();
//    }

    // bones
    if(aiMesh->HasBones()){


//        for (uint i = 0 ; i < pMesh->mNumBones ; i++) {
//            uint BoneIndex = 0;
//            string BoneName(pMesh->mBones[i]->mName.data);

//            if (m_BoneMapping.find(BoneName) == m_BoneMapping.end()) {
//                BoneIndex = m_NumBones;
//                m_NumBones++;
//                BoneInfo bi;
//                m_BoneInfo.push_back(bi);
//            }
//            else {
//                BoneIndex = m_BoneMapping[BoneName];
//            }

//            m_BoneMapping[BoneName] = BoneIndex;
//            m_BoneInfo[BoneIndex].BoneOffset = pMesh->mBones[i]->mOffsetMatrix;

//            for (uint j = 0 ; j < pMesh->mBones[i]->mNumWeights ; j++) {
//                uint VertexID = m_Entries[MeshIndex].BaseVertex + pMesh->mBones[i]->mWeights[j].mVertexId;
//                float Weight = pMesh->mBones[i]->mWeights[j].mWeight;
//                Bones[VertexID].AddBoneData(BoneIndex, Weight);
//            }
//        }

        if(verbose){
            std::cout << "Num bones: " << aiMesh->mNumBones << "\n";
        }

        for(size_t ii = 0; ii < aiMesh->mNumBones; ++ii){

            unsigned int boneIndex = 0;
            auto bone = aiMesh->mBones[ii];
            std::string boneName(bone->mName.C_Str());

            if(verbose){
                std::cout << "Bone: " << boneName << "\n";
            }


            if(model->bonesMapping.count(boneName) == 0){

                boneIndex = static_cast<unsigned int>(model->bonesMapping.size());
                model->bonesInfo.emplace_back(graphics::BoneInfo{});
//                model->bonesMapping[boneName] = boneIndex;

                if(verbose){
                    std::cout << "Add bone in mapping, current index: " << boneIndex << " " <<  model->bonesMapping.size() << "\n";
                }
            }else{
                boneIndex = model->bonesMapping[boneName];


                if(verbose){
                    std::cout << "Bone already in mapping at index: " << boneIndex << "\n";
                }
            }

            model->bonesMapping[boneName] = boneIndex;

            model->bonesInfo[boneIndex].offset = bone->mOffsetMatrix;

//            model->bonesInfo[boneIndex].offset = geo::Mat4f
//            {
//                m.a1,m.a2,m.a3,m.a4,
//                m.b1,m.b2,m.b3,m.b4,
//                m.c1,m.c2,m.c3,m.c4,
//                m.d1,m.d2,m.d3,m.d4,
//            };

//            // bone offset
//            // # decompose
//            aiVector3t<float> aiTr,aiRot,aiSc;
//            bone->mOffsetMatrix.Decompose(aiSc,aiRot,aiTr);
//            // # create offset transform
//            auto r = geo::Pt3f{aiRot.x,aiRot.y,aiRot.z};
//            model->bonesInfo[boneIndex].offset = geo::Mat4f::transform(
//                geo::Pt3f{aiSc.x,aiSc.y,aiSc.z},
//                geo::Pt3f{rad_2_deg(r.x()),rad_2_deg(r.y()),rad_2_deg(r.z())},
////                geo::Pt3f{(r.x()),(r.y()),(r.z())},
//                geo::Pt3f{aiTr.x,aiTr.y,aiTr.z}
//            );

            if(verbose){
                std::cout << "Num weights: " << bone->mNumWeights << "\n";
            }
            for (size_t jj = 0 ; jj < bone->mNumWeights; jj++) {
                unsigned int VertexId = bone->mWeights[jj].mVertexId;
                float Weight = bone->mWeights[jj].mWeight;
                mesh->bones[VertexId].add_bone_data(boneIndex, Weight);
            }            
        }
    }

    model->gmeshes.emplace_back(std::move(gmesh));
}

void AiLoader::read_material(Model *model, aiMaterial *aiMat){

    using MatP = Material::Property;

    // read properties
    Material material;
    // # str
    material.name               = to_string(read_property<aiString>(MatP::name, aiMat));
    // # int
    material.backfaceCulling    = read_property<int>(MatP::twosided, aiMat).value() != 0;
    material.wireframe          = read_property<int>(MatP::enable_wireframe, aiMat).value() != 0;
    // # float
    material.opacity            = read_property<float>(MatP::opacity, aiMat).value();
    material.shininess          = read_property<float>(MatP::shininess, aiMat).value();
    material.shininessStrength  = read_property<float>(MatP::shininess_strength, aiMat).value();
    material.refraction         = read_property<float>(MatP::refacti, aiMat).value();
    material.reflectivity       = read_property<float>(MatP::reflectivity, aiMat).value();
    // # point3f
    material.ambiantColor       = to_color(read_property<aiColor3D>(MatP::color_ambient,      aiMat));
    material.diffuseColor       = to_color(read_property<aiColor3D>(MatP::color_diffuse,      aiMat));
    material.specularColor      = to_color(read_property<aiColor3D>(MatP::color_specular,     aiMat));
    material.emissiveColor      = to_color(read_property<aiColor3D>(MatP::color_emissive,     aiMat));
    material.transparentColor   = to_color(read_property<aiColor3D>(MatP::color_transparent,  aiMat));
    material.reflectiveColor    = to_color(read_property<aiColor3D>(MatP::color_reflective,   aiMat));
    // mat.mNumAllocated;
    // mat.mNumProperties;

    // read textures
    for(const auto &type : textureTypes.data){
        for(unsigned int ii = 0; ii < aiMat->GetTextureCount(std::get<1>(type)); ++ii){

            // ai data
            aiString path;              // receives the path to the texture. If the texture is embedded, receives a '*' followed by the id of the texture
                                        // (for the textures stored in the corresponding scene) which can be converted to an int using a function like atoi. NULL is a valid value
            aiTextureMapping mapping = aiTextureMapping_UV; // texture mapping, NULL is allowed as value
            unsigned int uvIndex;       // uv index of the texture (NULL is valid value)
            ai_real blend;              // blend factor for the texture
            aiTextureOp operation = aiTextureOp_Multiply;// texture operation to be performed between this texture and the previous texture
            aiTextureMapMode mapMode[3];// mapping modes to be used for the texture, the parameter may be NULL but if it is a valid pointer it MUST
            aiMat->GetTexture(std::get<1>(type), ii, &path, &mapping, &uvIndex, &blend, &operation, &mapMode[0]);

            if(auto pathTexture = retrieve_texture_path(model, path);  pathTexture.has_value()){

                Texture2D *texture = nullptr;
                if(model->m_textures.count(pathTexture.value()) == 0){ // add texture
                    model->m_textures[pathTexture.value()] = Texture2D(pathTexture.value());
                }
                texture = &model->m_textures[pathTexture.value()];

                TextureInfo textureInfo;
                textureInfo.texture             = texture;
                textureInfo.options.type        = std::get<0>(type);
                textureInfo.options.mapping     = get_texture_mapping(mapping);
                textureInfo.options.operation   = get_texture_operation(operation);
                textureInfo.options.mapMode     = Pt3<TextureMapMode>{
                    get_texture_map_mode(mapMode[0]),
                    get_texture_map_mode(mapMode[1]),
                    get_texture_map_mode(mapMode[2])
                };

                // others textures info
                auto wrapping     = read_texture_property<int>(MatP::text_mapping,              aiMat, textureInfo.options.type, ii).value();
                auto uvwSource    = read_texture_property<int>(MatP::text_uvw_source,           aiMat, textureInfo.options.type, ii).value();
                auto mappingModeU = read_texture_property<int>(MatP::text_mapping_mode_u,       aiMat, textureInfo.options.type, ii).value();
                auto mappingModeV = read_texture_property<int>(MatP::text_mapping_mode_v,       aiMat, textureInfo.options.type, ii).value();
                auto flags        = read_texture_property<int>(MatP::text_flags,                aiMat, textureInfo.options.type, ii).value();
                auto texmapAxis   = read_texture_property<aiVector3D>(MatP::text_texmap_axis,   aiMat, textureInfo.options.type, ii).value();
                auto blend        = read_texture_property<float>(MatP::text_blend,              aiMat, textureInfo.options.type, ii).value();

                static_cast<void>(wrapping);
                static_cast<void>(uvwSource);
                static_cast<void>(mappingModeU);
                static_cast<void>(mappingModeV);
                static_cast<void>(flags);
                static_cast<void>(texmapAxis);
                static_cast<void>(blend);
//                name,twosided,shading_model,enable_wireframe,blend_func,opacity, bumpscaling, shininess, reflectivity,
//                shininess_strength, refacti, color_diffuse, color_ambient, color_specular, color_emissive, color_transparent,
//                color_reflective, global_background_image,
//                text_blend, text_mapping, text_operation, text_uvw_source,
//                text_mapping_mode_u, text_mapping_mode_v,
//                text_texmap_axis, text_flags,

                // add infos
                material.texturesInfo[textureInfo.options.type].emplace_back(std::move(textureInfo));
            }
        }
    }

    model->m_materials.emplace_back(std::move(material));
}



std::optional<std::string> AiLoader::retrieve_texture_path(Model *model, const aiString &aiPath){

    const std::string path = aiPath.C_Str();
    if(path.length() >  0){
        if(path[0] == '*'){
            std::cout << "[ASSIMP_LOADER] Embedded texture detected, not managed yet\n";
            return {};
        }
    }

    namespace fs = std::filesystem;
    fs::path texturePath = path;

    std::error_code code;
    if(!fs::exists(texturePath,code)){ // check if full path exist

        fs::path dirPath = model->directory;

        std_v1<fs::path> pathsToTest;
        pathsToTest.emplace_back(dirPath / texturePath.filename());
        pathsToTest.emplace_back(dirPath / "texture" / texturePath.filename());
        pathsToTest.emplace_back(dirPath / "textures" / texturePath.filename());
        pathsToTest.emplace_back(dirPath / ".." / "texture" / texturePath.filename());
        pathsToTest.emplace_back(dirPath / ".." / "textures" / texturePath.filename());

        bool found = false;
        for(const auto &pathToTest : pathsToTest){
            if(fs::exists(pathToTest)){
                found = true;
                texturePath = pathToTest;
                break;
            }
        }

        if(!found){
            std::cerr << "[ASSIMP_LOADER] Cannot find texture " << texturePath.filename() << "\n";
            return {};
        }
    }

    // found path
    return texturePath.string();
}

void AiLoader::read_bones_hierarchy(tool::graphics::BonesHierarchy *bones, aiNode *node){

    bones->boneName = node->mName.C_Str();

    // set transform
//    const auto &m = node->mTransformation;
//    aiVector3t<float> aiTr,aiRot,aiSc;
//    node->mTransformation.Decompose(aiSc,aiRot,aiTr);
//    auto r = geo::Pt3f{aiRot.x,aiRot.y,aiRot.z};
//    bones->tr = geo::Mat4f::transform(
//        geo::Pt3f{aiSc.x,aiSc.y,aiSc.z},
//        geo::Pt3f{rad_2_deg(r.x()),rad_2_deg(r.y()),rad_2_deg(r.z())},
////        geo::Pt3f{(r.x()),(r.y()),(r.z())},
//        geo::Pt3f{aiTr.x,aiTr.y,aiTr.z}
//    );

    bones->tr = node->mTransformation;
//    const auto &m = node->mTransformation;//.Transpose();
//    bones->tr = geo::Mat4f
//    {
//        m.a1,m.a2,m.a3,m.a4,
//        m.b1,m.b2,m.b3,m.b4,
//        m.c1,m.c2,m.c3,m.c4,
//        m.d1,m.d2,m.d3,m.d4,
//    };


//    std::cout << "TR: " << geo::Pt3f{aiSc.x,aiSc.y,aiSc.z} << " " << geo::Pt3f{rad_2_deg(r.x()),rad_2_deg(r.y()),rad_2_deg(r.z())} << " " << geo::Pt3f{aiTr.x,aiTr.y,aiTr.z} << "\n";

    for(size_t ii = 0; ii < node->mNumChildren; ++ii){
        graphics::BonesHierarchy bh;
        read_bones_hierarchy(&bh, node->mChildren[ii]);
        bones->children.emplace_back(std::move(bh));
    }
}
