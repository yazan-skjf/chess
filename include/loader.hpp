#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Loader {
    public:
        static json load(const std::string& path);
};