
#pragma once

// std
#include <vector>
#include <string>

// imgui
#include "imgui.h"

namespace ImGui{

static auto vector_getter = [](void* vec, int idx, const char** out_text){
    auto& vector = *static_cast<std::vector<std::string>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
    *out_text = vector.at(idx).c_str();
    return true;
};

[[maybe_unused]] static bool Combo(const char* label, int* currIndex, std::vector<std::string>& values){
    if (values.empty()) {
        return false;
    }
    return Combo(label, currIndex, vector_getter,static_cast<void*>(&values), values.size());
}

[[maybe_unused]] static bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values){
    if (values.empty()) {
        return false;
    }
    return ListBox(label, currIndex, vector_getter,static_cast<void*>(&values), values.size());
}
}
