#include "flight.h"
/**
 * Default constructor. Initializes all fields to empty/zero values.
 */

Flight::Flight() {
    flight_number = "";
    airline = "";
    arrival_date = "";
    arrival_time = "";
    passengers = 0;
}

/**
 * Parameterized constructor. Initializes fields with provided values.
 * 
 * @param flight_number_ Flight number (e.g., "SU123").
 * @param airline_ Airline name (e.g., "Aeroflot").
 * @param arrival_date_ Arrival date (e.g., "2023-10-15").
 * @param arrival_time_ Arrival time (e.g., "14:30").
 * @param passengers_ Passenger count (e.g., 150).
 */

Flight::Flight(std::string flight_number_, std::string airline_, std::string arrival_date_, std::string arrival_time_, int passengers_) {
    flight_number = flight_number_;
    airline = airline_;
    arrival_date = arrival_date_;
    arrival_time = arrival_time_;
    passengers = passengers_;
}

bool Flight::operator>(const Flight& other) const {
    if (arrival_date != other.arrival_date) {
        return (arrival_date > other.arrival_date);
    }
    if (arrival_time != other.arrival_time) { 
        return (arrival_time > other.arrival_time);
    }
    if (airline != other.airline) {
        return airline > other.airline;
    }
    return passengers > other.passengers;  
}

bool Flight::operator>=(const Flight& other) const {
    if (arrival_date != other.arrival_date) return arrival_date > other.arrival_date;
    if (arrival_time != other.arrival_time) return arrival_time > other.arrival_time;
    if (airline != other.airline) return airline > other.airline;
    return passengers <= other.passengers;  
}

bool Flight::operator<(const Flight& other) const {
    return !(*this >= other);  
}

bool Flight::operator<=(const Flight& other) const {
    return !(*this > other);  
}

bool Flight::operator==(const Flight& other) const {
    return arrival_date == other.arrival_date &&
           arrival_time == other.arrival_time &&
           airline == other.airline &&
           passengers == other.passengers;
}


std::ostream& operator<<(std::ostream& os, const Flight& flight) {
    os << flight.flight_number << " " << flight.airline << " " << flight.arrival_date << " " << flight.arrival_time << " " << flight.passengers;
    return os;
}

