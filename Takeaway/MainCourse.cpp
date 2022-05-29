#include "MainCourse.h"

std::string MainCourse::toString()
{

	return (name + ": " + char(156) + to_string(price).substr(0,4) + ", " + to_string(calories) + " cal ");
}