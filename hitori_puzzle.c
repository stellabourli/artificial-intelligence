#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 8*8   //plh8os tetragwnwn-metavlhtwn

int array[8][8] = {{4,8,1,6,3,2,5,7},{3,6,7,2,1,6,5,4},{2,3,4,8,2,8,6,1},{4,1,6,5,7,7,3,5},{7,2,3,1,8,5,1,2},{3,5,6,7,3,1,8,4},{6,4,2,3,5,4,7,8},{8,7,1,4,2,3,5,6}};
int check[8][8] = {{4,8,1,6,3,2,5,7},{3,6,7,2,1,6,5,4},{2,3,4,8,2,8,6,1},{4,1,6,5,7,7,3,5},{7,2,3,1,8,5,1,2},{3,5,6,7,3,1,8,4},{6,4,2,3,5,4,7,8},{8,7,1,4,2,3,5,6}};

void print_array(int array[8][8])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)	
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}

int periorismos1(int i,int j)
{
	int found = 0;
	int k,l;
	for(k=0;k<8;k++)
	{
		if(k!=i)
		{
			if(array[k][j]==array[i][j] && array[i][j]!=0)
			{
				found = 1;
				return found;
			}
		}
	}

	found = 0;
	for(l=0;l<8;l++)
	{
		if(l!=j)
		{
			if(array[i][l]==array[i][j] && array[i][j]!=0)
			{
				found=1;
				return found;
			}
		}
	}
	return found;
}

