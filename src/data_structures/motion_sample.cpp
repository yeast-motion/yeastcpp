#include "yeastcpp/data_structures/motion_sample.hpp"

namespace yeast_motion
{
    MotionSample::MotionSample()
    {
        this->pose_valid = false;
        this->velocity_valid = false;
        this->acceleration_valid = false;
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

    nlohmann::json MotionSample::to_json(void) const
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

    MotionSample& MotionSample::operator=(const OdometrySample& other)
    {
        this->pose = other.pose;
        this->pose_valid = other.pose_valid;
        this->velocity = other.velocity;
        this->velocity_valid = other.velocity_valid;
        this->acceleration = other.acceleration;
        this->acceleration_valid = other.acceleration_valid;

        return *this;
    }
}