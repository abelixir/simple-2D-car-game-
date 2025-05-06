
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>  // Include cmath for sin and cos

const int screenWidth = 1200, screenHeight = 850;
int carX = screenWidth / 2, carY = 50, carWidth = 50, carHeight = 50;
int oppoX[2], oppoY[2] = {screenHeight, screenHeight + 200};
int oppoWidth = 60, oppoHeight = 100;
bool gameOver = false;
int score = 0;
int level = 0; // 0: Welcome, 1: Menu, 2: Easy, 3: Medium, 4: Hard
bool welcomeScreen = true; // Manage flow between welcome and menu
const float PI = 3.1415926;
void drawRectangle(int x, int y, int width, int height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}
void drawDetailedCar(int x, int y, int width, int height) {
    // Car Body
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    drawRectangle(x, y, width, height);

    // Car Windows
    glColor3f(0.8f, 0.8f, 0.8f);  // Light Gray for windows
    drawRectangle(x + 10, y + height - 10, width - 20, 20);  // Front window
    drawRectangle(x + 10, y + 10, width - 20, 20);  // Rear window

    // Car Wheels
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    drawRectangle(x + 5, y - 10, 10, 10);  // Rear left wheel
    drawRectangle(x + width - 15, y - 10, 10, 10);  // Rear right wheel
    drawRectangle(x + 5, y + height, 10, 10);  // Front left wheel
    drawRectangle(x + width - 15, y + height, 10, 10);  // Front right wheel

    // Car Spoiler
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark Gray
    drawRectangle(x + width / 2 - 10, y - height / 2, 20, 5);

    // Car Side Mirrors
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    drawRectangle(x - 5, y + height - 10, 5, 10);  // Left mirror
    drawRectangle(x + width, y + height - 10, 5, 10);  // Right mirror

    // Car Lights
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    drawRectangle(x + width - 5, y + height - 5, 5, 5);  // Rear left light
    drawRectangle(x + width - 5, y, 5, 5);  // Rear right light
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    drawRectangle(x, y + height - 5, 5, 5);  // Front left light
    drawRectangle(x, y, 5, 5);  // Front right light

    // Shadow (just for a bit more visual effect)
    
}

void mindesign(int a ,int b){
	 glColor3f(0.1f, 0.1f, 0.1f); // design
    float mradse = 25.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = -1.0f * 3.14159f * i / 100; 
        glVertex2f(a + mradse * cos(angle), b + mradse * sin(angle)); 
    }
    glEnd();
    }
void design(int n ,int m){
	 glColor3f(0.1f, 0.1f, 0.1f); // design
    float radse = 35.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = -1.0f * 3.14159f * i / 100; 
        glVertex2f(n + radse * cos(angle), m + radse * sin(angle)); 
    }
    glEnd();
}
void drawText(const char *text, int x, int y) {
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawCircle(float x, float y, float radius) {
    int numSegments = 100;  // Number of segments for smooth circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);  // Center of circle
    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * 3.14159f * float(i) / float(numSegments);
        float dx = radius * cos(angle);  // Fixed cosf to cos
        float dy = radius * sin(angle);  // Fixed sinf to sin
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void displayWelcome() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gradient Background
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.4f); glVertex2f(0, 0);               // Dark Blue
    glColor3f(0.0f, 0.5f, 1.0f); glVertex2f(screenWidth, 0);     // Light Blue
    glColor3f(0.0f, 0.3f, 0.8f); glVertex2f(screenWidth, screenHeight);
    glColor3f(0.0f, 0.1f, 0.4f); glVertex2f(0, screenHeight);
    glEnd();

    // Welcome Text
    glColor3f(1.0f, 1.0f, 1.0f); // White for text
    drawText("WELCOME Start new game!", screenWidth / 2 - 250, screenHeight / 2 + 50);
    drawText("press ENTER To sart", screenWidth / 2 - 120, screenHeight / 2);
    drawText("ESC To exit", screenWidth / 2 - 90, screenHeight / 2 - 50);

    // Decorative Circles
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    drawCircle(screenWidth / 2, screenHeight / 2 + 200, 80);
    glColor3f(0.8f, 0.8f, 0.2f); // Yellow
    drawCircle(screenWidth / 2 + 100, screenHeight / 2 - 150, 50);

    glutSwapBuffers();
}

