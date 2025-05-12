#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
protected:
    std::string id_;
    double cpu_;
    double memory_;
    bool active_;

public:
    Resource(std::string id, double cpu, double memory);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual std::string getMetrics() const = 0;
    
    std::string getId() const { return id_; }
    double getCpu() const { return cpu_; }
    double getMemory() const { return memory_; }
    bool isActive() const { return active_; }
    
    virtual ~Resource() = default;
};

#endif