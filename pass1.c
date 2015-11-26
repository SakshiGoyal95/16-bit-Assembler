#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct op_table
{
        char opc[20];             //mnemonic name
        char opr1[20];            //operand 1
        char opr2[20];            //operand 2
        char opr3[20];            //operand 3
        char bin[20];            //hexadecimal code of mnemonic
        int len;                 //no. of cycles
        int ins_class;           //instruction class
};

int main()
{
	FILE *f1, *f2,*fh,*f3;
	char file1[20],file2[20];
	printf("Enter source file name:");
	scanf("%s",file1);
	printf("Enter destination file name:");
	scanf("%s",file2);
	f1 = fopen(file1, "r");		//file containing assembly language codes using new ISA opened in read mode
	
	f2 = fopen(file2,"w");		//pass one file opened in write mode
	
	f3 = fopen("opcodeTable.txt","r");
	
	
	char reg[20],regis[20],regop[20];
			
	struct op_table s[100];
	int q,x,f;
	char opcode[20];
	int opcod;
	fscanf(f3,"%s",opcode);
	
	
	while(!feof(f3))
	{
		for(q=0;q<100;q++)
		{
			for(x=0;x<20;x++)
			{
				s[q].opc[x]=opcode[x];
			}
			fscanf(f3,"%s",opcode);
				for(x=0;x<20;x++)
			{
				s[q].opr1[x]=opcode[x];
			}
			
			fscanf(f3,"%s",opcode);
				for(x=0;x<20;x++)
			{
				s[q].opr2[x]=opcode[x];
			}
			
			fscanf(f3,"%s",opcode);
				for(x=0;x<20;x++)
			{
				s[q].opr3[x]=opcode[x];
			}
			
			fscanf(f3,"%s",opcode);
				for(x=0;x<20;x++)
			{
				s[q].bin[x]=opcode[x];
			}
			
			fscanf(f3,"%d",opcode);
			
				s[q].len=opcode[0];
						
			fscanf(f3,"%d",opcode);
			
				s[q].ins_class=opcode[0];
			
			
			fscanf(f3,"%s",opcode);
			
			
		}
	}
	
	fclose(f3);
	char str[10],colon[10],garbage[10];
	int z,i,j,k,ilc=-1, flag = 0, flag3 = 0,p=0,flag4=0; //ilc is initialized to -1 sice we are incrementing it later as ilc of program starts from 0
	
    char c ,ch, sh,opcd[5],d,re[20],check[10];
	
	fprintf(f2,"SYMBOL TABLE\n");		
	fprintf(f2,"LABEL_NAME\tILC\n");
	
	while((c = fgetc(f1)) != EOF)    
	{
		if(c == '\n')
		{
			fscanf(f1,"%s",str);
			
            for(i=0;i<100;i++)                       //calculating ilc
			{
                
				strcpy(opcd,s[i].opc);
				
				flag =0;
				if((strcmp( str,opcd)) == 0)
				{
					
					ilc+=s[i].len; 
                    flag = 1;
					int temp;
					temp=i;
				
					if(strchr(s[temp].opr1,'null')==NULL)
					{
					
						fscanf(f1,"%s",reg);
						
						if(strchr(reg,',')!=NULL)
						{
							printf("USE OF COMMA IS NOT ALLOWED\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							
						}
						if(strchr(reg,';')!=NULL)
						{
							printf("SEMI_COLON NOT EXPECTED HERE\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						if(strchr(s[temp].opr1,'data')!=NULL)
							if(strcmp(reg,"0H")!=0 &&strcmp(reg,"1H")!=0 && strcmp(reg,"2H")!=0 && 
							strcmp(reg,"3H")!=0 && strcmp(reg,"4H")!=0 && strcmp(reg,"5H")!=0 &&
							strcmp(reg,"6H")!=0 && strcmp(reg,"7H")!=0 && strcmp(reg,"8H")!=0 &&
							strcmp(reg,"9H")!=0 && strcmp(reg,"AH")!=0 && strcmp(reg,"BH")!=0 && 
							strcmp(reg,"CH")!=0 && strcmp(reg,"DH")!=0 && strcmp(reg,"EH")!=0 && strcmp(reg,"FH")!=0) 
							{
								
							printf("INVALID DATA\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							}
						if (strchr(reg,'R')!=NULL || strchr(reg,'F')!=NULL)
					{	
						if(strcmp(reg,"R0")!=0 && strcmp(reg,"R1")!=0 && strcmp(reg,"R2")!=0 && strcmp(reg,"R3")!=0 
						&& strcmp(reg,"R4")!=0 && strcmp(reg,"R5")!=0 && strcmp(reg,"R6")!=0 && strcmp(reg,"F0")!=0 
						&& strcmp(reg,"F1")!=0 && strcmp(reg,"F2")!=0 && strcmp(reg,"F3")!=0 && strcmp(reg,"F4")!=0 
						&& strcmp(reg,"F5")!=0 && strcmp(reg,"FLAG")!=0 && strcmp(reg,"PC")!=0 && strcmp(reg,"SP")!=0)
						{
							printf("INAPPROPRIATE REGISTER NAME\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						
					}				
					
				}
				
				
				if(strchr(s[temp].opr2,'null')==NULL)
					{
					
						fscanf(f1,"%s",reg);
						
						if(strchr(reg,',')!=NULL)
						{
							printf("USE OF COMMA IS NOT ALLOWED\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							
						}
						if(strchr(reg,';')!=NULL)
						{
							printf("SEMI_COLON NOT EXPECTED HERE\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						if(strchr(s[temp].opr2,'data')!=NULL)
							if(strcmp(reg,"0H")!=0 &&strcmp(reg,"1H")!=0 && strcmp(reg,"2H")!=0 && 
							strcmp(reg,"3H")!=0 && strcmp(reg,"4H")!=0 && strcmp(reg,"5H")!=0 &&
							strcmp(reg,"6H")!=0 && strcmp(reg,"7H")!=0 && strcmp(reg,"8H")!=0 &&
							strcmp(reg,"9H")!=0 && strcmp(reg,"AH")!=0 && strcmp(reg,"BH")!=0 && 
							strcmp(reg,"CH")!=0 && strcmp(reg,"DH")!=0 && strcmp(reg,"EH")!=0 && strcmp(reg,"FH")!=0) 
							{
								
							printf("INVALID DATA\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							}
					
						if (strchr(reg,'R')!=NULL || strchr(reg,'F')!=NULL)
					{	
						if(strcmp(reg,"R0")!=0 && strcmp(reg,"R1")!=0 && strcmp(reg,"R2")!=0 && strcmp(reg,"R3")!=0 
						&& strcmp(reg,"R4")!=0 && strcmp(reg,"R5")!=0 && strcmp(reg,"R6")!=0 && strcmp(reg,"F0")!=0 
						&& strcmp(reg,"F1")!=0 && strcmp(reg,"F2")!=0 && strcmp(reg,"F3")!=0 && strcmp(reg,"F4")!=0 
						&& strcmp(reg,"F5")!=0 && strcmp(reg,"FLAG")!=0 && strcmp(reg,"PC")!=0 && strcmp(reg,"SP")!=0)
						{
							printf("INAPPROPRIATE REGISTER NAME\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						
					}				
					
				}
				if(strchr(s[temp].opr3,'null')==NULL)
					{
						
						fscanf(f1,"%s",reg);
						
						if(strchr(reg,',')!=NULL)
						{
							printf("USE OF COMMA IS NOT ALLOWED\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							
						}
						if(strchr(reg,';')!=NULL)
						{
							printf("SEMI_COLON NOT EXPECTED HERE\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						if(strchr(s[temp].opr3,'data')!=NULL)
							if(strcmp(reg,"0H")!=0 &&strcmp(reg,"1H")!=0 && strcmp(reg,"2H")!=0 && 
							strcmp(reg,"3H")!=0 && strcmp(reg,"4H")!=0 && strcmp(reg,"5H")!=0 &&
							strcmp(reg,"6H")!=0 && strcmp(reg,"7H")!=0 && strcmp(reg,"8H")!=0 &&
							strcmp(reg,"9H")!=0 && strcmp(reg,"AH")!=0 && strcmp(reg,"BH")!=0 && 
							strcmp(reg,"CH")!=0 && strcmp(reg,"DH")!=0 && strcmp(reg,"EH")!=0 && strcmp(reg,"FH")!=0) 
							{
								
							printf("INVALID DATA\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
							}
						if (strchr(reg,'R')!=NULL || strchr(reg,'F')!=NULL)
					{	
						
						if(strcmp(reg,"R0")!=0 && strcmp(reg,"R1")!=0 && strcmp(reg,"R2")!=0 && strcmp(reg,"R3")!=0 
						&& strcmp(reg,"R4")!=0 && strcmp(reg,"R5")!=0 && strcmp(reg,"R6")!=0 && strcmp(reg,"F0")!=0 
						&& strcmp(reg,"F1")!=0 && strcmp(reg,"F2")!=0 && strcmp(reg,"F3")!=0 && strcmp(reg,"F4")!=0 
						&& strcmp(reg,"F5")!=0 && strcmp(reg,"FLAG")!=0 && strcmp(reg,"PC")!=0 && strcmp(reg,"SP")!=0)
						{
							printf("INAPPROPRIATE REGISTER NAME\t INSTRUCTION NO. %d\n",ilc+1);
							flag4=1;
						}
						
					}				
					
				}
				break;
			}
			}
		
			
			
			
	        if(flag == 0)                           //printing label name and ilc (Symbol Table)
	        {
	        	
	        	fscanf(f1,"%s",colon);
	        if (strcmp(colon,":") == 0)
	        	{	 
					if(flag4==0){
	        		fprintf(f2,"%s\t",str);
					fprintf(f2,"\t%d\n",++ilc);}
				}
				else                   //if illegal opcode is encountered program is terminated
				{
					flag3 = 1;
					printf ("ILLEGAL OPCODE\tINSTRUCTION NO:%d\n",ilc+1);
					
				}
            }
			
		}
		
	}
	
					
	rewind(f1);
	if(flag4==0){
	fprintf(f2,"\n\n\t\t   \t\t\tOPCODE TABLE\n\n");
	fprintf(f2,"MNEMONIC \tOPR1 \t\tOPR2 \t\tOPR3 \t\tBIN_CODE \tINSTR. LENGTH \tINSTR. CLASS\n");}
	for(i=0; i<100; i++)       //printing opcode table
	{
		rewind(f1);
		while((c = fgetc(f1)) != EOF)
	    {
		     if(c == '\n')
		     {
		        	fscanf(f1,"%s",str);
		        	strcpy(opcd,s[i].opc);
		        	if((strcmp( str,opcd)) == 0)
				    {	
						if(flag4==0)
	                     fprintf(f2,"%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t    %d \t\t   %d\n",s[i].opc,s[i].opr1,s[i].opr2,s[i].opr3,s[i].bin,s[i].len,s[i].ins_class);
	                     break;
                    }
			}
		}
	}	

	
	fclose(f1);
	fclose(f2);
	printf("Enter 1 for help and 2 to exit\n");
					scanf("%d",&z);
						if(z==1)
						{			
						
							fh=fopen("help.txt", "r");
							while(1)
							{
								ch = fgetc(fh);
								if( feof(fh) )
								{
									break ;
								}
								printf("%c", ch);
							}
							fclose(fh);
							//break;
							//break;
						}
						else
	
	return 0;
}
