#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void main(){
	
	int fixed,j,l,k;
	
	int i,N,*a;                       //Obtain 10 random integers between 0 and 19
	time_t T=1;
	srand(time(&T));
	N=10;
	a=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++){ 
		a[i]=rand()%20;
		printf("%d,",a[i]);
     }
     
	 printf("\n");
	

		fixed=a[0];
		l=1;
		k=0;
		
		while(l<=N-2){                             
		  
		  if(fixed>a[l] && fixed<=a[l+1]){         //Test for the first position to interpolate unfixed numbers
			 
			for(j=k;j<=l-1;j++){
				a[j]=a[j+1];
			}
			a[l]=fixed;
		    fixed=a[k];
		    l=k;
		    printf("1.\t%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
	      
		  }else if(l==N-2 && fixed>=a[l+1]) {      //If the first position is the last one.
			for(j=k;j<=l;j++){
				a[j]=a[j+1];
			}	
			a[l+1]=fixed;
			fixed=a[k];
			l=k;
		    printf("2.\t%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		  
		  }else if(l==N-2 && a[k]==fixed){         //If we cannot find such positions,then we fix a number at located position and test for the next.
			fixed=a[k+1];
			k++;
			l=k;
			
		  }
	    		
		  
	    
		  l++;
	    
	   }  
	    

    
    system("pause");

}
	
