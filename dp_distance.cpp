#include<iostream>
#include<string>
 
using namespace std;
 
int minEditDistance(string src, string dest, int len1, int len2)
{
    int i, j;
 
    int edit[len1+1][len2+1];
     for(i=0;i<=len1;i++)
        edit[i][0]=i;    
 
    for(j=0;j<=len2;j++)
        edit[0][j]=j;  
 
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(src[i-1]==dest[j-1])
            {
                edit[i][j]=edit[i-1][j-1];
            }
             else
            {
                int x=1+edit[i-1][j];     
                int y=1+edit[i][j-1];    
                int z=1+edit[i-1][j-1];  
                edit[i][j]=min(x,min(y,z));
 
            }
        }
    }
     return edit[len1][len2];
}
 
 
int main()
{
    string src,dest;
 
    cout<<"Enter source string   ";
    getline(cin, src);
 
    cout<<"Enter destination string   ";
    getline(cin, dest);
 
    int len1=src.length();  
    int len2=dest.length(); 
 
    cout<<"Minimum number of edit operations required for transforming \nsource string to destination string is "<<minEditDistance(src,dest,len1,len2);
 
    cout<<endl;
    return 0;
}
