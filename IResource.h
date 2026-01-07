#pragma once
#include <string>
#include <cstdint>

// ---- Interfata resursei ----
class IResource {
public:
    using ResourceId = uint64_t; // un alias de tip

    virtual ~IResource() = default;

    virtual const std::string& getName() const = 0;
    virtual int getValue() const = 0;
    virtual void setValue(int newValue) = 0;

    virtual ResourceId getId() const = 0;
    // fiecare resursa are un id
};
