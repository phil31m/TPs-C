#ifndef CLOUD_EXCEPTIONS_H
#define CLOUD_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class CloudException : public std::runtime_error {
public:
    explicit CloudException(const std::string& message) : std::runtime_error(message) {}
};

class AllocationException : public CloudException {
public:
    explicit AllocationException(const std::string& message) : CloudException("Allocation Error: " + message) {}
};

class FileException : public CloudException {
public:
    explicit FileException(const std::string& message) : CloudException("File Error: " + message) {}
};

#endif 