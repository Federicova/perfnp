// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "perfnp/config.hpp"

#include <stdexcept>
#include <cassert>

using namespace perfnp;

unsigned Config::timeout() const
{
    if (m_json.find("config") == m_json.end()) {
        throw std::runtime_error("Configuration JSON"
            " does not have the \"config\" field.");
    }

    if (!m_json.at("config").is_number()) {
        throw std::runtime_error("Configuration JSON's"
            " \"config\" field is not a number.");
    }

    return m_json.at("config").get<unsigned>();
}
