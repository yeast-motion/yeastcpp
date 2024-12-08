#pragma once

#include <iostream>

#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class SwerveModuleStatus : JSONParsable
    {
        public:
        float speed = 0.0;
        float theta = 0.0;
        float position = 0.0;

        SwerveModuleStatus ();
        SwerveModuleStatus (nlohmann::json json);
        nlohmann::json to_json();
        void from_json (nlohmann::json json);
    };
}


