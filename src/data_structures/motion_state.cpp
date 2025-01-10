#include "yeastcpp/data_structures/motion_state.hpp"

namespace yeast_motion
{
    MotionState::MotionState ()
    {

    }
    
    MotionState::MotionState(nlohmann::json json)
    {
        // TODO: Implement.
        this->from_json(json);
    }

    void MotionState::from_json(nlohmann::json json)
    {
        // TODO: Implement.
        this->measurement = MotionSample(json["measurement"]);
        this->reference = MotionSample(json["reference"]);
    }

    nlohmann::json MotionState::to_json(void)
    {
        nlohmann::json object;
        object["measurement"] = measurement.to_json();
        object["reference"] = reference.to_json();
        return object;
    }
}