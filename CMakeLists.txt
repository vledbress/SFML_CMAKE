cmake_minimum_required(VERSION 3.10)

project(MySimpleSFMLProject)

# Указываем путь к папке SFML
set(SFML_INCLUDE_DIR "libs/sfml/include")
set(SFML_LIB_DIR "libs/sfml/lib")

# Добавляем пути для поиска библиотек и заголовков
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

# Указываем исходники
file(GLOB SRC_FILES "src/*.cpp")

# Указываем заголовочные файлы (возможно, они находятся в папке inc)
file(GLOB HEADER_FILES "inc/*.h")

# Добавляем исполняемый файл
add_executable(MySimpleSFMLProject ${SRC_FILES} ${HEADER_FILES})

# Подключаем библиотеки SFML
target_link_libraries(MySimpleSFMLProject sfml-graphics sfml-window sfml-system)

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
