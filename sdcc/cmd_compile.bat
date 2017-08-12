@echo off

set PATH=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin
set PATH=C:\Program Files\SDCC\bin;%PATH%

set SDCC_INCLUDE=..\src\manager

nmake
