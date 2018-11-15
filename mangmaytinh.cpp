#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
#define vocuc 666

int Doc_Dothi(char filename[], int [][MAX], int &);
void Xuat_Matran(int [][MAX], int);
int Dijkstra(int [][MAX],int,int );

main(){
	int a[MAX][MAX],n,s;
	char duongdan[30],kt; 

	while (1){
	printf("Duong dan cua do thi bieu dien: ");
	scanf("%s",duongdan);
	
	if (Doc_Dothi(duongdan,a,n)){
		Xuat_Matran(a,n);
		printf("Ban hay chon dinh goc: ");
		scanf("%d",&s);
		if (Dijkstra(a,n,s)==0)
			printf("Do thi xuat phat tu %d khong lien thong !",s);
	}	
	printf("\nNhan mot phim bat ky de tiep tuc!\n");
	scanf("%s",&kt);
	if (kt=='N' || kt=='n')
		break;
	printf("\n");
	}
	getch();		
}

int Doc_Dothi(char filename[], int a[MAX][MAX], int &n) {
	FILE *f;
	f=fopen(filename, "rt");
	if(f==NULL) {
		printf("Loi mo file !!!\n"); 
		printf("co the ban chon duong dan ko dung, vd: e:\\dothi.txt \n\n");
		return 0;  
	}
	fscanf(f,"%d\n",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			fscanf(f,"%d",&a[i][j]);
		fscanf(f,"\n");
	}
	fclose(f);
	return 1;	
}

void Xuat_Matran(int a[][MAX], int n) {
	printf("\n");
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int Dijkstra(int a[][MAX],int n,int s) {
	int Mark[MAX],d[MAX],pr[MAX], k,min,dem;
	
	for(int i=0;i<n;i++){
		d[i]=vocuc;			
		Mark[i]=0; 	
		pr[i]=s;		
	}
	
	for(int j=0;j<n;j++) {
		if(a[s][j])	
			d[j]=a[s][j];
	}
	
	d[s]=0;			
	Mark[s]=1; 		
	
	dem=n-1;			
	while (dem>0) {		
		min = vocuc;   		
		for(int i=0;i<n;i++)			
			if ((Mark[i]==0) && (d[i]<min)) {
				min = d[i];
				k = i;
			}
		if (min==vocuc){
			printf("Do thi khong lien thong");
			return 0;
		}
		Mark[k]=1;							
		for (int j=0;j<n;j++) 				
			if ((Mark[j]==0) && (d[k]+a[k][j]<d[j]) && (a[k][j]>0)) {
				d[j]=d[k]+a[k][j];
				pr[j]=k;
			}
		dem--;
	}

	for (int i=0;i<n;i++)
		if (i!=s)	
			if(d[i]==vocuc)		
				printf("ko co duong di tu %d->%d\n",s,i);
			else {
				printf("duong di tu %d->%d co do dai la: %d . ",s,i,d[i]);
				printf("Cac dinh di qua la : ");
			 	int mang[MAX];
			 	dem=0;
			 	int tam=pr[i];
			 	while (tam!=s) {
			 		mang[dem]=tam;
			 		tam=pr[tam];
			 		dem++;
			 	}
			 	printf("%d->",s);
			 	for (int j=dem;j>0;j--)
			 		printf("%d->",mang[j-1]);
		 		printf("%d\n",i);
			}
	return 1;
}
