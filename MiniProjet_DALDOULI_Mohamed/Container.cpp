#include "Container.h"
#include <iomanip>
#include <sstream>

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
    std::ostringstream oss;
    oss << "[Container: " << id_ << " : " << static_cast<int>(cpu_) << " CPU, " << static_cast<int>(memory_) << " Memory, " << image_ << " ]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}