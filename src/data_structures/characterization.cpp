#include "yeastcpp/data_structures/characterization.hpp"

namespace yeast_motion
{
    Characterization::Characterization(nlohmann::json json)
    {
        // TODO: Implement.
    }

    void Characterization::from_json(nlohmann::json json)
    {
        // TODO: Implement.
    }

    float Characterization::get_numeric_record(std::string key)
    {
        // TODO: Implement.
        return 195.0;
    }

    std::string Characterization::get_string_record(std::string key)
    {
        // TODO: Implement.
        return "Todd Sucks";
    }

    nlohmann::json Characterization::to_json(void)
    {
        // TODO: Implement.
        return nlohmann::json();
    }
}