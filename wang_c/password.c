//-------------------------
#include"my.h"
#include<string.h>
int main(void){
	int result=0;
	char text1[128]={'\0'};
	char text2[128]={'\0'};
	char cryptograph[128]={'\0'};
	printf("请输入加密模式：1加密，2解密，3退出。\n");
	scanf("%d",&result);
	scanf("%*[^\n]");
	scanf("%*c");
	while(1){
		if(result==1){
			do{
			printf("请输入加密密码：");
			fgets(text1,128,stdin);
			printf("请再次输入密码：");
			fgets(text2,128,stdin);
			if(strcmp(text1,text2)==0){
				int i;
				for(i=0;i<strlen(text2);i++){
					text2[i]=text2[i]+i+5;
				}
				text2[i]='\0';
				FILE* f=fopen("htpasswd","wb+");
				if(f){
				    if(fwrite(text2,strlen(text2),1,f)){
				       printf("密码设置成功\n");
				       fclose(f);
					   break;
					}else{ printf("设置出错，请重新输入：\n");continue;}
				}else{ printf("设置出错，请重新输入：\n");continue;}
			}else {
				printf("input error,Password inconsistency \n");
			}
			}while(1);
		}
		else if(result == 2){
			do{
				printf("input password: ");
				fgets(cryptograph,128,stdin);
				FILE* f=fopen("htpasswd","rb");
				char passwd[128]={'\0'};
				if(f){
					fread(passwd,sizeof(passwd),1,f);
						int i;
						for(i=0;i<strlen(passwd);i++){
							passwd[i]=passwd[i]-i-5;
						}
						passwd[i]='\0';
						if(strcmp(passwd,cryptograph)==0){
							printf("Password Correct\n");
							fclose(f);
							break;
						}else{ printf("password error 01\n");continue;}
				}else{ printf("password error 02\n");continue;}
			}while(1);
		}
		else if(result !=1 && result !=2 && result !=3){
			printf("input error\n");
	        break;
		}
		break;
	}
}
