#pragma once
#include "mlgui.2/src/Window.h"
#include "mlgui.2/src/WebView.h"

class MainWindow : public ml::Window
{
    public:
        MainWindow(ml::App* app);
        MainWindow(ml::App* app, ml::Window* parent);
        virtual ~MainWindow();

        virtual void init() override;
        void createMenus();

        ml::WebView* webView(){return _webview.get();}

    protected : 
        void _setEvents();
        std::shared_ptr<ml::WebView> _webview;
};
