/*						      submitted on May 5,2012

	Computer Graphics mini project about Encoding Schemes :
	-------------------------------------------------------
			T.Y. B.Tech(Comp)

	Names as per the roll numbers:

     *-----------------------------------------------------*
     |	Name of Student	    |	Scheme	      |	 Roll No   |
     |=====================================================|
     |	Chavhan Krishna	    |	Manchester    |	 20096010  |
     |-----------------------------------------------------|
     |	Ekonde Sharad	    |	NRZ-I         |	 20090615  |
     |-----------------------------------------------------|
     |	Khandagale Pramod   |   NRZ-L	      |	 20090630  |
     |-----------------------------------------------------|
     |	Khandare Jayendra   |   U-NRZ	      |	 20090631  |
     |-----------------------------------------------------|
     |	Khatal Shital	    |	Polar-RZ      |	 20090632  |
     |-----------------------------------------------------|
     |	Kirnapure Wrushal   |	AMI	      |	 20090634  |
     |-----------------------------------------------------|
     |	Parve Vaibhav	    |	Psuedoternary |	 20090643  |
     |-----------------------------------------------------|
     |	Sangle Anand	    |	D.Manchester  |	 20090657  |
     *-----------------------------------------------------*

		under the guidance of Ms.Heena Gite
				     ===============
*/

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

	int i,j,mx,my,x,y,flag=1,txt,time=7,col=5;
	int gd=DETECT,gm;

/*
	variables used:

	*integers :
	-----------
			gd,dm: for graphics initialization
			mx,my: for mid of x - axis and y - axis respectively
			i,j  : for various loops
			x,y  : for printing locations as point(x,y)
			flag : used int AMI() & PSUEDO() for marking something
			txt  : used to denote the location of bitstream char
			       to print on x - axis
			time : used to decide time interval in milliseconds
			       used only along with putpixel()
			col  : used for coloring the lines of encoding
*/

void layout(int len)//	for drawing the general layout for every scheme
{
	initgraph(&gd,&gm,"X:/BGI");
	mx=getmaxx()/2;
	my=getmaxy()/2;

	//co ordinate axes
	line(25,my,mx*2-25,my);
	line(25,25,25,my*2-25);

	x=25;
	setlinestyle(DASHED_LINE,1,1);
	for(j=0;j<len;j++)
	line(x,25,x+=50,my*2-25);
	settextstyle(5,0,1);

}

