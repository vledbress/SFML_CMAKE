@echo off
rem Сначала создаём проект
cd build
cmake ..
rem Затем строим проект в конфигурации Release
cmake --build . --config Release
