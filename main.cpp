/*-----------------------------------------------------------
Main Program - Pool Game V3
-----------------------------------------------------------*/
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include "glm\glm.hpp"

#include "freeglut\include\GL\freeglut.h"
#include "colours.h"
#include "table.h"
#include "DrawPrimatives.h"
#include "keyboard.h"

/*-----------------------------------------------------------
Macros
-----------------------------------------------------------*/
#define	SIM_UPDATE_MS	(10)

//Create Table
table gTable;

void DoCamera(int ms)
{
	static const vec3 up(0.0,1.0,0.0);

	if(gCamRotate)
	{
		if(gCamL)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localL = up.Cross(camDir);
			vec3 inc = (localL* ((gCamRotSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir + inc;
		}
		if(gCamR)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = up.Cross(camDir);
			vec3 inc = (localR* ((gCamRotSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir - inc;
		}
		if(gCamU)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir + inc;
		}
		if(gCamD)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir - inc;
		}		
	}
	else
	{
		if(gCamL)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localL = up.Cross(camDir);
			vec3 inc = (localL* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamR)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 inc = (localR* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamU)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamD)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localDown = camDir.Cross(localR);
			vec3 inc = (localDown* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
	}

	if(gCamZin)
	{
		vec3 camDir = (gCamLookAt - gCamPos).Normalised();
		vec3 inc = (camDir* ((gCamMoveSpeed*ms)/1000.0) );
		gCamPos += inc;
		gCamLookAt += inc;
	}
	if(gCamZout)
	{
		vec3 camDir = (gCamLookAt - gCamPos).Normalised();
		vec3 inc = (camDir* ((gCamMoveSpeed*ms)/1000.0) );
		gCamPos -= inc;
		gCamLookAt -= inc;
	}
}


void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.4f, 0.4f, 0.0f);				// set default background colour
	glMaterialfv(GL_FRONT, GL_DIFFUSE, DARKMAGENTA);	// set default draw colour

	//set camera
	glLoadIdentity();
	gluLookAt(gCamPos(0),gCamPos(1),gCamPos(2),gCamLookAt(0),gCamLookAt(1),gCamLookAt(2),0.0f,1.0f,0.0f);

	//draw the ball
	glColor3f(1.0,1.0,1.0);
	for(int i=0;i<NUM_BALLS;i++)
	{
		glPushMatrix();
			glTranslatef(gTable.balls[i].position(0), (BALL_RADIUS / 2.0f), gTable.balls[i].position(1));

			if (i > 0 && i % 2 == 1) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, CRIMSON);
			}
			else if (i > 0 && i % 2 == 0) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, YELLOW);
			}

			if (i == 0) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, WHITE);
			}

			if (i == 9) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, BLACK);
			}

			glutSolidSphere(gTable.balls[i].radius, 32, 32);

		glPopMatrix();		
	}
	

	//draw the table
	for(int i=0;i<NUM_CUSHIONS;i++)
	{	
		glBegin(GL_LINE_LOOP);
		glVertex3f (gTable.cushions[i].vertices[0](0), 0.0, gTable.cushions[i].vertices[0](1));
		glVertex3f (gTable.cushions[i].vertices[0](0), 0.1, gTable.cushions[i].vertices[0](1));
		glVertex3f (gTable.cushions[i].vertices[1](0), 0.1, gTable.cushions[i].vertices[1](1));
		glVertex3f (gTable.cushions[i].vertices[1](0), 0.0, gTable.cushions[i].vertices[1](1));
		glEnd();
	}

	for(int i=0;i<gTable.parts.num;i++)
	{
		
		glPushMatrix();
		glTranslatef(gTable.parts.particles[i]->position(0),gTable.parts.particles[i]->position(1),gTable.parts.particles[i]->position(2));
		glutSolidSphere(0.002f,32,32);
		glPopMatrix();		
	}


	//draw the cue
	if(gDoCue)
	{
		glBegin(GL_LINES);
		float cuex = sin(gCueAngle) * gCuePower;
		float cuez = cos(gCueAngle) * gCuePower;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, BLACK);
		glVertex3f (gTable.balls[0].position(0), (BALL_RADIUS/2.0f), gTable.balls[0].position(1));
		glVertex3f ((gTable.balls[0].position(0)+cuex), (BALL_RADIUS/2.0f), (gTable.balls[0].position(1)+cuez));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, DARKMAGENTA);
		glEnd();
	}

	
	glFlush();
	glutSwapBuffers();
}

void ChangeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,0.2,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0,0.7,2.1, 0.0,0.0,0.0, 0.0f,1.0f,0.0f);
	gluLookAt(gCamPos(0),gCamPos(1),gCamPos(2),gCamLookAt(0),gCamLookAt(1),gCamLookAt(2),0.0f,1.0f,0.0f);
}

void InitLights(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat light_ambient[] = { 2.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}

void UpdateScene(int ms) 
{
	if(gTable.AnyBallsMoving()==false) gDoCue = true;
	else gDoCue = false;

	if(gDoCue)
	{
		if(gCueControl[0]) gCueAngle -= ((gCueAngleSpeed * ms)/1000);
		if(gCueControl[1]) gCueAngle += ((gCueAngleSpeed * ms)/1000);
		if (gCueAngle <0.0) gCueAngle += TWO_PI;
		if (gCueAngle >TWO_PI) gCueAngle -= TWO_PI;

		if(gCueControl[2]) gCuePower += ((gCuePowerSpeed * ms)/1000);
		if(gCueControl[3]) gCuePower -= ((gCuePowerSpeed * ms)/1000);
		if(gCuePower > gCuePowerMax) gCuePower = gCuePowerMax;
		if(gCuePower < gCuePowerMin) gCuePower = gCuePowerMin;
	}

	DoCamera(ms);

	gTable.Update(ms);

	glutTimerFunc(SIM_UPDATE_MS, UpdateScene, SIM_UPDATE_MS);
	glutPostRedisplay();
}

int _tmain(int argc, _TCHAR* argv[])
{
	gTable.SetupCushions();

	glutInit(&argc, ((char **)argv));
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,700);
	//glutFullScreen();
	glutCreateWindow("MSc Workshop : Pool Game");
	InitLights();
	glutDisplayFunc(RenderScene);
	glutTimerFunc(SIM_UPDATE_MS, UpdateScene, SIM_UPDATE_MS);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RenderScene);
	
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecKeyboardFunc);
	glutSpecialUpFunc(SpecKeyboardUpFunc);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
