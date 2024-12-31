cmake_minimum_required(VERSION 3.10)

project(MySimpleSFMLProject)

# Указываем путь к папке SFML
set(SFML_INCLUDE_DIR "libs/sfml/include")
set(SFML_LIB_DIR "libs/sfml/lib")

# Добавляем пути для поиска библиотек и заголовков
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

# Указываем исходники и заголовочные файлы
aux_source_directory(src SRC_DIR)

set(HEADER_FILES
    inc/header.h
)

# Добавляем исполняемый файл
add_executable(MySimpleSFMLProject ${SRC_DIR} ${HEADER_FILES})

# Подключаем библиотеки SFML
target_link_libraries(MySimpleSFMLProject sfml-graphics sfml-window sfml-system)

# Указываем папку с заголовками для компиляции
target_include_directories(MySimpleSFMLProject PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Копируем папку res сначала в build, а затем в build/Release
add_custom_command(
    TARGET MySimpleSFMLProject
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    ${CMAKE_BINARY_DIR}/res
)

add_custom_command(
    TARGET MySimpleSFMLProject
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_BINARY_DIR}/res
    ${CMAKE_BINARY_DIR}/Release/res
)
