#pragma once
#include "IResource.h"
#include <string>

// ---- Resursa concreta ----
class Resource : public IResource {
private: 
    static inline ResourceId nextId = 1;

    ResourceId id;
    std::string name;
    int value;

public:
    Resource(const std::string& n, int v)
        : id(nextId++), name(n), value(v) {}
    ~Resource() override = default;

    const std::string& getName() const override { return name; }
    int getValue() const override { return value; }

    void setValue(int newValue) override { value = newValue; }

    ResourceId getId() const override { return id; }
};