cmake_minimum_required(VERSION 3.12)
project(turkish_numbers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(turkish_numbers src/main.cpp)

# Тесты (если Google Test установлен)
find_package(GTest REQUIRED)
add_executable(test_turkish_numbers test/test_turkish_numbers.cpp)
target_link_libraries(test_turkish_numbers GTest::gtest GTest::gtest_main)