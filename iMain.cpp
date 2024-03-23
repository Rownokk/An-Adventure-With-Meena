


# include "iGraphics.h"
#define JUMPLIMIT 150
#define upperBackGroundSpeed 10
#define lowerBackGroundSpeed 12

struct background{
	
	int x;
	int y;
};

bool heart1 = true ;
bool heart2= true ;
bool heart3= true ;



bool musicOn = true ;
bool musicOn1 = false ;

bool thiefOn;
char thief[7][20] = {"chor\\11.bmp","chor\\22.bmp","chor\\33.bmp","chor\\44.bmp","chor\\55.bmp","chor\\66.bmp","chor\\77.bmp"};
int thiefx = 1000;
int thiefy = 80;
int thiefIndex = 0 ;
char hart[3][20]={"heart\\1.bmp","heart\\2.bmp","heart\\3.bmp"};





int scoree=0,bestScore,bs,sc;


char S[10],S1[10],S2[10];

background upperBackGround[10];
background lowerBackGround[10];

struct obstacle1{							//new
	bool obstacle1On ;
	int x;
	int y;};
	obstacle1 obs1[100];
	int obstacle1Index =0;

struct obstacle2{
	bool obstacle2On;
	int x;
	int y;};
	obstacle2 obs2[100];
	int obstacle2Index =0;

struct obstacle3{
	bool obstacle3On;
	int x;
	int y;};
	obstacle3 obs3[100];
	int obstacle3Index =0;
char upperBackGroundImage[10][20] = { "up\\1.bmp", "up\\2.bmp", "up\\3.bmp", "up\\4.bmp", "up\\5.bmp", "up\\6.bmp", "up\\7.bmp", "up\\8.bmp", "up\\9.bmp", "up\\10.bmp"};
char lowerBackGroundImage[10][20] = { "low\\1.bmp", "low\\2.bmp", "low\\3.bmp", "low\\4.bmp", "low\\5.bmp", "low\\6.bmp", "low\\7.bmp", "low\\8.bmp", "low\\9.bmp", "low\\10.bmp"};
char pointImage[20]={"point\\1.bmp"};

struct point1{
bool point1On;
int x;
int y;
};
point1 points1[100];
int pointIndex1 = 0;

struct point2{
bool point2On;
int x;
int y;
};
point2 points2[100];
int pointIndex2 = 0;

struct menuCordinate
{
	int x;
	int y;
}mCordinate[5];

int mposx,  mposy;

char bm[12][20] = {"bm\\1.bmp","bm\\2.bmp","bm\\3.bmp","bm\\4.bmp","bm\\5.bmp","bm\\6.bmp","bm\\7.bmp","bm\\8.bmp","bm\\9.bmp","bm\\11.bmp","bm\\12.bmp"};
char bg[25] = {"background\\b1.bmp"};
char credits[20] = {"Credit\\1.bmp"};
char highscore[20] = {"highscore\\1.bmp"};
char instructions[20] = {"instructions\\1.bmp"};
char jumpp[2][15] = {"ju\\1.bmp","ju\\2.bmp"};
char button[5][25] = {"button\\1.bmp","button\\2.bmp","button\\3.bmp","button\\4.bmp","button\\5.bmp"};
char stand[15] = {"st\\bmp 2.bmp"};
char obstacleImage[3][20]={"obstac\\1.bmp","obstac\\2.bmp","obstac\\3.bmp"};
char whiteImage[20] = {"white\\1g.bmp"};

int bmIndex = 0;
int meenax = 120,meenay= 80;
int standCounter = 0;

bool standPosition =true  ;
bool jump = false ;
bool jumpUp = false ;

int jumpcordinatey = 0;

