#ifndef KUBERNETESCLUSTER_H
#define KUBERNETESCLUSTER_H

#include "Server.h"
#include "Pod.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class KubernetesCluster {
private:
    std::vector<std::shared_ptr<Server>> nodes_;
    std::vector<std::unique_ptr<Pod>> pods_;
    std::unordered_map<std::string, std::shared_ptr<Server>> podToNodeMapping_; 

public:
    const std::vector<std::unique_ptr<Pod>>& getPods() const { return pods_; }
    void addNode(std::shared_ptr<Server> node);
    bool removeNode(const std::string& id);
    bool removePod(const std::string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    bool schedulePod(Pod& pod);
    Pod* getPod(const std::string& name);
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};

#endif