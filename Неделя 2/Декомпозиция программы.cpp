#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <tuple>
#include <utility>
#include <cmath>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation;
    is >> operation;
    if (operation == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    } else if (operation == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (operation == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (operation == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (auto& now : q.stops) {
            is >> now;
        }
    }
    return is;
}

struct BusesForStopResponse {
    string stop;
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.count(r.stop) == 0) {
        os << "No stop";
    } else {
        for (const auto& bus : r.buses.at(r.stop)) {
            os << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus";
    } else {
        int i = 0;
        for (const auto& stop : r.stops) {
            ++i;
            os << "Stop " << stop.first << ":";
            if (stop.second.size() == 1) {
                os << " no interchange";
                os << endl;
            } else {
                for (const auto& bus : stop.second) {
                    if (bus != r.bus)
                    os << " " << bus;
                }
                if (i != r.stops.size())
                    os << endl;
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses.empty()) {
        cout << "No buses";
    } else {
        int i = 0;
        for (const auto& now : r.buses) {
            ++i;
            os << "Bus " << now.first << ":";
            for (const auto& temp : r.buses.at(now.first)) {
                os << " " << temp;
            }
            if (i != r.buses.size()) {
                os << endl;
            }
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        stops_for_bus[bus] = stops;
        for (const auto& stop : stops) {
            buses_for_stop[stop].push_back(bus);
        }
    }
    
    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if (buses_for_stop.count(stop) == 0) {
            return {};
        } else {
            return BusesForStopResponse{stop, buses_for_stop};
        }
    }
    
    StopsForBusResponse GetStopsForBus(const string& bus) const {
        vector<pair<string, vector<string>>> result;
        
        if (stops_for_bus.count(bus) > 0) {
            for (const auto& stop : stops_for_bus.at(bus)) {
                result.push_back(make_pair(stop, buses_for_stop.at(stop)));
            }
        }
        return StopsForBusResponse{bus, result};
    }
    
    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse{stops_for_bus};
    }
private:
    map<string, vector<string>> buses_for_stop;
    map<string, vector<string>> stops_for_bus;
};

int main() {
    
}
