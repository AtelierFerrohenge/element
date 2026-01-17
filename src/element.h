#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class Element : public Resource {
    GDCLASS(Element, Resource)

public:
    Element() = default;
    ~Element() override = default;

    void set_name(String p_name);
    String get_name() const;

protected:
    static void _bind_methods();

private:
    String name = "";
};