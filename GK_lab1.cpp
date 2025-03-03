/*
 * Laboratorium Grafiki Komputerowej
 * Pierwszy program wykorzystujący OpenGL'a
 */

 /* System */
#include<stdio.h>
#include<stdlib.h>

/* Biblioteka GLUT */
#include <GL\freeglut.h>

/* Deklaracje funkcji narzędziowych */

/* Funkcja do rysowania */
void DrawScene(void);

void Dywan(void);

/* Funkcja do inicjacji OpenGLa */
void InitOpenGL(void);

/* Funkcja wywoływana w momentach zmiany rozmiarów okna */
void ReshapeWindow(int width, int height);

/* Deklaracja globalnych zmiennych */

/* Globalny identyfikator głównego okna programu */
int mainWindow;

/* Funkcja main */
int main(int argc, char** argv)
{
	// Inicjujemy bibliotekę GLUT
	glutInit(&argc, argv);
	// Inicjujemy: format koloru, jeden bufor ramki
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	// Ustawiamy początkowe wymiary okna
	glutInitWindowSize(800, 800);
	// Ustawiamy pozycję okna - lewy górny naroznik
	glutInitWindowPosition(150, 150);
	// Tworzymy główne okno programu
	mainWindow = glutCreateWindow("Pierwsze Laboratorium");

	// Sprawdzamy powodzenie operacji
	if (mainWindow == 0) {
		puts("Nie mozna stworzyc okna!!!\nWyjscie z programu.\n");
		exit(-1);
	}

	// Czynimy aktywnym okno główne programu
	glutSetWindow(mainWindow);

	// Tutaj rejestrujemy funkcje narzędziowe - tzw. callbacks
	glutDisplayFunc(Dywan);
	glutReshapeFunc(ReshapeWindow);

	// ustawienia początkowe
	InitOpenGL();

	// Wejście do pętli programu
	glutMainLoop();

	return(0);
}

/* W tej funkcji określamy to co ma byc narysowane na ekranie.
 * Jest wywoływana zawsze wtedy, gdy trzeba przerysować ekran - bufor ramki.
 */
void DrawScene(void)
{
	// Czyścimy okno aktualnym (domyślnym) kolorem
	glClear(GL_COLOR_BUFFER_BIT);
	// Ustawiamy grubość linii
	glLineWidth(10.0f);
	// Tworzenie prymitywów graficznych zawsze ograniczamy funkcjami glBegin i glEnd
	glBegin(GL_TRIANGLES);
	// Ustawiamy bieżący kolor rysowania na czerwony
	glColor3f(1.0f, 0.0f, 0.0f);
	// Dwa końce pierwszego odcinka
	glVertex2f(-50.0f, 0.0f);
	//glVertex2f(0.0f, 50.0f);
	// Zmieniamy kolor rysowania na zielony
	glColor3f(0.0f, 1.0f, 0.0f);
	// Dwa końce drugiego odcinka
	glVertex2f(0.0f, 50.0f);
	//glVertex2f(50.0f, 0.0f);
	// Zmieniamy kolor rysowania na niebieski
	glColor3f(0.0f, 0.0f, 1.0f);
	// Dwa końce drugiego odcinka
	glVertex2f(50.0f, 0.0f);
	//glVertex2f(-50.0f, 0.0f);
	glEnd();
	// Komenda wykonania poleceń rysujących
	glFlush();

}

void Dywan(void) {
	// Czyścimy okno aktualnym (domyślnym) kolorem
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(5.0f, 2.0f, 0.0f);
	glVertex2f(-50.0f, 50.0f);
	glVertex2f(50.0f, 50.0f);
	glVertex2f(50.0f, -50.0f);
	glVertex2f(-50.0f, -50.0f);
	glEnd();
	// Komenda wykonania poleceń rysujących
	glFlush();
}


/* Ta funkcja służy do wstępnej konfiguracji OpenGLa.
 * Zanim coś narysujemy musimy wywołać tę funkcję.
 */
void InitOpenGL(void)
{
	// Usawiamy domyślny, czarny kolor tła okna - bufor ramki malujemy na czarno
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/* Tę funkcję wywołuje system w momencie gdy uytkownik zmieni myszą
 * rozmiar głownego okna. jej zadaniem jest zachowanie propocji wymiarów
 * rysowanych obiektów niezależnie od wymiarów okna.
 */
void ReshapeWindow(int width, int height)
{
	int aspectRatio; // = width / height

	// Na wypadek dzielenia przez 0
	if (height == 0) height = 1;

	// Wyliczamy współczynnik proporcji
	aspectRatio = width / height;

	// Ustawiamy wielkości okna okna urządzenia w zakresie
	// od 0,0 do wysokość, szerokość
	glViewport(0, 0, width, height);

	// Ustawiamy układ współrzędnych obserwatora
	glMatrixMode(GL_PROJECTION);

	// Resetujemy macierz projkecji 
	glLoadIdentity();

	// Korekta  
	if (width <= height)
		glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	// Ustawiamy macierz modelu
	glMatrixMode(GL_MODELVIEW);

	// Resetujemy macierz modelu
	glLoadIdentity();

}