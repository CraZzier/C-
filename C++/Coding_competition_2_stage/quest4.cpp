#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

vector<vector<string> > data_input;
map<string,bool> visited;
map<string,vector<string> >neighbourhood;
map<string,vector<string> >::iterator it_map;

bool DFS(string v, string szukane){
    visited[v] = true;
    bool wynik = false;
    for(int i=0;i<neighbourhood[v].size();i++){
        if(!visited[neighbourhood[v][i]]){
            if(neighbourhood[v][i] == szukane){
                 return true;
            }else{
                wynik = DFS(neighbourhood[v][i],szukane);
            }
        }
    }
    return wynik;
}

int main(int argc, char* argv[]){
    int line;
    int it = 0;
    int it_b = 0;
    bool wynik;
    string temp;
    while(cin>>temp){
        if(temp == "end" || cin.eof()){
            break;
        }
        line = it/3;
        data_input.resize(line+1);
        data_input[line].push_back(temp);
        it++;
    }
    for(int i = 0; i<data_input.size();i++){
        if(data_input[i][0]=="B"){
            neighbourhood[data_input[i][1]].push_back(data_input[i][2]);
            neighbourhood[data_input[i][2]].push_back(data_input[i][1]);
        }else{
            if(i==0){
                cout<<"N"<<endl;
                continue;
            }
            for(it_map = neighbourhood.begin();it_map!=neighbourhood.end();++it_map){
                visited[it_map->first] = false;
            }
            wynik = DFS(data_input[i][1],data_input[i][2]);
            if(it_b==0){
                    it_b++;
                if(wynik == true){
                    cout<<"T";
                }else{
                    cout<<"N";
                }
            }else{
                 if(wynik == true){
                    cout<<endl<<"T";
                }else{
                    cout<<endl<<"N";
                }
            }
        }
    }
    return 0;
}
