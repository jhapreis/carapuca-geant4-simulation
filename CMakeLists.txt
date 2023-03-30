# Sets compile_commands.json; for SonarLint extension
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# CMake infos
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()
# add_definitions("-Wall" "-g")
add_subdirectory(3rdparty/spdlog)
add_subdirectory(3rdparty/rapidjson)



# Project infos
set(PROJECT_NAME "CArapuca")
set(EXECUTABLE_FILENAME "ArapucaSim")
set(ARAPUCA_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

project(${PROJECT_NAME})


# Geant4 infos
find_package(Geant4 REQUIRED ui_all vis_all)
find_package(RapidJSON)
# find_package(RapidJSON)
include(${Geant4_USE_FILE})

# Headers and Source files
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# message(sources="${sources}")
# message(headers="${headers}")


add_executable(${EXECUTABLE_FILENAME} main.cpp ${sources} ${headers})

target_include_directories(
	${EXECUTABLE_FILENAME} 
	PRIVATE 
	${ARAPUCA_INC_PATH}
)

target_link_libraries(
	${EXECUTABLE_FILENAME}
	PUBLIC
	spdlog
	rapidjson
	${Geant4_LIBRARIES}
	${ROOT_LIBRARIES}
)

file(COPY macros/ DESTINATION macros/)
file(COPY data/ DESTINATION data/)
