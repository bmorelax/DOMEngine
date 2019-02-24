#include "util.h"

namespace util {
    
    std::vector<std::string> tokenize(std::string in, char delim)
    {
        int start = 0;
        std::vector<std::string> tokens;

        for (int i = 0; i < in.length(); i++)
        {
            if (in[i] == delim)
            {
                tokens.push_back(in.substr(start, i-start));
                start = i+1;
            }
        }

        tokens.push_back(in.substr(start, start-in.length()));

        return tokens;
    }

    bool isBlank(std::string& str)
    {
        return str.find_first_not_of(' ') == std::string::npos;
    }

    std::vector<std::string> tokenizeWhitespace(std::string in)
    {
        std::vector<std::string> tokens;

        int curr = 0;
        int len = in.length();
        int start;
        std::string token;
        while (curr < len)
        {
            while (curr < len && std::isspace(in[curr])) curr++;
            start = curr;
            
            while (curr < len && !std::isspace(in[curr])) curr++;
            token = in.substr(start, curr-start);
            if (!isBlank(token))
                tokens.push_back(token);
        }

        return tokens;
    }

    void readLine(std::string& line)
    {
        std::cin >> line;
    }

} // namespace util
