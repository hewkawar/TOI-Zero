#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long L, N;
    if (!(cin >> L >> N)) return 0;
    
    // Number of oranges in a pyramid of base L is sum of i^2 for i=1..L
    // Sum = L * (L + 1) * (2*L + 1) / 6.
    // The oranges are taken from the top.
    // So N oranges taken from the top means we remove the top k layers.
    // Wait! The problem says:
    // "เมื่อขายส้มได้ N ลูกแล้ว ส้มที่เรียงอยู่ในกองจะเหลืออยู่กี่ชั้น"
    // "ถ้า L=3 และขายไป 4 ลูก จะเหลือ 2 ชั้น"
    // For L=3, the layers from top to bottom have 1, 4, 9 oranges.
    // We pick from the top. We can pick any orange that is exposed.
    // The example says "ขายส้มไป 4 ลูก จะเหลือ 2 ชั้น".
    // 1st layer has 1 orange. 2nd layer has 4 oranges.
    // Wait, the picture for L=3, sold 4:
    // Left: 2 layers remaining. (The top 1x1 is gone, and 3 from the 2x2 are gone, leaving 1 in 2x2, and 9 in 3x3).
    // Total remaining = 14 - 4 = 10 oranges.
    // If it has 2 layers, it means the bottom layer (3x3) and the 2nd layer (2x2) still have SOME oranges.
    // The 1st layer (top) is completely gone.
    // The problem asks for the number of remaining layers.
    // A layer is remaining if it has at least 1 orange.
    // We take oranges from the top. To completely remove the top layer, we just take 1 orange.
    // To completely remove the 2nd layer, we must take all oranges in the 1st and 2nd layers.
    // 1st layer = 1 orange.
    // 2nd layer = 4 oranges.
    // To remove 2 layers, we need 1 + 4 = 5 oranges.
    // Example: L=3, sold 4. Removed 1 layer (needs 1). To remove 2 layers, we need 5. We sold 4, so 2 layers remain.
    // Example: sold 5. Removed 2 layers (1+4). Remaining = 3 - 2 = 1 layer.
    // Example: L=4, sold 7. 
    // 1st layer = 1.
    // 2nd layer = 4.
    // 3rd layer = 9.
    // To remove 2 layers: 1+4 = 5.
    // To remove 3 layers: 1+4+9 = 14.
    // Sold 7. It is >= 5, so 2 layers removed. < 14, so 3rd layer is not completely removed.
    // Remaining = 4 - 2 = 2 layers.
    // So the number of remaining layers is L - k, where k is the maximum number of layers that can be completely removed with N oranges.
    // Total oranges in k layers from top = sum_{i=1..k} i^2 = k*(k+1)*(2k+1)/6.
    
    long long k = 0;
    long long sum = 0;
    while (k < L) {
        long long next_sum = sum + (k + 1) * (k + 1);
        if (N >= next_sum) {
            sum = next_sum;
            k++;
        } else {
            break;
        }
    }
    
    cout << L - k << "\n";
    
    return 0;
}
