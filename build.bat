@echo off

SET SRC_DIR=src
SET BLD_DIR=build
SET TMP_DIR=temp
SET AST_DIR=assets
SET LIB_DIR=lib

SET BLD_NAME=rid
SET CPP_FILES=^
main.cpp

PATH = %PATH%;%appdata%\..\Local\w64devkit\bin

g++ -I. %SRC_DIR%\%CPP_FILES% -o %BLD_DIR%\%BLD_NAME%.exe -L%LIB_DIR% -lraylib -lopengl32 -lgdi32 -lwinmm -std=c++20 -march=x86-64

cd %BLD_DIR%
.\%BLD_NAME%

pause