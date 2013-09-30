#include <stdio.h>
#include <math.h>

main(){



        int ina,inb,bina,binb;
        for(ina=1;ina<10000;ina++){
            for(inb=1;inb<10000;inb++){
                    int sma=0,smb=0;
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
                ina = bina;
                inb = binb;

                if(sma == binb && smb == bina)
                    printf("%d e %d S‹o amigos\n",binb,bina);

            }
        }
        printf("fim!");

}


