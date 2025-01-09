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

        FollowerStatus();

        void from_json(nlohmann::json json)
        {
            (void)json;
            // TODO: Fix Mike Todd (Impossible task)
            return;
        }

        nlohmann::json to_json(void){
            return nlohmann::json();
        }
    };
}