#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include <cppyeastdefinitions/json_parsable.hpp>
#include "ck_utilities_node/geometry/geometry.hpp"

class FollowerStatus : JSONParsable
{
    public:
    
    FollowerStatus(nlohmann::json json);
};