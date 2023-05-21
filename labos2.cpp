#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

int pohlepniA(vector<vector<int>> vect) {
    int rez=0;
    int start=0;
    int end=0;
    int min= INT_MAX;
    int lowest_nextS;
    int lowest_nextE;
    int n= vect.size();
    int lowest_S;
    int lowest_E;
    int counter=0;
    vector<int> key(n);
    
    for(int i=0;i<key.size();i++)
        key[i]=0; 

    for(int i=0;i<n;i++) {
        for(int j=0;j<vect.size();j++) {
            if(vect[i][j]<min && vect[i][j]!=0) {
                start=i;
                end=j;
                min=vect[i][j];
            }
        }
    }
   // cout<< "ovo je min " << min<<endl;
    key[start]=1;    // zakljucani
    key[end]=1;

    rez+=min;
    
    while(counter<n-2) {
        lowest_nextS=INT_MAX;
        lowest_nextE=INT_MAX;
        for(int i=0;i<n;i++) {
            if(key[i]!=1) {
                if(vect[start][i]<lowest_nextS) {
                    lowest_nextS=vect[start][i];
                    lowest_S=i;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(key[i]!=1) {
                if(vect[end][i]<lowest_nextE) {
                    lowest_nextE=vect[end][i];
                    lowest_E=i;
                }
            }
        }
      //  cout<< lowest_nextE << " " <<lowest_nextS<< endl;
       // cout<< start << " " << end <<  " start end" <<endl;
        if(lowest_nextE<lowest_nextS) {
            rez+=lowest_nextE;
            end=lowest_E;
            key[end]=1;
        } else {
            rez+=lowest_nextS;
            start=lowest_S;
            key[start]=1;
        }
      //  cout<< start << " nakon ifa " << end << endl;
        counter++;
    }

    rez+=vect[start][end];

    return rez;
}

int iscrpniA(vector<vector<int>> vect) {
    int rez=INT_MAX;
    int start=0;
   

    vector<int> tmp;
    for(int i=0;i<vect.size();i++) {
        if(i!=start) {
            tmp.push_back(i);
        }
    }

    do {

         int curr=0;

        int k=start;
        for(int i=0;i<tmp.size();i++) {
            curr+=vect[k][tmp[i]];
            k=tmp[i];
        }
        curr+=vect[k][start];

        rez=min(rez,curr);

    } while(next_permutation(tmp.begin(),tmp.end()));
    



    return rez;
}

void print(vector<vector<int>> vect) {
    for(int i=0;i<vect.size();i++) {
        for(int j=0;j<vect.size();j++) {
            cout<< vect[i][j] << " ";
        }
        cout<< endl;
    }
    cout<<endl;
}

int main(void) {

    int n, a, b;

    cout<<"unesite redom, odvojene razmakom, parametre n, a i b: ";
    cin>> n;
    cin>> a;
    cin>> b;

    // (ak+bl)2 + 1 

    vector<vector<int>> aux(n, vector<int> (n,0));

   

    for(int k=0;k<n;k++) {
        for(int l=0;l<n;l++) {
            
            if(k==l) {
                aux[k][l]=0;
            } else if(k<l){
                aux[k][l]=pow((a*(k+1)+b*(l+1)), 2) +1;
                aux[l][k]=pow((a*(k+1)+b*(l+1)), 2) +1;
            }
        }
        
    }

    print(aux);
    

    
    int rezP=pohlepniA(aux);
 
   int rezI=iscrpniA(aux);

    cout<< "Pohlepni algoritam nalazi ciklus duljine " << rezP << endl;
    cout<<"Iscrpni algoritam nalazi ciklus duljine " << rezI << endl;

    if(rezP==rezI) {
        cout<< "Pohlepni algoritam na ovom grafu daje optimalno rjesenje";
    } else {
        
        cout<< "Pohlepni algoritam na ovom grafu ne daje optimalno rjesenje";
    }
    
    return 0;
}