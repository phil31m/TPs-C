#include "KubernetesCluster.h"
#include <algorithm>

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
    
    if (schedulePod(*pod)) {
        std::cout << "-> Deploying Pod " << *pod << "\n";
        std::cout << "on node " << *podToNodeMapping_[podName] << "\n";
        pods_.push_back(std::move(pod));
        std::cout << "Pod deployed successfully.\n";
    } else {
        std::cout << "Deployment failed: insufficient resources.\n";
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
    std::string metrics = "=== Kubernetes Cluster Metrics ===\n";
    
    metrics += "Nodes:\n";
    for (const auto& node : nodes_) {
        metrics += "  " + node->getMetrics() + "\n";
    }
    
    metrics += "Pods:\n";
    for (const auto& pod : pods_) {
        metrics += pod->getMetrics() + "\n";
    }
    
    metrics += "Pod to Node Mapping:\n";
    for (const auto& mapping : podToNodeMapping_) {
        metrics += "  Pod '" + mapping.first + "' is hosted on Node '" + mapping.second->getId() + "'\n";
    }
    
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}