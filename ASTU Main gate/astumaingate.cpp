
#include <GL/glut.h>
#include <cmath>
 

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP); // Draw a line loop
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments); // Calculate the angle
        float x = r * cosf(theta); // Calculate x
        float y = r * sinf(theta); // Calculate y
        glVertex2f(x + cx, y + cy); // Output vertex
    }
    glEnd();
}

// Background image dimensions
int backgroundWidth = 1500;
int backgroundHeight = 1000;
// Wheel position
float wheelPositionX = backgroundWidth ;
float wheelPositionY = backgroundHeight;
// Wheel Angle
float wheelAngle = 0.0f;
// Car position
int carX = 600+200;
// Animation update rate (milliseconds)
const int animationUpdateRate = 10;

void drawCar(int increase_height){

    glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(carX, 200, 0);
    glScalef(2, 1, 1);

    // Draw car body
    glBegin(GL_POLYGON);
    glVertex2f(-60, -30+increase_height);
    glVertex2f(-60, 20+increase_height);
    glVertex2f(70, 20+increase_height);
    glVertex2f(70, -30+increase_height);
    glEnd();

    int adjustcockpit= 10;
    glBegin(GL_POLYGON);
    glVertex2f(-35-adjustcockpit, 25+increase_height-adjustcockpit);//A
    glVertex2f(-18-adjustcockpit, 55+increase_height+adjustcockpit);//B
    glVertex2f(-5 , 55+increase_height+adjustcockpit); //C
    glVertex2f(-5 + adjustcockpit, 25+increase_height-adjustcockpit); //D
    glEnd();

    // Draw car window 1
    //glColor3f(0.698, 0.745, 0.71); // Ash gray color
    //glColor4f(1.0f, 0.5f, 0.0f, 0.0f);//orange/brown
    glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glBegin(GL_POLYGON);
    glVertex2f(-35, 25+increase_height-adjustcockpit/2);
    glVertex2f(-22-1, 55+increase_height);
    glVertex2f(-8, 55+increase_height);
    glVertex2f(-8, 25+increase_height-adjustcockpit/2);
    glEnd();

    // Draw car wheels
    glColor3f(0.0, 0.0, 0.0);
    const float wheelRadius = 20.0f;
    const int numTriangles = 8;
    const float angleIncrement = 2.0f * M_PI / numTriangles;

    for (int i = 0; i < numTriangles; ++i)
    {
        const float angle1 = i * angleIncrement + wheelAngle;
        const float angle2 = (i + 1) * angleIncrement + wheelAngle;

        glBegin(GL_TRIANGLES);
        glVertex2f(-30 + wheelRadius * cos(angle1), increase_height-30 + wheelRadius * sin(angle1));
        glVertex2f(-30 + wheelRadius * cos(angle2),increase_height -30 + wheelRadius * sin(angle2));
        glVertex2f(-30, -30+increase_height);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(30 + wheelRadius * cos(angle1), increase_height -30 + wheelRadius * sin(angle1));
        glVertex2f(30 + wheelRadius * cos(angle2), increase_height-30 + wheelRadius * sin(angle2));
        glVertex2f(30, -30+increase_height);
        glEnd();
    }
    glPopMatrix();
}




void update(int value){
    // Update wheel position
    wheelPositionX += 1.7; // Move 5 pixels to the right
    wheelPositionY += .5; // Move 5 pixels upward

    // Check if the wheel has reached the top-right corner
    if (wheelPositionX > backgroundWidth && wheelPositionY > backgroundHeight) {
        wheelPositionX = backgroundWidth-1380; // Reset X position to the left-middle
        wheelPositionY = backgroundHeight-150; // Reset Y position to the middle
    }

    // Rotate Wheel
    wheelAngle = wheelAngle - 0.4f;
    // Move the car horizontally
    carX = carX - 2;
    // Reset the positions when they reach the end of the screen
    if (carX < backgroundWidth -1600)
        carX = 1600;

    // Request redrawing of the scene
    glutPostRedisplay();
    // Schedule the next update
    glutTimerFunc(animationUpdateRate, update, 0);

    // Redraw the scene
    glutPostRedisplay();
}


