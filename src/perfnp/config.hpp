// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef PERFNP_CONFIG_H_
#define PERFNP_CONFIG_H_

#include <nlohmann/json.hpp>

#include <string>
#include <vector>

namespace perfnp {

class Config {

    nlohmann::json m_json;

public:

    Config(const nlohmann::json& json)
    : m_json(json)
    {}

    unsigned timeout() const;
    unsigned command() const;
}; // Config
} // perfnp
#endif // PERFNP_CONFIG_H_
