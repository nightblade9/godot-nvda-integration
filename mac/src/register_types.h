#ifndef NVDA_REGISTER_TYPES_H
#define NVDA_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_nvda_module(ModuleInitializationLevel p_level);
void uninitialize_nvda_module(ModuleInitializationLevel p_level);

#endif