void render2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the wheel
    //drawWheel();

    glutSwapBuffers();
}


 

const float PI = 3.1415926;
void gate(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	glLoadIdentity();	
    gluOrtho2D(0.0, 1500.0, 0.0, 1000.0);
    glColor3f(0.0, 0.5, 1.0);
       int increase_height= 50;
     glRecti(0, 0, 1500, 1000);
     
     
				           glLineWidth(15.0f);
		glBegin(GL_LINES);               //screen
		 glColor3f(0.0, 0.0, 0.0);
		    glVertex2i(100, 420);
		  glVertex2i(100, 480);
		   glEnd();
		    glRecti(40, 500, 160, 580); 
		     glColor3f(1.0, 1.0, 0.5);
		     glRecti(50, 510, 150, 570);
			  
		     glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2i(60,540);
for(int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15," A S T U "[i]);
glEnd();
  
     
     glColor3f(0.5, 0.25, 0.0);//fence
     glRecti(0, 400, 280, 500);
     glRecti(1220, 400, 1500, 500);
    
       
 glLineWidth(4.0f);//fence
 glBegin(GL_LINES);
       glColor3f(1.0, 0.0, 0.0);	
         for (int i = 0; i < 1500;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	glColor3f(1.0, 0.5, 0.0);//fence
         for (int i = 25; i < 1500;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	
    glColor3f(1.0, 0.0, 0.0);
        glVertex2i(0, 515);
        glVertex2i(1500, 515);
        
    glEnd();
    
      
     float radiusX= 500;//astu gate first ellips
     float radiusY =400;
     int num_segments = 100;
     glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = radiusX*cosf(theta);
     	float y = radiusY*sinf(theta);
     	glVertex2f(750+x, 400+y);
	 } glEnd();
	 
	 
	 
	 float rradiusX= 480;// astu gate second ellips
     float rradiusY =380;
     int nnum_segments = 100;
     glBegin(GL_POLYGON);
     glColor3f(0.0,0.7,1.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = rradiusX*cosf(theta);
     	float y = rradiusY*sinf(theta);
     	glVertex2f(750+x, 400+y);
	 } glEnd();
	
    
    glColor3f(0.0f, 0.5f, 1.0f); // astu gate the center door
    float radise = 75.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(620 + radise * cos(angle), 500 + radise * sin(angle)); 
    }
    glEnd();
    glColor3f(0.0f, 0.5f, 1.0f); // astu gate the center door
    float radse = 75.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(830 + radse * cos(angle), 500 + radse * sin(angle)); 
    }
    glEnd();
     glColor3f(0.0f, 0.5f, 1.0f); // astu gate the left door
    float rase = 50.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(450 + rase * cos(angle), 430 + rase * sin(angle)); 
    }
    glEnd();
    glColor3f(0.0f, 0.5f, 1.0f); // astu gate the right door
    float rdse = 50.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(1000 + rdse * cos(angle), 430 + rdse * sin(angle)); 
    }
    glEnd();
      glColor3f(0.0, 0.5, 0.0);
     glRecti(400, 400, 480, 430);
    glColor3f(0.0, 0.5, 1.0);
    glRecti(545, 400, 695, 505);
    glRecti(755, 400, 905, 505);
    glRecti(400, 400, 500, 435);
    glRecti(950, 400, 1050, 435);
    
     glColor3f(0.7f, 0.0f, 0.0f); // astu logo
    float lradse = 30.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 500; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(730 + lradse * cos(angle), 600 + lradse * sin(angle)); 
    }
     glEnd();
       glColor3f(0.8f, 0.8f, 0.8f); // astu logo
    float llradse = 23.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(730 + llradse * cos(angle), 600 + llradse * sin(angle)); 
    }
     glEnd();
      glColor3f(0.0f, 0.5f, 1.0f); // astu logo
    float llllradse = 22.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = -1.0f * 3.14159f * i / 100; 
        glVertex2f(730 + llllradse * cos(angle), 595 + llllradse * sin(angle)); 
    }
     glEnd();
     
      glColor3f(0.0f, 0.5f, 0.0f); // astu logo
    float lllradse = 13.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(730 + lllradse * cos(angle), 600 + lllradse * sin(angle)); 
    }
     glEnd();
     
     
      glColor3f(0.5f, 0.0f, 0.0f);//astu logo
     glRecti(720, 590, 740, 600);
     glColor3f(1.0f, 1.0f, 1.0f);
      glRecti(722, 594, 738, 600);
  
   glLineWidth(85.0f);
         glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(545, 430);
        	glVertex2i(695, 430);
        		glVertex2i(755, 430);
        	glVertex2i(905, 430);
        		glVertex2i(400, 420);
        	glVertex2i(500, 420);
        		glVertex2i(950, 420);
        	glVertex2i(1050, 420);
        	glEnd(); 
     glColor3f(0.2, 0.2, 0.2);
     glRecti(0, 0, 1500, 420);
     
    glColor3f(0.2, 0.2, 0.2);
    glRecti(545, 350, 695, 420);//roads
    glRecti(755, 350, 905, 420);
     glRecti(0, 100, 1500, 350);
    
    glLineWidth(25.0f);
 glBegin(GL_LINES);//road white lines
 glColor3f(1.0, 1.0, 1.0);
 for (int i = 0; i < 1500;i++ ){
  glVertex2i(i, 225);
  glVertex2i(i, 235);
  i=i+150;
 }
   glEnd();
       glColor3f(0.0, 0.5, 0.0);//grass
    glRecti(0, 350, 545, 420); 
     glRecti(905, 350, 1500, 420);
	 glRecti(0, 0, 1500, 100);
	  
	      glBegin(GL_POLYGON);//inside grass
   glColor3f(0.0, 0.5, 0.0);
            glVertex2i(935, 400);
        	glVertex2i(970, 450);
        	glVertex2i(1020, 450);
        	glVertex2i(1060, 400);
        		glEnd();
        		 glBegin(GL_POLYGON);//inside grass
   glColor3f(0.0, 0.5, 0.0);
            glVertex2i(390, 400);
        	glVertex2i(425, 450);
        	glVertex2i(475, 450);
        	glVertex2i(510, 400);
        		glEnd();
        		 glBegin(GL_POLYGON);
        	glColor3f(0.3, 0.3, 0.3);//walk road
        	 glVertex2i(970, 385);
        	 glVertex2i(990, 450);
           glVertex2i(1000, 450);
         glVertex2i(1020, 385);
         
          
 glEnd();
  glBegin(GL_POLYGON);
        	glColor3f(0.3, 0.3, 0.3);//walk road
  
  glVertex2i(425, 385);
  glVertex2i(445, 450);
  glVertex2i(455, 450);
   glVertex2i(475, 385);
  
  glEnd();
  
  
       glLineWidth(25.0f);
       
 glBegin(GL_LINES);
	glColor3f(0.3, 0.3, 0.3);//walk road
  glVertex2i(0, 385);
  glVertex2i(545, 385);
  glVertex2i(905, 385);
  glVertex2i(1500, 385);
  glVertex2i(0, 70);
  glVertex2i(1500, 70);
  glEnd();
  
      glLineWidth(10.0f);