int gameState= -1 ;
char dead[20] = {"dead\\dead.bmp"};
int z=0 ;
void iDraw()
{

	iClear();

	
	

	FILE *fp = fopen("data1.txt", "r");
		
		fscanf(fp, "%d", &bestScore);		
		sprintf(S1, "%d", bestScore);
		
		fclose(fp);




	




	if(jump)
	{
		if(jumpUp)
		{
			iShowBMP2(meenax,meenay + jumpcordinatey,jumpp[0],0);
		}
		else
		{
			iShowBMP2(meenax,meenay + jumpcordinatey,jumpp[1],0);
		}
	}

	else
	{
		if(!standPosition)
			{
				iShowBMP2(meenax,meenay,bm[bmIndex],0);
				standCounter++;

				if(standCounter >=20)
					{
						standCounter = 0 ;
						bmIndex = 0;
						standPosition= true ;
					}
			}
		else
			{
				iShowBMP2(meenax,meenay,stand,0);
			}
	}


	if (gameState == -1)
		{
			iShowBMP(0,0,bg);
			if(!musicOn){	
			musicOn= true;
	PlaySound("song\\1.wav",NULL,SND_LOOP | SND_ASYNC);
			}
			musicOn1 = false ;



				for (int i =0 ;i<5;i++)
					{
						iShowBMP2(mCordinate[i].x,mCordinate[i].y,button[i],0);
					}


		}
	else if(gameState == 3)
	{
		iShowBMP(0,0,credits);
	}
	else if(gameState == 1)
	{
		iShowBMP(0,0,instructions);
	}
	else if(gameState == 2)
	{
		iShowBMP(0,0,highscore );
					
		fp = fopen("data1.txt", "r");
		
		fscanf(fp, "%d", &bs);		
		sprintf(S1, "%d", bs);
		fclose(fp);
		iSetColor(255,255,255);
		iText(672,500,S2,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(672,300,S1,GLUT_BITMAP_TIMES_ROMAN_24);

	 


	}
	else if(gameState == 4)
	{
		exit(0);
	}

	else if(gameState == 0)
		{  

			if(musicOn){
			musicOn = false;
			PlaySound(0,0,0);}

			
			if(!musicOn1)
			{musicOn1 = true;
			PlaySound("song1\\1.wav",NULL,SND_LOOP | SND_ASYNC);}
			
		


			for (int i = 0; i<10; i++)
	{
		iShowBMP(upperBackGround[i].x, upperBackGround[i].y, upperBackGroundImage[i]);
		iShowBMP(lowerBackGround[i].x, lowerBackGround[i].y, lowerBackGroundImage[i]);
		
		
	}

			iShowBMP(0,0,whiteImage);
			if(heart1){iShowBMP2(0,0,hart[0],16777215);}
			if(heart2)iShowBMP2(0,100,hart[1],16777215);
			if(heart3)iShowBMP2(0,200,hart[2],16777215);


			iSetColor(0,255,0);
		iText(50,450,S, GLUT_BITMAP_TIMES_ROMAN_24);
		
		



if(scoree > bestScore){
		
			fp = fopen("data1.txt", "w");
		
			fprintf(fp,"%d", scoree);
			fclose(fp);
			
		}

			for(int i = 0 ; i<100;i++)
			{
				if(obs1[i].obstacle1On)iShowBMP2(obs1[i].x,obs1[i].y,obstacleImage[0],0);			//new
				if(obs2[i].obstacle2On)iShowBMP2(obs2[i].x,obs2[i].y,obstacleImage[1],0);
				if(obs3[i].obstacle3On)iShowBMP2(obs3[i].x,obs3[i].y,obstacleImage[2],0);
				if(points1[i].point1On)iShowBMP2(points1[i].x,points1[i].y,pointImage,0);
				if(points2[i].point2On)iShowBMP2(points2[i].x,points2[i].y,pointImage,0);
			}

			for(int i = 0 ; i<100;i++)
			{
				if(obs1[i].obstacle1On)iShowBMP2(obs1[i].x,obs1[i].y,obstacleImage[0],0);			//new
				
			}
			if(thiefOn){
			iShowBMP2(thiefx,thiefy,thief[thiefIndex],0);
			}



			if(jump)
				{
					if(jumpUp)
						{
							for (int i = 0; i<10; i++){
		upperBackGround[i].x -= upperBackGroundSpeed;
		lowerBackGround[i].x -= lowerBackGroundSpeed;

		if (upperBackGround[i].x <= 0)
		{
			upperBackGround[i].x =990;
			
			
		}
		if (lowerBackGround[i].x <= 0)
		{
			lowerBackGround[i].x = 1000;
		}

		
		
		} 



							iShowBMP2(meenax,meenay + jumpcordinatey,jumpp[0],0);
						}
			else
					{

						for (int i = 0; i<10; i++){
		upperBackGround[i].x -= upperBackGroundSpeed;
		lowerBackGround[i].x -= lowerBackGroundSpeed;

		if (upperBackGround[i].x <= 0)
		{
			upperBackGround[i].x =990;
			
			
		}
		if (lowerBackGround[i].x <= 0)
		{
			lowerBackGround[i].x = 1000;
		}

		
		
		} 

						iShowBMP2(meenax,meenay + jumpcordinatey,jumpp[1],0);
			
					}
				}

	else
		{
			if(!standPosition)
				{
					

					iShowBMP2(meenax,meenay,bm[bmIndex],0);
					standCounter++;
					if(standCounter >=20)
						{
							standCounter = 0 ;
							bmIndex = 0;
							standPosition= true ;}
				}
		else
			{
				iShowBMP2(meenax,meenay,stand,0);
			}
		}

	}


	if(!heart3)iShowBMP(0,0,dead);

	} 
	

	



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for(int i = 0 ;i<5 ;i++)
			{
				if(mx>=mCordinate[i].x && mx<=mCordinate[i].x+150 && my>=mCordinate[i].y+8 && my<=mCordinate[i].y+28)
					{
						
						gameState = i;
					}
			}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == ' ')
		{
			if(!jump)
				{
					jump = true;
					jumpUp = true;
		}//do something with 'q'

		}
	if(key == 'a')
		{
		gameState = -1;
		z= 0 ;
		scoree = 0;
		heart1= true;
		heart2= true;
		heart3= true;
		
		
		
		
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_RIGHT)
		{
	       
			


			for (int i = 0; i<10; i++){
				
		upperBackGround[i].x -= upperBackGroundSpeed;
		lowerBackGround[i].x -= lowerBackGroundSpeed;

		if (upperBackGround[i].x <= 0)
		{
			upperBackGround[i].x =990;
			
			
		}
		if (lowerBackGround[i].x <= 0)
		{
			lowerBackGround[i].x = 1000;
		}

		
		
		} 

           

		


			meenax +=0;
			bmIndex++;
			if(bmIndex>=11)
				 bmIndex = 0;
				 standPosition = false;

				 
		}
	if(key == GLUT_KEY_LEFT)
	{
		meenax -=0;
		bmIndex--;
		 if(bmIndex<0)
		 bmIndex = 10;
		 standPosition = false;

	}
	//place your codes for other keys here
}
//
void change()
{
	if(jump)
		{
			if(jumpUp)
				{
					jumpcordinatey +=5;
					if(jumpcordinatey > JUMPLIMIT)
						{
							jumpUp =false;
						}
				}
		else
			{
				jumpcordinatey -=5;
				if(jumpcordinatey < 0)
					{
						jump =false;
						jumpcordinatey = 0;}
			}
		}
}

