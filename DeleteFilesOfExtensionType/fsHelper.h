#pragma once
//"fsHelper.h"
#pragma once
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
typedef fs::path element_t;


const std::vector<element_t> collect_relivant_files(const std::vector<element_t>& directory, const std::vector<element_t>& extns_to_delete);