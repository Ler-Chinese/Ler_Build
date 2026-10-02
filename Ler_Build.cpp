//build.cpp:
//by Ler_Chinese
#include "Ler_Build.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <filesystem>

std::string compile_order;
std::string src_file;
std::string include_dir;
std::string lib_dir;
std::string lib_file;
std::string output_dir = "NULL";

void InitBuild()
{
  setvbuf(stdout, NULL, _IONBF, 0);
}

void Compile()
{
  compile_order = "g++ " +  include_dir + lib_dir + src_file + lib_file + "-o " + output_dir;;
  printf(GREEN "[INFO]" RESET "Compile Order: %s\n", compile_order.c_str());
  if(system(compile_order.c_str()) == 0) {
    printf(GREEN "[INFO]" RESET "Success in compile programe. Output file: %s\n", output_dir.c_str());
    return;
  }
  exit(1);
}

void RunProgram()
{
  std::string __Tmp_output_dir;
  std::string __Tmp_output_file;
  std::error_code ErrCode;
  __Tmp_output_dir += output_dir;
  
  while(!__Tmp_output_dir.empty()) {
    char TmpLastChar = __Tmp_output_dir[__Tmp_output_dir.size() - 1];
    
    if(TmpLastChar == '/') { break;}
    
    __Tmp_output_file.push_back(TmpLastChar);
    __Tmp_output_dir.pop_back();
  }

  printf(GREEN "[INFO]" RESET "Running programe now......\n");
  //printf(GREEN "[TIST]" RESET "%s\n", __Tmp_output_dir.c_str());

  if(__Tmp_output_dir.empty()) {
    system(output_dir.c_str());
    return;
  }
  //else:
  std::reverse(__Tmp_output_file.begin(), __Tmp_output_file.end());
  std::filesystem::current_path(__Tmp_output_dir.c_str());
  system(__Tmp_output_file.c_str());
}

void AddSrcFile(const char* Src_File)
{
  src_file += Src_File;
  src_file += " ";
}

void AddIncludeDir(const char* Include_Dir)
{
  include_dir += "-I ";
  include_dir += Include_Dir;
  include_dir += " ";
}

void AddLibDir(const char* Lib_Dir)
{
  lib_dir += "-L ";
  lib_dir += Lib_Dir;
  lib_dir += " ";
}

void AddLibFile(const char* Lib_File)
{
  lib_file += "-l";
  lib_file += Lib_File;
  lib_file += " ";
}

void SetOutputFile(const char* Output_File)
{
  output_dir = Output_File;
}