void U_NRZ(char ip[])//Jay Khandare	unipolar-NRZ encoding scheme
{
	layout(strlen(ip));

	outtextxy(mx,25,"unipolar-NRZ Encoding Scheme");

	x=25;	y=my;	i=-1;	txt=0;

	while(++i<10)
	{
		if(ip[i]=='1')
		{
			if(y==my)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			else if(y==my-50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			outtextxy(txt+=50,50,"1");
		}
		if(ip[i]=='0')
		{
			if(y==my)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			else if(y==my-50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x,y++,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			outtextxy(txt+=50,50,"0");
		}
	}
	getch();
	closegraph();
}

void NRZL(char ip[])//Pramod K	NRZ-L encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,25,"NRZ-L Encoding Scheme");

	x=25;	txt=0;

	if(ip[0]=='1')
	y=my+50;
	else
	y=my-50;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]=='0')
		{
			outtextxy(txt+=50,50,"0");
			if(y==my-50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			if(y==my+50)
			{
				for(j=1;j<101;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
		}

		if(ip[i]=='1')
		{
			outtextxy(txt+=50,50,"1");
			if(y==my+50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			if(y==my-50)
			{
				for(j=1;j<101;j++)
				{
					putpixel(x,y++,col);
					delay(time);
				}

				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
		}
	     }

	getch();
	closegraph();
}

void NRZI(char ip[])//Sharad	NRZ-I encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,25,"NRZ-I Encoding Scheme");



	x=25;	y=my-50;	txt=0;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]=='0')
		{
			outtextxy(txt+=50,50,"0");
			if(y==my-50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
		       else if(y==my+50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
		}
			if(ip[i]=='1')
			{
				outtextxy(txt+=50,50,"1");
				if(y==my-50)
				{
					for(j=1;j<101;j++)
					{
						putpixel(x,y++,col);
						delay(time);
					}
					for(j=1;j<51;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}

				}
			       else if(y==my+50)
				{
					for(j=1;j<101;j++)
					{
						putpixel(x,y--,col);
						delay(time);
					}
					for(j=1;j<51;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}
				}
			}
	}
	     getch();
	     closegraph();
}

void P_RZ(char ip[])//Khatal	polar-RZ encoding scheme
{
	layout(strlen(ip));

	outtextxy(mx,25,"polar-RZ Encoding Scheme");

	x=25;	y=my;	i=-1;	txt=0;

	while(++i<10)
	{
		if(ip[i]=='0')
		{
			for(j=1;j<26;j++)
			{
				putpixel(x,y++,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x++,y,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x,y--,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x++,y,col);
				delay(time);
			}
			outtextxy(txt+=50,50,"0");
		}

		else if(ip[i]=='1')
		{
			for(j=1;j<26;j++)
			{
				putpixel(x,y--,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x++,y,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x,y++,col);
				delay(time);
			}
			for(j=1;j<26;j++)
			{
				putpixel(x++,y,col);
				delay(time);
			}
			outtextxy(txt+=50,50,"1");
		}
	}
	getch();
	closegraph();
}

void MANC(char ip[])//KChavhan	Manchester encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,25,"Manchester Encoding Scheme");

	x=25;	txt=0;

	if(ip[0]=='0')
	y=my-50;
	else
	y=my+50;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]=='0')
		{
			outtextxy(txt+=50,50,"0");
			if(y==my-50)
			{
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
				for(j=1;j<101;j++)
				{
				      putpixel(x,y++,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
			}

			else if(y==my+50)
			{
				for(j=1;j<101;j++)
				{
				      putpixel(x,y--,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
				for(j=1;j<101;j++)
				{
				      putpixel(x,y++,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
			}
		}

		if(ip[i]=='1')
		{
			outtextxy(txt+=50,50,"1");
			if(y==my+50)
			{
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
				for(j=1;j<101;j++)
				{
				      putpixel(x,y--,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
			}
		       else if(y==my-50)
			{
				for(j=1;j<101;j++)
				{
				      putpixel(x,y++,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
				for(j=1;j<101;j++)
				{
				      putpixel(x,y--,col);
				      delay(time);
				}
				for(j=1;j<26;j++)
				{
				      putpixel(x++,y,col);
				      delay(time);
				}
			 }
		}
	    }
	getch();
	closegraph();
}

void DMANC(char ip[])//AASangle Differntial Manchester encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,25,"Differential Manchester Encoding Scheme");

	x=25;	y=my-50;	txt=0;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]=='0')
		{
			outtextxy(txt+=50,50,"0");
			if(y==my-50)
			{
			   for(j=1;j<101;j++)
			   {
				putpixel(x,y++,col);
				delay(time);
			   }
			  for(j=1;j<26;j++)
			   {
				putpixel(x++,y,col);
				delay(time);
			   }
			   for(j=1;j<101;j++)
			   {
				putpixel(x,y--,col);
				delay(time);
			   }
			   for(j=1;j<26;j++)
			   {
				putpixel(x++,y,col);
				delay(time);
			   }
			}
			else if(y==my+50)
			{
				for(j=1;j<101;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
				for(j=1;j<26;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
				for(j=1;j<101;j++)
				{
					putpixel(x,y++,col);
					delay(time);
				}
				for(j=1;j<26;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
		}
			if(ip[i]=='1')
			{
				outtextxy(txt+=50,50,"1");
				if(y==my-50)
				{
					for(j=1;j<26;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}
					for(j=1;j<101;j++)
					{
						putpixel(x,y++,col);
						delay(time);
					}
					for(j=1;j<26;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}
			}
				else if(y==my+50)
				{
					for(j=1;j<26;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}
					for(j=1;j<101;j++)
					{
						putpixel(x,y--,col);
						delay(time);
					}
					for(j=1;j<26;j++)
					{
						putpixel(x++,y,col);
						delay(time);
					}
				 }
			}
		}
		getch();
		closegraph();
}

void AMI(char ip[])//W Kirnapure	AMI encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,25,"AMI Encoding Scheme");

	x=25;	y=my;	txt=0;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]== '0')
		{
			outtextxy(txt+=50,50,"0");
			if(y==my)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
			else if(y==(my-50))
			{
				for(j=1;j<51;j++)
				{
					putpixel(x,y++,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			  }

			else if(y==my+50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
	    }
		if(ip[i]=='1')
		{
		       outtextxy(txt+=50,50,"1");
		       if( (flag%2) ==1)
		       {

			   for(j=1;j<51;j++)
			   {
				putpixel(x,y--,col);
				delay(time);
			   }
			   for(j=1;j<51;j++)
			   {
				putpixel(x++,y,col);
				delay(time);
			   }
			   for(j=1;j<51;j++)
			   {
				putpixel(x,y++,col);
				delay(time);
			   }
		       flag++;
		      }
		      else
		      {
			       for(j=1;j<51;j++)
			       {
					putpixel(x,y++,col);
					delay(time);
			       }
			       for(j=1;j<51;j++)
			       {
					putpixel(x++,y,col);
					delay(time);
			       }
				for(j=1;j<51;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
			flag++;
		      }
	       }
	}

	getch();
	closegraph();
}

void PSEUDO(char ip[])//VBParve	  Psuedoternary encoding scheme
{

	layout(strlen(ip));

	outtextxy(mx,50,"Psuedo-ternary Encoding Scheme");

	x=25;	y=my;	txt=0;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]== '1')
		{
			outtextxy(txt+=50,50,"1");
			if(y==my)
			{    for(j=1;j<51;j++)
			     {
			     putpixel(x++,y,col);
			     delay(time);
			     }
			}
			else if(y==(my-50))
			{
				for(j=1;j<51;j++)
				{
				  putpixel(x,y++,col);
				  delay(time);
				}
				for(j=1;j<51;j++)
				{
				    putpixel(x++,y,col);
				    delay(time);
				}
			  }
			else if(y==my+50)
			{
				for(j=1;j<51;j++)
				{
					putpixel(x,y--,col);
					delay(time);
				}
				for(j=1;j<51;j++)
				{
					putpixel(x++,y,col);
					delay(time);
				}
			}
	    }
		if(ip[i]=='0')
		{
		       outtextxy(txt+=50,50,"0");
		       if( (flag%2) ==1)
		       {
			   for(j=1;j<51;j++)
			   {
				putpixel(x,y--,col);
				delay(time);
			   }
			   for(j=1;j<51;j++)
			   {
				putpixel(x++,y,col);
				delay(time);
			   }
			   for(j=1;j<51;j++)
			   {
				putpixel(x,y++,col);
				delay(time);
			   }
		       flag++;
		      }
		      else
		      {
			       for(j=1;j<51;j++)
			       {
					putpixel(x,y++,col);
					delay(time);
			       }
			       for(j=1;j<51;j++)
			       {
					putpixel(x++,y,col);
					delay(time);
			       }
			       for(j=1;j<51;j++)
			       {
					putpixel(x,y--,col);
					delay(time);
			       }
			flag++;
		      }
	       }
	}

	getch();
	closegraph();
}
