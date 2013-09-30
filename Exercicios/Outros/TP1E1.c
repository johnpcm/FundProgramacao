#include <stdio.h>
#include <math.h>

main(){


    do{
        int ina,inb,sma=0,smb=0,bina,binb;
        scanf("%d%d",&ina,&inb);

        if(ina<0 || inb<0)
            break;

        bina = ina;
        binb = inb;

        ina *= ina;
        while (ina != 0){
            sma+=ina%10;
            ina /= 10;
        }

        inb *= inb;
        while(inb != 0){
            smb+=inb%10;
            inb /= 10;
        }

        if(sma == binb && smb == bina)
            printf("S‹o amigos\n");
        else
            printf("n‹o s‹o\n");


    }while(1);
}


