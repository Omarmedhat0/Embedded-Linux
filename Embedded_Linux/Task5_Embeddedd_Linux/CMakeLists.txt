Cmake_minimum_required (VERSION 3.2...3.7)
Project (Calculator
	DESCRIPTION "Calculator Project"
	LANGUAGES	C) 
add_library(operation STATIC Lib/addition.c Lib/division.c Lib/modulus.c Lib/multiplication.c Lib/subtraction.c)
target_include_directories(operation INTERFACE Include)
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC operation)
