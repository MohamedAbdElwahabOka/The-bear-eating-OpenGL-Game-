#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>
//#include <bits/stdc++.h>
//#include <string>
//#include<iostream>
//#include<fstream>
#include<stdlib.h>
#include<Windows.h>
#include<mmsystem.h>  ///صوت
//#include "RGBPixMap.h"
#define pi 3.142857
#include<MMSYSTEM.h>




float a = 0.1 ;
float d = -0.5 ;
float sx = 0.11 ;
float sy =0.22;
float angel = 0;
float sun_angle = 70;
float spead_of_cloud1=0.0;
float spead_of_cloud2=0.1;
float spead_of_boat = 0.0;
float fish1_x = -0.6;
float fish1_y = -0.7;
float fish2_x = -0.5;
float fish2_y = -0.9;
float Scale1_x= 0.0;
float Scale1_Y= 0.9;
float Scale2_x= 0.8;
float Scale2_Y= 0.8;
float scale_bird = 0.0;
float fish_angle =0.0;
float PointSize = 0.3;
float spead_of_bird_1 = -0.1;
float spead_of_bird_2 = -0.7;
float spead_of_bird_3  = -0.9;
float spead_of_bird_4 = -1.2;
float spead_of_bird_5 = -0.3;
float spead_of_bird_6 = -5;
float spead_of_bird_7 = -9;
float spead_of_bird_8 = -9;
float spead_of_bird_9 = -15;
float spead_of_bird_10 = -5;
int scale_bird_1 = 5;
int scale_bird_2 = 5;
int scale_bird_3 = 5;
int scale_bird_4 = 5;
int scale_bird_5 = 5;
int scale_bird_6 = 5;
int scale_bird_7 = 5;
int scale_bird_8 = 5;
int scale_bird_9 = 5;
int scale_bird_10 = 5;
int jump_flag = 5;
int i=0;
int start = 0;
int Score = 0;
int Live = 3;
int boat_direction = 4;




/// ****************************
///                            *
///                            *
///          Sun               *
///                            *
///                            *
/// ****************************
void sun(){

    glBegin(GL_LINES);
glLineWidth(0.3f);

 glColor3f(0.0,0.0,0.0);
 //glColor3f(254.0/255.0,213.0/255.0,50.0/255.0);
       /* glVertex2f(0.3, 0.3);
        glVertex2f(0.5, 0.5);*/

         for (float i = 6; i <= 360; i+=8){
        float Degree = i*3.14 / 180;
        float XX = 0.5*cos(Degree);
        float YY = 0.5*sin(Degree);
           // glVertex2f(XX + -1.0 ,YY + 1.0);
             glVertex2f(XX ,YY);
             if(i < 100){
                glVertex2f(XX +0.1,YY+0.1);
             }else if(i > 100){
                 glVertex2f(XX -0.1,YY - 0.1);
             }else if(i == 100){
                       glVertex2f(XX ,YY);
             }


         }
glEnd();


        glBegin(GL_POLYGON);
        glColor3f(254.0/255.0,213.0/255.0,33.0/255.0);
         for (float i = 0; i <= 360; i++){
        float Degree = i*3.14 / 180;
        float XX = 0.5*cos(Degree);
        float YY= 0.5*sin(Degree);
          // glVertex2f(XX + -1.0 ,YY + 1.0);
          glVertex2f(XX,YY);

}glEnd();

glBegin(GL_LINE_STRIP);
        glColor3f(1.0,1.0,1.0);
         for (float i = 0; i <= 360; i++){
        float Degree = i*3.14 / 180;
        float XX = 0.5*cos(Degree);
        float YY = 0.5*sin(Degree);
           // glVertex2f(XX + -1.0 ,YY + 1.0);
             glVertex2f(XX ,YY);

}
glEnd();


}

