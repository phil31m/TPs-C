#ifndef CONTAINER_H
#define CONTAINER_H

#include "Resource.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Container : public Resource {
private:
    std::string image_;

public:
    Container(std::string id, std::string image, double cpu, double memory);
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    const std::string& getImage() const { return image_; }
    friend std::ostream& operator<<(std::ostream& os, const Container& c);
};

#endif