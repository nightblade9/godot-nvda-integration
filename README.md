![icon](https://raw.githubusercontent.com/nightblade9/godot-nvda-integration/main/icon.png) 

# Godot NVDA Integration

As of 2024, the latest package for integrating NVDA support into Godot seems to be https://github.com/lightsoutgames/godot-tts. However, from speaking to the author on Discord, I understood that this is no longer going to be maintained.

Ergo, as a sighted developer, I need a quick-and-easy way to integrate NVDA with Godot, so that I can send NVDA texts to read; this provides the best-case for usability for blind users and users who depend on screen readers.

The current code is based on a hastily-thrown-together example from @bruvzg, circa 2023, which you can find here: https://github.com/godotengine/godot-proposals/discussions/6757#discussioncomment-5722559

I attempted to adapt and maintain the code for Godot 4.2.1 in 2024, and going forward.

# Installation

- Copy `addons` and `nvda.gdextension` into your project
- Add `addons/nvda_integration/NvdaWrapper.gd` as an auto-load

Call `NvdaWrapper.say(...)` to say any text. If NVDA is running, it will speak through NVDA using the user's settings. If NVDA is not running, it will fall back to Godot's text-to-speech (which is dependent on the underlying system's text-to-speech).

# Usage / APIs

- `NvdaWrapper.say(...)`: speaks any text to NVDA, and fall back to text-to-speech. If there's a text already being spoken, it will be cancelled, and the new text will play immediately.
- `NvdaWrapper.say_nvda`: speaks something only to NVDA, and only if NVDA is running Does not fall back to text-to-speech. Cancels the current text if one is being spoken.
- `NvdaWrapper.stop`: stops speaking (if speaking)
- `NvdaWrapper.is_using_nvda`: returns `true` if NVDA is running
- `NvdaWrapper.voice`: specifies the voice ID (name) of the godot TTS voice to use; this is system dependent, and defaults to the first voice.
- `ScreenReaderStatusLabel`: a label that reads `NVDA integration is enabled/disabled` with the current status (updated every frame). By default, it speaks whenever NVDA is turned on or off. To disable this functionality, set `speak_on_state_change` to `false`.

# Development Instructions

You need the same C++ pre-requisites installed that are required for the `godot` repository. Follow the [official build instructions for your target platform](https://docs.godotengine.org/en/stable/contributing/development/compiling/index.html#building-for-target-platforms).

Once that's done:

- Build `godot-cpp` by running `scons` from the root of the `godot-cpp` repo
- Move this directory so it's a subdirectory of `godot-cpp`
- From the root directory of this project, run `scons`
- Wait. A long, long time.

This should generate the DLL `demo\bin\libgnvda.windows.template_debug.x86_64.dll`. Copy or move this into `addons\nvda_integration\bin` to use it.

Run the demo project in `demo`. It should Just Work :tm:

Note that any signature changes to the `src` directory's files (e.g. new method, new class, change method signature) requires you to re-run `scons` and restart the Godot editor.

To build the release binary, run `scons target=template_release`