/// ****************************
///                            *
///                            *
///          bird              *
///                            *
///                            *
/// ****************************
void bird_body(char c){
    if(c == 'y')
        glColor3f(1.0, 204.0/255.0, 0.0);
        else
        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_POLYGON);
        for( float i=0;i<360;i++){
         float deginrad =i*3.14/180;
         float x = 0.1*cos(deginrad);
         float y = 0.1*sin(deginrad);
         glVertex2f( x + -0.3,y + 0.4) ;

        }
        glEnd();

}
void baird_mous(){
  //glScalef(0.5,0.5,1);
      glColor3f(1.0,0.0, 0.0);
        glBegin(GL_POLYGON);
         glVertex2f( -0.2,0.5);
          glVertex2f(-0.2,0.3);
           glVertex2f(-0.1,0.3);

glEnd();

}
void baird_eye(){
  glColor3f(1.0,1.0, 1.0);
   glBegin(GL_POLYGON);
        for( float i=0;i<360;i++){
         float deginrad =i*3.14/180;
         float x = 0.031*cos(deginrad);
         float y = 0.031*sin(deginrad);
         glVertex2f( x + -0.2,y + 0.4) ;

        }
        glEnd();



        glPointSize(3);
        glColor3f(0.0,0.0, 0.0);
   glBegin(GL_POINTS);
     glVertex2f( -0.2,0.4);
glEnd();
}


void bird_tail(){
glColor3f(1.0,1.0, 1.0);
   glBegin(GL_POLYGON);
        for( float i=0;i<360;i++){
         float deginrad =i*3.14/180;
         float x = 0.051*cos(deginrad);
         float y = 0.061*sin(deginrad);
         glVertex2f( x + -0.4,y + 0.4) ;

        }
        glEnd();


}
void bird(char c){
 glPushMatrix();
       glTranslatef(-0.1,0.2,0.0);
       glScalef(0.6,0.6,1);
      baird_mous();
glPopMatrix();



       bird_tail();
       bird_body(c);

  baird_eye();
}

 ///❤❤❤
 /*
void hart(){
        Beep(1000,0);
        //glPointSize(1);
    glColor3ub(0, 0, 0);  // Color Red
    glBegin(GL_LINE_STRIP);
        for (float x = -1.139; x <= 1.139; x += 0.001)
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
    glEnd();
    glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_POLYGON);
        for (float x = -1.139; x <= 1.139; x += 0.001)
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
    glEnd();

}
*/
/// ****************************
///                            *
///                            *
///          Main Colud        *
///                            *
///                            *
/// ****************************


void main_colud(float r, float x ,float y) {
        glColor3f(0.9607843137254f, 0.9607843137254f, 0.9607843137254f);
        glBegin(GL_POLYGON);
        for( float i=0;i<360;i++){
         float deginrad =i*3.14/180;
         float x_cloud = r*cos(deginrad);
         float y_cloud = r*sin(deginrad);
         glVertex2f(x_cloud + x ,y_cloud +y) ;

        }
        glEnd();
}

 void cloud(float x,float y){

glPushMatrix();

glTranslatef(-0.40,0.85,0.0);

main_colud(0.11,x,y);
   glPopMatrix();


   glPushMatrix();

glTranslatef(-0.30,0.85,0.0);

main_colud(0.15,x,y);
   glPopMatrix();

glPushMatrix();
glTranslatef(-0.20,0.85,0.0);

main_colud(0.11,x,y);
   glPopMatrix();
}


/// ****************************
///                            *
///                            *
///          Score             *
///                            *
///                            *
/// ****************************


void score (int Score){
     glColor3f (1.0, 0.0, 0.0);

        glRasterPos2f(-0.7,0.9); //define position on the screen
        char int_str[20];
        sprintf(int_str, "%d", Score);
        char str[20] = "Your Score : ";
        strcat(str,int_str);
        char *string = (str);

      while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
      }
}
/// ****************************
///                            *
///                            *
///          Score             *
///                            *
///                            *
/// ****************************

void Lives(int Live){
     glColor3f (1.0, 0.0, 0.0);

        glRasterPos2f(0.7,0.9); //define position on the screen
        char int_str[20];
        sprintf(int_str, "%d", Live);
        char str[20] = "Your lives : ";
        strcat(str,int_str);
        char *string = (str);

      while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
      }
}



