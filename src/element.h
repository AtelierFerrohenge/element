#pragma once

#include "godot_cpp/classes/resource.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class Element : public Resource {
    GDCLASS(Element, Resource)

public:
    Element() = default;
    ~Element() override = default;

    void set_name(StringName p_name);
    StringName get_name() const;

    virtual Variant get_interaction(StringName element) const;

protected:
    static void _bind_methods();

    GDVIRTUAL1RC_REQUIRED(Variant, _get_interaction, StringName)

private:
    StringName name = "";
};