#include "yeastcpp/data_structures/swerve_module_config.hpp"

namespace yeast_motion
{
    SwerveModuleConfig::SwerveModuleConfig()
    {

    }

    SwerveModuleConfig::SwerveModuleConfig(nlohmann::json json)
    {
        this->from_json(json);
    }

    void SwerveModuleConfig::from_json(nlohmann::json json)
    {
        this->translation = json["translation"];
    }

    nlohmann::json SwerveModuleConfig::to_json(void)
    {
        nlohmann::json object;
        object["translation"] = this->translation.to_json();
        return object;
    }
}