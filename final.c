
#include<math.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int width,height;
double  r=.2,s=.3;  
int i;
float  tx=05,bx=20;
# define PI           3.14159265358979323846

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-210,210,-220,310,-210,310);
}

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}


//-----------------------sky------------------------------------------------------------------

//-----------------------cloud-----------------------------------------------------------------
void cloud(double x, double y)
{
   
    
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*r;
            y=y+sin((i*3.14)/180)*r;
 
            glVertex2d(x,y);
            
        }
        
        
    glEnd();

        
    
}
void sun(double x, double y)
{
   
    
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*s;
            y=y+sin((i*3.14)/180)*s;
 
            glVertex2d(x,y);
            
        }
        
        
    glEnd();

        
    
}
// ------------------------------------Fence-------------------------------------------------
void fence(int x)
{
    glBegin(GL_POLYGON);  
        glColor3ub(184,134,11);
        
        glVertex2i(190-x,130);
        glVertex2i(190-x,70);
        glVertex2i(187-x,70);
        glVertex2i(187-x,130);
        glVertex2i(190-x,130);

        
        
    glEnd();

}

//--------------------------------------------------------------------------------------------





void display() 
{

    glClear(GL_COLOR_BUFFER_BIT);
//-----------------------sky------------------------------------------------------------------
    glColor3ub(135,206,250);//light blue
        glRecti(-200,300,200,100);
//-----------------------------------field------------------------------
    glBegin(GL_POLYGON);  
        glColor3ub(0,100,0);//green
        
        glVertex2i(-200,100);
        glVertex2i(-100,160);
        glVertex2i(0,100);
        glVertex2i(50,70);
        glVertex2i(100,180);
        glVertex2i(200,100);
        glColor3ub(255,215,0);//gold
        glVertex2i(200,-200);
        
        glVertex2i(-200,-200);
        glColor3ub(255,215,0);//gold
        glVertex2i(-200,100);
        
    glEnd();
    
//-------------------SUN-------------------------
    glColor3ub(255,215,0);
    sun(90,250);
// ------------------------------------fence--------------------------
    int x=0;
    for(int i=0;i<39;i++)
    {
        fence(x);
        x+=10;
    }
    
    glColor3ub(184,134,11);
    glRecti(-200,120,200,115);
    glRecti(-200,100,200,95);
    glRecti(-200,85,200,80);
    
    
//-------------------------------------TREE------------------------
    glColor3ub(139,69,19);//
    glRecti(-20,200,-13,140);
    glColor3ub(0,100,0);
    sun(-30,190);
    sun(0,190);
    sun(-10,210);
    sun(-30,175);
    sun(-0,170);
    glBegin(GL_POLYGON); // Main Tree // first part
        glColor3ub(139,69,19);//
        glVertex2i(-170,160);
        glVertex2i(-168,120);
        glColor3ub(139,69,19);//
        glVertex2i(-178,40);
        glVertex2i(-145,40);
        glColor3ub(139,69,19);//
        glVertex2i(-153,120);
        glVertex2i(-150,160);
        glVertex2i(-170,160);   
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // second part
        glColor3ub(139,69,19);//
        glVertex2i(-153,100);
        glVertex2i(-100,200); 
        glVertex2i(-95,200); 
        glVertex2i(-153,80);
        glVertex2i(-153,100); 
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // third part
        glColor3ub(139,69,19);//
        glVertex2i(-170,160);
        glVertex2i(-185,210);
        glVertex2i(-190,210);
        glVertex2i(-168,90);
        glVertex2i(-170,160);
        
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // fourth part
        glColor3ub(139,69,19);//
        glVertex2i(-160,160);
        glVertex2i(-150,210);
        glVertex2i(-140,210);
        glVertex2i(-150,160);
        glVertex2i(-160,160);
        
        
    glEnd();
    glColor3ub(0,128,0);//leaf
        sun(-95,200);
        sun(-80,180);
        sun(-110,180);
        sun(-120,200);

        sun(-150,200);
        sun(-130,180);
        sun(-125,220);
        sun(-140,230);

        sun(-190,210);
        sun(-180,200);
        sun(-175,225);
        sun(-195,190);
        

//-----------------------------------------------TUBEWELL-----------------------------------------
    
    glBegin(GL_POLYGON);  // First part

        glColor3ub(0,100,0);//
        glVertex2i(115,65);
        glVertex2i(95,5);
        glVertex2i(145,5);
        glVertex2i(165,65);
        glVertex2i(115,65);
        
    glEnd();
    glBegin(GL_POLYGON);  // second part

        glColor3ub(143,188,143);//
        glVertex2i(120,58);
        glVertex2i(104,13);
        glVertex2i(140,12);
        glVertex2i(155,58);
        glVertex2i(120,58);
        
    glEnd();
    glColor3ub(0,0,0);// third part
        glRecti(95,5,145,-6);

    glBegin(GL_POLYGON);  // fourth  part
        glColor3ub(0,0,0);//
        glVertex2i(165,65);
        glVertex2i(166,55);
        glVertex2i(145,-6);
        glVertex2i(145,5);
        glVertex2i(165,65);       
    glEnd();
    glBegin(GL_POLYGON);  // tubewell 1st part
        glColor3ub(184,134,11);
        glVertex2i(120,85);
        glVertex2i(120,30);
        glVertex2i(125,28);
        glVertex2i(130,30);
        glVertex2i(130,85);
        glVertex2i(125,87);
        glVertex2i(120,85);          
    glEnd();
    glBegin(GL_POLYGON);  // tubewell second part
        glColor3ub(255,215,0);//golden rod
        glVertex2i(120,85);
        glVertex2i(125,80);
        glVertex2i(130,85);
        glVertex2i(125,87);
        glVertex2i(120,85);

    glEnd();
    glColor3ub(205,133,63);//golden rod // tubewell third part
    glRecti(123,100,126,85);

    glBegin(GL_POLYGON);  // tubewell fourth part
        glColor3ub(139,69,19);//saddle brown
        glVertex2i(126,100);
        glVertex2i(128,102);
        glVertex2i(128,110);
        glVertex2i(126,113);
        glVertex2i(124,111);
        glVertex2i(100,80);
        glVertex2i(90,70);
        glVertex2i(90,65);
        glVertex2i(100,73);
        glVertex2i(126,100);
    glEnd();
    glBegin(GL_POLYGON);  // tubewell 5th part
        glColor3ub(210,105,30);//golden rod
        glVertex2i(130,70);
        glVertex2i(140,70);
        glVertex2i(140,50);
        glVertex2i(136,50);
        glVertex2i(136,60);
        glVertex2i(130,60);
        glVertex2i(130,70);
        
    glEnd();
    glColor3ub(210,105,30);//golden rod //tubewell last part
    glRecti(123,29,127,20);
    glColor3ub(139,69,19);//saddle brown
    glRecti(118,22,132,14);
// --------------------------------------- HOUSE one----------------------------
    glBegin(GL_POLYGON);  // first Part
        glColor3ub(128,0,0);//gray
        glVertex2i(-58,115);
        glVertex2i(-75,145);
        glVertex2i(-115,150);//point
        glVertex2i(-90,100);
        glVertex2i(-62,100);
        glVertex2i(-58,115);
        
    glEnd();
    glBegin(GL_POLYGON);  // second Part
        glColor3ub(120,0,0);//maroon   
        glVertex2i(-115,150);
        glVertex2i(-130,100);
        glVertex2i(-120,100);//point
        glVertex2i(-108,137);//point
        glVertex2i(-115,150);  
    glEnd();
    glBegin(GL_POLYGON);  // third Part
        glColor3ub(46,139,87);//
        glVertex2i(-108,137);
        glVertex2i(-120,100);
        glVertex2i(-120,45);
        glVertex2i(-90,40);//point
        glVertex2i(-90,100);
        glVertex2i(-108,137);
    glEnd();
    
    
    glBegin(GL_POLYGON);  // fourth Part
        glColor3ub(143,188,143);//
        glVertex2i(-90,40);
        glVertex2i(-60,45);
        glVertex2i(-60,100);
        glVertex2i(-90,100);
        
    glEnd();
    glColor3ub(120,0,0);//maroon // Door One
        glRecti(-75,80,-65,40);
    glColor3ub(120,0,0);//maroon // Door One
        glRecti(-110,90,-100,70);
    glBegin(GL_POLYGON);  // third Part (lower part 1)
        glColor3ub(0,0,0);//
        glVertex2i(-90,40);
        glVertex2i(-123,45);
        glVertex2i(-123,35);
        glVertex2i(-90,30);
        glVertex2i(-90,40);
        
    glEnd();
    glBegin(GL_POLYGON);  // third Part (lower part 2)
        glColor3ub(0,0,0);//
        glVertex2i(-90,40);
        glVertex2i(-55,45);
        glVertex2i(-55,35);
        glVertex2i(-90,30);
        glVertex2i(-90,40);
        
        
    glEnd();




//-------------------------------------------  HOUSE  two  -------------------------------------------------
    glBegin(GL_POLYGON);  // First part

        glColor3ub(25,25,112);//midnight blue
        glVertex2i(-50,140);
        glVertex2i(0,149);
        glVertex2i(-12,88);
        glVertex2i(-65,89);
        glVertex2i(-50,140);
    glEnd();
    
    
    
    

    glBegin(GL_POLYGON);  // Second Part
    glColor3ub(70,130,180);//midnight blue
        glVertex2i(-60,90);
        glVertex2i(-60,30);
        glVertex2i(-10,25);
        glVertex2i(-10,95);
    glEnd();
     

//---------------------------------------Door------------------------------------------
    glColor3ub(25,25,112);//midnight blue
    glRecti(-45,70,-30,27);

//--------------------------------------------------------------------------
    glBegin(GL_POLYGON);   // Third part 
    glColor3ub(95,158,160);//midnight blue
        glVertex2i(-10,25);
        glVertex2i(18,35);
        glVertex2i(18,100);
        glVertex2i(0,148);
        glVertex2i(-10,100);
        glVertex2i(-10,25);
        
    glEnd();
   
    glBegin(GL_POLYGON); 
    glColor3ub(25,25,112);//midnight blue
        glVertex2i(-1,150);
        glVertex2i(20,100);
        glVertex2i(17,90);
        glVertex2i(-4,140);
        glVertex2i(-1,150);

    glEnd();
    
    
    glBegin(GL_POLYGON);  // door
    glColor3ub(25,25,112);//midnight blue
        glVertex2i(0,70);
        glVertex2i(10,73);
        glVertex2i(10,32);
        glVertex2i(0,29);
        glVertex2i(0,70);
        
        
    glEnd();
    glBegin(GL_POLYGON);  // (lower part 1)
        glColor3ub(0,0,0);//
        glVertex2i(-10,25);
        glVertex2i(-10,15);
        glVertex2i(20,27);
        glVertex2i(20,37);
        glVertex2i(-10,25);
        
        
    glEnd();
    glBegin(GL_POLYGON);  // (lower part 2)
        glColor3ub(0,0,0);//
        glVertex2i(-10,25);
        glVertex2i(-62,30);
        glVertex2i(-62,20);
        glVertex2i(-10,15);
        glVertex2i(-10,25);
        
        
        
        
    glEnd();
    

//------------------------------------------RIVER--------------------------------------------------  
    glBegin(GL_POLYGON);
        glColor3ub(30,144,255);
        glVertex2i(-200,-50);
        glVertex2i(200,-30);
        glColor3ub(0,0,128);
        glVertex2i(200,-200);
        glVertex2i(-200,-200);
        glVertex2i(-200,-50);   
    glEnd();
    glBegin(GL_POLYGON); // border
        glColor3ub(128,128,0);
        glVertex2i(-200,-45);
        glVertex2i(200,-25);
        glVertex2i(200,-30);
        glVertex2i(-200,-50 );
        glVertex2i(-200,-45);   
    glEnd();
    
//-------------------------------------------CLOUD-------------------------------------------------
	glPushMatrix();
	glColor3ub(220,220,220);
    glTranslatef(tx,0,0);
    cloud(0,250); 
    cloud(15,245);
    cloud(10,240);
    cloud(-2,243);

    

    cloud(-80,250); 
    cloud(-95,245);
    cloud(-90,240);
    cloud(-90,243);
    cloud(-75,243);

    glPopMatrix();
    tx+=.01;
    if(tx>200)
    tx=-200;
//-------------------------------------------BOAT-------------------------------------------------
    glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(bx,0,0);
    glBegin(GL_POLYGON);
        glVertex2i(-180,-70);
        glVertex2i(-165,-100);
        glVertex2i(-150,-120);
        glVertex2i(-150,-100);
        glVertex2i(-180,-70);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(-150,-100);
        glVertex2i(-150,-120);
        glVertex2i(-120,-125);
        glVertex2i(-90,-120);
        glVertex2i(-85,-100);
        glVertex2i(-150,-100); 
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(-85,-100);
        glVertex2i(-90,-120);
        glVertex2i(-75,-105);  
        glVertex2i(-60,-70);
        glVertex2i(-85,-100);     
    glEnd();
    glColor3ub(211,211,211);
    sun(-165,260); 
    sun(-185,245);
    sun(-180,240);
    sun(-152,243);

    //--------------------------BOAT FLAG----------------------------
    glBegin(GL_POLYGON);
        glColor3ub(173,216,230);
        glVertex2i(-57,-40);
        glVertex2i(-50,-10);
        glVertex2i(-49,10);
        glVertex2i(-50,30);
        glVertex2i(-55,45);
        glVertex2i(-63,57);
        glVertex2i(-73,68); // end
        glVertex2i(-105,45);
        glVertex2i(-50,-10);
        
                   
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(173,216,230);
        
        glVertex2i(-68,-70);
        glVertex2i(-57,-40);
        glVertex2i(-85,10);
        glVertex2i(-68,-70);                
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(173,216,230);
        glVertex2i(-85,-100);
        glVertex2i(-68,-70);
        glVertex2i(-80,-10);
        glVertex2i(-85,-100);
                        
    glEnd();

    glColor3ub(139,69,19);
    glRecti(-88,80,-86,-100);  // Boat stand
    glBegin(GL_POLYGON);
        glColor3f(0.55,0.27,0.0745);//wood color
        glVertex2i(-85,-100);
        glVertex2i(-87,-80);
        glVertex2i(-93,-62);
        glVertex2i(-97,-55);
        glVertex2i(-105,-50);
        glVertex2i(-120,-48);
        glVertex2i(-120,-100);
        glVertex2i(-85,-100);
          
    glEnd();
    
    glBegin(GL_POLYGON);
        glColor3f(0.55,0.27,0.0745);//wood color
        glVertex2i(-150,-100);
        glVertex2i(-148,-80);
        glVertex2i(-142,-62);
        glVertex2i(-138,-55);
        glVertex2i(-130,-50);
        glVertex2i(-115,-48);
        glVertex2i(-115,-100);
        glVertex2i(-150,-100);
        
          
    glEnd();
    
//--------------------------BOAT LINE----------------------------
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-142,-62);
        glVertex2i(-73,68);
        glVertex2i(-73,63);

        glVertex2i(-142,-62);
        glVertex2i(-105,45);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-148,-80);
        glVertex2i(-87,-80);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-142,-62);
        glVertex2i(-93,-62);      
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-115,-48);
        glVertex2i(-115,-100);     
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-130,-50);
        glVertex2i(-130,-100);     
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);//Black
        glVertex2i(-100,-52);
        glVertex2i(-100,-100);     
    glEnd();
    
   



    glPopMatrix();
    bx+=.03;
    if(bx>270)
    bx=-180;

    
    glutPostRedisplay();
    glColor3ub(255,255,255);//
    glRecti(-210,310,-200,-210);
    glRecti(200,310,210,-210);
