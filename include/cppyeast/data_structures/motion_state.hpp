#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "cppyeastdefinitions/json_parsable.hpp"
#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/data_structures/motion_sample.hpp"



class MotionState : JSONParsable
{
    MotionSample reference;
    MotionSample measuremed;
    MotionState(nlohmann::json json);
};