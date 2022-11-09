#include<iostream>
#define MAX 100
#define inputfile "matran12.txt"
#define outputfile "bai2.TXT"
typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;
DOTHI g;

int DOCMATRANKE(DOTHI &g)
{
	FILE* f;
	f = fopen(inputfile, "rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file");
		return 0;
	}
	fscanf(f,"%d", &g.n);
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		fscanf(f,"%d",&g.a[i][j]);
	}
	fclose(f);
	return 1;
}

void displayMatrix(DOTHI g)
{
    int n = g.n ; 
    for(int i=0; i< n ; i++)
    {
        for(int j = 0 ;  j < n ;j++)
        {
            printf("%d\t",g.a[i][j]) ; 
        }
        printf("\n") ;  
    }
}

void ditimdothilienthong(DOTHI g, int x[MAX], int i)
{
    for(int j = 0;j<g.n;j++ )
        if(g.a[i][j]!=0 && x[j]!=x[i])
        {
            x[j]=x[i];
            ditimdothilienthong(g,x,j);
        }
}

void xetlienthong(DOTHI g)
{
    int x[MAX];
     
    int i;
    for(i=0;i<g.n;i++)
        x[i]=0;
    int Sotplienthong=0;
    for(i=0;i<g.n;i++)
        if(x[i]==0)
        {
            Sotplienthong++;
            x[i] = Sotplienthong;
            ditimdothilienthong(g,x,i);
        }
    printf("\nSo thanh phan lien thong la %d\n", Sotplienthong);
    for(i=1;i<=Sotplienthong;i++)
    {
        printf("\nThanh phan lien thong thu %d gom cac dinh : ", i);

            for(int j = 0; j < g.n ; j++)
            {
                        if(x[j] == i)
                        {
                            printf("%d\t",j) ;
                        }

            }
            printf("\n") ; 
           
    }

}

int main()
{
    printf("hello world!") ;  
    printf("\n Ma tran duoc khoi tao: \n") ; 
    DOCMATRANKE(g) ;  
    displayMatrix(g); printf("\n") ;  

    displayMatrix(g);
    printf("\nPress any keys!!!");

    xetlienthong(g);

}