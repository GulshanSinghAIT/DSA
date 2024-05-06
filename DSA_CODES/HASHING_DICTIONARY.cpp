
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

struct node{
    string word;
    string meaning; 
    node*next;
    node(){
        word="";
        meaning="";
        next=NULL;
    }
    node(string s,string m){
        word=s;
        meaning=m;
        next=NULL;
    }
};
class hashing:public node{
    public:
    node*table[10];
    hashing(){
       for(int i=0;i<10;i++){
        table[i]=NULL;
       }
    }
    int func(string s){
        int l=s.length();
        int val=0;
        for(int i=0;i<l;i++){
            val+=(s[i]-'a'+1);
        }
        return val%10;
    }
    void insert(string s,string m){
        int index=func(s);
        if(table[index]==NULL){
            table[index]=new node(s,m);
        }
        else{
            node*temp=table[index];
            table[index]=new node(s,m);
            table[index]->next=temp;
        }
        
    }
    void searchword(string s){
         int index=func(s);
         node*temp=table[index];
         while(temp->word!=s && temp!=NULL){
            temp=temp->next;
         }
         if(temp!=NULL){
            cout<<"word found:"<<s<<temp->meaning<<endl;
         }
         else{
            cout<<"not found";
         }
    }
    void displaytable(){
        cout<<"Dictionary Content :";
        for(int i=0;i<10;i++){
            cout<<"Index :"<<i<<endl;
            node*temp=table[i];
            while(temp!=NULL){
            cout<<temp->word<<" "<<temp->meaning;
            temp=temp->next;
            }
        }

    }
};

int main(){
   hashing h;
   h.insert("Harshita","hhuh");
   h.insert("Khushia","jhgy");
   h.insert("Display","ghft");
   h.insert("Payal","bjyht");
   h.displaytable();
   h.searchword("Harshita");
   return 0;
}