#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "yeastcpp/data_structures/motion_command.hpp"
#include "yeastcpp/data_structures/motion_state.hpp"
#include "yeastcpp/data_structures/swervemodulecommand.hpp"
#include "yeastcpp/data_structures/swervemodulestatus.hpp"

namespace yeast_motion
{    
    class DriveController
    {
        public:
            virtual MotionState drive(yeast_motion::MotionCommand command) = 0;
            virtual std::vector<SwerveModuleCommand> get_command() = 0;
            virtual void update_motor_status (std::vector<SwerveModuleStatus> motor_status) = 0;
    };
}