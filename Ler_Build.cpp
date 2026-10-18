//build.cpp:
//by Ler_Chinese
#include "Ler_Build.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <filesystem>

//-----string List-----
std::string Program_Language = "NULL Language"; // The language                 of the program
std::string compile_order;                      // The order to compile            the program
std::string src_file;                           // The source file              in the program 
std::string include_dir;                        // The include path             in the program 
std::string lib_dir;                            // The lib     path             in the program 
std::string lib_file;                           // The lib file                 in the program 
std::string order;                              // The additional order         in the program
std::string output_dir = "NULL";                // The ouput file (path + file) in the program
//---------------------

void InitBuild(const std::string Language) // Init the Build system and set the language
{
  setvbuf(stdout, NULL, _IONBF, 0);
  Program_Language  = Language; // Set Language(only C ans C++)
}

void Compile()
{
  // Choose the compiler according to the language:
  if(Program_Language == "C++" || Program_Language == "Cpp") { compile_order = "g++ "; } // C++ (g++)
  else if(Program_Language == "C") { compile_order = "gcc "; }                           // C   (gcc)
  else {                                                                                 // Another(not C++ / C _OR_ Not a language)
    printf(RED "[ERR]" RESET "Language: %s, Sorry Ler_Build can only use in C++/C project, please change a language\n", Program_Language.c_str());
  }
  //----------------------------------------------
  
  compile_order += include_dir + lib_dir + src_file + lib_file + "-o " + output_dir + " " + order; // Make compile order
  
  printf(GREEN "[INFO]" RESET "Compile Order: %s\n", compile_order.c_str());
  
  if(!system(compile_order.c_str())) { // Success in compiling
    printf(GREEN "[INFO]" RESET "Success in compiling programe. Output file: %s\n", output_dir.c_str());
    return;
  }
  
  exit(1);
}

void RunProgram()
{
  std::string __Tmp_output_dir;  // path of output file
  std::string __Tmp_output_file; // file name of output file
  std::error_code ErrCode;       // Useless for me......
  
  __Tmp_output_dir += output_dir;// copy output_dir -> __Tmp_output_dir

  //There are 2 parts in output_dir:
  //Example: outputdir/outputfile
  //         --part-1-^--part-2--
  // the part 1 is the path AND the part 2 is the file name  
  
  while(!__Tmp_output_dir.empty()) {
    char TmpLastChar = __Tmp_output_dir[__Tmp_output_dir.size() - 1]; // Get the Last character of __Tmp_output_dir
    
    if(TmpLastChar == '/') { break;}          // get the file name already
    
    __Tmp_output_file.push_back(TmpLastChar); // Add the character
    __Tmp_output_dir.pop_back();              // Delete the Last character
  }

  printf(GREEN "[INFO]" RESET "Running programe now......\n");
  //printf(GREEN "[TIST]" RESET "%s\n", __Tmp_output_dir.c_str());

  if(__Tmp_output_dir.empty()) { // the output_dir is just the file name
    system(output_dir.c_str());
    return;
  }
  //else:
  std::reverse(__Tmp_output_file.begin(), __Tmp_output_file.end());
  std::filesystem::current_path(__Tmp_output_dir.c_str()); // into the path
  
  system(__Tmp_output_file.c_str()); // Run
}

void AddSrcFile   (const std::string Src_File)    { src_file    += Src_File + " "; }
void AddIncludeDir(const std::string Include_Dir) { include_dir += "-I " + Include_Dir + " ";}
void AddLibDir    (const std::string Lib_Dir)     { lib_dir     += "-L " + Lib_Dir + " "; }
void AddLibFile   (const std::string Lib_File)    { lib_file    += "-l"  + Lib_File + " "; }
void AddOrder     (const std::string Order)       { order       += Order + " "; }
void SetOutputFile(const std::string Output_File) { output_dir   = Output_File; }
