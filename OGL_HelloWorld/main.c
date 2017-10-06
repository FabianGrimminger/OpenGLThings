#include <GL/glut.h>

int width = 640;
int height = 480;

void init(int argc, char** argv) {
	glutInit(&argc, argv);					// Initialisierung der GLUT Bibliothek
	glutInitDisplayMode(GLUT_SINGLE);		// Initialisierung des Single Buffer Modes
	glutInitWindowSize(2*width, height);		// Fenstergr��e in Pixel (Breite, Hoehe)
	glutInitWindowPosition(2*100, 100);		// Fensterposition in Pixel, ausgehend vom Ursprung des Window Systems
	glViewport(0, 0, width, height);
	glutCreateWindow("Hello world");		// Erstellen des Fensters
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	char *myText = "Hello World!";
	int j;

	
	glClearColor(0.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat myColor[3] = { 0.0,0.0,1.0 };
	glColor3fv(myColor);

	glBegin(GL_POLYGON);
	glVertex3f((width / 2), (height / 2) + (height / 4), 0.0);
	glVertex3f((width / 2) + (width / 4), (height / 2) - (height / 4), 0.0);
	glVertex3f((width / 2) - (width / 4), (height / 2) - (height / 4), 0.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i((width / 2) - (width / 4) + 10, (height / 2) - (height / 4) + 10);
	for (j = 0; j<strlen(myText); j++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, myText[j]);
	}

	glFlush();
}


int main(int argc, char** argv)
{
	init(argc, argv);
	glutDisplayFunc(display);				// Callback-Funktion f�r das Fenster
	glutMainLoop();							// Abgabe der Kontrolle an GLUT-Bibliothek
	return 0;
}

