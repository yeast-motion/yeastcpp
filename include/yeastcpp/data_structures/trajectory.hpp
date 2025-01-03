#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/json_parsable.hpp"
#include "yeastcpp/data_structures/traj_point.hpp"

namespace yeast_motion
{
    class Trajectory : JSONParsable
    {
        public:
        nlohmann::json trajectory;

        Trajectory(nlohmann::json json)
        {
            this->trajectory = json;
        }

        void from_json(nlohmann::json json)
        {
            this->trajectory = json;
            return;
        }
        nlohmann::json to_json(void)
        {
            return this->trajectory;
        }
    };
}