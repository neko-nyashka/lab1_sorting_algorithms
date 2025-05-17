#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <iostream>
class Flight
{
private:
    std::string flight_number;
    std::string airline;
    std::string arrival_date;
    std::string arrival_time;
    int passengers;

public:
    Flight();
    Flight(std::string flight_number_, std::string airline_, std::string arrival_date_, std::string arrival_time_, int passengers_); 
    ~Flight() = default;
    bool operator>(const Flight& other) const;
    bool operator<(const Flight& other) const;
    bool operator<=(const Flight& other) const;
    bool operator>=(const Flight& other) const;
    bool operator==(const Flight& other) const;
    Flight& operator=(const Flight& other) = default;
    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
};

#endif