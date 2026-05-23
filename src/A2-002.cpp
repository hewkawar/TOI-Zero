#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // ปรับปรุงประสิทธิภาพการรับส่งข้อมูล (I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // ใช้ Map เพื่อเก็บค่า X ที่น้อยที่สุดและมากที่สุด สำหรับแต่ละกลุ่มผลลบ (x - y) และผลบวก (x + y)
    map<long long, long long> min_x_minus_y, max_x_minus_y;
    map<long long, long long> min_x_plus_y, max_x_plus_y;

    long long max_size = 0; // ขนาดเริ่มต้นคือ 0 ตามเงื่อนไขโจทย์

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;

        long long diff = x - y;
        long long sum = x + y;

        // 1. ตรวจสอบกลุ่ม x - y
        if (min_x_minus_y.find(diff) == min_x_minus_y.end()) {
            // ถ้ายังไม่เคยเจอค่าผลลบนี้ ให้บันทึกค่า x เป็นทั้งค่าน้อยสุดและมากสุด
            min_x_minus_y[diff] = x;
            max_x_minus_y[diff] = x;
        } else {
            // ถ้าเคยเจอแล้ว ให้อัปเดตค่าน้อยสุด/มากสุด และคำนวณหาขนาดเต็นท์ที่ใหญ่ที่สุด
            min_x_minus_y[diff] = min(min_x_minus_y[diff], x);
            max_x_minus_y[diff] = max(max_x_minus_y[diff], x);
            max_size = max(max_size, max_x_minus_y[diff] - min_x_minus_y[diff]);
        }

        // 2. ตรวจสอบกลุ่ม x + y
        if (min_x_plus_y.find(sum) == min_x_plus_y.end()) {
            // ถ้ายังไม่เคยเจอค่าผลบวกนี้ ให้บันทึกค่า x เป็นทั้งค่าน้อยสุดและมากสุด
            min_x_plus_y[sum] = x;
            max_x_plus_y[sum] = x;
        } else {
            // ถ้าเคยเจอแล้ว ให้อัปเดตค่าน้อยสุด/มากสุด และคำนวณหาขนาดเต็นท์ที่ใหญ่ที่สุด
            min_x_plus_y[sum] = min(min_x_plus_y[sum], x);
            max_x_plus_y[sum] = max(max_x_plus_y[sum], x);
            max_size = max(max_size, max_x_plus_y[sum] - min_x_plus_y[sum]);
        }
    }

    // แสดงผลลัพธ์ขนาดของเต็นท์ที่ใหญ่ที่สุด
    cout << max_size << "\n";

    return 0;
}