int periorismos2(int i,int j)
{
	int mauro = 0;
	if(i==0 && j==0) 
	{
		if(array[i][j] == 0 && (array[i+1][j] == 0 || array[i][j+1] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i==0 && j==7)
	{
		if(array[i][j] == 0 && (array[i][j-1] == 0 || array[i+1][j] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i==7 && j==0)
	{
		if(array[i][j] == 0 && (array[i-1][j] == 0 || array[i][j+1] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i==7 && j==7)
	{
		if(array[i][j] == 0 && (array[i-1][j] == 0 || array[i][j-1] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i==0 && j!=7)
	{
		if(array[i][j] == 0 && (array[i][j-1] == 0 || array[i][j+1] == 0 || array[i+1][j] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i!=7 && j==0)
	{
		if(array[i][j] == 0 && (array[i-1][j] == 0 || array[i+1][j] == 0 || array[i][j+1] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i==7 && j!=7)
	{
		if(array[i][j] == 0 && (array[i][j-1] == 0 || array[i][j+1] == 0 || array[i-1][j] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else if(i!=7 && j==7)
	{
		if(array[i][j] == 0 && (array[i-1][j] == 0 || array[i+1][j] == 0 || array[i][j-1] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	else
	{
		if(array[i][j] == 0 && (array[i][j-1] == 0 || array[i][j+1] == 0 || array[i-1][j] == 0 || array[i+1][j] == 0))
		{
			mauro = 1;
			return mauro;
		}
	}
	return mauro;
}

void geitonas(int i,int j,int *ni,int *nj)
{
	int e=0,r;
	int epiloges[4];
	if(i!=0)
	{
		epiloges[e] = 0;
		e++;
	}
	if(i!=7)
	{
		epiloges[e] = 1;
		e++;
	}
	if(j!=0)
	{
		epiloges[e]=2;
		e++;
	}
	if(j!=7)
	{
		epiloges[e]=3;
		e++;
	}
	r = rand()%e;
	if(epiloges[r] == 0)
	{
		*ni = i-1;
		*nj = j;
	}
	else if(epiloges[r] == 1)
	{
		*ni = i+1;
		*nj = j;
	}
	else if(epiloges[r] == 2)
	{
		*ni = i;
		*nj = j-1;
	}
	else if(epiloges[r] == 3)
	{
		*ni = i;
		*nj = j+1;
	}
}

int kostos(int i,int j)
{
	int d;
	if(periorismos1(i,j)==1 && periorismos2(i,j)==1)
	{
		d=2;
	}
	else if(periorismos1(i,j)==1 && periorismos2(i,j)==0)
	{
		d=1;
	}
	else if(periorismos1(i,j)==0 && periorismos2(i,j)==1)
	{
		d=1;
	}
	else
	{
		d=0;
	}
	return d;
}

int luthike()
{
	int i,j;
	int l=1;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(periorismos1(i,j)!=0 || periorismos2(i,j)!=0)
			{
				l=0;
				return l;
			}
		}
	}
	return l;
}

void change(int i,int j)
{
	if(i==0 && j==0) 
	{
		array[i+1][j] = check[i+1][j]; //katw
		array[i][j+1] = check[i][j+1]; //deksia
	}
	else if(i==0 && j==7)
	{
		array[i][j-1] = check[i][j-1]; //aristera
		array[i+1][j] = check[i+1][j]; //katw
	}
	else if(i==7 && j==0)
	{
		array[i-1][j] = check[i-1][j]; //panw
		array[i][j+1] = check[i][j+1]; //deksia
	}
	else if(i==7 && j==7)
	{
		array[i-1][j] = check[i-1][j]; //panw
		array[i][j-1] = check[i][j-1]; //aristera
	}
	else if(i==0 && j!=7)
	{
		array[i][j-1] = check[i][j-1]; //aristera
		array[i][j+1] = check[i][j+1]; //deksia
		array[i+1][j] = check[i+1][j]; //katw
	}
	else if(i!=7 && j==0)
	{
		array[i-1][j] = check[i-1][j]; //panw
		array[i+1][j] = check[i+1][j]; //katw
		array[i][j+1] = check[i][j+1]; //deksia
	}
	else if(i==7 && j!=7)
	{
		array[i][j-1] = check[i][j-1]; //aristera
		array[i][j+1] = check[i][j+1]; //deksia
		array[i-1][j] = check[i-1][j]; //panw
	}
	else if(i!=7 && j==7)
	{
		array[i-1][j] = check[i-1][j]; //panw
		array[i+1][j] = check[i+1][j]; //katw
		array[i][j-1] = check[i][j-1]; //aristera
	}
	else
	{
		array[i][j-1] = check[i][j-1]; //aristera
		array[i][j+1] = check[i][j+1]; //deksia
		array[i-1][j] = check[i-1][j]; //panw
		array[i+1][j] = check[i+1][j]; //katw
	}
}


void SA(float T,int dokimes,float meiwsh,int termatismos)
{
	int row = 0;
	int colomn = 0;
	array[row][colomn] = 0;
	int ni,nj;
	int tryfail = 0;
	int st=0,m=0;
	while(tryfail<termatismos && T>0 && luthike()==0)
	{
		int steps = 0;
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!megalo whileee....\n");
		while(steps != dokimes)
		{
			geitonas(row,colomn,&ni,&nj);
			printf("geitonas: %d,%d\n",ni,nj);
			int d = kostos(ni,nj)-kostos(row,colomn);
			printf("%d-%d=kostos: %d\n",kostos(ni,nj),kostos(row,colomn),d);
			if(d<0)
			{
				row = ni;
				colomn = nj;
				printf("1\n");
				if(periorismos1(row,colomn)==1)
				{
					printf("HERE");//EDW
					change(row,colomn);
					array[row][colomn] = 0;
				}
				st+=1;
			}
			else if((rand()/(float)RAND_MAX) < (1/(1+exp(d/T))))
			{
				row = ni;
				colomn = nj;
				printf("2\n");
				if(periorismos1(row,colomn)==1)
				{
					change(row,colomn);
					array[row][colomn] = 0;
				}
				st+=1;
			}
			else
			{
				st+=1;
				m+=1;
				if(st==m)
				{
					tryfail+=1;
				}
				else
				{
					st=0;
					m=0;
					tryfail=1;
				}
				printf("3\n");
			}
			steps+=1;
			print_array(array);
			printf("steps: %d\n",steps);
		}
		T = meiwsh*T;
		printf("T: %f\n",T);
		printf("tryfail: %d\n",tryfail);
	}
}

int main()
{
	print_array(array);
	float T = 10.0;
	int dokimes = 2*N;
	float meiwsh = 0.999;
	int termatismos = 6*N;
	SA(T,dokimes,meiwsh,termatismos);
	print_array(array);
	return 0;
}