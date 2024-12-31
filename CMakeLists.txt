cmake_minimum_required(VERSION 3.10)

project(MySimpleSFMLProject)

# Указываем путь к папке SFML
set(SFML_INCLUDE_DIR "libs/sfml/include")
set(SFML_LIB_DIR "libs/sfml/lib")

# Добавляем пути для поиска библиотек и заголовков
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

aux_source_directory(src SRC_DIR)

# Добавляем исполняемый файл
add_executable(MySimpleSFMLProject ${SRC_DIR})

# Подключаем библиотеки SFML
target_link_libraries(MySimpleSFMLProject sfml-graphics sfml-window sfml-system)

# Копируем папку res после сборки
add_custom_command(
    TARGET MySimpleSFMLProject
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    ${CMAKE_BINARY_DIR}/Release/res
)
