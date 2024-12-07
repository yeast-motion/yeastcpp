#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/data_structures/motion_command.hpp"
#include "yeastcpp/data_structures/motion_state.hpp"

namespace yeast_motion
{
    class DriveFilter
    {
        public:
        virtual MotionCommand filter (MotionCommand command, MotionState state) = 0;
    };
}