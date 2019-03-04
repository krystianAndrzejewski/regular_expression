CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project(Regular_expression)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
add_library(Regex STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(Regex PUBLIC include)
target_link_libraries(Regex StateMachine)

install(TARGETS Regex DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include/Regex)