/// ****************************
///                            *
///                            *
///          Boat              *
///                            *
///                            *
/// ****************************


void boat(){
      glColor3f(84.0/255.0f,50.0/255.0f,34.0/255.0f);

        glBegin(GL_POLYGON);
        glVertex2f(-0.4,-0.4);
        glVertex2f(-0.2,-0.5);
        glVertex2f(0.4,-0.5);
        glVertex2f(0.6,-0.4);
        glVertex2f(0.4,-0.6);
        glVertex2f(-0.2,-0.6);

    glEnd();
}

/// ****************************
///                            *
///                            *
///          Bear              *
///                            *
///                            *
/// ****************************

void body(){
      glBegin(GL_POLYGON);
      //glColor3f(102.0/255.0f,107.0/255.0f,112.0/255.0f);  /// Gray
      glColor3f(126.0/255.0,75.0/255.0,21.0/255.0);
      glVertex2f(-0.6 , 0.8);
      glVertex2f(0.6 , 0.8);
      glVertex2f(0.6 , -0.8);
      glVertex2f(-0.6 , -0.8);
    glEnd();

}
void circle(
            float red,
            float green ,
            float blue,
            float start_angel,
            float end_angel,
            float radius,
            float Xplus,
            float Yplus
){

       glBegin(GL_POLYGON);
       glColor3f(red,green,blue);
        for (float i = start_angel; i <= end_angel; i++){
        float Degree = i*3.14 / 180;
        float X = radius*cos(Degree);
        float Y = radius*sin(Degree);
            glVertex2f(X + Xplus ,Y + Yplus);
       }
        glEnd();

}



void Left_Eye(float radius){



          glBegin(GL_POLYGON);
       glColor3f(126.0/255.0,75.0/255.0,21.0/255.0);
       for(float i = 0; i <= 360; i++){
        float Degree = i*3.14 / 180;
        float X = radius*cos(Degree);
        float Y = radius*sin(Degree);
            glVertex2f(X + -0.4 ,Y + 0.9);
       }
       glEnd();

         glBegin(GL_POLYGON);
       glColor3f(1.0f,1.0f,1.0f);
       for(float i = 150; i >= -150; i--){
        float Degree = i*3.14 / 180;
        float X = radius*cos(Degree);
        float Y = radius*sin(Degree);
            glVertex2f(X + -0.33 ,Y + 0.4);
       }
       glEnd();

}




void Right_Eye(float radius){

 circle(126.0/255.0,75.0/255.0,21.0/255.0,0,360,radius,0.4,0.9);

 circle(1.0,1.0,1.0,30,330,radius,0.33,0.4);
 //circle(84.0/255.0f,50.0/255.0f,34.0/255.0f,30,330,radius,0.44,0.7);
 //circle(84.0/255.0f,50.0/255.0f,34.0/255.0f,30,330,radius,-0.44,0.7);

}
void In_Right_Eye(float radius){
    circle(126.0/255.0,75.0/255.0,21.0/255.0,0,360,radius / 2,0.33,0.4);
     //circle(99.0/255.0,191.0/255.0,206.0/255.0,0,360,radius / 2.5,0.33,0.4);
    circle(84.0/255.0f,50.0/255.0f,34.0/255.0f,0,360,radius / 2.5,0.33,0.4);
}
void In_Left_Eye(float radius){

   // circle(0.0,0.0,0.0,0,360,radius / 2,-0.33,0.4);
     //circle(99.0/255.0,191.0/255.0,206.0/255.0,0,360,radius / 2.5,-0.33,0.4);
     circle(126.0/255.0,75.0/255.0,21.0/255.0,0,360,radius / 2,-0.33,0.4);
    circle(84.0/255.0f,50.0/255.0f,34.0/255.0f,0,360,radius / 2.5,-0.33,0.4);
}



void U_nose(){


     glBegin(GL_POLYGON);

    //   glColor3f(0.0f,0.0f,0.0f);
    glColor3f(84.0/255.0f,50.0/255.0f,34.0/255.0f);
        for(float i = 0; i <= 360; i++){
        float Degree = i*3.14 / 180;
        float X = 0.1*cos(Degree);
        float Y = 0.1*sin(Degree);
            glVertex2f(X ,Y );
       }
       glEnd();



}


