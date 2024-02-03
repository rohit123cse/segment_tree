#include<bits/stdc++.h>
using namespace std;
class sumrangeds{
  vector<int>tree;
  int size;
  void buildtree(int index,int low,int high,vector<int>&vec){
    if(low==high){
      tree[index]=vec[low];
      return;
    }
    int mid=(low+high)/2;
    buildtree(2*index+1,low,mid,vec);
    buildtree(2*index+2,mid+1,high,vec);
    tree[index]=(tree[2*index+1]+tree[index*2+2]);
    return;
  }
  public:
  sumrangeds(vector<int>&vec){
    int n=vec.size();
    tree.resize(4*n+1);
    buildtree(0,0,n-1,vec);
    size=n;
  }
  void newtree(vector<int>&vec){
    tree.clear();
    size=vec.size();
    buildtree(0,0,vec.size()-1,vec);
  }
  int query(int index,int low,int high,int const &reqlow,int const &reqhigh){
    if(low==high){
      if(reqlow<=low&&reqhigh>=low)return tree[index];
      else return 0;
    }
    if(reqlow<=low&&reqhigh>=high)return tree[index];
    if(high<reqlow||low>reqhigh)return 0;
    int mid=(low+high)/2;
    return (query(2*index+1,low,mid,reqlow,reqhigh)+query(2*index+2,mid+1,high,reqlow,reqhigh));
  }
  void pointupdate(int const &updateindex,int index,int low,int high,int const &val){
    if(low==high){
      if(updateindex==low)tree[index]=val;
      return;
    }
    if(updateindex>high||updateindex<low)return;
    int mid=(low+high)/2;
    pointupdate(updateindex,2*index+1,low,mid,val);
    pointupdate(updateindex,2*index+2,mid+1,high,val);
    tree[index]=(tree[index*2+1]+tree[index*2+2]);
    return;
  }
};
int main(){
  






return 0;
}