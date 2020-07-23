/*** keep hungry and calm CoolGuang!***/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pp;
const ll INF=1e17;
const int Maxn=2e7+10;
const int maxn =2e5+10;
const int mod=998244353;
const int Mod = 1e9+7;
const double eps=1e-3;
inline bool read(ll &num)
{char in;bool IsN=false;
    in=getchar();if(in==EOF) return false;while(in!='-'&&(in<'0'||in>'9')) in=getchar();if(in=='-'){ IsN=true;num=0;}else num=in-'0';while(in=getchar(),in>='0'&&in<='9'){num*=10,num+=in-'0';}if(IsN) num=-num;return true;}
ll n,m,p;
char s[maxn],t[maxn];
ll sum[maxn][30];
int vis[30],tvis[30];
bool mp1[Maxn],mp2[Maxn];
ull H[maxn],H1[maxn];
char F[300];
inline void out(ll x){ if (x == 0) return (void) (putchar('0'), putchar('\n'));    ll tmp = x > 0 ? x : -x;    if (x < 0) putchar('-');    int cnt = 0;    while (tmp > 0) {        F[cnt++] = tmp % 10 + '0';        tmp /= 10;     }   while (cnt > 0) putchar(F[--cnt]);   printf("\n"); }
ll qpow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        b/=2;a = (a*a)%mod;
    }return ans;
}
int main(){
    scanf("%s%s",s+1,t+1);
    int lens = strlen(s+1),lent = strlen(t+1);
    for(register int i=1;i<=lens;i++) vis[s[i]-'a']++;
    ll temp_27 = qpow(27,lens);
    ll ans = 0;
    for(register int i=1;i<=lent;i++) H[i] = (H[i-1]*27 + (t[i]-'a'+1))%mod;
	for (register int i = 1; i <= lent; i++)
		cerr << "i = " << H[i] << endl;
    for(int i=1;i<=lens;i++) tvis[t[i]-'a']++;
    int cot = 0;
    for(int i=0;i<26;i++) if(tvis[i] != vis[i]) cot++;
    for(register int i=lens;i<=lent;i++){
        if(!cot){
            ll tempx = (H[i] - (H[i-lens]*temp_27)%mod+mod)%mod;
			cerr << "i = " << i << ' ' << "lens = " << lens << endl;
			cerr << tempx << endl;
            tempx %= 10000007;
            if(!mp1[tempx]){
                mp1[tempx] = true;
                ans++;
            }
        }
        tvis[t[i-lens+1]-'a']--;
        if(tvis[t[i-lens+1]-'a'] == vis[t[i-lens+1]-'a']&&tvis[t[i-lens+1]-'a']+1 != vis[t[i-lens+1]-'a']) cot--;
        if(tvis[t[i-lens+1]-'a'] != vis[t[i-lens+1]-'a']&&tvis[t[i-lens+1]-'a']+1 == vis[t[i-lens+1]-'a']) cot++;
        tvis[t[i+1]-'a']++;
        if(tvis[t[i+1]-'a'] == vis[t[i+1]-'a']&&tvis[t[i+1]-'a']-1 != vis[t[i+1]-'a']) cot--;
        if(tvis[t[i+1]-'a'] != vis[t[i+1]-'a']&&tvis[t[i+1]-'a']-1 == vis[t[i+1]-'a']) cot++;
    }
    out(ans);
    return 0;
}
/**
aab
abacabaa
**/
