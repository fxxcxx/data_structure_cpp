#include <stdio.h>
#define MAX_TERMS	80

struct Term {				// 하나의 항을 표현하는  클래스
	int		expon;			// 항의 지수
	float	coeff;			// 항의 계수
};

class SparsePoly {			// 희소 다항식 클래스
	int	nTerms;				// 계수가 0이 아닌 항의 개수
	Term term[MAX_TERMS];	// 계수가 0이 아닌 항의 배열

public:
	void read() {
		nTerms = 0;
		while (1) {
			printf("계수 차수 입력(종료:-1): ");
			scanf("%f%d", &(term[nTerms].coeff), &(term[nTerms].expon));
			if (term[nTerms].expon < 0) {
				display("입력 다항식:");
				return;
			}
			nTerms++;
		}
	}
// add함수를 작성해라.
void add(SparsePoly a, SparsePoly b)
{
	int count = 0, bcount = 0;
	int start = 0;
	struct Term add;
	*this = a;
	nTerms += b.nTerms;
	Term *temp = new Term[a.nTerms];
	for(int i =0; i<a.nTerms; i++)
		temp[i] = a.term[i];
	while(count<nTerms && bcount<b.nTerms)
	{
		if(temp[count].expon == b.term[bcount].expon)
		{
			add.coeff = temp[count].coeff+b.term[bcount].coeff;
			add.expon = temp[count].expon;
			term[start++] = add;
			count++;
			bcount++;
			nTerms--;
		}
		else if(temp[count].expon > b.term[bcount].expon)
		{
			term[start++] = temp[count];
			count++;
		}
		else
		{
			term[start++] = b.term[bcount];
			bcount++;
		}
	}
	for(;count<nTerms;count++)
	{
		term[start++] = temp[count];
	}
	for(;bcount<b.nTerms;bcount++)
	{
		term[start++] = b.term[bcount];
	}
	delete[]temp;
}
	
	void display(char *str = "SPoly") {
		int i;
		printf("\t%s", str);
		for (i = 0; i < nTerms; i++) {
			printf("%5.1f", term[i].coeff);
			if (term[i].expon > 0)
				printf(" x^%d", term[i].expon);
			if(i != nTerms - 1)
				printf(" +");
		}
		printf("\n");
	}
} ;
int main()
{
	SparsePoly a, b, c, d, e;
	a.read();
	b.read();
	c.add(a, b);

	a.display(" A = ");
	b.display(" B = ");
	c.display("A+B= ");
	
	return 0;
}
