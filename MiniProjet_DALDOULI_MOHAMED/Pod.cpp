#include "Pod.h"
#include <algorithm>

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
    std::string metrics = "[Pod: " + name_ + "]\n";
    
    for (const auto& container : containers_) {
        metrics += "  " + container->getMetrics() + "\n";
    }
    
    if (!labels_.empty()) {
        metrics += "  Labels: ";
        for (const auto& pair : labels_) {
            metrics += pair.first + "=" + pair.second + " ";
        }
        metrics += "\n";
    }
    
    return metrics;
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