void displayMenu() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gradient Background
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f); glVertex2f(0, 0);               // Gray
    glColor3f(0.4f, 0.4f, 0.4f); glVertex2f(screenWidth, 0);     // Lighter Gray
    glColor3f(0.6f, 0.6f, 0.6f); glVertex2f(screenWidth, screenHeight);
    glColor3f(0.2f, 0.2f, 0.2f); glVertex2f(0, screenHeight);
    glEnd();

    // Menu Text
    glColor3f(1.0f, 1.0f, 1.0f); // White for text
    drawText("Select level:", screenWidth / 2 - 150, screenHeight / 2 + 100);
    drawText("1. Easy ", screenWidth / 2 - 80, screenHeight / 2 + 50);
    drawText("2. Midium ", screenWidth / 2 - 80, screenHeight / 2 + 20);
    drawText("3. Hard ", screenWidth / 2 - 80, screenHeight / 2 - 10);
    drawText("1, 2, or 3 to select the level", screenWidth / 2 - 140, screenHeight / 2 - 60);
    drawText("ESC To Exit", screenWidth / 2 - 90, screenHeight / 2 - 100);

    // Decorative Rectangles
    glColor3f(0.0f, 0.7f, 0.5f); // Teal
    drawRectangle(50, 50, 100, 50);
    glColor3f(0.5f, 0.0f, 0.8f); // Purple
    drawRectangle(screenWidth - 150, 50, 100, 50);

    glutSwapBuffers();
}

void displayGame() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw racetrack
    glColor3f(0.2f, 0.2f, 0.2f); // Black for track
    drawRectangle(screenWidth / 4, 0, screenWidth / 2, 700);
    
    glColor3f(1.1f, 1.1f, 1.1f);// white lines
    glLineWidth(15);
    glBegin(GL_LINES);
     for (int i = 0; i < 700; i++) {
        glVertex2i(600, i);
        glVertex2i(610, i);
        i=i+80;
		 }
        	 glEnd(); 
			 
			 

    // Draw sideways
    glColor3f(0.0f, 0.5f, 0.0f); // Green for sidewalks
    drawRectangle(0, 0, screenWidth / 4, screenHeight);
    drawRectangle(screenWidth * 3 / 4, 0, screenWidth / 4, screenHeight);
   

    if (gameOver) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red for "Game Over"
        drawText("Game over!", screenWidth / 2 - 80, screenHeight / 2);
        drawText("press R to restart", screenWidth / 2 - 80, screenHeight / 2 - 30);
          drawText("esc To exit", screenWidth / 2 - 80, screenHeight / 2 - 70);
        glutSwapBuffers();
        return;
    }
    
    
   
    /* Draw the player's car
    glColor3f(0.0f, 0.0f, 0.0f);
      drawRectangle(carX-18, carY-5, carWidth-28, carHeight-18);
       drawRectangle(carX+15, carY-5, carWidth+1, carHeight-18);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    drawRectangle(carX-5, carY, carWidth+7, carHeight);
     glColor3f(0.0f, 0.5f, 1.0f);
     drawRectangle(carX-12, carY-15, carWidth+20, carHeight);
      glColor3f(1.0f, 0.0f, 1.0f); // Blue
    drawRectangle(carX-5, carY-10, carWidth+5, carHeight-5);
    */
    // Draw opponent cars
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    for (int i = 0; i < 2; i++) {
        drawRectangle(oppoX[i], oppoY[i], oppoWidth, oppoHeight);
    }
     glColor3f(0.0f, 0.5f, 0.0f); // sky
    glRecti(0,700,1200,850);
  glColor3f(0.5f, 0.25f, 0.0f);
   glRecti(40, 650, 1170, 760);
   glRecti(40, 760, 180, 800);
   glRecti(1030, 760, 1170, 800);
   glRecti(480, 760, 740, 830);
   glRecti(40, 400, 300, 760);
   glRecti(900, 400, 1170, 760);
   glColor3f(0.5f, 0.5f, 0.0f);
   glRecti(900, 400, 1030, 650);
   glRecti(170, 400, 300, 650);
   
    //design for the gate
    
   glColor3f(0.5f, 0.35f, 0.0f);
    glLineWidth(25);
    glBegin(GL_LINES);
    	glVertex2i(40, 650);
        glVertex2i(1170, 650);
        glEnd(); 
        
         glLineWidth(8);
    glBegin(GL_LINES);
    for (int i = 50; i < 175; i++) {
        glVertex2i(i, 400);
        glVertex2i(i, 650);
        i=i+20;
		 }
        	 glEnd(); 
        	 
        	  glBegin(GL_LINES);
    for (int i = 1045; i < 1165; i++) {
        glVertex2i(i, 400);
        glVertex2i(i, 650);
        i=i+20;
		 }
        	 glEnd(); 
    
    design(780,762);
    design(880,762);
     design(980,762);
     
     design(220,762);
    design(320,762);
     design(420,762);
     
    design(560,832);
     design(660,832);
     
    mindesign(70,800);
     mindesign(150,800);
     
    mindesign(1060,800);
     mindesign(1140,800);
     
      glColor3f(0.75f, 0.75f, 0.75f); // harar gate the left door
    float radse = 45.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(230 + radse * cos(angle), 560 + radse * sin(angle)); 
    }
    glEnd();
     
     glRecti(185, 400, 275, 565);
      glLineWidth(40);
    glBegin(GL_LINES);
        	glVertex2i(230, 380);
        	glVertex2i(230, 0);
        	glEnd(); 
     
      glColor3f(0.75f, 0.75f, 0.75f); // harar gate the right door
    float rradse = 45.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(960 + rradse * cos(angle), 560 + rradse * sin(angle)); 
    }
    glEnd();
    glRecti(915, 400, 1005, 565);
    glLineWidth(40);
    glBegin(GL_LINES);
        	glVertex2i(960, 380);
        	glVertex2i(960, 0);
        	glEnd(); 
     
      glColor3f(0.5f, 0.35f, 0.0f);
     glRecti(560, 690, 650, 770);// photo
      glColor3f(1.0f, 0.5f, 0.0f);
     glRecti(570, 700, 640, 760);
     
      	glLineWidth(15);
        	 glColor3f(0.75f, 0.75f, 0.0f);
        	 glBegin(GL_LINES);
        	glVertex2i(580, 745);
        	glVertex2i(630, 745);
        	glEnd(); 
        	 glColor3f(0.5f, 0.25f, 0.0f);
      float se = 15.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(605 + se * cos(angle), 730 + se * sin(angle)); 
    }
    glEnd();
    glLineWidth(10);
    glColor3f(0.75f, 0.75f, 0.0f);
    glBegin(GL_LINES);
        
        	glVertex2i(570, 700);
        	glVertex2i(640, 700);
        	glVertex2i(590, 710);
        	glVertex2i(620, 710);
        		glEnd(); 
        
     
     glColor3f(1.0f, 1.0f, 0.0f);
