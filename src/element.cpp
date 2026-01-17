#include "element.h"

void Element::set_name(String p_name) {
    name = p_name;
}

String Element::get_name() const {
    return name;
}

void Element::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_name", "name"), &Element::set_name);
    ClassDB::bind_method(D_METHOD("get_name"), &Element::get_name);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
}