glBegin(GL_LINES);//zebra
 glColor3f(1.0, 1.0, 1.0);
  for (int i =110 ; i < 350;i++ ){
  glVertex2i(370, i);
  glVertex2i(420, i);
  i=i+20;
 }
   glEnd();
   
     glLineWidth(15.0f);
glBegin(GL_LINES);//traffic
 glColor3f(0.0, 0.0, 0.0);
    glVertex2i(50, 330);
  glVertex2i(50, 450);
   glEnd();
    glLineWidth(35.0f);
glBegin(GL_LINES);//traffic
 glColor3f(0.0, 0.0, 0.0);
   glVertex2i(50, 440);
  glVertex2i(50, 500);
   glEnd();
   
    glColor3f(0.0f, 1.0f, 0.0f); // green color
    float r = 5.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(50 + r * cos(angle), 485 + r * sin(angle));
		 }
        glEnd(); 
        glColor3f(1.0f, 1.0f, 0.0f); // yellow color
    float rr = 5.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(50 +rr * cos(angle), 470 + rr * sin(angle));
		 }
        glEnd(); 
        glColor3f(1.0f, 0.0f, 0.0f); // red color
    float rrr = 5.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(50 + rrr * cos(angle), 455 + rrr * sin(angle));
		 }
        glEnd(); 
         glLineWidth(15.0f);
