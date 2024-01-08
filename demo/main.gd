extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$CheckBox.button_pressed = (NVDA.is_running() == 0)

func _on_button_pressed():
	NVDA.speak_text("test test")
