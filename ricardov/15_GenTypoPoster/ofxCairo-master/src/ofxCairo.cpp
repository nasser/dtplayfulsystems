#include "ofxCairo.h"

ofxCairo::ofxCairo()
{
    _renderCollection = ofPtr<ofRendererCollection>(new ofRendererCollection);
    _imageRenderer = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
    _imageRenderer->setupMemoryOnly(ofCairoRenderer::IMAGE);
    _renderCollection->renderers.push_back(_imageRenderer);
}

void ofxCairo::resize(float w, float h)
{
	_imageRenderer->setupMemoryOnly(ofCairoRenderer::IMAGE);
	cairo_set_line_cap(_imageRenderer->getCairoContext(), _lineCap);
}

void ofxCairo::begin(bool savePdf, string pdfName)
{
	_savePdf = savePdf;
	
	if (savePdf)
	{
		_pdfRenderer = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
		_pdfRenderer->setup(pdfName);
		cairo_set_line_cap(_pdfRenderer->getCairoContext(), _lineCap);
		_renderCollection->renderers.push_back(_pdfRenderer);
	}
	
    _origRenderer = ofGetCurrentRenderer();
    ofSetCurrentRenderer(_renderCollection);
}

void ofxCairo::setLineCap(_cairo_line_cap lineCap)
{
    cairo_set_line_cap(_imageRenderer->getCairoContext(), lineCap);
	_lineCap = lineCap;
}

void ofxCairo::end()
{
    _renderCollection->update();
    ofSetCurrentRenderer(_origRenderer);
	
	if (_savePdf)
	{
		_savePdf = false;
		_pdfRenderer->close();
		
		if (_renderCollection->renderers.size() > 1)
		{
			_renderCollection->renderers.pop_back();
		}
	}
}

void ofxCairo::draw()
{
	_tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    _tex.texData.glTypeInternal = GL_BGRA;
    ofPixels &pix = _imageRenderer->getImageSurfacePixels();
    _tex.loadData(pix.getPixels(), pix.getWidth(), pix.getHeight(), GL_BGRA);
    if (_tex.isAllocated()) _tex.draw(0, 0);
}