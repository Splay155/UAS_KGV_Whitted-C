#include <iostream> 
#include <glut.h>
#include <stdlib.h>
#include <math.h>
float xp = 0, yp = 0, r = 10, n = 1000, a, x, y;
int j, k, l, m, t, o = 0;
bool done = false;

void write(float x, float y, float z, void* font, const char* string)
{
	glColor3f(1, 1, 1);
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void init() {
	glClearColor(0.45, 0.8, 10, 0.0); //untuk memberi warna dasar pada window
	gluOrtho2D(0, 650, 0, 440);//besarnya range sumbu x dan y
}

void lingkaran() { //fungsi lingkaran
	glBegin(GL_POLYGON);
	a = 6.28 / n;
	for (int i = 0; i < n; i++) {
		x = xp + r * cos(i * a);
		y = yp + r * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void latar()
{
	glBegin(GL_POLYGON); //latar
	glColor3ub(135, 206, 250);
	glVertex2f(0, 500);
	glColor3ub(135, 206, 250);
	glVertex2f(650, 500);
	glColor3ub(253, 154, 115);
	glVertex2f(650, 200);
	glColor3ub(253, 154, 115);
	glVertex2f(0, 200);
	glEnd();
}

void gunung1() {
	glBegin(GL_POLYGON); //gunung1
	glColor3ub(20, 91, 12);
	glVertex2f(0, 200);
	glColor3ub(93, 175, 84);
	glVertex2f(150, 350);
	glColor3ub(93, 175, 84);
	glVertex2f(300, 200);
	glEnd();
}

void gunung() {
	glBegin(GL_POLYGON); //gunung
	glColor3ub(5, 44, 11);
	glVertex2f(125, 200);
	glColor3ub(20, 91, 12);
	glVertex2f(325, 400);
	glColor3ub(73, 132, 81);
	glVertex2f(500, 200);
	glEnd();
}

void tanah() {
	glBegin(GL_POLYGON);//rumput
	glColor3ub(154, 205, 50);
	glVertex2f(0, 200);
	glColor3ub(107, 142, 35);
	glVertex2f(650, 200);
	glColor3ub(173, 255, 47);
	glVertex2f(650, 0);
	glColor3ub(154, 205, 50);
	glVertex2f(0, 0);
	glEnd();
}

void jalan() {
	glBegin(GL_POLYGON);//jalan
	glColor3ub(0, 0, 0);
	glVertex2f(0, 100);
	glVertex2f(650, 100);
	glVertex2f(650, 40);
	glVertex2f(0, 40);
	glEnd();

	glLineWidth(5); //Mengatur tebal garis
	glBegin(GL_LINES);//garis
	glColor3ub(169, 169, 169);
	glVertex2f(0, 100);
	glVertex2f(650, 100);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);//garis
	glColor3ub(169, 169, 169);
	glVertex2f(650, 40);
	glVertex2f(0, 40);
	glEnd();
}

void garis_jalan() {
	glLineWidth(5);
	glBegin(GL_LINES);//garis_jalan
	glColor3ub(225, 255, 255);
	glVertex2f(50, 70);
	glVertex2f(100, 70);
	glEnd();
}

void danau() {
	glBegin(GL_POLYGON);//danau
	glColor3ub(135, 206, 250);
	glVertex2f(0, 125);
	glColor3ub(0, 255, 255);
	glVertex2f(0, 200);
	glColor3ub(0, 191, 255);
	glVertex2f(650, 200);
	glColor3ub(135, 206, 250);
	glVertex2f(650, 125);
	glEnd();
}

void mobil() {
	glBegin(GL_POLYGON);//badan_mobil
	glColor3ub(255, 0, 0);
	glVertex2f(60, 75);
	glVertex2f(120, 75);
	glVertex2f(140, 70);
	glVertex2f(140, 55);
	glVertex2f(120, 55);
	glVertex2f(50, 55);
	glEnd();

	glBegin(GL_POLYGON);//atap_mobil
	glColor3ub(174, 48, 10);
	glVertex2f(70, 75);
	glVertex2f(77, 90);
	glVertex2f(108, 90);
	glVertex2f(115, 75);
	glEnd();

	glBegin(GL_POLYGON);//jendela_mobil
	glColor3ub(202, 229, 29);
	glVertex2f(78, 88);
	glVertex2f(88, 88);
	glVertex2f(88, 77);
	glVertex2f(73, 77);
	glEnd();

	glBegin(GL_POLYGON);//jendela_mobil
	glColor3ub(255, 255, 255);
	glVertex2f(90, 88);
	glVertex2f(107, 88);
	glVertex2f(112, 77);
	glVertex2f(90, 77);
	glEnd();

	glPushMatrix();//ban_mobil
	glTranslatef(70, 55, 0);
	glColor3ub(105, 105, 105);
	lingkaran();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(120, 55, 0); //untuk memindahkan objek 
	glColor3ub(105, 105, 105);
	lingkaran();
	glPopMatrix();

}
void perahu2() {
	glBegin(GL_POLYGON);//badan_perahu2
	glColor3ub(25, 25, 112);
	glVertex2f(55, 170);
	glVertex2f(185, 170);
	glVertex2f(170, 150);
	glVertex2f(70, 150);
	glEnd();

	glBegin(GL_POLYGON);//atap_perahu
	glColor3ub(176, 196, 222);
	glVertex2f(75, 170);
	glVertex2f(80, 185);
	glVertex2f(145, 185);
	glVertex2f(165, 170);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);//tiang_perahu
	glColor3ub(255, 255, 255);
	glVertex2f(65, 170);
	glVertex2f(65, 210);
	glEnd();

	glBegin(GL_POLYGON);//bendera_merah
	glColor3ub(255, 0, 0);
	glVertex2f(65, 210);
	glVertex2f(90, 210);
	glVertex2f(90, 200);
	glVertex2f(65, 200);
	glEnd();

	glBegin(GL_POLYGON);//bendera_putih
	glColor3ub(255, 255, 255);
	glVertex2f(65, 200);
	glVertex2f(90, 200);
	glVertex2f(90, 190);
	glVertex2f(65, 190);
	glEnd();
}

void awan()
{
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef(25, 380, 0);
	glScalef(2, 2, 0);//mengubah ukuran objek
	lingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 390, 0);
	glScalef(3, 3, 0);
	lingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(75, 380, 0);
	glScalef(2, 2, 0);
	lingkaran();
	glPopMatrix();
}


