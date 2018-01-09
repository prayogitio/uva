#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int s, b, l, r;
    map<int,int> left_buddies;
    map<int,int> right_buddies;
    while ( scanf("%d %d", &s, &b) && (s != 0 && b != 0) )
    {        
        for ( int i = 1; i <= s; ++i )
        {
            left_buddies[i] = i - 1;
            right_buddies[i] = i + 1;
        }
        for ( int i = 0; i < b; ++i)
        {
            scanf("%d %d", &l, &r);
            if ( left_buddies[l] != 0 ) printf("%d ", left_buddies[l]);
            else printf("* ");
            if ( right_buddies[r] != s + 1 ) printf("%d\n", right_buddies[r]);
            else printf("*\n");
            left_buddies[right_buddies[r]] = left_buddies[l];
            right_buddies[left_buddies[l]] = right_buddies[r];
        }
        printf("-\n");
        left_buddies.clear();
        right_buddies.clear();
    }
    return 0;
}