
#include "yeastcpp/data_structures/absolute_pose_estimate.hpp"

namespace yeast_motion
{
    AbsolutePoseEstimate::AbsolutePoseEstimate()
    {
        this->timestamp = 0;
    }

    AbsolutePoseEstimate::AbsolutePoseEstimate(nlohmann::json json)
    {
        this->from_json(json);
    }

    void AbsolutePoseEstimate::from_json(nlohmann::json json)
    {
        this->pose = Pose2D(json["pose"]);
        this->timestamp = json["timestamp"];
    }

    nlohmann::json AbsolutePoseEstimate::to_json(void) const
    {
        nlohmann::json object;
        object["pose"] = pose.to_json();
        object["timestamp"] = timestamp;
        return object;
    }
}