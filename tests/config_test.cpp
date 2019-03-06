// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "perfnp/config.hpp"

#include "catch.hpp"

using namespace perfnp;

TEST_CASE("Config read + write")
{
    nlohmann::json j = R"({
        "config":10
    })"_json;

    perfnp::Config conf(j);
    REQUIRE(conf.timeout() == 10);
}
