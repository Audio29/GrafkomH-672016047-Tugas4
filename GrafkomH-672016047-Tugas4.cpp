#include <iostream>
#include <GL/freeglut.h>

float xpos = 0.0;
float ypos = 0.0;
float zpos = -1.0 ;
float tpos = 0.0;
float delta = 0.025f;
float apos = 0.035;
bool X = true;
int state = 1;



void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex2f(-0.05 + xpos, 0.05);
	glVertex2f(-0.05 + xpos, -0.05 );
	glVertex2f(0.05 + xpos, -0.05 );
	glVertex2f(0.05 + xpos, 0.05 );
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-0.05, 0.05 + ypos);
	glVertex2f(-0.05, -0.05 + ypos);
	glVertex2f(0.05, -0.05 + ypos);
	glVertex2f(0.05, 0.05 + ypos);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-0.05 + zpos, 0.05 + tpos);
	glVertex2f(-0.05 + zpos, -0.05 + tpos);
	glVertex2f(0.05 + zpos, -0.05 + tpos);
	glVertex2f(0.05 + zpos, 0.05 + tpos);
	glEnd();
	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);

		if (xpos < 1.0 && X)
			xpos += delta;
		else
			X = false;
		if (xpos > -1.0  && !X)
			xpos -= delta;
		else
			X = true;
		if (ypos < 1.0  && X)
			ypos += delta;
		else
			X = false;
		if (ypos > -1.0  && !X)
			ypos -= delta;
		else
			X = true;
		switch (state)
	case 1:
		{

			if (zpos < 0.0)
				zpos += apos;
			if (tpos > -1.0 )
				tpos -= apos;
			else
				state = 2;
			break;

	case 2:

		if (tpos < 0.0)
			tpos += apos;
		if (zpos < 1.0 )
			zpos += apos;

		else
			state = 3;
		break;

	case 3:
		if (tpos < 1.0 )
			tpos += apos;
		if (zpos > 0.0)
			zpos -= apos;

		else state = 4;
		break;

	case 4:
		if (tpos > 0.0)
			tpos -= apos;
		if (zpos > -1.0 )
			zpos -= apos;
		else
			state = 1;
		break;

		}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("AUDIX");
	glutDisplayFunc(display);
	myinit();
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}
