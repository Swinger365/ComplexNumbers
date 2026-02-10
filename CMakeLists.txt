cmake_minimum_required(VERSION 3.14)
project(ComplexNumbers
    VERSION 1.0.0
    DESCRIPTION "Complex Numbers Library with different representations"
    LANGUAGES CXX
)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Опции проекта
option(BUILD_TESTING "Build tests" ON)
option(BUILD_DOCS "Build Doxygen documentation" OFF)

# Добавление исходников
add_subdirectory(src)

# Документация (Doxygen)
if(BUILD_DOCS)
    find_package(Doxygen QUIET)
    if(DOXYGEN_FOUND)
        add_custom_target(docs
            COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )
    else()
        message(WARNING "Doxygen not found. Install it or set BUILD_DOCS=OFF.")
    endif()
endif()

# Добавление тестов
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
