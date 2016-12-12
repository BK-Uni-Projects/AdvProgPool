#pragma once

const float PI		= 3.1416;
const float TWO_PI	= 6.2832f;

/**
* Function that draws a circle using a line loop.
*
* Params:
*	x - the x position of the circles center.
*	x - the x position of the circles center.
*	radius - circle radius
*	segments - circle segments (default 8)
*/
inline void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, int segments) {
	if (segments == 0) segments = 100;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= segments; i++) {
		glVertex3f(x + (radius * cos(i *  TWO_PI / segments)), 0.0f, z + (radius * sin(i * TWO_PI / segments)));
	}
	glEnd();
}

/**
* Function that draws a quad using a line loop.
*
* Params:
*	x - the x position of the circles center.
*	x - the x position of the circles center.
*	radius - circle radius
*	segments - circle segments (default 8)
*/
inline void drawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	// Code here
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
	glEnd();
}


