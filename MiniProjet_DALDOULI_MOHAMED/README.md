# Cloud Resource Simulator

This project simulates a cloud environment with Kubernetes clusters, nodes, pods, and containers. It demonstrates resource management, deployment, and scaling operations in a cloud infrastructure.

## Project Structure

- `Resource.h/cpp`: Base class for computing resources (CPU, RAM, Storage)
- `Container.h/cpp`: Container implementation with resource requirements
- `Pod.h/cpp`: Pod implementation that can contain multiple containers
- `Server.h/cpp`: Server (node) implementation with resource capacity
- `KubernetesCluster.h/cpp`: Kubernetes cluster implementation
- `Cloud_Util.h/cpp`: Utility functions for cloud operations
- `main.cpp`: Main program demonstrating the functionality
- `Makefile`: Build configuration

## Building the Project

To build the project, run:
```bash
make
```

To clean the build files:
```bash
make clean
```

## Running the Program

After building, run the program:
```bash
./cloud_simulator
```

## Features

- Create and manage Kubernetes clusters
- Add/remove nodes to clusters
- Deploy pods with multiple containers
- Resource allocation and management
- Simulation of deployment failures due to insufficient resources
- Container and pod lifecycle management

## Requirements

- C++17 compatible compiler
- Make build system

## License

This project is licensed under the MIT License. 