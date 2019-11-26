`//g++ -o main main.cpp -lglut -lGLU -lGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>
void display()
{
//sobrepoẽ a matriz toda hora
glLoadIdentity();
//cor da janela
glClearColor(1, 1, 1, 1);
//cor do display
glColor3f(1,0.7,0.5);
//limpar tela
glClear(GL_COLOR_BUFFER_BIT);
//todo objeto
glBegin(GL_TRIANGLES);
glVertex2f(-1,0);
glVertex2f(1, 0);
glVertex2f(0, 1);
