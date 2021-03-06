#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <sstream>


using namespace std;

// A?ACI BASTIRMAK ???N FONKS?YON

int printTree(int x, int y, char* array,
              int index,
              int total_elements)
{

    // ?LK KONTROL
    if (index >= total_elements)
        return NULL;

    ostringstream str1;
    str1 << array[index];

    string str2 = str1.str();
    char* str = &str2[0u];

    // DA?RELER?N RENG?N? BEL?RLEME
    setcolor(GREEN);

    // DA?RE ??ZD?RME
    circle(x, y, 20);
    floodfill(x, y, GREEN);

    // ??ZG?LER?N RENG?N? BEL?RLEME
    setcolor(GREEN);

    // SOL VE SAG D?G?MLER? AYIRMA
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    printTree(x - y / (index + 1), y + 50,
              array, left, total_elements);

    printTree(x + y / (index + 1), y + 50,
              array, right, total_elements);

    // C?ZG?LER? C?ZD?RME
    if (left < total_elements)
    {
        line(x, y, x - y / (index + 1), y + 50);
    }

    if (right < total_elements)
    {
        line(x, y, x + y / (index + 1), y + 50);
    }


    setcolor(YELLOW);

    circle(150, 100, 20);
    floodfill(150, 100, YELLOW);
    line(300,150,150,100);

    circle(450, 100, 20);
    floodfill(450, 100, YELLOW);
    line(300,150,450,100);




    outtextxy(200,118,"bxac");
    outtextxy(146,88,"3");
    outtextxy(375,116,"c");
    outtextxy(200,176,"xa");
    outtextxy(200,216,"c");
    outtextxy(245,240,"4");
    outtextxy(448,88,"6");
    outtextxy(92,220,"bxac");
    outtextxy(46,240,"1");
    outtextxy(375,172,"a");
    outtextxy(401,217,"bxac");
    outtextxy(380,240,"2");
    outtextxy(480,217,"c");
    outtextxy(515,240,"5");


    settextstyle(3,HORIZ_DIR,1);
    outtextxy(285,145,"K?K");




    return NULL;
}

