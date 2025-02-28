#include "yeastcpp/data_structures/follower_status.hpp"

namespace yeast_motion
{
    FollowerStatus::FollowerStatus()
    {
        this->finished = false;
        this->sync_number = -1;
    }

    FollowerStatus::FollowerStatus(nlohmann::json json)
    {
        this->from_json(json);
    }

    void FollowerStatus::from_json(nlohmann::json json)
    {
        this->passed_commands = json["passed_commands"];
        this->finished = json["finished"];
        this->sync_number = json["sync_number"];
    }

    nlohmann::json FollowerStatus::to_json(void) const
    {
        nlohmann::json object;
        object["passed_commands"] = this->passed_commands;
        object["finished"] = this->finished;
        object["sync_number"] = this->sync_number;
        return object;
    }
}