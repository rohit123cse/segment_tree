#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int open,close,full;
  node(int o,int c):open(o),close(c),full(0){};
  node(int o,int c,int f):open(o),close(c),full(f){};
};
class segment_tree{
  vector<node>tree;
  string st;
  void build_helper(int low,int high,string const &s,int index){
    if(low==high){
      if(s[low]=='('){
        node temp(1,0);
        tree[index]=temp;
        return;
      }
      node temp(0,1);
      tree[index]=temp;
      return;
    }
    int mid=(low+high)/2;
    build_helper(low,mid,s,2*index+1);
    build_helper(mid+1,high,s,2*index+2);
    int l=2*index+1,r=2*index+2;
    int ncl=min(tree[l].open,tree[r].close),no=tree[l].open,nc=tree[r].close;
    no-=ncl;nc-=ncl;
    ncl+=tree[l].full;ncl+=tree[r].full;
    no+=tree[r].open;nc+=tree[l].close;
    node temp(no,nc,ncl);
    tree[index]=temp;
    return;
  }
  public:
  void buildtree(string const &s){
    int n=s.size();
    st=s;
    tree.resize(4*n+1);
    build_helper(0,n-1,s,0);
  }
  int currval(){
    return tree[0].full;
  }
  void update_helper(int low,int high,int updateindex,int index,char c){
    if(low==high){
      if(updateindex==low){
        if(c=='('){
          tree[index].close--;
          tree[index].open++;
        }
        else{
          tree[index].close++;
          tree[index].open--;       
      }
    }
    return;
    }
    int mid=(low+high)/2;
    if(low<=mid)update_helper(low,mid,updateindex,index*2+1,c);
    else update_helper(mid+1,high,updateindex,index*2+2,c);
    int l=2*index+1,r=2*index+2;
    int ncl=min(tree[l].open,tree[r].close),no=tree[l].open,nc=tree[r].close;
    no-=ncl;nc-=ncl;
    ncl+=tree[l].full;ncl+=tree[r].full;
    no+=tree[r].open;nc+=tree[l].close;
    node temp(no,nc,ncl);
    tree[index]=temp;
    return;
  }
  int update(int updateindex,char c){
    if(st[updateindex]==c)return currval();
    st[updateindex]=c;
    update_helper(0,st.size()-1,updateindex,0,c);
    return currval();
  }
};
int main(){
  






return 0;
}