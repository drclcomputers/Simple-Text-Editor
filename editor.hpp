#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    char action; string text, data, filename, data2[10000]; 
    int aux=0;
    
    while(action!='e'){
        data="", filename.clear(), text.clear(); 
        
        cout<<"Simple Text Editor: C++ Edition"<<endl<<"Write (w), Open (o), Exit (e): "; cin>>action;

        if(action=='w'){
            while(text!="exit"){
                getline(cin, text);
                if(text!="exit") data+=text+"\n"; }
            cout<<"Input Filename: "; getline(cin, filename);
            if(filename!=""){ 
                ofstream fout; 
                fout.open(filename); 
                fout<<data; 
                fout.close(); 
            }
        }

        if(action=='o'){
            cout<<"Input filename: ";
            cin.ignore();
            getline(cin, filename);
            fstream fin;
            fin.open(filename);
            int line=1;
            if(fin.is_open()){
                while(getline(fin, data)){
                    data2[aux]=data;
                    aux++;}
                
                while(line!=0){
                    for(int i=0; i<aux; i++)
                        cout<<i+1<<" "<<data2[i]<<endl;
                    cout<<"Input line to edit (0 - exit): "; cin>>line;
                    if(line!=0){
                        while(line>aux){
                            data2[aux]="";
                            aux++;}
                        cin.ignore();
                        cout<<"Input text: "; getline(cin, text);
                        data2[line-1]=text;
                        fin.clear(); fin.seekg(0);
                        for(int i=0; i<aux; i++)
                            fin<<data2[i]<<endl;}
                    
                    system("cls");
                }
                
                for(int i=0; i<aux; i++)
                    data2[i]="";
                aux=0;
                fin.close();
            }
            else
            {
                cout<<"File appears to not exist"<<endl<<"Try again (a) or Exit (e): ";
                string a; cin>>a;
                if(a!="a")
                    action='e';}
        }
        system("cls");
    }
    
    return 0;
    
}
