#ifndef 	BEZIER_H
#define 	BEZIER_H

#include "ofMain.h"


/*
XXO Paul Bourke
http://local.wasp.uwa.edu.au/~pbourke/surfaces_curves/bezier/index2.html
*/
//-----------------------------------------
inline ofPoint getBezier3Pt( ofPoint p1, ofPoint p2, ofPoint p3, float mu );
inline ofPoint getBezier3Pt( ofPoint p1, ofPoint p2, ofPoint p3, float mu )
{
    double mum1,mum12,mu2;
    ofPoint p;

    mu2 = mu * mu;
    mum1 = 1 - mu;
    mum12 = mum1 * mum1;
    p.x = p1.x * mum12 + 2 * p2.x * mum1 * mu + p3.x * mu2;
    p.y = p1.y * mum12 + 2 * p2.y * mum1 * mu + p3.y * mu2;
    p.z = p1.z * mum12 + 2 * p2.z * mum1 * mu + p3.z * mu2;

    return(p);
}

//-----------------------------------------
inline ofPoint getBezier4Pt( ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float mu );
inline ofPoint getBezier4Pt( ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4,float mu )
{
   double mum1,mum13,mu3;
   ofPoint p;

   mum1 = 1 - mu;
   mum13 = mum1 * mum1 * mum1;
   mu3 = mu * mu * mu;

   p.x = mum13*p1.x + 3*mu*mum1*mum1*p2.x + 3*mu*mu*mum1*p3.x + mu3*p4.x;
   p.y = mum13*p1.y + 3*mu*mum1*mum1*p2.y + 3*mu*mu*mum1*p3.y + mu3*p4.y;
   p.z = mum13*p1.z + 3*mu*mum1*mum1*p2.z + 3*mu*mu*mum1*p3.z + mu3*p4.z;

   return(p);
}

//-----------------------------------------
inline ofPoint getBezier( vector<ofPoint> & cpts, float mu );
inline ofPoint getBezier( vector<ofPoint> & cpts, float mu )
{

   int k,kn,nn,nkn;
   double blend,muk,munk;
   ofPoint b = ofPoint(0.0,0.0);

   int n = cpts.size()-1;

   muk = 1;
  // munk = pow(1-mu,(double)n);



   for (k=0;k<=n;k++) {
      nn = n;
      kn = k;
      nkn = n - k;
      blend = muk * munk;
      muk *= mu;
      munk /= (1-mu);
      while (nn >= 1) {
         blend *= nn;
         nn--;
         if (kn > 1) {
            blend /= (double)kn;
            kn--;
         }
         if (nkn > 1) {
            blend /= (double)nkn;
            nkn--;
         }
      }
      b.x += cpts[k].x * blend;
      b.y += cpts[k].y * blend;
      b.z += cpts[k].z * blend;
   }

   return(b);
}
#endif
