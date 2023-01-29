#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int Sum(int numA , int numB) {
  return numA + numB;
}
int Min(int numA , int numB) {
  return numA - numB;
}
double Mul(int numA , int numB) {
  return numA * numB;
}
double Div(double numA , double numB) {
  return (numA / numB);
}
void printLine(){
  printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
}

int main() {
  int numA , numB , selNum;
  
  numA = 0;
  numB = 0;

  printLine();
  printf("100자리 이하 정수 계산기입니다.\n");
  printLine();
  
  while(1){

    selNum = 0;
    printf("원하시는 메뉴의 번호를 선택 후 엔터를 눌러주세요.\n");
    printf("1.숫자A 입력  2.숫자B입력  3.더하기  4.빼기  5.곱하기  6.나누기 7.종료\n");
    printLine();
    scanf("%d",&selNum);
    if(selNum==7){
      printf("계산기를 종료합니다.\n");
      break;
    }
    switch(selNum){
      case 1:
          while (1) {
              printf("숫자A를 입력해주세요 :");
              scanf("%d", &numA);

              if (numA <= 100 && numA >= -100)break;

              printf("-100 ~ 100 사이 정수를 입력해주세요.\n");
          }
        printf("%d 이(가) 숫자A에 입력되었습니다.\n\n",numA);
      break;
      case 2:
          while (1) {
              printf("숫자B를 입력해주세요 :");
              scanf("%d", &numB);

              if (numB <= 100 && numB >= -100)break;

              printf("-100 ~ 100 사이 정수를 입력해주세요.\n");
          }
        printf("%d 이(가) 숫자B에 입력되었습니다.\n\n",numB);
      break;
      case 3:
        printf("숫자A 더하기 숫자B의 결과는 %d입니다.\n\n\n",Sum(numA,numB));
      break;
      case 4:
        printf("숫자A 빼기 숫자B의 결과는 %d입니다.\n\n\n",Min(numA,numB));
      break;
      case 5:
        printf("숫자A 곱하기 숫자B의 결과는 %.0f입니다.\n\n\n",Mul(numA,numB));
      break;
      case 6://Divide two numbers 3,three decimal places
        if(numB==0){
          printf("0으로 나눌 수 없습니다.\n\n");
        }else{
          printf("숫자A 나누기 숫자B의 결과는 %.3f입니다.\n\n\n",Div((double)numA,(double)(numB)));
        }
      break;
      default:
        printf("잘못 입력하셨습니다. 메뉴를 보시고 숫자를 입력해주세요.\n\n\n");
      break;
    }
  }
  return 0;
}