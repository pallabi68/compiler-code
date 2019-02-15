#include<bits/stdc++.h>
using namespace std;
//NOTE : ' are replaced by 1;
// EX: E' : E1 
// replace all id by i;
// epsilon is denoted by @
// t  denotes top of stack and s denotes current pointer in the inputs string 
int main(){
// input parsing table
map <pair<string ,string>,string> mp;
mp.insert(pair<pair<string ,string>,string>(make_pair("E","i"),"TE1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("E","("),"TE1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("E1","+"),"+TE1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("E1",")"),"@"));
mp.insert(pair<pair<string ,string>,string>(make_pair("E1","$"),"@"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T","i"),"FT1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T","("),"FT1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T1","+"),"@"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T1","*"),"*FT1"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T1",")"),"@"));
mp.insert(pair<pair<string ,string>,string>(make_pair("T1","$"),"@"));
mp.insert(pair<pair<string ,string>,string>(make_pair("F","i"),"i"));
mp.insert(pair<pair<string ,string>,string>(make_pair("F","("),"(E)"));

map <string,int> is_terminal;
is_terminal.insert(pair<string,int>("i",1));
is_terminal.insert(pair<string,int>("+",1));
is_terminal.insert(pair<string,int>("*",1));
is_terminal.insert(pair<string,int>("(",1));
is_terminal.insert(pair<string,int>(")",1));
is_terminal.insert(pair<string,int>("$",1));
cout<<"--------------------------------";
stack<string> stc;
stc.push("$");
stc.push("E");
string in="i+i*i$";
int i=0;
int n=in.length();
cout<<"length of the string is"<<n<<endl;
string t;

int flag=1;
string s;
while(1){
  
  t=stc.top();
  cout<<"stack top is "<<t<<endl;
   if(t=="$" && i>=(n-1)){
     cout<<"THE STRING SUCCESFULLY PARSED"<<endl;
     }
  if(t=="$" || i>=n){
    break;
    }
    cout<<"i value  "<<i<<endl;
    
  if(flag){
     // cout<<"inside flag"<<endl;
     char  x=in[i];
      
         s="";
         s+=x;
         cout<<"current s is "<<s<<endl;
     flag=0;
     }
    
     
 //if current character is a terminal
 if(is_terminal[t]==1){
 cout<<"terminal encountered   "<<endl;
   if(s==t){
    stc.pop();
    i=i+1;
    flag=1;
    }
    else {
     cout<<"Invalid String"<<endl;
     break;
     }
     }
   else {
  
    if(mp[make_pair(t,s)]==""){
      //error entry 
   
       cout<<"no M[t,s] entry occur   Invalid String"<<endl;
       break;
       }
     else{
      //M[x,a]->y1y2...yk
      //push yk,yk-1,.....,1
       stc.pop();
       string temp=mp[make_pair(t,s)];
       int dash=0;
       for(int j=temp.length()-1;j>=0;j--){
        if(temp[j]=='1'){
         dash=1;
        
         }
        else {
         char c=temp[j];
         string h(1,c);
         if(dash){
          h+="1";
          dash=0;
          
          }
          
          if(h!="@"){
          stc.push(h);
          cout<<"I pushed  "<<h<<endl;
          }
        } 
        
       }    
     }
 
 }

 }
 
 

return 0;
}