//--------------------------------------------------------------------------------------------
    glFlush();   
}


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

GLfloat z = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;



void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {

            speed += 0.1f;


    }

        if (button == GLUT_RIGHT_BUTTON)
    {

            speed -= 0.1f;


    }



    glutPostRedisplay();
}


void update(int value) {

    if(position > 1.70)
        position = -1.70f;

    position += speed;

    glutPostRedisplay();


    glutTimerFunc(250, update, 0);
}


GLfloat position1 = 0.0f;
GLfloat speed1 = 0.1f;


void update1(int value) {

    if(position1 > 1.70)
        position1 = -1.70f;

    position1 += speed1;

    glutPostRedisplay();


    glutTimerFunc(500, update1, 0);
}

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.1f;
void update2(int value) {

    if(position2 <-1.70)
        position2 = 1.70f;

    position2 -= speed2;

    glutPostRedisplay();


    glutTimerFunc(500, update2, 0);
}



GLfloat position5 = 0.0f;
GLfloat speed5 = 0.1f;
void update5(int value) {

    if(position5 <-2.50)
        position5 = 2.50f;

    position5 -= speed5;

    glutPostRedisplay();


    glutTimerFunc(200, update5, 0);
}


GLfloat position6 = 0.0f;
GLfloat speed6 = 0.1f;


void update6(int value) {

    if(position6 <- 2.50)
        position6 = 2.50f;

    position6 -= speed6;

    glutPostRedisplay();


    glutTimerFunc(200, update6, 0);
}


void night()
{
    glClearColor(0.184314f, 0.184314f, 0.309804f,0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glPointSize(2.0);
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // Red
    glVertex2f(0.4f, 0.4f);    // x, y
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.7f, 0.4f);
    glVertex2f(-0.5f, 0.7f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.9f, 0.8f);
    glVertex2f(0.9f, 0.8f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.1f, 0.9f);
    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.75f, 0.7f);
    glVertex2f(-0.9f, 0.5f);
    glEnd();

    glPointSize(3.0);
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // Red
    glVertex2f(0.6f, 0.5f);    // x, y
    glVertex2f(0.4f, 0.9f);
    glVertex2f(-0.4f, 0.6f);
    glVertex2f(0.2f, 0.9f);
    glVertex2f(-0.3f, 0.6f);
    glVertex2f(0.0f, 0.75f);
    glEnd();





//Moon
glLoadIdentity();
 glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
    GLfloat x5=.7f;
    GLfloat y5=.7f;
    GLfloat radius5 =.07f;
    GLfloat twicePi5 = 2.0f * PI;
   GLfloat triangleAmount5=100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount5; i++)
    {
        glVertex2f(
            x5 + (radius5 * cos(i *  twicePi5 / triangleAmount5)),
            y5 + (radius5 * sin(i * twicePi5 / triangleAmount5))
        );
    }
    glEnd();




      //PLANE CODE START



 glLoadIdentity();


glPushMatrix();
 glScalef(0.4,0.4,0);
 glTranslatef(0.0f,1.5f, 0.0f);
glTranslatef(position6, 0.0f, 0.0f);

    glBegin(GL_POLYGON); // airplane outer body
    glColor3ub(234, 229, 229); // white
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.45f, 0.5f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.35f, 0.38f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.35f, 0.23f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON); // airplane front window
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(-0.37f, 0.35f);
    glVertex2f(-0.32f, 0.35f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.38f);
    glVertex2f(-0.35f, 0.38f);
    glEnd();
    glBegin(GL_LINES); // airplane front window
    glColor3ub(255, 255, 255); // white
    glVertex2f(-0.35f, 0.35f);
    glVertex2f(-0.33f, 0.38f);
    glVertex2f(-0.33f, 0.35f);
    glVertex2f(-0.31f, 0.38f);
    glEnd();
    glBegin(GL_LINES); // airplane front door
    glColor3ub(144, 126, 181); // purple one
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.23f, 0.24f);
    glVertex2f(-0.23f, 0.24f);
    glVertex2f(-0.18f, 0.24f);
    glVertex2f(-0.18f, 0.24f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.36f);
    glVertex2f(-0.16f, 0.36f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.23f, 0.38f);
    glVertex2f(-0.23f, 0.38f);
    glVertex2f(-0.25f, 0.36f);
    glVertex2f(-0.25f, 0.36f);
    glVertex2f(-0.25f, 0.26f);
    glEnd();
    glBegin(GL_QUADS); // Airplane front wind
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(0.02f, 0.15f);
    glVertex2f(0.05f, 0.15f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.1f, 0.26f);
    glEnd();
    glBegin(GL_QUADS); // Airplane back wind
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(-0.08f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.07f, 0.49f);
    glVertex2f(0.04f, 0.49f);
    glEnd();
    // Airplane  window
    glColor3ub(117, 69, 160); // purple one
    GLfloat x2=-0.09f;
    GLfloat y2=0.35f;
    GLfloat  radius1 =.02f;
     int triangleAmount1 = 100;
    GLfloat twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x2 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y2 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
    // Airplane  window
    glColor3ub(117, 69, 160); // purple one
    GLfloat x3=-0.02f;
    GLfloat y3=0.35f;
     radius1 =.02f;
       twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y3 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
    // Airplane  window
    glColor3ub(117, 69, 160); // purple one
    GLfloat x4=0.06f;
    GLfloat y4=0.35f;
    radius1 =.02f;
    twicePi1 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
            y4 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

