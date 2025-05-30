#include "AEROFLOT.h"
AEROFLOT::AEROFLOT() : flight_number(0) {
    strcpy_s(destination, "");
    strcpy_s(paircraft_type, "");
}

AEROFLOT::AEROFLOT(const char* n, int f, const char* p)
{
    strcpy_s(destination, n);
    strcpy_s(paircraft_type, p);
    flight_number = f;
}

AEROFLOT::AEROFLOT(const AEROFLOT& m) : flight_number(m.flight_number) {
    strcpy_s(destination, 20, m.destination);
    strcpy_s(paircraft_type, 10, m.paircraft_type);
}
bool AEROFLOT::compNumber(AEROFLOT& a, AEROFLOT& b)
{
    return a.flight_number < b.flight_number;
}

bool AEROFLOT::compDestination(AEROFLOT& a, AEROFLOT& b)
{

    return strcmp(a.destination, b.destination) < 0;

}

bool AEROFLOT::operator==(const AEROFLOT& w) const
{
    return (flight_number == w.flight_number) &&
        (strcmp(destination, w.destination) == 0) &&
        (strcmp(paircraft_type, w.paircraft_type) == 0);
}

bool AEROFLOT::operator<(const AEROFLOT& m)
{
    return strcmp(destination, m.destination);
}

bool AEROFLOT::operator>(const AEROFLOT& m)
{
    return strcmp(destination, m.destination);
}

ostream& operator<<(ostream& os, const AEROFLOT& m)
{
        os << m.destination << " " << m.flight_number << " " << m.paircraft_type << " ";
        return os;
}

istream& operator>>(istream& is, AEROFLOT& m)
{
        is >> m.destination >> m.flight_number >> m.paircraft_type;
        return is;
}
