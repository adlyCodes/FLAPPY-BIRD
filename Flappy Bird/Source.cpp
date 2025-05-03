#include <iostream>
#include <conio.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <mmsystem.h>
#include <string>


#include <windows.h>

using namespace std;

GLfloat x_position = -0.85f; // initial (startig) x position of the bird
GLfloat y_position = 0.0f; // initial (starting) y position of the bird
GLfloat bottomOfScreen = -2.0f;
GLfloat x_positionrec = 0.0f;// begin 0.5(matshelsh deh)  end(-1.6)
GLfloat x_positionrec2 = 0.0f;//begin 0.1(matshelsh deh)  end(-2)
GLfloat x_positionrec3 = 0.0f;//-0.3 begin    end -2.4
GLfloat x_positionrec4 = 0.0f;//-0.7 begin     end -2.8
int timerActive = 1;
const int numSegments = 50;
int i = 0; // Counter to count the order (number) of the most recent opened window
int a = 1; // Arrow counter in Home screen
int s = 1; // Arrow counter in Start screen
int t = 0; // Counter for timerUp function (to smooth the movement of the bird)
int score = 0; // Score counter variable

void SetConsoleCursorPosition(int x, int y);
void SetConsoleColor(int color);
void CenterTextInConsole(const string& text);

void displayWelcome();
void displayHome();
void drawColumn();
void displayStart();
void drawBox();
void drawSmallCloud();
void displaySceneOne();
void displaySceneTwo();
void displayInstructions();
void displayCredits();
void displayGameOver();
void displayGameOverS();

void keyboardHome(unsigned char key, int x, int y);
void keyboardWelcome(unsigned char key, int x, int y);
void keyboardStart(unsigned char key, int x, int y);
void keyboardInstructions(unsigned char key, int x, int y);
void keyboardCredits(unsigned char key, int x, int y);
void displayText(float, float, float, float, float, int, const char*);
void drawCircle(float cx, float cy, float r, int num_segments);
void drawCloud();
void drawBird();
void drawBirds();

void drawFilledHalfCircle();
void drawFilledHalfCircleS();
void drawGAMEOVER();
void drawGAMEOVERs();
void rectext();
void rec();
void rec2();
void rec3();
void rec4();
void recs();
void recs2();
void recs3();
void recs4();
void timerrec(int value);
void timerrec2(int value);
void timerrecs(int value);
void timerrecs2(int value);
void timerrecs3(int value);
void timerrecs4(int value);



void play_music(const char* filename) {
    PlaySound(L"gameofthrones.wav", NULL, ASYNC_MODE_COMPATIBILITY);
}

void timerUp(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        y_position += 0.05;
        t++;

        // Redraw the scene
        glutPostRedisplay();

        if (t <= 5)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerUp, 0);
        }
    }
}

void timerGravity(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        y_position -= 0.02;

        // Redraw the scene
        glutPostRedisplay();

        // Set the timer for the next iteration after 50 milliseconds
        glutTimerFunc(50, timerGravity, 0);
    }
    else
    {
        y_position = 0.0f;
        x_positionrec = 0.0f;
        x_positionrec2 = 0.0f;
        x_positionrec3 = 0.0f;
        x_positionrec4 = 0.0f;
    }
}


void timerrec(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec > -1.54 && x_positionrec < -1.14) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
            else if (y_position >= 0.5) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec > -1.6)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrec, 0);
        }
        else if (x_positionrec <= -1.6) {
            x_positionrec = 0.5;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrec, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void timerrec2(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec2 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec2 > -1.94 && x_positionrec2 < -1.54) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.6) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
            else if (y_position >= 0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec2 > -2)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrec2, 0);
        }
        else if (x_positionrec2 <= -2) {
            x_positionrec2 = 0.1;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrec2, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void timerrec3(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec3 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec3 > -2.34 && x_positionrec3 < -1.94) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.1) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
            else if (y_position >= 0.7) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec3 > -2.4)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrec3, 0);
        }
        else if (x_positionrec3 <= -2.4) {
            x_positionrec3 = -0.3;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrec3, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}

void timerrec4(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec4 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec4 > -2.74 && x_positionrec4 < -2.34) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
            else if (y_position >= 0.5) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOver);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec4 > -2.8)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrec4, 0);
        }
        else if (x_positionrec4 <= -2.8) {
            x_positionrec4 = -0.7;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrec4, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void timerrecs(int value)
{

    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec > -1.54 && x_positionrec < -1.14) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
            else if (y_position >= 0.5) {

                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec > -1.6)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrecs, 0);
        }
        else if (x_positionrec <= -1.6) {
            x_positionrec = 0.5;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrecs, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void timerrecs2(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec2 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec2 > -1.94 && x_positionrec2 < -1.54) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.6) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();

                glutDisplayFunc(displayGameOverS);
            }
            else if (y_position >= 0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec2 > -2)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrecs2, 0);
        }
        else if (x_positionrec2 <= -2) {
            x_positionrec2 = 0.1;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrecs2, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void timerrecs3(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec3 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec3 > -2.34 && x_positionrec3 < -1.94) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.1) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
            else if (y_position >= 0.7) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec3 > -2.4)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrecs3, 0);
        }
        else if (x_positionrec3 <= -2.4) {
            x_positionrec3 = -0.3;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrecs3, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}

