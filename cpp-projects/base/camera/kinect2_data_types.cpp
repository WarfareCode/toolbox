
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
#include "kinect2_data_types.hpp"

// turbojpeg
#include <turbojpeg.h>

using namespace std;

using namespace tool;
using namespace tool::camera::K2;


#include <iostream>
//auto int_to_voxel(const Voxel64 &vi){

//    return geo::Voxel{
//        {-7.f+static_cast<float>(vi.x)*0.001f, -7.f+static_cast<float>(vi.y)*0.001f, static_cast<float>(vi.z)*0.001f},
//        {static_cast<byte>(vi.r), static_cast<byte>(vi.g), static_cast<byte>(vi.b)}
//    };
//}

//auto voxel_to_int(const geo::Voxel &v){

//    return Voxel64{
//        static_cast<std::uint16_t>(std::clamp(v.p.x()+7.f,0.f,14.f)*1000.f),
//        static_cast<std::uint16_t>(std::clamp(v.p.y()+7.f,0.f,14.f)*1000.f),
//        static_cast<std::uint16_t>(std::clamp(v.p.z(),0.f,4.095f)*1000.f),
//        v.c.x(),
//        v.c.y(),
//        v.c.z()
//    };
//}



std::string Parameters::to_string() const{
    std::ostringstream ss;
    ss << "window: " << minWidth << " " << maxWidth << " " << minHeight << " " << maxHeight << "\n";
    ss << "infra_threshold: " << minInfra << " " << maxInfra << " " << minInfraRange << " " << maxInfraRange << "\n";
    ss << "color_factor: " << yFactor << " " << uFactor << " " << vFactor << "\n";
    ss << "depth_threshold: " << minDepthValue << " " << maxDepthValue << " " << maxLocalDiff << " " << offsetAfterMin << " "  << vmin << " " << vmax << " " << gmin << "\n";
    ss << "compression: " << static_cast<int>(jpegCompressionRate) << "\n";
    ss << "smoothing: " << static_cast<int>(smoothingKernelSize )<< " " << static_cast<int>(smoothingMethod) << "\n";
    ss << "neigbhours: " << static_cast<int>(nbMinNeighboursNb) << " " << static_cast<int>(minNeighboursLoops) << "\n";
    ss << "erosion: " << static_cast<int>(erosionSize) << " " << static_cast<int>(erosionType) << " " << static_cast<int>(minErosionValue) << "\n";
    ss << "fps: " << static_cast<int>(fps) << "\n";
    ss << "color_filter: " << static_cast<int>(filterColor.x()) << " " << static_cast<int>(filterColor.y()) << " " << static_cast<int>(filterColor.z()) << " "
       << static_cast<int>(maxDiffColor.x()) << " " << static_cast<int>(maxDiffColor.y()) << " " << static_cast<int>(maxDiffColor.z()) << "\n";
    ss << "flags: " <<filterDepthWithColor << " " << infraInvert << " " << infraBinary << " " << smoothingEnabled << " " << doErosion << " " << doTemporalFilter << "\n";
    return ss.str();
}

