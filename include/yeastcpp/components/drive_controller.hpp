#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/data_structures/motion_command.hpp"
#include "yeastcpp/data_structures/motion_state.hpp"

namespace yeast_motion
{
    class DriveController
    {
        virtual MotionState drive(MotionCommand command) = 0;
    };
}