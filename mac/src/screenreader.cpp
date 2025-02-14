#include "screenreader.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

// These are nulled out methods for now.
// This way you can still compile in Linux.
// Preferably, this should extend Orca in the future or something.
// It's called "NVDA" but might want to be changed to something else in the future.

int64_t NVDA::speak_text_modifier(const String &p_text, const String &lang, float speed) {
	return 0;
}

int64_t NVDA::speak_text(const String &p_text) {
	return 0;
}

int64_t NVDA::braille_message(const String &p_text) {
	return 0;
}

bool NVDA::is_running() {
	return false;
}

int64_t NVDA::cancel() {
	return 0;
}

void NVDA::_bind_methods() {
	ClassDB::bind_static_method("NVDA", D_METHOD("speak_text_modifier", "text", "lang", "speed"), &NVDA::speak_text_modifier);
	ClassDB::bind_static_method("NVDA", D_METHOD("speak_text", "text"), &NVDA::speak_text);
	ClassDB::bind_static_method("NVDA", D_METHOD("braille_message", "text"), &NVDA::braille_message);
	ClassDB::bind_static_method("NVDA", D_METHOD("is_running"), &NVDA::is_running);
	ClassDB::bind_static_method("NVDA", D_METHOD("cancel"), &NVDA::cancel);
}
