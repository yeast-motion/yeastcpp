#include "yeastcpp/data_structures/motion_sample.hpp"

namespace yeast_motion
{
    MotionSample::MotionSample()
    {

    }

    MotionSample::MotionSample(nlohmann::json json)
    {
        // TODO: Implement.
    }

    void MotionSample::from_json(nlohmann::json json)
    {
        // TODO: Implement.
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