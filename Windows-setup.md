# Windows Setup and Depends

- Open a Powershell as admin
- Install Chocolatey
  - Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
- Install VS Build Tools
  - choco install visualstudio2017-workload-nodebuildtools
- Install OpenCV
  - choco install opencv
- Install CMake
  - choco install cmake
- Install NodeJS
  - choco install nodejs

# TODO

- Add some consistency check here.

