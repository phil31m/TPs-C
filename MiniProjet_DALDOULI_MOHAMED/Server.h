#ifndef SERVER_H
#define SERVER_H

#include "Resource.h"
#include <iostream>

class Server : public Resource {
private:
    double available_cpu_;
    double available_memory_;

public:
    Server(std::string id, double cpu, double memory);
    bool allocate(double cpu, double memory);
    void deallocate(double cpu, double memory);
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    friend std::ostream& operator<<(std::ostream& os, const Server& s);
    double getAvailableCpu() const;
    double getAvailableMemory() const;
};

#endif