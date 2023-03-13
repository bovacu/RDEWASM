emcc  modules/imgui/imgui.cpp modules/imgui/imgui_draw.cpp modules/imgui/imgui_tables.cpp modules/imgui/imgui_widgets.cpp modules/imgui/misc/cpp/imgui_stdlib.cpp modules/imgui/backends/imgui_impl_opengl3.cpp modules/imgui/backends/imgui_impl_sdl2.cpp \
      $(find "/Users/macmini/Documents/RDEWASM/modules/Chipmunk2D/src/" -type f -iregex ".*\.c*") \
      $(find "/Users/macmini/Documents/RDE/engine/src/" -type f -iregex ".*\.cpp") \
      /Users/macmini/Documents/RDE/editor/Editor.cpp /Users/macmini/Documents/RDE/editor/EditorEntry.cpp \
      -s WASM=1 \
      -s USE_SDL=2 \
      -s USE_SDL_IMAGE=2 \
      -s USE_SDL_MIXER=2 \
      -s SDL2_IMAGE_FORMATS='["png","jpeg","svg"]' \
      -s SDL2_MIXER_FORMATS='["ogg","mp3"]' \
      -s MAX_WEBGL_VERSION=3 \
      -s FULL_ES3 \
      -s USE_FREETYPE=1 \
      -I/Users/macmini/Documents/RDE/vcpkg/installed/x64-osx/include/ \
      -I/Users/macmini/Documents/RDEWASM/modules/imgui  \
      -I/Users/macmini/Documents/RDEWASM/modules/Chipmunk2D/include  \
      -I/Users/macmini/Documents/RDE/engine/include  \
      -o main.html \
      --preload-file /Users/macmini/Documents/RDE/defaultAssets \
      --preload-file /Users/macmini/Documents/RDE/assets \
      && emrun main.html --no_browser
      
# $(find "/Users/macmini/Documents/WASMTest/modules/glm/" -type f -iregex ".*\.hpp") \
