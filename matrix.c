/*
	@author : Keshav Kabra
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#define ROW 3
#define COL 3
float A[ROW][COL];
float B[ROW][COL];
float s[ROW][COL]={0};
float c[ROW][COL]={0};
void gotoxy(short int col,short int row)
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(h,position);
}
void getmat(float m[ROW][COL],int p,int q)
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			gotoxy(p,q);
			scanf("%f",&m[i][j]);
			p=p+8;	
		}
		p=2;
		q=q+1;
	}
}
void disp_mat(float m[ROW][COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("  %2f\t",m[i][j]);
		}
		printf("\n");
	}
}
void sum(float m[ROW][COL],float n[ROW][COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			s[i][j]=m[i][j]+n[i][j];
		}
	}
}
void subtract(float m[ROW][COL],float n[ROW][COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			s[i][j]=m[i][j]-n[i][j];
		}
	}
}
void mult(float m[ROW][COL],float n[ROW][COL])
{
	int i,j,k,sum=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			s[i][j]=0;
			for(k=0;k<3;k++)
			{
				s[i][j]=s[i][j]+(m[i][k]*n[k][j]);
			}
		}
	}
}
void transp(float m[ROW][COL])
{
	int i,j,flag=1;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			s[i][j]=m[j][i];
		}
	}
	disp_mat(s);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(s[i][j]!=A[i][j])
			{
				flag=0;
				break;
			}
		}
	}
	if(flag==1)
		printf("\n  Entered Matrix was SYMMETRIC MATRIX !\n");
	else
		printf("\n  Entered Matrix was NOT a SYMMETRIC MATRIX !\n");
}
float determ(float m[ROW][COL])
{
	int i,j=1,k=2;
	float sum=0.0;
	for(i=0;i<ROW;i++)
	{
		if(i==2)
			k=1;
		sum=sum+m[0][i]*pow(-1,i)*(m[1][j]*m[2][k]-m[2][j]*m[1][k]);
		j=0;
	}
	return(sum);
}
void max_mat(float m[ROW][COL])
{
	int i,j;
	float temp;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL-1;j++)
		{
			if(m[i][j]>m[i][j+1])
			{
				temp=m[i][j];
				m[i][j]=m[i][j+1];
				m[i][j+1]=temp;
			}
		}
	}
	printf("\nHighest elements of corresponding ROWS :\n");
	for(i=0;i<ROW;i++)
	{
		printf("%f\n",m[i][ROW-1]);
	}
	printf("Highest Element of Matrix :\n");
	for(i=0;i<ROW-1;i++)
	{
		if(m[i][ROW-1]>m[i+1][ROW-1])
		{
			temp=m[i][ROW-1];
			m[i][ROW-1]=m[i+1][ROW-1];
			m[i+1][ROW-1]=temp;
		}
	}
	printf("%f\n",m[ROW-1][ROW-1]);
}
void min_mat(float m[ROW][COL])
{
	int i,j,temp;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL-1;j++)
		{
			if(m[i][j]<m[i][j+1])
			{
				temp=m[i][j];
				m[i][j]=m[i][j+1];
				m[i][j+1]=temp;
			}
		}
	}
	printf("\nSmallest elements of corresponding ROWS :\n");
	for(i=0;i<ROW;i++)
	{
		printf("%f\n",m[i][ROW-1]);
	}
	printf("Smallest Element of Matrix :\n");
	for(i=0;i<ROW-1;i++)
	{
		if(m[i][ROW-1]<m[i+1][ROW-1])
		{
			temp=m[i][ROW-1];
			m[i][ROW-1]=m[i+1][ROW-1];
			m[i+1][ROW-1]=temp;
		}
	}
	printf("%f\n",m[ROW-1][ROW-1]);
}
void minor(float m[ROW][COL])
{
	int i,j,a,b,c,d;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			a=1,b=2,c=1,d=2;
			if(i>=1) a=0;
			if(i==2) b=1;
			if(j>=1) c=0;
			if(j==2) d=1;
			s[i][j]=((m[a][c]*m[b][d])-(m[a][d]*m[b][c]));
		}
	}
}
void cofactor(float m[ROW][COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			B[i][j]=pow(-1,i+j)*m[i][j];
		}
	}
}
void adjoint(float m[ROW][COL])
{
	int i,j;
	transp(m);
}
void inverse(float m[ROW][COL],float n[ROW][COL])
{
	int i,j;
	float s=determ(n);
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			c[i][j]=m[i][j]/s;
		}
	}
}
int main()
{
	int oprtn,repeat=1;
	while(repeat==1)
	{
		system("cls");
		printf("\n************************* MATRIX CALCULATOR ***********************************\n\n");
		printf("Enter the Operation you want to do :\n\n");
		printf("1. Sum of matrices\t          2. Subtraction of matrices\n");
		printf("3. Multiplication of matrices\t  4. Transpose of matrix (Symmetrical or Not)\n");
		printf("5. Determinent of matrix\t  6. Largest and Smallest Number of matrix\n");
		printf("7. Minor and Cofactor of matrix\t  8. Adjoint and Inverse of matrix\n");
		printf("\n*******************************************************************************\n\n");
		scanf("%d",&oprtn);
		if(oprtn==1||oprtn==2||oprtn==3)
		{
			printf("\nEnter %d elements of 1st Matrix :\n",ROW*COL);
			getmat(A,2,16);
			printf("Enter %d elements of 2nd Matrix :\n",ROW*COL);
			getmat(B,2,21);
			system("cls");
			printf("Entered Matrix A :\n");
			disp_mat(A);
			printf("\nEntered Matrix B :\n");
			disp_mat(B);
		}
		if(oprtn==4||oprtn==5||oprtn==6||oprtn==7||oprtn==8)
		{
			printf("\nEnter %d elements of any Matrix :\n",ROW*COL);
			getmat(A,2,16);
			system("cls");
			printf("Entered Matrix is :\n");
			disp_mat(A);
		}
		switch(oprtn)
		{
		
			case(1):
				{
				
					printf("\nSum of Entered Matrices :\n");
					sum(A,B);
					disp_mat(s);
					break;
				}
			case(2):
				{
					printf("\nSubtraction Result of Entered Matrices (A-B) :\n");
					subtract(A,B);
					disp_mat(s);
					break;
				}
			case(3):
				{
					printf("\nMultiplication Result of Entered Matrices(A*B) :\n");
					mult(A,B);
					disp_mat(s);
					break;
				}	
			case(4):
				{
					printf("\nTranspose of Entered Matrix :\n");
					transp(A);
					break;
				}
			case(5):
				{
					determ(A);
					printf("\nDeterminent of Entered Matrix = %f",determ(A));
					break;
				}
			case(6):
				{
					max_mat(A);
					min_mat(A);
					break;
				}
			case(7):
				{
					minor(A);
					printf("\nMinor(s) of Entered Matrix:\n");
					disp_mat(s);
					cofactor(s);
					printf("\nCofactor(s) of Entered Matrix :\n");
					disp_mat(B);
					break;
				}
			case(8):
				{
					minor(A);
					cofactor(s);
					printf("\nAdjoint of Entered Matrix :\n");
					adjoint(B);
					printf("\nInverse of Entered Matrix :\n");
					inverse(s,A);
					disp_mat(c);
					break;
				}
			default :
				{
					printf("\nInvalid key Entered !!");
					break;
				}
		}
		printf("\n\nRepeat Process again - Press 1 for YES and Any Other key to terminate :\n");
		scanf("%d",&repeat);
	}
	printf("\n\nHope you liked the service !!\n");
	printf("Program designed by :\n\n \t **** KESHAV KABRA ****\n");
	getch();
}
