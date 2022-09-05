EM=em++
CC=g++

EMFLAGS= --bind -O2 -s USE_SDL=2 -s USE_SDL_TTF=2 \
 -s TOTAL_MEMORY=67108864 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' \
 -s USE_SDL_GFX=2 --preload-file assets -s EXPORTED_FUNCTIONS='["_main"]'
CCFLAGS= -o out/a.out -lSDL2 -lSDL2_gfx -lSDL2_image



default: src/main.cpp src/eng/Utility.hpp src/eng/Utility.cpp src/eng/Button.hpp src/eng/Button.cpp src/eng/Scene.hpp src/eng/Scene.cpp src/eng/Sprite.cpp src/eng/Sprite.hpp src/eng/App.hpp src/eng/App.cpp src/TestScene.cpp
	clear
	$(CC) src/main.cpp src/eng/Scene.cpp src/eng/Sprite.cpp src/eng/Button.cpp src/eng/App.cpp src/eng/Utility.cpp src/TestScene.cpp $(CCFLAGS) 
	$(EM) -o out/Outbreak.html src/main.cpp src/eng/Scene.cpp src/eng/Sprite.cpp src/eng/Button.cpp src/eng/App.cpp src/eng/Utility.cpp src/TestScene.cpp $(EMFLAGS) 
	echo -ne '\007'