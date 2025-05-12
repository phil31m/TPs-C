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
#include "MetricLogger.h"
#include <algorithm>


int main() {
    std::cout << "=== Test AllocationException direct ===\n";

    try 
    {
        Server failNode("fail-node", 1.0, 1024.0);
        failNode.allocate(4.0, 4096.0); // Trop gros
    }
    catch (const AllocationException& e) 
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Test FileException ===\n";
    KubernetesCluster cluster;
    auto nodeX = std::make_shared<Server>("nodeX", 12.0, 12048.0);
    nodeX->start(); // activer le noeud
    cluster.addNode(nodeX); // cluster non vide
    
    try {
        saveClusterMetrics(cluster, "cluster1_metrics.txt");
        std::cout << "Métriques sauvegardées avec succès." << std::endl;
    } 
    catch (const FileException& e) 
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Test Lambda : serveurs inactifs ===\n";
    KubernetesCluster cluster1;
    auto inactiveServer = std::make_shared<Server>("node3", 2.0, 4096.0); // Ne sera pas activé
    cluster1.addNode(inactiveServer);
    
    auto inactifs = cluster1.getFilteredServers([](const Server& s) {
        return !s.isActive();
    });

    for (const auto& s : inactifs) {std::cout << s->getMetrics() << std::endl;}

    std::cout << "\n=== Déploiement sur un serveur inactif ===\n";
    auto c = std::make_unique<Container>("inactive-c1", "busybox", 1.0, 1024.0);
    auto pod = std::make_unique<Pod>("test-pod");
    pod->addContainer(std::move(c));
    
    try { cluster1.deployPod(std::move(pod));}
    catch (const AllocationException& e) 
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Pods triés par nombre de conteneurs ===\n";
    // Création des conteneurs
    auto c1 = std::make_unique<Container>("c1", "nginx", 2.0, 1024.0);
    auto c2 = std::make_unique<Container>("c2", "redis", 4, 2048.0);
    auto c3 = std::make_unique<Container>("c3", "mysql", 2, 1024.0);
    auto c4 = std::make_unique<Container>("c4", "myapp", 10, 12024.0);
    // Création des pods
    auto pod1 = std::make_unique<Pod>("web-pod");
    pod1->addContainer(std::move(c1));
    pod1->addContainer(std::move(c2));
    auto pod2 = std::make_unique<Pod>("db-pod");
    pod2->addContainer(std::move(c3));
    // Déploiement sans planification réelle, on injecte les pods manuellement
    std::vector<std::unique_ptr<Pod>> pods;
    pods.push_back(std::move(pod1));
    pods.push_back(std::move(pod2));
    
    for (auto& p : pods) {cluster.deployPod(std::move(p));   }
    
    std::vector<const Pod*> podRefs;
    for (const auto& up : cluster.getPods()) {
        podRefs.push_back(up.get());
    }
    std::sort(podRefs.begin(), podRefs.end(), [](const Pod* a, const Pod* b) {
        return a->getContainers().size() > b->getContainers().size();
    });

    std::cout << "\n=== Tri des pods ===\n";
    for (size_t i = 0; i < podRefs.size(); ++i) 
    {
        std::cout << podRefs[i]->getMetrics();
        if (i + 1 < podRefs.size()) std::cout << "\n";
    }
    std::cout << "\n=== Tous les conteneurs du cluster 1 ===\n";
    for (const auto& up : cluster.getPods()) 
    {
        for (const auto& cont : up->getContainers()) 
        {
            std::cout << cont->getMetrics() << std::endl;
        }
    }
    return 0;
}