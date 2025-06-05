cmake_minimum_required(VERSION 3.10)
project(sfml-sierpinski)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(sfml-sierpinski src/main.cpp)

target_compile_features(sfml-sierpinski
                        PRIVATE
                        cxx_std_17)

target_compile_options(sfml-sierpinski
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
					   $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>)

# Any additional include files would go here
#target_include_directories(sfml-sierpinski
#                           PUBLIC
#                           )

target_compile_definitions(sfml-sierpinski
                           PRIVATE
                           $<$<CONFIG:Debug>:DEBUG>)

target_link_libraries(sfml-sierpinski
                      PRIVATE
                      SFML::Graphics)
