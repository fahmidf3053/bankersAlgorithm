#include<bits/stdc++.h>

using namespace std;

int main()
{
    int P=5,R=3;
    int n[P][R];//need matrix
    bool f[P];

    // Input from the slide
	int avl[]={3,3,2};

	int mx[][R]={{7,5,3},
                 {3,2,2},
                 {9,0,2},
                 {2,2,2},
                 {4,3,3}};

	int alt[][R]={{0,1,0},
                  {2,0,0},
                  {3,0,2},
                  {2,1,1},
                  {0,0,2}};

    for(int i=0;i<P;i++)
        f[i]=false;

	for (int i=0;i<P;i++)
		for (int j=0;j<R;j++)
			n[i][j]=mx[i][j]-alt[i][j];

	int use[R];
	for (int i=0;i<R;i++)
		use[i]=avl[i];

	for(int cn=0;cn<P;)
	{
		bool fnd=false;
		for(int p=0;p<P;p++)
		{
			if(!f[p])
			{
				int j;
				for(j=0;j<R;j++)
					if(n[p][j]>use[j])
						break;

				if(j==R)
				{
					for(int k=0;k<R;k++)
						use[k]=use[k]+alt[p][k];

                    cn++;
					f[p]=true;
					fnd=true;
				}
			}
		}
		if(fnd==false)
		{
		    cout<<"Not in safe state";
			return 0;
		}
	}

	cout<<"Safe state";

	return 0;
}
