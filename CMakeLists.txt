CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project(Regular_expression_sample)

add_subdirectory(StateMachine)
add_subdirectory(RegularExpression)

add_executable(app main.cpp)
target_link_libraries(app Regex)

install(TARGETS app DESTINATION bin)

