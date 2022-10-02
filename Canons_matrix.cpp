

#include<bits/stdc++.h>
using namespace std;

void rotate1(int a[][4],int a1[][4],int i,int d,int n)
{
    int temp[4][4];
     int k = 0;
    for (int s = d; s < n; s++) {
        temp[i][k] = a[i][s];
        k++;
    }

     for (int s = 0; s < d; s++) {
        temp[i][k] = a[i][s];
        k++;
    }
    for (int s = 0; s < n; s++) {
        a1[i][s] = temp[i][s];
    }
}


void rotate2(int b[][4],int b1[][4],int i,int d,int n)
{
    int temp[4][4];
     int k = 0;
    for (int s = d; s < n; s++) {
        temp[k][i] = b[s][i];
        k++;
    }

     for (int s = 0; s < d; s++) {
        temp[k][i] = b[s][i];
        k++;
    }
    for (int s = 0; s < n; s++) {
        b1[s][i] = temp[s][i];
    }
}


void rotate1left(int a[][4],int a1[][4],int i,int d,int n)
{
    int temp[4][4];
     int k = 0;
    for (int s = d; s < n; s++) {
        temp[i][k] = a[i][s];
        k++;
    }

     for (int s = 0; s < d; s++) {
        temp[i][k] = a[i][s];
        k++;
    }
    for (int s = 0; s < n; s++) {
        a1[i][s] = temp[i][s];
    }
}

void rotate1up(int b[][4],int b1[][4],int i,int d,int n)
{

     int temp[4][4];
     int k = 0;
    for (int s = d; s < n; s++) {
        temp[k][i] = b[s][i];
        k++;
    }

     for (int s = 0; s < d; s++) {
        temp[k][i] = b[s][i];
        k++;
    }
    for (int s = 0; s < n; s++) {
        b1[s][i] = temp[s][i];
    }
}



void multiply1(int c1[][4],int a[][4],int b[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            c1[i][j]=a[i][j]*b[i][j];
        }
    }
}


void result1(int c1[][4],int c2[][4],int c3[][4],int c4[][4],int c[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            c[i][j]=c1[i][j]+c2[i][j]+c3[i][j]+c4[i][j];
        }
    }
}

int main()
{

    int n=4;
    int a[4][4]={{2,3,4,5},{9,8,7,6},{5,4,2,3},{8,7,3,4}};
    int b[4][4]={{3,5,7,6},{2,7,6,3},{7,5,3,2},{4,3,2,5}};

    //cout<<"Enter elements for array a"<<endl;
    //for(int i=0;i<n;i++)
   // {
    //    for(int j=0;j<n;j++)
     //   {

//            cin>>a[i][j];
  //      }
   // }

    int d=0;
    int a1[4][4];
    int b1[4][4];
    for(int i=0;i<n;i++)  //left shifting by 0,1,2,3
    {
      rotate1(a,a1,i,d,n);
      d++;
    }

    d=0;
    for(int i=0;i<n;i++)   //Up shifting by 0,1,2,3
    {

        rotate2(b,b1,i,d,n);
        d++;
    }





    int c1[4][4];
    multiply1(c1,a1,b1);




    int a2[4][4];
    for(int i=0;i<n;i++)
    {
      rotate1left(a1,a2,i,1,n);

    }

    int b2[4][4];
    for(int i=0;i<n;i++)
    {
        rotate1up(b1,b2,i,1,n);
    }


    int c2[4][4];
    multiply1(c2,a2,b2);

    int a3[4][4];
    int b3[4][4];

    for(int i=0;i<n;i++)  //Finding a3 by using a2 using 1 left shift
    {
        rotate1left(a2,a3,i,1,n);
    }

    for(int i=0;i<n;i++)   //Finding b3 by using b2 using 1 up shift
    {
        rotate1up(b2,b3,i,1,n);
    }

     int c3[4][4];  //Calculating c3
     multiply1(c3,a3,b3);



    int a4[4][4];
    int b4[4][4];

    for(int i=0;i<n;i++)  //Finding a4 by using a3 using 1 left shift
    {
        rotate1left(a3,a4,i,1,n);
    }


    for(int i=0;i<n;i++)  //Finding b4 by using b3 using 1 left shift
    {
        rotate1up(b3,b4,i,1,n);
    }


    int c4[4][4]; //calculating c4
    multiply1(c4,a4,b4);


    int c[4][4]; //calculating final result
    result1(c1,c2,c3,c4,c);



    for(int i=0;i<n;i++)  //Printing all elements
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

}
