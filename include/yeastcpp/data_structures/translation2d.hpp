#pragma once

#include <iostream>
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class Translation2D : JSONParsable
    {
        public:
            float x = 0.0;
            float y = 0.0;

            Translation2D();
            Translation2D(nlohmann::json json);
            nlohmann::json to_json() const;
            void from_json(nlohmann::json json);
    };
}
