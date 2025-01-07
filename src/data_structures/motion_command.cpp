#include "yeastcpp/data_structures/motion_command.hpp"

namespace yeast_motion
{
    MotionCommand::MotionCommand(nlohmann::json json)
    {
        // TODO: Implement.
    }

    void MotionCommand::from_json(nlohmann::json json)
    {
        // TODO: Implement.
    }

    nlohmann::json MotionCommand::to_json(void)
    {
        // TODO: Implement.
        nlohmann::json output;
        nlohmann::json velocity;
        velocity["x"] = this->velocity.x;
        velocity["y"] = this->velocity.y;
        velocity["omega"] = this->velocity.omega;
        output["velocity"] = velocity;
        return output;
    }
}