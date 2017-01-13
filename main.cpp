/*-----------------------------------------------------------
Main Program - Pool Game V3
-----------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include "glm\glm.hpp"

#include "freeglut\include\GL\freeglut.h"
#include "colours.h"
#include "table.h"
#include "ruleset.h"
#include "DrawPrimatives.h"
#include "keyboard.h"
#include "camera.h"


/*-----------------------------------------------------------
Macros
-----------------------------------------------------------*/
const int SIM_UPDATE_MS = 10;

//Create Global Objects
table gTable;
ruleset gGame;

void RenderScene(void);
void ChangeWindowSize(int width, int height);
void InitLights(void);
void UpdateScene(int ms);

int main(int argc, char* argv[]){

	// Setup game and table
	gTable.SetupCushions();
	gTable.SetupPockets();
	gTable.SetupPlayers();

	// Set up GLUT Window
	glutInit(&argc, ((char **)argv));
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,700);
	glutCreateWindow("Marc Chapman 054888139 - Assessment 1: Pool Game");

	// Set up scene and render
	InitLights();
	glutDisplayFunc(RenderScene);
	glutTimerFunc(SIM_UPDATE_MS, UpdateScene, SIM_UPDATE_MS);
	glutReshapeFunc(ChangeWindowSize);
	glutIdleFunc(RenderScene);
	glEnable(GL_DEPTH_TEST);
	
	// set up keyboard monitoring
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecKeyboardFunc);
	glutSpecialUpFunc(SpecKeyboardUpFunc);

	// What it says on the tin
	glutMainLoop();

}
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.4f, 0.4f, 0.0f);				// set default background colour
	glMaterialfv(GL_FRONT, GL_DIFFUSE, DARKMAGENTA);	// set default draw colour

	//set camera
	glLoadIdentity();
	gluLookAt(gCamPos(0),gCamPos(1),gCamPos(2),gCamLookAt(0),gCamLookAt(1),gCamLookAt(2),0.0f,1.0f,0.0f);

	//draw the ball
	for(int i=0;i<NUM_BALLS;i++)	{
		glPushMatrix();
			glTranslatef(gTable.balls[i].position(0), (BALL_RADIUS / 2.0f), gTable.balls[i].position(1));

			if (gTable.balls[i].set == 0) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, WHITE);
			}
			if (gTable.balls[i].set == 1) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, CRIMSON);
			}
			if (gTable.balls[i].set == 2) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, YELLOW);
			}
			if (gTable.balls[i].set == 3) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, BLACK);
			}
			
			glutSolidSphere(gTable.balls[i].radius, 32, 32);

		glPopMatrix();		
	}	

	//draw the table
	for(int i=0;i<NUM_CUSHIONS;i++)	{	
		glBegin(GL_LINE_LOOP);
		glVertex3f (gTable.cushions[i].vertices[0](0), 0.0, gTable.cushions[i].vertices[0](1));
		glVertex3f (gTable.cushions[i].vertices[0](0), 0.1, gTable.cushions[i].vertices[0](1));
		glVertex3f (gTable.cushions[i].vertices[1](0), 0.1, gTable.cushions[i].vertices[1](1));
		glVertex3f (gTable.cushions[i].vertices[1](0), 0.0, gTable.cushions[i].vertices[1](1));
		glEnd();
	}

	// Draw pockets
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BLUE);
	for (int i = 0; i < NUM_POCKETS; i++) {
		drawCircle(gTable.pocket[i].position(0), 0.0f, gTable.pocket[i].position(1), gTable.pocket[i].drawRadius, 32);
		drawCircle(gTable.pocket[i].position(0), 0.0f, gTable.pocket[i].position(1), gTable.pocket[i].colRadius, 32);
	}

	//draw the cue
	if(gDoCue)	{
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

void ChangeWindowSize(int width, int height) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (height == 0) height = 1;
	float ratio = 1.0* width / height;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);

	// Set the correct perspective.
	gluPerspective(45,ratio,0.2,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0,0.7,2.1, 0.0,0.0,0.0, 0.0f,1.0f,0.0f);
	gluLookAt(gCamPos(0),gCamPos(1),gCamPos(2),gCamLookAt(0),gCamLookAt(1),gCamLookAt(2),0.0f,1.0f,0.0f);
}

void InitLights(void){
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 80.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glShadeModel (GL_SMOOTH);
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat light_ambient[] = { .5, .5, .5, 1 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}

void UpdateScene(int ms) {
	if(gTable.AnyBallsMoving()==false) gDoCue = true;
	else gDoCue = false;

	if(gDoCue)	{
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


