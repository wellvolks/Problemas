#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
  
typedef long long int64;
 #ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

const int MOD = (1e9)+7;
int x[] = {-1,0,1,0};
int y[] = {0,-1,0,1};
int n, m, h;
int xi, yi, xf, yf, q;
int queue[1002*1002];
char mat[1002][1002];
int inQueue[1002][1002], us = 1;
int used[1002][1002], fs = 1;
int ans[1002][1002];
char pot[] = {1,2,4,8};
char pot_n[] = {((1<<5)-1)^1,((1<<5)-1)^2,((1<<5)-1)^4,((1<<5)-1)^8};
  
int main(){
    while(scanf("%d %d %d",&n,&m,&h) != EOF){  
        register int i, a, j, p = 0;
        for(i = 0; i <= n; i++) for(j = 0; j <= m; j++ ) ans[i][j] = mat[i][j] = 0;
  
        for(a = 0; a < h; a++ ){
            scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
            for(j = yi+1; j <= yf-1; j++){
                mat[xi][j] |= pot[2];
                mat[xf][j] |= pot[0]; 
            }
            for(j = xi+1; j <= xf-1; j++){
                mat[j][yi] |= pot[3];
                mat[j][yf] |= pot[1];  
            }
            mat[xi][yi] &= (pot_n[3]);
            mat[xi][yi] &= (pot_n[2]);
            mat[xf][yf] &= (pot_n[1]);
            mat[xf][yf] &= (pot_n[0]);
            mat[xi][yf] &= (pot_n[0]);
            mat[xi][yf] &= (pot_n[3]);
            mat[xf][yi] &= (pot_n[2]);
            mat[xf][yi] &= (pot_n[1]);
        }
  
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
  
            us++; fs++;
            p = 0;
            fila[p++] = ((xi<<10)|yi);
            inQueue[xi][yi] = fs;
            ans[xi][yi] = 1;
            used[xi][yi] = us;
            while( p ){
                register int u = fila[p-1];
                register int ax = (u>>10);
                register int ay = (u&1023);
                fila.pop();
                inQueue[ax][ay] = 0;
                if( ax == xf && ay == yf ) break;
                for(i = 0; i < 4; i++){
                    if( (mat[ax][ay] & pot[i]) ) continue;
                    register int xx = ax + x[i];
                    register int yy = ay + y[i];
                    if( (xx < 0) || (xx > n) || (yy < 0) || (yy > m) ) continue;
                    if( inQueue[xx][yy] == fs ){
                        ans[xx][yy] = (ans[xx][yy] + ans[ax][ay]);
                        while (ans[xx][yy] >= MOD) ans[xx][yy] -= MOD;
                    }
                    else if( used[xx][yy] != us ){
                        ans[xx][yy] = ans[ax][ay];
                        inQueue[xx][yy] = fs;
                        used[xx][yy] = us;
                        fila[p++] = ((xx<<10)|yy);
                    }
                }
            }
            writeInt(ans[xf][yf]);
            putchar_unlocked('\n');
        }
        putchar_unlocked('\n');
    }
    return 0;
}