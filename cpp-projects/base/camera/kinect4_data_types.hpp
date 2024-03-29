
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

#pragma once

// std
#include <memory>
#include <chrono>
#include <mutex>

// kinect4
#include <k4a/k4atypes.h>

// base
#include "utility/tuple_array.hpp"
#include "geometry/point3.hpp"

namespace tool::camera::K4{

    enum class ImageFormat : int {
        MJPEG    = K4A_IMAGE_FORMAT_COLOR_MJPG,   // The buffer for each image is encoded as a JPEG and can be decoded by a JPEG decoder.
        NV12     = K4A_IMAGE_FORMAT_COLOR_NV12,   // NV12 images separate the luminance and chroma data such that all the luminance is at the
                                                  // beginning of the buffer, and the chroma lines follow immediately after.
        YUY2     = K4A_IMAGE_FORMAT_COLOR_YUY2,   // YUY2 stores chroma and luminance data in interleaved pixels.
        BGRA32   = K4A_IMAGE_FORMAT_COLOR_BGRA32, // Each pixel of BGRA32 data is four bytes. The first three bytes represent Blue, Green,
                                                  // and Red data. The fourth byte is the alpha channel and is unused in the Azure Kinect APIs.
        IR16     = K4A_IMAGE_FORMAT_IR16,         // Each pixel of IR16 data is two bytes of little endian unsigned depth data.
                                                  // The value of the data represents brightness.
        DEPTH16  = K4A_IMAGE_FORMAT_DEPTH16,      // Each pixel of DEPTH16 data is two bytes of little endian unsigned depth data.
                                                  // The unit of the data is in millimeters from the origin of the camera.
        CUSTOM   = K4A_IMAGE_FORMAT_CUSTOM,       // Used in conjunction with user created images or images packing non-standard data.
        CUSTOM8  = K4A_IMAGE_FORMAT_CUSTOM8,      // Each pixel of CUSTOM8 is a single channel one byte of unsigned data.
        CUSTOM16 = K4A_IMAGE_FORMAT_CUSTOM16      // Each pixel of CUSTOM16 is a single channel two bytes of little endian unsigned data.
    };

    enum class ColorResolution : int {
        OFF     = K4A_COLOR_RESOLUTION_OFF,     // Color camera will be turned off with this setting
        R720P   = K4A_COLOR_RESOLUTION_720P,    // 1280 * 720  16:9
        R1080P  = K4A_COLOR_RESOLUTION_1080P,   // 1920 * 1080 16:9
        R1440P  = K4A_COLOR_RESOLUTION_1440P,   // 2560 * 1440 16:9
        R1536P  = K4A_COLOR_RESOLUTION_1536P,   // 2048 * 1536 4:3
        R2160P  = K4A_COLOR_RESOLUTION_2160P,   // 3840 * 2160 16:9
        R3072P  = K4A_COLOR_RESOLUTION_3072P    // 4096 * 3072 4:3
    };

    enum class DepthMode : int {
         OFF            = K4A_DEPTH_MODE_OFF ,              // Depth sensor will be turned off with this setting.
         NFOV_2X2BINNED = K4A_DEPTH_MODE_NFOV_2X2BINNED,    // Depth captured at 320x288. Passive IR is also captured at 320x288.
         NFOV_UNBINNED  = K4A_DEPTH_MODE_NFOV_UNBINNED,     // Depth captured at 640x576. Passive IR is also captured at 640x576.
         WFOV_2X2BINNED = K4A_DEPTH_MODE_WFOV_2X2BINNED,    // Depth captured at 512x512. Passive IR is also captured at 512x512.
         WFOV_UNBINNED  = K4A_DEPTH_MODE_WFOV_UNBINNED,     // Depth captured at 1024x1024. Passive IR is also captured at 1024x1024.
         PASSIVE_IR     = K4A_DEPTH_MODE_PASSIVE_IR,        // Passive IR only, captured at 1024x1024.
    };