glRasterPos2i(540,670);
for(int i=0;i<17;i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,"Welcome To Harar"[i]);
glEnd();
  
     // In the displayGame function, replace the car drawing section with:
drawDetailedCar(carX, carY, carWidth, carHeight);
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(100, 160);
        	glVertex2i(100, 230);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(100, 180);
        	glVertex2i(130, 190);
        		glVertex2i(100, 190);
        	glVertex2i(70, 200);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float tree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(100 + tree * cos(angle), 230 + tree * sin(angle));
		 }
        glEnd(); 
        float treel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(130 + treel1 * cos(angle), 190 + treel1 * sin(angle));
		 }
        glEnd(); 
        float treel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(70 + treel2 * cos(angle), 200 + treel2 * sin(angle));
		 }
        glEnd(); 
        
        
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 160);
        	glVertex2i(1150, 230);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 180);
        	glVertex2i(1180, 190);
        		glVertex2i(1150, 190);
        	glVertex2i(1120, 200);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float ltree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1150 + ltree * cos(angle), 230 + ltree * sin(angle));
		 }
        glEnd(); 
        float ltreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1180 + ltreel1 * cos(angle), 190 + ltreel1 * sin(angle));
		 }
        glEnd(); 
        float ltreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1120 + ltreel2 * cos(angle), 200 + ltreel2 * sin(angle));
		 }
        glEnd(); 
       
    //* Display score and level
    glColor3f(1.0f, 1.0f, 1.0f); // White
    char scoreStr[50];
    itoa(score, scoreStr, 10); // Convert score to string
    strcat(scoreStr, " Score: ");
    drawText(scoreStr, 10, screenHeight - 20);

    char levelStr[50];
    if (level == 2) strcpy(levelStr,"Level: Easy ");
    else if (level == 3) strcpy(levelStr, "Level: Medium                                                                      CONGRAGULATION          YOU ARE IN LEVEL 2");
    else if (level == 4) strcpy(levelStr, "Level: HARD                                                                         CONGRAGULATION          YOU ARE IN LEVEL 3");
    else if (level == 5) strcpy(levelStr, "Level: very Hard                                                                   CONGRAGULATION          YOU ARE IN LEVEL 4");
    else if (level == 6) strcpy(levelStr, "Level: difficulty                                                                  CONGRAGULATION          YOU ARE IN LEVEL 5");
    else if (level == 7) strcpy(levelStr, "Level: very difficulty                                                             CONGRAGULATION          YOU ARE IN LEVEL 6");
    drawText(levelStr, 10, screenHeight - 40);

    glutSwapBuffers();
}


