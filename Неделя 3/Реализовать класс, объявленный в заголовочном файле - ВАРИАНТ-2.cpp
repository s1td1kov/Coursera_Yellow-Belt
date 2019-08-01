#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream is(international_number);
    if (is.peek() == '+') {    
        is.ignore(1);
        int country_code;
        if (is >> country_code) {
            country_code_ = to_string(country_code);
            int city_code;
            if (is.peek() == '-') {
                is.ignore(1);
                if (is >> city_code) {
                    city_code_ = to_string(city_code);
                    if (is.peek() == '-') {
                        is.ignore(1);
                        is >> local_number_;
                    } else {
                        throw invalid_argument("");
                    }
                } else {
                    throw invalid_argument("");
                }
            } else {
                throw invalid_argument("");
            }
        } else {
            throw invalid_argument("");
        }
    } else {
        throw invalid_argument("");
    }
}

string PhoneNumber::GetCountryCode() const {
    return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const {
    return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}
