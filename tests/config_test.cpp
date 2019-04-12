// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "perfnp/config.hpp"
#include "catch.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>//setw
#include <cstdint>

using namespace perfnp;
using namespace std;
// for convenience
using json = nlohmann::json;


TEST_CASE("Config::timeout")
{
std::ifstream f("config.json");
json j;
f >> j;

/*//different type of outputs
// the setw manipulator was overloaded to set the indentation for pretty printing
std::cout << std::setw(4) << j << "\n"<< std::endl;

// iterate the array
for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << *it << "\n";

// special iterator member functions for objects
  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    std::cout << it.key() << " : " << it.value()  <<"\n";
  }
}*/

json jf = j["command"].at("file");
json jb = j.at("command").at("blockvar");


string ss=jf[0].get<string>();
string b=jb[0].get<string>();
cout << "set file: " << ss<< "\n";
cout<<"Number of available files: " << jf.size() << endl;
cout << "set blockvar: " << b<< "\n";
cout<<"Number of blockvar options: " << jb.size() << endl;

SECTION("command")
{
    Config c(j);
    //REQUIRE(c.timeout() == 60);
    REQUIRE_THROWS_AS(c.command(), std::runtime_error);
}
SECTION("timeout")
{
    Config c(j);
    //REQUIRE(c.timeout() == 60);
    REQUIRE_THROWS_AS(c.timeout(), std::runtime_error);
}
return;
}

/*TEST_CASE("Config::timeout")
{
    SECTION("standard operation")
    {
        Config c(R"({
            "config" : 10
        })"_json);

        REQUIRE(c.timeout() == 10);
    }

    SECTION("field is missing")
    {
        Config c(R"({})"_json);
        REQUIRE_THROWS_AS(c.timeout(), std::runtime_error);
    }

    SECTION("field has invalid type")
    {
        Config c(R"({"config":"hello"})"_json);
        REQUIRE_THROWS_AS(c.timeout(), std::runtime_error);
    }
}*/
