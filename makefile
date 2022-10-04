.PHONY: all web clean tests app
all: clean web

app:
	cmake -S . -B .build/app -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -G Ninja
	cmake --build .build/app

web:
	 cmake  -S . -B .build/web \
  		 -DVCPKG_TARGET_TRIPLET=wasm32-emscripten -DUSE_WEB=ON \
		 -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF \
		 -DCMAKE_C_COMPILER=${HOME}/tools/emsdk/upstream/emscripten/emcc \
		 -DCMAKE_CXX_COMPILER=${HOME}/tools/emsdk/upstream/emscripten/em++ \
		 -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE="${HOME}/tools/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" \
		 -G Ninja
	cmake --build .build/web

tests:
	cmake -E make_directory .build/test
	cmake -S . -B .build/test -G Ninja
	cmake --build .build/test
	pushd .build/test; \
  	ctest --extra-verbose; \
	popd;

clean:
	if test -d ".build/web"; then rm -r .build/web; fi

clean-all:
	if test -d ".build"; then rm -r .build; fi

