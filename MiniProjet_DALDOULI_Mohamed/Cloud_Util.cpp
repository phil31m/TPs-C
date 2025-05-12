#include "Cloud_Util.h"
#include <sstream>
#include <iomanip>
#include <iostream>

std::string generateRandomId(const std::string& prefix) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 9999);
    
    std::stringstream ss;
    ss << prefix << "-" << std::setw(4) << std::setfill('0') << dis(gen);
    return ss.str();
}

std::unique_ptr<Container> createContainer(const std::string& image, double cpu, double memory) {
    std::string id = generateRandomId("container");
    return std::make_unique<Container>(id, image, cpu, memory);
}

std::unique_ptr<Pod> createPod(const std::string& name, 
                               const std::vector<std::unique_ptr<Container>>& containers,
                               const std::unordered_map<std::string, std::string>& labels) {
    auto pod = std::make_unique<Pod>(name, labels);
    
    for (size_t i = 0; i < containers.size(); i++) {
        if (containers[i]) {
            pod->addContainer(std::move(const_cast<std::unique_ptr<Container>&>(containers[i])));
        }
    }
    
    return pod;
}

std::shared_ptr<Server> createServer(double cpu, double memory) {
    std::string id = generateRandomId("node");
    auto server = std::make_shared<Server>(id, cpu, memory);
    server->start();
    return server;
}

bool scalePod(KubernetesCluster& cluster, const std::string& podName, int replicas) {
    return false;
}

void autoScalePods(KubernetesCluster& cluster, double cpuThreshold, double memoryThreshold) {
}

void display(const KubernetesCluster& cluster) {
    std::cout << cluster;
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        try {
            std::cout << "-> Déploiement du Pod " << *pod << std::endl;
            cluster.deployPod(std::move(pod));
        } catch (const AllocationException& e) {
            std::cerr << "Exception capturée : " << e.what() << std::endl;
        }
    }
    pods.clear();
}

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileException("Impossible d'ouvrir le fichier " + filename);
    }
    file << cluster.getMetrics();
    std::cout << "Métriques sauvegardées avec succès." << std::endl;
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    const auto& pods = cluster.getPods();
    for (const auto& pod : pods) {
        const auto& containers = pod->getContainers();
        for (const auto& container : containers) {
            func(*container);
        }
    }
}