#include "Pod.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(name), labels_(labels) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id) {
    for (size_t i = 0; i < containers_.size(); i++) {
        if (containers_[i]->getId() == id) {
            containers_.erase(containers_.begin() + i);
            return true;
        }
    }
    return false;
}

void Pod::deploy() {
    for (const auto& container : containers_) {
        container->start();
    }
}

std::string Pod::getMetrics() const {
    std::ostringstream oss;
    oss << "[Pod: " << name_ << "]\n";
    for (size_t i = 0; i < containers_.size(); ++i) {
        oss << containers_[i]->getMetrics();
        if (i + 1 < containers_.size()) oss << "\n";
    }
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}

const std::string& Pod::getName() const {
    return name_;
}

double Pod::getTotalCpu() const {
    double total = 0.0;
    for (const auto& container : containers_) {
        total += container->getCpu();
    }
    return total;
}

double Pod::getTotalMemory() const {
    double total = 0.0;
    for (const auto& container : containers_) {
        total += container->getMemory();
    }
    return total;
}