void Right_leg(float radius){

    circle(177.0/255.0,99.0/255.0f,31.0/255.0,0,180,radius,0.25,-0.8);

}
void In_Right_leg(float radius){


      circle(230.0/255.0,126.0/255.0,34.0/255.0,0,180,radius,0.25,-0.8);
}
void Left_leg(float radius){

    circle(177.0/255.0,99.0/255.0,31.0/255.0,0,180,radius,-0.25,-0.8);

}
void In_Left_leg(float radius){

    circle(230.0/255.0,126.0/255.0,34.0/255.0,0,180,radius,-0.25,-0.8);

}
void ball(float radius){


    circle(1.0,1.0,1.0,0,180,radius,0,-0.759);

}
void Right_hand(float radius){

        glBegin(GL_POLYGON);
      // glColor3f(0.0f,0.0f,0.0f);
      glColor3f(126.0/255.0,75.0/255.0,21.0/255.0);
       for (float i = 40; i >= -40; i--){

        float Degree = i*3.14 /180;
        float X = 0.4*cos(Degree);
        float Y = 0.4*sin(Degree);

           glVertex2f(X + 0.29, Y + -0.2);
       }

         glEnd();

}
void Left_hand(float radius){

        circle(126.0/255.0,75.0/255.0,21.0/255.0,140,220,radius,-0.29,-0.2);
}


void Bear (){



       body();

      float radiuss = 0.2799999;
      //ear(radiuss);
      Right_Eye(radiuss);
      In_Right_Eye(radiuss);
      Left_Eye(radiuss);
    //  ears(radiuss);
      In_Left_Eye(radiuss);
      U_nose();
    //  D_nose();
      ball(0.45);
      Right_leg(0.199);
      In_Right_leg(0.15);
      Left_leg(0.199);
      In_Left_leg(0.15);
      Right_hand(0.4);
      Left_hand(0.4);
      // boat();

}


/// ****************************
///                            *
///                            *
///          water             *
///                            *
///                            *
/// ****************************

void water(){
    glBegin(GL_POLYGON);
    glColor3f(0.0/255.0,167.0/255.0,231.0/255.0);
       glVertex2f(0.0, -0.7);
       glVertex2f(0.0, -1.0);
       glVertex2f(-1.0 , -1.0);
       glVertex2f(-1.0 ,-0.7);




    glEnd();

}

void specialkeys(int key,int x,int y);
void keyboard(unsigned char key, int x, int y);


void press_Enter_to_start(){
  glColor3f(1.0f,0.0f,0.0f);
        glRasterPos3f(-0.1,0.0,0.0);
        char Beart[] = "press space to start";
        for(int i = 0 ;i < strlen(Beart);i++)
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Beart[i]);
}


void the_rules(){
 glColor3f(0.0f,0.0f,0.0f);
        glRasterPos3f(-0.5,0.2,0.0);
        char rules[] = "You must eat yellow, do not eat red, if you eat it, your level will decrease until you die";

        for(int i = 0 ;i < strlen(rules);i++)
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rules[i]);

}

void the_ruless(){
 glColor3f(0.0f,0.0f,0.0f);
        glRasterPos3f(-0.2,0.1,0.0);

         char ruless[] = "Move with 'A' and 'D' and jump with space or 'W'";
        for(int i = 0 ;i < strlen(ruless);i++)
           glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ruless[i]);

}





void me(){
glColor3f(1.0f,0.0f,0.0f);
        glRasterPos3f(-0.2,0.9,0.0);
        char rules[] = "Submitted By : Mohamed Abdelwahab";
        for(int i = 0 ;i < strlen(rules);i++)
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rules[i]);
}

