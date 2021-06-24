
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

#include "kinect2_settings_files.hpp"

// std
#include <filesystem>
#include <iostream>
#include <fstream>

using namespace tool::camera::K2;

bool ScanerConfig::save_grabber_camera_settings_file(const Parameters &p, std::string path){

    if(path.length() == 0){
        path = (std::filesystem::current_path() / "config/camera/camera_saved.config").string();
    }

    std::ofstream file;
    file.open(path);
    if(!file.is_open()){
        return  false;
    }

    file << p.to_string();

    return true;
}

std::optional<Parameters> ScanerConfig::read_grabber_camera_settings_file(std::string path){

    std::filesystem::path fsPath;
    if(path.length() == 0){
        fsPath = std::filesystem::current_path() / "config/camera/camera_default.config";
    }else{
        fsPath = path;
        if(fsPath.extension() != ".config"){
            std::cerr << "Invalid extension for config file " << fsPath.string() << "\n";
            return {};
        }
    }

    std::ifstream inConfigFile(fsPath.string());
    if(!inConfigFile.is_open()){
        std::cerr << "No config file found at: " << fsPath.string() << "\n";
        return {};
    }

    std::string str;
    inConfigFile.seekg(0, std::ios::end);
    str.reserve(static_cast<size_t>(inConfigFile.tellg()));
    inConfigFile.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(inConfigFile)),std::istreambuf_iterator<char>());

    return Parameters::from_string(str);
}

bool ScanerConfig::read_grabber_config_file(int *readingPort, std::string path){

    std::filesystem::path fsPath;
    if(path.length() == 0){
        fsPath = std::filesystem::current_path() / "config/network/network_default.config";
    }else{
        fsPath = path;
        if(fsPath.extension() != ".config"){
            std::cerr << "Invalid extension for config file " << fsPath.string() << "\n";
            return false;
        }
    }

    std::ifstream inConfigFile(fsPath.string());
    if(!inConfigFile.is_open()){
        std::cerr << "No config file found at: " << fsPath.string() << "\n";
        return false;
    }

    // retrieve reading port
    std::string line;
    while (std::getline(inConfigFile, line)){
        *readingPort = std::stoi(line);
    }

    return true;
}

std::vector<GrabberTargetInfo> ScanerConfig::read_manager_network_config_file(std::string path){

    std::filesystem::path fsPath;
    std::cout << "Read manager network confile file: " << path << "\n";
    if(path.length() == 0){
        fsPath = std::filesystem::current_path() / "config/network/network_default.config";
    }else{
        fsPath = path;
        if(fsPath.extension() != ".config"){
            std::cerr << "Invalid extension for config file " << fsPath.string() << "\n";
            return {};
        }
    }

    std::ifstream inConfigFile(fsPath.string());
    if(!inConfigFile.is_open()){
        std::cerr << "Cannot open manager network config file with path: " << fsPath.string() << "\n";
        return {};
    }

    // retrieve infos
    std_v1<GrabberTargetInfo> infos;
    std::string line;
    while (std::getline(inConfigFile, line)){
        auto split = tool::str::split(line, ' ');
        if(split.size() != 4){
            std::cerr << "Invalid manager network config file with path: " << fsPath.string() << "\n";
            return {};
        }
        infos.emplace_back(GrabberTargetInfo{split[0],std::stoi(split[1]),std::stoi(split[2]),std::stoi(split[3])});
    }

    return infos;
}

std::vector<tool::geo::Mat4d> ScanerConfig::read_manager_calibration_file(std::string path){

    std::filesystem::path fsPath;
    if(path.length() == 0){
        fsPath = std::filesystem::current_path() / "config/calibrations/network_default.config";
    }else{
        fsPath = path;
        if(fsPath.extension() != ".config"){
            std::cerr << "Invalid extension for config file " << fsPath.string() << "\n";
            return {};
        }
    }

    std::ifstream inConfigfile(fsPath.string());
    if(!inConfigfile.is_open()){
        std::cerr << "Cannot open manager calibration file " << fsPath.string() << "\n";
        return {};
    }

    std::stringstream buffer;
    buffer << inConfigfile.rdbuf();
    inConfigfile.close();


    auto read_matrix = [&]()-> std::optional<geo::Mat4d>{

        std::string line;
        std_v1<double> values;
        for(size_t ii = 0; ii < 4; ++ii){

            std::getline(buffer, line);

            auto split = str::split(line, ' ');
            if(split.size() == 4){
                values.emplace_back(std::stof(split[0]));
                values.emplace_back(std::stof(split[1]));
                values.emplace_back(std::stof(split[2]));
                values.emplace_back(std::stof(split[3]));
            }else{
                return {};
            }
        }

        return std::make_optional<geo::Mat4d>(values.data());
    };

    bool read = true;
    std_v1<geo::Mat4d> mCalibs;
    while(read){
        std::string line;
        std::getline(buffer, line);
        if(line.size() > 0){

            auto matrix = read_matrix();
            if(matrix.has_value()){
                mCalibs.emplace_back(std::move(matrix.value()));
            }else{
                std::cerr << "Invalid manager calibration file " << fsPath.string() << "\n";
                return {};
            }

        }else{
            read = false;
        }
    }

    return mCalibs;
}
