cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(ASSETS_DIRECTORY ${CMAKE_SOURCE_DIR}/Assets)

setup_exe(test_engine_test)
link_project(test_engine)

set_folder("engine")
