#include <iostream>

int main() {
    int n, m, ai, qi, divide[1000];
    divide[0] = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ai);
        divide[i+1] = divide[i] + ai;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &qi);
        int l = 0, r = n;
        while(l < r){
	    std::cout << l << " " << r << std::endl;
            if(qi == divide[(l+r)/2]) {
                break;
            }
	    else if(l+1 == r)
		break;
            else if(qi < divide[(l+r)/2])
                r = (l+r)/2;
            else
                l = (l+r)/2;
        }
	if(qi == divide[(l+r)/2])
            printf("%d\n", (l+r)/2);
	else if(qi <= divide[l])
	    printf("%d\n", l);
	else
	    printf("%d\n", r);
    }
    return 0;
}
