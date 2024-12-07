#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class FollowerEvent : JSONParsable
    {
        public:
        std::string name;

        FollowerEvent(nlohmann::json json);
    };
}