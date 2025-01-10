#include "yeastcpp/data_structures/motion_sample.hpp"

namespace yeast_motion
{
    MotionSample::MotionSample()
    {

    }

    MotionSample::MotionSample(nlohmann::json json)
    {
        this->from_json(json);
    }

    void MotionSample::from_json(nlohmann::json json)
    {
        this->pose = Pose2D(json["pose"]);
        this->pose_valid = json["pose_valid"];
        this->velocity = Twist2D(json["velocity"]);
        this->velocity_valid = json["velocity_valid"];
        this->acceleration = Twist2D(json["acceleration"]);
        this->acceleration_valid = json["acceleration_valid"];
    }

    nlohmann::json MotionSample::to_json(void)
    {
        nlohmann::json object;
        object["pose"] = pose.to_json();
        object["pose_valid"] = pose_valid;
        object["velocity"] = velocity.to_json();
        object["velocity_valid"] = velocity_valid;
        object["acceleration"] = acceleration.to_json();
        object["acceleration_valid"] = acceleration_valid;
        return object;
    }
}