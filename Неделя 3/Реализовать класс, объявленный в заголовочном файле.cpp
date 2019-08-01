#include <algorithm>
#include <stdexcept>
#include <string>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream is(international_number);
    char sign = is.get();
    getline(is, country_code_, '-');
    getline(is, city_code_, '-');
    getline(is, local_number_);
    
    if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
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
