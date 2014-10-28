//! The exception header file
/*!
This is the header file of the exception class.
*/
#pragma once
#include <exception>
#include <string>
class endOfFile : public std::exception {};

class invalidPosition : public std::exception {
public:
	//! The constructor of the invalidPosition exception.
	/*!
	Creates a string which tells what character has an invalid position.
	*/
	invalidPosition(char c);

	//! The what() method of an exception returns a string stating the exception.
	const char * what() const override {
		return s.c_str();
	}

private:
	std::string s;
};

class unknownObject : public std::exception {
public:
	//! The constructor of the unknownObject exception.
	/*!
	Creates a string which specifies what object is unkown
	*/
	unknownObject(std::string string);

	//! The what() method of an exception returns a string stating the exception.
	const char * what() const override {
		return s.c_str();
	}

private:
	std::string s;
};
