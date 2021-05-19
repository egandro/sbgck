# Windows Setup and Depends

- Open a Powershell as admin
- Install Chocolatey
  - Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
- Install NodeJS
  - choco install -y nodejs
- Install VS Build Tools
  - choco install -y python2 visualstudio2019-workload-vctools
  - choco install -y visualstudio2017-workload-nodebuildtools
- Install CMake (take one option)
  - choco install -y  cmake.install --installargs '"ADD_CMAKE_TO_PATH=User"'
  - choco install -y cmake.install --installargs '"ADD_CMAKE_TO_PATH=System"'
- Install OpenCV
  - choco install -y  opencv
  - Add this variables to the environment (must be done with the UI not on a cmd prompt)
  - OPENCV_DIR=C:\tools\opencv\build
  - PATH append this %OPENCV_DIR%\x64\vc15\bin
- https://nhancv.medium.com/build-opencv-opencv-contrib-on-windows-2e3b1ca96955
- https://cv-tricks.com/how-to/installation-of-opencv-4-1-0-in-windows-10-from-source/
- https://github.com/nut-tree/npm-opencv-build#readme
- https://github.com/nut-tree/opencv4nodejs

## Consistency checks

- Test OpenCV Setup
  - Visual Studio Command Prompt (my be here: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 201x\Visual Studio Tools) - change x :)
  - cd @sbgck\desktop\cpp\hello_world_opencv
  - mkdir build
  - cd build
  - cmake ..
  - cmake --build . --config Release
  - Release\hello_world_opencv.exe
- TBD add more
