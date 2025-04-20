#include "Container.h"

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(id, cpu, memory), image_(image) {}

void Container::start() {
    active_ = true;
    std::cout << "Starting container " << id_ << " (" << image_ << ")\n";
}

void Container::stop() {
    active_ = false;
    std::cout << "Stopping container " << id_ << " (" << image_ << ")\n";
}

std::string Container::getMetrics() const {
    std::string status = active_ ? "Running" : "Stopped";
    return "[Container " + id_ + ": " + image_ + ", " +
           std::to_string(cpu_) + " CPU, " + 
           std::to_string(memory_) + " Memory, " + status + "]";
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}