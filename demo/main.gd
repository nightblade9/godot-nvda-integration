extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$CheckBox.button_pressed = NvdaWrapper.is_using_nvda()

func _on_button_pressed():
	NvdaWrapper.say("Screenreader Test Work")

func _on_button_2_pressed():
	NvdaWrapper.say_nvda("Screenreader only")

func _on_button_new_voice_pressed():
	NvdaWrapper.say("I have cats", "en-US", 0.75)

func _on_button_french_pressed():
	NvdaWrapper.say("J'ai les chats", "fr-FR", 1.0)

func _on_button_invalid_pressed():
	NvdaWrapper.say("This will speak, but the voice is invalid.", "INVALID")

func _on_button_no_text_pressed():
	NvdaWrapper.say("")


func _on_button_default_2_pressed():
	NvdaWrapper.say("<speak>" +
	"<say-as interpret-as='currency' language='en-US'>$42.01</say-as>" +
	"</speak>")
