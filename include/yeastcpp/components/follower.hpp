#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/data_structures/trajectory.hpp"
#include "yeastcpp/data_structures/motion_command.hpp"
#include "yeastcpp/data_structures/motion_state.hpp"
#include "yeastcpp/data_structures/follower_status.hpp"

namespace yeast_motion
{
    class Follower
    {
        public: 
        virtual void begin(Trajectory trajectory, MotionState initial_state = MotionState()) = 0;

        virtual MotionCommand follow(MotionState motion_state) = 0;
        virtual FollowerStatus status() = 0;
    };
}