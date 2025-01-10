#include "yeastcpp/data_structures/follower_status.hpp"

namespace yeast_motion
{
    FollowerStatus::FollowerStatus()
    {

    }

    FollowerStatus::FollowerStatus(nlohmann::json json)
    {
        this->from_json(json);
    }

    void FollowerStatus::from_json(nlohmann::json json)
    {
        this->passed_commands = json["passed_commands"];
        this->finished = json["finished"];
    }

    nlohmann::json FollowerStatus::to_json(void){
        nlohmann::json object;
        object["passed_commands"] = this->passed_commands;
        object["finished"] = this->finished;
        return object;
    }
}