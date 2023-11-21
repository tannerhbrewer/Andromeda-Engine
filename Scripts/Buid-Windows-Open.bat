@echo off

pushd ..
Dependencies\Binaries\Premake\Windows\premake5.exe --file=Build.lua vs2022
start Andromeda-Engine.sln
popd