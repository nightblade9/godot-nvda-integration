extends Node

# Sets the voice for built-in TTS. Feel free to set it when you update options.
var voice:String

func _init():
	var voices = DisplayServer.tts_get_voices_for_language("en")
	self.voice = voices[0] # pick the first. Just 'cuz.

# Say something! If we're already talking, stop.
func say(text:String) -> void:
	self.stop()
	if is_using_nvda():
		NVDA.speak_text(text)
	else:
		DisplayServer.tts_speak(text, self.voice)

# Stop speaking. Right. Now.
func stop():
	if is_using_nvda():
		NVDA.cancel()
	else:
		DisplayServer.tts_stop()

func is_using_nvda():
	return NVDA.is_running()