void timerrecs4(int value)
{
    if (timerActive) {
        // Update the Y position of the bird
        x_positionrec4 -= 0.005;
        //x_positionrec2 -= 0.005;
        if (x_positionrec4 > -2.74 && x_positionrec4 < -2.34) {//-1.14 first bird    -1.54 end bird
            if (y_position <= -0.3) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
            else if (y_position >= 0.5) {
                i++;
                timerActive = 0;
                glutDestroyWindow(i); // Closes the most recent opened window
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutCreateWindow("Flappy Bird: Home");
                glutFullScreen();
                glutDisplayFunc(displayGameOverS);
            }
        }
        // Redraw the scene
        glutPostRedisplay();

        if (x_positionrec4 > -2.8)
        {
            // Set the timer for the next iteration after 10 milliseconds (0.01 seconds)
            glutTimerFunc(10, timerrecs4, 0);
        }
        else if (x_positionrec4 <= -2.8) {
            x_positionrec4 = -0.7;
            score++;
            printf("Score: %d\n", score);
            //x_positionrec2 =0.75;
            glutTimerFunc(0, timerrecs4, 0);
            //glutTimerFunc(100, timerrec, 0);

        }
    }
}
void drawBirds()
{
    glPushMatrix();
    glTranslatef(x_position, y_position, 0.0);

    // Legs
    glBegin(GL_LINES); // Begin drawing lines
    glColor3f(1, 1, 1); // Set color to white (RGB: 1, 1, 1)
    glVertex2f(-0.02, -0.05); // First endpoint of the line (x, y)
    glVertex2f(-0.02, -0.1); // Second endpoint of the line (x, y)
    glEnd(); // End drawing lines

    // Body
    glColor3f(1.0, 0.0, 0.0); // Yellowish color
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // Position the body
    glScalef(0.7, 0.7, 0.7); // Scale down the body
    glutSolidSphere(0.1, 100, 100); // Example: Use a sphere for the body
    glPopMatrix();

    // Head
    glColor3f(1.0, 0.0, 0.0); // Yellowish color
    glPushMatrix();
    glTranslatef(0.06, 0.04, 0.0); // Position the head
    glScalef(0.7, 0.7, 0.7); // Scale down the head
    glutSolidSphere(0.05, 100, 100); // Example: Use a smaller sphere for the head
    glPopMatrix();

    // Eye
    glColor3f(1.0, 1.0, 1.0); // Black color
    glPushMatrix();
    glTranslatef(0.068, 0.048, 0.0); // Adjust the position of the eye
    glutSolidSphere(0.005, 50, 50); // Eye sphere
    glPopMatrix();

    // Beak
    glColor3f(1.0, 0.8, 0.0); // Orange color
    glPushMatrix();
    glTranslatef(0.06, 0.01, 0.0); // Position the beak
    glBegin(GL_TRIANGLES);
    glVertex2f(0.032, 0.045);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.032, 0.015);
    glEnd();
    glPopMatrix();

    // Legs
    glBegin(GL_LINES); // Begin drawing lines
    glColor3f(1, 1, 1); // Set color to white (RGB: 1, 1, 1)
    glVertex2f(0, -0.05); // First endpoint of the line (x, y)
    glVertex2f(0, -0.1); // Second endpoint of the line (x, y)
    glEnd(); // End drawing lines


    glPushMatrix();
    glTranslatef(-0.55, 0.52, 0.0);


    drawFilledHalfCircleS();
    glPopMatrix();

    glPopMatrix();
}

void drawBird()
{
    glPushMatrix();
    glTranslatef(x_position, y_position, 0.0);

    // Legs
    glBegin(GL_LINES); // Begin drawing lines
    glColor3f(0, 0, 0); // Set color to white (RGB: 1, 1, 1)
    glVertex2f(-0.02, -0.05); // First endpoint of the line (x, y)
    glVertex2f(-0.02, -0.1); // Second endpoint of the line (x, y)
    glEnd(); // End drawing lines

    // Body
    glColor3f(1.0, 0.8, 0.0); // Yellowish color
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // Position the body
    glScalef(0.7, 0.7, 0.7); // Scale down the body
    glutSolidSphere(0.1, 100, 100); // Example: Use a sphere for the body
    glPopMatrix();

    // Head
    glColor3f(1.0, 0.8, 0.0); // Yellowish color
    glPushMatrix();
    glTranslatef(0.06, 0.04, 0.0); // Position the head
    glScalef(0.7, 0.7, 0.7); // Scale down the head
    glutSolidSphere(0.05, 100, 100); // Example: Use a smaller sphere for the head
    glPopMatrix();

    // Eye
    glColor3f(0.0, 0.0, 0.0); // Black color
    glPushMatrix();
    glTranslatef(0.068, 0.048, 0.0); // Adjust the position of the eye
    glutSolidSphere(0.005, 50, 50); // Eye sphere
    glPopMatrix();

    // Beak
    glColor3f(1.0, 0.5, 0.0); // Orange color
    glPushMatrix();
    glTranslatef(0.06, 0.01, 0.0); // Position the beak
    glBegin(GL_TRIANGLES);
    glVertex2f(0.032, 0.045);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.032, 0.015);
    glEnd();
    glPopMatrix();

    // Legs
    glBegin(GL_LINES); // Begin drawing lines
    glColor3f(0, 0, 0); // Set color to white (RGB: 1, 1, 1)
    glVertex2f(0, -0.05); // First endpoint of the line (x, y)
    glVertex2f(0, -0.1); // Second endpoint of the line (x, y)
    glEnd(); // End drawing lines


    glPushMatrix();
    glTranslatef(-0.55, 0.52, 0.0);

    drawFilledHalfCircle();
    glPopMatrix();

    glPopMatrix();
}

void drawFilledHalfCircle() {
    glColor3f(0, 0, 0);

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = 0.045f * cos(angle) + 0.5f;
        float y = 0.045f * sin(angle) + 0.5f;
        glVertex2f(x, -y); // Negate the y-coordinate to flip the half-circle
    }
    glEnd();
}
void drawFilledHalfCircleS() {
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = 0.045f * cos(angle) + 0.5f;
        float y = 0.045f * sin(angle) + 0.5f;
        glVertex2f(x, -y); // Negate the y-coordinate to flip the half-circle
    }
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCloud()
{
    glColor3f(0, 0, 0);  // Set cloud color to black

    // Draw circles to represent a custom-shaped cloud border
    drawCircle(-0.4f, 0.0f, 0.21f, 100);
    drawCircle(-0.25f, 0.15f, 0.26f, 100);
    drawCircle(0.0f, 0.05f, 0.31f, 100);
    drawCircle(0.25f, 0.15f, 0.26f, 100);
    drawCircle(0.4f, 0.0f, 0.21f, 100);

    // Draw border for the larger circle as a peak
    drawCircle(0.0f, 0.3f, 0.31f, 100);

    // Draw border to the little circle to the right
    drawCircle(-0.25f, -0.2f, 0.16f, 100);

    glColor3f(1.0f, 1.0f, 1.0f);  // Set cloud color to white

    // Draw circles to represent a custom-shaped cloud
    drawCircle(-0.4f, 0.0f, 0.2f, 100);
    drawCircle(-0.25f, 0.15f, 0.25f, 100);
    drawCircle(0.0f, 0.05f, 0.3f, 100);
    drawCircle(0.25f, 0.15f, 0.25f, 100);
    drawCircle(0.4f, 0.0f, 0.2f, 100);

    // Draw a larger circle as a peak
    drawCircle(0.0f, 0.3f, 0.3f, 100);

    // Draw the little circle to the right
    drawCircle(-0.25f, -0.2f, 0.15f, 100);
}

void keyboardWelcome(unsigned char key, int x, int y)
{
    if (key == 27) // Esc key is pressed
        exit(0);

    else if (key == 13) // Enter key is pressed
    {
        i++;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Home");
        glutFullScreen();
        glutDisplayFunc(displayHome);

        printf("Enter key is pressed\n");
    }
    else printf("%c", key);
}

