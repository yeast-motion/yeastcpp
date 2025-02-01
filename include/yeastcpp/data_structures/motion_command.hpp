#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/data_structures/twist2d.hpp"
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class MotionCommand : JSONParsable
    {
        public:
            bool velocity_valid;
            Twist2D velocity;
            bool acceleration_valid;
            Twist2D acceleration;

            MotionCommand();
            MotionCommand(nlohmann::json json);
            nlohmann::json to_json() const;
            void from_json(nlohmann::json json);
    };
}