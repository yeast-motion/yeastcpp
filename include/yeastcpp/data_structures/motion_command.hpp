#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/yeastcpp.hpp"

namespace yeast_motion
{
    class MotionCommand : JSONParsable
    {
        public:
            bool velocity_valid;
            Twist2D velocity;
            bool acceleration_valid;
            Twist2D acceleration;

            MotionCommand(nlohmann::json json);
            nlohmann::json to_json ();
            void from_json(nlohmann::json json);
    };
}