void displayWelcome() //Welcome screen (Welcome to Flappy Bird!)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);

    displayText(-0.7, 0.925, 0, 0.9, 0, 3, "____           __   _______   __             ______    ______    .___  ___. _______       .__________.  ______");
    displayText(-0.7, 0.85, 0, 0.9, 0, 3, "\\     \\  /    \\  /     / |     ____|  |     |            /            | /     __    \\     |     \\/     | |    ____  |      ||                    | /     __    \\ ");
    displayText(-0.7, 0.775, 0, 0.9, 0, 3, " \\     \\/      \\/     /  |    |__       |     |           | ,----'   |    |     |    |   |    \\   /    | |   |__             `---|    |--- `|     |    |    |");
    displayText(-0.7, 0.7, 0, 0.9, 0, 3, "  \\                  /    |     __|      |     |          |   |            |     |     |   |    |    |\\/|    | |      __|                   |   |          |     |    |    |");
    displayText(-0.7, 0.625, 0, 0.9, 0, 3, "   \\       /\\      /      |    |____  |     `----.|   `----.  |    `--'    |   |    |  |    | |    |____                 |   |          |    `--'    |");
    displayText(-0.7, 0.55, 0, 0.9, 0, 3, "    \\__/  \\__/       |_______||_______|  \\______| \\______/    |__|  |__| |_______|              |...|           \\______/");


    displayText(-0.8, 0.4, 0, 0.9, 0, 3, "._____.       ._.                      .___.          .____.     .____.     .__       __.       .____.      .___.    ._____.            ._______.       .__. ");
    displayText(-0.8, 0.325, 0, 0.9, 0, 3, "|     ___|       |  |                       /    \\            |  _    \\     |   _    \\     \\    \\   /   /          |   _   \\       |  |        |  ._   \\              |       \         \\      |  |");
    displayText(-0.8, 0.25, 0, 0.9, 0, 3, "|    |__          |  |                      /   ^  \\          |  |_)   |    |   |_)   |      \\   \\ /   /           |  |_)   |      |  |        |  |_)  |             |      .--.     |     |  |");
    displayText(-0.8, 0.175, 0, 0.9, 0, 3, "|     __|         |  |                    /    /_\\  \\        |   ___/    |   ___/        \\ ..... /            |   _  <       |  |         |       /              |      |    |      |    |  |");
    displayText(-0.8, 0.1, 0, 0.9, 0, 3, "|    |              |  `------.    /  ____  \\       |  |            |  |                  |  |              |  |_)    |     |  |         |     |\\  \\___      |     |__|     /     |  |");
    displayText(-0.8, 0.025, 0, 0.9, 0, 3, "|__|              |_______/    /__/     \\__\\     |_|            |_|                  |_|              |____/      |_|         |__| `._____|   |_______/     (__)");

    displayText(-0.15, -0.3, 0, 0.8, 0, 3, "Press Enter to Continue");
    displayText(-0.15, -0.375, 0, 0.8, 0, 3, "Press Esc to Exit");



    glutKeyboardFunc(keyboardWelcome);




    glFlush();
}

void keyboardHome(unsigned char key, int x, int y)
{

    if (key == 's' || key == 'S') //Arrow downward is pressed
    {
        if (a != 4) {
            a++;
            glutPostRedisplay();
        }
    }
    else if (key == 'w' || key == 'W') //Arrow upward is pressed
    {
        if (a != 1) {
            a--;
            glutPostRedisplay();
        }
    }
    else if (key == 27) //Esc key is pressed
        exit(0);
    else if (key == 8) //Backspace key is pressed
    {
        i++;
        glutDestroyWindow(i); //Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Welcome");
        glutFullScreen();
        glutDisplayFunc(displayWelcome);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }

    if (key == 13) //Enter key is pressed
    {
        if (a == 1) //Arrow in pointing at 'Start' option
        {
            glutDestroyWindow(i); //Closes the most recent window
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutCreateWindow("Flappy Bird: Start");
            glutFullScreen();
            glutDisplayFunc(displayStart);
            glutPostRedisplay();
        }
        else if (a == 2) //Arrow in pointing at 'Instructions' option
        {
            glutDestroyWindow(i); //Closes the most recent window
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutCreateWindow("Flappy Bird: Instructions");
            glutFullScreen();
            glutDisplayFunc(displayInstructions);
            glutPostRedisplay();
        }
        else if (a == 3) //Arrow in pointing at 'Credits' option
        {
            glutDestroyWindow(i); //Closes the most recent window
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutCreateWindow("Flappy Bird: Credits");
            glutFullScreen();
            glutDisplayFunc(displayCredits);
            glutPostRedisplay();
        }
        else //Arrow in pointing at 'Quit' option
        {
            exit(0);
        }
    }

    else printf("Invalid key is pressed\n");
}

void displayHome() //Home screen (Start, Instructions, Credits, and Quit)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    drawCloud();
    displayText(-0.075, 0.3, 0, 0, 0, 1, "Start");
    displayText(-0.119, 0.2, 0, 0, 0, 1, "Instructions");
    displayText(-0.087, 0.1, 0, 0, 0, 1, "Credits");
    displayText(-0.07, 0, 0, 0, 0, 1, "Quit");

    switch (a)
    {
    case 1:displayText(-0.27, 0.3, 0, 0, 0, 1, "||---->"); break;
    case 2:displayText(-0.27, 0.2, 0, 0, 0, 0, "||---->"); break;
    case 3:displayText(-0.27, 0.1, 0, 0, 0, 0, "||---->"); break;
    case 4:displayText(-0.27, 0, 0, 0, 0, 0, "||---->"); break;
    }

    drawColumn();

    glutKeyboardFunc(keyboardHome);

    glFlush();
}

