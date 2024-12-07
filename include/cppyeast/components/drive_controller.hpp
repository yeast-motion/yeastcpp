#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "cppyeastdefinitions/data_structures/motion_command.hpp"
#include "cppyeastdefinitions/data_structures/motion_state.hpp"

class DriveController
{
    virtual MotionState drive(MotionCommand command) = 0;
};