glPopMatrix();

   //PLANE CODE END

//HOUSE or BUILDING

   glBegin(GL_QUADS);//house 1
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.95f,-0.5f);
   glVertex2f(-.85f,-0.5f);
    glVertex2f( -.85f,.3f);
    glVertex2f( -.95f,.3f);
    glEnd();


   glBegin(GL_QUADS);//house 1
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.91f,0.5f);
   glVertex2f(-.89f,0.5f);
    glVertex2f( -.85f,.3f);
    glVertex2f( -.95f,.3f);
    glEnd();
       glBegin(GL_QUADS);//house 1
    glColor3f(.7f, .6f, .0f);
   glVertex2f( -.93f,-0.5f);
   glVertex2f(-.87f,-0.5f);
    glVertex2f( -.87f,.4f);
    glVertex2f( -.93f,.4f);
    glEnd();

   glBegin(GL_LINES);//    antina
    glColor3f(.2f, .5f, 0.f);
   glVertex2f( -.9f,0.5f);
    glVertex2f( -.9f,.7f);
    glEnd();

       glBegin(GL_LINES);// col line
    glColor3f(.1f, .6f, 0.f);
   glVertex2f( -.93f,-0.5f);
   glVertex2f( -.93f,0.4f);
    glVertex2f( -.87f,-.5f);
     glVertex2f( -.87f,.4f);
    glEnd();



       glBegin(GL_LINES);// row line
    glColor3f(.1f, .6f, 0.f);
   glVertex2f( -.95f,-0.4f);
   glVertex2f( -.85f,-0.4f);

      glVertex2f( -.9f,-0.5f);
   glVertex2f( -.9f,0.5f);

   glVertex2f( -.95f,-0.3f);
   glVertex2f( -.85f,-0.3f);
     glVertex2f( -.95f,-0.2f);
   glVertex2f( -.85f,-0.2f);
     glVertex2f( -.95f,-0.1f);
   glVertex2f( -.85f,-0.1f);
  glVertex2f( -.95f,0.0f);
   glVertex2f( -.85f,0.0f);
     glVertex2f( -.95f,0.1f);
   glVertex2f( -.85f,0.1f);
     glVertex2f( -.95f,0.2f);
   glVertex2f( -.85f,0.2f);
     glVertex2f( -.95f,0.3f);
   glVertex2f( -.85f,0.3f);
    glVertex2f( -.93f,0.4f);
   glVertex2f( -.87f,0.4f);
    glEnd();




     glBegin(GL_QUADS);//tower2
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.77f,-.5f);
   glVertex2f(-.7f,-0.5f);
    glVertex2f( -.7f,.7f);
    glVertex2f( -.8f,.5f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.77f,-.4f);
   glVertex2f(-.7f,-0.4f);
    glVertex2f( -.7f,-.41f);
    glVertex2f( -.77f,-.41f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-.3f);
   glVertex2f(-.7f,-0.3f);
    glVertex2f( -.7f,-.31f);
    glVertex2f( -.78f,-.31f);
    glEnd();


     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-.2f);
   glVertex2f(-.7f,-0.2f);
    glVertex2f( -.7f,-.21f);
    glVertex2f( -.78f,-.21f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-0.1f);
   glVertex2f(-.7f,-0.1f);
    glVertex2f( -.7f,-.11f);
    glVertex2f( -.78f,-.11f);
    glEnd();


      glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.0f);
   glVertex2f(-.7f,0.0f);
    glVertex2f( -.7f,0.01f);
    glVertex2f( -.78f,0.01f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.1f);
   glVertex2f(-.7f,0.1f);
    glVertex2f( -.7f,0.11f);
    glVertex2f( -.78f,0.11f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.2f);
   glVertex2f(-.7f,0.2f);
    glVertex2f( -.7f,0.21f);
    glVertex2f( -.79f,0.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.3f);
   glVertex2f(-.7f,0.3f);
    glVertex2f( -.7f,0.31f);
    glVertex2f( -.79f,0.31f);
    glEnd();


     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.4f);
   glVertex2f(-.7f,0.4f);
    glVertex2f( -.7f,0.41f);
    glVertex2f( -.79f,0.41f);
    glEnd();

     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.5f);
   glVertex2f(-.7f,0.5f);
    glVertex2f( -.7f,0.51f);
    glVertex2f( -.79f,0.51f);
    glEnd();

     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.75f,-0.5f);
   glVertex2f(-.758f,-0.5f);
    glVertex2f( -.758f,0.5f);
    glVertex2f( -.75f,0.5f);
    glEnd();


     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.72f,-0.5f);
   glVertex2f(-.728f,-0.5f);
    glVertex2f( -.728f,0.5f);
    glVertex2f( -.72f,0.5f);
    glEnd();




     glBegin(GL_QUADS);//tower3
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.69f,-.5f);
   glVertex2f(-.62f,-0.5f);
    glVertex2f( -.6f,.5f);
    glVertex2f( -.69f,.6f);
    glEnd();



    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.4f);
   glVertex2f(-.61f,-0.4f);
    glVertex2f( -.61f,-.41f);
    glVertex2f( -.69f,-.41f);
    glEnd();

   glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.3f);
   glVertex2f(-.61f,-0.3f);
    glVertex2f( -.61f,-.31f);
    glVertex2f( -.69f,-.31f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.2f);
   glVertex2f(-.61f,-0.2f);
    glVertex2f( -.61f,-.21f);
    glVertex2f( -.69f,-.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.1f);
   glVertex2f(-.61f,-0.1f);
    glVertex2f( -.61f,-.11f);
    glVertex2f( -.69f,-.11f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.0f);
   glVertex2f(-.61f,0.0f);
    glVertex2f( -.61f,0.01f);
    glVertex2f( -.69f,0.01f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.1f);
   glVertex2f(-.61f,0.1f);
    glVertex2f( -.61f,0.11f);
    glVertex2f( -.69f,0.11f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.2f);
   glVertex2f(-.61f,0.2f);
    glVertex2f( -.61f,0.21f);
    glVertex2f( -.69f,0.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.2f);
   glVertex2f(-.61f,0.2f);
    glVertex2f( -.61f,0.21f);
    glVertex2f( -.69f,0.21f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.3f);
   glVertex2f(-.61f,0.3f);
    glVertex2f( -.61f,0.31f);
    glVertex2f( -.69f,0.31f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.4f);
   glVertex2f(-.61f,0.4f);
    glVertex2f( -.61f,0.41f);
    glVertex2f( -.69f,0.41f);
    glEnd();


   glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.5f);
   glVertex2f(-.61f,0.5f);
    glVertex2f( -.61f,0.51f);
    glVertex2f( -.69f,0.51f);
    glEnd();

       glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.67f,-0.5f);
   glVertex2f(-.678f,-0.5f);
    glVertex2f( -.678f,0.5f);
    glVertex2f( -.67f,0.5f);
    glEnd();


       glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.65f,-0.5f);
   glVertex2f(-.658f,-0.5f);
    glVertex2f( -.658f,0.5f);
    glVertex2f( -.65f,0.5f);
    glEnd();


     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.63f,-0.5f);
   glVertex2f(-.638f,-0.5f);
    glVertex2f( -.638f,0.5f);
    glVertex2f( -.63f,0.5f);
    glEnd();


