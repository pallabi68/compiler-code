//IMPLEMENTATION OF LEXICAL ANALYSER USING NFA
//for keyword it is implemented only for "if" and "else"
//you need to write in your input file program.txt


#include<bits/stdc++.h>
using namespace std; 
using namespace std;
 
 
int main(){
	int final_state[9]={2,6,7,8,9,10,11,12,13};
	map<int,string> mp;
	mp.insert(make_pair(2,"KEYWORD"));
	mp.insert(make_pair(6,"KEYWORD"));
	mp.insert(make_pair(7,"CONSTANT"));
	mp.insert(make_pair(8,"IDENTIFIER"));
	mp.insert(make_pair(9,"ASSIGN_OPERATOR"));
	mp.insert(make_pair(10,"GREATER_OPERATOR"));
	mp.insert(make_pair(11,"GREATER_EQUAL_OPERATOR"));
	mp.insert(make_pair(12,"LESSTHAN_OPERATOR"));
	mp.insert(make_pair(13,"LESS_EQUAL_OPERATOR"));
	
	
	ifstream fin;
	fin.open("program.txt", ios::in);
	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
	int state=0;
	//cout<<mp[10]<<endl;
	char ch= fin.get();
	char next = fin.get();
	
	
	while(!fin.eof()){
	int p=int(ch);
	        if(ch!=' ' && ch!='\n'){
	        cout<<"character  ->	"<<ch<<"     ";
	        //cout<<"P    "<<p<<endl;
	        }
   		
   		//cout<<"P    "<<p<<endl;
   		switch(state){
		case 0:
		  if(ch==' ' || ch=='\n'){
		   break;
		   }
   		 else if(ch=='i' && !(next==' ' || next=='\n')){
   		   state=1;}
   		  
   		  else if(ch=='e' && !(next==' ' || next=='\n')){
   		    state=3;
   		    }
   		   else if(p>=48 && p<=57){
   		     if(next){
   		     state=7;
   		     }
   		     else {
   		     
   		     cout<<"TYPE    "<<mp[7]<<endl;
   		     state=0;
   		     }
   		     }
   		   else if( (p>=97 && p<=122) || (p>=65 && p<=90)){
   		      if(next==' ' || next=='\n'){
   		       state=0;
   		       //cout<<"hello"<<endl;
   		       cout<<"TYPE    "<<mp[8]<<endl;
   		       }
   		       else {
   		       if(next>=0 && next<=9){
   		        state=7;
   		        }
   		        else {
   		        
   		        state=8;
   		        
   		        }
   		       }
   		      }
   		     else if(ch=='='){
   		      state=9;
   		      }
   		      else if(ch=='>'){
   		          if(next){
   		            state=10;
   		            }
   		            else {
   		             state=0;
   		             cout<<"TYPE    "<<mp[10]<<endl;
   		             }
   		         }
   		    else if(ch=='<') {
   		      if(next){
   		            state=12;
   		            }
   		            else {
   		             state=0;
   		             cout<<"TYPE    "<<mp[10]<<endl;
   		             }
   		             }  
   		     else if(ch=='+'){
   		        cout<<"TYPE    "<<"ADD_OPERATOR"<<endl;
   		        state=0;
   		        }
   		      else if(ch=='-'){
   		        cout<<"TYPE    "<<"SUBSTRACT_OPERATOR"<<endl;
   		        state=0;
   		        } 
   		      else if(ch=='*'){
   		        cout<<"TYPE    "<<"MUL_OPERATOR"<<endl;
   		        state=0;
   		        } 
   		      else if(ch=='/'){
   		        cout<<"TYPE    "<<"DIV_OPERATOR"<<endl;
   		        state=0;
   		        }    
   		                 
   		          break;   
   		      
   		    
		case 1:
   		      if(ch=='f'){
   		       state=2;
   		       
   		       }   
   		     break;
   		     
		case 2:
   		     if(ch==' ' || ch=='\n'){
   		       state=0;
   		       cout<<"TYPE    "<<mp[2]<<endl;
   		     }
   		     break;
   		     
		case 3:
   		        if(ch=='l'){
   		        state=4;
   		        }
   		        break;
   		        
		case 4:
   		    if(ch=='s'){
   		     state=5;
   		     }
   		     break;
   		     
		case 5:
   		        if(ch=='e'){
   		         state=6;
   		         }
   		         break;
   		         
		case 6:
   		     if(ch==' ' || ch=='\n'){
   		       cout<<"TYPE    "<<mp[6]<<endl;
   		       }
   		       break;
   		       
		case 7:
   		           if(p>=48 && p<=57){
   		        state=7;
   		        }
   		        else {
   		         // cout<<"  "<<endl;
   		        cout<<"TYPE    "<<mp[7]<<endl;
   		        state=0;
   		        } 
   		        break;
		case 8:
		        if(!next){
   		       state=0;
   		       cout<<"TYPE    "<<mp[8]<<endl;
   		       }
   		       else {
   		       if(next>=0 && next<=9){
   		        state=7;
   		        }
   		        else {
   		        
   		        state=8;
   		        
   		        } 		        
   		      
   		      }  
   		      break;
   		case 9:
   		     if(ch==' '){	
   		      state=0;
   		      cout<<"TYPE    "<<mp[9]<<endl;
   		      }
   		      break;      
   		case 10:
   		 	if(ch=='='){
   		 	state=11;
   		 	}
   		 	break;
   		case 11:
   		      if(ch==' '){
   		      cout<<"TYPE    "<<mp[11]<<endl;
   		      state=0; 				      
   		    }  
   		    break;
   		case 12:
   			if(ch=='=' && next==' '){
   			cout<<"TYPE    "<<mp[13]<<" ";
   			state=0;
   			}
   			break;
   		}	
   			         
   		   ch=next;
   		   next=fin.get();  		 
   		
}
	
	
	
	fin.close();
	
	return 0;
}
