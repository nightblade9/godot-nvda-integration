#ifndef NVDA_CLASS_H
#define NVDA_CLASS_H

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class NVDA : public Object {
	GDCLASS(NVDA, Object);

protected:
	static void _bind_methods();

	static int64_t speak_text(const String &p_text);
	static int64_t braille_message(const String &p_text);
	static bool is_running();
	static int64_t cancel();
};

#endif
