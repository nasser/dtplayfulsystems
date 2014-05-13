#ifndef __ofxCairoExample__ofxCairo__
#define __ofxCairoExample__ofxCairo__

#include "ofMain.h"

class ofxCairo
{
public:
	ofxCairo();
	void begin(bool savePdf = false, string pdfName = "");
	void end();
	void draw();
	void setLineCap(_cairo_line_cap lineCap);
	void resize(float w, float h);
	
private:
	bool _savePdf;
	_cairo_line_cap _lineCap;
	ofTexture _tex;
	ofPtr<ofBaseRenderer> _origRenderer;
	ofPtr<ofRendererCollection> _renderCollection;
	ofPtr<ofCairoRenderer> _imageRenderer;
	ofPtr<ofCairoRenderer> _pdfRenderer;
};

#endif /* defined(__ofxCairoExample__ofxCairo__) */
