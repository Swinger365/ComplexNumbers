# Все что снизу - с документации google test
# Подключение GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)

# Для Windows: принудительное использование общей CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Создание исполняемого файла тестов
add_executable(my_tests
    algebraic_tests.cpp
    exponential_tests.cpp
    trigonometric_tests.cpp
)

# Линковка библиотек
target_link_libraries(my_tests
    PRIVATE
        GTest::gtest_main
        algebraic
        exponential
        trigonometric
)

# Обнаружение и регистрация тестов
include(GoogleTest)
gtest_discover_tests(my_tests)