#ifndef AUDIO_STREAM_PREVIEW_GENERATOR_H
#define AUDIO_STREAM_PREVIEW_GENERATOR_H

#include "core/os/thread.h"
#include "core/safe_refcount.h"
#include "scene/main/node.h"
#include "servers/audio/audio_stream.h"
#include "audio_stream_preview.h"

class AudioStreamPreviewGenerator : public Node {
  GDCLASS(AudioStreamPreviewGenerator, Node);

  static AudioStreamPreviewGenerator *singleton;

  struct Preview {
    Ref<AudioStreamPreview> preview;
    Ref<AudioStream> base_stream;
    Ref<AudioStreamPlayback> playback;
    SafeFlag generating;
    ObjectID id;
    Thread *thread;

    // Needed for the bookkeeping of the Map
    Preview &operator=(const Preview &p_rhs) {
      preview = p_rhs.preview;
      base_stream = p_rhs.base_stream;
      playback = p_rhs.playback;
      generating.set_to(generating.is_set());
      id = p_rhs.id;
      thread = p_rhs.thread;
      return *this;
    }
  };

  Map<ObjectID, Preview> previews;

  static void _preview_thread(void *p_preview);

  void _update_emit(ObjectID p_id);

protected:
  void _notification(int p_what);
  static void _bind_methods();

public:
  static AudioStreamPreviewGenerator *get_singleton() { return singleton; }

  Ref<AudioStreamPreview> generate_preview(const Ref<AudioStream> &p_stream);

  AudioStreamPreviewGenerator();
};

#endif
