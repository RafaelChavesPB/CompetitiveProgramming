#include <bits/stdc++.h>

using namespace std;

int main(){
    set<char> letters;
    char letra;
    scanf("%*c");
    while(scanf("%c%*c%*c",&letra)!=EOF){
        if(letra!='}')
            letters.insert(letra);
    }
    cout<<letters.size()<<endl;

    return 0;
}