    enum class Framerate : int{
        F5  = K4A_FRAMES_PER_SECOND_5,   // 5 FPS
        F15 = K4A_FRAMES_PER_SECOND_15,  // 15 FPS
        F30 = K4A_FRAMES_PER_SECOND_30,  // 30 FPS
    };

    enum class SynchronisationMode : int{
        Standalone  = K4A_WIRED_SYNC_MODE_STANDALONE, // Neither 'Sync In' or 'Sync Out' connections are used.
        Master      = K4A_WIRED_SYNC_MODE_MASTER,     // The 'Sync Out' jack is enabled and synchronization data it driven out the connected wire.
                                                      // While in master mode the color camera must be enabled as part of the multi device sync signalling logic.
                                                      // Even if the color image is not needed, the color camera must be running.
        Subordinate = K4A_WIRED_SYNC_MODE_SUBORDINATE // The 'Sync In' jack is used for synchronization and 'Sync Out' is driven for the
                                                      // next device in the chain. 'Sync Out' is a mirror of 'Sync In' for this mode.
    };

    enum class Mode : int {
        // clouds
        Cloud_320x288,
        Cloud_640x576,
        Cloud_512x512,
        Cloud_1024x1024,
        // frames
        Full_frame_320x288,
        Full_frame_640x576,
        Full_frame_512x512,
        Full_frame_1024x1024,
        // colors
        Only_color_1280x720,
        Only_color_1920x1080,
        Only_color_2560x1440,
        Only_color_2048x1536,
        Only_color_3840x2160,
        Only_color_4096x3072,
        SizeEnum
    };

    using IF  = ImageFormat;
    using CR  = ColorResolution;
    using DM  = DepthMode;
    using FPS = Framerate;

    using TMode = std::tuple<
        Mode,                             ImageFormat,   ColorResolution,   DepthMode,          Framerate>;
    static constexpr TupleArray<Mode::SizeEnum, TMode> modes = {{
        // cloud
        TMode{Mode::Cloud_320x288,        IF::YUY2,      CR::R720P,         DM::NFOV_2X2BINNED, FPS::F30},
        TMode{Mode::Cloud_640x576,        IF::YUY2,      CR::R720P,         DM::NFOV_UNBINNED,  FPS::F30},
        TMode{Mode::Cloud_512x512,        IF::YUY2,      CR::R720P,         DM::WFOV_2X2BINNED, FPS::F30},
        TMode{Mode::Cloud_1024x1024,      IF::YUY2,      CR::R720P,         DM::WFOV_UNBINNED,  FPS::F15},
        // frame
        TMode{Mode::Full_frame_320x288,   IF::YUY2,      CR::R720P,         DM::NFOV_2X2BINNED, FPS::F30},
        TMode{Mode::Full_frame_640x576,   IF::YUY2,      CR::R720P,         DM::NFOV_UNBINNED,  FPS::F30},
        TMode{Mode::Full_frame_512x512,   IF::YUY2,      CR::R720P,         DM::WFOV_2X2BINNED, FPS::F30},
        TMode{Mode::Full_frame_1024x1024, IF::YUY2,      CR::R720P,         DM::WFOV_UNBINNED,  FPS::F15},
        // only color
        TMode{Mode::Only_color_1280x720,  IF::BGRA32,    CR::R720P,         DM::OFF,            FPS::F30},
        TMode{Mode::Only_color_1920x1080, IF::BGRA32,    CR::R1080P,        DM::OFF,            FPS::F30},
        TMode{Mode::Only_color_2560x1440, IF::BGRA32,    CR::R1440P,        DM::OFF,            FPS::F30},
        TMode{Mode::Only_color_2048x1536, IF::BGRA32,    CR::R1536P,        DM::OFF,            FPS::F30},
        TMode{Mode::Only_color_3840x2160, IF::BGRA32,    CR::R2160P,        DM::OFF,            FPS::F30},
        TMode{Mode::Only_color_4096x3072, IF::BGRA32,    CR::R3072P,        DM::OFF,            FPS::F15},
    }};


