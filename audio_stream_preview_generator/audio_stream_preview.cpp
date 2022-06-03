#include "audio_stream_preview.h"

float AudioStreamPreview::get_length() const {
  return length;
}
float AudioStreamPreview::get_max(float p_time, float p_time_next) const {
  if (length == 0) {
    return 0;
  }

  int max = preview.size() / 2;
  int time_from = p_time / length * max;
  int time_to = p_time_next / length * max;
  time_from = CLAMP(time_from, 0, max - 1);
  time_to = CLAMP(time_to, 0, max - 1);

  if (time_to <= time_from) {
    time_to = time_from + 1;
  }

  uint8_t vmax = 0;

  for (int i = time_from; i < time_to; i++) {
    uint8_t v = preview[i * 2 + 1];
    if (i == 0 || v > vmax) {
      vmax = v;
    }
  }

  return (vmax / 255.0) * 2.0 - 1.0;
}
float AudioStreamPreview::get_min(float p_time, float p_time_next) const {
  if (length == 0) {
    return 0;
  }

  int max = preview.size() / 2;
  int time_from = p_time / length * max;
  int time_to = p_time_next / length * max;
  time_from = CLAMP(time_from, 0, max - 1);
  time_to = CLAMP(time_to, 0, max - 1);

  if (time_to <= time_from) {
    time_to = time_from + 1;
  }

  uint8_t vmin = 255;

  for (int i = time_from; i < time_to; i++) {
    uint8_t v = preview[i * 2];
    if (i == 0 || v < vmin) {
      vmin = v;
    }
  }

  return (vmin / 255.0) * 2.0 - 1.0;
}

AudioStreamPreview::AudioStreamPreview() {
  length = 0;
}

void AudioStreamPreview::_bind_methods() {
  ClassDB::bind_method("get_length", &AudioStreamPreview::get_length);
  ClassDB::bind_method(D_METHOD("get_max", "p_time", "p_time_next"), &AudioStreamPreview::get_max);
  ClassDB::bind_method(D_METHOD("get_min", "p_time", "p_time_next"), &AudioStreamPreview::get_min);
}