void setAll()
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i<10; i++)
	{
		upperBackGround[i].y = 110;
		lowerBackGround[i].y = 0;
		upperBackGround[i].x = sum1;
		lowerBackGround[i].x = sum;

		sum += 110;
		sum1 += 100;

	}

}



void kane(){
	
	for (int i = 0; i<10; i++){
		upperBackGround[i].x -= upperBackGroundSpeed;
		lowerBackGround[i].x -= lowerBackGroundSpeed;

		if (upperBackGround[i].x <= 0)
		{
			upperBackGround[i].x =990;
			
			
		}
		if (lowerBackGround[i].x <= 0)
		{
			lowerBackGround[i].x = 1000;
		}

		
		
		} 
			
	}

void arriveObstacle1(){															//new
	obs1[obstacle1Index].obstacle1On=true;
	obs1[obstacle1Index].x=1000;
	obs1[obstacle1Index].y=90;
	obstacle1Index++;
	if(obstacle1Index>100)obstacle1Index=0;
}
void arriveObstacle2(){
	obs2[obstacle2Index].obstacle2On=true;
	obs2[obstacle2Index].x=1000;
	obs2[obstacle2Index].y=75;
	obstacle2Index++;
	if(obstacle2Index>100)obstacle2Index=0;
}
void arriveObstacle3(){
	obs3[obstacle3Index].obstacle3On=true;
	obs3[obstacle3Index].x=1000;
	obs3[obstacle3Index].y=55;
	obstacle3Index++;
	if(obstacle3Index>100)obstacle3Index=0;
}

void arrivePoints1(){
	points1[pointIndex1].point1On = true;
	points1[pointIndex1].x = 1000;
	points1[pointIndex1].y =200 ;
	pointIndex1++;
	if(pointIndex1>100)pointIndex1 = 0;


}

void arrivePoints2(){
	points2[pointIndex2].point2On = true;
	points2[pointIndex2].x = 1000;
	points2[pointIndex2].y =300 ;
	pointIndex2++;
	if(pointIndex2>100)pointIndex2 = 0;


}


