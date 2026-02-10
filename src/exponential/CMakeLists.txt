# Библиотека для экспоненциальной формы комплексных чисел
add_library(exponential exponential.cpp)

target_link_libraries(exponential 
    PUBLIC 
        complex
)