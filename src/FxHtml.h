#pragma once
#include "mlgui.2/src/App.h"

class MainWindow;
class FxHtml : public ml::App
{
    public:
        FxHtml(int argc, char *argv[]);
        virtual ~FxHtml();
        void createCommands();
        void createWindows();
        void setEvents();

        void comvertMdToHtml(const std::string& md);

    private : 
        MainWindow* _fxhtmlW=nullptr; //bp cg

        ml::Vec<std::string> _htmlCreated;

    public : 
#include "./FxHtml_gen.h"
};

namespace fxhtml
{
    FxHtml* get();
}
