#include "nvda.h"

#include <godot_cpp/core/class_db.hpp>

#include "nvdaController.h"

using namespace godot;

// this allows you to add language and speed modifiers to text.
// pitch and volume are not supported.
int64_t NVDA::speak_text_modifier(const String &p_text, const String &lang, float speed) {

	// speech modifiers values
	const float ___DEFAULT_SPEED = 1.0f;
	
	// constrains speed values
	if(speed > 1.0f){
		speed = 1.0f;
	}
	
	if(speed < 0.5f){
		speed = 0.5f;
	}

	// if this value is not 0, it will ignore attempts to read ssml modifiers.
	int64_t ssml_success = 1;

	const wchar_t* base_text = (const wchar_t*)p_text.utf16().get_data();
	const wchar_t* language = (const wchar_t*)lang.utf16().get_data();

	// Checks if any modifiers are to be applied. If none, just read text normally.
	if(speed != ___DEFAULT_SPEED || wcslen(language) > 0) {
		
		String p_text_decorated = String("<speak>");
		
		// add language open tag, if applicable
		if (wcslen(language) > 0)
			p_text_decorated += String("<voice xml:lang=\"{0}\">").format(Array::make(lang));
		
		// add speed tag, if applicable
		if (speed != ___DEFAULT_SPEED)
			p_text_decorated += String("<prosody rate=\"{0}%\">").format(Array::make(int(speed * 100 + 0.5)));
		
		
		p_text_decorated += p_text;
		
		
		// add language close tag, if applicable
		if (speed != ___DEFAULT_SPEED)
			p_text_decorated += "</prosody>";
		
		// add language close tag, if applicable
		if (wcslen(language) > 0)
			p_text_decorated += "</voice>";
		
		p_text_decorated += "</speak>";
		
		ssml_success = nvdaController_speakSsml((const wchar_t*)p_text_decorated.utf16().get_data(), SYMBOL_LEVEL_UNCHANGED, SPEECH_PRIORITY_NORMAL, true);

		if (ssml_success != 0)
		{
			return nvdaController_speakText((const wchar_t*)p_text.utf16().get_data());
		}

		return ssml_success;
	}
	
	return nvdaController_speakText((const wchar_t*)p_text.utf16().get_data());
}

int64_t NVDA::speak_text(const String &p_text) {
	return nvdaController_speakText((const wchar_t*)p_text.utf16().get_data());
}

int64_t NVDA::braille_message(const String &p_text) {
	return nvdaController_brailleMessage((const wchar_t *)p_text.utf16().get_data());
}

bool NVDA::is_running() {
	// Zero is a win; anything else is an error status code (error_status_t or int64_t)
	return nvdaController_testIfRunning() == 0;
}

int64_t NVDA::cancel() {
	return nvdaController_cancelSpeech();
}

void NVDA::_bind_methods() {
	ClassDB::bind_static_method("NVDA", D_METHOD("speak_text_modifier", "text", "lang", "speed"), &NVDA::speak_text_modifier);
	ClassDB::bind_static_method("NVDA", D_METHOD("speak_text", "text"), &NVDA::speak_text);
	ClassDB::bind_static_method("NVDA", D_METHOD("braille_message", "text"), &NVDA::braille_message);
	ClassDB::bind_static_method("NVDA", D_METHOD("is_running"), &NVDA::is_running);
	ClassDB::bind_static_method("NVDA", D_METHOD("cancel"), &NVDA::cancel);
}
