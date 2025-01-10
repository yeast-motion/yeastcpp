#pragma once

#include <iostream>

#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class Rotation2D : JSONParsable
    {
        public:
            float theta = 0.0;
            nlohmann::json to_json();
            void from_json(nlohmann::json json);
    };
}
