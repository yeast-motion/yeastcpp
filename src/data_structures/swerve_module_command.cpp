#include "yeastcpp/data_structures/swerve_module_command.hpp"

namespace yeast_motion
{
    SwerveModuleCommand::SwerveModuleCommand ()
    {

    }

    SwerveModuleCommand::SwerveModuleCommand(nlohmann::json json)
    {
        this->from_json(json);
    }

    void SwerveModuleCommand::from_json(nlohmann::json json)
    {
        this->speed = json["speed"];
        this->theta = json["theta"];
        if (json.contains("accel"))
        {
            this->accel = json["accel"];
        }
    }

    nlohmann::json SwerveModuleCommand::to_json(void) const
    {
        nlohmann::json object;
        object["speed"] = speed;
        object["theta"] = theta;
        object["accel"] = accel;
        return object;
    }
}