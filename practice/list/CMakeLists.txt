message("project path: ${PROJECT_SOURCE_DIR}")
set(OBJNAME list)

include_directories(./)
file(GLOB SRC_FILES *.cpp)
message("SRC_FILES:${SRC_FILES}")

add_executable(${OBJNAME} ${SRC_FILES})
