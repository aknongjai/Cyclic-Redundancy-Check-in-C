#include<stdio.h>
int a[100],b[100],i,j,len,k,count=0,gpLen;
// Generator Polynomial: g(x)=x^16+x^12+x^5+1
int gp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int main(){
  gpLen=17;
  void div();
  printf("\n Enter the length of the data frame :\n" );
  scanf("%d",&len);
  printf("Enter the message :\n");
  for(i=0;i<len;i++){
    scanf("%d",&a[i]);
  }

  //adding zeroes,but by default the array contains zeroes.So when I take (len+16) it will give the same result
  //must check what's the default value first for empty array??
  for(i=0;i<16;i++){
    a[len++]=0;//len has been incremented by 16
  }
  printf("%d is length after adding zeroes\n",len);
  //Or
  //len=len+16;
  //putting the dataword to b[100]
  for(i=0;i<len;i++){
    b[i]=a[i];
  }
  // for(i=0;i<len;i++){
  //   printf("%d ",b[i]);
  // }

  //no. of times to be devided is equal to the msg length
  k=len-16;//i can do it as--- k=len ---just after getting the value of len from user
  div();


  for(i=0;i<len;i++){
    if(b[i]==0 && a[i]==0){
      b[i]=0;
    }
    // else if(b[i]==1 && a[i]==0){ //this must be vice versa
    //   b[i]==1;
    // }

    else if (b[i]==1 && a[i]==1)// no such case will come ,though just writing for understanding
    {
      b[i]=0;
    }
    else{
      b[i]=1;
    }
    // b[i]=b[i]^a[i];
  }
  printf("\n data to be transmitted : \n");
  for(i=0;i<len;i++){
    printf("%3d",b[i]);
  }
  printf("Enter the recieved data : \n");
  for(i=0;i<len;i++){
    scanf("%d",&a[i]);
  }
  div();
  for(i=0;i<len;i++){
    if(a[i]!=0){
      printf("Error in recieved data\n");
      goto END;
    }
  }
  printf("Data recieved is Error Free\n");
  END: printf("Remainder is :\n");
  for(i=(len-16);i<len;i++){
    printf("%2d ",a[i]);
  }
  printf("\n");
}


void div()
{
  for(i=0;i<k;i++){
    if(a[i]==1)// gp[0]=0 will not make sense
    {
      for(j=i;j<17+i;j++){// (17+i) because the size of the devisor must be 17
        if(a[j]==0 && gp[count++]==0){
          a[j]=0;
        }else if(a[j]==1 && gp[count++]==1){
          a[j]=0;
        }
        else{
          a[j]=1;
        }
        // a[j]=a[j]^gp[count++];
      }
    }
    count=0;
  }
}
