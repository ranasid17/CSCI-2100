{\rtf1\ansi\ansicpg1252\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
using namespace std;\
\
// swap function from Wk02 lecture notes \
void\
swap (int *x, int *y)\
\{\
  int temp;\
  temp = *x;\
  *x = *y;\
  *y = temp;\
  return;\
\}\
\
double\
percentChange (double newVal, int oldVal)\
\{\
  double difference = (newVal - oldVal) / double (oldVal) * 100;\
  if (difference < 0)\
    \{\
      difference = difference * (-1);\
    \}\
  return difference;\
\}\
\
int\
main ()\
\{\
  // init vars to hold dimensions \
  int a, b, c, d;\
  while (a != 0)\
    \{\
      cin >> a >> b >> c >> d;\
      // calculate scale factors (1)\
      double widthScale, heightScale;\
      widthScale = double (a) / c;\
      heightScale = double (b) / d;\
      // do nothing if image dim < paper dim \
      if (widthScale <= 1 || heightScale <= 1) \{\
	    cout << 100 << "%" << endl;\
      \}\
      else \{\
	    // rotate image dim when necessary (2)\
	    double scaledA, scaledB;\
	    if (widthScale > heightScale)\
	      \{\
	          swap (&a, &b);\
	         // update scale factors (2.2)\
	        widthScale = double (a) / c;\
	        heightScale = double (b) / d;\
	        // scaled dimensions\
	        scaledA = double (a) / heightScale;\
	        scaledB = double (b) / heightScale;\
	        \}\
	    else if (widthScale == heightScale) \{\
	       cout << 100 << "%"<< endl; \
	    \}\
	    else \
	       \{\
	        // scaled dimensions for no rotation \
	        scaledA = double (a) / widthScale;\
	        scaledB = double (b) / widthScale;\
	    \}\
	    double perChange;\
	    perChange = percentChange (scaledA, a);\
	    //cout << a << " " << b << " " << c << " " << d << endl;\
	    //cout << scaledA << " " << scaledB << endl;\
	    cout << perChange << "%" << endl;\
	 \}\
    \}\
    if (a == 0) \{ \
       cout << 100 << "%" << endl; \
    \}\
  return 0;\
\}\
}