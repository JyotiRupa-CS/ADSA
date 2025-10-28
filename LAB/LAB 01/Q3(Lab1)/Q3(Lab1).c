#include<stdio.h>

int defectiveCoin(int coins[], int n);
int SumofWeights(int coins[], int leftStart, int leftEnd, int rightStart, int rightEnd);

int main()
{
    int n;
    printf("Enter the number of coins:");
    scanf("%d", &n);

    int coins[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &coins[i]);
    }

    int index = defectiveCoin(coins,n);

    if(index != -1)
        printf("Defective coin found at index:%d  weight is %d",index ,coins[index]);
    else
        printf("No defective coins");

    return 0;

}

int SumofWeights(int coins[], int leftStart, int leftEnd, int rightStart, int rightEnd)
{
    int sumLeft = 0; int sumRight = 0;

    //sum of left side

    for (int i=leftStart; i<=leftEnd; i++)
    {
        sumLeft = sumLeft + coins[i];
    }

    //Sum of right side

    for (int i=rightStart; i<=rightEnd; i++)
    {
        sumRight = sumRight + coins[i];
    }

    if (sumLeft < sumRight)
    {
        return -1; //-1 means left has defective
    }
    else if(sumLeft > sumRight)
    {
        return 1; // 1 means right has defective
    }
    else{
        return 0; //Balanced between both the sides 
    }
}

 int defectiveCoin(int coins[], int n) {
    int ref = coins[0] == coins[1] ? coins[0] : coins[2]; // assume first 2 are normal, if not, 3rd is normal

     for(int i = 0; i < n; i++) {
        if(coins[i] != ref)
            return i; // defective coin found
    }
    return -1; // all coins are same
}

// int defectiveCoin(int coins[], int left, int right) {
//     int n = right - left + 1;

//     // Base case: only one coin
//     if (n == 1) return left;

//     int mid = (left + right) / 2;

//     if (n % 2 == 0) {
//         // even number of coins: divide equally
//         int sumLeft = 0, sumRight = 0;
//         for (int i = left; i <= mid; i++) sumLeft += coins[i];
//         for (int i = mid + 1; i <= right; i++) sumRight += coins[i];

//         if (sumLeft < sumRight) return defectiveCoin(coins, left, mid);
//         else if (sumLeft > sumRight) return defectiveCoin(coins, mid + 1, right);
//         else return -1;  // all coins same weight
//     } else {
//         // odd number of coins: exclude middle coin
//         int sumLeft = 0, sumRight = 0;
//         for (int i = left; i < mid; i++) sumLeft += coins[i];
//         for (int i = mid + 1; i <= right; i++) sumRight += coins[i];

//         if (sumLeft == sumRight) return mid;  // middle coin is defective
//         else if (sumLeft < sumRight) return defectiveCoin(coins, left, mid - 1);
//         else return defectiveCoin(coins, mid + 1, right);
//     }
// }

// int defectiveCoin(int coins[], int left, int right)
// {
//     if(left == right) {
//         return left; // Only one coin left, must be defective
//     }

//     if(right - left == 1) {
//         // Two coins left, return the one with different weight
//         if(coins[left] != coins[right])
//             return (coins[left] < coins[right]) ? left : right;
//         else
//             return -1;
//     }

//     int n = right - left + 1;
//     int mid = (left + right) / 2;

//     if(n % 2 == 0) {
//         // Even number of coins
//         int result = SumofWeights(coins, left, mid, mid+1, right);

//         if(result == -1)
//             return defectiveCoin(coins, left, mid);
//         else if(result == 1)
//             return defectiveCoin(coins, mid+1, right);
//         else
//             return -1;
//     } else {
//         // Odd number of coins
//         int result = SumofWeights(coins, left, mid-1, mid+1, right);

//         if(result == -1)
//             return defectiveCoin(coins, left, mid-1);
//         else if(result == 1)
//             return defectiveCoin(coins, mid+1, right);
//         else
//             return mid; // middle coin is defective
//     }
// }