    [[maybe_unused]] static constexpr ImageFormat image_format(Mode m) {
        return modes.at<0,1>(m);
    }
    [[maybe_unused]] static constexpr ColorResolution color_resolution(Mode m) {
        return modes.at<0,2>(m);
    }
    [[maybe_unused]] static constexpr DepthMode depth_mode(Mode m) {
        return modes.at<0,3>(m);
    }
    [[maybe_unused]] static constexpr Framerate framerate(Mode m) {
        return modes.at<0,4>(m);
    }

    struct Config{
        K4::Mode mode = K4::Mode::Cloud_640x576;
        bool synchronizeColorAndDepth = true;
        int delayBetweenColorAndDepthUsec = 0;
        K4::SynchronisationMode synchMode = K4::SynchronisationMode::Standalone;
        int subordinateDelayUsec = 0;
        bool disableLED = false;
    };


    static constexpr int max_width_value  = 1024;
    static constexpr int max_height_value = 1024;

    [[maybe_unused]] static constexpr std::int16_t invalid_depth_value = 0;
    static constexpr std::int16_t default_depth_value = 3000;
    [[maybe_unused]] static constexpr std::int16_t max_depth_value = 16000;

    struct Parameters{

        // # width / height
        unsigned int minWidth  = 0;
        unsigned int maxWidth  = max_width_value;
        unsigned int minHeight = 0;
        unsigned int maxHeight = max_height_value;

        // color
        float yFactor = 1.f;
        float uFactor = 1.f;
        float vFactor = 1.f;
        geo::Pt3<std::uint8_t> filterColor  = geo::Pt3<std::uint8_t>(255,0,0);
        geo::Pt3<std::uint8_t> maxDiffColor = geo::Pt3<std::uint8_t>(10,40,40);

        // # depth
        std::int16_t minDepthValue = 300;
        std::int16_t maxDepthValue = default_depth_value;

        // compression
        unsigned char jpegCompressionRate = 80;

        // # neigbhours
        unsigned char nbMinNeighboursNb = 1;
        unsigned char minNeighboursLoops = 1;

        // flogs
        bool filterDepthWithColor = false;

        // send
        bool sendCompressedDataFrame    = false;
        bool sendDisplayColorFrame      = false;
        bool sendDisplayDepthFrame      = false;
        bool sendDisplayInfraredFrame   = false;
        bool sendDisplayCloud           = false;
    };

    struct PixelsFrame{
        size_t width;
        size_t height;
        std::vector<geo::Pt3f> pixels;
    };

    struct ColoredCloud{
        size_t validVerticesCount = 0;
        std::vector<geo::Pt3f> vertices;
        std::vector<geo::Pt3f> colors;
    };

    struct CompressedDataFrame{
        size_t colorWidth;
        size_t colorHeight;
        std::vector<std::uint8_t> compressedColorBuffer;
        size_t depthWidth;
        size_t depthHeight;
        std::vector<std::uint32_t> compressedDepthBuffer;
    };

    struct DisplayData{
        std::mutex lock;
        PixelsFrame colorFrame;
        PixelsFrame depthFrame;
        PixelsFrame infraredFrame;
        ColoredCloud cloud;
    };

    struct FrameReadingTimings{
        std::chrono::nanoseconds startFrameReadingTS;
        std::chrono::nanoseconds afterCaptureTS;
        std::chrono::nanoseconds getColorTS;
        std::chrono::nanoseconds getDepthTS;
        std::chrono::nanoseconds getInfraTS;
        std::chrono::nanoseconds afterGetImagesTS;
        std::chrono::nanoseconds afterUncompressTS;
        std::chrono::nanoseconds afterTransformTS;
        std::chrono::nanoseconds afterFilteringTS;
        std::chrono::nanoseconds afterSendingCompressedTS;
        std::chrono::nanoseconds afterProcessingDisplayDataTS;
        std::chrono::nanoseconds afterGeneratingDisplayDataTS;
        std::chrono::nanoseconds endFrameReadingTS;
    };



    struct color_point_t{
        int16_t xyz[3];
        uint8_t rgb[3];
    };
}









