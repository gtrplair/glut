//triangulo rotacionando
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <GL/gl.h>

float angulo = 0.0f;

void renderizacao(void)
{
//limpa tela e exibe buffer
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//redefini transformação
glLoadIdentity();
//definindo camera
gluLookAt(0.0f,0.0f,10.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
//rotacionar camera
glRotated(angulo,0.0f,1.0f,0.0f);
//desenho
glBegin(GL_TRIANGLES);
glVertex3f(-2.0f, -2.0f, 0.0f);
glVertex3f(2.0, 0.0, 0.0);
glVertex3f(0.0, 2.0, 0.0);
glEnd();
angulo += 0.1f;
//faz com que os buffers frontais e traseiros alterem
glutSwapBuffers();
}
void tamJanela(int w, int h){
if(h==0){
h=1;}
//Matriz de projecao
glMatrixMode(GL_PROJECTION);
//Reseta a matriz
glLoadIdentity();
//viewport para janela inteira
glViewport(0,0,w,h);
//perspectiva de tela
gluPerspective(45,h/w,1,1000);
//modelo de visao
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
//inicia o glut
glutInit(&argc,argv);
//modo de exibição
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//define numero de pixel da tela
glutInitWindowPosition(800,800);
//tamanho da janela
glutInitWindowSize (600,600);
//nome da janela
glutCreateWindow("Resta-1");
//renderiza o retorno da charada
glutDisplayFunc(renderizacao);
//funcao para cuidar quando a janela redimensiona
glutReshapeFunc(tamJanela);
//quando a renderizacao tiver ociosa
glutIdleFunc(renderizacao);
//loop do evento
glutMainLoop();
return 0;
}