void keyboardStart(unsigned char key, int x, int y)
{
    if (key == 's' || key == 'S') //Arrow downward is pressed
    {
        if (s == 1) {
            s++;
            glutPostRedisplay();
        }
    }
    else if (key == 'w' || key == 'W') //Arrow upward is pressed
    {
        if (s == 2) {
            s--;
            glutPostRedisplay();
        }
    }

    if (key == 8) //Backspace key is pressed
    {
        i++;
        glutDestroyWindow(i); //Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Home");
        glutFullScreen();
        glutDisplayFunc(displayHome);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) //Esc key is pressed
    {
        exit(0);
    }
    else if (key == 13) //Enter key pressed
    {
        if (s == 1)
        {
            i++;
            glutDestroyWindow(i); //Closes the most recent opened window
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutCreateWindow("Flappy Bird: Scene One");
            glutFullScreen();
            glutDisplayFunc(displaySceneOne);
            timerActive = 1;
            glutTimerFunc(0, timerGravity, 0);
            glutTimerFunc(0, timerrec, 0);
            glutTimerFunc(100, timerrec2, 0);
            glutTimerFunc(200, timerrec3, 0);
            glutTimerFunc(300, timerrec4, 0);


            y_position = 0.0f;
            x_positionrec = 0.0f;
            x_positionrec2 = 0.0f;
            x_positionrec3 = 0.0f;
            x_positionrec4 = 0.0f;

            // Set the coordinate system
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
            glutPostRedisplay();
        }
        else if (s == 2) {
            i++;
            glutDestroyWindow(i); //Closes the most recent opened window
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutCreateWindow("Flappy Bird: Scene Two");
            glutFullScreen();
            glutDisplayFunc(displaySceneTwo);
            timerActive = 1;
            glutTimerFunc(0, timerGravity, 0);
            glutTimerFunc(0, timerrecs, 0);
            glutTimerFunc(100, timerrecs2, 0);
            glutTimerFunc(200, timerrecs3, 0);
            glutTimerFunc(300, timerrecs4, 0);


            y_position = 0.0f;
            x_positionrec = 0.0f;
            x_positionrec2 = 0.0f;
            x_positionrec3 = 0.0f;
            x_positionrec4 = 0.0f;

            // Set the coordinate system
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
            glutPostRedisplay();

        }
    }
    else printf("Invalid key is pressed\n");
}

void displayStart()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);

    drawSmallCloud();

    displayText(-0.055, 0.43, 0, 0, 0, 0, "Scene One");
    displayText(-0.055, -0.37, 0, 0, 0, 0, "Scene Two");

    switch (s)
    {
    case 1:displayText(-0.49, 0.43, 0, 0, 0, 0, "||------>"); break;
    case 2:displayText(-0.49, -0.40, 0, 0, 0, 0, "||------>"); break;
    }

    glutKeyboardFunc(keyboardStart);

    glFlush();
}

