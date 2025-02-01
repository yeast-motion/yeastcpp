#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace yeast_motion
{
    class JSONParsable
    {
        public:
        virtual void from_json(nlohmann::json json) = 0;
        virtual nlohmann::json to_json() const = 0;
    };
}