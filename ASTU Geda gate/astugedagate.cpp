#include <GL/glut.h>
#include <cmath>
 
// Background image dimensions
int backgroundWidth = 1280;
int backgroundHeight = 720;
// Wheel position
float wheelPositionX = backgroundWidth ;
float wheelPositionY = backgroundHeight;
// Wheel Angle
float wheelAngle = 0.0f;
// Car position
int carX = 1500+200;
// Animation update rate (milliseconds)
const int animationUpdateRate = 10;

void drawCar(int increase_height){

    glColor4f(0.0f, 0.0f, 1.0f, 0.0f);//yellow
    glPushMatrix();
    glTranslatef(carX, 100, 0);
    glScalef(2, 1, 1);

    // Draw car body
    glBegin(GL_POLYGON);
    glVertex2f(-60, -30+increase_height);
    glVertex2f(-60, 20+increase_height);
    glVertex2f(70, 20+increase_height);
    glVertex2f(70, -30+increase_height);
    glEnd();

    int adjustcockpit= 10;
    glBegin(GL_POLYGON);//the following points should be rotating clockwise
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
        carX = 1500;

    // Request redrawing of the scene
    glutPostRedisplay();
    // Schedule the next update
    glutTimerFunc(animationUpdateRate, update, 0);

    // Redraw the scene
    glutPostRedisplay();
}

