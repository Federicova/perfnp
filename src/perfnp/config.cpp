// Copyright (c) 2019 Locksley.CZ s.r.o.
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "perfnp/config.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cassert>
#include <string>

using namespace perfnp;
using namespace std;

unsigned Config::timeout() const
{

    if (m_json.find("timeout") == m_json.end()) {
        throw std::runtime_error("Configuration JSON "
        "does not have the \"timeout\" field.");
    }
    else
    {
        cout << "Configuration JSON "
        "has the \"timeout\" field." << endl;
    }

    if (!m_json.at("timeout").is_number()) {
        throw std::runtime_error("Configuration JSON's"
            " \"timeout\" field is not a number.");
    }
    else
    {
        cout<< "Configuration JSON's"
            " \"timeout\" field is a number."<<endl;
    }
    return m_json.at("timeout").get<unsigned>();
}

unsigned Config::command() const
{
    if (m_json.find("command") == m_json.end()) {
        throw std::runtime_error("Configuration JSON"
            " does not have the \"command\" field.");
    }
    else
    {
        cout << "Configuration JSON has the \"command\" field." << endl;
    }
    if (!m_json.at("command").is_object())
    {
        throw std::runtime_error("The \"command\" field is not an object.");
    }
    else
    {
        cout<<"The \"command\" field is an object."<<endl;
    }

    if (m_json.at("command").find("program") != m_json.at("command").end()) {

            cout<<"The \"program\" field is present."<<endl;
        }

    else {
                 throw std::runtime_error("The \"program\" field is missing.");
         }

     if (!m_json.at("command").at("program").is_string()) {

             throw std::runtime_error("The \"program\" field has invalid type.");
         }

     else {
                 cout<<"The \"program\" field is string."<<endl;
          }

    if (m_json.at("command").find("blockvar") != m_json.at("command").end()) {

            cout<<"The \"blockvar\" field is present."<<endl;
        }

    else {
             throw std::runtime_error("The \"blockvar\" field is missing.");
         }

    if (m_json.at("command").find("file") != m_json.at("command").end()) {

         cout<<"The \"file\" field is present."<<endl;
     }

    else {
             throw std::runtime_error("The \"file\" field is missing.");
      }
    return 0;
}
