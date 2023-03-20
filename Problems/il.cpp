#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	char line[121];
	while(gets(line)){
		for(unsigned int i=0;i<strlen(line);i++){
			if(line[i]=='I'){printf("i");}
            else if(line[i]=='l'){printf("L");}
            else{printf("%c", line[i]);}
		}
		printf("\n");
	}
	return 0;
}