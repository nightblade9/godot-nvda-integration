extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$CheckBox.button_pressed = NVDA.is_running()

func _on_button_pressed():
	NvdaWrapper.say("test test")

func _on_button_2_pressed():
	NvdaWrapper.say_nvda("NVDA only")
