#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//Name: Abed alrheem Fialah / ID: 1220216 / LabC section : 7L

void displayMainMenu();
void addBook(int bins[],double prices[],int *size);
void removeBook(int bins[],double prices[],int *size);
void searchForBook(int bins[],double prices[],int size);
void uploadDataFile(int bins[],double prices[],int *size);
void updateDataFile(int bins[],double prices[],int size);
void printBook(int bins[],double prices[],int size);

int bins[MAXSIZE];
double prices[MAXSIZE];
int n=0;

int main()
{
    printf("Welcome to my BookStore Management System !\n");
    int i;
    uploadDataFile(bins,prices,&n);
    displayMainMenu();
    scanf("%d",&i);
    while(1) // Loop used to repeat showing the menu
        {
    if(i==1){ // If statement used to determine which function to print
        addBook(bins,prices,&n);
    }else if(i==2){
        removeBook(bins,prices,&n);
    }else if(i==3){
        searchForBook(bins,prices,n);
    }else if(i==4){
        printBook(bins,prices,n);
    }else if(i==5){
       updateDataFile(bins,prices,n);
       break; // (break) is used to get out of the cycle
   }
    else {
        printf("no such operation, Please try again !\n");
    }
    displayMainMenu();
    scanf("%d",&i);

}
}
void displayMainMenu(){ // Function is used to display the main menu

    printf("\nPlease Select an Operation (1-4):\n1- Add a Book\n2- Remove a Book\n3- Search for a Book\n4- Print Book List\n5- Exit System\n");
}

void addBook(int bins[],double prices[],int *size){
    if((*size)< MAXSIZE){

    int bookbin;
    int flag = 0;
    printf("Enter bin number for book : \n");
    scanf("%d",&bookbin);

    for(int i=0;i<(*size)-1;i++){
    if (bins[i] == bookbin){
        flag = 1;
        printf("error, there is similar bin number !");
        break;
    }
    }
    if (flag==0){
  bins[(*size)-1] = bookbin;
  printf("\aPlease enter the price of book: \n");
  scanf("%lf", &prices[(*size)-1]);
  (*size)++ ;
  printf("book with id: %d has been added. \n\n", bookbin);
}


for(int i =0; i<((*size)-1); i++){
for(int j=0; j<((*size)-2); j++){

     if(bins[j]>bins[j+1]){

     int temp = bins[j];
     bins[j] = bins[j+1];
     bins[j+1] = temp;

     int temp2 = prices[j];
     prices[j] = prices[j+1];
     prices[j+1] = temp2;

    }}
    }
}
}

void removeBook(int bins[], double prices[], int *size){
    if (*size > 0)
    {
   int bookbin;
   int flag = 0;

   printf("Enter bin number for book to remove: ");
   scanf("%d", &bookbin);
   for (int i = 0; i < MAXSIZE; i++)
   {
       if (bins[i] == bookbin)
       {
           flag = 1;

           if (i < MAXSIZE - 1)
           {

               for (int j = i; j < MAXSIZE - 1; j++)
               {

                   bins[j] = bins[j + 1];
                   prices[j] = prices[j + 1];
               }
           }
           (*size)--;
            printf("Book with bin %d has beed removed !", bookbin);
       }
   }


   if (flag == 0)
   {
       printf("Book with bin %d does not exist !", bookbin);
   }
    }
    else
    {
   printf("There is no book to remove !");
    }
}


void searchForBook(int bins[],double prices[],int size){
    if(size>0){
            int bookbin;
            int flag =0;
            printf("Enter bin number for book to search for: ");
            scanf("%d",&bookbin);

            for(int i=0;i<MAXSIZE;i++){
            if(bins[i]==bookbin){
            flag = 1;
            printf("bin# = %d\tprice# = %f",bins[i],prices[i]);
            }
            size++;
}

if(flag == 0){
    printf("book with %d bin does not exist",bookbin);

}}else{printf("there is no bin book to search for !");}}

void uploadDataFile(int bins[],double prices[],int *size){
   printf("\nUploading data file ...\n");
   int inputBookbin = 0;
   int i=0;
   double inputPrice =0.0;
   FILE *input;
   input = fopen("books.txt","r");
while (fscanf(input,"%d %lf",&inputBookbin,&inputPrice)!= EOF){
    bins[i]=inputBookbin;
    prices[i]=inputPrice;
    i++;
   }
   *size = i +1;
   printf("Data File uploaded");
}

void updateDataFile(int bins[],double prices[],int size){
   printf("\nUpdating data file ...");

   FILE *output;
   output = fopen("book.txt","w");
   int outputBookbin = 0;
   double outputPrice = 0.0;
   int i = 0;

   while(i<(size-1)){

    outputBookbin = bins[i];
    outputPrice = prices[i];
    fprintf(output,"bin# = %d\tprice# = %f\n",outputBookbin,outputPrice);
    i++;
   }
   fclose(output);
   printf("\nData File updated !");
   printf("\n\nThank you for using my BookStore Management System, Good Bye\n");

}
void printBook(int bins[],double prices[],int size){

    for(int i=0;i<(size-1);i++){
    printf("bin# = %d\tprice# = %f\n",bins[i],prices[i]);
}
}
