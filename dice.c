// Currently solves for sets of three 6-sided dice
// Optimized for speed and not legibility :)

#include<stdio.h>

int r[6], s[6], tHash[12];

// returns P( i > j ) > P( i < j ) 
int compare( int i[6], int j[6] )
{
   int m,n;
   int c = 0;
   for(m = 0; m < 6; m ++) for(n=0; n < 6; n ++) if(i[m] > j[n]) c++;
     return ( c > 18 );
}

void t(int i[6], int f, int max, int size, int j[6] )
{
   if(f == 6)
   {
      if( size == 18 ) t(j,0,1,12,i);
      else
      {
         int m,n;
         for( m = 0, n = 1; m < 12; n ++ ) 
	    if( n != j[0] && n != j[1] && n != j[2] && n != j[3] && n != j[4] && n != j[5] ) 
               tHash[m++] = n;
         for( m = 1, n = 0; m <= 12; m ++ )
            if( m != i[0] && m != i[1] && m != i[2] && m != i[3] && m != i[4] && m != i[5] ) 
               s[n++] = tHash[m-1];
         for ( m = 0; m < 6; m++ ) r[m] = tHash[i[m]-1];

         // Comment out below if statement to get all possible unique triplets of dice
         if( (compare(j,r) && compare(r,s) && compare(s,j)) || (compare(j,s) && compare(s,r) && compare(r,j)) )
            printf("%d %d %d %d %d %d | %d %d %d %d %d %d | %d %d %d %d %d %d\n", j[0],j[1],j[2],j[3],j[4],j[5],r[0],r[1],r[2],r[3],r[4],r[5],s[0],s[1],s[2],s[3],s[4],s[5]);
      } 
      return;
   }
   if( max > size) return;
   for( i[f] = max; i[f] <= size && i[0] <= 1; i[f] ++) t(i, f+1, i[f] + 1,size,j);
}

int main()
{
   int i[6], j[6];
   t(i,0,1,18,j);
   return 0;
}