//KHALIFA TOWE START

   glBegin(GL_QUADS);// mid tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.2f,-.5f);
   glVertex2f(-.15f,-.5f);
    glVertex2f( -.15f,.85f);
    glVertex2f( -.2f,.85f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.48f);
   glVertex2f(-.17f,-.48f);
    glVertex2f( -.17f,-.42f);
    glVertex2f( -.19f,-.42f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.38f);
   glVertex2f(-.17f,-.38f);
    glVertex2f( -.17f,-.32f);
    glVertex2f( -.19f,-.32f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.28f);
   glVertex2f(-.17f,-.28f);
    glVertex2f( -.17f,-.22f);
    glVertex2f( -.19f,-.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.18f);
   glVertex2f(-.17f,-.18f);
    glVertex2f( -.17f,-.12f);
    glVertex2f( -.19f,-.12f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.08f);
   glVertex2f(-.17f,-.08f);
    glVertex2f( -.17f,-.02f);
    glVertex2f( -.19f,-.02f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.08f);
   glVertex2f(-.17f,.08f);
    glVertex2f( -.17f,.02f);
    glVertex2f( -.19f,.02f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.18f);
   glVertex2f(-.17f,.18f);
    glVertex2f( -.17f,.12f);
    glVertex2f( -.19f,.12f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.28f);
   glVertex2f(-.17f,.28f);
    glVertex2f( -.17f,.22f);
    glVertex2f( -.19f,.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.38f);
   glVertex2f(-.17f,.38f);
    glVertex2f( -.17f,.32f);
    glVertex2f( -.19f,.32f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.48f);
   glVertex2f(-.17f,.48f);
    glVertex2f( -.17f,.42f);
    glVertex2f( -.19f,.42f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.58f);
   glVertex2f(-.17f,.58f);
    glVertex2f( -.17f,.52f);
    glVertex2f( -.19f,.52f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.68f);
   glVertex2f(-.17f,.68f);
    glVertex2f( -.17f,.62f);
    glVertex2f( -.19f,.62f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.78f);
   glVertex2f(-.17f,.78f);
    glVertex2f( -.17f,.72f);
    glVertex2f( -.19f,.72f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.179f,.85f);
   glVertex2f(-.171f,.85f);
    glVertex2f( -.171f,.82f);
    glVertex2f( -.179f,.82f);
    glEnd();







    glBegin(GL_QUADS);//tower khalifa antena
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.18f,-.85f);
   glVertex2f(-.17f,-.85f);
    glVertex2f( -.17f,.98f);
    glVertex2f( -.18f,.98f);
    glEnd();




     glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.15f,-.5f);
   glVertex2f(-.1f,-.5f);
    glVertex2f( -.1f,.5f);
    glVertex2f( -.15f,.5f);
    glEnd();


     glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.48f);
   glVertex2f(-.121f,.48f);
    glVertex2f( -.121f,.42f);
    glVertex2f( -.129f,.42f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.38f);
   glVertex2f(-.121f,.38f);
    glVertex2f( -.121f,.32f);
    glVertex2f( -.129f,.32f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.28f);
   glVertex2f(-.121f,.28f);
    glVertex2f( -.121f,.22f);
    glVertex2f( -.129f,.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.18f);
   glVertex2f(-.121f,.18f);
    glVertex2f( -.121f,.12f);
    glVertex2f( -.129f,.12f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.08f);
   glVertex2f(-.121f,.08f);
    glVertex2f( -.121f,.02f);
    glVertex2f( -.129f,.02f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.08f);
   glVertex2f(-.121f,-.08f);
    glVertex2f( -.121f,-.02f);
    glVertex2f( -.129f,-.02f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.18f);
   glVertex2f(-.121f,-.18f);
    glVertex2f( -.121f,-.12f);
    glVertex2f( -.129f,-.12f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.28f);
   glVertex2f(-.121f,-.28f);
    glVertex2f( -.121f,-.22f);
    glVertex2f( -.129f,-.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.38f);
   glVertex2f(-.121f,-.38f);
    glVertex2f( -.121f,-.32f);
    glVertex2f( -.129f,-.32f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.48f);
   glVertex2f(-.121f,-.48f);
    glVertex2f( -.121f,-.42f);
    glVertex2f( -.129f,-.42f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.58f);
   glVertex2f(-.121f,-.58f);
    glVertex2f( -.121f,-.52f);
    glVertex2f( -.129f,-.52f);
    glEnd();





      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.25f,-.5f);
   glVertex2f(-.2f,-.5f);
    glVertex2f( -.2f,.7f);
    glVertex2f( -.25f,.7f);
    glEnd();


      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.3f,-.5f);
   glVertex2f(-.25f,-.5f);
    glVertex2f( -.25f,.3f);
    glVertex2f( -.3f,.3f);
    glEnd();


      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.1f,-.5f);
   glVertex2f(-.05f,-.5f);
    glVertex2f( -.05f,.15f);
    glVertex2f( -.1f,.15f);
    glEnd();


     glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.35f,-.5f);
   glVertex2f(-.3f,-.5f);
    glVertex2f( -.3f,.05f);
    glVertex2f( -.35f,.05f);
    glEnd();


        glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.48f);
   glVertex2f(-.071f,-.48f);
    glVertex2f( -.071f,-.42f);
    glVertex2f( -.079f,-.42f);
    glEnd();

        glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.38f);
   glVertex2f(-.071f,-.38f);
    glVertex2f( -.071f,-.32f);
    glVertex2f( -.079f,-.32f);
    glEnd();
            glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.28f);
   glVertex2f(-.071f,-.28f);
    glVertex2f( -.071f,-.22f);
    glVertex2f( -.079f,-.22f);
    glEnd();
            glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.18f);
   glVertex2f(-.071f,-.18f);
    glVertex2f( -.071f,-.12f);
    glVertex2f( -.079f,-.12f);
    glEnd();
                glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.08f);
   glVertex2f(-.071f,-.08f);
    glVertex2f( -.071f,-.02f);
    glVertex2f( -.079f,-.02f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,.08f);
   glVertex2f(-.071f,.08f);
    glVertex2f( -.071f,.02f);
    glVertex2f( -.079f,.02f);
    glEnd();


                  glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.48f);
   glVertex2f(-.221f,-.48f);
    glVertex2f( -.221f,-.42f);
    glVertex2f( -.229f,-.42f);
    glEnd();

                  glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.38f);
   glVertex2f(-.221f,-.38f);
    glVertex2f( -.221f,-.32f);
    glVertex2f( -.229f,-.32f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.28f);
   glVertex2f(-.221f,-.28f);
    glVertex2f( -.221f,-.22f);
    glVertex2f( -.229f,-.22f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.18f);
   glVertex2f(-.221f,-.18f);
    glVertex2f( -.221f,-.12f);
    glVertex2f( -.229f,-.12f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.08f);
   glVertex2f(-.221f,-.08f);
    glVertex2f( -.221f,-.02f);
    glVertex2f( -.229f,-.02f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.08f);
   glVertex2f(-.221f,.08f);
    glVertex2f( -.221f,.02f);
    glVertex2f( -.229f,.02f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.18f);
   glVertex2f(-.221f,.18f);
    glVertex2f( -.221f,.12f);
    glVertex2f( -.229f,.12f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.28f);
   glVertex2f(-.221f,.28f);
    glVertex2f( -.221f,.22f);
    glVertex2f( -.229f,.22f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.38f);
   glVertex2f(-.221f,.38f);
    glVertex2f( -.221f,.32f);
    glVertex2f( -.229f,.32f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.48f);
   glVertex2f(-.221f,.48f);
    glVertex2f( -.221f,.42f);
    glVertex2f( -.229f,.42f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.58f);
   glVertex2f(-.221f,.58f);
    glVertex2f( -.221f,.52f);
    glVertex2f( -.229f,.52f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.68f);
   glVertex2f(-.221f,.68f);
    glVertex2f( -.221f,.62f);
    glVertex2f( -.229f,.62f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.28f);
   glVertex2f(-.271f,.28f);
    glVertex2f( -.271f,.22f);
    glVertex2f( -.279f,.22f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.18f);
   glVertex2f(-.271f,.18f);
    glVertex2f( -.271f,.12f);
    glVertex2f( -.279f,.12f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.08f);
   glVertex2f(-.271f,.08f);
    glVertex2f( -.271f,.02f);
    glVertex2f( -.279f,.02f);
    glEnd();

           glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.08f);
   glVertex2f(-.271f,-.08f);
    glVertex2f( -.271f,-.02f);
    glVertex2f( -.279f,-.02f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.18f);
   glVertex2f(-.271f,-.18f);
    glVertex2f( -.271f,-.12f);
    glVertex2f( -.279f,-.12f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.28f);
   glVertex2f(-.271f,-.28f);
    glVertex2f( -.271f,-.22f);
    glVertex2f( -.279f,-.22f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.38f);
   glVertex2f(-.271f,-.38f);
    glVertex2f( -.271f,-.32f);
    glVertex2f( -.279f,-.32f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.48f);
   glVertex2f(-.271f,-.48f);
    glVertex2f( -.271f,-.42f);
    glVertex2f( -.279f,-.42f);
    glEnd();






      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.05f,-.5f);
   glVertex2f(-.0f,-.5f);
    glVertex2f( -.0f,-.15f);
    glVertex2f( -.05f,-.15f);
    glEnd();

