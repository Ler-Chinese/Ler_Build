//build.h:
//by Ler_Chinese
//g++ -I ./include main.cpp gg.cpp -o main
#ifndef LER_BUILD
#define LER_BUILD

#include <string>

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void InitBuild();
void Compile();
void RunProgram();
void AddSrcFile(const char* Src_File);
void AddIncludeDir(const char* Include_Dir);
void AddLibDir(const char* Lib_Dir);
void AddLibFile(const char* Lib_File);
void SetOutputFile(const char* Project_Name);

#endif
