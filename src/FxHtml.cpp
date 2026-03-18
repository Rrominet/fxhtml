#include "./FxHtml.h"
#include "./MainWindow.h"
#include "mlgui.2/src/GuiCommand.h"
#include "debug.h"
#include "mlgui.2/src/App.hpp"
#include "files.2/files.h"

namespace fxhtml
{
    FxHtml* _fxhtml = nullptr;
}

FxHtml::FxHtml(int argc,char *argv[]) : ml::App(argc,argv)
{
    fxhtml::_fxhtml = this;	
    this->createCommands();
    this->createWindows();
    this->setEvents();
    db::setLogFile(files::execDir() + files::sep() + "fxhtml.log");

    auto later = [this]
    {
        this->addCss("fxhtml.css");
    };

    this->setTimeout(later, 16);

    try
    {
        auto uri = this->argv().at("0");
        if (uri.find("http://") == 0 || uri.find("https://") == 0)
            _fxhtmlW->webView()->setURI(uri);
        else 
        {
            if (files::ext(uri) == "md")
                this->comvertMdToHtml(uri);
            _fxhtmlW->webView()->readFile(files::parent(uri) + files::sep() + files::baseName(uri) + ".html");
        }
    }
    catch(const std::exception& e)
    {
        _fxhtmlW->webView()->setURI("http://localhost");
    }

    try
    {
        auto title = this->argv().at("title");
        _fxhtmlW->setTitle(title);
    }
    catch(const std::exception& e){}

    try
    {
        auto size_s = this->argv().at("size");
        auto tmp = str::split(size_s, "x");
        int w = std::stoi(tmp[0]);
        int h = std::stoi(tmp[1]);
        _fxhtmlW->setSize(w, h);
    }
    catch(const std::exception& e){}

}

void FxHtml::setEvents()
{
}

void FxHtml::createCommands()
{
    //     auto cmd = _cmds.createCommand<ml::GuiCommand>("Create Command", "create-cmd");
    //     cmd->aliases().concat({"ccmd", "ncmd"});
    //     cmd->setHelp("Create a new command to execute...");
    //     cmd->setKeybind("ctrl n");
    //     cmd->setExec([this](const std::any&){auto w = this->createWindow<CommandWindow>(_main); w->show();});
}

void FxHtml::createWindows()
{
    this->createMainWindow<MainWindow>();
    _fxhtmlW = (MainWindow*)_main;
}

void FxHtml::comvertMdToHtml(const std::string& md)
{
    std::string mdtohtml = files::execDir() + files::sep() + "mdtohtml";
    if (!files::exists(mdtohtml))
    {
        this->error("mdtohtml is not installed.");
        return;
    }

    std::vector<std::string> args{mdtohtml, md};
    auto res = boost::process::system(args);
    if (res == 0)
    {
        _fxhtmlW->webView()->readFile(md + ".html");
        _htmlCreated.push_back(md + ".html");
    }
    else 
        this->error("mdtohtml failed to convert " + md);
}

FxHtml::~FxHtml()
{
    for (auto& f : _htmlCreated)
        files::remove(f);
    fxhtml::_fxhtml = nullptr;	
}

namespace fxhtml
{
    FxHtml* get(){return _fxhtml;}
}

