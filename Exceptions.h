#pragma once
#include <exception>
#include <string>

namespace Exceptions {
	/**
	* This exception is thrown when there is a problem opening file.
	*/
	class FileOpenException : public std::runtime_error {
	public:
		FileOpenException() : std::runtime_error("Cannot open the file") { }
		FileOpenException(std::string fileName) : std::runtime_error(fileName.c_str()) { }
	}; 

	/**
	* This exception is thrown when one of the input value is invalid.
	*/
	class InvalidInputValueException : public std::runtime_error {
	public:
		InvalidInputValueException() : std::runtime_error("One of the input values is ivalid.") { }
		InvalidInputValueException(std::string message) : std::runtime_error(message.c_str()) { }
	};
}