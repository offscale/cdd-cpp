#include <iostream>
#include <fstream>
#include <filesystem>
#include <clang/Tooling/CommonOptionsParser.h>
#include <llvm/Support/CommandLine.h>

const llvm::ExitOnError ExitOnErr;
static llvm::cl::OptionCategory CddCategory("Compiler Driven Development (CDD) options");


int main(int argc, const char **argv) {
    enum Emit {
        OatModel, OatRoute
    };

    const llvm::cl::opt<Emit> EmitOption(llvm::cl::desc("Emit one of:"),
                                         llvm::cl::values(
                                                 clEnumVal(OatModel, "Produce Oat++ Model(s)"),
                                                 clEnumVal(OatRoute, "Produce Oat++ route(s)")),
                                                 llvm::cl::cat(CddCategory));
    const llvm::cl::opt<std::string> OutputFilename("o", llvm::cl::desc("Specify output filename"),
                                                    llvm::cl::value_desc("filename"),
                                                    llvm::cl::cat(CddCategory));
    clang::tooling::CommonOptionsParser OptionsParser = ExitOnErr(
            clang::tooling::CommonOptionsParser::create (argc, argv, CddCategory));
    for (const std::string& filename : OptionsParser.getCompilations().getAllFiles())
        std::cout << "filename:\t" << filename << "\n";
    if (std::filesystem::is_regular_file(OutputFilename.c_str())) {
        std::cerr << "-o refers to an existent file, merging is currently NotImplemented. "
                     "Specify an alternative file, or delete/move the specified: '"
                  << OutputFilename << "'" << std::endl;
        return 2;
    }
    {
        const std::ofstream Output(OutputFilename.c_str(), std::ios::out);
        if (Output.good()) {
            std::cout << "Opened: '" << OutputFilename << "'" << std::endl;
        }
    }
    // std::ofstream::close(Output);
    std::cout << std::flush;
}
