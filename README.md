# Godot Engine Audio Waveform Module

This is Godot Engine custom module based on the engine internal waveform preview code.

It consumes original `AudioStreamPreview` and `AudioStreamPreviewGenerator` C++ classes and makes it available in GDScript.

Originally made for Godot 3

I tested and it worked in new Godot 4 too.

## Installing

If you don't have Godot source yet, download it from repo
`git clone https://github.com/godotengine/godot.git`

Copy the folder `audio_stream_preview_generator` to Godot `modules` folder

Recompile the engine (change platform to yours)
`scons platform=osx bits=64 tools=yes`

And run the new build:
`./bin/godot.osx.tools.64 `

## Usage example

In opened project manager window, choose the project folder `audio_wave_test`

Look to `audio_waveform.gd` source.

Run the project.

Have fun!