/*
void render2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the wheel
    //drawWheel();

    glutSwapBuffers();
}

*/
 
			
			
 
const float PI = 3.1415926;
void gate(void){
	 int increase_height= 50;
    int moveobject = 300; 
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	glLoadIdentity();	
    gluOrtho2D(0.0, 1500.0, 0.0, 1000.0);
    glColor3f(0.0, 0.5, 1.0);
     glRecti(0, 0, 1500, 1000);
     
     
     glColor3f(0.0, 0.5, 0.0);//grass
    glRecti(0, 350, 1500, 480); 
     
     glColor3f(0.5, 0.25, 0.0);//fence
     glRecti(0, 400, 330, 500);
     glRecti(1200, 400, 1500, 500);
       
 glLineWidth(4.0f);//fence
 glBegin(GL_LINES);
       glColor3f(1.0, 0.0, 0.0);	
         for (int i = 0; i < 330;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	glColor3f(1.0, 0.5, 0.0);//fence
         for (int i = 25; i < 330;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	
    glColor3f(1.0, 0.0, 0.0);
        glVertex2i(0, 515);
        glVertex2i(330, 515);
        
    glEnd();
    
    glLineWidth(4.0f);//fence
 glBegin(GL_LINES);
       glColor3f(1.0, 0.0, 0.0);	
         for (int i =1200 ; i < 1500;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	glColor3f(1.0, 0.5, 0.0);//fence
         for (int i = 1225; i < 1500;i++ ){
        glVertex2i(i,500 );
        glVertex2i(i, 515);	
         i=i+50;
	}
	
    glColor3f(1.0, 0.0, 0.0);
        glVertex2i(1200, 515);
        glVertex2i(1500, 515);
        
    glEnd();
    
      
    
	  glLineWidth(40.0f);
    float radiusX= 320;//astu gate first ellips
     float radiusY =330;
     int num_segments = 100;
     glBegin(GL_LINE_LOOP);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = radiusX*cosf(theta);
     	float y = radiusY*sinf(theta);
     	glVertex2f(650+x, 400+y);
	 } glEnd();
	 
	  

    float rrradiusX= 150;//astu gate left door out
     float rrradiusY =150;
     int rrnum_segments = 100;
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = rrradiusX*cosf(theta);
     	float y = rrradiusY*sinf(theta);
     	glVertex2f(445+x, 400+y);
	 } glEnd();
	 
   glColor3f(0.5f, 0.25f, 0.0f); // astu gate the left door
    float rase = 130.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(445 + rase * cos(angle), 400 + rase * sin(angle)); 
    }
     glEnd();
     
    float irrradiusX= 60;//astu gate left door in
     float irrradiusY =95;
     int irrnum_segments = 100;
     glBegin(GL_POLYGON);
     glColor3f(0.0,0.5,1.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = irrradiusX*cosf(theta);
     	float y = irrradiusY*sinf(theta);
     	glVertex2f(515+x, 400+y);
	 } glEnd();
	 glLineWidth(5.0f);
	 float inrrradiusX= 60;//astu gate left door in ellips
     float inrrradiusY =95;
     int inrrnum_segments = 100;
     glBegin(GL_LINE_STRIP);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = inrrradiusX*cosf(theta);
     	float y = inrrradiusY*sinf(theta);
     	glVertex2f(515+x, 400+y);
	 } glEnd();
   
    float diusX= 150;//astu gate right door out
     float diusY =150;
     int um_segments = 100;
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = diusX*cosf(theta);
     	float y = diusY*sinf(theta);
     	glVertex2f(1100+x, 400+y);
	 } glEnd();
    glColor3f(0.5f, 0.25f, 0.0f); // astu gate the right door
    float rrase = 130.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(1100 + rrase * cos(angle), 400 + rrase * sin(angle)); 
    }
    glEnd();
    float idiusX= 65;//astu gate right door in
     float idiusY =90;
     int ium_segments = 100;
     glBegin(GL_POLYGON);
     glColor3f(0.0,0.5,1.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = idiusX*cosf(theta);
     	float y = idiusY*sinf(theta);
     	glVertex2f(1035+x, 400+y);
	 } glEnd();
	 float iidiusX= 65;//astu gate right door in
     float iidiusY =90;
     int iium_segments = 100;
     glBegin(GL_LINE_STRIP);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = iidiusX*cosf(theta);
     	float y = iidiusY*sinf(theta);
     	glVertex2f(1035+x, 400+y);
	 } glEnd();
     
	 glLineWidth(40.0f);
    float rradiusX= 330;//astu gate second MAIN ellips
     float rradiusY =400;
     int rnum_segments = 150;
     glBegin(GL_LINE_STRIP);
     glColor3f(1.0,0.6,0.0);
     for (int i =0 ; i<=180;i++){
     	float theta =2.0f*PI*float(i)/360;
     	float x = rradiusX*cosf(theta);
     	float y = rradiusY*sinf(theta);
     	glVertex2f(780+x, 400+y);
	 } glEnd();
	 
	  
       
	  glLineWidth(20.0f);//the door lines
	 glBegin(GL_LINES);
        	glVertex2i(815, 690);
        	glVertex2i(895, 770);
        	
        	glVertex2i(750, 699);
        	glVertex2i(820, 790);
        	
        	glVertex2i(680, 710);
        	glVertex2i(739, 810);
        	
        	glVertex2i(865, 650);
        	glVertex2i(950, 735);
        	
        	glVertex2i(895, 600);
        	glVertex2i(1015, 690);
        	
        	glVertex2i(945, 520);
        	glVertex2i(1060, 605);
        	glEnd();
			 glColor3f(0.0,0.0,0.0);
        	glRecti(405, 350, 1090, 420);
        	
        	
        	//fixing the line
        	glColor3f(1.0,0.6,0.0);
        	 glPointSize(20.0f);
        	 glBegin(GL_POINTS);
        	 
        	 	glVertex2i(545, 690);
        	 	
        	 		glEnd();
        	 	 	glColor3f(1.0,0.6,0.0);
    float rr = 15.0f;
    glBegin(GL_POLYGON);//fixing the line
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1007 +rr * cos(angle), 688 + rr * sin(angle));
		 }
        glEnd();
		float frr = 10.0f;
    glBegin(GL_POLYGON);//fixing the line
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(895 +frr * cos(angle), 620 + frr * sin(angle));
		 }
        glEnd(); 
        	float ffrr = 14.0f;
    glBegin(GL_POLYGON);//fixing the line
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(411 +ffrr * cos(angle), 619 + ffrr * sin(angle));
		 }
        glEnd(); 
   
    // glColor3f(1.0, 1.0, 0.5);//window
	  //glRecti(1130, 470, 1160, 490);
     //glRecti(1200, 400, 1500, 500);
     
    glColor3f(0.2, 0.2, 0.2);// main road
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
       glRecti(0, 350, 655, 420); 
       glRecti(905, 350, 1500, 420);
	   glRecti(0, 0, 1500, 100);
	  glRecti(468, 400, 563, 450);// in grass
	   glRecti(985, 400, 1088, 450);// in grass
	 
       glLineWidth(20.0f);
  glBegin(GL_LINES);
 	glColor3f(0.3, 0.3, 0.3);//walk road
  glVertex2i(0, 385);
  glVertex2i(540, 385);
  glVertex2i(1000, 385);
  glVertex2i(1500, 385);
  glVertex2i(0, 60);// the lower one
  glVertex2i(1500, 60);
  
 
	  glEnd();
       glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);//walk road left door inside
 glVertex2i(475, 425);
  glVertex2i(500, 450);
  glVertex2i(520, 450);
  glVertex2i(540, 425);
    glEnd();
    
 
 glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);//walk road right door inside
 glVertex2i(1005, 425);
  glVertex2i(1035, 450);
  glVertex2i(1045, 450);
  glVertex2i(1070, 425);
    glEnd();
    
    
    
 glColor3f(0.2,0.2,0.2);// door road
   // glRecti(605, 350, 920, 450);
     glBegin(GL_POLYGON);
	glVertex2i(500, 350);
  glVertex2i(720, 485);
  glVertex2i(800, 485);
  glVertex2i(1050, 350);
  glEnd();
   glLineWidth(8.0f);
  glBegin(GL_LINES);
 glColor3f(1.0, 1.0, 1.0);//door rood white line
  glVertex2i(765, 385);
  glVertex2i(765, 405);
   glVertex2i(765, 425);
  glVertex2i(765, 440);
  glVertex2i(765, 455);
  glVertex2i(765, 465);
   glVertex2i(765, 475);
  glVertex2i(765, 480);
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
    float rr1 = 5.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(50 +rr1 * cos(angle), 470 + rr1 * sin(angle));
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
        
       
       
         glColor3f(1.5f, 1.0f, 0.0f); // sun
    float sun = 150.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(100 + sun * cos(angle), 1000 + sun * sin(angle));
		 }
        glEnd(); 
        
        
          glLineWidth(15.0f);
