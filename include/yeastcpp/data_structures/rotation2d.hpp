#pragma once

#include <iostream>

#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class Rotation2D : JSONParsable
    {
        public:
            float theta = 0.0;
            Rotation2D();
            Rotation2D(nlohmann::json json);
            nlohmann::json to_json() const;
            void from_json(nlohmann::json json);
    };
}
