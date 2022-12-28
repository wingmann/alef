project(alef_test)

file(GLOB PROJECT_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*/*/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*/*/*/*.cpp")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ../include/alef/types.h ../include/alef/core/types/numerics/radix.h ../include/alef/lib/concepts/__detail.h ../include/alef/core/io/__detail.h ../include/alef/bits.h ../include/alef/lib/numerics/big_integer.h ../include/alef/core/strings/string.h ../include/alef/core/strings/string_streams.h ../include/alef/core/strings/string_view.h ../include/alef/core/constants/__detail.h)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