Parameters Parameters::from_string(const std::string &parametersStr){

    Parameters p;

    std::istringstream in(parametersStr);
    std::string line;


    std::getline(in, line);
    auto split = str::split(line, ' ');
    if(split.size() == 5){
        p.minWidth  = std::stoul(split[1]);
        p.maxWidth  = std::stoul(split[2]);
        p.minHeight = std::stoul(split[3]);
        p.maxHeight = std::stoul(split[4]);
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 5){
        p.minInfra      = static_cast<std::uint16_t>(std::stoi(split[1]));
        p.maxInfra      = static_cast<std::uint16_t>(std::stoi(split[2]));
        p.minInfraRange = static_cast<std::uint16_t>(std::stoi(split[3]));
        p.maxInfraRange = static_cast<std::uint16_t>(std::stoi(split[4]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 4){
        p.yFactor  = std::stof(split[1]);
        p.uFactor  = std::stof(split[2]);
        p.vFactor  = std::stof(split[3]);
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 8){
        p.minDepthValue     = std::stof(split[1]);
        p.maxDepthValue     = std::stof(split[2]);
        p.maxLocalDiff      = std::stof(split[3]);
        p.offsetAfterMin    = std::stof(split[4]);
        p.vmin              = std::stof(split[5]);
        p.vmax              = std::stof(split[6]);
        p.gmin              = std::stof(split[7]);
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 2){
        p.jpegCompressionRate   = static_cast<std::uint8_t>(std::stoi(split[1]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 3){
        p.smoothingKernelSize   = static_cast<std::uint8_t>(std::stoi(split[1]));
        p.smoothingMethod       = static_cast<std::uint8_t>(std::stoi(split[2]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 3){
        p.nbMinNeighboursNb     = static_cast<std::uint8_t>(std::stoi(split[1]));
        p.minNeighboursLoops    = static_cast<std::uint8_t>(std::stoi(split[2]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 4){
        p.erosionSize           = static_cast<std::uint8_t>(std::stoi(split[1]));
        p.erosionType           = static_cast<MorphShapes>(std::stoi(split[2]));
        p.minErosionValue       = static_cast<std::uint8_t>(std::stoi(split[3]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() == 2){
        p.fps                   = static_cast<std::uint8_t>(std::stoi(split[1]));
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() >= 7){
        p.filterColor           = {static_cast<std::uint8_t>(std::stoi(split[1])),
                                   static_cast<std::uint8_t>(std::stoi(split[2])),
                                   static_cast<std::uint8_t>(std::stof(split[3]))
                                  };

        p.maxDiffColor          = {static_cast<std::uint8_t>(std::stoi(split[4])),
                                   static_cast<std::uint8_t>(std::stoi(split[5])),
                                   static_cast<std::uint8_t>(std::stof(split[6]))
                                  };
    }

    std::getline(in, line);
    split = str::split(line, ' ');
    if(split.size() >= 7){
        p.filterDepthWithColor  = (std::stoi(split[1])==1);
        p.infraInvert           = (std::stoi(split[2])==1);
        p.infraBinary           = (std::stoi(split[3])==1);
        p.smoothingEnabled      = (std::stoi(split[4])==1);
        p.doErosion             = (std::stoi(split[5])==1);
        p.doTemporalFilter      = (std::stoi(split[6])==1);
    }

    return p;
}



Frame::Frame(bool initData){

    if(initData){
        infraData = std::make_unique<InfraData>();
        depthData = std::make_unique<DepthData>();
        compressedDepthData.resize(2*depth_count+1024);
    }
}


Frame Frame::copy_frame(){

//    auto t1 = std::chrono::high_resolution_clock::now();
    Frame frameCopy(false);

    // copy infos
    frameCopy.parameters = parameters;
    frameCopy.intrinsics = intrinsics;
    frameCopy.mode = mode;
    frameCopy.frameId = frameId;
    frameCopy.relativeTimeColor = relativeTimeColor;
    frameCopy.relativeTimeDepth = relativeTimeDepth;
    frameCopy.relativeTimeInfra = relativeTimeInfra;
    frameCopy.relativeTimeLongInfra = relativeTimeLongInfra;
    frameCopy.relativeTimeBody = relativeTimeBody;
    frameCopy.minReliableDistance = minReliableDistance;
    frameCopy.maxReliableDistance = maxReliableDistance;
    frameCopy.timeStampGetFrame = timeStampGetFrame;
    frameCopy.timeStampEndProcessing = timeStampEndProcessing;

    // copy color data
    if(frameCopy.mode == FrameRequest::compressed_color_1920x1080 || frameCopy.mode == FrameRequest::compressed_color_512x424 ||
       frameCopy.mode == FrameRequest::compressed_color_cloud     || frameCopy.mode == FrameRequest::compressed_color_mesh){

        frameCopy.jpegColorSize = jpegColorSize;
        frameCopy.compressedImage = compressedImage;
    }

    if(frameCopy.mode == FrameRequest::compressed_color_cloud || frameCopy.mode == FrameRequest::compressed_color_mesh){

        frameCopy.compressedDepthSize = compressedDepthSize;
        frameCopy.compressedDepthData = compressedDepthData;
        frameCopy.bodiesData = bodiesData;

    }else if(frameCopy.mode == FrameRequest::depth_512x424){

        frameCopy.depthData = std::make_unique<DepthData>(*depthData);

    }else if(frameCopy.mode == FrameRequest::infra_512x424 || frameCopy.mode == FrameRequest::long_exposure_infra_512x424){

        if(frameCopy.infraData == nullptr){
            frameCopy.infraData = std::make_unique<InfraData>();
        }

        copy(begin(*infraData), end(*infraData), begin(*frameCopy.infraData));
    }

//    auto t2 = std::chrono::high_resolution_clock::now();
//    auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
//    std::cout << "Copy " << d1.count() << "\n";

    return frameCopy;
}



