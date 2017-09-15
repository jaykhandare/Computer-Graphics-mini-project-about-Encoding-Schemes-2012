/*
		Comp Graphics mini project about encoding schemes :

		further details about working are given in "CGPROJ.H"
*/


#include"CGPROJ.H"
int check(char[]);

void main()
{
	int ch,i;
	char ip[10];
	clrscr();

	printf("Welcome ! ! ! \n\nLet's Start The Program.\n\n");
	getch();

Change_ip:

	printf("\nEnter bitstream for conversion : ");
	scanf("%s",ip);

	if(check(ip))
	{
		printf("\n\nWrong bitstream entered.\n\nTry Again . . .\n");
		goto Change_ip;
	}

Change_enc:

	printf("\nSelect an encoding scheme from the followings :\n");
	printf("1.Unipolar NRZ\n");
	printf("2.NRZ - L\n");
	printf("3.NRZ - I\n");
	printf("4.Polar - RZ\n");
	printf("5.Manchester\n");
	printf("6.Differential Manchester\n");
	printf("7.AMI\n");
	printf("8.Psuedoternary\n");
	printf("9.Change bitstream\n");
	printf("10.E X I T\n : ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			U_NRZ(ip);
			break;
		case 2:
			NRZL(ip);
			break;
		case 3:
			NRZI(ip);
			break;
		case 4:
			P_RZ(ip);
			break;
		case 5:
			MANC(ip);
			break;
		case 6:
			DMANC(ip);
			break;
		case 7:
			AMI(ip);
			break;
		case 8:
			PSEUDO(ip);
			break;
		case 9:
			goto Change_ip;

		case 10:
			printf("\n\n\n\n\t\t\tThank You for using me ! \n");
			getch();
			exit();
		default:
			clrscr();
			printf("\n\nWrong Choice . . .\nTry Again . . .\n");
	}
	goto Change_enc;
}

int check(char ip[])
{
	int i;

	for(i=0;i<strlen(ip);i++)
	{
		if(ip[i]=='1'||ip[i]=='0')
		{}
		else
		{
			return(1);
		}
	}
	return(0);
}