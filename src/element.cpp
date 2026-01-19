#include "element.h"

void Element::set_name(StringName p_name) {
    name = p_name;
}

StringName Element::get_name() const {
    return name;
}

Variant Element::get_interaction(StringName p_element) const {
    Variant ret;
    GDVIRTUAL_CALL(_get_interaction, p_element, ret);
    return ret;
}

void Element::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_name", "name"), &Element::set_name);
    ClassDB::bind_method(D_METHOD("get_name"), &Element::get_name);

    // Standardize either using semicolons here or not
    GDVIRTUAL_BIND(_get_interaction);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "name"), "set_name", "get_name");
}