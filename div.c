//division of the given numbers
#include <stdio.h>

void dectobinary(int num,int nbit, int arry[]){
    while(nbit>=0){
        if(num>0){
            arry[nbit-1] = num%2;
            num = num/2;
            nbit--;
        }
        else{
            arry[nbit-1]=0;
            nbit--;
        }
    }
}


storeAccumulator(int arry[],int nbit){
    int i;
    for(i=0;i<nbit;i++){
        arry[i]=0;
    }
}

void showbinary(int arry[],int nbit){
    int i;
    for(i=0;i<nbit;i++){
        printf("%d",arry[i]);
    }
    printf("\n");
}

void twoComplement(int arry[], int twos_M[],int nbit){
	int bitsum,i,carry=1;
// 	reverse the array data
	for(i=0;i<nbit;i++){
		arry[i] = !arry[i];
	}

	for(i=nbit-1;i>=0;i--){
		bitsum = arry[i]+carry;
		twos_M[i] = bitsum%2;
		carry = bitsum/2;
	}

// 	make it to original form
	for(i=0;i<nbit;i++){
		arry[i] = !arry[i];
	}
}


void addbinary(int arry1[],int arry2[],int nbit){
	int i, bitsum,carry =0;
	for(i=nbit-1;i>=0;i--){
		bitsum = arry1[i]+arry2[i]+carry;
		arry1[i] = bitsum%2;
		carry = bitsum/2;
	}
}


void binarytodec(int arry[],int nbit){
	int add=0,i;
	if(arry[0]==1){
		add = add-arry[0] * pow(2,nbit-1);
	}
	else{
		add = add+arry[0] * pow(2,nbit-1);
	}
	for(i=1;i<=nbit-1;i++){

		add = add + arry[i] * pow(2,(nbit-1)-i);

	}
	printf("The decimal equivalent is %d\n\n",add);
}

void division(int M[],int Q[],int A[],int nbit){
    int twos_M[10],i,count;
    count = nbit;

    // make tows complement
    twoComplement(M,twos_M,nbit+1);

    while(count>0){
        if(A[0]==0){
            // shift left
            for(i=0;i<nbit+1;i++){
                A[i]=A[i+1];
            }
            A[nbit]=Q[0];
            // Add A = A-M
            addbinary(A,twos_M,nbit+1);

            // show Q shift
            for(i=0;i<nbit;i++){
                Q[i]=Q[i+1];
            }

            // provide the Q0 value
            if(A[0]==0){
                Q[nbit-1] = 1;
            }
            else if (A[0]==1){
                Q[nbit-1]=0;
            }

            count=count-1;
        }
        else{
            // shift the A
            for(i=0;i<nbit+1;i++){
                A[i]=A[i+1];
            }
            A[nbit]=Q[0];

            // Add the number
            addbinary(A,M,nbit+1);


            // show Q shift
            for(i=0;i<nbit;i++){
            Q[i]=Q[i+1];
            }

            // provide the value for Q0
            if(A[0]==0){
                Q[nbit-1]=1;
            }
            else if(A[0]==1){
                Q[nbit-1]=0;
            }
            count=count-1;
        }
    }

    printf("\n-----OutPut----\n");
    if(A[0]==1){
        addbinary(A,M,nbit+1);

        printf("\nBinary of Quotient\n");
        showbinary(Q,nbit);
        binarytodec(Q,nbit);
        printf("\nBinary of Remainder\n");
        showbinary(A,nbit+1);
        binarytodec(A,nbit+1);

    }
    else if (A[0]==0){

        printf("\nBinary of Quotient\n");
        showbinary(Q,nbit);
        binarytodec(Q,nbit);
        printf("\nBinary of Remainder\n");
        showbinary(A,nbit+1);
        binarytodec(A,nbit+1);
    }
}

int main() {
    int nbit,num1,num2,M[20],Q[20],A[20];
    printf("Enter Dividend 'Q'?");
    scanf("%d",&num2);
    printf("Enter Divisor 'M'?");
    scanf("%d",&num1);
    printf("Enter nth number of bit?");
    scanf("%d",&nbit);

    dectobinary(num1,nbit+1,M);
    dectobinary(num2,nbit,Q);

    printf("\n---Data---\n");
    printf("%d binary equivalent --> ",num2);
    showbinary(Q,nbit);
    printf("%d binary equivalent --> ",num1);
    showbinary(M,nbit+1);
    printf("Accumulator equivalent --> ");
    storeAccumulator(A,nbit+1);
    showbinary(A,nbit+1);

    division(M,Q,A,nbit);
    return 0;
}


