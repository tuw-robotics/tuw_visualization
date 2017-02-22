#ifndef TUW_VIEWER_H
#define TUW_VIEWER_H

#include <mgl2/mgl.h>
#include <mgl2/wnd.h>
#include <mgl2/fltk.h>

namespace tuw {

class Views : public mglDraw {
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
        gr->Line ( mglPoint(),pnt,"Ar2" );
        char str[16];
        snprintf ( str,15,"i=%ld",i );
        gr->Puts ( mglPoint(),str );
        gr->Plot ( laser[0], laser[1], " #dr" );
        return 0;
    }
    void Calc() {
        for ( i=0;; i++ ) {	// do calculation
            //long_calculations();// which can be very long
            Check();	// check if need pause
            pnt.Set ( 2*mgl_rnd()-1,2*mgl_rnd()-1 );
            if ( wnd )	wnd->Update();
        }
    }
};
};

#endif // TUW_VIEWER_NODE_H
