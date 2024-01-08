#include "nvda.h"

#include <godot_cpp/core/class_db.hpp>

#include "nvdaController.h"

using namespace godot;

int64_t NVDA::speak_text(const String &p_text) {
	return nvdaController_speakText((const wchar_t *)p_text.utf16().get_data());
}

int64_t NVDA::braille_message(const String &p_text) {
	return nvdaController_brailleMessage((const wchar_t *)p_text.utf16().get_data());
}

int64_t NVDA::is_running() {
	return nvdaController_testIfRunning() == 0;
}

int64_t NVDA::cancel() {
	return nvdaController_cancelSpeech();
}

void NVDA::_bind_methods() {
	ClassDB::bind_static_method("NVDA", D_METHOD("speak_text", "text"), &NVDA::speak_text);
	ClassDB::bind_static_method("NVDA", D_METHOD("braille_message", "text"), &NVDA::braille_message);
	ClassDB::bind_static_method("NVDA", D_METHOD("is_running"), &NVDA::is_running);
	ClassDB::bind_static_method("NVDA", D_METHOD("cancel"), &NVDA::cancel);
}
