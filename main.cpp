#include <iostream>
#include "Resource.h"
#include "ResourceManager.h"

int main() {
    ResourceManager<Resource> manager1;
    ResourceManager<Resource> manager2;

    manager1.addResource(std::make_unique<Resource>("CPU", 100));
    manager1.addResource(std::make_unique<Resource>("Memory", 256));
    manager1.addResource(std::make_unique<Resource>("Disk", 1000));

    std::cout << "Manager 1:\n";
    manager1.showAllResources();

    // Transfer semantic: prin ID
    uint64_t memId = 2; // Memory are ID 2

    auto transferred = manager1.transferResourceById(memId);
    manager2.receiveResource(std::move(transferred));

    std::cout << "\nManager 1 dupa transfer:\n";
    manager1.showAllResources();

    std::cout << "\nManager 2:\n";
    manager2.showAllResources();

    return 0;
}
