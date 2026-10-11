//build.h:
//by Ler_Chinese
#ifndef LER_BUILD
#define LER_BUILD

#include <string>

//---Color Define---
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
//------------------

//----Function List----
void InitBuild();
void Compile();
void RunProgram();
void AddSrcFile(const char* Src_File);
void AddIncludeDir(const char* Include_Dir);
void AddLibDir(const char* Lib_Dir);
void AddLibFile(const char* Lib_File);
void AddOrder(const char* Order);
void SetOutputFile(const char* Project_Name);
//---------------------

#endif
