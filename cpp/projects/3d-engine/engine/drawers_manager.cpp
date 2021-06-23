
#include "drawers_manager.hpp"


using namespace tool;
using namespace tool::graphics;


bool DrawersManager::add_drawer(const std::string &drawerAlias, std::shared_ptr<gl::Drawer> drawer){

    if(drawers.count(drawerAlias) != 0){
        std::cerr << "[ModelsM] Drawer alias already used: " << drawerAlias << "\n";
        return false;
    }

    drawers[drawerAlias] = drawer;

    return true;
}

std::weak_ptr<tool::gl::Drawer> DrawersManager::get_drawer(std::string alias){
    if(drawers.count(alias) != 0){
        return drawers[alias];
    }
    return {};
}

tool::gl::Drawer *DrawersManager::get_drawer_ptr(std::string alias){
    if(drawers.count(alias) != 0){
        return drawers[alias].get();
    }
    return nullptr;
}
