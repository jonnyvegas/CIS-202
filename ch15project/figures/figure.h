#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
namespace villegasfigures
{
    class Figure
    {
    public:
        virtual void draw();//draw a figure
        virtual void erase();//erase the figure
        virtual void center();//erase and draw the figure in the center
    private:
        int middle;
    };
}


#endif // FIGURE_H_INCLUDED
