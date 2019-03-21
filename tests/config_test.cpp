// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "perfnp/config.hpp"

#include "catch.hpp"

using namespace perfnp;

TEST_CASE("Config::timeout")
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
}