int length[100];
int length1[100];
int lengthObstacle1[100];


void speedObstacle(){
	for(int i=0;i<100;i++){	
	
		
		if(obs1[i].obstacle1On){
			obs1[i].x -= 15;
			length[i] = obs1[i].x - meenax;
			length1[i] =(obs1[i].y+85)-  ( meenay+jumpcordinatey);


			if((length[i]<=88) && (length1[i]>=25)){
				obs1[i].obstacle1On=false;
				
				if(!heart2){heart3 = false;}
				if(!heart1)
				{heart2 = false;}
				
				heart1= false;
			}
				
					
			

			
			if(obs1[i].x<=0)obs1[i].obstacle1On=false;
			
			
			
		}
		if(obs2[i].obstacle2On){
			obs2[i].x -= 15;
			length[i] = obs2[i].x - meenax;
			length1[i] =(obs2[i].y+70)-  ( meenay+jumpcordinatey);
			if(length[i]<=88 && length1[i]>=25){
			
				obs2[i].obstacle2On=false;
			
			if(!heart2){heart3 = false;}
				if(!heart1)
				{heart2 = false;}
				
				heart1= false;
			}
			if(obs2[i].x<=0)obs2[i].obstacle2On=false; 
		}

		if(obs3[i].obstacle3On){
			obs3[i].x -= 15;
			length[i] = obs3[i].x - meenax;
				length1[i] =(obs3[i].y+58)-  ( meenay+jumpcordinatey);
			if(length[i]<=88 && length1[i]>=14 ){
				obs3[i].obstacle3On=false;
			if(!heart2){heart3 = false;}
				if(!heart1)
				{heart2 = false;}
				
				heart1= false;
			}
			if(obs3[i].x<=0)obs3[i].obstacle3On=false; 
		}

		if(points1[i].point1On){
			points1[i].x -= 15;
			length[i] = points1[i].x - meenax;
				length1[i] =(points1[i].y+40)-  ( meenay+jumpcordinatey);
			if(length[i]<=88 && length1[i]>=14 )
				{points1[i].point1On=false;
			scoree+=10;}

			
			if(points1[i].x<=0)points1[i].point1On=false; 
		}

			if(points2[i].point2On){
			points2[i].x -= 15;
			length[i] = points2[i].x - meenax;
				length1[i] =(points2[i].y+40)-  ( meenay+jumpcordinatey);
			if(length[i]<=88 && length1[i]<=200 )
			{	points2[i].point2On=false;
			    scoree+=10;
			}
			
			if(points2[i].x<=0)points2[i].point2On=false; 
		}

	}
}
void score()
{
	if(gameState == 0)
		
		
		
		{
		scoree++;
		
		}
	sc = scoree;

	sprintf(S, "SCORE: %d", sc);
	sprintf(S2, "%d", sc);
	
	if(bestScore<sc)
	{
		bestScore = sc;
	}

}

int thiefresult;
void thiefchange(){

if(thiefOn){
thiefIndex++;
if(thiefIndex>6)thiefIndex = 0;

if(standPosition){
thiefx+=20;

}
else
	thiefx-=10;
	




}}

void thiefboolcheck(){
	thiefresult = thiefx - meenax;
	if(thiefresult <110)thiefOn = false;
	else
	thiefOn = true;




}




int main()
{
	int sum =150;
	for(int i = 4 ;i>=0;i--)
	{
		mCordinate[i].x = 700;
		mCordinate[i].y = sum;
		sum+=60;
	}
	iSetTimer(25,change);
		//place your own initialization codes here.

	
	setAll();
	iSetTimer(10000,arriveObstacle1);												//new
	iSetTimer(40000+rand()%5000,arriveObstacle2);
	iSetTimer(20000+rand()%5000,arriveObstacle3);
	iSetTimer(5000 + rand()%3000,arrivePoints1);
	iSetTimer(8000+rand()%5000,arrivePoints2);
	iSetTimer(25,speedObstacle);
	iSetTimer(1000,score);
	iSetTimer(50,thiefchange);
	iSetTimer(500,thiefboolcheck);
	

	if(musicOn)
		PlaySound("song\\1.wav",NULL,SND_LOOP | SND_ASYNC);


	iInitialize(1000, 600, "An Adventure With Meena");
	
	
	return 0;
	
}
