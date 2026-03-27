#pragma once
#include <string>

namespace fxhtml
{
    inline void open(const std::string& url,
            const std::string& title="fxhtml", 
            int width=800, int height=600)
    {
        std::string size = std::to_string(width) + "x" + std::to_string(height);
        std::string cmd = "/opt/fxhtml/fxhtml \"" + url + "\" --title \"" + title + "\" --size \"" + size + "\" &";
        system(cmd.c_str());
    }
}