void update(int value) {
    if (!gameOver) {
        int speed = (level == 2) ? 5 : (level == 3) ? 7 : 10; // Adjust speed based on level
        for (int i = 0; i < 2; ++i) {
            oppoY[i] -= speed;
            if (oppoY[i] < 0) {
                oppoY[i] = screenHeight;
                oppoX[i] = rand() % (screenWidth / 2 - oppoWidth) + screenWidth / 4;
                score++;
            }
        }
//         if (score==5) {
//        glColor3f(1.0f, 0.0f, 0.0f); 
//        drawText("level 2", screenWidth / 2 - 80, screenHeight / 2);
//       
//    }

  if ( score == 5){
    score++;
    level=3; 

   }
   if ( score == 10){
   	score++;
    level=4; 	
   }
   if ( score == 15){
   	score++;
    level=5; 	
   }
   if ( score == 20){
   	score++;
    level=6; 	
   }
   if ( score == 25){
   	score++;
    level=7; 	
   }
    
  


     
	    // Collision detection
        for (int i = 0; i < 2; ++i) {
            if (carX < oppoX[i] + oppoWidth && carX + carWidth > oppoX[i] &&
                carY < oppoY[i] + oppoHeight && carY + carHeight > oppoY[i]) {
                gameOver = true;
            }
        }

        glutPostRedisplay();
        glutTimerFunc(30, update, 0);
    }
   
}

void handleKeypress(unsigned char key, int x, int y) {
    if (welcomeScreen && (key == 13)) { // Enter key
        welcomeScreen = false;
        level = 1;
        glutDisplayFunc(displayMenu);
        glutPostRedisplay();
        return;
    }

    if (gameOver && (key == 'r' || key == 'R')) {
        gameOver = false;
        score = 0;
        oppoY[0] = screenHeight;
        oppoY[1] = screenHeight + 200;
        glutPostRedisplay();
        glutTimerFunc(30, update, 0);
    }
    if (key ==  27) {
            exit(0);
            
			}
    if (level == 1) {
        if (key == '1') level = 2;
        else if (key == '2') level = 3;
        else if (key == '3') level = 4;

        if (level > 1) {
            oppoX[0] = rand() % (screenWidth / 2 - oppoWidth) + screenWidth / 4;
            oppoX[1] = rand() % (screenWidth / 2 - oppoWidth) + screenWidth / 4;
            glutDisplayFunc(displayGame);
            glutTimerFunc(30, update, 0);
        }
    }
}

void handleSpecialKeypress(int key, int x, int y) {
    if (!gameOver) {
        if (key == GLUT_KEY_LEFT && carX > screenWidth / 4) {
            carX -= 10;
        } else if (key == GLUT_KEY_RIGHT && carX < screenWidth * 3 / 4 - carWidth) {
            carX += 10;
        }
         else if (key == GLUT_KEY_DOWN ) {
            carY -= 10;
        }
         else if (key == GLUT_KEY_UP && carY< 550 ) {
            carY += 10;
        }

			
        glutPostRedisplay();
    }

}

int main(int argc, char **argv) {
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Car Racing Game");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, screenWidth, 0, screenHeight);

    glutDisplayFunc(displayWelcome);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);

    glutMainLoop();
    return 0;
}
