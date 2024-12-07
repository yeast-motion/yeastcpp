#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/json_parsable.hpp"
#include "yeastcpp/data_structures/motion_sample.hpp"


namespace yeast_motion
{
    class MotionState : JSONParsable
    {
        MotionSample reference;
        MotionSample measuremed;
        MotionState(nlohmann::json json);
        nlohmann::json to_json();
        void from_json(nlohmann::json json);
    };
}