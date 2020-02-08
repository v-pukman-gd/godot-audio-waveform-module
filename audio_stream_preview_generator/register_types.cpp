#include "register_types.h"

#include "core/class_db.h"
#include "audio_stream_preview_generator.h"

void register_audio_stream_preview_generator_types() {
  ClassDB::register_class<AudioStreamPreviewGenerator>();
}

void unregister_audio_stream_preview_generator_types() {
}
