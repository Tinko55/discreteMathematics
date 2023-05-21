#include <iostream>
#include <math.h>
using namespace::std;


double recursion(int n, double lambda1, double lambda2, double a0, double a1) {

    
    double an;
   
    if(n==0) {

        return a0;
    }
    else if(n==1) {
        return a1;
    } else {
         
        while(n>1) {
       
        return lambda1*recursion(n-1,lambda1,lambda2,a0,a1)+ lambda2*recursion(n-2,lambda1,lambda2,a0,a1);
       }
    }
   
    return an;

}



int main(void) {

    double lambda1;
    double lambda2;
    double a0;
    double a1;
    int n;
    
    cout << "Unesite prvi koeficijent λ_1 rekurzivne relacije: ";
    cin >> lambda1;
    cout << "Unesite drugo koeficijent λ_2 rekurzivne relacije: ";
    cin >> lambda2;
    cout << "Unesite vrijednost nultog clana niza a_0: ";
    cin >> a0;
    cout << "Unesite vrijednost prvog clana niza a_1:";
    cin >> a1;
    cout << "Unesite redni broj n trazenog clana niza:";
    cin >> n;

    double result1;  //rekurzivno
    double result2;  // pomocu formule
    double result3; // n-2 clan

  

    double A;
    double B;

    double determinanta= lambda1*lambda1 +4*1*(lambda2);

    double x1= (lambda1 + sqrt(determinanta))/2;   
    double x2 = (lambda1 - sqrt(determinanta) )/2;
   

    if(determinanta==0) {
        A=a0;       
                      //Ax1+Bnx2=a0
        B=(a1-A*x1)/x2;
                    //Ax1+Bnx2=a1
        result2=A*pow(x1,n)+B*n*pow(x2,n);
        result3=A*pow(x1, (n-2)) +B*(n-2)*pow(x2, (n-2));
       } else {
           B=(a1-a0*x1)/(x2-x1);
           A=a0-B;
       result2=A*pow(x1,n)+B*pow(x2,n);
       result3=A*pow(x1, (n-2)) +B*pow(x2, (n-2));
    }



    result1=recursion(n, lambda1, lambda2, a0, a1);
    cout<< "Vrijednost n-tog clana niza pomocu formule: " << result2 << "\n";
    cout<< "Vrijednost n-tog clana niza iz rekurzije: " << result1 << "\n";
    cout<< "Vrijednos (n-2) člana niza pomoću formule : "<< result3 << "\n";
    
    if(result3 > result2) {
        cout << "(n-2) člana je" << " veci "<<"od n-tog člana";
    }
    else if(result3 < result2) {
        cout << "(n-2) člana je " << "manji "<<"od n-tog člana";
    } else {
         cout << "(n-2) člana je " << " jednak "<<"od n-tog člana";
    }
    

   return 0;
}

