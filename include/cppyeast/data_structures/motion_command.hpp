#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include <cppyeastdefinitions/json_parsable.hpp>
#include <ck_utilities_node/geometry/geometry.hpp>

class MotionCommand : JSONParsable
{
    public:
    bool velocity_valid;
    geometry::Twist velocity;
    bool acceleration_valid;
    geometry::Twist acceleration;

    MotionCommand(nlohmann::json json);
};