void keyboardGameOver(unsigned char key, int x, int y)
{
    if (key == 8) // Backspace key is pressed
    {
        i++;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Home");
        glutFullScreen();
        glutDisplayFunc(displayStart);
        glutPostRedisplay();
        score = 0;

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) // Esc key is pressed
    {
        exit(0);
    }
    else printf("Invalid key is pressed\n");
}
void drawGAMEOVER() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw "GAME OVER" using lines
    glColor3f(0.0, 1.0, 0.0); // Set color to red
    glLineWidth(2.5); // Set line width

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    glBegin(GL_LINES);

    // 'G'
    glVertex3f(-0.8f, 0.8f, -1.0f);
    glVertex3f(-0.8f, 0.4f, -1.0f);
    glVertex3f(-0.8f, 0.8f, -1.0f);
    glVertex3f(-0.6f, 0.8f, -1.0f);
    glVertex3f(-0.8f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.4f, -1.0f);
    glVertex3f(-0.6f, 0.4f, -1.0f);
    glVertex3f(-0.8f, 0.4f, -1.0f);


    // 'A'
    // Add lines for 'A' here
    glBegin(GL_LINES);
    glVertex3f(-0.3f, 0.8f, -1.0f);
    glVertex3f(-0.3f, 0.4f, -1.0f);
    glVertex3f(-0.3f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.3f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.4f, -1.0f);
    //glVertex3f(-0.5f, 0.4f, -1.0f);
    //glVertex3f(-0.3f, 0.4f, -1.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, 0, 0);
    // 'M'
    // Add lines for 'M' here
    glBegin(GL_LINES);
    glVertex3f(-0.1f, 0.8f, -1.0f);
    glVertex3f(-0.1f, 0.4f, -1.0f);
    glVertex3f(-0.1f, 0.8f, -1.0f);
    glVertex3f(-0.2f, 0.6f, -1.0f);
    glVertex3f(-0.2f, 0.6f, -1.0f);
    glVertex3f(-0.3f, 0.7f, -1.0f);
    glVertex3f(-0.3f, 0.7f, -1.0f);
    glVertex3f(-0.4f, 0.6f, -1.0f);
    glVertex3f(-0.4f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.4f, -1.0f);



    // 'E'
    // Add lines for 'E' here
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.8f, -1.0f);
    glVertex3f(0.0f, 0.4f, -1.0f);
    glVertex3f(0.0f, 0.8f, -1.0f);
    glVertex3f(0.2f, 0.8f, -1.0f);
    glVertex3f(0.0f, 0.6f, -1.0f);
    glVertex3f(0.2f, 0.6f, -1.0f);
    glVertex3f(0.0f, 0.4f, -1.0f);
    glVertex3f(0.2f, 0.4f, -1.0f);
    glEnd();
    glPopMatrix();


    // 'O'
    // Add lines for 'O' here
    glBegin(GL_LINES);
    glVertex3f(0.3f, 0.8f, -1.0f);
    glVertex3f(0.3f, 0.4f, -1.0f);
    glVertex3f(0.3f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.4f, -1.0f);
    glVertex3f(0.5f, 0.4f, -1.0f);
    glVertex3f(0.3f, 0.4f, -1.0f);

    // 'V'
    // Add lines for 'V' here
    glBegin(GL_LINES);
    glVertex3f(0.7f, 0.4f, -1.0f);
    glVertex3f(0.6f, 0.8f, -1.0f);
    glVertex3f(0.7f, 0.4f, -1.0f);
    glVertex3f(0.8f, 0.8f, -1.0f);


    // 'E'
    // Add lines for 'E' here
    glBegin(GL_LINES);
    glVertex3f(0.9f, 0.8f, -1.0f);
    glVertex3f(0.9f, 0.4f, -1.0f);
    glVertex3f(0.9f, 0.8f, -1.0f);
    glVertex3f(1.1f, 0.8f, -1.0f);
    glVertex3f(0.9f, 0.6f, -1.0f);
    glVertex3f(1.1f, 0.6f, -1.0f);
    glVertex3f(0.9f, 0.4f, -1.0f);
    glVertex3f(1.1f, 0.4f, -1.0f);


    // 'R'
    // Add lines for 'R' here
    glBegin(GL_LINES);
    glVertex3f(1.2f, 0.8f, -1.0f);
    glVertex3f(1.2f, 0.4f, -1.0f);
    glVertex3f(1.2f, 0.8f, -1.0f);
    glVertex3f(1.3f, 0.8f, -1.0f);
    glVertex3f(1.3f, 0.8f, -1.0f);
    glVertex3f(1.4f, 0.7f, -1.0f);
    glVertex3f(1.4f, 0.7f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.2f, 0.6f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.4f, 0.4f, -1.0f);


    glEnd();

    glFlush();
}
void drawGAMEOVERs() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw "GAME OVER" using lines
    glColor3f(0.7, 0.5, 0.10); // Set color to red
    glLineWidth(2.5); // Set line width

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    glBegin(GL_LINES);

    // 'G'
    glVertex3f(-0.8f, 0.8f, -1.0f);
    glVertex3f(-0.8f, 0.4f, -1.0f);
    glVertex3f(-0.8f, 0.8f, -1.0f);
    glVertex3f(-0.6f, 0.8f, -1.0f);
    glVertex3f(-0.8f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.6f, -1.0f);
    glVertex3f(-0.6f, 0.4f, -1.0f);
    glVertex3f(-0.6f, 0.4f, -1.0f);
    glVertex3f(-0.8f, 0.4f, -1.0f);


    // 'A'
    // Add lines for 'A' here
    glBegin(GL_LINES);
    glVertex3f(-0.3f, 0.8f, -1.0f);
    glVertex3f(-0.3f, 0.4f, -1.0f);
    glVertex3f(-0.3f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.3f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.4f, -1.0f);
    //glVertex3f(-0.5f, 0.4f, -1.0f);
    //glVertex3f(-0.3f, 0.4f, -1.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, 0, 0);
    // 'M'
    // Add lines for 'M' here
    glBegin(GL_LINES);
    glVertex3f(-0.1f, 0.8f, -1.0f);
    glVertex3f(-0.1f, 0.4f, -1.0f);
    glVertex3f(-0.1f, 0.8f, -1.0f);
    glVertex3f(-0.2f, 0.6f, -1.0f);
    glVertex3f(-0.2f, 0.6f, -1.0f);
    glVertex3f(-0.3f, 0.7f, -1.0f);
    glVertex3f(-0.3f, 0.7f, -1.0f);
    glVertex3f(-0.4f, 0.6f, -1.0f);
    glVertex3f(-0.4f, 0.6f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.8f, -1.0f);
    glVertex3f(-0.5f, 0.4f, -1.0f);



    // 'E'
    // Add lines for 'E' here
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.8f, -1.0f);
    glVertex3f(0.0f, 0.4f, -1.0f);
    glVertex3f(0.0f, 0.8f, -1.0f);
    glVertex3f(0.2f, 0.8f, -1.0f);
    glVertex3f(0.0f, 0.6f, -1.0f);
    glVertex3f(0.2f, 0.6f, -1.0f);
    glVertex3f(0.0f, 0.4f, -1.0f);
    glVertex3f(0.2f, 0.4f, -1.0f);
    glEnd();
    glPopMatrix();


    // 'O'
    // Add lines for 'O' here
    glBegin(GL_LINES);
    glVertex3f(0.3f, 0.8f, -1.0f);
    glVertex3f(0.3f, 0.4f, -1.0f);
    glVertex3f(0.3f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.8f, -1.0f);
    glVertex3f(0.5f, 0.4f, -1.0f);
    glVertex3f(0.5f, 0.4f, -1.0f);
    glVertex3f(0.3f, 0.4f, -1.0f);

    // 'V'
    // Add lines for 'V' here
    glBegin(GL_LINES);
    glVertex3f(0.7f, 0.4f, -1.0f);
    glVertex3f(0.6f, 0.8f, -1.0f);
    glVertex3f(0.7f, 0.4f, -1.0f);
    glVertex3f(0.8f, 0.8f, -1.0f);


    // 'E'
    // Add lines for 'E' here
    glBegin(GL_LINES);
    glVertex3f(0.9f, 0.8f, -1.0f);
    glVertex3f(0.9f, 0.4f, -1.0f);
    glVertex3f(0.9f, 0.8f, -1.0f);
    glVertex3f(1.1f, 0.8f, -1.0f);
    glVertex3f(0.9f, 0.6f, -1.0f);
    glVertex3f(1.1f, 0.6f, -1.0f);
    glVertex3f(0.9f, 0.4f, -1.0f);
    glVertex3f(1.1f, 0.4f, -1.0f);


    // 'R'
    // Add lines for 'R' here
    glBegin(GL_LINES);
    glVertex3f(1.2f, 0.8f, -1.0f);
    glVertex3f(1.2f, 0.4f, -1.0f);
    glVertex3f(1.2f, 0.8f, -1.0f);
    glVertex3f(1.3f, 0.8f, -1.0f);
    glVertex3f(1.3f, 0.8f, -1.0f);
    glVertex3f(1.4f, 0.7f, -1.0f);
    glVertex3f(1.4f, 0.7f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.2f, 0.6f, -1.0f);
    glVertex3f(1.3f, 0.6f, -1.0f);
    glVertex3f(1.4f, 0.4f, -1.0f);


    glEnd();

    glFlush();
}
void drawline() 
{
    glBegin(GL_LINES);
    glVertex3f(-0.21f, -0.1f, -1.0f);
    glVertex3f(-0.15f, 0.15f, -1.0f);
    glVertex3f(0.3f, 0.15f, -1.0f);
    glVertex3f(0.25f, -0.1f, -1.0f);
    glVertex3f(-0.15f, 0.15f, -1.0f);
    glVertex3f(0.3f, 0.15f, -1.0f);
    glVertex3f(-0.21f, -0.1f, -1.0f);
    glVertex3f(0.25f, -0.1f, -1.0f);

    glEnd();
}

void displayGameOver()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1.0f);


    drawGAMEOVER();
    std::string scoreString = std::to_string(score);
    const char* scoreCString = scoreString.c_str();
    displayText(-0.1, -0.018, 0, 1, 0, 0, "Score : ");
    displayText(0.12, -0.018, 0, 1, 0, 0, scoreCString);


    drawline();
    glutKeyboardFunc(keyboardGameOver);

    glFlush();
}
void displayGameOverS()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.15, 0, 0, 1.0f);


    drawGAMEOVERs();
    std::string scoreString = std::to_string(score);
    const char* scoreCString = scoreString.c_str();
    displayText(-0.1, -0.018, 0.7, 0.5, 0.10, 0, "Score : ");
    displayText(0.12, -0.018, 0.7, 0.5, 0.10, 0, scoreCString);
    drawline();
    glutKeyboardFunc(keyboardGameOver);

    glFlush();
}

