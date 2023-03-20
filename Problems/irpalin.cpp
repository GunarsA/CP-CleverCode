#include<stdio.h>
using namespace std;

int main(){
    int len;
    bool palindrome=true;
    scanf("%d ",&len);
    char text[len+1];
    for(int i=0;i<len;i++){
        scanf("%c",&text[i]);
    }
    for(int i=0,j=len-1;i<j;i++,j--){
        while((text[i]<65||text[i]>90)&&
        (text[i]<97||text[i]>122)){i++;}
        while((text[j]<65||text[j]>90)&&
        (text[j]<97||text[j]>122)){j--;}
        if(text[i]!=text[j]&&
        ((text[i]!=text[j]+32)&&(text[i]!=text[j]-32))){
            palindrome=false;
            break;
        }
    }
    palindrome?
    printf("IR"):
    printf("NAV");
}