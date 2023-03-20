#include<iostream>
#include<stdio.h>
using namespace std;

unsigned int gcd (unsigned int a, unsigned int b){
  if (a == 0){
      return b;
    }
  return gcd (b % a, a);
}

unsigned int lcm (unsigned int a, unsigned int b){
    if (a == 0){
      return b;
    }
  else if (b == 0)
    {
      return a;
    }
  return (a * b) / gcd (a, b);
}

int main (){
  unsigned int z[3], x, res, kF;
  scanf ("%u%u%u%u", &z[0], &z[1], &z[2], &x);
  unsigned int L = lcm (z[0], lcm (z[1], z[2]));
  kF = L;
  bool virkne[L]{};
  //cout << "L  " << L << endl;
  for(unsigned int i = 0; i < 3; i++){
      for(unsigned int j = z[i]; j <= L; j += z[i]){
        //res	  //cout<<j<<endl;
	    if (!virkne[j - 1]){
	    kF--;
	    }
	    virkne[j - 1] = true;
	}
}
  //cout << "kF   " << kF << endl;	//<<L<<endl;
  //cout << endl;
    res = x / kF;
    res *= L;
  for (int i = 0,j=x%kF; j>0; i++){
      if (!virkne[i]){
	    //cout << i + 1 << endl;
	    //res++;
	    j--;
	  }
	  res++;
	  //cout<<res<<endl;
    }

  
  //cout << "res1  " << res << endl;
  
  //cout << "res2  " << res << endl;
  /*
  for (unsigned int i = x % kF, j = 0; 0 < i; j++){
      if (!virkne[j]){
	  i--;
	  //cout << i << endl;
	  }
      else{
        res++;
	  }
  }
  */
    printf ("%u", res);
    
    return 0;
}