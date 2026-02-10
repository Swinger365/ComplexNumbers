# Библиотека для тригонометрической формы комплексных чисел
add_library(trigonometric trigonometric.cpp)

target_link_libraries(trigonometric 
    PUBLIC 
        complex
)