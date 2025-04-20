#ifndef CLOUD_UTIL_H
#define CLOUD_UTIL_H

#include "KubernetesCluster.h"
#include "Pod.h"
#include "Container.h"
#include "Server.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>

std::string generateRandomId(const std::string& prefix);

std::unique_ptr<Container> createContainer(const std::string& image, double cpu, double memory);

std::unique_ptr<Pod> createPod(const std::string& name, 
                              const std::vector<std::unique_ptr<Container>>& containers,
                              const std::unordered_map<std::string, std::string>& labels = {});

std::shared_ptr<Server> createServer(double cpu, double memory);

bool scalePod(KubernetesCluster& cluster, const std::string& podName, int replicas);

void autoScalePods(KubernetesCluster& cluster, double cpuThreshold, double memoryThreshold);

void display(const KubernetesCluster& cluster);

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

#endif