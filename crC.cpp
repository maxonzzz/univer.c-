#include <iostream>

#include <fstream>

using namespace std;

int main()

{ int i,j; 

int n=6;

int mas[n]; 

// масив заповнили випадковими значеннями від 0 до 100

for (i= 0;i <= (n-1); i++)

{ mas[i]= rand() % 101; 

if ((i%7) == 0 && (i!=0)) { cout <<" "<< mas[i]<<endl;} // вив-мо по 7 елем у рядку

else { cout <<" "<< mas[i]; }

}



int temp = 0;

for (i= 0;i <= (n-1); i++){

for (j= 0; j<= (n-2-i); j++) {

if (mas[j] > mas[j+1]) {

temp = mas[j+1] ;

mas[j+1] = mas[j] ;

mas[j] = temp; 

}} 

}


cout <<endl<< "sort mas:"<<endl;

//  відсортований масив

for (i= 0;i <= (n-1); i++)

{

if ((i%7) == 0 && (i!=0)) { cout <<" "<< mas[i]<<endl;} // вив-мо по 7 елем у строчці

else { cout <<" "<< mas[i]; }


}

    ofstream fout("buble.txt"); //  об'экт класа ofstream для запису и звязування його з файлом 
    for (j= 0;j <= (n-1); j++)
    {
    fout << " " << mas[j] ;
    }
     // запись строки в файл
    fout.close(); // закрываем файл
    system("pause");



return 0;

}
