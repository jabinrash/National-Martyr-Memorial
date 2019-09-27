//  © Jabin Rubayat //

#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string.h>

#include "imageloader.h"

//OpenGL32.lib Glu32.lib Glaux.lib
#define PI 3.1415926535898
GLfloat	l_t=0,u_p=0,beside=0;	//used for movement of the object lt, rt, up and down
GLfloat zoom=70;
GLuint text[3];



//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;

	glGenTextures(1, &textureId);
	//Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureIdEkus ; //The id of the texture
int z = -100;

void single_pillar()
{



	glPushMatrix();
	glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(1.0f,1.0f,1.0f);


		glVertex3f(1.0f,20.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f,20.0f,1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Top)


		glVertex3f(1.0f,0.0f,1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,0.0f,1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,0.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(1.0f,0.0f,-1.0f);					// Bottom Right Of The Quad (Bottom)


		glVertex3f(1.0f,20.0f,1.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-1.0f,20.0f,1.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,0.0f, 1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f,0.0f, 1.0f);					// Bottom Right Of The Quad (Front)


		glVertex3f(1.0f,20.0f,-1.0f);					// Top Right Of The Quad (back)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Top Left Of The Quad (back)
		glVertex3f(-1.0f,0.0f, -1.0f);					// Bottom Left Of The Quad (baCK)
		glVertex3f(1.0f,0.0f, -1.0f);					// Bottom Right Of The Quad (back)


		             						// Set The Color To  veryyyyyy light  gray
	glColor3f( 0.850,0.850,0.850);

		glVertex3f(-1.0f,20.0f,1.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f,0.0f,1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,0.0f,-1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Left)



		glVertex3f(1.0f,20.0f,-1.0f);					// Top Right Of The Quad (right)
		glVertex3f(1.0f,20.0f,1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(1.0f,0.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(1.0f,0.0f,-1.0f);					// Bottom Right Of The Quad (Left)


	glEnd();

		glPopMatrix();




}

void stick()
{

		glPushMatrix();
	glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(0.30,0.19,0.14);

		glVertex3f(0.03125f,20.0f,0.0625f);					// Top Right Of The Quad (Front)
		glVertex3f(-0.03125f,20.0f,0.0625f);					// Top Left Of The Quad (Front)
		glVertex3f(-0.03125f,0.0f, 0.0625f);					// Bottom Left Of The Quad (Front)
		glVertex3f(0.03125f,0.0f, 0.0625f);					// Bottom Right Of The Quad (Front)

	glEnd();
	glPopMatrix();

}
void bend_stick()
{

	glPushMatrix();
	glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(0.30,0.19,0.14);

		glVertex3f(0.03125f,25.0f,7.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-0.03125f,25.0f,7.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-0.03125f,20.0f, 0.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(0.03125f,20.0f, 0.0f);					// Bottom Right Of The Quad (Front)

	glEnd();
	glPopMatrix();

}

void bend_on_top()
{
glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(1.0f,1.0f,1.0f);

		glVertex3f(1.0f,25.0f,7.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f,26.0f,6.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f,26.0f,6.0f);					// Bottom Right Of The Quad (Top)


		glVertex3f(1.0f,18.0f,1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,18.0f,1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Bottom)


		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,25.0f,7.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f,18.0f,1.0f);					// Bottom Right Of The Quad (Front)


		glVertex3f(1.0f,26.0f,6.0f);					// Top Right Of The Quad (back)
		glVertex3f(-1.0f,26.0f,6.0f);					// Top Left Of The Quad (back)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Left Of The Quad (baCK)
		glVertex3f(1.0f,20.0f,-1.0f);            // Bottom Right Of The Quad (back)


		   glColor3f(0.9f,0.9f,0.9f);          						// Set The Color To gray


		glVertex3f(-1.0f,26.0f,6.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Left)



		glVertex3f(1.0f,26.0f,6.0f);					// Top Right Of The Quad (right)
		glVertex3f(1.0f,25.0f,7.0f);					// Top Left Of The Quad (Left)
		glVertex3f(1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Left)


	glEnd();
glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(1.0f,1.0f,1.0f);

		glVertex3f(1.0f,25.0f,7.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f,26.0f,6.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f,26.0f,6.0f);					// Bottom Right Of The Quad (Top)


		glVertex3f(1.0f,18.0f,1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,18.0f,1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Bottom)


		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,25.0f,7.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f,18.0f,1.0f);					// Bottom Right Of The Quad (Front)


		glVertex3f(1.0f,26.0f,6.0f);					// Top Right Of The Quad (back)
		glVertex3f(-1.0f,26.0f,6.0f);					// Top Left Of The Quad (back)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Left Of The Quad (baCK)
		glVertex3f(1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (back)



		  glColor3f(0.9f,0.9f,0.9f);	// Set The Color To Yellow


		glVertex3f(-1.0f,26.0f,6.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f,25.0f,7.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Left)



		glVertex3f(1.0f,26.0f,6.0f);					// Top Right Of The Quad (right)
		glVertex3f(1.0f,25.0f,7.0f);					// Top Left Of The Quad (Left)
		glVertex3f(1.0f,18.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(1.0f,20.0f,-1.0f);					// Bottom Right Of The Quad (Left)


	glEnd();

}



void bar_on_top_floor()
{

glBegin(GL_QUADS);									// Draw A Quad

		glColor3f(1.0f,1.0f,1.0f);

		glVertex3f(7.0f,0.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(7.0f,0.0f,-1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f,0.0f,-1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( -1.0f,0.0f,1.0f);					// Bottom Right Of The Quad (Top)


		glVertex3f(7.0f,-1.0f,1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(7.0f,-1.0f,-1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Bottom)

//	glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(7.0f,0.0f,1.0f);					// Top Right Of The Quad (Front)
		glVertex3f(7.0f,-1.0f,1.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(-1.0f,0.0f,1.0f);					// Bottom Right Of The Quad (Front)


		glVertex3f(7.0f,0.0f,-1.0f);					// Top Right Of The Quad (back)
		glVertex3f(7.0f,-1.0f,-1.0f);					// Top Left Of The Quad (back)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (baCK)
		glVertex3f(-1.0f,0.0f,-1.0f);					// Bottom Right Of The Quad (back)
		 glColor3f(0.9f,0.9f,0.9f);            						// Set The Color To Yellow


		glVertex3f(-1.0f,0.0f,1.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f,0.0f,-1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Left)



		glVertex3f(7.0f,0.0f,1.0f);					// Top Right Of The Quad (right)
		glVertex3f(7.0f,0.0f,-1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(7.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(7.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Left)


	glEnd();






}

void floor_piller()
{

glPushMatrix();
glScalef(1.1f,1.0f,1.1f);
	bar_on_top_floor();  ///bottom  right
	glPopMatrix();
glPushMatrix();
glScalef(1.1f,1.0f,1.1f);
   glTranslatef(-6.0f,0.0f,0.0f);
   bar_on_top_floor();    /////bottom left
glPopMatrix();


glPushMatrix();
   glTranslatef(0.0f,26.0f,6.0f);
   glRotatef(-48.0f,1.0f,0.0f,0.0f);  ///////////// check it also////
   glScalef(1.0f,1.4f,0.6f);//////////////check it


   bar_on_top_floor();      /////top right
glPopMatrix();


glPushMatrix();
   glTranslatef(-6.0f,26.0f,6.0f);
   glRotatef(-48.0f,1.0f,0.0f,0.0f);  ///////////// check it also////
   glScalef(1.0f,1.4f,0.6f);//////////////check it


   bar_on_top_floor();      ////top left
glPopMatrix();
}

void middle_pillar()
{
	single_pillar();
	bend_on_top();

	glPushMatrix();
	glTranslatef(6.0f,0.0f,0.0f);
		single_pillar();
		bend_on_top();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0f,0.0f,0.0f);
		single_pillar();
		bend_on_top();
	glPopMatrix();



	////////////sticks///////
		glPushMatrix();
	glTranslatef(1.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(2.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(3.0f,0.0f,0.0f);
		stick();
        bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(3.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(4.0f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(4.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();



	//////////left////
		////////////sticks///////
		glPushMatrix();
	glTranslatef(-1.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(-2.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(-3.0f,0.0f,0.0f);
		stick();
        bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(-3.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(-4.0f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();
		glPushMatrix();
	glTranslatef(-4.5f,0.0f,0.0f);
		stick();
		bend_stick();
	glPopMatrix();



floor_piller();









}


void bar_top_bottom()    /////for 2nd and 3rd piller/////
{
	glPushMatrix();
        glScalef(1.1f,1.0f,1.1f); /////////check
		glTranslatef(-0.25f,0.0f,0.0f);
	bar_on_top_floor();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f,20.0f,0.0f);
	bar_on_top_floor();   ///bottom
	glPopMatrix();
}

void single_side_piller_right()
{

glPushMatrix();

    	glScalef(1.0f,1.0f,0.8f);
	single_pillar();

/////stick////////

	glPushMatrix();
	glTranslatef(1.5f,0.0f,0.0f);
		stick();

	glPopMatrix();


    glPushMatrix();
	glTranslatef(2.0f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0f,0.0f,0.0f);
		stick();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(3.5f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5f,0.0f,0.0f);
		stick();

	glPopMatrix();


	//////stick end






	glTranslatef(6.0f,0.0f,0.0f);
//	glRotatef(60.0f,0.0f,1.0f,0.0f);
		single_pillar();

	glPopMatrix();

glPushMatrix();
        glScalef(1.0f,1.0f,0.8f);
	bar_top_bottom();
   glPopMatrix();


}


void single_side_piller_left()
{


   glPushMatrix();

    	glScalef(1.0f,1.0f,0.8f);
	single_pillar();
//////stick start/////
	glPushMatrix();
	glTranslatef(-1.5f,0.0f,0.0f);
		stick();

	glPopMatrix();


    glPushMatrix();
	glTranslatef(-2.0f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.0f,0.0f,0.0f);
		stick();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-3.5f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0f,0.0f,0.0f);
		stick();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5f,0.0f,0.0f);
		stick();

	glPopMatrix();


	//////stick end

	glTranslatef(-6.0f,0.0f,0.0f);
//	glRotatef(60.0f,0.0f,1.0f,0.0f);
		single_pillar();

	glPopMatrix();

glPushMatrix();
        glScalef(1.0f,1.0f,0.8f);
		glTranslatef(-6.0f,0.0f,0.0f);
	bar_top_bottom();
   glPopMatrix();

}
void side_piller()
{

	glPushMatrix();  ///////2nd piller right//////

	glTranslatef(14.0f,0.0f,-3.5f);
	glRotatef(-55.0f,0.0f,1.0f,0.0f);   ///////check korte katci
	single_side_piller_right();
	//	single_pillar();
		//bend_on_top();
	glPopMatrix();



	glPushMatrix();      ///////// 3rd piller right////
     glScalef(1.0f,0.85f,1.f);
	glTranslatef(23.0f,0.0f,3.0f);
	glRotatef(-55.0f,0.0f,1.0f,0.0f);      ///// check korte katci
	single_side_piller_right();

	glPopMatrix();
///////////////////////////////////////////////////////////check




	 glPushMatrix();  ///////2nd piller left//////

	glTranslatef(-14.0f,0.0f,-3.5f);
	glRotatef(55.0f,0.0f,1.0f,0.0f);   ///////check korte katci
	single_side_piller_left();
	//	single_pillar();
		//bend_on_top();
	glPopMatrix();

	glPushMatrix();      ///////// 3rd piller left////
     glScalef(1.0f,0.85f,1.f);
	glTranslatef(-23.0f,0.0f,3.0f);
	glRotatef(55.0f,0.0f,1.0f,0.0f);      ///// check korte katci
	single_side_piller_left();

	glPopMatrix();
}

void circle(GLdouble rad)
{



	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;

		glPushMatrix();
	glTranslatef(0,15,-4.5);
    glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	{
		for( GLint i = 0; i <=50; i++, theta += delTheta )
		{
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
glPopMatrix();

}

void singlebase()
{
   glColor3f(1.f,0.0f,0.0f);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, text[0]);

	glBegin(GL_QUADS);	   ////////////top////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-30.0f,0.25f,12.0f);
		glTexCoord2f(4.0f, 0.0f);		glVertex3f(30.0f,0.25f,12.0f);
		glTexCoord2f(4.0f, 4.0f);			glVertex3f(30.0f,0.25f,-12.0f);
		glTexCoord2f(0.0f, 4.0f);	        	glVertex3f( -30.0f,0.25f,-12.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[0]);

	glBegin(GL_QUADS);	   ////////////bottom////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-30.0f,-0.25f,12.0f);
		glTexCoord2f(4.0f, 0.0f);		glVertex3f(30.0f,-0.25f,12.0f);
		glTexCoord2f(4.0f, 4.0f);			glVertex3f(30.0f,-0.25f,-12.0f);
		glTexCoord2f(0.0f, 4.0f);	        	glVertex3f( -30.0f,-0.25f,-12.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[1]);

glColor3f(0.647059,0.164706, 0.164706);
	glBegin(GL_QUADS);	   ////////////front////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-30.0f,-0.25f,12.0f);
		glTexCoord2f(3.0f, 0.0f);		glVertex3f(30.0f,-0.25f,12.0f);
		glTexCoord2f(3.0f, 3.1f);			glVertex3f(30.0f,0.25f,12.0f);
		glTexCoord2f(0.0f, 3.0f);	        	glVertex3f( -30.0f,0.25f,12.0f);
	glEnd();
	/////////////back/////////////
glBindTexture(GL_TEXTURE_2D, text[1]);

//glColor3f(0.647059,0.164706, 0.164706);
	glBegin(GL_QUADS);	   ////////////front////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-30.0f,-0.25f,-12.0f);
		glTexCoord2f(3.0f, 0.0f);		glVertex3f(30.0f,-0.25f,-12.0f);
		glTexCoord2f(3.0f, 3.1f);			glVertex3f(30.0f,0.25f,-12.0f);
		glTexCoord2f(0.0f, 3.0f);	        	glVertex3f( -30.0f,0.25f,-12.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[1]);

	glBegin(GL_QUADS);	   ////////////right////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(30.0f,-0.25f,12.0f);
		glTexCoord2f(3.0f, 0.0f);		glVertex3f(30.0f,-0.25f,-12.0f);
		glTexCoord2f(3.0f, 3.1f);			glVertex3f(30.0f,0.25f,-12.0f);
		glTexCoord2f(0.0f, 3.0f);	        	glVertex3f( 30.0f,0.25f,12.0f);
	glEnd();

		glBindTexture(GL_TEXTURE_2D, text[1]);

	glBegin(GL_QUADS);	   ////////////left////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-30.0f,-0.25f,12.0f);
		glTexCoord2f(3.0f, 0.0f);		glVertex3f(-30.0f,-0.25f,-12.0f);
		glTexCoord2f(3.0f, 3.1f);			glVertex3f(-30.0f,0.25f,-12.0f);
		glTexCoord2f(0.0f, 3.0f);	        	glVertex3f( -30.0f,0.25f,12.0f);
	glEnd();

glPopMatrix();

}

void lamp()
{
		glPushMatrix();
		glColor3f(0.36,0.25,0.20);
	glBegin(GL_QUADS);									// Draw A Quad


		glVertex3f(0.5f,20.0f,0.5f);					// Top Right Of The Quad (Top)
		glVertex3f(-0.5f,20.0f,0.5f);					// Top Left Of The Quad (Top)
		glVertex3f(-0.5f,20.0f,-0.5f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 0.5f,20.0f,-0.5f);					// Bottom Right Of The Quad (Top)


		glVertex3f(0.5f,0.0f,0.5f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-0.5f,0.0f,0.5f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-0.5f,0.0f,-0.5f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(0.5f,0.0f,-0.5f);					// Bottom Right Of The Quad (Bottom)


		glVertex3f(0.50f,20.0f,0.50f);					// Top Right Of The Quad (Front)
		glVertex3f(-0.50f,20.0f,0.50f);					// Top Left Of The Quad (Front)
		glVertex3f(-0.50f,0.0f, 0.50f);					// Bottom Left Of The Quad (Front)
		glVertex3f(0.50f,0.0f, 0.50f);					// Bottom Right Of The Quad (Front)


		glVertex3f(0.50f,20.0f,-0.50f);					// Top Right Of The Quad (back)
		glVertex3f(-0.50f,20.0f,-0.50f);					// Top Left Of The Quad (back)
		glVertex3f(-0.50f,0.0f, -0.50f);					// Bottom Left Of The Quad (baCK)
		glVertex3f(0.50f,0.0f, -0.50f);					// Bottom Right Of The Quad (back)


		             						// Set The Color To  veryyyyyy light  gray
	glColor3f( 0.34,0.23,0.18);

		glVertex3f(-0.50f,20.0f,0.50f);					// Top Right Of The Quad (Left)
		glVertex3f(-0.50f,0.0f,0.50f);					// Top Left Of The Quad (Left)
		glVertex3f(-0.50f,0.0f,-0.50f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-0.50f,20.0f,-0.50f);					// Bottom Right Of The Quad (Left)



		glVertex3f(0.50f,20.0f,-0.50f);					// Top Right Of The Quad (right)
		glVertex3f(0.50f,20.0f,0.50f);					// Top Left Of The Quad (Left)
		glVertex3f(0.50f,0.0f,0.50f);					// Bottom Left Of The Quad (Left)
		glVertex3f(0.50f,0.0f,-0.50f);					// Bottom Right Of The Quad (Left)


	glEnd();

		glPopMatrix();

		glColor3f(0.0,0.0,0.0);

		////////////batti//////
			glPushMatrix();
			glColor3f(1.0,1.0,0.0 );
	glBegin(GL_QUADS);									// Draw A Quad


		glVertex3f(1.0f,24.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f,24.0f,1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f,24.0f,-1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f,24.0f,-1.0f);					// Bottom Right Of The Quad (Top)


		glVertex3f(0.5f,20.0f,0.5f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-0.5f,20.0f,0.5f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-0.5f,20.0f,-0.5f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(0.5f,20.0f,-0.5f);					// Bottom Right Of The Quad (Bottom)


		glVertex3f(0.50f,20.0f,0.50f);					// Top Right Of The Quad (Front)
		glVertex3f(-0.50f,20.0f,0.50f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,24.0f, 1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f,24.0f, 1.0f);					// Bottom Right Of The Quad (Front)

	glVertex3f(0.50f,20.0f,-0.50f);					// Top Right Of The Quad (backt)
		glVertex3f(-0.50f,20.0f,-0.50f);					// Top Left Of The Quad (back)
		glVertex3f(-1.0f,24.0f, -1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f,24.0f, -1.0f);



		             						// Set The Color To  veryyyyyy light  gray
	glColor3f(1,0.9,0 );

	glVertex3f(-0.50f,20.0f,-0.50f);					// Top Right Of The Quad (right)
		glVertex3f(-0.50f,20.0f,0.50f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,24.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,24.0f,-1.0f);



		glVertex3f(0.50f,20.0f,-0.50f);					// Top Right Of The Quad (right)
		glVertex3f(0.50f,20.0f,0.50f);					// Top Left Of The Quad (Left)
		glVertex3f(1.0f,24.0f,1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(1.0f,24.0f,-1.0f);					// Bottom Right Of The Quad (Left)


	glEnd();

		glPopMatrix();


		///////////top

			glPushMatrix();
			glColor3f(0.36,0.25,0.20);
	glBegin(GL_QUADS);									// Draw A Quad


		glVertex3f(1.4f,24.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.4f,24.0f,1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.4f,24.0f,-1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f( 1.4f,24.0f,-1.0f);					// Bottom Right Of The Quad (Top)
		glEnd();

	glBegin(GL_TRIANGLES);								// Start Drawing A Triangle

		glVertex3f(1.4f,24.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.4f,24.0f,1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(0.0f,25.5f,0.0f);					// Bottom Left Of The Quad (Top)

		glEnd();

		glBegin(GL_TRIANGLES);								// Start Drawing A Triangle

		glVertex3f(1.4f,24.0f,-1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.4f,24.0f,-1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(0.0f,25.5f,0.0f);					// Bottom Left Of The Quad (Top)

		glEnd();
		glColor3f(0.34,0.23,0.18);
			glBegin(GL_TRIANGLES);								// Start Drawing A Triangle

		glVertex3f(-1.40f,24.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.40f,24.0f,-1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(0.0f,25.5f,0.0f);					// Bottom Left Of The Quad (Top)

		glEnd();
	glBegin(GL_TRIANGLES);								// Start Drawing A Triangle

		glVertex3f(1.40f,24.0f,1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(1.40f,24.0f,-1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(0.0f,25.5f,0.0f);					// Bottom Left Of The Quad (Top)

		glEnd();


		glPopMatrix();

}

void grass()
{
	glColor3f(0.309804,0.309804,0.184314);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, text[2]);

	glBegin(GL_QUADS);	   ////////////top////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-40.0f,0.25f,35.0f);
		glTexCoord2f(5.0f, 0.0f);		glVertex3f(40.0f,0.25f,35.0f);
		glTexCoord2f(5.0f, 5.0f);			glVertex3f(40.0f,0.25f,-35.0f);
		glTexCoord2f(0.0f, 5.0f);	        	glVertex3f( -40.0f,0.25f,-35.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[2]);

	glBegin(GL_QUADS);	   ////////////bottom////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-40.0f,-0.25f,35.0f);
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f,-0.25f,35.0f);
		glTexCoord2f(1.0f, 0.1f);			glVertex3f(40.0f,-0.25f,-35.0f);
		glTexCoord2f(0.0f, 1.0f);	        	glVertex3f( -40.0f,-0.25f,-35.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[2]);

	glBegin(GL_QUADS);	   ////////////front////
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-40.0f,-0.25f,35.0f);
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f,-0.25f,35.0f);
		glTexCoord2f(1.0f, 0.1f);			glVertex3f(40.0f,0.25f,35.0f);
		glTexCoord2f(0.0f, 1.0f);	        	glVertex3f( -40.0f,0.25f,35.0f);
	glEnd();

glPopMatrix();
glPushMatrix();


glDisable(GL_TEXTURE_2D);

glTranslatef(34.0f,0.25f,25.0f);
lamp();
glPopMatrix();

glPushMatrix();


glDisable(GL_TEXTURE_2D);

glTranslatef(34.0f,0.25f,10.0f);
lamp();
glPopMatrix();

glPushMatrix();
glDisable(GL_TEXTURE_2D);

glTranslatef(34.0f,0.25f,-5.0f);
lamp();
glPopMatrix();

glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(34.0f,0.25f,-20.0f);
lamp();
glPopMatrix();

glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(34.0f,0.25f,-35.0f);
lamp();
glPopMatrix();


/////left

glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(-34.0f,0.25f,-35.0f);
lamp();
glPopMatrix();
glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(-34.0f,0.25f,-20.0f);
lamp();
glPopMatrix();
glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(-34.0f,0.25f,-5.0f);
lamp();
glPopMatrix();
glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(-34.0f,0.25f,10.0f);
lamp();
glPopMatrix();
glPushMatrix();

glDisable(GL_TEXTURE_2D);

glTranslatef(-34.0f,0.25f,25.0f);
lamp();
glPopMatrix();




}
void baseStairs()
{
glPushMatrix();

	glTranslatef(0.0f,-1.5f,0.0f);
	singlebase();

	glPopMatrix();

	glPushMatrix();
	glScalef(1.0125f,1.1f,1.05f);
	glTranslatef(0.0f,-2.0f,0.5f);
	singlebase();

	glPopMatrix();


	glPushMatrix();
	glScalef(1.025f,1.1f,1.1f);
	glTranslatef(0.0f,-2.5f,1.0f);
	singlebase();

	glPopMatrix();


	glPushMatrix();
	glScalef(1.0375f,1.1f,1.15f);
	glTranslatef(0.0f,-3.0f,1.5f);
	singlebase();

	glPopMatrix();


	glPushMatrix();
	glScalef(1.05f,1.1f,1.2f);
	glTranslatef(0.0f,-3.5f,2.0f);
	singlebase();

	glPopMatrix();


	glPushMatrix();
	glScalef(1.0625f,1.1f,1.25f);
	glTranslatef(0.0f,-4.0f,2.5f);
	singlebase();

	glPopMatrix();


	glPushMatrix();
	glScalef(1.075f,1.1f,1.3f);
	glTranslatef(0.0f,-4.5f,3.0f);
	singlebase();

	glPopMatrix();



	glPushMatrix();
	glScalef(1.0875f,1.1f,1.35f);
	glTranslatef(0.0f,-5.0f,3.5f);
	singlebase();
	grass();


	glPopMatrix();



}
void display(void){



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer

	glLoadIdentity();									// Reset The Current Modelview Matrix



glPushMatrix();
    glTranslatef(-30.0f, 15.0f, z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdEkus);
	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glColor3f(1.0f, 0.2f, 0.2f);
	glBegin(GL_QUADS);
	//glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-15.0f, -15.0f, 2.5f);

	glTexCoord2f(1.0f, 0.0f);glVertex3f(15.0f, -15.0f, 2.5f);

	glTexCoord2f(1.0f, 1.0f);glVertex3f(15.0f, 15.0f, 2.5f);

	glTexCoord2f(0.0f, 1.0f);glVertex3f(-15.0f, 15.0f, 2.5f);
	glEnd();
 glPopMatrix();


	glPushMatrix();
//	glTranslatef(0.0f,-5.0f,-zoom);
    glTranslatef(beside,-5.0f,-zoom);

	glPushMatrix();
	glRotatef(l_t,0.0f,1.0f,0.0f);
	glPushMatrix();
	glRotatef(u_p,1.0f,0.0f,0.0f);



	glEnable(GL_TEXTURE_2D);
	baseStairs();


glDisable(GL_TEXTURE_2D);

middle_pillar();

side_piller();

circle(11.5f);


	glPopMatrix();
	glPopMatrix();
	glPopMatrix();



	glutSwapBuffers() ;

}




void init(void)
{




	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading

	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background

	glClearDepth(1.0f);									// Depth Buffer Setup


	gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing

	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	  /*Image* image = loadBMP("D:\\SohidMinar\\brick.bmp");
	_textureIdEkus = loadTexture(image);
	delete image;*/
}
void spinDisplay(void)		//spin speed
{
	l_t =l_t+0.2;
    glutPostRedisplay();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);

   glMatrixMode (GL_PROJECTION);

   glLoadIdentity ();

   gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 0.1f, 100.0);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

   gluLookAt (0.0, 0.0, 300.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void mouse(int button, int state, int x, int y)
{
   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {

   case 'd':
	u_p=u_p+1;
	   glutPostRedisplay();
	   break;

	case 'u':
	u_p=u_p-1;
	   glutPostRedisplay();
	   break;

   case 's':
	   zoom+=0.5;
	   glutPostRedisplay();
	   break;

	case 'b':
	   zoom-=0.5;
	   glutPostRedisplay();
	   break;

	case 'r':
	  l_t =l_t-1;
	   glutPostRedisplay();
	   break;

   case 'l':
	  l_t =l_t+1;
	   glutPostRedisplay();
	   break;
 case 'q':
	  beside =beside+0.5;
	   glutPostRedisplay();
	   break;

case 'w':
	  beside =beside-0.5;
	   glutPostRedisplay();
	   break;

	   case 'z':
	       z=0;
	       	   glutPostRedisplay();
	   break;
	     case 'x':
	       z=-100;
	       	   glutPostRedisplay();
	   break;

   default:
	   break;
   }
}

int main()
{


   printf("\n********** Shohid minar ***************\n\n");
   printf("\n    1.	Press 'left' mouse button to rotate and 'right' to stop.\n");
   printf("\n    2.	Press 'l' to move object left. \n");
   printf("\n    3.	Press 'r' to move object right. \n");
   printf("\n    4.	Press 'd' to move object down. \n");
   printf("\n    5.	Press 'u' to move objecct up. \n");
   printf("\n    6.	Press 'b' to zoom out \n");
   printf("\n    7.	Press 's' to zoom in  \n");
   printf("\n    8.	Press 'q' to move left \n");
   printf("\n    9.	Press 'w' to move right \n\n\n");

   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1400, 700);
   glutInitWindowPosition (0,0);//start drawing
   glutCreateWindow ("shohid minar");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
