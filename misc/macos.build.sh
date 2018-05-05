g++ -g -std=c++11 \
    -I./include \
    -I./include/node/ \
    -I./include/v8/ \
    -I./include/uv/ \
    ./src/main.cpp ./src/node.cpp \
    -pthread -ldl -lm \
    -lnode.59 -lv8_libplatform -lv8_libbase \
    -fno-rtti \
    -L./build/ -L./lib/mac \
    -Wl,-rpath,./ \
    -o ./build/test2
