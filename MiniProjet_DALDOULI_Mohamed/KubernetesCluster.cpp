#include "KubernetesCluster.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(node);
}

bool KubernetesCluster::removeNode(const std::string& id) {
    for (const auto& mapping : podToNodeMapping_) {
        if (mapping.second->getId() == id) {
            return false;
        }
    }
    
    for (size_t i = 0; i < nodes_.size(); i++) {
        if (nodes_[i]->getId() == id) {
            nodes_.erase(nodes_.begin() + i);
            return true;
        }
    }
    return false;
}

bool KubernetesCluster::removePod(const std::string& name) {
    for (size_t i = 0; i < pods_.size(); i++) {
        if (pods_[i]->getName() == name) {
            if (podToNodeMapping_.count(name) > 0) {
                auto& node = podToNodeMapping_[name];
                node->deallocate(pods_[i]->getTotalCpu(), pods_[i]->getTotalMemory());
                podToNodeMapping_.erase(name);
            }
            
            pods_.erase(pods_.begin() + i);
            return true;
        }
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    std::string podName = pod->getName();
    
    try {
        if (schedulePod(*pod)) {
            std::cout << "-> Déploiement du Pod " << *pod << "\n";
            std::cout << "sur le nœud " << *podToNodeMapping_[podName] << "\n";
            pods_.push_back(std::move(pod));
        }
    } catch (const AllocationException& e) {
        throw;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    for (const auto& node : nodes_) {
        if (node->allocate(pod.getTotalCpu(), pod.getTotalMemory())) {
            pod.deploy();
            podToNodeMapping_[pod.getName()] = node;
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    for (const auto& pod : pods_) {
        if (pod->getName() == name) {
            return pod.get();
        }
    }
    return nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::ostringstream oss;
    for (const auto& pod : pods_) {
        oss << pod->getMetrics() << "\n";
    }
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}

std::vector<std::shared_ptr<Server>> KubernetesCluster::getFilteredServers(
    const std::function<bool(const Server&)>& filter) const {
    std::vector<std::shared_ptr<Server>> filtered;
    for (const auto& node : nodes_) {
        if (filter(*node)) {
            filtered.push_back(node);
        }
    }
    return filtered;
}