void welcome_Display(){
   glClearColor(148.0/255.5, 216.0/255.0, 255.0/255.0, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

///************************ Water ***************************************/
        glPushMatrix();
            water();
            glTranslatef(1,0.0,0.0);
            water();
        glPopMatrix();
///*********************** Sun *************************************/
glPushMatrix();
        glTranslatef(-1.0,1.0,0.0);
         glScalef(0.5,0.9,1.0);
        glRotatef(sun_angle,0.0,0.0,1.0);
       sun();

glPopMatrix();

///******************************* Clouds ********************************/

glPushMatrix();

     glScalef(0.8,0.8,1.0);
     glTranslatef(spead_of_cloud1,0.0,0.0);
     cloud(0.6,-0.3);
 glPopMatrix();

 glPushMatrix();

     glScalef(0.6,0.6,1.0);
     glTranslatef(spead_of_cloud2,0.0,0.0);
     cloud(-0.5,-0.1);                                /// small
 glPopMatrix();
  /// ***********************  boat ******************************* /
glPushMatrix();
  glScalef(1,0.7,1.0);

    glTranslatef(spead_of_boat,-0.5,0.0);
    boat();

glPopMatrix();

/// ***********************  Bear ******************************* /
  glPushMatrix();


             glLoadIdentity();
             glTranslatef(a,d,1.0);  /// glTranslatef(a +spead_of_boat-0.1,d,1.0);
             glScalef(sx,sy,1.0);
             glRotatef(angel,0.0,0.0,1.0);

                Bear();
     glPopMatrix();
/// *********************** Score **********************************/
glPushMatrix();
    glScalef(0.9,0.9,1.0);
    score(Score);
glPopMatrix();


/// *********************** Lives **********************************/
glPushMatrix();
    glScalef(0.9,0.9,1.0);
    Lives(Live);
glPopMatrix();

    // The_Bear_eating();
     press_Enter_to_start();
     the_rules();
me();
the_ruless();

    glutSwapBuffers();

}
void GameOverDisplay()
{

    glColor3f(1, 0, 0);
    glRasterPos3f(-0.5, 0, 0);
    char msg1[] = "GAME OVER ";
    for (int i = 0; i < strlen(msg1); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
    glRasterPos3f(0.0, 0.8, 0);

    sndPlaySound("gameover.wav" ,SND_ASYNC);
    glutSwapBuffers();
}

/*
void specialkeys(int key,int x,int y){

    if(key == ' '){
    start = 1;
    }

 glutPostRedisplay();
}
*/

/// ****************************
///                            *
///                            *
///          display           *
///                            *
///                            *
/// ****************************





void display()
{

    if(start == 0){
        welcome_Display();
    }else{




   // glPointSize(5.0f); // Point Size
    glClearColor(148.0/255.5, 216.0/255.0, 247.0/255.0, 1.0f);  // Color of sky
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);




///**************************  bird1 ***************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_1,0.0,0.0);
  if(scale_bird_1 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_1 = -1;
   glTranslatef(spead_of_bird_1,-0.1,0.0);

  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
   //pee();
   bird('y');



if(d >= 0.1 && (a +0.1) <= spead_of_bird_1 && (a +0.1) >= spead_of_bird_1 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
    scale_bird_1 = 1;
    //PointSize = 0.0;
}
spead_of_bird_1 = spead_of_bird_1 + 0.00051;

glPopMatrix();

///**************************  bird 2 ***************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_2,-0.1,0.0);
  if(scale_bird_2 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_2 =5;
   glTranslatef(spead_of_bird_2,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a +0.1) <= spead_of_bird_2 && (a +0.1) >= spead_of_bird_2 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
    scale_bird_2 = 1;
    //PointSize = 0.0;
}
spead_of_bird_2 = spead_of_bird_2 +0.00051;

///************************** bird 3 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_3,-0.2,0.0);
  if(scale_bird_3 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_3 =5;
   glTranslatef(spead_of_bird_3,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('r');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_3 && (a +0.1) >= spead_of_bird_3 - 0.1){   /// a <= -0.1 && a >= -0.3
    //Score ++;
    Live--;
   scale_bird_3 = 1;
   //Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_3 = spead_of_bird_3 + 0.00051;



///************************** bird 4 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_4,0.0,0.0);
  if(scale_bird_4 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_4 =5;
   glTranslatef(spead_of_bird_4,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_4 && (a +0.1) >= spead_of_bird_4 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
   scale_bird_4 = 1;
   Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_4 = spead_of_bird_4 + 0.00051;

///************************** bird 5 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_5,0.0,0.0);
  if(scale_bird_5 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_5 =5;
   glTranslatef(spead_of_bird_5,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_5 && (a +0.1) >= spead_of_bird_5 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
   scale_bird_5 = 1;
   Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_5 = spead_of_bird_5+ 0.00051;

///************************** bird 6 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_6,-0.6,0.0);
  if(scale_bird_6 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_6 =5;
   glTranslatef(spead_of_bird_6,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('r');
glPopMatrix();


if(d <= -0.1 && (a+0.1) <= spead_of_bird_6 && (a +0.1) >= spead_of_bird_6 - 0.1){   /// a <= -0.1 && a >= -0.3
    //Score ++;
    Live--;
   scale_bird_6 = 1;
   //Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_6 = spead_of_bird_6 + 0.00051;

///************************** bird 7 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_7,0.0,0.0);
  if(scale_bird_7 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_7 =5;
   glTranslatef(spead_of_bird_7,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_7 && (a +0.1) >= spead_of_bird_7 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
   scale_bird_7 = 1;
 //  Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_7 = spead_of_bird_7 + 0.00051;

///************************** bird 7 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_8,0.0,0.0);
  if(scale_bird_8 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_8 =5;
   glTranslatef(spead_of_bird_8,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_8 && (a +0.1) >= spead_of_bird_8 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
   scale_bird_8 = 1;
 //  Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_8 = spead_of_bird_8 + 0.00051;

///************************** bird 9 *********************************************************/
glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_9,0.0,0.0);
  if(scale_bird_9 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_9 =5;
   glTranslatef(spead_of_bird_9,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('y');
glPopMatrix();


if(d >= 0.1 && (a+0.1) <= spead_of_bird_9 && (a +0.1) >= spead_of_bird_9 - 0.1){   /// a <= -0.1 && a >= -0.3
    Score ++;
   scale_bird_9 = 1;
 //  Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_10 = spead_of_bird_10 + 0.00051;



///************************** bird 10*********************************************************/


glPushMatrix();
 // glTranslatef(-0.1,0.1,0.0);
  glTranslatef(spead_of_bird_10,-0.6,0.0);
  if(scale_bird_10 == 1){
   // glScalef(scale_bird,scale_bird,1);
   spead_of_bird_10 =5;
   glTranslatef(spead_of_bird_10,-0.1,0.0);
  }
  glScalef(0.5,0.5,1);
  glRotatef(0.0,0.0,0.0,1.0);
   //fish(PointSize);
//   pee();
bird('r');
glPopMatrix();


if(d <= -0.1 && (a+0.1) <= spead_of_bird_10 && (a +0.1) >= spead_of_bird_10 - 0.1){   /// a <= -0.1 && a >= -0.3
    //Score ++;
    Live--;
   scale_bird_10 = 1;
   //Beep(1000,0);
    //PointSize = 0.0;
}
spead_of_bird_10 = spead_of_bird_10 + 0.00051;



///************************ Water ***************************************/
glPushMatrix();
    water();
    glTranslatef(1,0.0,0.0);
    water();

glPopMatrix();
///*************************Land*****************************************/
/*
glPushMatrix();
  glTranslatef(0.1,0.1,1.0);
    land();
glPopMatrix();
*/
 /// /*********************** Sun *************************************/
glPushMatrix();
      // glLoadIdentity();
        glTranslatef(-1.0,1.0,0.0);
         glScalef(0.5,0.9,1.0);
        glRotatef(sun_angle,0.0,0.0,1.0);
       sun();
       sun_angle= sun_angle + 0.01;
glPopMatrix();
if(sun_angle >= 110){
    sun_angle = 70;
}
//printf("%f\n",sun_angle);

///******************************* Clouds ********************************/

glPushMatrix();

     glScalef(0.8,0.8,1.0);
     glTranslatef(spead_of_cloud1,0.0,0.0);
     cloud(0.6,-0.3);
     spead_of_cloud1 = spead_of_cloud1 + 0.0001;    /// big
     if(spead_of_cloud1 >= 1.2){
        spead_of_cloud1 = -2.0;
     }

 glPopMatrix();

 glPushMatrix();

     glScalef(0.6,0.6,1.0);
     glTranslatef(spead_of_cloud2,0.0,0.0);
     cloud(-0.5,-0.1);
     spead_of_cloud2 = spead_of_cloud2 + 0.0001;       /// small
     if(spead_of_cloud2 >= 2.8){
        spead_of_cloud2 = -1.2;
     }
 glPopMatrix();
 /// ***********************  boat ******************************* /
glPushMatrix();
  glScalef(1,0.7,1.0);

    glTranslatef(spead_of_boat,-0.5,0.0);
    boat();

glPopMatrix();




///******************************* Bear ******************************/
     glPushMatrix();


             glLoadIdentity();
            // float old_d = d;

             if(jump_flag == 1){

                d = d + 0.0051;
             }
             else if(jump_flag == 0){

               d = d - 0.0051;

             }

             glTranslatef(a,d,1.0);  /// glTranslatef(a +spead_of_boat-0.1,d,1.0);
             glScalef(sx,sy,1.0);
             glRotatef(angel,0.0,0.0,1.0);

                Bear();
     glPopMatrix();
     if(d >=  +0.1){
        jump_flag = 0;

     }
     if(d <= -0.5){
         d = -0.5;
     }
     if(a <= -0.94){
        a = -0.94;
     }else if(a >= 0.94){
         a = 0.94;
     }

    if(a <= (spead_of_boat -0.2)){
        a = spead_of_boat - 0.2;
     }
     if(a >= (spead_of_boat + 0.4)){
        a = spead_of_boat  +0.4;
     }



/*

printf("a = %f \n",a);
printf("boat = %f \n",spead_of_boat);

*/

/// *********************** Score **********************************/
glPushMatrix();
    glScalef(0.9,0.9,1.0);
    score(Score);
glPopMatrix();


/// *********************** Lives **********************************/
glPushMatrix();
    glScalef(0.9,0.9,1.0);
    Lives(Live);
glPopMatrix();



if(Live == 0){
glutDisplayFunc(GameOverDisplay);
}

/*
glPushMatrix();
glTranslatef(0.7,0.8,1.0);
 glScalef(0.05,0.06,1.0);
hart();
glPopMatrix();

*/

 glFlush();
 glutPostRedisplay();


}
}

void keyboard(unsigned char key, int x, int y){


        if(key == 'a' || key == 'A'){ //a left
        //x--;
        a = a - 0.01 -(0.01 *5);

        }
        if(a != 1){
            if(key == 'd' || key == 'D'){ // d
            //x++;
        a = a + 0.01 + (0.01 *5);
      }
 }

      if(key == 'w' || key == 'W'){ //w
        //y++;
       // d = d + 0.01 +(0.01 *5);
       jump_flag = 1;
      // sndPlaySound("jump.wav" ,SND_ASYNC);
      }

      if(d <= -1){

            if(key == 115){ //s
        //y--;
      //  d = d - 0.01 - (0.01 *5);
      }
      }

      if(key == 43){  // +
          sx = sx + 0.01;
          sy = sy + 0.01;
      }if(key == 45){  //-
          sx = sx - 0.01;
          sy = sy - 0.01;
      }if(key == 101){ //e
          angel = angel + 5 ;

      }if(key == 113 ){ //q
           angel = angel - 5  ;
      }

      if(key == ' '){ // c jump

         jump_flag = 1;
         start = 1;
        // sndPlaySound("jump.wav" ,SND_ASYNC);

      }


glutPostRedisplay();
}


int main(int argc, char** argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1100, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("The bear etating");
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    //sndPlaySound("background.wav" ,SND_ASYNC);
    //PlaySound(TEXT("background.wav"),NULL,SND_ASYNC);
    //SoundEngine->play2D("background.wav", false);
    PlaySound("background.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glutMainLoop();
    return 0;
}


































