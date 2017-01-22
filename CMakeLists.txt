cmake_minimum_required(VERSION 3.6)
project(pcm_to_wav)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c wavfile.c wavfile.h mixer.c mixer.h)
add_executable(pcm_to_wav ${SOURCE_FILES})