#include "Point.h"

State_type Point::get_value()
{
    return state;
}

void Point::set_value(State_type s)
{
    // check for set_value validity ???
    state = s;
}