// ARANAN KATARI BULMAK ?C?N FONKS?YON
int katarbul(char *getWord,char *findKatar,int size1,int size2)
{
    int i=0,j=0,k=0,n=-1;
    while(i<(size1-size2))
    {
        j=0;
        k=i;
        n=1;
        while(j<size2)
        {
            //ALINAN KATARI VE ?STENEN KATARI KAR?ILA?TIRMA
            if(getWord[k]!=findKatar[j])
            {
                n=0;
                break;
            }

            j++;
            k++;
        }

        if(n==1)
            return i;
        i++;
    }
    return -1;
}
int main()
{


    char getWord2[50];
    char getWord[50];

    //TANIMLAMALAR
    char *str;
    char*str1;
    int i,k,sayy;
    char findKatar[500];
    FILE *ptr;
    ptr=fopen("katar.txt","w");

    char iste[16];
    printf("Katari giriniz: ");
    scanf("%s",&iste);

    fprintf(ptr,"%s",iste);
    fclose(ptr);

    for(int oo=0; oo<100; oo++) {}

    fopen("katar.txt","r");

    fscanf(ptr,"%s",&getWord);

    strcpy(getWord2,getWord);

    char son_ek[strlen(getWord)][50];
    char on_ek[strlen(getWord)][50];


    str=getWord;


    //ONEK VE SONEKLER? BASTIRMAK ???N FOR D?NG?LER?
    for(i=0; i<strlen(getWord); i++)
    {

        strcpy(son_ek[i],str+i);


    }
    int countt=strlen(getWord);

    for(i=0; i<strlen(getWord); i++)
    {
        printf("%s",son_ek[i]);
        printf("\n");
    }

    printf("\n\n");

    for(i=0; i<strlen(getWord); i++)
    {

        for(k=0; k<=i; k++)
        {
            on_ek[i][k]=getWord[k];
        }
        on_ek[i][k]='\0';
    }

    printf("\n");

    int sayac3=0;

    for(i=0; i<strlen(getWord2)+strlen(getWord); i++)
    {

        strcpy(on_ek[i],getWord2);
        getWord2[strlen(getWord2)-1]='\0';
        sayac3++;
    }

    for(i=0; i<countt; i++)
    {
        //ONEK BASTIR
        printf("\n%s",on_ek[i]);
    }

    printf("\n\n\n");

    int temp=1;

    for(i=1; i<countt; i++)
    {

        if(strcmp(son_ek[i],on_ek[i])==0)
        {

            temp=0;
            break;
        }
    }

    if(temp==0)
    {

        printf("Girdiginiz Katar icin Suffix Tree olusturulamiyor...\n\n");
    }
    else
    {

        printf("Girdiginiz Katar icin Suffix Tree olusturulabiliyor...\n\n\n");

    }
    for(int i=0; i<100; i++) {}
    char sa;
    printf("Aramak istediginiz Katari giriniz: ");
    scanf("%s",&findKatar);


    //gets(findKatar);


    //ARANAN KATARI VE ??EREN KATARI KAR?ILA?TIRMA
    int countt2=strlen(findKatar);
    int deger=katarbul(getWord,findKatar,countt,countt2);
    int adet1=0,adet2=0;
    for (i=0; i<countt; i++)
    {

        adet2=0;
        for(int k=0; k<countt; k++)
        {

            for(int j=0; j<countt2; j++)
            {
                if(getWord[k+j]==findKatar[j])
                {
                    adet1++;
                }
                else
                {
                    adet1=0;
                }
            }
            if(adet1==countt2)
            {
                adet2++;
            }
        }
        adet1=0;
    }
    if(deger==-1)
    {
        printf("Aranan  P  Katari  s  Katarini icermemektedir. ");
    }
    else
    {
        printf("Aranan  P Katari  s  Katarinin ( %d. ) karakterinden baslayan Soneginin ( %d. ) karakterinde sonlanan onegidir\nAranan katardan ( %d ) adet bulunmaktadir.\n\n",deger+1,countt2,adet2);
    }
    char t,tut_char;

    int nkucuk=0,kucuk=0,min=0,max=0;
    for(int j=0; j<countt; j++)
    {
        max=min;
        nkucuk=0;
        t=getWord[j];
        for(int o=0; o<countt; o++)
        {
            if(t==getWord[o])
            {
                nkucuk++;
            }
        }
        min=nkucuk;
        if(min>=max)
        {
            kucuk=nkucuk;
            tut_char=t;
        }
    }

    printf("\nEn cok tekrar eden altkatar ( %c ) ve ( %d ) defa tekrar etmektedir.\n\n",tut_char,kucuk);



    int b,a,y,n=2,n_adet=0,count_number=0,biggest,x_max=0,x_min=0,biggest_x;
    max=0;
    min=0;
    int x=0;

    char l[20];

    //TEKRAR EDEN EN UZUN ALT KATARI BULMAK
    for(n=2; n<7; n++)
    {
        for (x=0; x<5; x++)
        {


            char katar_alt[n];
            for(i=0; i<n; i++)
            {
                katar_alt[i]=getWord[i+x];
            }
            for(i=0; i<19; i++)
            {
                max=min;
                for(int j=0; j<n; j++)
                {
                    if(getWord[i+j]==katar_alt[j])
                    {
                        n_adet++;
                    }
                    else
                    {
                        n_adet=0;
                    }
                }
                if(n_adet==n)
                {
                    count_number++;
                }
                min=count_number;
                if(max<min)
                {
                    biggest=min;

                }
                n_adet=0;
                x_max=x_min;
                x_min=biggest;
                if(x_max<x_min)
                {
                    biggest_x=x_min;
                    for(a=0; a<n; a++)
                    {
                        l[a]=katar_alt[a];
                    }
                    b=n;
                }


            }


            count_number=0;
        }
    }
    printf("\n");

    if(biggest_x==1)
    {
        printf("S katari icinde en cok tekrar eden en uzun altkatar %s'dir ve ( 1 ) kere tekrar etmektedir.\n\n\n",iste);
    }
    else
    {
        printf("S katari icinde en cok tekrar eden en uzun altkatar( ");
        for(i=0; i<b; i++)
        {
            printf("%c",l[i]);
        }
        printf(" ) 'dir ve ( %d ) defa tekrar etmektedir.\n\n\n",biggest_x);

    }


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "None");

    /*
    		1
    	/	 \
    	2	 3
    / \	 / \
    4 5 6 7
    / \ /
    8 9 10
    */

    char array[128];

    // FONKS?YON ?A?IRMA
    printTree(300, 150, array, 0, 7);
    getch();

    // BELLEKTE BO?A YER KAPLAMAMASI ???N GRAF??? SERBEST BIRAKMA
    closegraph();





    return 0;
}
