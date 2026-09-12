cmake_minimum_required(VERSION 3.16)

project(refugio_huellas LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(refugio_huellas
    main.cpp
    dao/EmpleadoDAO.cpp
	dao/CandidatoDAO.cpp
    lib/sqlite3.c
)

target_include_directories(refugio_huellas PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/dao
    ${CMAKE_CURRENT_SOURCE_DIR}/entities
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

if (WIN32)
    target_link_libraries(refugio_huellas PRIVATE ws2_32)
endif()

add_custom_command(TARGET refugio_huellas POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/sql_create.sql
        $<TARGET_FILE_DIR:refugio_huellas>/sql_create.sql
)