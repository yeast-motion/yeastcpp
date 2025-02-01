#pragma once

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

#include <yeastcpp/json_parsable.hpp>

namespace yeast_motion
{
    class FollowerStatus : JSONParsable
    {
        public:
        std::vector<std::string> passed_commands;
        bool finished = false;

        FollowerStatus();
        FollowerStatus(nlohmann::json json);
        void from_json(nlohmann::json json);
        nlohmann::json to_json(void) const;
    };
}