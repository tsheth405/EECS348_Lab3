#include <stdio.h>

void print_output(int td, int fg, int sf, int tdpt, int tdfg){
    printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", tdpt, tdfg, td, fg, sf);
}

int main(){
    int td = 0;
    int fg = 0;
    int sf = 0;
    int tdpt = 0;
    int tdfg = 0;

    int td_total = 6;
    int fg_total = 3;
    int sf_total = 2;
    int tdpt_total = 8;
    int tdfg_total = 7;

    int n = 0;

    while(1){
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter a number of points scored: ");
        scanf("%d", &n);
        for (int a = 0; a <= n/td_total; a++){
            for (int b = 0; b <= n/fg_total; b++){
                for (int c = 0; c <= n/sf_total; c++){
                    for (int d = 0; d <= n/tdpt_total; d++){
                        for (int e = 0; e <= n/tdfg_total; e++){
                            if((td_total*a + fg_total*b + sf_total*c + tdpt_total*d + tdfg_total*e) == n){
                                td = a;
                                fg = b;
                                sf = c;
                                tdpt = d;
                                tdfg = e;
                                print_output(td, fg, sf, tdpt, tdfg);
                            }
                        }
                    }
                }
            }
        }
        if (n == 0 || n == 1){
            break;
        }
    }
    return 0;
}