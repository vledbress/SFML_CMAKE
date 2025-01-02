@echo off
if exist build (
    cd build
    cmake --build . --config Release
    start "" "../rr.lnk"
)




