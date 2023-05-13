#ifndef STATIC_PICS_HPP_INCLUDED
#define STATIC_PICS_HPP_INCLUDED


class Static_pics : public Widget
{
protected:
    std::string _filename;
public:
    Static_pics(App * a,int x,int y,int sx,int sy,std::string filename) : Widget(a,x,y,sx,sy), _filename(filename)
    {
        draw();
    }
    virtual void draw();
    virtual void handle();

};

#endif // STATIC_PICS_HPP_INCLUDED
