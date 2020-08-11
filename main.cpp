#include <bits/stdc++.h>

using namespace std;
vector <int> posizioni;
long long N,B;
long long result=0;

void prova(int corrente)
{
    vector <int> distanze;
    int posizione_corrente= posizioni[corrente];
    for(int i=0; i<N; i++)
    {
        if(posizioni[corrente] - B <= posizioni[i] && posizioni[corrente] + B >= posizioni[i])
        {
            distanze.push_back(abs(posizioni[i]-posizione_corrente));
        }
    }
    sort(distanze.begin(),distanze.end());
      indice=0;
    while(B-distanze[indice] < 0 || indice==distanze.size())
    {
        B-=distanze[indice];
        indice++;
    }
    if(result < indice)
        result= indice;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N >> B;
    posizioni.resize(N);
    for(int i=0; i<N; i++)
    {
        cin >> posizioni[i];
    }

    for(int i=0; i<N; i++)
    {
        prova(i);
    }

    cout << result << endl;
    return 0;
}
