#include "yeastcpp/data_structures/swerve_module_command.hpp"

namespace yeast_motion
{
    SwerveModuleCommand::SwerveModuleCommand ()
    {

    }

    SwerveModuleCommand::SwerveModuleCommand(nlohmann::json json)
    {
        // TODO: Implement.
    }

    void SwerveModuleCommand::from_json(nlohmann::json json)
    {
        // TODO: Implement.
    }

    nlohmann::json SwerveModuleCommand::to_json(void)
    {
        nlohmann::json object;
        object["speed"] = speed;
        object["theta"] = theta;
        return object;
    }
}