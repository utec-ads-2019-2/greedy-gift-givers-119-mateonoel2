#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int personas, count = 0;
    while(cin>>personas){
        string grupo[personas];

        string regalador[personas];
        vector<int> plataGastada;
        int a;
        vector<int> cantidad_recividores;
        int b;
        string recividor;
        vector<string> recividores;
        vector<vector<string>> grupo_de_recividores;
        int moneys[personas];
        int temp = 0;

        for(int i=0; i<personas; i++){
            cin>>grupo[i];
            moneys[i]=0;
        }
        for(int i=0; i<personas; i++){
            cin>>regalador[i];
            cin>>a;
            plataGastada.push_back(a);
            cin>>b;
            cantidad_recividores.push_back(b);
            for(int j=0; j<cantidad_recividores[i];j++){
                cin>>recividor;
                recividores.push_back(recividor);
            }
            grupo_de_recividores.push_back(recividores);
            recividores.clear();
        }

        for(int i=0; i<personas; i++){
            for(int j=0; j<personas; j++){
                if(grupo[i]==regalador[j]){
                    swap(regalador[j], regalador[i]);
                    swap(plataGastada[j], plataGastada[i]);
                    swap(cantidad_recividores[j], cantidad_recividores[i]);
                    swap(grupo_de_recividores[j], grupo_de_recividores[i]);
                }
            }
        }

        for(int i=0; i<personas; i++){
            if(cantidad_recividores[i] == 0) continue;
            temp = floor(plataGastada[i]/cantidad_recividores[i]);
            for(int j=0 ;j<personas; j++){
                for(int k=0; k<cantidad_recividores[i]; k++){
                    if(grupo[j]==grupo_de_recividores[i][k]){
                        moneys[j] += temp;
                    }
                }
            }
            moneys[i] -= temp*cantidad_recividores[i];
        }

        if (count++ > 0) cout << endl;
        for(int i=0; i<personas; i++){
            cout<<grupo[i]<<" "<< moneys[i]<<'\n';
        }
    }
    return 0;
}