//KHALIFA END

    glBegin(GL_QUADS); //  tower
    glColor3ub(76, 84, 109);
    glVertex2f(0.77f, -0.5f);
    glVertex2f(0.83f, -0.5f);
    glVertex2f(0.83f, -0.3f);
    glVertex2f(0.77f, -0.3f);
    glEnd();
    glBegin(GL_QUADS); //  tower
    glColor3ub(124, 193, 187);
    glVertex2f(0.75f, -0.3f);
    glVertex2f(0.85f, -0.3f);
    glVertex2f(0.85f, -0.28f);
    glVertex2f(0.75f, -0.28f);
    glEnd();
    glBegin(GL_QUADS); //  tower
    glColor3ub(112, 114, 114);
    glVertex2f(0.75f, -0.28f);
    glVertex2f(0.85f, -0.28f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.7f, -0.2f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(244, 230, 68);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f,  -0.15f);
    glVertex2f(0.7f,  -0.15f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(7, 175, 242);
    glVertex2f(0.7f, -0.15f);
    glVertex2f(0.9f, -0.15f);
    glVertex2f(0.83f,  -0.1f);
    glVertex2f(0.77f,  -0.1f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(139, 141, 142);
    glVertex2f(0.77f, -0.1f);
    glVertex2f(0.83f, -0.1f);
    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.75f,  -0.05f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(242, 199, 7);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.85f, -0.07f);
    glVertex2f(0.75f,  -0.07f);
    glEnd();
    glBegin(GL_LINES); //  tower
    glColor3ub(0, 0, 0);
    glVertex2f(0.8f, -0.05f);
    glVertex2f(0.8f, 0.1f);
    glEnd();
    glColor3ub(9, 239, 224); //  tower
    int i;
    GLfloat x=.8f;
    GLfloat y=.1f;
    GLfloat radius =.02f;
    int triangleAmount = 100; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();






glPopMatrix();



    glBegin(GL_QUADS); //  road
    glColor3ub(61, 60, 60);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(0.99f, -0.99f);
    glVertex2f(0.99f, -0.5f);
    glVertex2f(-0.99f, -0.5f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.9f, -0.75f);
    glVertex2f(-0.8f, -0.75f);
    glVertex2f(-0.8f, -0.73f);
    glVertex2f(-0.9f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.7f, -0.75f);
    glVertex2f(-0.6f, -0.75f);
    glVertex2f(-0.6f, -0.73f);
    glVertex2f(-0.7f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.5f, -0.75f);
    glVertex2f(-0.4f, -0.75f);
    glVertex2f(-0.4f, -0.73f);
    glVertex2f(-0.5f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.2f, -0.75f);
    glVertex2f(-0.2f, -0.73f);
    glVertex2f(-0.3f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.1f, -0.75f);
    glVertex2f(0.0f, -0.75f);
    glVertex2f(0.0f, -0.73f);
    glVertex2f(-0.1f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.1f, -0.75f);
    glVertex2f(0.2f, -0.75f);
    glVertex2f(0.2f, -0.73f);
    glVertex2f(0.1f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.3f, -0.75f);
    glVertex2f(0.4f, -0.75f);
    glVertex2f(0.4f, -0.73f);
    glVertex2f(0.3f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.5f, -0.75f);
    glVertex2f(0.6f, -0.75f);
    glVertex2f(0.6f, -0.73f);
    glVertex2f(0.5f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.7f, -0.75f);
    glVertex2f(0.8f, -0.75f);
    glVertex2f(0.8f, -0.73f);
    glVertex2f(0.7f, -0.73f);
    glEnd();

    //Bus
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(158, 23, 23);
    glVertex2f(-0.8, -0.65);
    glVertex2f(-0.3, -0.65);
    glVertex2f(-0.3, -0.55);
    glVertex2f(-0.35, -0.45);
    glVertex2f(-0.8, -0.45);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(37, 93, 170);
    glVertex2f(-0.37, -0.63);
    glVertex2f(-0.37, -0.5);
    glVertex2f(-0.43, -0.5);
    glVertex2f(-0.43, -0.63);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(37, 93, 170);
    glVertex2f(-0.46, -0.57);
    glVertex2f(-0.46, -0.5);
    glVertex2f(-0.52, -0.5);
    glVertex2f(-0.52, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(37, 93, 170);
    glVertex2f(-0.55, -0.57);
    glVertex2f(-0.55, -0.5);
    glVertex2f(-0.61, -0.5);
    glVertex2f(-0.61, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(37, 93, 170);
    glVertex2f(-0.64, -0.57);
    glVertex2f(-0.64, -0.5);
    glVertex2f(-0.70, -0.5);
    glVertex2f(-0.70, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(37, 93, 170);
    glVertex2f(-0.73, -0.57);
    glVertex2f(-0.73, -0.5);
    glVertex2f(-0.79, -0.5);
    glVertex2f(-0.79, -0.57);
    glEnd();

    // bus wheel
    // bus second wheel
    glColor3ub(0, 0, 0); // black hole
    GLfloat x6= -0.72f;
    GLfloat y6=-0.65f;
    radius =.03f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius * cos(i *  twicePi / triangleAmount)),
            y6 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    // bus second inner wheel
        glColor3ub(153, 140, 140); // silver hole
    GLfloat x7= -0.72f;
    GLfloat y7=-0.65f;
    radius =.01f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius * cos(i *  twicePi / triangleAmount)),
            y7 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
     glColor3ub(0, 0, 0); // black hole
    GLfloat x10= -0.52f;
    GLfloat y10=-0.65f;
    radius =.03f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10, y10); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x10 + (radius * cos(i *  twicePi / triangleAmount)),
            y10 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    // bus first wheel
    glColor3ub(153, 140, 140); // silver hole
    GLfloat x8= -0.52f;
    GLfloat y8=-0.65f;
    radius =.01f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius * cos(i *  twicePi / triangleAmount)),
            y8 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    //CLOUD



  glEnable(GL_LIGHTING);
  GLfloat global_ambient[] = {4.0, 4.0, 4.0, 0.1};
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);


     glLoadIdentity();
    glTranslatef(-0.9f,0.5f, 0.0f);
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle60;
    for (int i=0;i<360;i++)
    {
        angle60=i*3.1416/180;
        glVertex2f(0.0+0.05*cos(angle60),0.0+0.05*sin(angle60));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle61;
    for (int i=0;i<360;i++)
    {
        angle61=i*3.1416/180;
        glVertex2f(-0.05+0.05*cos(angle61),-0.05+0.05*sin(angle61));

    }
    glEnd();



      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle62;
    for (int i=0;i<360;i++)
    {
        angle62=i*3.1416/180;
        glVertex2f(0.07+0.05*cos(angle62),0.0+0.05*sin(angle62));

    }
    glEnd();


       glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle63;
    for (int i=0;i<360;i++)
    {
        angle63=i*3.1416/180;
        glVertex2f(0.045+0.05*cos(angle63),-0.05+0.05*sin(angle63));

    }
    glEnd();

    glPopMatrix();

    //CLOUD2


      glLoadIdentity();
    glTranslatef(0.8f,0.8f, 0.0f);
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle5;
    for (int i=0;i<360;i++)
    {
        angle5=i*3.1416/180;
        glVertex2f(0.0+0.05*cos(angle5),0.0+0.05*sin(angle5));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle4;
    for (int i=0;i<360;i++)
    {
        angle4=i*3.1416/180;
        glVertex2f(-0.05+0.05*cos(angle4),-0.05+0.05*sin(angle4));

    }
    glEnd();



      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle3;
    for (int i=0;i<360;i++)
    {
        angle3=i*3.1416/180;
        glVertex2f(0.07+0.05*cos(angle3),0.0+0.05*sin(angle3));

    }
    glEnd();


       glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle2;
    for (int i=0;i<360;i++)
    {
        angle2=i*3.1416/180;
        glVertex2f(0.045+0.05*cos(angle2),-0.05+0.05*sin(angle2));

    }
    glEnd();
    glPopMatrix();

     glDisable(GL_LIGHTING);
glPopMatrix();


    glFlush();
}

void day()
{
    glClearColor(0.196078f, 0.6f, 0.8f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)



    glBegin(GL_POLYGON); //mountain
    glColor3ub(53, 79, 1);
    glVertex2f(-0.9f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.25f, -0.4f);
    glVertex2f(-0.25f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.45f, -0.3f);
    glVertex2f(-0.45f, -0.3f);
    glVertex2f(-0.55f, -0.28f);
    glVertex2f(-0.55f, -0.28f);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.62f, -0.2f);
    glVertex2f(-0.62f, -0.2f);
    glVertex2f(-0.65f, -0.3f);
    glVertex2f(-0.65f, -0.3f);
    glVertex2f(-0.7f, -0.3f);
    glVertex2f(-0.7f, -0.3f);
    glVertex2f(-0.75f, -0.4f);
    glVertex2f(-0.75f, -0.4f);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.9f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON); //mountain
    glColor3ub(53, 79, 1);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.15f, -0.38f);
    glVertex2f(0.15f, -0.38f);
    glVertex2f(0.1f, -0.3f);
    glVertex2f(0.1f, -0.3f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.3f, -0.38f);
    glVertex2f(-0.3f, -0.38f);
    glVertex2f(-0.4f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON); //mountain
    glColor3ub(53, 79, 1);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.35f, 0.1f);
    glVertex2f(0.35f, 0.1f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.15f, -0.1f);
    glVertex2f(0.15f, -0.1f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();

//HOUSE or BUILDING

   glBegin(GL_QUADS);//house 1
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.95f,-0.5f);
   glVertex2f(-.85f,-0.5f);
    glVertex2f( -.85f,.3f);
    glVertex2f( -.95f,.3f);
    glEnd();


   glBegin(GL_QUADS);//house 1
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.91f,0.5f);
   glVertex2f(-.89f,0.5f);
    glVertex2f( -.85f,.3f);
    glVertex2f( -.95f,.3f);
    glEnd();
       glBegin(GL_QUADS);//house 1
    glColor3f(.7f, .6f, .0f);
   glVertex2f( -.93f,-0.5f);
   glVertex2f(-.87f,-0.5f);
    glVertex2f( -.87f,.4f);
    glVertex2f( -.93f,.4f);
    glEnd();

   glBegin(GL_LINES);//    antina
    glColor3f(.2f, .5f, 0.f);
   glVertex2f( -.9f,0.5f);
    glVertex2f( -.9f,.7f);
    glEnd();

       glBegin(GL_LINES);// col line
    glColor3f(.1f, .6f, 0.f);
   glVertex2f( -.93f,-0.5f);
   glVertex2f( -.93f,0.4f);
    glVertex2f( -.87f,-.5f);
     glVertex2f( -.87f,.4f);
    glEnd();



       glBegin(GL_LINES);// row line
    glColor3f(.1f, .6f, 0.f);
   glVertex2f( -.95f,-0.4f);
   glVertex2f( -.85f,-0.4f);

      glVertex2f( -.9f,-0.5f);
   glVertex2f( -.9f,0.5f);

   glVertex2f( -.95f,-0.3f);
   glVertex2f( -.85f,-0.3f);
     glVertex2f( -.95f,-0.2f);
   glVertex2f( -.85f,-0.2f);
     glVertex2f( -.95f,-0.1f);
   glVertex2f( -.85f,-0.1f);
  glVertex2f( -.95f,0.0f);
   glVertex2f( -.85f,0.0f);
     glVertex2f( -.95f,0.1f);
   glVertex2f( -.85f,0.1f);
     glVertex2f( -.95f,0.2f);
   glVertex2f( -.85f,0.2f);
     glVertex2f( -.95f,0.3f);
   glVertex2f( -.85f,0.3f);
    glVertex2f( -.93f,0.4f);
   glVertex2f( -.87f,0.4f);
    glEnd();




     glBegin(GL_QUADS);//tower2
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.77f,-.5f);
   glVertex2f(-.7f,-0.5f);
    glVertex2f( -.7f,.7f);
    glVertex2f( -.8f,.5f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.77f,-.4f);
   glVertex2f(-.7f,-0.4f);
    glVertex2f( -.7f,-.41f);
    glVertex2f( -.77f,-.41f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-.3f);
   glVertex2f(-.7f,-0.3f);
    glVertex2f( -.7f,-.31f);
    glVertex2f( -.78f,-.31f);
    glEnd();


     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-.2f);
   glVertex2f(-.7f,-0.2f);
    glVertex2f( -.7f,-.21f);
    glVertex2f( -.78f,-.21f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.78f,-0.1f);
   glVertex2f(-.7f,-0.1f);
    glVertex2f( -.7f,-.11f);
    glVertex2f( -.78f,-.11f);
    glEnd();


      glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.0f);
   glVertex2f(-.7f,0.0f);
    glVertex2f( -.7f,0.01f);
    glVertex2f( -.78f,0.01f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.1f);
   glVertex2f(-.7f,0.1f);
    glVertex2f( -.7f,0.11f);
    glVertex2f( -.78f,0.11f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.2f);
   glVertex2f(-.7f,0.2f);
    glVertex2f( -.7f,0.21f);
    glVertex2f( -.79f,0.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.3f);
   glVertex2f(-.7f,0.3f);
    glVertex2f( -.7f,0.31f);
    glVertex2f( -.79f,0.31f);
    glEnd();


     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.4f);
   glVertex2f(-.7f,0.4f);
    glVertex2f( -.7f,0.41f);
    glVertex2f( -.79f,0.41f);
    glEnd();

     glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.79f,0.5f);
   glVertex2f(-.7f,0.5f);
    glVertex2f( -.7f,0.51f);
    glVertex2f( -.79f,0.51f);
    glEnd();

     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.75f,-0.5f);
   glVertex2f(-.758f,-0.5f);
    glVertex2f( -.758f,0.5f);
    glVertex2f( -.75f,0.5f);
    glEnd();


     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.72f,-0.5f);
   glVertex2f(-.728f,-0.5f);
    glVertex2f( -.728f,0.5f);
    glVertex2f( -.72f,0.5f);
    glEnd();




     glBegin(GL_QUADS);//tower3
    glColor3f(1.7f, 1.f, 1.6f);
   glVertex2f( -.69f,-.5f);
   glVertex2f(-.62f,-0.5f);
    glVertex2f( -.6f,.5f);
    glVertex2f( -.69f,.6f);
    glEnd();



    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.4f);
   glVertex2f(-.61f,-0.4f);
    glVertex2f( -.61f,-.41f);
    glVertex2f( -.69f,-.41f);
    glEnd();

   glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.3f);
   glVertex2f(-.61f,-0.3f);
    glVertex2f( -.61f,-.31f);
    glVertex2f( -.69f,-.31f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.2f);
   glVertex2f(-.61f,-0.2f);
    glVertex2f( -.61f,-.21f);
    glVertex2f( -.69f,-.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,-.1f);
   glVertex2f(-.61f,-0.1f);
    glVertex2f( -.61f,-.11f);
    glVertex2f( -.69f,-.11f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.0f);
   glVertex2f(-.61f,0.0f);
    glVertex2f( -.61f,0.01f);
    glVertex2f( -.69f,0.01f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.1f);
   glVertex2f(-.61f,0.1f);
    glVertex2f( -.61f,0.11f);
    glVertex2f( -.69f,0.11f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.2f);
   glVertex2f(-.61f,0.2f);
    glVertex2f( -.61f,0.21f);
    glVertex2f( -.69f,0.21f);
    glEnd();

    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.2f);
   glVertex2f(-.61f,0.2f);
    glVertex2f( -.61f,0.21f);
    glVertex2f( -.69f,0.21f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.3f);
   glVertex2f(-.61f,0.3f);
    glVertex2f( -.61f,0.31f);
    glVertex2f( -.69f,0.31f);
    glEnd();


    glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.4f);
   glVertex2f(-.61f,0.4f);
    glVertex2f( -.61f,0.41f);
    glVertex2f( -.69f,0.41f);
    glEnd();


   glBegin(GL_QUADS);//row quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.69f,0.5f);
   glVertex2f(-.61f,0.5f);
    glVertex2f( -.61f,0.51f);
    glVertex2f( -.69f,0.51f);
    glEnd();

       glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.67f,-0.5f);
   glVertex2f(-.678f,-0.5f);
    glVertex2f( -.678f,0.5f);
    glVertex2f( -.67f,0.5f);
    glEnd();


       glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.65f,-0.5f);
   glVertex2f(-.658f,-0.5f);
    glVertex2f( -.658f,0.5f);
    glVertex2f( -.65f,0.5f);
    glEnd();


     glBegin(GL_QUADS);//col quad
    glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f( -.63f,-0.5f);
   glVertex2f(-.638f,-0.5f);
    glVertex2f( -.638f,0.5f);
    glVertex2f( -.63f,0.5f);
    glEnd();

 // Khalifa start

 glBegin(GL_QUADS);// mid tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.2f,-.5f);
   glVertex2f(-.15f,-.5f);
    glVertex2f( -.15f,.85f);
    glVertex2f( -.2f,.85f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.48f);
   glVertex2f(-.17f,-.48f);
    glVertex2f( -.17f,-.42f);
    glVertex2f( -.19f,-.42f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.38f);
   glVertex2f(-.17f,-.38f);
    glVertex2f( -.17f,-.32f);
    glVertex2f( -.19f,-.32f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.28f);
   glVertex2f(-.17f,-.28f);
    glVertex2f( -.17f,-.22f);
    glVertex2f( -.19f,-.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.18f);
   glVertex2f(-.17f,-.18f);
    glVertex2f( -.17f,-.12f);
    glVertex2f( -.19f,-.12f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,-.08f);
   glVertex2f(-.17f,-.08f);
    glVertex2f( -.17f,-.02f);
    glVertex2f( -.19f,-.02f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.08f);
   glVertex2f(-.17f,.08f);
    glVertex2f( -.17f,.02f);
    glVertex2f( -.19f,.02f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.18f);
   glVertex2f(-.17f,.18f);
    glVertex2f( -.17f,.12f);
    glVertex2f( -.19f,.12f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.28f);
   glVertex2f(-.17f,.28f);
    glVertex2f( -.17f,.22f);
    glVertex2f( -.19f,.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.38f);
   glVertex2f(-.17f,.38f);
    glVertex2f( -.17f,.32f);
    glVertex2f( -.19f,.32f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.48f);
   glVertex2f(-.17f,.48f);
    glVertex2f( -.17f,.42f);
    glVertex2f( -.19f,.42f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.58f);
   glVertex2f(-.17f,.58f);
    glVertex2f( -.17f,.52f);
    glVertex2f( -.19f,.52f);
    glEnd();

    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.68f);
   glVertex2f(-.17f,.68f);
    glVertex2f( -.17f,.62f);
    glVertex2f( -.19f,.62f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.19f,.78f);
   glVertex2f(-.17f,.78f);
    glVertex2f( -.17f,.72f);
    glVertex2f( -.19f,.72f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.179f,.85f);
   glVertex2f(-.171f,.85f);
    glVertex2f( -.171f,.82f);
    glVertex2f( -.179f,.82f);
    glEnd();







    glBegin(GL_QUADS);//tower khalifa antena
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.18f,-.85f);
   glVertex2f(-.17f,-.85f);
    glVertex2f( -.17f,.98f);
    glVertex2f( -.18f,.98f);
    glEnd();




     glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.15f,-.5f);
   glVertex2f(-.1f,-.5f);
    glVertex2f( -.1f,.5f);
    glVertex2f( -.15f,.5f);
    glEnd();


     glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.48f);
   glVertex2f(-.121f,.48f);
    glVertex2f( -.121f,.42f);
    glVertex2f( -.129f,.42f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.38f);
   glVertex2f(-.121f,.38f);
    glVertex2f( -.121f,.32f);
    glVertex2f( -.129f,.32f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.28f);
   glVertex2f(-.121f,.28f);
    glVertex2f( -.121f,.22f);
    glVertex2f( -.129f,.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.18f);
   glVertex2f(-.121f,.18f);
    glVertex2f( -.121f,.12f);
    glVertex2f( -.129f,.12f);
    glEnd();



    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,.08f);
   glVertex2f(-.121f,.08f);
    glVertex2f( -.121f,.02f);
    glVertex2f( -.129f,.02f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.08f);
   glVertex2f(-.121f,-.08f);
    glVertex2f( -.121f,-.02f);
    glVertex2f( -.129f,-.02f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.18f);
   glVertex2f(-.121f,-.18f);
    glVertex2f( -.121f,-.12f);
    glVertex2f( -.129f,-.12f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.28f);
   glVertex2f(-.121f,-.28f);
    glVertex2f( -.121f,-.22f);
    glVertex2f( -.129f,-.22f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.38f);
   glVertex2f(-.121f,-.38f);
    glVertex2f( -.121f,-.32f);
    glVertex2f( -.129f,-.32f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.48f);
   glVertex2f(-.121f,-.48f);
    glVertex2f( -.121f,-.42f);
    glVertex2f( -.129f,-.42f);
    glEnd();


    glBegin(GL_QUADS);// mid tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.129f,-.58f);
   glVertex2f(-.121f,-.58f);
    glVertex2f( -.121f,-.52f);
    glVertex2f( -.129f,-.52f);
    glEnd();





      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.25f,-.5f);
   glVertex2f(-.2f,-.5f);
    glVertex2f( -.2f,.7f);
    glVertex2f( -.25f,.7f);
    glEnd();


      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.3f,-.5f);
   glVertex2f(-.25f,-.5f);
    glVertex2f( -.25f,.3f);
    glVertex2f( -.3f,.3f);
    glEnd();


      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.1f,-.5f);
   glVertex2f(-.05f,-.5f);
    glVertex2f( -.05f,.15f);
    glVertex2f( -.1f,.15f);
    glEnd();


     glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.35f,-.5f);
   glVertex2f(-.3f,-.5f);
    glVertex2f( -.3f,.05f);
    glVertex2f( -.35f,.05f);
    glEnd();


        glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.48f);
   glVertex2f(-.071f,-.48f);
    glVertex2f( -.071f,-.42f);
    glVertex2f( -.079f,-.42f);
    glEnd();

        glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.38f);
   glVertex2f(-.071f,-.38f);
    glVertex2f( -.071f,-.32f);
    glVertex2f( -.079f,-.32f);
    glEnd();
            glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.28f);
   glVertex2f(-.071f,-.28f);
    glVertex2f( -.071f,-.22f);
    glVertex2f( -.079f,-.22f);
    glEnd();
            glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.18f);
   glVertex2f(-.071f,-.18f);
    glVertex2f( -.071f,-.12f);
    glVertex2f( -.079f,-.12f);
    glEnd();
                glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,-.08f);
   glVertex2f(-.071f,-.08f);
    glVertex2f( -.071f,-.02f);
    glVertex2f( -.079f,-.02f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f( -.079f,.08f);
   glVertex2f(-.071f,.08f);
    glVertex2f( -.071f,.02f);
    glVertex2f( -.079f,.02f);
    glEnd();


                  glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.48f);
   glVertex2f(-.221f,-.48f);
    glVertex2f( -.221f,-.42f);
    glVertex2f( -.229f,-.42f);
    glEnd();

                  glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.38f);
   glVertex2f(-.221f,-.38f);
    glVertex2f( -.221f,-.32f);
    glVertex2f( -.229f,-.32f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.28f);
   glVertex2f(-.221f,-.28f);
    glVertex2f( -.221f,-.22f);
    glVertex2f( -.229f,-.22f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.18f);
   glVertex2f(-.221f,-.18f);
    glVertex2f( -.221f,-.12f);
    glVertex2f( -.229f,-.12f);
    glEnd();
                      glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,-.08f);
   glVertex2f(-.221f,-.08f);
    glVertex2f( -.221f,-.02f);
    glVertex2f( -.229f,-.02f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.08f);
   glVertex2f(-.221f,.08f);
    glVertex2f( -.221f,.02f);
    glVertex2f( -.229f,.02f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.18f);
   glVertex2f(-.221f,.18f);
    glVertex2f( -.221f,.12f);
    glVertex2f( -.229f,.12f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.28f);
   glVertex2f(-.221f,.28f);
    glVertex2f( -.221f,.22f);
    glVertex2f( -.229f,.22f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.38f);
   glVertex2f(-.221f,.38f);
    glVertex2f( -.221f,.32f);
    glVertex2f( -.229f,.32f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.48f);
   glVertex2f(-.221f,.48f);
    glVertex2f( -.221f,.42f);
    glVertex2f( -.229f,.42f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.58f);
   glVertex2f(-.221f,.58f);
    glVertex2f( -.221f,.52f);
    glVertex2f( -.229f,.52f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.229f,.68f);
   glVertex2f(-.221f,.68f);
    glVertex2f( -.221f,.62f);
    glVertex2f( -.229f,.62f);
    glEnd();
   glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.28f);
   glVertex2f(-.271f,.28f);
    glVertex2f( -.271f,.22f);
    glVertex2f( -.279f,.22f);
    glEnd();
    glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.18f);
   glVertex2f(-.271f,.18f);
    glVertex2f( -.271f,.12f);
    glVertex2f( -.279f,.12f);
    glEnd();
       glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,.08f);
   glVertex2f(-.271f,.08f);
    glVertex2f( -.271f,.02f);
    glVertex2f( -.279f,.02f);
    glEnd();

           glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.08f);
   glVertex2f(-.271f,-.08f);
    glVertex2f( -.271f,-.02f);
    glVertex2f( -.279f,-.02f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.18f);
   glVertex2f(-.271f,-.18f);
    glVertex2f( -.271f,-.12f);
    glVertex2f( -.279f,-.12f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.28f);
   glVertex2f(-.271f,-.28f);
    glVertex2f( -.271f,-.22f);
    glVertex2f( -.279f,-.22f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.38f);
   glVertex2f(-.271f,-.38f);
    glVertex2f( -.271f,-.32f);
    glVertex2f( -.279f,-.32f);
    glEnd();
             glBegin(GL_QUADS);// left 2nd tower color
    glColor3f(5.0f, 0.5f, .0f);
   glVertex2f( -.279f,-.48f);
   glVertex2f(-.271f,-.48f);
    glVertex2f( -.271f,-.42f);
    glVertex2f( -.279f,-.42f);
    glEnd();






      glBegin(GL_QUADS);//tower khalifa
    glColor3f(0.137255f, 0.419608f, 0.556863f);
   glVertex2f( -.05f,-.5f);
   glVertex2f(-.0f,-.5f);
    glVertex2f( -.0f,-.15f);
    glVertex2f( -.05f,-.15f);
    glEnd();