void keyboardSceneOne(unsigned char key, int x, int y)
{

    if (key == 32)// spacebar
    {
        if (y_position < 0.9f)// so that the bird doesnt exceed the screen y axis
        {
            t = 0;

            // Y position += 0.25f;
            glutTimerFunc(0, timerUp, 0);

            // Set the coordinate system
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
            glutPostRedisplay();
        }
    }

    if (key == 8) // Backspace key is pressed
    {
        i++;
        timerActive = 0;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Start");
        glutFullScreen();
        glutDisplayFunc(displayStart);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) // Esc key is pressed
    {
        exit(0);
    }
    else printf("Invalid key is pressed\n");
}

void displaySceneOne()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    drawBird();

    if (y_position <= -0.8f)
    {
        i++;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Start");
        glutFullScreen();
        glutDisplayFunc(displayGameOver);
        timerActive = 0;

        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }

    //   std::string scoreString = std::to_string(score);
    std::string scoreString = std::to_string(score);
    const char* scoreCString = scoreString.c_str();




    rec();
    rec2();
    rec3();
    rec4();

    rectext();
    displayText(0.8, 0.9, 1, 1, 1, 0, "Score : ");
    displayText(0.9, 0.9, 1, 1, 1, 0, scoreCString);


    glutKeyboardFunc(keyboardSceneOne);

    glFlush();
}
void rectext() {//score parallelogram
    glBegin(GL_QUADS);

    glColor3f(0, 0, 0);
    glVertex2f(0.77, 0.97);
    glVertex2f(0.97, 0.97);
    glVertex2f(0.95, 0.85);
    glVertex2f(0.75, 0.85);
    glEnd();

}

void keyboardSceneTwo(unsigned char key, int x, int y)
{
    if (key == 32)
    {
        if (y_position < 0.9f)
        {
            t = 0;

            // Y position += 0.25f;
            glutTimerFunc(0, timerUp, 0);

            // Set the coordinate system
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
            glutPostRedisplay();
        }
    }

    if (key == 8) // Backspace key is pressed
    {
        i++;
        timerActive = 0;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Start");
        glutFullScreen();
        glutDisplayFunc(displayStart);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) // Esc key is pressed
    {
        exit(0);
    }
    else printf("Invalid key is pressed\n");
}

void displaySceneTwo()
{
    // glColor3f(0.7f, 0.5f, 0.10f);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.15f, 0.0f, 0.0f, 1.0f);
    drawBirds();

    if (y_position <= -0.8f)
    {
        i++;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Start");
        glutFullScreen();
        glutDisplayFunc(displayGameOverS);
        timerActive = 0;

        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }

    //   std::string scoreString = std::to_string(score);
    std::string scoreString = std::to_string(score);
    const char* scoreCString = scoreString.c_str();




    recs();
    recs2();
    recs3();
    recs4();

    rectext();
    displayText(0.8, 0.9, 1, 1, 1, 0, "Score : ");
    displayText(0.9, 0.9, 1, 1, 1, 0, scoreCString);


    glutKeyboardFunc(keyboardSceneOne);

    glFlush();
}

void keyboardInstructions(unsigned char key, int x, int y)
{
    if (key == 8) // Backspace key is pressed
    {
        i++;
        glutDestroyWindow(i); // Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Home");
        glutFullScreen();
        glutDisplayFunc(displayHome);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) // Esc key is pressed
    {
        exit(0);
    }
    else printf("Invalid key is pressed\n");
}
void displayInstructions()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);

    drawBox();

    displayText(-0.35, 0.5, 0, 0, 0, 1, "KEYS");
    displayText(0.18, 0.5, 0, 0, 0, 1, "FUNCTION");

    displayText(-0.37, 0.49, 0, 0, 0, 1, "_______");
    displayText(0.1625, 0.49, 0, 0, 0, 1, "____________");


    displayText(-0.35, 0.3, 0, 0, 0, 1, "Enter");
    displayText(0.1275, 0.3, 0, 0, 0, 1, "Continue / Select");

    displayText(-0.35, 0.125, 0, 0, 0, 1, "Backspace");
    displayText(0.025, 0.125, 0, 0, 0, 1, "Return to previous screen");

    displayText(-0.35, -0.05, 0, 0, 0, 1, "W / w");
    displayText(-0.0425, -0.05, 0, 0, 0, 1, "Move selection arrow upwards");

    displayText(-0.35, -0.225, 0, 0, 0, 1, "S / s");
    displayText(-0.075, -0.225, 0, 0, 0, 1, "Move selection arrow downwards");

    displayText(-0.35, -0.4, 0, 0, 0, 1, "Space");
    displayText(0.025, -0.4, 0, 0, 0, 1, "Jump the FLAPPY BIRD");

    displayText(-0.35, -0.55, 0, 0, 0, 1, "Esc");
    displayText(0.15, -0.55, 0, 0, 0, 1, "Exit to Desktop");


    glutKeyboardFunc(keyboardInstructions);

    glFlush();
}

void keyboardCredits(unsigned char key, int x, int y)
{
    if (key == 8) //Backspace key is pressed
    {
        i++;
        glutDestroyWindow(i); //Closes the most recent opened window
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Flappy Bird: Home");
        glutFullScreen();
        glutDisplayFunc(displayHome);
        glutPostRedisplay();

        printf("Backspace key is pressed\n");
    }
    else if (key == 27) //Esc key is pressed
    {
        exit(0);
    }
    else printf("Invalid key is pressed\n");
}

void displayCredits()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    drawBox();

    displayText(-0.06, 0.5, 0, 0, 0, 1, "Flappy BIRD");
    displayText(-0.1, 0.49, 0, 0, 0, 1, "_______________");

    displayText(-0.35, 0.125, 0, 0, 0, 1, "Project members:");
    displayText(0.0175, 0.125, 0, 0, 0, 1, "Ahmed Hossam El-din Adly");
    displayText(0.0175, 0.05, 0, 0, 0, 1, "Omar Ahmed Fouad");
    displayText(0.0175, -0.025, 0, 0, 0, 1, "Ali Hassan Fahim");
    displayText(0.0175, -0.1, 0, 0, 0, 1, "Mohamed Tarek Shawky");
    displayText(0.0175, -0.175, 0, 0, 0, 1, "Ali Mohamed Ali");

    displayText(-0.35, -0.4, 0, 0, 0, 1, "Project guidance:");
    displayText(0.0175, -0.4, 0, 0, 0, 1, "Khaled Magdy");
    displayText(0.0175, -0.475, 0, 0, 0, 1, "Dr. Wessam Askar");

    glutKeyboardFunc(keyboardCredits);

    glFlush();
}

