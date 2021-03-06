//main.h
#include <GL/glut.h>
#include "object.h"
#include <unistd.h>

//using namespace std;
#define WINW 512
#define WINH 512
#define WPOSX 100
#define WPOSY 50

#define PI 3.1415926

// ----- Scene Description -----
int szImg = 512;            //--  rendering screen size
int nrTypes = 2;            //--  object tpye = 0:SPHERE, 1:PLANE
int nrObjects = 0;          //--  num of object
int nrObjects0 = 0;         //-- backup for light objects;
// ----- Photon Mapping -----
int   nrPhotons = 64;     //--  Number of Photons Emitted
int   nrBounces = 3;        //--  Number of Times Each Photon Bounces
bool  lightPhotons = true;  //--  Enable Photon Lighting?
float exposure = 100.0;     //--  Number of Photons Integrated at Brightest Pixel
int   numPhotons[64];       //--  Photon Count for Each Scene Object

bool singleLight = false; //point Light or square Light?
bool squareObj = true; //add square light object?
//  Allocated Memory for Per-Object Photon Info
//  0 : location
//  1 : direction
//  2 : energy
Vector3 photons[64][5000][3];


/**functions**/

Vector3 reflect(
    CObj *ob,
    const Vector3 &point,
    const Vector3 &ray,
    const Vector3 &fromPoint);
Vector3 refract(
    CObj *ob,
    const Vector3 &point,
    const Vector3 &ray,
    const Vector3 &fromPoint,
    float &ref);

Vector3 gatherPhotons(const Vector3 &p, CObj *ob);
void    emitPhotons();
void    storePhoton(CObj *ob,
    const Vector3 &location,
    const Vector3 &direction,
    const Vector3 &energy );
void    shadowPhoton(const Vector3 &ray, const Vector3 &pnt);
void    drawPhoton(const Vector3 &rgb, const Vector3 &p);


Vector3 mulColor(const Vector3 &rgbIn, CObj *ob);

void render();
void resetRender();

void initObje();
void freeObje();

void display();
void resize (int w, int h);
void onKeyPress(unsigned char key, int x, int y);
void onClick(int button, int state, int x, int y);
void onDrag(int x, int y);
void onTimer(int val);

//--  screen status variables
//--  to stop drawing
bool empty = true;
//--  to switch Views
bool view3D = false;

bool mouseDragging = false;
int  mouseX, mouseY;

//--  rendering pixel info
int  pRow, pCol, pIteration, pMax;
