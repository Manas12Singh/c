#include "BigInteger.h"

Digit *saveDigit(char c,Digit* nextDigit)
{
	Digit *node=(Digit*) malloc(sizeof(Digit));
	if(node==NULL)
		return NULL;
	node->digit=c-'0';
	node->next=nextDigit;
	return node;
}

void freeDigit(Digit **node)
{
	if (*node == NULL)
		return;
	freeDigit(&((*node)->next));
	free(*node);
	*node = NULL;
}

void deleteBigInteger(BigInteger **b)
{
	if (*b == NULL)
		return;
	freeDigit(&((*b)->lastDigit));
	free(*b);
	*b = NULL;
}

BigInteger *toBigInteger(char *s)
{
    BigInteger *temp = (BigInteger *)malloc(sizeof(BigInteger));
	if(temp==NULL)
		return temp;
    temp->lastDigit = NULL;
    int i = 0;
	while (s[i] != '\0' & s[i] != '+' & s[i] != '-' & !(s[i] >= '0' & s[i] <= '9'))
		i++;
	if (s[i] == '-') {
		temp->sign = -1, i++;
	} else {
		temp->sign=1;
		if(s[i]=='+')
			i++;
	}
	while(s[i]=='0')
		i++;
    while (s[i]>='0' & s[i]<='9')
    {
        Digit *newLast= saveDigit(s[i],temp->lastDigit);
		if(newLast==NULL)
		{
			deleteBigInteger(&temp);
			return NULL;
		}
		temp->lastDigit=newLast;
        i++;
    }
    if(temp->lastDigit==NULL) {
		temp->sign = 1;
		temp->lastDigit= saveDigit('0',NULL);
		if(temp->lastDigit==NULL)
		{
			free(temp);
			temp=NULL;
		}
	}
    return temp;
}

void printDigit(Digit *digit)
{
    if (digit == NULL)
        return;
    printDigit(digit->next);
    printf("%d", digit->digit);
}

void printBigInteger(BigInteger *b)
{
    if (b == NULL)
    {
        printf("No number saved.");
        return;
    }
    if (b->sign == -1)
        printf("%c", '-');
    printDigit(b->lastDigit);
    printf("\n");
}

void removeZeroes(Digit **digit)
{
    if (*digit == NULL)
        return;
    if ((*digit)->next != NULL)
        removeZeroes(&((*digit)->next));
    if ((*digit)->digit == 0 & (*digit)->next == NULL)
    {
        free(*digit);
        *digit = NULL;
    }
}

Digit *addDigit(Digit *d1,Digit *d2,short carry)
{
	if(d1==NULL && d2==NULL && carry==0)
		return NULL;
	short num=carry;
	if(d1)
	{
		num+=d1->digit;
		d1=d1->next;
	}
	if(d2)
	{
		num+=d2->digit;
		d2=d2->next;
	}
	carry=num/10;
	num%=10;
	Digit *sum= saveDigit('0'+num,addDigit(d1,d2,carry));
	if(sum==NULL)
		return NULL;
	if( (d1||d2||carry) & (sum->next==NULL))
	{
		free(sum);
		sum=NULL;
	}
	return sum;
}

Digit *subDigit(Digit *d1, Digit *d2,short borrow)
{
	if(d1==NULL)
		return NULL;
	short num=d1->digit-borrow;
	if(d2)
	{
		num-=d2->digit;
		d2=d2->next;
	}
	borrow=(num<0)?1:0;
	num+=10;
	num%=10;
	Digit *diff= saveDigit('0'+num,subDigit(d1->next,d2,borrow));
	if(diff==NULL)
		return NULL;
	if(diff->digit==0 & diff->next==NULL)
	{
		free(diff);
		diff=NULL;
	}
	return diff;
}

int unsignedCompare(Digit *d1, Digit *d2)
{
	if (d1 == NULL && d2==NULL)
		return 0;
	else if(d1==NULL)
		return -1;
	else if(d2==NULL)
		return 1;
	int c = unsignedCompare(d1->next, d2->next);
	if (c == 0)
	{
		if (d1->digit > d2->digit)
			return 1;
		else if (d1->digit < d2->digit)
			return -1;
	}
	return c;
}