void drawBox()
{
    glBegin(GL_QUADS);

    glColor3f(0, 0, 0);
    glVertex2f(-0.41, 0.71);
    glVertex2f(0.41, 0.71);
    glVertex2f(0.41, -0.71);
    glVertex2f(-0.41, -0.71);

    glColor3f(1, 1, 1);
    glVertex2f(-0.4, 0.7);
    glVertex2f(0.4, 0.7);
    glVertex2f(0.4, -0.7);
    glVertex2f(-0.4, -0.7);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.1, 1);
    glVertex2f(0.1, 1);
    glVertex2f(0.1, 0.8);
    glVertex2f(-0.1, 0.8);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.12, 0.9);
    glVertex2f(0.12, 0.9);
    glVertex2f(0.12, 0.8);
    glVertex2f(-0.12, 0.8);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.1, -1);
    glVertex2f(0.1, -1);
    glVertex2f(0.1, -0.8);
    glVertex2f(-0.1, -0.8);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.12, -0.9);
    glVertex2f(0.12, -0.9);
    glVertex2f(0.12, -0.8);
    glVertex2f(-0.12, -0.8);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.8, 1);
    glVertex2f(-0.6, 1);
    glVertex2f(-0.6, 0.4);
    glVertex2f(-0.8, 0.4);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.82, 0.5);
    glVertex2f(-0.58, 0.5);
    glVertex2f(-0.58, 0.4);
    glVertex2f(-0.82, 0.4);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.8, -1);
    glVertex2f(-0.6, -1);
    glVertex2f(-0.6, -0.15);
    glVertex2f(-0.8, -0.15);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.82, -0.25);
    glVertex2f(-0.58, -0.25);
    glVertex2f(-0.58, -0.15);
    glVertex2f(-0.82, -0.15);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, 1);
    glVertex2f(0.6, 1);
    glVertex2f(0.6, -0.05);
    glVertex2f(0.8, -0.05);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.82, 0.05);
    glVertex2f(0.58, 0.05);
    glVertex2f(0.58, -0.05);
    glVertex2f(0.82, -0.05);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, -1);
    glVertex2f(0.6, -1);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.8, -0.6);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.82, -0.7);
    glVertex2f(0.58, -0.7);
    glVertex2f(0.58, -0.6);
    glVertex2f(0.82, -0.6);

    glEnd();

}
void rec() {

    glPushMatrix();
    glTranslatef(x_positionrec, 0, 0);
    //-1.62

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.4, 1);
    glVertex2f(0.6, 1);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.4, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.38, 0.6);
    glVertex2f(0.62, 0.6);
    glVertex2f(0.62, 0.5);
    glVertex2f(0.38, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.4, -1);
    glVertex2f(0.6, -1);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.4, -0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.38, -0.4);
    glVertex2f(0.62, -0.4);
    glVertex2f(0.62, -0.3);
    glVertex2f(0.38, -0.3);

    glEnd();
    glPopMatrix();
    //0.8  0.4

}

void rec2() {
    glPushMatrix();
    glTranslatef(x_positionrec2, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(0.8, 0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.78, 0.4);
    glVertex2f(1.02, 0.4);
    glVertex2f(1.02, 0.3);
    glVertex2f(0.78, 0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.6);
    glVertex2f(0.8, -0.6);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.78, -0.7);
    glVertex2f(1.02, -0.7);
    glVertex2f(1.02, -0.6);
    glVertex2f(0.78, -0.6);

    glEnd();
    glPopMatrix();
}

void rec3() {
    glPushMatrix();//0.6
    glTranslatef(x_positionrec3, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.2, 1);
    glVertex2f(1.4, 1);
    glVertex2f(1.4, 0.7);
    glVertex2f(1.2, 0.7);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.18, 0.8);
    glVertex2f(1.42, 0.8);
    glVertex2f(1.42, 0.7);
    glVertex2f(1.18, 0.7);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.2, -1);
    glVertex2f(1.4, -1);
    glVertex2f(1.4, -0.2);
    glVertex2f(1.2, -0.2);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.18, -0.1);
    glVertex2f(1.42, -0.1);
    glVertex2f(1.42, -0.2);
    glVertex2f(1.18, -0.2);

    glEnd();
    glPopMatrix();
}

void rec4() {
    glPushMatrix();//0.6
    glTranslatef(x_positionrec4, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.6, 1);
    glVertex2f(1.8, 1);
    glVertex2f(1.8, 0.5);
    glVertex2f(1.6, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.58, 0.6);
    glVertex2f(1.82, 0.6);
    glVertex2f(1.82, 0.5);
    glVertex2f(1.58, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.6, -1);
    glVertex2f(1.8, -1);
    glVertex2f(1.8, -0.4);
    glVertex2f(1.6, -0.4);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(1.58, -0.3);
    glVertex2f(1.82, -0.3);
    glVertex2f(1.82, -0.4);
    glVertex2f(1.58, -0.4);

    glEnd();
    glPopMatrix();
}

void recs() {

    glPushMatrix();
    glTranslatef(x_positionrec, 0, 0);
    //-1.62

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.4, 1);
    glVertex2f(0.6, 1);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.4, 0.5);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.38, 0.6);
    glVertex2f(0.62, 0.6);
    glVertex2f(0.62, 0.5);
    glVertex2f(0.38, 0.5);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.4, -1);
    glVertex2f(0.6, -1);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.4, -0.3);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.38, -0.4);
    glVertex2f(0.62, -0.4);
    glVertex2f(0.62, -0.3);
    glVertex2f(0.38, -0.3);

    glEnd();
    glPopMatrix();
    //0.8  0.4

}

void recs2() {
    glPushMatrix();
    glTranslatef(x_positionrec2, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.8, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(0.8, 0.3);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.78, 0.4);
    glVertex2f(1.02, 0.4);
    glVertex2f(1.02, 0.3);
    glVertex2f(0.78, 0.3);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.8, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.6);
    glVertex2f(0.8, -0.6);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(0.78, -0.7);
    glVertex2f(1.02, -0.7);
    glVertex2f(1.02, -0.6);
    glVertex2f(0.78, -0.6);

    glEnd();
    glPopMatrix();
}

void recs3() {
    glPushMatrix();//0.6
    glTranslatef(x_positionrec3, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.2, 1);
    glVertex2f(1.4, 1);
    glVertex2f(1.4, 0.7);
    glVertex2f(1.2, 0.7);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.18, 0.8);
    glVertex2f(1.42, 0.8);
    glVertex2f(1.42, 0.7);
    glVertex2f(1.18, 0.7);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.2, -1);
    glVertex2f(1.4, -1);
    glVertex2f(1.4, -0.2);
    glVertex2f(1.2, -0.2);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.18, -0.1);
    glVertex2f(1.42, -0.1);
    glVertex2f(1.42, -0.2);
    glVertex2f(1.18, -0.2);

    glEnd();
    glPopMatrix();
}

