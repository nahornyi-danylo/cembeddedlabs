// 17.
// z_1 = sqrt((3m + 2)^2 - 24)/(3sqrt(m) - 2/sqrt(m)) = sqrt((3m + 2)^2 - 24)/((3m - 2)/sqrt(m))
// z_2 = -sqrt(m)
// z_1 is defined for all m > 0
// z_2 is defined for all m >= 0

#include <stdio.h>
#include <math.h>

struct {
  double sqm;
  double mmm;
} data;

int processInput(){
  double m;
  int res;

  res = scanf("%lf", &m);

  if(res != 1){
    char ch;

    while((ch = getchar()) != '\n' && ch != EOF); // discarding non-numeric input
    return 0;
  }

  if(m < 0) return 0;

  data.sqm = sqrt(m);
  data.mmm = 3 * m;

  return 1;
}

double z1(){
  return sqrt((data.mmm + 2) * (data.mmm + 2) - 24)/((data.mmm - 2)/data.sqm);
}

double z2(){
  return -data.sqm;
}

int main(){
  printf("z_1 = sqrt((3m + 2)^2 - 24)/(3sqrt(m) - 2/sqrt(m))\n");
  printf("z_2 = -sqrt(m)\n");

  while(1){
    printf("Enter a non-negative value of m\n");

    if(processInput()){
      if(data.sqm > 0) printf("z_1 = %lf\n", z1());
      printf("z_2 = %lf\n", z2());
    } 

  }
}