//Khalifa End

    glBegin(GL_QUADS); //  tower
    glColor3ub(76, 84, 109);
    glVertex2f(0.77f, -0.5f);
    glVertex2f(0.83f, -0.5f);
    glVertex2f(0.83f, -0.3f);
    glVertex2f(0.77f, -0.3f);
    glEnd();
    glBegin(GL_QUADS); //  tower
    glColor3ub(124, 193, 187);
    glVertex2f(0.75f, -0.3f);
    glVertex2f(0.85f, -0.3f);
    glVertex2f(0.85f, -0.28f);
    glVertex2f(0.75f, -0.28f);
    glEnd();
    glBegin(GL_QUADS); //  tower
    glColor3ub(112, 114, 114);
    glVertex2f(0.75f, -0.28f);
    glVertex2f(0.85f, -0.28f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.7f, -0.2f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(244, 230, 68);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f,  -0.15f);
    glVertex2f(0.7f,  -0.15f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(7, 175, 242);
    glVertex2f(0.7f, -0.15f);
    glVertex2f(0.9f, -0.15f);
    glVertex2f(0.83f,  -0.1f);
    glVertex2f(0.77f,  -0.1f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(139, 141, 142);
    glVertex2f(0.77f, -0.1f);
    glVertex2f(0.83f, -0.1f);
    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.75f,  -0.05f);
    glEnd();
    glBegin(GL_QUADS); // Airplane tower
    glColor3ub(242, 199, 7);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.85f, -0.07f);
    glVertex2f(0.75f,  -0.07f);
    glEnd();
    glBegin(GL_LINES); //  tower
    glColor3ub(0, 0, 0);
    glVertex2f(0.8f, -0.05f);
    glVertex2f(0.8f, 0.1f);
    glEnd();
    glColor3ub(9, 239, 224); //  tower
    int i;
    GLfloat x=.8f;
    GLfloat y=.1f;
    GLfloat radius =.02f;
    int triangleAmount = 100; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();






