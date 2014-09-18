#include "stdafx.h"
#include "Exception.h"

invalidPosition::invalidPosition(char c)
{
	s = std::string{ "invalid position character [" } +c + "]";
}

unknownObject::unknownObject(std::string string)
{
	s = std::string{ "unknown object [" } +string + "]";
}
