#ifndef AUDIO_STREAM_PREVIEW_H
#define AUDIO_STREAM_PREVIEW_H

#include "core/reference.h"

class AudioStreamPreview : public Reference {
  GDCLASS(AudioStreamPreview, Reference)
  friend class AudioStream;
  Vector<uint8_t> preview;
  float length;

  friend class AudioStreamPreviewGenerator;

protected:
  static void _bind_methods();

public:
  float get_length() const;
  float get_max(float p_time, float p_time_next) const;
  float get_min(float p_time, float p_time_next) const;

  AudioStreamPreview();
};

#endif // AUDIO_STREAM_PREVIEW_H