glBegin(GL_LINES);               //screen
 glColor3f(0.0, 0.0, 0.0);
    glVertex2i(1400, 420);
  glVertex2i(1400, 480);
   glEnd();
    glRecti(1350, 480, 1450, 560); 
     glColor3f(1.0, 1.0, 0.5);
     glRecti(1360, 490, 1440, 550); 
     
     glColor3f(0.0f, 0.0f, 1.0f);
glRasterPos2i(1380,520);
for(int i=0;i<5;i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,"ASTU"[i]);
glEnd();
     
     
        //trees
    
        
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
        	glVertex2i(350, 360);
        	glVertex2i(350, 430);
        	glEnd(); 
        	 glLineWidth(10.0f);
        	  glColor3f(0.5f, 0.25f, 0.0f);
glBegin(GL_LINES);
        	glVertex2i(350, 380);
        	glVertex2i(380, 390);
        		glVertex2i(350, 390);
        	glVertex2i(320, 400);
        
        	 glEnd(); 
        	 glColor3f(0.0f, 0.25f, 0.0f);
        	 float tttree = 30.0f;
    glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(350 + tttree * cos(angle), 430 + tttree * sin(angle));
		 }
        glEnd(); 
        float tttreel1= 15.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(380 + tttreel1 * cos(angle), 390 + tttreel1 * sin(angle));
		 }
        glEnd(); 
        float tttreel2 = 12.0f;
         glBegin(GL_POLYGON);// tree leaves
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(320 + tttreel2 * cos(angle), 400 + tttreel2 * sin(angle));
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
        
        
        
        
        
        // astu logo
          glColor3f(0.7f, 0.0f, 0.0f); // astu logo
    float lradse = 30.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 500; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1160 + lradse * cos(angle), 460 + lradse * sin(angle)); 
    }
     glEnd();
       glColor3f(0.8f, 0.8f, 0.8f); // astu logo
    float llradse = 23.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100; 
        glVertex2f(1160 + llradse * cos(angle), 460 + llradse * sin(angle)); 
    }
     glEnd();
      glColor3f(0.0f, 0.5f, 1.0f); // astu logo
    float llllradse = 22.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = -1.0f * 3.14159f * i / 100; 
        glVertex2f(1160 + llllradse * cos(angle), 455 + llllradse * sin(angle)); 
    }
     glEnd();
     
      glColor3f(0.0f, 0.5f, 0.0f); // astu logo
    float lllradse = 13.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 1.0f * 3.14159f * i / 100; 
        glVertex2f(1160 + lllradse * cos(angle), 460 + lllradse * sin(angle)); 
    }
     glEnd();
     
     
      glColor3f(0.5f, 0.0f, 0.0f);//astu logo
     glRecti(1150, 450, 1170, 460);
     glColor3f(1.0f, 1.0f, 1.0f);
      glRecti(1152, 454, 1168, 460);
  
       
        
        
drawCar(increase_height+60);

   // drawWheel();
   glFlush();
}


 
 

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1500, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("astugedagate");
	 glutTimerFunc(animationUpdateRate, update, 0);
	glutDisplayFunc(gate);
	glutMainLoop();
	return 0;
}

