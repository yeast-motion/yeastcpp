#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "ck_utilities_node/geometry/geometry.hpp"
#include "cppyeastdefinitions/data_structures/trajectory.hpp"
#include "cppyeastdefinitions/data_structures/motion_command.hpp"
#include "cppyeastdefinitions/data_structures/motion_state.hpp"
#include "cppyeastdefinitions/data_structures/follower_status.hpp"

class Follower
{
    public: 
    virtual void begin(Trajectory trajectory) = 0;

    virtual MotionCommand follow(MotionState motion_state) = 0;
    virtual FollowerStatus status() = 0;
};