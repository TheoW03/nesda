./BuildTestRoms.sh
cmake -S . -DBUILD_WINDOWS=OFF -B  build 
cmake --build build --config Release -j8
# test