#include<stdio.h>

#define MAX_DEGREE 80 //최고차수는 80

class Polynomial{
	
	int degree;
	float coef[MAX_DEGREE];
	
public:
	void read(){
			
		int i;
		printf("다항식의 최고 차수를 입력하시오:");
		scanf("%d",&degree);
		printf("각 항의 계수를 입력하시오 (총 %d개):",degree + 1);
		for(i=degree; i>=0; i--)
			scanf("%f",coef+i);
	}
	/*
	void print(char*str){
		int i;
		printf("\t%s",str);
		for(i=degree;i>0;i--)
			printf("%5.1fx^%d+",coef[i],i);
		printf("%4.1f\n", coef[0]);
	}
	*/
	void add(Polynomial a, Polynomial b){
		int i;
		if(a.degree>b.degree){
			*this = a;
			for(i=0; i<=b.degree; i++)
				coef[i]+=b.coef[i];
		}
		
		else{
			*this = b;
			for (i=0; i<=a.degree; i++)
				coef[i] += a.coef[i];
		}
	}
		/*
	int isZero(){return degree == 0;}
	*/
	
	void display(const char*str="Poly="){
		int i;
		printf("\t%s", str); //탭
		for(i=degree; i>0; i--){ //차수
			if(coef[i] != 0){ //차수가 0이 아니면 실시, 계속 돌다 숫자항 나오며 탈출
				if(i != degree) //차수와 i가 다르면
					printf("+"); // 플러스, 이건 처음에 안붙이려고 쓰는거
				
				if(coef[i]==1) //x앞에 뭐 안붙음
					printf("x^%d",i);
				
				else //1아니야? 그럼 숫자 붙여
					printf("%5.1fx^%d",coef[i],i);
			}
		}
		
		if(coef[0]!=0) //숫자항이 0이면 안써도 됨. 근데 0이 아니면 배열에 들어있는 값 써줘
			printf("+%4.1f\n",coef[0]);
		}
	};

int main()
{
	Polynomial a,b,c,d,e;
	
	a.read();
	
	b.read();
	
	c.add(a,b);
	
	a.display("A=");
	b.display("B=");
	c.display("A+B=");
	
	
	return 0;
}
