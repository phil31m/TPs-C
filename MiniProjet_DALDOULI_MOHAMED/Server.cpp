#include "Server.h"

Server::Server(std::string id, double cpu, double memory)
    : Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    if (cpu <= available_cpu_ && memory <= available_memory_) {
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    return false;
}

void Server::deallocate(double cpu, double memory) {
    if (available_cpu_ + cpu > cpu_) {
        std::cerr << "Warning: Attempting to deallocate more CPU than was allocated on server " << id_ << std::endl;
        available_cpu_ = cpu_;
    } else {
        available_cpu_ += cpu;
    }
    
    if (available_memory_ + memory > memory_) {
        std::cerr << "Warning: Attempting to deallocate more memory than was allocated on server " << id_ << std::endl;
        available_memory_ = memory_;
    } else {
        available_memory_ += memory;
    }
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

std::string Server::getMetrics() const {
    std::string status = active_ ? "Running" : "Stopped";
    return "[Server: " + id_ + ": " + std::to_string(cpu_) + " CPU, " + 
           std::to_string(memory_) + " Memory, Available: " + 
           std::to_string(available_cpu_) + " CPU, " + 
           std::to_string(available_memory_) + " Memory, " + status + "]";
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}

double Server::getAvailableCpu() const {
    return available_cpu_;
}

double Server::getAvailableMemory() const {
    return available_memory_;
}