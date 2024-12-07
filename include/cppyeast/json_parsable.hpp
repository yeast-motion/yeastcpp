#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ck_utilities_node/geometry/geometry.hpp"

class JSONParsable
{
    virtual void from_json(nlohmann::json json) = 0;
    virtual nlohmann::json to_json() = 0;
};