void specialKey(int key, int x, int y)//fungsi specialkey
{
	switch (key)
	{
	case GLUT_KEY_UP:
		m += 5;
		break;
	case GLUT_KEY_LEFT:
		l -= 5;
		break;
	case GLUT_KEY_DOWN:
		m -= 5;
		break;
	case GLUT_KEY_RIGHT:
		l += 5;
		break;
	}

	glutPostRedisplay();
}

void mouse(int button, int state, int xmouse, int ymouse) { //fungsi mouse untuk menggerakkan mobil
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		j += 10;
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		j -= 10;
	if (j > 600) done = true;
	glutPostRedisplay();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(1, 92, 0);
	glColor3ub(105, 105, 105);
	lingkaran();
	glPopMatrix();

	latar();
	awan();
	glPushMatrix();
	glTranslatef(175, 0, 0);
	awan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(450, 0, 0);
	awan();
	glPopMatrix();

	gunung();
	gunung1();
	glPushMatrix();
	glTranslatef(400, 0, 0);
	gunung1();
	glPopMatrix();

	tanah();
	jalan();
	for (float i = 0; i < 650; i += 100) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		garis_jalan();
		glPopMatrix();
	}
	danau();

	glPushMatrix();
	glTranslatef(l, m, 0);
	perahu2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(j, k, 0);
	mobil();
	glPopMatrix();

	glPushMatrix();//mengembalikan titik tengah posisi koordinat
	glColor3ub(255, 255, 0);
	glTranslatef(600, 400, 0);
	glScalef(3, 3, 0);
	lingkaran();
	glPopMatrix();// penutup dari glPushMatrix();

	if (done) write(0, 20.0f, 0, GLUT_BITMAP_HELVETICA_18, "Hacking complete, press ESC to exit");
	glutSwapBuffers();
}

int main()
{
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10); //menentukan posisi layer
	glutInitWindowSize(1200, 680);//ukuran window program
	glutCreateWindow("UAS KGV"); //nama program
	init();
	glutIdleFunc(display);
	glutDisplayFunc(display);//memanggil fungsi lain 
	glutSpecialFunc(specialKey);//memanggil fungsi specialKey
	glutMouseFunc(mouse);//memanggil fungsi mouse
	glutMainLoop();//fungsi untuk perulangan
}