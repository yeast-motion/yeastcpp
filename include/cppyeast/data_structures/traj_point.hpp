#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/json_parsable.hpp"
#include "cppyeastdefinitions/data_structures/motion_sample.hpp"

class TrajPoint : JSONParsable
{
    public:
    MotionSample point;

    TrajPoint(nlohmann::json);
    nlohmann::json to_json();
    void from_json (nlohmann::json json);
};