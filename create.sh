#!/bin/bash

emcc -std=c++17 -g -gsource-map --no-entry -s STANDALONE_WASM box.cpp game_logic.cpp -o game_logic.html -O1