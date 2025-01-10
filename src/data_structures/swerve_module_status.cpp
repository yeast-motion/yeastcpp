#include "yeastcpp/data_structures/swerve_module_status.hpp"

namespace yeast_motion
{
    SwerveModuleStatus::SwerveModuleStatus()
    {
        // TODO: Implement.
    }

    SwerveModuleStatus::SwerveModuleStatus(nlohmann::json json)
    {
        this->from_json(json);
    }

    void SwerveModuleStatus::from_json(nlohmann::json json)
    {
        this->speed = json["speed"];
        this->theta = json["theta"];
        this->position = json["position"];
    }

    nlohmann::json SwerveModuleStatus::to_json(void)
    {
        nlohmann::json object;
        object["speed"] = speed;
        object["theta"] = theta;
        object["position"] = position;
        return object;
    }
}


