#include "yeastcpp/data_structures/traj_point.hpp"

namespace yeast_motion
{
    TrajPoint::TrajPoint(nlohmann::json json)
    {
        this->from_json(json);
    }

    void TrajPoint::from_json(nlohmann::json json)
    {
        this->point = MotionSample(json["point"]);
    }

    nlohmann::json TrajPoint::to_json(void)
    {
        nlohmann::json object;
        object["point"] = point.to_json();
        return object;
    }
}
