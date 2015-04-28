#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(){
	
	int fixed,temp,j,counters,counterl,num_known;
	
	int i,N,*a;                       //Obtain 11 random integers between 0 and 19 written into a[1]~a[11],and a[0] is prepared for storage.
	
	time_t T=1;
	srand(time(&T));
	N=12;
	a=(int*)malloc(N*sizeof(int));
	for(i=1;i<N;i++){ 
		a[i]=rand()%20;
		printf("%d,",a[i]);
     }
     a[0]=0;

  printf("\n\n\n");
 
  j=1;
  counters=0;                  //Recording the number of (elements > pivot) forward the position of pivot.
  counterl=0;                  //Recording the number of (elements < pivot) afterward the position of pivot.
  fixed=a[N/2];                //Start Quick sort from the midian position of an array,and define it as pivot.
  num_known=0;                 //a counter for recording the maximal number of operations 
  printf("pivot=%d\n",fixed);
  
  
  
  
  
  while(j<N/2){
	
  	if(a[j]>fixed){              //Counting the number of (elements > pivot) forward the position of pivot.     
      counters=counters+1;
	}
  	if(a[N-j]<fixed){            //Counting the number of (elements < pivot) forward the position of pivot.
      counterl=counterl+1;
	}
	
    
    
	if(counters!=counterl && j==N/2-1){                  //Obtain the i-th position of naturally-ordered array,but not the median of this array.
		printf("(#{S|S>pivot},#{L|L<pivot})=(%d,%d)\n",counters,counterl);
		printf("the %d-th position=%d\n",(N+1)/2+(counterl-counters),fixed);
		
		if(a[N/2]!=a[N/2+(counterl-counters)]){
		  a[N/2]=a[N/2+(counterl-counters)];
		  a[N/2+(counterl-counters)]=fixed;
		  fixed=a[N/2];
	    
		}else if(a[N/2]==a[N/2+(counterl-counters)] && N/2+(counterl-counters)-1!=0){
		  a[N/2]=a[N/2+(counterl-counters)-1];	
		  a[N/2+(counterl-counters)-1]=fixed;
		  fixed=a[N/2];	
	    
		}else{  
		  a[N/2]=a[N/2+(counterl-counters)+1];	
		  a[N/2+(counterl-counters)+1]=fixed;
		  fixed=a[N/2];	
		  
	    }
				
		printf("%d,%d,%d,%d,%d,(%d),%d,%d,%d,%d,%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]);
		j=0;
		counters=0;
		counterl=0;
		printf("\n\npivot=%d\n",fixed);
		num_known++;
     
	}else if(counters==counterl && j==(N+1)/2-1){         //Obtain the median of the well-arraged array.
		printf("the median(%d-th position)=%d\n",N/2+(counterl-counters),fixed);		
		printf("\t%d,%d,%d,%d,%d,(%d),%d,%d,%d,%d,%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]);
	
	}else if(num_known==N/2){                             //Due to ill-condition of initial pivot,we try to reset it and execute from this new pivot again.
		  a[N/2]=a[N-1];
		  a[N-1]=fixed;
		  fixed=a[N/2];
		printf("Reset the initial pivot.\n");
		printf("%d,%d,%d,%d,%d,(%d),%d,%d,%d,%d,%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]);
		j=0;
		counters=0;
		counterl=0;
		num_known=0;
		printf("\n\npivot=%d\n",fixed);
		
     }
	
	j++;	
}

 
		

   system("PAUSE");  
   return 0;

}




