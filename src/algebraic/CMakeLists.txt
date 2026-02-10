# Библиотека для алгебраической формы комплексных чисел
add_library(algebraic algebraic.cpp)

target_link_libraries(algebraic 
    PUBLIC 
        complex
)