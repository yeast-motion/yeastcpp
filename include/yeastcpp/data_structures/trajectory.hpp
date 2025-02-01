#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class Trajectory : JSONParsable
    {
        public:
        nlohmann::json trajectory;

        Trajectory() {}

        Trajectory(nlohmann::json json)
        {
            trajectory = json;
        }

        void from_json(nlohmann::json json)
        {
            trajectory = json;
        }
        nlohmann::json to_json(void) const
        {
            return this->trajectory;
        }
    };
}