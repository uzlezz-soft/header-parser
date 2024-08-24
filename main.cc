#include "parser.h"
#include "handler.h"
#include "options.h"
//#include <tclap/CmdLine.h>
#include <iostream>
#include <fstream>
#include <sstream>

//----------------------------------------------------------------------------------------------------
void print_usage()
{
  std::cout << "Usage: inputFile" << std::endl;
}

//----------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  Options options;
  std::string inputFile;
  /*try
  {
    using namespace TCLAP;

    CmdLine cmd("Header Parser");

    ValueArg<std::string> enumName("e", "enum", "The name of the enum macro", false, "ENUM", "", cmd);
    ValueArg<std::string> className("c", "class", "The name of the class macro", false, "CLASS", "", cmd);
    MultiArg<std::string> functionName("f", "function", "The name of the function macro", false, "", cmd);
    ValueArg<std::string> propertyName("p", "property", "The name of the property macro", false, "PROPERTY", "", cmd);
    MultiArg<std::string> customMacro("m", "macro", "Custom macro names to parse", false, "", cmd);
    UnlabeledValueArg<std::string> inputFileArg("inputFile", "The file to process", true, "", "", cmd);

    cmd.parse(argc, argv);

    inputFile = inputFileArg.getValue();
    options.classNameMacro = className.getValue();
    options.enumNameMacro = enumName.getValue();
    options.functionNameMacro = functionName.getValue();
    options.customMacros = customMacro.getValue();
    options.propertyNameMacro = propertyName.getValue();
  }
  catch (TCLAP::ArgException& e)
  {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    return -1;
  }*/
  auto project_api_macro = argv[1];
  inputFile = argv[2];
  options.classNameMacro = "MCLASS";
  options.enumNameMacro = "MENUM";
  options.functionNameMacro = {"MFUNC"};
  options.propertyNameMacro = "MPROP";
  options.customMacros = { std::string(project_api_macro), std::string("NO_API"), std::string("ML_META") };

  // Open from file
  std::ifstream t(inputFile);
  if (!t.is_open())
  {
    std::cerr << "Could not open " << inputFile << std::endl;
    return -1;
  }

  std::stringstream buffer;
  buffer << t.rdbuf();

  Parser parser(options);
  if (parser.Parse(buffer.str().c_str()))
    std::cout << parser.result() << std::endl;
  
	return 0;
}
