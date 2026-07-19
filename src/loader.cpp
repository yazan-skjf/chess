#include "loader.hpp"
#include <fstream>

using json = nlohmann::json;

json Loader::load(const std::string& path)
{
    std::ifstream file(path);

    json data;
    file >> data;

    return data;
}