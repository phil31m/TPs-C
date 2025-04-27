#include <iostream>
#include <stdexcept>

class NegativeQuantityException : public std::runtime_error {
public:
    NegativeQuantityException() : std::runtime_error("Negative quantity is not allowed") {}
};

class InsufficientStockException : public std::runtime_error {
public:
    InsufficientStockException() : std::runtime_error("Insufficient stock") {}
};

// Template général pour la classe Inventory
template<typename T>
class Inventory {
private:
    T stock;

public:
    Inventory(T initial_stock) : stock(initial_stock) {}

    void add_items(T quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        stock += quantity;
    }

    void remove_items(T quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        if (quantity > stock) {
            throw InsufficientStockException();
        }
        stock -= quantity;
    }

    T get_stock() const {
        return stock;
    }
};

// Spécialisation pour les entiers
template<>
class Inventory<int> {
private:
    int stock;

public:
    Inventory(int initial_stock) : stock(initial_stock) {}

    void add_items(int quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        stock += quantity;
    }

    void remove_items(int quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        if (quantity > stock) {
            throw InsufficientStockException();
        }
        stock -= quantity;
    }

    int get_stock() const {
        return stock;
    }
};

// Spécialisation pour les doubles
template<>
class Inventory<double> {
private:
    double stock;

public:
    Inventory(double initial_stock) : stock(initial_stock) {}

    void add_items(double quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        stock += quantity;
    }

    void remove_items(double quantity) {
        if (quantity < 0) {
            throw NegativeQuantityException();
        }
        if (quantity > stock) {
            throw InsufficientStockException();
        }
        stock -= quantity;
    }

    double get_stock() const {
        return stock;
    }
};

int main() {
    // Test avec des entiers
    try {
        Inventory<int> inv(100);
        std::cout << "Initial stock (int): " << inv.get_stock() << std::endl;
        inv.add_items(50);
        std::cout << "After adding 50 items: " << inv.get_stock() << std::endl;
        inv.remove_items(30);
        std::cout << "After removing 30 items: " << inv.get_stock() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    // Test avec des doubles
    try {
        Inventory<double> doubleInv(100.5);
        std::cout << "Initial stock (double): " << doubleInv.get_stock() << std::endl;
        doubleInv.add_items(25.5);
        std::cout << "After adding 25.5 items: " << doubleInv.get_stock() << std::endl;
        doubleInv.remove_items(10.2);
        std::cout << "After removing 10.2 items: " << doubleInv.get_stock() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
} 