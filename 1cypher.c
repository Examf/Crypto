#include <stdio.h>
#include <stdlib.h>
void encryption(char message[], int key)
{
     int i;
     char ch;
     for(i = 0; message[i] != '\0'; ++i){
         ch = message[i];
         if(ch >= 'a' && ch <= 'z'){
             ch = ch + key;
             if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
         }
         else if(ch >= 'A' && ch <= 'Z'){
             ch = ch + key;
             if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
             }
             message[i] = ch;
         }
         else if(ch >= '0' && ch <= '9')
         {
             message[i] = (message[i] - '0' + key) % 10 + '0';
         }
     }
     printf("The Encrypted Message is -> %s",message);
     printf("\n");
}

void decryption(char message[], int key)
{
     int i;
     char ch;
     for(i = 0; message[i] != '\0'; ++i)
         {
             ch = message[i];
             if(ch >= 'a' && ch <= 'z'){
                 ch = ch - key;
                 if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                 }
                 message[i] = ch;
             }
             else if(ch >= 'A' && ch <= 'Z'){
                 ch = ch - key;
                 if(ch < 'A'){
                    ch = ch + 'Z' - 'A' + 1;
                 }
                 message[i] = ch;
             }
             else if(ch >= '0' && ch <= '9')
             {
                 message[i] = (message[i] - '0' - key + 10) % 10 + '0';
             }
         }
     printf("The Decrypted Message is -> %s",message);
     printf("\n");
}

int main()
{
    char msg[100];
    int key;
    printf("Enter the Message : ");
    scanf("%s",&msg);
    printf("Enter the key : ");
    scanf("%d",&key);
    printf("\n");
    encryption(msg, key);
    decryption(msg, key);
    return 0;
}
