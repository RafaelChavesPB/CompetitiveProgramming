#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr,int start, int mid, int end){

    vector<int> first(arr.begin()+start,arr.begin()+mid+1);
    vector<int> second(arr.begin()+mid+1,arr.begin()+end+1);
    
    int inv=0; //conta as inversões
    int i=0; //contador para o vetor first
    int j=0; //contador para o vetor second
    int k=start; //contador para arr

    while(i<first.size() and j<second.size()){
        if(first[i]>second[j]){
            arr[k++]=second[j++];
            inv+=(first.size()-i);
        }else{ 
            arr[k++]=first[i++];
        }
    }
    while(i<first.size())
    {
        arr[k++]=first[i++];
    }

    while(j<second.size())
        arr[k++]=second[j++];

    return inv;

}

int mergersort(vector<int> &arr,int start, int end) {
    int mid=(start+end)/2;
    int inv=0;
    if(start==end)
        return 0;
    inv+=mergersort(arr,start,mid);
    inv+=mergersort(arr,mid+1,end);
    inv+=merge(arr,start,mid,end);
    return inv;
}

int main(){
    vector<int> array;
    int n, temp;
    while(scanf("%d",&n) && n){
        array.clear();
        while(n--){
            scanf("%d",&temp);
            array.push_back(temp);
        }
        // printf("%d",mergersort(array,0,array.size()-1));
        if(mergersort(array,0,array.size()-1)%2){
            printf("Marcelo\n");
        }else{
            printf("Carlos\n");
        }


    }

    return 0;
}