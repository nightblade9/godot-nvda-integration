# Godot NVDA Integration

As of 2024, the latest package for integrating NVDA support into Godot seems to be https://github.com/lightsoutgames/godot-tts. However, from speaking to the author on Discord, I understood that this is no longer going to be maintained.

Ergo, as a sighted developer, I need a quick-and-easy way to integrate NVDA with Godot, so that I can send NVDA texts to read; this provides the best-case for usability for blind users and users who depend on screen readers.

The current code is based on a hastily-thrown-together example from @bruvzg, circa 2023, which you can find here: https://github.com/godotengine/godot-proposals/discussions/6757#discussioncomment-5722559

I attempted to adapt and maintain the code for Godot 4.2.1 in 2024, and going forward.

# Development Instructions

You need the same C++ pre-requisites installed that are required for the `godot` repository. Follow the [official build instructions for your target platform](https://docs.godotengine.org/en/stable/contributing/development/compiling/index.html#building-for-target-platforms).

Once that's done:

- Build `godot-cpp` by running `scons` from the root of the `godot-cpp` repo
- Move this directory so it's a subdirectory of `godot-cpp`
- From the root directory of this project, run `scons`
- Wait. A long, long time.

This should regenerate some of the files in `demo\bin`, such as `demo\bin\libgnvda.windows.template_debug.x86_64.dll`. 

Run the demo project in `demo`. It should Just Work :tm:

Note that any signature changes to the `src` directory's files (e.g. new method, new class, change method signature) requires you to re-run `scons` and restart the Godot editor.