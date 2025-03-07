#pragma once

#include <iostream>

#include "yeastcpp/data_structures/translation2d.hpp"
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class SwerveModuleConfig : JSONParsable
    {
        public:
        Translation2D translation;

        SwerveModuleConfig();
        SwerveModuleConfig(nlohmann::json json);
        nlohmann::json to_json() const;
        void from_json(nlohmann::json json);
    };
}