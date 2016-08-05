CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

# 使用資料夾名稱作為Project名稱
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
PROJECT(${ProjectId})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Using C++ 11
set(CMAKE_CXX_FLAGS		"-std=c++11 ")

# Append version flag
set(CMAKE_CXX_FLAGS		"${CMAKE_CXX_FLAGS} ${VER_FLAGS}")

# Source directory
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src ${ProjectId}_SRC)




# add_executable(${ProjectId} ${${ProjectId}_SRC}) #執行檔名稱 + source
# target_link_libraries(${ProjectId} TitleModule ContentModule)


add_library(${ProjectId} SHARED ${${ProjectId}_SRC}) #執行檔名稱 + source

# Shared Library version & soname
SET_TARGET_PROPERTIES(${ProjectId}
						PROPERTIES VERSION 1.0.3
						SOVERSION 1)

add_custom_target(automake COMMAND make clean COMMAND make)
add_custom_target(makeRun ./${ProjectId})
add_dependencies(makeRun automake)