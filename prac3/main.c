#include <stdio.h>
#include <string.h>

// 17. Перетворення числа в строку (цілочисленне беззнакове)

void reverse(char *str){
  for(int i = 0, j = strlen(str) - 1; i < j; i++, j--){
    char tmp;

    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

int myItoa(unsigned num, char *str, unsigned bufSize){
  int i = 0;

  if(num == 0){
    if(bufSize < 2) return 0;

    str[0] = '0';
    str[1] = 0;

    return 1;
  }

  while(num){
    if(i >= bufSize - 1){
      return 0;
    }

    str[i++] = '0' + num % 10;
    num /= 10;
  }

  str[i] = 0;

  reverse(str);
  return 1;
}

int main(){
  unsigned i;
  char arr[10];

  while(1){
    if(scanf("%u", &i) != 1){
      int ch;
      while((ch = getchar()) != '\n' && ch != EOF);
      continue;
    }

    if(myItoa(i, arr, 10)){
      printf("%s\n", arr);
    }
    else{
      printf("not enought space in array\n");
    }

  }
}
