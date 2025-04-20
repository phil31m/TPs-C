#include "Cloud_Util.h"
#include "KubernetesCluster.h"
#include "Pod.h"
#include "Container.h"
#include "Server.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;

    std::cout << "\n=== Cluster 1 ===\n";
    
    std::vector<KubernetesCluster> clusters(2);

    KubernetesCluster& cluster1 = clusters[0];
    cluster1.addNode(std::make_shared<Server>("node1-1", 4.0, 8192.0));
    cluster1.addNode(std::make_shared<Server>("node1-2", 8.0, 14096.0));

    auto c1_1 = std::make_unique<Container>("c1-1", "nginx:latest", 2, 5120.0);
    auto c1_2 = std::make_unique<Container>("c1-2", "redis:latest", 6, 2560.0);

    auto pod1_1 = std::make_unique<Pod>("web-pod", std::unordered_map<std::string, std::string>{{"app", "nginx"}});
    pod1_1->addContainer(std::move(c1_1));
    pod1_1->addContainer(std::move(c1_2));

    auto c1_3 = std::make_unique<Container>("c1-3", "mysql:latest", 0.7, 1024.0);
    auto pod1_2 = std::make_unique<Pod>("db-pod", std::unordered_map<std::string, std::string>{{"app", "mysql"}});
    pod1_2->addContainer(std::move(c1_3));

    std::vector<std::unique_ptr<Pod>> pods1;
    pods1.push_back(std::move(pod1_1));
    pods1.push_back(std::move(pod1_2));
    deployPods(cluster1, pods1);

    std::cout << "\n=== Test 0 : Déploiement d'un pod avec ressources insuffisantes ===\n";
    auto large_container = std::make_unique<Container>("large-c1", "large-app:latest", 5.0, 10000.0);
    auto large_pod = std::make_unique<Pod>("large-pod", std::unordered_map<std::string, std::string>{{"app", "large"}});
    large_pod->addContainer(std::move(large_container));
    cluster1.deployPod(std::move(large_pod));

    std::cout << "\n=== Cluster 2 ===\n";
    
    KubernetesCluster& cluster2 = clusters[1];
    cluster2.addNode(std::make_shared<Server>("node2-1", 3.0, 6144.0));
    cluster2.addNode(std::make_shared<Server>("node2-2", 1.5, 2048.0));

    auto c2_1 = std::make_unique<Container>("c2-1", "node:latest", 0.6, 768.0);
    auto c2_2 = std::make_unique<Container>("c2-2-2", "memcached:latest", 0.4, 384.0);

    auto pod2_1 = std::make_unique<Pod>("api-pod", std::unordered_map<std::string, std::string>{{"app", "node"}});
    pod2_1->addContainer(std::move(c2_1));

    auto pod2_2 = std::make_unique<Pod>("cache-pod", std::unordered_map<std::string, std::string>{{"app", "memcached"}});
    pod2_2->addContainer(std::move(c2_2));

    std::vector<std::unique_ptr<Pod>> pods2;
    pods2.push_back(std::move(pod2_1));
    pods2.push_back(std::move(pod2_2));
    deployPods(cluster2, pods2);

    std::cout << "\n=== État initial ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    std::cout << "\n=== Test 1 : Suppression du conteneur c1-2 (redis) ===\n";
    Pod* web_pod = clusters[0].getPod("web-pod");
    if (web_pod && web_pod->removeContainer("c1-2")) {
        std::cout << "Conteneur c1-2 supprimé du web-pod\n";
    } else {
        std::cout << "Conteneur c1-2 ou web-pod non trouvé\n";
    }

    std::cout << "\n=== État après suppression du conteneur ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    std::cout << "\n=== Test 2 : Suppression du pod db-pod ===\n";
    if (clusters[0].removePod("db-pod")) {
        std::cout << "Pod db-pod supprimé du cluster 1\n";
    } else {
        std::cout << "Pod db-pod non trouvé\n";
    }

    std::cout << "\n=== État après suppression du pod ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    std::cout << "\n=== Test 3 : Suppression du cluster 2 ===\n";
    clusters.erase(clusters.begin() + 1);

    std::cout << "\n=== État après suppression du cluster ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }

    return 0;
}