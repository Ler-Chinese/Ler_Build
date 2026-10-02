# Ler_Build
# by Ler_Chinese
\
This is a tool used for build a cpp project.\

# Notice:

If you want use it in windows please run StartAnsi.ps1 first\

# Example code:
'cpp'
/*\
#include "Ler_build.h"\
\
int main()\
{\
  InitBuild();\
  SetOutputFile("./project/project");\
\
  AddSrcFile("./src/main.cpp");\
\
  AddIncludeDir("./include");\
\
  AddLibDir("./lib");\
\
  Compile();\
  RunProgram();\
}\
*/\



# Function list:\
\
void InitBuild();//Init Ler_Build system\
void Compile();//Compile Project\
void RunProgram();//Run Project Output File\
void AddSrcFile(const char* Src_File);//Add source file\
void AddIncludeDir(const char* Include_Dir);//Add head file path\
void AddLibDir(const char* Lib_Dir);//Add lib file path\
void AddLibFile(const char* Lib_File);//Add lib file\
void SetOutputFile(const char* Project_Name);//Set the output file\
