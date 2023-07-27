#include <iostream>
//#include "llvm/Support/Streams.h"
#include <compare>


 int get_value(int len , int* ptrObstacle);
 int getNextObstacalLen(int len,  int* ptrObsArray);

  int getNextObstacalLen(int len, int* ptrObsArray)
  {
    if(len!=0)
    {
        return *(ptrObsArray+1);
    }
    else
    {
        return 15;
    }
  }

 int get_value(int len , int* ptrObstacle)
{
    int sumOfLens=1+2+3;
    int current_len;
    int lenChangeCounter=0;
    int Position=0;
    int nextLen=0;

    current_len=*(ptrObstacle+Position);

    while(Position<len)
    {        
        Position++;

        if(current_len==*(ptrObstacle+Position)) //need to change the lane
        {
            nextLen=current_len;
            while(current_len==nextLen)
            {
                 nextLen=getNextObstacalLen(len-Position,ptrObstacle+Position );
                 Position++;
                if(Position>len || nextLen>3)
                {
                    break;
                }

            }
           lenChangeCounter++;
           current_len=sumOfLens-(current_len+nextLen);
           Position--; //adjust the position 
        }

    }
 
    return ( lenChangeCounter);
}

int main() 
{
    int obsArray[6]={1,1,2,3,2,1};
    auto result =(10<=>20) >0;
    int tVal=6;
    tVal= get_value(6, &obsArray[0]);
    std::cout << tVal << "\n" <<std::flush;
   std::cout<< result << "\n";

   return 0 ;
}
