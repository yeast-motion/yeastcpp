#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/json_parsable.hpp"

class MotionSample : JSONParsable
{
    public:
    bool pose_valid;
    geometry::Pose pose;
    bool velocity_valid;
    geometry::Twist velocity;
    bool acceleration_valid;
    geometry::Twist acceleration;

    MotionSample(nlohmann::json json);
    nlohmann::json to_json();
    void from_json (nlohmann::json json);
};