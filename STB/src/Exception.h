#pragma once
#include <exception>
#include <string>
class endOfFile : public std::exception {};

class invalidPosition : public std::exception {
public:
	invalidPosition(char c);

	const char * what() const override {
		return s.c_str();
	}

private:
	std::string s;
};

class unknownObject : public std::exception {
public:
	unknownObject(std::string string);

	const char * what() const override {
		return s.c_str();
	}

private:
	std::string s;
};
