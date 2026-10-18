# Ler_Build
## by Ler_Chinese

## This is a tool used for build a C / Cpp project.
## 这是一个C/C++项目的构建工具

![Picture](./紅白蝶.jpg "紅白蝶")

## Notice:

If you want use it in windows please run EnableAnsi.ps1 first\
如果你想要在windows中正常用这个工具的话, 请先运行 EnableAnsi.ps1

## Project structure:
```cpp
/-----root------
|  /-src
|  |  #......
|  /-include
|  |  #......
|  #Ler_Build.h
|  #Ler_Build.cpp
|  #make.cpp
------------------
```

## Example code:
```cpp

// make.cpp
// compile order: g++ make.cpp Ler_Build.cpp -o build

#include "Ler_build.h"

int main()
{
  InitBuild("C++");// "Cpp" or "C"
  SetOutputFile("./project/project");

  AddSrcFile("./src/main.cpp");

  AddIncludeDir("./include");

  AddLibDir("./lib");

  AddOrder("-std=c++11");

  Compile();
  RunProgram();
}
```


## Function list:
```cpp
//----Function List----
void InitBuild(const std::string Language);
void Compile();
void RunProgram();
void AddSrcFile(const std::string Src_File);
void AddIncludeDir(const std::string Include_Dir);
void AddLibDir(const std::string Lib_Dir);
void AddLibFile(const std::string Lib_File);
void AddOrder(const std::string Order);
void SetOutputFile(const std::string Project_Name);
//---------------------
```
