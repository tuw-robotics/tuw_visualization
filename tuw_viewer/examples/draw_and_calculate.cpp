/// http://mathgl.sourceforge.net/doc_en/Draw-and-calculate.html#Draw-and-calculate
#include <mgl2/mgl.h>
#include <mgl2/wnd.h>
#include <mgl2/fltk.h>

class myDraw : public mglDraw {
    mglPoint pnt;	// some variable for changeable data
    long i;			// another variable to be shown
    mglWnd *wnd;	// external window for plotting
public:
    myDraw ( mglWnd *w=0 ) : mglDraw()	{
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

int main ( int argc,char **argv ) {
    myDraw dr;
    mglFLTK gr ( &dr,"Multi-threading test" );	// create window
    dr.SetWnd ( &gr );	// pass window pointer to yours class
    dr.Run();	// run calculations
    gr.Run();	// run event loop for window
    return 0;
}
