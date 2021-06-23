
#include "textures_manager.hpp"


using namespace tool;
using namespace tool::graphics;


bool TexturesManager::load_textures_from_directory(const std::string &directoryPath, std_v1<TextureLoadingInfo> infos){

    for(const auto &info : infos){

        // check alias
        if(textures.count(info.alias) != 0){
            std::cerr << "[TexturesM] Texture alias already used: " << info.alias << "\n";
            continue;
        }

        // check if texture has already been loaded
        const std::string textureFilePath = {directoryPath + "/" + info.fileName};
        if(aliasPerPath.count(textureFilePath) != 0){

            // find previously loaded texture
            textures[info.alias] = textures[aliasPerPath[textureFilePath]];
            std::cout << "[TexturesM] Texture file " << textureFilePath << " has already been loaded with alias" << info.alias << "\n";
            continue;
        }

        // load texture
        auto texture = std::make_shared<graphics::Texture2D>();
        if(!texture->load_2d_image_file_data(textureFilePath, info.flip, info.targetNbChannels)){
            std::cerr << "[TexturesM] Cannot load texture file: " << textureFilePath << "\n";
            return false;
        }

        // add to map
        aliasPerPath[textureFilePath] = info.alias;
        textures[info.alias] = texture;
    }

    return true;
}

bool TexturesManager::load_cube_map(const std::string &basePath, const std_a1<std::string, 6> &extensions, const std::string &alias, bool flip){

    // check alias
    if(cubeMaps.count(alias) != 0){
        std::cerr << "[TexturesM] CubeMap alias already used: " << alias << "\n";
        return false;
    }

    // check if textures have already been loaded
    std_a1<TexturePath, 6> texturesPath;
    for(size_t ii = 0; ii < extensions.size(); ++ii){
        texturesPath[ii] = {basePath + extensions[ii]};
        if(aliasPerPath.count(texturesPath[ii].v) != 0){
            std::cerr << "[TexturesM] Cubemap texture file already loaded: " << texturesPath[ii].v << "\n";
            continue;
        }
    }

    // load cube map
    auto cubeMap = std::make_shared<graphics::CubeMap>();
    if(!cubeMap->load_2d_images_files(texturesPath, flip)){
        std::cerr << "[TexturesM] Cannot load cubemap files. \n";
        return false;
    }

    // add to map
    for(const auto &path : texturesPath){
        aliasPerPath[path.v] = alias;
    }
    cubeMaps[alias] = cubeMap;

    return true;
}

std::weak_ptr<Texture2D> TexturesManager::get_texture(const std::string &textureAlias){
    if(textures.count({textureAlias}) != 0){
        return textures[{textureAlias}];
    }
    return {};
}

Texture2D *TexturesManager::get_texture_ptr(const std::string &textureAlias){
    if(textures.count({textureAlias}) != 0){
        return textures[{textureAlias}].get();
    }
    return nullptr;
}

TextureInfo TexturesManager::get_texture_info(const std::string &textureAlias, TextureOptions options){
    return TextureInfo{get_texture_ptr(textureAlias),options};
}

bool TexturesManager::generate_texture2d_tbo(const std::string &tboAlias, const std::string &textureAlias, TextureOptions options){

    if(textures.count(textureAlias) == 0){
        std::cerr << "[TextureM] Texture alias " << textureAlias << " doesn't exist.\n";
        return false;
    }

    if(TBOs.count(tboAlias) != 0){
        std::cerr << "[TexturesM] TBO alias already used: " << tboAlias << "\n";
        return false;
    }

    tool::gl::Texture2D tbo;
    tbo.load_texture(textures[textureAlias].get(), {options});
    TBOs[tboAlias] = std::move(tbo);

    return true;
}

bool TexturesManager::generate_projected_texture2d_tbo(const std::string &tboAlias, const std::string &textureAlias){

    if(textures.count(textureAlias) == 0){
        std::cerr << "[TextureM] Texture alias " << textureAlias << " doesn't exist.\n";
        return false;
    }

    if(TBOs.count(tboAlias) != 0){
        std::cerr << "[TexturesM] TBO alias already used: " << tboAlias << "\n";
        return false;
    }

    tool::gl::Texture2D tbo;
    tbo.load_projected_texture(textures[textureAlias].get());
    TBOs[tboAlias] = std::move(tbo);

    return true;
}

bool TexturesManager::generate_cubemap_tbo(const std::string &tboAlias, const std::string &cubemapAlias){

    if(cubeMaps.count(cubemapAlias) == 0){
        std::cerr << "[TextureM] Cubemap alias " << cubemapAlias << " doesn't exist.\n";
        return false;
    }

    if(TBOs.count(tboAlias) != 0){
        std::cerr << "[TexturesM] TBO alias already used: " << tboAlias << "\n";
        return false;
    }

    tool::gl::CubeMap tbo;
    tbo.load_textures(&cubeMaps[cubemapAlias]->textures);
    TBOs[tboAlias] = std::move(tbo);

    return true;
}

gl::TBO *TexturesManager::get_tbo(const std::string &tboAlias){
    if(TBOs.count(tboAlias) != 0){
        return &TBOs[tboAlias];
    }
    return nullptr;
}

