#include <stdio.h>

int main(){
    int lab[100][200][2];
    int x,y,z=2,inix,iniy,posx,posy;
    int i,j,k,c;

    scanf("%d %d", &x,&y);

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            for(k=0;k<z;k++){
                scanf("%d", &lab[i][j][k]);
            }
        }
    }

    scanf("%d %d", &inix,&iniy);

    c = 0;

    do{
        posx = lab[inix][iniy][1];
        posy = lab[inix][iniy][2];

        inix = posx;
        iniy = posy;

        if(c>10000) break;
        c++;
    } while(posx != 0 && posy != 0);

    if(inix == 0 && iniy == 0)printf("vence");
    else printf("preso");

    return 0;
}
