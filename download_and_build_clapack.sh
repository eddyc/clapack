cd /Volumes/Data/emsdk-portable
source ./emsdk_env.sh
git clone git@github.com:eddyc/clapack.git clapack
cd clapack
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN/cmake/Modules/Platform/Emscripten.cmake ..
emmake make
emcc ../../main.c -I/usr/local/include -o main.bc
emcc -O2 -s WASM=1 -s ASSERTIONS=1 -s "BINARYEN_METHOD='native-wasm'" ../../main.bc ./F2CLIBS/libf2c/libf2c.a ./BLAS/SRC/libblas.a ./SRC/liblapack.a  -o library.html
