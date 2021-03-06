#ifndef SCRIPT_H
#define SCRIPT_H

#include <iostream>
#include <vector>

#include "tree.h"
#include "interpreter.h"

namespace dom
{
    
    class ScriptRunner
    {
    private:
        Tree* tree;
        Interpreter interpreter;
        std::vector<std::string> src;

        struct ScriptCommand
        {
            std::string cmd;
            std::vector<std::string>* subCmds;
        };

        std::vector<ScriptCommand*>* commands;

        int parse();

        static void cleanSource(std::string& line);
    public:
        ScriptRunner(Tree* tree, char* scriptSrc);

        int run();
    };

} // namespace dom

#endif  // SCRIPT_H