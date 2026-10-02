# Ler_Build
# by Ler_Chinese
\
This is a tool used for build a cpp project.\
这是一个C++项目的构建工具

# Notice:

If you want use it in windows please run StartAnsi.ps1 first\
如果你想要在windows中正常用这个工具的话, 请先运行 StartAnsi.ps1

# Example code:
```cpp
#include "Ler_build.h"

int main()
{
  InitBuild();
  SetOutputFile("./project/project");

  AddSrcFile("./src/main.cpp");

  AddIncludeDir("./include");

  AddLibDir("./lib");

  Compile();
  RunProgram();
}
```


# Function list:\
```cpp
void InitBuild();
void Compile();
void RunProgram();
void AddSrcFile(const char* Src_File);
void AddIncludeDir(const char* Include_Dir);
void AddLibDir(const char* Lib_Dir);
void AddLibFile(const char* Lib_File);
void SetOutputFile(const char* Project_Name);
```
