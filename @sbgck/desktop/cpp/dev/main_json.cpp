#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char **argv)
{
    // https://github.com/nlohmann/json

    auto j = json::parse("{ \"happy\": true, \"name\": \"foo\", \"pi\": 3.141 }");

    // explicit conversion to string
    std::string s = j.dump();
    std::cout << s << std::endl;

    // serialization with pretty printing
    // pass in the amount of spaces to indent
    std::cout << j.dump(4) << std::endl;


    float pi = j["pi"].get<float>();
    bool happy = j["happy"].get<bool>();
    std::string name = j["name"].get<std::string>();


    std::cout << pi << " " <<  happy << " " <<  name << std::endl;

    return 0;
}
