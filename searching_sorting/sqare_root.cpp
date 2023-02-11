
// link- https://practice.geeksforgeeks.org/problems/count-squares3649/1

    int countSquares(int N) {
        int k= sqrt(N);
        if(k*k==N){
            return k-1;
        }
        return k;
    }
