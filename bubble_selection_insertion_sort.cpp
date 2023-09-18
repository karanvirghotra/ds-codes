//printing choice to do sorting bubble selection or insertion 
#include <iostream>

using namespace std;

void display(int arr[],int n)
{
cout<<"\nIndex:: ";
for (int i=0;i<n;i++)
cout<<i<<" ";
cout<<"\nArray:: ";
for (int i=0;i<n;i++)
cout<<arr[i]<<" ";
}

void bubble(int arr[],int n)
{
int temp,step=1;
for (int i=0;i<n;i++)

for(int j=0;j<n-i-1;j++)
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
cout<<"\n\nAfter step "<<step<<"::";



display(arr,n);
step++;
}
}
void selection(int arr[],int n)
{
int temp,step=1,min=0;
cout<<"\n1. Selection Sort ::";
for(int i=0;i<n-1;i++)
{
for (int j=i+1;j<n;j++)
if(arr[j]<arr[min])
min=j;
if(min!=i){
temp=arr[i];
arr[i]=arr[min];
arr[min]=temp;
cout<<"\n\nAfter step "<<step<<"::";
display(arr,n);
step++;
}
min=i+1;

}
}

void inseration(int arr[],int n)



{
int temp,i,j,step=1;
for (int i=1;i<n;i++)
{
for (j=i;j>0;j--)
{
if(arr[j]<arr[j-1])
{
temp=arr[j];
arr[j]=arr[j-1];
arr[j-1]=temp;
cout<<"\n\nAfter step "<<step<<"::";
display(arr,n);
step++;
}
}
}
}
void choice (int arr[],int n)
{
int ch;
cout<<"\n Enter sorting ::";
cout<<"\n1. Bubble sorting";
cout<<"\n2. Selection sorting";
cout<<"\n3. insertion sorting ";
cout<<"\n Enter choice ::";
cin>>ch;



if(ch==1){
cout<<"-------------------------------------";
bubble(arr,n);
cout<<"\n-------------------------------------";
}
else if(ch ==2){
cout<<"-------------------------------------";
selection(arr,n);
cout<<"\n-------------------------------------";
}
else if (ch==3)
{
cout<<"-------------------------------------";
inseration(arr,n);
cout<<"\n-------------------------------------";

}
else
cout<<"\n Wrong choice !!";

}

int main()
{
int n,i;
cout<<"\n Enter number of element ::";
cin>>n;



int arr[n];
cout<<"\n Enter element one by one ::";
for (i=0;i<n;i++)
cin>>arr[i];
choice(arr,n);
cout<<"\n\n\nAfter final sorting ::";
display(arr,n);
return 0;

}