#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/json_parsable.hpp"
#include "cppyeastdefinitions/data_structures/traj_point.hpp"

class Trajectory : JSONParsable
{
    public:
    std::vector<TrajPoint> trajectory_points;

    Trajectory(nlohmann::json json);
};