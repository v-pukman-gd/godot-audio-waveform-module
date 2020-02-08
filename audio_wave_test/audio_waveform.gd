extends ColorRect

const COLOR = Color(0.68, 1, 0.18, 1)

var preview
var preview_len
var loaded = false
var stream = preload("res://audio.ogg")

func _ready():
	pass
	
func setup(stream):
	var g = AudioStreamPreviewGenerator.new()
	g.connect("preview_updated", self, "_on_preview_updated")
	preview = g.generate_preview(stream)
	preview_len = float(preview.get_length())
	
func _draw_preview():
	print("_draw_preview")
	
	var rect = get_rect()
	var size = rect.size
	
	for i in range(0, size.x):
		var ofs = i * preview_len / size.x
		var ofs_n = (i+1) * preview_len / size.x
		var maxi = preview.get_max(ofs, ofs_n) * 0.5 + 0.5
		var mini = preview.get_min(ofs, ofs_n) * 0.5 + 0.5
		
		draw_line(Vector2(i+1, size.y*0.05 + mini * size.y*0.9), Vector2(i+1, size.y*0.05 + maxi * size.y*0.9), COLOR, 1, false)
		
func _on_preview_updated(e):
	if not loaded:
		loaded = true

func _draw():
	if loaded:
		_draw_preview()
