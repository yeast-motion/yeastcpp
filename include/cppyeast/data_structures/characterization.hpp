#pragma once

#include <iostream>
#include <map>

#include <nlohmann/json.hpp>

#include "cppyeastdefinitions/json_parsable.hpp"

class Characterization : JSONParsable
{
    public:
    class NumericRecord
    {
        std::string key;
        float value;
    }; 
    
    class StringRecord
    {
        std::string key;
        std::string value;
    };
    
    float get_numeric_record(std::string key);
    std::string get_string_record(std::string key);

    Characterization(nlohmann::json json);
    nlohmann::json to_json();
    void from_json(nlohmann::json json);

    private:
    std::map<std::string, float> numeric_records;
    std::map<std::string, std::string> string_records;
};