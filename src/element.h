#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class Element : public Resource {
    GDCLASS(Element, Resource)

public:
    Element() = default;
    ~Element() override = default;

protected:
    static void _bind_methods();
};