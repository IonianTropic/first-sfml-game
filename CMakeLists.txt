cmake_minimum_required(VERSION 3.16)
project(FirstGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB SRCS CONFIGURE_DEPENDS "include/*.h" "src/*.cpp")

add_executable(FirstGame ${SRCS})
target_include_directories(FirstGame PRIVATE include)
target_link_libraries(FirstGame PRIVATE sfml-graphics)
target_link_libraries(FirstGame PRIVATE sfml-audio)
target_link_libraries(FirstGame PRIVATE sfml-system)
target_compile_features(FirstGame PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET FirstGame
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:FirstGame>
        VERBATIM)
endif()

install(TARGETS FirstGame)