int compareBigInteger(BigInteger *b1, BigInteger *b2)
{
	if(b1==NULL | b2==NULL)
		return 0;
	if (b1->sign != b2->sign)
		return b1->sign;
	return b1->sign * unsignedCompare(b1->lastDigit, b2->lastDigit);
}

BigInteger *addBigInteger(BigInteger *b1, BigInteger *b2)
{
	BigInteger *sum=(BigInteger *) malloc(sizeof(BigInteger));
	if(sum==NULL)
		return NULL;
	if(b1==NULL && b2==NULL)
	{
		sum->sign=1;
		sum->lastDigit= saveDigit('0',NULL);
	}
	else if(b1==NULL)
	{
		sum->sign=b2->sign;
		sum->lastDigit= addDigit(b2->lastDigit,NULL,0);
	}
	else if(b2==NULL)
	{
		sum->sign=b1->sign;
		sum->lastDigit= addDigit(b1->lastDigit,NULL,0);
	}
	else if(b1->sign==b2->sign)
	{
		sum->sign=b1->sign;
		sum->lastDigit= addDigit(b1->lastDigit,b2->lastDigit,0);
	}
	else if(unsignedCompare(b1->lastDigit,b2->lastDigit)==1)
	{
		sum->sign=b1->sign;
		sum->lastDigit= subDigit(b1->lastDigit,b2->lastDigit,0);
	}
	else
	{
		sum->sign=b2->sign;
		sum->lastDigit= subDigit(b2->lastDigit,b1->lastDigit,0);
	}
	if(sum->lastDigit==NULL)
	{
		sum->lastDigit= saveDigit('0',NULL);
		sum->sign=1;
	}
	return sum;
}

BigInteger *subtractBigInteger(BigInteger *b1, BigInteger *b2)
{
	BigInteger *diff=(BigInteger *) malloc(sizeof(BigInteger));
	if(diff==NULL)
		return NULL;
	if(b1==NULL && b2==NULL)
	{
		diff->sign=1;
		diff->lastDigit= saveDigit('0',NULL);
	}
	else if(b1==NULL)
	{
		diff->sign=b2->sign*-1;
		diff->lastDigit= addDigit(b2->lastDigit,NULL,0);
	}
	else if(b2==NULL)
	{
		diff->sign=b1->sign;
		diff->lastDigit= addDigit(b1->lastDigit,NULL,0);
	}
	else if(b1->sign!=b2->sign)
	{
		diff->sign=b1->sign;
		diff->lastDigit=addDigit(b1->lastDigit,b2->lastDigit,0);
	}
	else if(unsignedCompare(b1->lastDigit,b2->lastDigit)==1)
	{
		diff->sign=b1->sign;
		diff->lastDigit=subDigit(b1->lastDigit,b2->lastDigit,0);
	}
	else
	{
		diff->sign=b1->sign*-1;
		diff->lastDigit= subDigit(b2->lastDigit,b1->lastDigit,0);
	}
	if(diff->lastDigit==NULL)
	{
		diff->lastDigit= saveDigit('0',NULL);
		diff->sign=1;
	}
	return diff;
}

BigInteger *multiplyBigInteger(BigInteger *b1, BigInteger *b2)
{
	BigInteger *product = (BigInteger *)malloc(sizeof(BigInteger));
	if(product==NULL)
		return NULL;
    if (b1 == NULL | b2 == NULL | (b1->lastDigit->digit==0 & b1->lastDigit->next==NULL) | (b2->lastDigit->digit==0 & b2->lastDigit->next==NULL))
    {
		product->sign=1;
		product->lastDigit= saveDigit('0',NULL);
	    return product;
	}
    if (unsignedCompare(b1->lastDigit, b2->lastDigit) == -1)
    {
        BigInteger *temp = b1;
        b1 = b2;
        b2 = temp;
    }
    product->sign = (b1->sign == b2->sign) ? 1 : -1;
    product->lastDigit = saveDigit('0',NULL);
    Digit *t2 = b2->lastDigit,*trav = product->lastDigit;
    while (t2)
    {
        Digit *t1 = b1->lastDigit, *trav2 = trav;
        int carry = 0;
        while (t1 || carry)
        {
			trav2->digit+=carry;
            if (t1)
            {
                trav2->digit += t1->digit * t2->digit;
                t1 = t1->next;
            }
            carry = trav2->digit / 10;
            trav2->digit %= 10;
            if((trav2->next==NULL) & (t1 || carry))
				trav2->next= saveDigit('0',NULL);
			trav2=trav2->next;
        }
        t2 = t2->next;
		trav=trav->next;
    }
    return product;
}