void recs4() {
    glPushMatrix();//0.6
    glTranslatef(x_positionrec4, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.6, 1);
    glVertex2f(1.8, 1);
    glVertex2f(1.8, 0.5);
    glVertex2f(1.6, 0.5);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.58, 0.6);
    glVertex2f(1.82, 0.6);
    glVertex2f(1.82, 0.5);
    glVertex2f(1.58, 0.5);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.6, -1);
    glVertex2f(1.8, -1);
    glVertex2f(1.8, -0.4);
    glVertex2f(1.6, -0.4);

    glColor3f(0.7f, 0.5f, 0.10f);
    glVertex2f(1.58, -0.3);
    glVertex2f(1.82, -0.3);
    glVertex2f(1.82, -0.4);
    glVertex2f(1.58, -0.4);

    glEnd();
    glPopMatrix();
}


void drawColumn()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.1, 1);

    glVertex2f(0.1, 1);
    glVertex2f(0.1, 0.7);
    glVertex2f(-0.1, 0.7);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.12, 0.8);
    glVertex2f(0.12, 0.8);
    glVertex2f(0.12, 0.7);
    glVertex2f(-0.12, 0.7);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.1, -1);
    glVertex2f(0.1, -1);
    glVertex2f(0.1, -0.5);
    glVertex2f(-0.1, -0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.12, -0.6);
    glVertex2f(0.12, -0.6);
    glVertex2f(0.12, -0.5);
    glVertex2f(-0.12, -0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.4, 1);
    glVertex2f(0.6, 1);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.4, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.38, 0.6);
    glVertex2f(0.62, 0.6);
    glVertex2f(0.62, 0.5);
    glVertex2f(0.38, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.4, -1);
    glVertex2f(0.6, -1);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.4, -0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.38, -0.4);
    glVertex2f(0.62, -0.4);
    glVertex2f(0.62, -0.3);
    glVertex2f(0.38, -0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.4, 1);
    glVertex2f(-0.6, 1);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.4, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.38, 0.4);
    glVertex2f(-0.62, 0.4);
    glVertex2f(-0.62, 0.5);
    glVertex2f(-0.38, 0.5);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.4, -1);
    glVertex2f(-0.6, -1);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.4, -0.4);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.38, -0.5);
    glVertex2f(-0.62, -0.5);
    glVertex2f(-0.62, -0.4);
    glVertex2f(-0.38, -0.4);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.8, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, -0.25);
    glVertex2f(-0.8, -0.25);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.78, -0.125);
    glVertex2f(-1, -0.125);
    glVertex2f(-1, -0.25);
    glVertex2f(-0.78, -0.25);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.8, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, 0.65);
    glVertex2f(-0.8, 0.65);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(-0.78, 0.55);
    glVertex2f(-1, 0.55);
    glVertex2f(-1, 0.65);
    glVertex2f(-0.78, 0.65);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(0.8, 0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.78, 0.4);
    glVertex2f(1, 0.4);
    glVertex2f(1, 0.3);
    glVertex2f(0.78, 0.3);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.6);
    glVertex2f(0.8, -0.6);

    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.78, -0.7);
    glVertex2f(1, -0.7);
    glVertex2f(1, -0.6);
    glVertex2f(0.78, -0.6);

    glEnd();
}

void drawSmallCloud()
{
    // Draw circles to represent a custom-shaped cloud border
    glColor3f(0, 0, 0);  // Set cloud color to Black

    // Draw circles to represent a custom-shaped cloud
    drawCircle(-0.1f, 0.4f, 0.11f, 100);
    drawCircle(-0.05f, 0.45f, 0.12f, 100);
    drawCircle(0, 0.4f, 0.12f, 100);
    drawCircle(0.05f, 0.45f, 0.12f, 100);
    drawCircle(0.1f, 0.4f, 0.11f, 100);

    // Draw a larger circle as a peak
    drawCircle(0.05f, 0.5f, 0.12f, 100);

    glColor3f(1.0f, 1.0f, 1.0f);  // Set cloud color to white

    // Draw circles to represent a custom-shaped cloud
    drawCircle(-0.1f, 0.4f, 0.1f, 100);
    drawCircle(-0.05f, 0.45f, 0.11f, 100);
    drawCircle(0, 0.4f, 0.11f, 100);
    drawCircle(0.05f, 0.45f, 0.11f, 100);
    drawCircle(0.1f, 0.4f, 0.1f, 100);

    // Draw a larger circle as a peak
    drawCircle(0.05f, 0.5f, 0.11f, 100);

    // Draw circles to represent a custom-shaped cloud border
    glColor3f(0, 0, 0);  // Set cloud color to Black

    // Draw circles to represent a custom-shaped cloud
    drawCircle(-0.1f, -0.4f, 0.11f, 100);
    drawCircle(-0.05f, -0.35f, 0.12f, 100);
    drawCircle(0, -0.4f, 0.12f, 100);
    drawCircle(0.05f, -0.35f, 0.12f, 100);
    drawCircle(0.1f, -0.4f, 0.11f, 100);

    // Draw a larger circle as a peak
    drawCircle(0.05f, -0.3f, 0.12f, 100);//+0.1

    glColor3f(1.0f, 1.0f, 1.0f);  // Set cloud color to white

    // Draw circles to represent a custom-shaped cloud
    drawCircle(-0.1f, -0.4f, 0.1f, 100);
    drawCircle(-0.05f, -0.35f, 0.11f, 100);
    drawCircle(0, -0.4f, 0.11f, 100);
    drawCircle(0.05f, -0.35f, 0.11f, 100);
    drawCircle(0.1f, -0.4f, 0.1f, 100);

    // Draw a larger circle as a peak
    drawCircle(0.05f, -0.3f, 0.11f, 100);
}

void displayText(float x, float y, float r, float g, float b, int font, const char* string)
{
    //GLvoid* font_style = GLUT_BITMAP_TIMES_ROMAN_24;
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void SetConsoleCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CenterTextInConsole(const string& text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int textWidth = static_cast<int>(text.length());

    // Calculate the X position for horizontal centering
    int xCenter = (consoleWidth - textWidth) / 2;

    // Calculate the Y position for vertical centering
    int yCenter = (consoleHeight / 2);

    SetConsoleCursorPosition(xCenter, yCenter);
    cout << text;
}

int main(int argc, char** argv)
{
    play_music("gameofthrones.wav");

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Flappy Bird");
    glutFullScreen();
    glutDisplayFunc(displayWelcome);

    glutMainLoop();

    return 0;
}