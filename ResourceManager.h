#pragma once
#include <memory>
#include <vector>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include "IResource.h"

// ---- Manager resursei ----
template<typename T>
class ResourceManager
{
private:
    std::vector<std::unique_ptr<T>> resources;

public:
    // adaugare resursa
    void addResource(std::unique_ptr<T> r) {
        if (r)
            resources.push_back(std::move(r));
    }

    // transfera ownership ul unei resurse
    std::unique_ptr<T> transferResourceById(IResource::ResourceId id) {
        for (size_t i = 0; i < resources.size(); ++i) {
            if (resources[i]->getId() == id) {
                auto ptr = std::move(resources[i]);
                resources.erase(resources.begin() + i);
                return ptr;
            }
        }
        return nullptr;
    }

    // primeste o resursa transferata
    void receiveResource(std::unique_ptr<T> r) {
        if (r)
            resources.push_back(std::move(r));
    }


    // afiseaza toate resursele
    void showAllResources() const {
        for (const auto& r : resources) {
            std::cout << "[" << r->getId() << "] "
                      << r->getName() << " = "
                      << r->getValue() << "\n";
        }
    }

    void modifyResourceById(uint64_t id, int newValue) {
        for (auto& r : resources) {
            if (r->getId() == id) {
                r->setValue(newValue);
                return;
            }
        }
    }

    size_t getResourceCount() const { return resources.size(); }
};