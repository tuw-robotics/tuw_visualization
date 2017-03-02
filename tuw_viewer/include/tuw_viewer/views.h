#ifndef TUW_VIEWER_H
#define TUW_VIEWER_H

#include <mgl2/mgl.h>
#include <mgl2/wnd.h>
#include <mgl2/fltk.h>

namespace tuw
{

class Views : public mglDraw
{
    mglPoint pnt;	// some variable for changeable data
    long i;			// another variable to be shown
    mglWnd *wnd;	// external window for plotting

public:

    mglData laser[2];


    Views ( mglWnd *w=0 ) : mglDraw()	{
        wnd=w;
    }
    void SetWnd ( mglWnd *w )	{
        wnd=w;
    }
    int Draw ( mglGraph *gr ) {
        gr->SubPlot ( 2, 1, 0);
        gr->Title ( "local" );
        gr->Aspect ( NAN, NAN );
        gr->SetRange ( 'x', -5, 5 );
        gr->SetRange ( 'y', -5, 5 );
	gr->Rotate(0, -90);
        gr->Label ( 'x',"x",0 );
        gr->Label ( 'y',"y",0 );
        gr->Axis();
	gr->Box();
        gr->Grid();
        gr->Plot ( laser[0], laser[1], ".r" );
        gr->SubPlot ( 2, 1, 1);
        gr->Title ( "map" );
        gr->SetRange ( 'x', -10, 10 );
        gr->SetRange ( 'y', -10, 10 );
        gr->Label ( 'x',"x",0 );
        gr->Label ( 'y',"y",0 );
        gr->Aspect ( NAN, NAN );
        gr->Axis();
	gr->Box();
        gr->Grid();
        gr->Plot ( laser[0], laser[1], ".r" );
        return 0;
    }
    void Calc() {
        for ( i=0;; i++ ) {	// do calculation
            //long_calculations();// which can be very long
            Check();	// check if need pause
            pnt.Set ( 2*mgl_rnd()-1,2*mgl_rnd()-1 );
            if ( wnd )	{
                wnd->Update();
            }
        }
    }
};
};

#endif // TUW_VIEWER_NODE_H
