extends Control

var stream = preload("res://audio.ogg")
onready var audio_waveform = get_node("VBoxContainer/AudioWaveform")

func _ready():
	audio_waveform.setup(stream)
