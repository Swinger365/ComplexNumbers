# INTERFACE библиотека для базового класса Complex (header-only)
add_library(complex INTERFACE)
target_include_directories(complex 
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Подключение модулей
add_subdirectory(algebraic)
add_subdirectory(exponential)
add_subdirectory(trigonometric)