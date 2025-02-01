#include "yeastcpp/data_structures/motion_command.hpp"

namespace yeast_motion
{
    MotionCommand::MotionCommand()
    {
        this->velocity_valid = false;
        this->acceleration_valid = false;
    }

    MotionCommand::MotionCommand(nlohmann::json json)
    {
        this->from_json(json);
    }

    void MotionCommand::from_json(nlohmann::json json)
    {
        this->velocity_valid = json["velocity_valid"];
        this->acceleration_valid = json["acceleration_valid"];
        this->acceleration.from_json(json["acceleration"]);
        this->velocity.from_json(json["velocity"]);
    }

    nlohmann::json MotionCommand::to_json(void) const
    {
        nlohmann::json output;
        output["velocity_valid"] = this->velocity_valid;
        output["acceleration_valid"] = this->acceleration_valid;
        output["acceleration"] = this->acceleration.to_json();
        output["velocity"] = this->velocity.to_json();
        return output;
    }
}
