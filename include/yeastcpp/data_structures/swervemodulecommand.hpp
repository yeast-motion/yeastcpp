#pragma once

#include <iostream>

#include "yeastcpp/yeastcpp.hpp"

namespace yeast_motion
{
    class SwerveModuleCommand : JSONParsable
    {
        public:
        float speed = 0.0;
        float theta = 0.0;

        SwerveModuleCommand();
        SwerveModuleCommand(nlohmann::json json);
        nlohmann::json to_json();
        void from_json(nlohmann::json json);
    };
}