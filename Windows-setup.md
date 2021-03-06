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


# Consistency checks

- Test OpenCV Setup
  - Visual Studio Command Prompt (my be here: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 201x\Visual Studio Tools) - change x :)
  - cd @sbgck\desktop\cpp\hello_world_opencv
  - mkdir build
  - cmake ..
  - msbuild ALL_BUILD.vcxproj
- TBD add more

