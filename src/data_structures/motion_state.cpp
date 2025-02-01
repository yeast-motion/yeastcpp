#include "yeastcpp/data_structures/motion_state.hpp"

namespace yeast_motion
{
    MotionState::MotionState ()
    {

    }

    MotionState::MotionState(nlohmann::json json)
    {
        this->from_json(json);
    }

    void MotionState::from_json(nlohmann::json json)
    {
        this->measurement.from_json(json["measurement"]);
        this->reference.from_json(json["reference"]);
    }

    nlohmann::json MotionState::to_json(void) const
    {
        nlohmann::json object;
        object["measurement"] = measurement.to_json();
        object["reference"] = reference.to_json();
        return object;
    }
}