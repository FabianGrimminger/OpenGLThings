#include <GL/glut.h>
#include <stdio.h>

int width = 640;
int height = 480;

float _angle = 0.0;
float _cameraangle = 30.0;

void display(void)
{	
	glMatrixMode(GL_MODELVIEW); // Den richtigen Stack aktivieren
	glLoadIdentity();              // Die Matrix zurücksetzen

	glTranslatef(0, 0, -3.5);
	//glRotatef(-20, 1, 0, 0);
	glRotatef(_angle, 0, 1, 0);

	glClearColor(0, 0, 0,0.0);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT); //Bildbuffer löschen							  

	glBegin(GL_QUADS);

	glColor3f(1, 0, 0); //türkis?
	glVertex3f(-1, -1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(1, -1, -1);
	glColor3f(0,1, 0);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(-1, -1, 1);

	glEnd();

	glBegin(GL_TRIANGLES);
	
	glVertex3f(-1, -1, 1);
	glColor3f(0, 1, 0);   //  grün
	glVertex3f(0.0, 1.0, 0.0);	
	glVertex3f(1, -1, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 0); //gelb
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1, -1, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 0);   //  rot
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);	
	glEnd();

	glBegin(GL_TRIANGLES);
	
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1); //blau
	glVertex3f(0.0, 1.0, 0.0);	
	glVertex3f(-1, -1, 1);	
	glEnd(); 

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 2.0f;
	if (_angle > 360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

//wird am anfang einmal durchlaufen
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
	glFrustum(-1.6, 1.6, -1.2, 1.2, 1.5, 6.5);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("rotate");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}