
/*******************************************************************************
** Toolbox-3d-engine                                                          **
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

#pragma once

// opengl-utlity
#include "opengl/gl_texture.hpp"

namespace tool::graphics {

struct TextureLoadingInfo{
    std::string alias;
    std::string fileName;
    bool flip = true;
    int targetNbChannels = 4;
};

class TexturesManager{

public:

    bool load_textures_from_directory(const std::string &directoryPath, std_v1<TextureLoadingInfo> infos);
    bool load_cube_map(const std::string &basePath, const std_a1<std::string,6> &extensions, const std::string &alias, bool flip = true);

    std::weak_ptr<Texture2D> get_texture(const std::string &textureAlias);
    Texture2D* get_texture_ptr(const std::string &textureAlias);
    TextureInfo get_texture_info(const std::string &textureAlias, TextureOptions options = {});

    bool generate_texture2d_tbo(const std::string &tboAlias, const std::string &textureAlias, TextureOptions options = {});
    bool generate_projected_texture2d_tbo(const std::string &tboAlias, const std::string &textureAlias);
    bool generate_cubemap_tbo(const std::string &tboAlias, const std::string &cubemapAlias);

    gl::TBO *get_tbo(const std::string &tboAlias);
    gl::TextureName id(const std::string &tboAlias){
        if(auto tbo = get_tbo(tboAlias); tbo != nullptr){
            return tbo->id();
        }
        return 0;
    }

private:

    using Alias = std::string;
    using Path  = std::string;

    std::unordered_map<Path,  Alias> aliasPerPath;
    std::unordered_map<Alias, std::shared_ptr<Texture2D>> textures;
    std::unordered_map<Alias, std::shared_ptr<CubeMap>> cubeMaps;

    std::unordered_map<Alias, gl::TBO> TBOs;
};

}
