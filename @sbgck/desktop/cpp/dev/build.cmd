@rem set msbuild.exe=for /D %%D in (%SYSTEMROOT%\Microsoft.NET\Framework\v4*) do set msbuild.exe=%%D\MSBuild.exe
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
C:\WINDOWS\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe ALL_BUILD.vcxproj
cd ..


