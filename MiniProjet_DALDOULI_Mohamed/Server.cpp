#include "Server.h"

Server::Server(std::string id, double cpu, double memory)
    : Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    if (!active_) {
        throw AllocationException("Serveur " + id_ + " est inactif");
    }
    if (cpu > available_cpu_ || memory > available_memory_) {
        throw AllocationException("Ressources insuffisantes sur le serveur " + id_);
    }
    available_cpu_ -= cpu;
    available_memory_ -= memory;
    return true;
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
    std::ostringstream oss;
    oss << "[Server: " << std::left << std::setw(10) << id_ << " | "
        << "Total: " << std::setw(4) << cpu_ << " CPU, " << std::setw(6) << memory_ << " MB | "
        << "Free: " << std::setw(4) << available_cpu_ << " CPU, " << std::setw(6) << available_memory_ << " MB]";
    return oss.str();
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

bool Server::isActive() const {
    return active_;
}