
#define max 5
void ins(int q[],int *f,int *r,char ch[],int ele)
{

 if((*f==0 && *r==max-1) || *f-1==*r)
 {
  printf("\n%s queue is full",ch);
 }
 else
 {
    if(*r==max-1 && *f>0)
       *r=-1;
  *r+=1;
  q[*r]=ele;
  if(*r==0 && *f==-1)
    *f=0;
 }
}
void del(int q[],int *f,int *r)
{
 if(*f==-1)
 {
  printf("\nqueue is empty");
 }
 else
 {
  q[*f]=0;
  if(*f==max-1 && *r<*f)
  {
   *f=0;
  }
  else if(*f==*r)
  {  *f=-1;*r=-1; }
  else
   *f+=1;
 }
}
void display(int c[],int r[],int f1,int r1,int f2,int r2)
{
 int i=0;
 printf("\nCitizen Queue\n");
 for(i=f1;i<=max-1 && i!=-1;i++)
 {
  printf(" %d ",c[i]);
  if(i==r1)
    break;
  if(i==max-1)
   i=-1;
 }
 printf("\nRegular Queue\n");
 for(i=f2;i<=max-1 && i!=-1;i++)
 {
  printf(" %d ",r[i]);
  if(i==r2)
    break;
  if(i==max-1)
   i=-1;
 }
}
void main()
{
 int cq[max],rq[max],choice,f1=-1,r1=-1,f2=-1,r2=-1;
 int *cf=&f1,*cr=&r1,*rf=&f2,*rr=&r2,temp;
 clrscr();
 while(1)
 {
  printf("\n1.insert");
  printf("\n2.delete");
  printf("\n3.exit");
  printf("\nenter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:if(((*cf==0 && *cr==max-1)||*cf-1==*cr) && ((*rf==0 && *rr==max-1)||*rf-1==*rr))
	    printf("\nBoth Queue is full");
	  else{
	    printf("\nenter new age : ");
	    scanf("%d",&temp);
	    if(temp>=60)
	      ins(cq,cf,cr,"Citizen",temp);
	    else
	      ins(rq,rf,rr,"Regular",temp);
	  }
	 // printf("\ncitizen Queue f=%d and r=%d\nregular queue f=%d and r=%d",*cf,*cr,*rf,*rr);
	  display(cq,rq,*cf,*cr,*rf,*rr);
	  break;
   case 2:if(*cf==-1 && *rf==-1)
	    printf("\nBoth Queue is Empty");
	  else
	  {
	     if(*cf==-1)
	     {
	       printf("\nCitizen Queue is Empty");
	       del(rq,rf,rr);
	     }
	     else
	      del(cq,cf,cr);
	  }

	   display(cq,rq,*cf,*cr,*rf,*rr);
	  break;
   case 3:exit(0);
  }
 }
 getch();
}