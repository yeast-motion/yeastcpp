#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/json_parsable.hpp"
#include "yeastcpp/data_structures/motion_sample.hpp"

namespace yeast_motion
{
    class TrajPoint : JSONParsable
    {
        public:
        MotionSample point;

        TrajPoint(nlohmann::json);
        nlohmann::json to_json();
        void from_json (nlohmann::json json);
    };
}