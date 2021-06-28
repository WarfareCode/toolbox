
#include "shaders_manager.hpp"


using namespace tool::graphics;
using namespace tool::gl;

bool ShadersManager::add_shader( const std::string &alias, const std::vector<std::string> &paths){

    if(shaders.count(alias) != 0){
        std::cerr << "[ShadersM] Shader alias " << alias << " already exists.\n";
        return false;
    }

    auto shader = std::make_shared<gl::ShaderProgram>();
    if(!shader->load_from_files(paths)){
        std::cerr << "[ShadersM] Cannot generate ShaderProgram from paths:\n";
        for(const auto &path : paths){
            std::cerr << "  -> " << path << "\n";
        }
        return false;
    }

    shaders[alias] = shader;
    return true;
}

bool ShadersManager::add_shader(const std::string &alias, ShaderProgram&& shader){

    if(shaders.count(alias) != 0){
        std::cerr << "[ShadersM] Shader alias " << alias << " already exists.\n";
        return false;
    }

    shaders[alias] = std::make_shared<ShaderProgram>(std::move(shader));
    return true;
}

std::weak_ptr<ShaderProgram> ShadersManager::get(std::string alias){
    if(shaders.count(alias) != 0){
        return shaders[alias];
    }
    return {};
}

ShaderProgram *ShadersManager::get_ptr(std::string alias){
    if(shaders.count(alias) != 0){
        return shaders[alias].get();
    }
    return nullptr;
}

void ShadersManager::unbind(){
    ShaderProgram::unbind();
}
