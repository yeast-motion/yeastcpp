#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/json_parsable.hpp"

class FollowerEvent : JSONParsable
{
    public:
    std::string name;

    FollowerEvent(nlohmann::json json);
};