Digit *specialSubDigit(Digit *d1, Digit *d2,short borrow)
{
	if((d1==NULL) | (d2==NULL & borrow==0))
		return d1;
	d1->digit-=borrow;
	if(d2)
	{
		d1->digit-=d2->digit;
		d2=d2->next;
	}
	borrow=(d1->digit<0)?1:0;
	d1->digit+=10;
	d1->digit%=10;
	d1->next=specialSubDigit(d1->next,d2,borrow);
	if(d1->digit==0 & d1->next==NULL)
	{
		free(d1);
		d1=NULL;
	}
	return d1;
}

Digit *divide(Digit *n1, Digit *n2, BigInteger *q)
{
    if (n1 == NULL)
        return NULL;
    n1->next = divide(n1->next, n2, q);
    if (q)
        q->lastDigit = saveDigit('0',q->lastDigit);
    while (unsignedCompare(n1,n2)>=0)
    {
        n1= specialSubDigit(n1,n2,0);
        if (q)
            q->lastDigit->digit++;
    }
	if(q && q->lastDigit->digit==0 & q->lastDigit->next==NULL)
	{
		free(q->lastDigit);
		q->lastDigit=NULL;
	}
    return n1;
}

BigInteger *divideBigInteger(BigInteger *b1, BigInteger *b2)
{
	if(b1==NULL | b2==NULL)
		return NULL;
	BigInteger *quotient = (BigInteger *)malloc(sizeof(BigInteger));
	if(quotient==NULL)
		return NULL;
	if(b2->lastDigit->digit==0 & b2->lastDigit->next==NULL)
	{
		printf("Cannot divide by 0(Zero).\n");
		return NULL;
	}
    quotient->sign = b1->sign*b2->sign;
    quotient->lastDigit = NULL;
    Digit *dividend = NULL, *t1, *t2 = b1->lastDigit;
    while (t2)
    {
        Digit *temp= saveDigit('0'+t2->digit,NULL);
        if (dividend)
        {
            t1->next = temp;
            t1 = t1->next;
        }
        else
            dividend = t1 = temp;
        t2 = t2->next;
    }
    dividend=divide(dividend, b2->lastDigit, quotient);
	if (quotient->lastDigit == NULL)
	{
		if(dividend==NULL)
			quotient->sign = 1;
		quotient->lastDigit= saveDigit('0',NULL);
	}
	if((b1->sign==-1) & (dividend!=NULL))
		quotient->lastDigit=specialSubDigit(quotient->lastDigit,NULL,-1),freeDigit(&dividend);;
    return quotient;
}

BigInteger *modulusBigInteger(BigInteger *b1, BigInteger *b2)
{
	if (b1 == NULL | b2 == NULL)
		return NULL;
	BigInteger *mod = (BigInteger *)malloc(sizeof(BigInteger));
	if(mod==NULL)
		return NULL;
    mod->sign = 1;
	if(b2->lastDigit->digit==0 & b2->lastDigit->next==NULL)
	{
		printf("Cannot divide by 0(Zero).\n");
		return NULL;
	}
	Digit *dividend = NULL, *t1, *t2 = b1->lastDigit;
	while (t2)
	{
		Digit *temp= saveDigit('0'+t2->digit,NULL);
		if (dividend)
		{
			t1->next = temp;
			t1 = t1->next;
		}
		else
			dividend = t1 = temp;
		t2 = t2->next;
	}
    mod->lastDigit = divide(dividend, b2->lastDigit, NULL);
	if(mod->lastDigit!=NULL & b1->sign==-1)
	{
		Digit *temp= subDigit(b2->lastDigit,mod->lastDigit,0);
		freeDigit(&(mod->lastDigit));
		mod->lastDigit=temp;
	}
    if (mod->lastDigit == NULL)
        mod->lastDigit= saveDigit('0',NULL);
    return mod;
}