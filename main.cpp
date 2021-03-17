#include <iostream>
#include <clang/Tooling/CommonOptionsParser.h>
#include <llvm/Support/CommandLine.h>

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory MyToolCategory("my-tool options");

int main(int argc, const char **argv) {
    // CommonOptionsParser constructor will parse arguments and create a
    // CompilationDatabase.  In case of error it will terminate the program.
    llvm::Expected<clang::tooling::CommonOptionsParser> OptionsParserMaybe = clang::tooling::CommonOptionsParser::create (argc, argv, MyToolCategory);
    if (auto Err = OptionsParserMaybe.takeError()) {
        std::cerr << Err.dynamicClassID();
        return EXIT_FAILURE;
    }
    auto &OptionsParser = OptionsParserMaybe;
    for (const auto& filename : OptionsParser->getCompilations().getAllFiles())
        std::cout << "filename:\t" << filename << "\n";
    std::cout << std::flush;

    // Use OptionsParser.getCompilations() and OptionsParser.getSourcePathList()
    // to retrieve CompilationDatabase and the list of input file paths.
}
