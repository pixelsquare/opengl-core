/*
 * opengl_core.c
 *
 *  Created on: Mar 6, 2011
 *      Author: ryan
 */

#include <glut.h>

// Uncomment this line and comment the previous line if you are using freeglut.
//#include <freeglut.h>

/*

Hybrid OpenGL engine from Redbook and NeHE productions

Author: Write your name here. :)

Credits:Ryan Baclit
	ryan.baclit@gmail.com

To compile this source code in Linux or Mac OS X, use the command

gcc opengl_core.c -o opengl_core -lglut -lGL -lGLU -I/usr/include/GL

And use

./opengl_core

To run your compiled program.

*/

/* ascii code for the escape key */

#define ESCAPE 27

/* The number of our GLUT window */

int windowHandle;

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */

void resizeScene(int width, int height)
{
	// Prevent A Divide By Zero If The Window Is Too Small

	if(height == 0)
	{
		height=1;
	}

	// Reset The Current Viewport And Perspective Transformation

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}


void showScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();



	//	Write your 3D stuff below this line! :)

 

	/*

	don't wait!
	start processing buffered OpenGL routines

	*/

	glFlush();

	// Need to swap buffer to show latest render

	glutSwapBuffers();
}

/*

	Prepare everything for viewing

*/

void initMyComponents(int width, int height)
{
	GLfloat aspectRatio;

	//	select clearing (background) color

	glClearColor(0.0, 0.0, 0.0, 0.0);

	//	initialize viewing values

	//	Clear both screen and depth buffer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	// Reset The Projection Matrix

	glLoadIdentity();

	// No need for this advanced clipping function from the red book.

	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	// Calculate The Aspect Ratio Of The Window

	aspectRatio = (GLfloat) width / (GLfloat) height;
	gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void keyPressed(unsigned char key, int x, int y)
{
    /* avoid thrashing this procedure. Uncomment the line if using gcc */

    //usleep(100);

    /* If escape is pressed, kill everything. */

    if (key == ESCAPE)
    {
		/* shut down our window */

		glutDestroyWindow(windowHandle);

		/* exit the program...normal termination. */

		exit(0);
    }
}

/*

	Declare initial window size, position, and display mode
	(single buffer and RGBA). Open window with "hello"
	in its title bar. Call initialization routines.
	Register callback function to display graphics.
	Enter main loop and process events.

*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// Do double-buffer for smoother rendering and animation.

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	//glutInitWindowPosition(100, 100);
	glutInitWindowPosition(0, 0);
	windowHandle = glutCreateWindow("Your OpenGL Program");

	initMyComponents(640, 480);

	/* Register the function called when the keyboard is pressed. */

	glutKeyboardFunc(&keyPressed);

	//	Show in full screen. Can be used later by uncommenting.

	//glutFullScreen();

	// Draw the scenery

	glutDisplayFunc(&showScene);
	glutReshapeFunc(&resizeScene);
	glutIdleFunc(&showScene);
	glutMainLoop();

	return 0;
}

