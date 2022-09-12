.PHONY: all web clean
all: clean web



web:
	 cmake -B .build/web -S . -DVCPKG_TARGET_TRIPLET=wasm32-emscripten -DUSE_WEB=ON\
 	 -DCMAKE_BUILD_TYPE=Release \
     -DCMAKE_C_COMPILER=${HOME}/tools/emsdk/upstream/emscripten/emcc \
     -DCMAKE_CXX_COMPILER=${HOME}/tools/emsdk/upstream/emscripten/em++ \
	 -DCMAKE_TOOLCHAIN_FILE="${HOME}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake"  \
 	 -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE="${HOME}/tools/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" \
	 -G Ninja

	cmake --build .build/web


desktop:
	 cmake -B .build/debug -S . -DCMAKE_TOOLCHAIN_FILE="${HOME}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake" -G Ninja
	 cmake --build .build/debug




clean:
	if test -d ".build/web"; then rm -r .build/web; fi

clean-all:
	if test -d ".build"; then rm -r .build; fi

