#include "./MainWindow.h"
#include "./FxHtml.h"
#include "mlgui.2/src/Scrollable.hpp"

MainWindow::MainWindow(ml::App* app) : ml::Window(app){}
MainWindow::MainWindow(ml::App* app, ml::Window* parent) : ml::Window(app, parent){}
MainWindow::~MainWindow(){}

void MainWindow::init()
{
    ml::Window::init();	
    this->setSize(800,600);
    this->setTitle("fxhtml");
    this->createMenus();
    _webview = _main->createWebView();
    _setEvents();
}

void MainWindow::_setEvents()
{
}

void MainWindow::createMenus()
{

}