glPopMatrix();



    glBegin(GL_QUADS); //  road
    glColor3ub(61, 60, 60);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(0.99f, -0.99f);
    glVertex2f(0.99f, -0.5f);
    glVertex2f(-0.99f, -0.5f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.9f, -0.75f);
    glVertex2f(-0.8f, -0.75f);
    glVertex2f(-0.8f, -0.73f);
    glVertex2f(-0.9f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.7f, -0.75f);
    glVertex2f(-0.6f, -0.75f);
    glVertex2f(-0.6f, -0.73f);
    glVertex2f(-0.7f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.5f, -0.75f);
    glVertex2f(-0.4f, -0.75f);
    glVertex2f(-0.4f, -0.73f);
    glVertex2f(-0.5f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.2f, -0.75f);
    glVertex2f(-0.2f, -0.73f);
    glVertex2f(-0.3f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.1f, -0.75f);
    glVertex2f(0.0f, -0.75f);
    glVertex2f(0.0f, -0.73f);
    glVertex2f(-0.1f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.1f, -0.75f);
    glVertex2f(0.2f, -0.75f);
    glVertex2f(0.2f, -0.73f);
    glVertex2f(0.1f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.3f, -0.75f);
    glVertex2f(0.4f, -0.75f);
    glVertex2f(0.4f, -0.73f);
    glVertex2f(0.3f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.5f, -0.75f);
    glVertex2f(0.6f, -0.75f);
    glVertex2f(0.6f, -0.73f);
    glVertex2f(0.5f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(0.7f, -0.75f);
    glVertex2f(0.8f, -0.75f);
    glVertex2f(0.8f, -0.73f);
    glVertex2f(0.7f, -0.73f);
    glEnd();

    //Bus
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(238, 223, 123);
    glVertex2f(-0.8, -0.65);
    glVertex2f(-0.3, -0.65);
    glVertex2f(-0.3, -0.55);
    glVertex2f(-0.35, -0.45);
    glVertex2f(-0.8, -0.45);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 30, 10);
    glVertex2f(-0.37, -0.63);
    glVertex2f(-0.37, -0.5);
    glVertex2f(-0.43, -0.5);
    glVertex2f(-0.43, -0.63);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 30, 10);
    glVertex2f(-0.46, -0.57);
    glVertex2f(-0.46, -0.5);
    glVertex2f(-0.52, -0.5);
    glVertex2f(-0.52, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 30, 10);
    glVertex2f(-0.55, -0.57);
    glVertex2f(-0.55, -0.5);
    glVertex2f(-0.61, -0.5);
    glVertex2f(-0.61, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 30, 10);
    glVertex2f(-0.64, -0.57);
    glVertex2f(-0.64, -0.5);
    glVertex2f(-0.70, -0.5);
    glVertex2f(-0.70, -0.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 30, 10);
    glVertex2f(-0.73, -0.57);
    glVertex2f(-0.73, -0.5);
    glVertex2f(-0.79, -0.5);
    glVertex2f(-0.79, -0.57);
    glEnd();

    // bus wheel
    // bus second wheel
    glColor3ub(0, 0, 0); // black hole
    GLfloat x5= -0.72f;
    GLfloat y5=-0.65f;
    radius =.03f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius * cos(i *  twicePi / triangleAmount)),
            y5 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    // bus second inner wheel
        glColor3ub(153, 140, 140); // silver hole
    GLfloat x7= -0.72f;
    GLfloat y7=-0.65f;
    radius =.01f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius * cos(i *  twicePi / triangleAmount)),
            y7 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
     glColor3ub(0, 0, 0); // black hole
    GLfloat x6= -0.52f;
    GLfloat y6=-0.65f;
    radius =.03f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius * cos(i *  twicePi / triangleAmount)),
            y6 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    // bus first wheel
    glColor3ub(153, 140, 140); // silver hole
    GLfloat x8= -0.52f;
    GLfloat y8=-0.65f;
    radius =.01f;
    twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius * cos(i *  twicePi / triangleAmount)),
            y8 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    //CLOUD



  glEnable(GL_LIGHTING);
  GLfloat global_ambient[] = {4.0, 4.0, 4.0, 0.1};
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);


     glLoadIdentity();
    glTranslatef(-0.9f,0.5f, 0.0f);
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle60;
    for (int i=0;i<360;i++)
    {
        angle60=i*3.1416/180;
        glVertex2f(0.0+0.05*cos(angle60),0.0+0.05*sin(angle60));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle61;
    for (int i=0;i<360;i++)
    {
        angle61=i*3.1416/180;
        glVertex2f(-0.05+0.05*cos(angle61),-0.05+0.05*sin(angle61));

    }
    glEnd();



      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle62;
    for (int i=0;i<360;i++)
    {
        angle62=i*3.1416/180;
        glVertex2f(0.07+0.05*cos(angle62),0.0+0.05*sin(angle62));

    }
    glEnd();


       glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle63;
    for (int i=0;i<360;i++)
    {
        angle63=i*3.1416/180;
        glVertex2f(0.045+0.05*cos(angle63),-0.05+0.05*sin(angle63));

    }
    glEnd();

    glPopMatrix();

    //CLOUD2


      glLoadIdentity();
    glTranslatef(0.8f,0.8f, 0.0f);
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle5;
    for (int i=0;i<360;i++)
    {
        angle5=i*3.1416/180;
        glVertex2f(0.0+0.05*cos(angle5),0.0+0.05*sin(angle5));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle4;
    for (int i=0;i<360;i++)
    {
        angle4=i*3.1416/180;
        glVertex2f(-0.05+0.05*cos(angle4),-0.05+0.05*sin(angle4));

    }
    glEnd();



      glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle3;
    for (int i=0;i<360;i++)
    {
        angle3=i*3.1416/180;
        glVertex2f(0.07+0.05*cos(angle3),0.0+0.05*sin(angle3));

    }
    glEnd();


       glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    float angle2;
    for (int i=0;i<360;i++)
    {
        angle2=i*3.1416/180;
        glVertex2f(0.045+0.05*cos(angle2),-0.05+0.05*sin(angle2));

    }
    glEnd();
    glPopMatrix();


     glDisable(GL_LIGHTING);


    //bird

    glLoadIdentity();
     glPushMatrix();
     glTranslatef(position5,0.0f, 0.0f);
     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle41;
    for (int i=0;i<360;i++)
    {
        angle41=i*3.1416/180;
        glVertex2f(0.8+0.04*cos(angle41),0.7+0.02*sin(angle41));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle42;
    for (int i=0;i<360;i++)
    {
        angle42=i*3.1416/180;
        glVertex2f(0.75+0.02*cos(angle42),0.71+0.02*sin(angle42));

    }
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(255.0, 255.0, 255.0);
    float angle43;
    for (int i=0;i<360;i++)
    {
        angle43=i*3.1416/180;
        glVertex2f(0.74+0.005*cos(angle43),0.71+0.005*sin(angle43));

    }
    glEnd();
    
    //wing

     glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 255.0, 255.0);
    glVertex2f(0.8f,0.75f);
    glVertex2f(0.79,0.71f);
    glVertex2f(0.785f,0.8f);
    glEnd();





    //lip
    glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 0.0, 0.0);
    glVertex2f(0.73f,0.72f);
    glVertex2f(0.69f,0.71f);
    glVertex2f(0.73f,0.70f);
    glEnd();



    //BIRD2

    glTranslatef(-0.1f,-0.1f, 0.0f);
     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle44;
    for (int i=0;i<360;i++)
    {
        angle44=i*3.1416/180;
        glVertex2f(0.8+0.04*cos(angle44),0.7+0.02*sin(angle44));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle45;
    for (int i=0;i<360;i++)
    {
        angle45=i*3.1416/180;
        glVertex2f(0.75+0.02*cos(angle45),0.71+0.02*sin(angle45));

    }
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(255.0, 255.0, 255.0);
    float angle46;
    for (int i=0;i<360;i++)
    {
        angle46=i*3.1416/180;
        glVertex2f(0.74+0.005*cos(angle46),0.71+0.005*sin(angle46));

    }
    glEnd();
    //wing

     glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 255.0, 255.0);
    glVertex2f(0.8f,0.75f);
    glVertex2f(0.79,0.71f);
    glVertex2f(0.785f,0.8f);
    glEnd();


    //lip
    glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 0.0, 0.0);
    glVertex2f(0.73f,0.72f);
    glVertex2f(0.69f,0.71f);
    glVertex2f(0.73f,0.70f);
    glEnd();

