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
        std::vector<TrajPoint> trajectory_points;

        Trajectory(nlohmann::json json);
    };
}