#include <stdio.h>
#include <math.h>

void investmentCalc();
double calcSimpInter(double princ, double rate, double time);
double calcCompInter(double princ, double rate, double time, int n);

int main() {
  int choice;
  printf("Financial Calculator App\n");
  printf("\n");
  for (;;) {
    printf("Enter 1 for investment calculator\n");
    printf("Enter 0 to exit\n");
    printf("\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if(choice == 0){
      printf("Exiting app.....");
      break;
    }else if(choice==1){
      investmentCalc();
    }else{
      printf("Not a choice");
    }
  }
  return 0;
}

void investmentCalc() {
  double princ, rate, time;
  int compFreq;
  char interType;
  printf("Enter principle amount: ");
  scanf("%lf", &princ);

  printf("Enter annual interest rate: ");
  scanf("%lf", &rate);

  printf("Enter time (years): ");
  scanf("%lf", &time);

  printf("Type of interest: S for Simple or C for Compound: ");
  scanf(" %c", &interType);
  printf("\n");
  if(interType == 'S' || interType == 's'){
      printf("Simple Interest: %.4f\n", calcSimpInter(princ, rate, time));
      printf("\n");
  }else if(interType == 'C' || interType == 'c'){
      printf("Enter number of times interest is compounded per year:");
      scanf("%d", &compFreq);
      printf("Compound Interest: %.4f\n", calcCompInter(princ, rate, time, compFreq));
  }else{
      printf("Invalid Interest type entered");
  }
}

double calcSimpInter(double princ, double rate, double time) {
  return princ * (rate / 100) * time;
}

double calcCompInter(double princ, double rate, double time, int n) {
  double r= rate/100;
  return princ * pow((1+r/n), n * time) - princ;
}