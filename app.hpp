#ifndef APP_HPP_INCLUDED
#define APP_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"

class App
{
protected:
   std::vector<Widget*> widgets;

public:
    void add_widget(Widget * w) {widgets.push_back(w);}
    void event_loop();
    void open(int XX, int YY);

    //virtual void app_event();

};

#endif // APP_HPP_INCLUDED