//BIRD3


    glTranslatef(-0.2f,0.1f, 0.0f);
     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle47;
    for (int i=0;i<360;i++)
    {
        angle47=i*3.1416/180;
        glVertex2f(0.8+0.04*cos(angle47),0.7+0.02*sin(angle47));

    }
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0.0, 0.0, 0.0);
    float angle48;
    for (int i=0;i<360;i++)
    {
        angle48=i*3.1416/180;
        glVertex2f(0.75+0.02*cos(angle48),0.71+0.02*sin(angle48));

    }
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(255.0, 255.0, 255.0);
    float angle49;
    for (int i=0;i<360;i++)
    {
        angle49=i*3.1416/180;
        glVertex2f(0.74+0.005*cos(angle49),0.71+0.005*sin(angle49));

    }
    glEnd();
    //wing

     glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 255.0, 255.0);
    glVertex2f(0.8f,0.75f);
    glVertex2f(0.79,0.71f);
    glVertex2f(0.785f,0.8f);
    glEnd();


    //lip
    glBegin(GL_TRIANGLES);
    glColor3ub(255.0, 0.0, 0.0);
    glVertex2f(0.73f,0.72f);
    glVertex2f(0.69f,0.71f);
    glVertex2f(0.73f,0.70f);
    glEnd();




glPopMatrix();


//sun

glLoadIdentity();
 glBegin(GL_POLYGON);
    glColor3ub(255.0f, 255.0f, 128.0f);
    float angle10;
    for (int i=0;i<360;i++)
    {
        angle10=i*3.1416/180;
        glVertex2f(0.0+0.12*cos(angle10),0.9+0.12*sin(angle10));

    }
    glEnd();

    glFlush();
}

//-------------------------------Start of endwindow()----------------------
void glutBitmapString();
void displayend()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,0.8,1.0);
    int i;
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(600,400,10);
    glutBitmapString("THANK YOU........!!");
    glFlush();
    glutSwapBuffers();

}
void myReshape();
void endKey();
void endwindow()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,768);
	glutCreateWindow("End");
	  // glutFullScreen();
	glLineWidth(2.0);
	glutDisplayFunc(displayend);
	//glutFullScreen();
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(myReshape);
	//glutKeyboardFunc(endkey);
	glutMainLoop();
}

//----------------------------End of endWindow()------------------	

void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {

case 's':
    speed = 0.0f;
    break;
case 'r':
    speed = 0.02f;
    break;

case 'd':
    glutDisplayFunc(day);
    glutPostRedisplay();
    break;

    case 'n':
    glutDisplayFunc(night);
    glutPostRedisplay();
    break;
case 'e':
	endwindow();
    break;
glutPostRedisplay();


    }
}


//-------------------------------Start of frontPage--------------
void glutBitmapString(const char *str)
{
	int i=0;
	while(str[i]!='\0')
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i++]);
}
GLfloat vertices [][3] = {{1150.0,550.0,-50.0}, {1250.0,550.0,-50.0}, {1250.0,650.0,-50.0}, {1150.0,650.0,-50.0}, {1150.0,550.0,50.0}, {1250.0,550.0,50.0}, {1250.0,650.0,50.0}, {1150.0,650.0,50.0}};
GLfloat colors [][3] = {{0.0,0.0,0.0}, {1.0,-1.0,-1.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};


void display1()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,0.8,1.0);
    int i;
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(300,700,10);
    glutBitmapString("VIVEKANANDA COLLEGE OF ENGINEERING AND TECHNOLOGY,PUTTUR");
    glRasterPos3f(370,650,10);
    glutBitmapString("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glRasterPos3f(450,600,10);
    glutBitmapString("SIMPLE VILLAGE TO A SMART CITY SCENARIO");
    glRasterPos3f(200,400,10);
    glutBitmapString("USN : 4VP20CS070");
    glRasterPos3f(200,350,10);
    glutBitmapString("USN : 4VP20CS109");
    glRasterPos3f(850,400,10);
    glutBitmapString("NAME : RAJASHREE");
    glRasterPos3f(850,350,10);
    glutBitmapString("NAME : YASHASWI MD");
    glRasterPos3f(200,200,10);
  //  glutBitmapString("");
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(615.0,100.0,10.0);
        glVertex3f(615.0,140.0,10.0);
        glVertex3f(710.0,140.0,10.0);
        glVertex3f(710.0,100.0,10.0);
    glEnd();
    glColor3f(0.82,0.82,0.82);
    glBegin(GL_QUADS);
        glVertex3f(615.0,100.0,9.0);
        glVertex3f(615.0,140.0,9.0);
        glVertex3f(710.0,140.0,9.0);
        glVertex3f(710.0,100.0,9.0);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(630,110,10.0);
    glutBitmapString("NEXT");
    glRasterPos3f(130,160,10.0);
    glutBitmapString("(1) First Press v for Village Scene");
    glRasterPos3f(130,130,10.0);
    glutBitmapString("(2) Then press d for City day Scene");
    glRasterPos3f(130,100,10.0);
    glutBitmapString("(3) Then press n for City night Scene");
    glRasterPos3f(130,70,10.0);
    glutBitmapString("(4) Then press e for End");
    glFlush();
    glutSwapBuffers();

    
}

//---------------------------End of Front page----------------------

//--------------------------start of nextPage()--------------------
void nextwindow()
{
    //glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("village"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    initGL();
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    init();
    //glutFullScreen();
    glutTimerFunc(250, update, 0);
    glutTimerFunc(500, update2, 0);
    glutTimerFunc(500, update1, 0);

    glutTimerFunc(200, update5, 0);
    glutTimerFunc(200, update6, 0);	
    
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();    
    
} 

//-----------------------End of nextpage()----------------------------
void mouse(int button, int state, int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
		
			nextwindow();
   			}
		break;
	
	default:
		break;
	}
}

void endkey(unsigned char key, int x, int y){
	switch(key)
	{
		case 'e':
			endwindow();
		break;
	}
}
    
void myReshape(int w,int h)
{
        width=w;height=h;
    	glViewport(0,0,w,h);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
        glOrtho(0.0,1367.0,0.0,767.0, -180.0,180.0);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(1.0,1.0,0.8,1.0);
        
}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,768);
	glutCreateWindow("Demo");
	  //glutFullScreen();
	glLineWidth(2.0);
	glutDisplayFunc(display1);
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
