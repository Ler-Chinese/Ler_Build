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

#endif
