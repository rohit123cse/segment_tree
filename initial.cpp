 #include<bits/stdc++.h>
using namespace std;

class maxrangeds{
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
    tree[index]=max(tree[2*index+1],tree[index*2+2]);
    return;
  }
  public:
  maxrangeds(vector<int>&vec){
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
      if(reqlow<=low&&reqhigh>=high)return tree[index];
      else return INT_MAX;
    }
    if(reqlow<=low&&reqhigh>=high)return tree[index];
    if(high<reqlow||low>reqhigh)return INT_MAX;
    int mid=(low+high)/2;
    return max(query(2*index+1,low,mid,reqlow,reqhigh),query(2*index+2,mid+1,high,reqlow,reqhigh));
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
    tree[index]=max(tree[index*2+1],tree[index*2+2]);
    return;
  }
};
class minrangeds{
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
    tree[index]=min(tree[2*index+1],tree[index*2+2]);
    return;
  }
  public:
  minrangeds(vector<int>&vec){
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
      else return INT_MAX;
    }
    if(reqlow<=low&&reqhigh>=high)return tree[index];
    if(high<reqlow||low>reqhigh)return INT_MAX;
    int mid=(low+high)/2;
    return min(query(2*index+1,low,mid,reqlow,reqhigh),query(2*index+2,mid+1,high,reqlow,reqhigh));
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
    tree[index]=min(tree[index*2+1],tree[index*2+2]);
    return;
  }
};
int main(){

  // int n=10;
  // cout<<"enter";
  // vector<int>store={8,2,5,1,4,5,3,9,6,10},tree(4*n+1,-1);  //max index is 4*n +1
  // maxbuildtree(store,0,0,n-1,tree);
  // int l=3,r=8;
  // cout<<maxquery(0,0,n-1,tree,l,r)<<endl;
  // maxpointupdate(6,0,0,n-1,tree,100);
  // cout<<maxquery(0,0,n-1,tree,l,r);
  vector<int>store={8,2,5,1,4,5,3,9,6,10};
  minrangeds tree(store);
  cout<<tree.query(0,0,9,3,8);
  tree.pointupdate(3,0,0,9,100);
  cout<<tree.query(0,0,9,3,8);
  



return 0;
}
