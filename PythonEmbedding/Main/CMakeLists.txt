cmake_minimum_required (VERSION 3.8)


set (TARGET_NAME Main)

set(PYBIND11_PYTHON_VERSION 3.7.3 CACHE STRING "")

find_package(pybind11 CONFIG REQUIRED)


add_executable (${TARGET_NAME} "Main.cpp" )
# note: 9 additional targets are not displayed.    
#target_link_libraries(${TARGET_NAME} PRIVATE mylib pybind11::lto pybind11::embed pybind11::module)
target_link_libraries(${TARGET_NAME} PRIVATE pybind11::embed pybind11::module pybind11::pybind11)


# setting the binary filenames
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_DEBUG ${TARGET_NAME}-debug )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_RELWITHDEBINFO ${TARGET_NAME}-relwidthdebinfo )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_RELEASE ${TARGET_NAME}-release )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_MINSIZEREL ${TARGET_NAME}-minsizerel )

# Warning levels
if (MSVC)
	target_compile_options(${TARGET_NAME} PUBLIC /W4 /permissive)
else()
	target_compile_options(${TARGET_NAME} PUBLIC -Wall -Wextra -pedantic)
endif()