glBegin(GL_LINES);//traffic
 glColor3f(0.0, 0.0, 0.0);
    glVertex2i(130, 330);
  glVertex2i(130, 440);
   glEnd();
   glColor3f(1.0f, 0.0f, 0.0f); // n redcolor
    float tr = 30.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(130 + tr * cos(angle), 445 + tr * sin(angle));
		 }
     glEnd();
     glColor3f(0.5f, 0.6f, 0.5f); // n whitecolor
    float trr = 25.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(130 + trr * cos(angle), 445 + trr * sin(angle));
		 }
     glEnd();
      glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2i(113,440);
for(int i=0;i<5;i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15," 30 "[i]);
glEnd();
        
       
       
         glColor3f(1.0f, 0.5f, 0.0f); // sun
    float sun = 150.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(100 + sun * cos(angle), 1000 + sun * sin(angle));
		 }
        glEnd(); 
        
        
		     
        
         glColor3f(0.0, 0.5, 0.0);
    glRecti(545, 420, 695, 480);//inside grass
    glRecti(755, 420, 905, 480);//inside grass
    
        glBegin(GL_POLYGON);//in road
    glColor3f(0.2,0.2,0.2);
            glVertex2i(550, 400);
        	glVertex2i(590, 490);
        	glVertex2i(650, 490);
        	glVertex2i(695, 400);
        		glEnd();
        
        	 glBegin(GL_POLYGON);
        	glVertex2i(750, 400);
        	glVertex2i(799, 490);
        	glVertex2i(850, 490);
        	glVertex2i(905, 400);
        	glEnd();
        	glLineWidth(8.0f);
        	 glBegin(GL_LINES);//inside white line
    glColor3f(1.0,1.0,1.0);
            glVertex2i(622, 420);
        	glVertex2i(622, 440);
        	glVertex2i(622, 460);
        	glVertex2i(622, 470);
        	glVertex2i(622, 480);
        	glVertex2i(622, 487);
        	
        	 glVertex2i(827, 420);
        	glVertex2i(827, 440);
        	glVertex2i(827, 460);
        	glVertex2i(827, 470);
        	glVertex2i(827, 480);
        	glVertex2i(827, 487);
        		glEnd();
        
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 360);
        	glVertex2i(1150, 430);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 380);
        	glVertex2i(1180, 390);
        		glVertex2i(1150, 390);
        	glVertex2i(1120, 400);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float tree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1150 + tree * cos(angle), 430 + tree * sin(angle));
		 }
        glEnd(); 
        float treel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1180 + treel1 * cos(angle), 390 + treel1 * sin(angle));
		 }
        glEnd(); 
        float treel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1120 + treel2 * cos(angle), 400 + treel2 * sin(angle));
		 }
        glEnd(); 
        
        
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1350, 360);
        	glVertex2i(1350, 430);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1350, 380);
        	glVertex2i(1380, 390);
        		glVertex2i(1350, 390);
        	glVertex2i(1320, 400);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float ttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1350 + ttree * cos(angle), 430 + ttree * sin(angle));
		 }
        glEnd(); 
        float ttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1380 + ttreel1 * cos(angle), 390 + ttreel1 * sin(angle));
		 }
        glEnd(); 
        float ttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1320 + ttreel2 * cos(angle), 400 + ttreel2 * sin(angle));
        
		 }
        glEnd(); 
       glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 30);
        	glVertex2i(1150, 100);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1150, 50);
        	glVertex2i(1180, 60);
        		glVertex2i(1150, 60);
        	glVertex2i(1120, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float dtree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1150 + dtree * cos(angle), 100 + dtree * sin(angle));
		 }
        glEnd(); 
        float dtreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1180 + dtreel1 * cos(angle), 60 + dtreel1 * sin(angle));
		 }
        glEnd(); 
        float dtreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1120 + dtreel2 * cos(angle), 70 + dtreel2 * sin(angle));
		 }
        glEnd(); 
        
        
        
        
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1350, 30);
        	glVertex2i(1350, 100);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(1350, 50);
        	glVertex2i(1380, 60);
        		glVertex2i(1350, 60);
        	glVertex2i(1320, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float dttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1350 + dttree * cos(angle), 100 + dttree * sin(angle));
		 }
        glEnd(); 
        float dttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1380 + dttreel1 * cos(angle), 60 + dttreel1 * sin(angle));
		 }
        glEnd(); 
        float dttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1320 + dttreel2 * cos(angle), 70 + dttreel2 * sin(angle));
		 }
        glEnd(); 
        
        
        
         glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(350, 30);
        	glVertex2i(350, 100);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(350, 50);
        	glVertex2i(380, 60);
        	glVertex2i(350, 60);
        	glVertex2i(320, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float dtttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(350 + dtttree * cos(angle), 100 + dtttree * sin(angle));
		 }
        glEnd(); 
        float dtttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(380 + dtttreel1 * cos(angle), 60 + dtttreel1 * sin(angle));
		 }
        glEnd(); 
        float dtttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(320 + dtttreel2 * cos(angle), 70 + dtttreel2 * sin(angle));
		 }
        glEnd(); 
        
          glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(550, 30);
        	glVertex2i(550, 100);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(550, 50);
        	glVertex2i(580, 60);
        	glVertex2i(550, 60);
        	glVertex2i(520, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float adtttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(550 + adtttree * cos(angle), 100 + adtttree * sin(angle));
		 }
        glEnd(); 
        float adtttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(580 + adtttreel1 * cos(angle), 60 + adtttreel1 * sin(angle));
		 }
        glEnd(); 
        float adtttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(520 + adtttreel2 * cos(angle), 70 + adtttreel2 * sin(angle));
		 }
        glEnd(); 
        
          glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(850, 30);
        	glVertex2i(850, 100);
        	glEnd();
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(850, 50);
        	glVertex2i(880, 60);
        	glVertex2i(850, 60);
        	glVertex2i(820, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float aadtttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(850 + aadtttree * cos(angle), 100 + aadtttree * sin(angle));
		 }
        glEnd(); 
        float aadtttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(880 + aadtttreel1 * cos(angle), 60 + aadtttreel1 * sin(angle));
		 }
        glEnd(); 
        float aadtttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(820 + aadtttreel2 * cos(angle), 70 + aadtttreel2 * sin(angle));
		 }
        glEnd(); 
        
          glLineWidth(25.0f);//tree
         glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(150, 30);
        	glVertex2i(150, 100);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(150, 50);
        	glVertex2i(180, 60);
        	glVertex2i(150, 60);
        	glVertex2i(120, 70);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float tdtttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(150 + tdtttree * cos(angle), 100 + tdtttree * sin(angle));
		 }
        glEnd(); 
        float dtttreel3= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(180 + dtttreel3 * cos(angle), 60 + dtttreel3 * sin(angle));
		 }
        glEnd(); 
        float ddtttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(120 + ddtttreel2 * cos(angle), 70 + ddtttreel2 * sin(angle));
		 }
        glEnd(); 
            drawCar(increase_height+60);
        

glColor3f(1.0f, 1.0f, 0.0f);
glRasterPos2i(560,650);
for(int i=0;i<40;i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,"A          S           T           U         "[i]);
glEnd();
  
   glFlush();
}


 

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1500, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("astugate");
	glutDisplayFunc(gate);
	 glutTimerFunc(animationUpdateRate, update, 0);
	glutMainLoop();
	return 0;
}

