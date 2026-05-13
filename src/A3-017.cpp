#include <iostream>

using namespace std;

int main() {
    long long w, l, m, n;
    if (!(cin >> w >> l >> m >> n)) return 0;
    
    long long min_rem = -1;
    
    // We want to minimize remainder area.
    // Given A x 1, we can place floor(W/A) * A blocks per row, L times.
    // Or we place A along L: floor(L/A) * A blocks per column, W times.
    // Actually the problem says "คุณจะนำสินค้ามาหมุนแล้วเรียงไปทีละแถวอีกครั้งจนกระทั่งทำไม่ได้".
    // 1st orientation: A x 1. We put blocks of A x 1 along W. 
    // We can put floor(W / A) blocks per row. Since height is 1, we can do this for L rows.
    // So area used = floor(W / A) * A * L.
    // Remainder area = W * L - (floor(W / A) * A * L) = (W % A) * L.
    // Then we can rotate the remaining items (1 x A). We have remaining space (W % A) x L.
    // Can we put 1 x A in (W % A) x L?
    // The width is W % A, height is L. We place 1 x A items.
    // So we can place floor(L / A) items per column, for W % A columns.
    // Area used = (W % A) * floor(L / A) * A.
    // Total remaining area = (W % A) * L - (W % A) * floor(L / A) * A = (W % A) * (L % A).
    
    // The problem statement says:
    // "คุณจะเริ่มโดยการเรียงสินค้าไปตามแนวยาวไปทีละแถวจนใส่ไม่ได้ ก็จะขึ้นแถวใหม่ทำไปจนครบ W แถว"
    // Wait, "กว้าง W ยาว L" and box is A x 1.
    // Put along the length? "แนวยาว" is L?
    // "กว้าง W ยาว L" -> Width W, Length L.
    // Example W=11, L=4, A=3. 
    // 3x1 items.
    // "เรียงสินค้าไปตามแนวยาวไปทีละแถว"
    // The image shows 3 blocks of 3x1 in a row of length W=11? 
    // Yes! 3 * 3 = 9. Remainder 2. Height is 4.
    // Then rotated items are 1x3. We have 2x4 area. We can place one 1x3 in each column? Yes, so 2 * 3 = 6. 
    // Remaining area = 2 * 1 = 2.
    // This perfectly matches (W % A) * (L % A).
    // (11 % 3) * (4 % 3) = 2 * 1 = 2.
    // Example 3: W=13, L=20. M=7, N=9.
    // A=7 -> (13 % 7) * (20 % 7) = 6 * 6 = 36.
    // A=8 -> (13 % 8) * (20 % 8) = 5 * 4 = 20.
    // A=9 -> (13 % 9) * (20 % 9) = 4 * 2 = 8.
    // So the formula is simply (W % A) * (L % A).
    
    for (long long a = m; a <= n; ++a) {
        long long rem = (w % a) * (l % a);
        if (min_rem == -1 || rem < min_rem) {
            min_rem = rem;
        }
    }
    
    cout << min_rem << "\n";
    
    return 0;
}
