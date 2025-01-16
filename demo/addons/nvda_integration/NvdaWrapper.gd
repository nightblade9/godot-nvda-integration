class_name NvdaWrapper
extends Object
## This class acts as a wrapper class for NVDA.
##
## It will allow for direct NVDA access, and can fall back to
## OS level TTS function if NVDA is not available.

## Constants

## The default language used for reading.
const DEFAULT_LANGUAGE = "en-EN"

## The default voice used for reading.
const DEFAULT_VOICE = 0

## Properties

## Stores the current language ID.
## Defaults to English.
static var language:String = "en-EN"

## Methods

static var voice:String = ""

## Initializes the voices. 
## Voices will be initialized when first speaking,
## but this allows for a developer to initialize
## voices independently.
static func init_voices(_language: String = "en"):
	_load_voices(_language)

## Speaks using NVDA only.
## If NVDA is not detected, the method returns.
static func say_nvda(text: String, _language: String = language) -> void:
	if not is_using_nvda():
		return
	
	# If no text is passed, ignore attempting to read.
	if text.strip_edges().is_empty():
		print("No text passed to speak.")
		return	
	
	# Ends current speech.
	NVDA.cancel()
	
	# Starts speaking.
	NVDA.speak_text(text)

## Speaks using NVDA, if available.
## If NVDA is not available, will fallback to DisplayServer.tts.
static func say(text:String, _language: String = "", _speed: float = 1.0) -> void:
	
	# If no text is passed, ignore attempting to read.
	if text.strip_edges().is_empty():
		print("No text passed to speak.")
		return
	
	# Grabs voices if no voice detected, or language 
	if !_language.is_empty() || language != _language:
		_load_voices(_language)
		
	# Stops current speech.
	stop()
	
	# Starts speaking.
	if is_using_nvda():
		if !_language.is_empty() || _speed != 1.0:
			NVDA.speak_text_modifier(text, _language, _speed)
		else:
			NVDA.speak_text(text)
	else:
		# If a voice is not set by loading voices, print an error.
		if voice.is_empty():
			printerr("No voice is available with language %s." % _language)
			return
		
		DisplayServer.tts_speak(text, voice, 50, 1.0, _speed)

## Stops all speech.
static func stop():
	if is_using_nvda():
		NVDA.cancel()
	else:
		DisplayServer.tts_stop()

## Checks if NVDA is available.
static func is_using_nvda():
	return NVDA.is_running()

## Loads available voice.
static func _load_voices(_language: String = "en"):
	voice = ""
	language = DEFAULT_LANGUAGE
	
	var voices = DisplayServer.tts_get_voices_for_language(_language.split("-")[0])
	
	# If voices are empty, print an error and return.
	if voices.is_empty():
		printerr("No voices found for language %s" % _language)
		return
		
	voice = voices[0]
	language = _language
