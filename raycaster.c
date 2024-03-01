#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float px, py; // Player position

void drawPlayer()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
}

int mapX = 8 , mapY = 8 , mapS = 64;
int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
	
};

void drawMap2D() {
	int x0, y0 ,x ,y;
  for (y = 0; y < mapY; y++) {
    for (x = 0; x < mapX; x++) {
      if (map[y*mapX+x] == 1) {glColor3f(1, 1, 1);} 
	  else {
        glColor3f(0, 0, 0);
      }

	  x0 = x*mapS; y0 = y*mapS;
      glBegin(GL_QUADS);
        glVertex2f(x0 +1 , y0+1);  
        glVertex2f(x0 +1, y0+mapS-1);  
        glVertex2f(x0+mapS-1 , y0+mapS-1);  
        glVertex2f(x0+mapS-1, y0+1); 
      glEnd();
    }
  }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawMap2D();
    drawPlayer();
    glutSwapBuffers();
}

void buttons(unsigned char key, int x, int y)
{
    if (key == 'a'){px -= 5;}
    if (key == 'd'){px += 5;}
    if (key == 'w'){py -= 5;}
    if (key == 's'){py += 5;}
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 1024, 512, 0);
    px = 300;
    py = 300;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("RayCaster -Engine");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}

