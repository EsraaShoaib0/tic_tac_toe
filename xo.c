#include <stdio.h>
/*    X-O Game 		*/
typedef unsigned long uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
void set_score(uint8 ch);
uint8 check_winner();
uint8 check_full(uint8 i,uint8 j);
uint8 player_turn();
void insert(uint8 r,uint8 c,uint8 data);
void set_shape(uint8);

    static uint8 count=0;			//to count number of moves
    static uint8 scorex=0;        //score of the first player
    static uint8 scoreo=0;        //the score of the second player 
    static uint8 arr[3][3] ={
                      {' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '}
							}; 
//main function
int main(){
	uint8 r,c;
	while(check_winner()==0)
	{
		set_shape(arr[3][3]);
		printf("enter the number of row , column");
		scanf("%c",&r);
		scanf("%c",&c);
		insert(r,c,player_turn());
		check_winner();
	}
	
	return 0;
}
set_shape(uint8 arr[3][3])
{
	uint8 r,c;
	for(r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			printf("%c",arr[r][c]);
		}
	}
}
 uint8 check_full(uint8 i,uint8 j)
     {
		 if(arr[i][j]==' ')
		 {
			 return 0;
		 }
		 else
		 {
         return 1;
		 }
     }
  void insert(uint8 r,uint8 c,uint8 data)
     {
         count++;
        if (check_full(r,c)==0)		//if it's empty then insert
        {
            arr[r][c]=data; 
            
        }
        else
        {
            printf("you can't overwrite ");
        }
        
     }
uint8 player_turn()
    {
        if(count%2==0)
        {
            return 'x';
        }
        else
        {
            return 'o';
        }
    }
void set_score(uint8 ch)
{
	if(ch=='x')    		 //player1 win
	{ 
	scorex++;
	printf("player x win ;)");
	}
    else 				//player2 win
	{
		scoreo++;
		printf("player o win ;)");
	}          
           
}
uint8 check_winner(){
	 if (count ==9)
        { 
        printf("Draw x)");
        return 1;
        }
        else 
        {
        for(int i=0;i<=2;i++)     //rows checker 
        {
            if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] && arr[i][0]!=' ')
            {
                setscore(arr[i][0]);
                return 1;
            }
        }
        for(int i=0;i<=2;i++)      //columns checker
        {
            if(arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]&& arr[0][i]!=' ')
              {
                setscore(arr[0][i]);
                return 1;
            }
        }
        if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] && arr[0][0]!=' ')       //main diagonal checker
        {
            setscore(arr[0][0]);
            return 1;
        }
        else if(arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0] && arr[0][2]!=' ')  //2nd diagonal checker
        {
            setscore(arr[0][0]);
            return 1;
        }
        
        else
        {
            return 0;
        }
        }
        

	
}