./BuildTestRoms.sh
cmake -S . -DBUILD_WINDOWS=ON -B  build 
cmake --build build --config Release -j8
